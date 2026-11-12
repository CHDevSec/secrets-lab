#!/usr/bin/env bash
# Compila o binário de LAB e mostra que os segredos hardcoded aparecem em texto puro.
# Nada aqui toca software de terceiro: o cofre-lab.exe é NOSSO, com segredos plantados.
set -euo pipefail
cd "$(dirname "$0")"

echo "[*] Compilando cofre-lab.exe ..."
gcc -O0 cofre.c -o cofre-lab.exe

echo
echo "[*] Rodando: strings cofre-lab.exe | grep (os segredos cravados)"
echo "--------------------------------------------------------------"
strings cofre-lab.exe | grep -E 'S3nha|sk_live|CHDV-SIGN|ADMIN_PASSWORD|API_KEY' || true
echo "--------------------------------------------------------------"
echo
echo "[!] Tudo isso estava 'escondido' dentro do app. strings lê em 1 comando."
echo "    Senha, chave de API e chave de licença, em texto puro. E ainda os NOMES"
echo "    das variaveis. Ofuscar renomeia o nome, nao cifra o valor."
echo
echo "    -> Agora blinde o seu codigo: ../defesa/checklist.md"
