# Checklist: varrer segredo no teu código (hoje)

O que o vídeo prometeu. Roda em qualquer repo. Leva uns minutos.

## 1. Escaneia o que já tá lá (inclusive o histórico do git)

Um scanner acha senha, chave de API, token e chave privada cravados no código **e nos
commits antigos** (apagar do último commit NÃO tira do histórico).

```bash
# gitleaks (Go, 1 binário) — https://github.com/gitleaks/gitleaks
gitleaks detect --source . --report-path gitleaks-report.json

# ou trufflehog (verifica se a credencial ainda está ATIVA)
trufflehog git file://. --only-verified
```

## 2. Achou algo? Trata como VAZADO

- [ ] **Rotaciona já** (gera nova chave/senha e revoga a antiga). Remover do código não
      basta: se foi pro GitHub, considere que já copiaram.
- [ ] Tira o segredo do código (ver passo 4).
- [ ] Se precisar, limpa o histórico (`git filter-repo` / BFG) — mas só DEPOIS de rotacionar.

## 3. Impede de voltar (automatiza)

- [ ] **Pre-commit hook** que bloqueia commit com segredo:
      `gitleaks protect --staged` (via [pre-commit](https://pre-commit.com/)).
- [ ] **Scanner no CI** (GitHub Actions/GitLab CI) que reprova o PR se achar segredo.
      Ex. GitHub: action `gitleaks/gitleaks-action`.
- [ ] Liga o **secret scanning** nativo do GitHub (grátis em repo público).

## 4. Tira o segredo do código de vez

- [ ] Em dev: **variável de ambiente** só como último caso; o certo é um **cofre de
      segredos** (HashiCorp Vault, AWS/GCP Secrets Manager, Doppler, 1Password...).
- [ ] O que é segredo do servidor **fica no servidor**. O cliente (app/site/binário) nunca
      guarda a chave que dá o acesso — ele pede, e o servidor valida.
- [ ] `.env` no `.gitignore`. Commita um `.env.example` só com os NOMES, sem valores.

## 5. Mantém

- [ ] Rotação periódica das chaves.
- [ ] Revisão de PR olha pra segredo também.
- [ ] Nada de "ofuscar e pronto": ofuscação atrasa, não esconde.
