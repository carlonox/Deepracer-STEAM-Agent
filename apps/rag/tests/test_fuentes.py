"""Verifica que el indexador descubre el mismo conjunto de manuales que la
ubicación anterior, sin instalar langchain ni descargar modelos."""
import sys
import types
import pathlib
import importlib.util

# Stubs de langchain para poder importar indexador.py sin instalarlo
def _mk_mod(name, attrs=None):
    mod = types.ModuleType(name)
    if attrs:
        for k, v in attrs.items():
            setattr(mod, k, v)
    sys.modules[name] = mod
    return mod

_mk_mod("langchain_community")
class _Doc:
    def __init__(self, page_content="", metadata=None):
        self.page_content = page_content
        self.metadata = metadata or {}

class _TextLoader:
    def __init__(self, path, encoding=None):
        pass
    def load(self):
        return [_Doc(page_content="contenido de prueba")]

_mk_mod("langchain_community.document_loaders", {"TextLoader": _TextLoader})
_mk_mod("langchain_text_splitters", {"RecursiveCharacterTextSplitter": object})
_mk_mod("langchain_community.embeddings", {"HuggingFaceEmbeddings": object})
_mk_mod("langchain_community.vectorstores", {"FAISS": object})
_mk_mod("langchain_community.document_loaders.text", {})
_mk_mod("langchain_core")
_mk_mod("langchain_core.documents", {"Document": object})

SRC = pathlib.Path(__file__).resolve().parents[1] / "src" / "indexador.py"
spec = importlib.util.spec_from_file_location("rag_indexador", SRC)
indexador = importlib.util.module_from_spec(spec)
spec.loader.exec_module(indexador)

# Conjunto esperado: 19 Manual_*.md + GUIA_SETUP.md (mismo que antes del traslado;
# el README del componente no es un manual y dejó de indexarse).
EXPECTED = 20


def test_descubre_mismo_conjunto():
    knowledge = pathlib.Path(__file__).resolve().parents[1] / "knowledge"
    docs = indexador.cargar_documentos(str(knowledge))
    assert len(docs) == EXPECTED
    nombres = sorted({d.metadata["source"] for d in docs})
    assert "GUIA_SETUP.md" in nombres
    manuales = [n for n in nombres if n.startswith("Manual_")]
    assert len(manuales) == 19


def test_ruta_conocimiento_desde_archivo():
    # El indexador resuelve knowledge/ relativo a su propio archivo
    knowledge = pathlib.Path(__file__).resolve().parents[1] / "knowledge"
    assert knowledge.exists()
    assert knowledge.is_dir()
