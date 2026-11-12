# Defesa: como blindar (a regra e o porquê)

A regra, em uma frase: **segredo não vive no cliente.** O código roda na máquina de quem
ataca — qualquer coisa cravada nele pode ser lida. Então:

## 1. Valida no servidor
A decisão que depende do segredo (liberar acesso, validar licença, assinar algo) acontece no
**servidor**, que o atacante não controla. O cliente manda o pedido; o servidor responde sim/
não. A chave que assina/valida nunca sai do servidor.

## 2. Guarda em cofre de segredos
Em vez de hardcode, use um **cofre**: HashiCorp Vault, AWS/GCP Secrets Manager, Doppler,
1Password Secrets. Variável de ambiente só como último recurso (segue vazável em dump/log).

## 3. Scanner no CI + pre-commit
Automatiza pra o segredo nunca mais entrar: hook de pre-commit + scanner no pipeline que
reprova o PR. Ver [`checklist.md`](checklist.md).

## 4. Rotaciona o que já vazou
Se um segredo foi pro repo um dia, trate como comprometido: **gere novo e revogue o antigo**.
Mais de 64% das credenciais que vazaram em 2022 ainda funcionavam em 2026 justamente porque
ninguém trocou (GitGuardian, State of Secrets Sprawl 2026).

## 5. Ofuscação não é segurança
ProGuard/R8 e similares **renomeiam identificadores, não cifram o valor** do segredo. String
cifrada é decifrada em runtime — o atacante só espera. Ofuscar atrasa, não esconde.

## Sobre licenciamento de software
Se o seu produto valida licença, o **algoritmo e a chave de assinatura ficam no servidor**.
Licença embutida com a chave de verificação no cliente é forjável — foi exatamente o furo que
a CHDEVSEC achou num pentest de licenciamento (chave hardcoded → forjar licença pra qualquer
máquina). Validação online ou assinatura verificada contra uma chave pública (com a privada
no servidor) resolve.
