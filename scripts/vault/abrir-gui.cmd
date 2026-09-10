@echo off
rem Lanzador de la GUI del vault. Doble clic o:  scripts\vault\abrir-gui.cmd
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0DeepRacerVaultGui.ps1"
