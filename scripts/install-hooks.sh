#!/usr/bin/env bash
# Instala el hook pre-commit de gitleaks en este clon.
# Uso: bash scripts/install-hooks.sh
set -euo pipefail

HOOKS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)/.git/hooks"
SOURCE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/pre-commit"

if [ ! -d "$HOOKS_DIR" ]; then
  echo "No hay .git/hooks — ¿es un clon de git?" >&2
  exit 1
fi

cp "$SOURCE" "$HOOKS_DIR/pre-commit"
chmod +x "$HOOKS_DIR/pre-commit"
echo "✅ Hook pre-commit instalado (gitleaks)."