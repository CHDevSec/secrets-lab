# secrets-lab

**Por que uma senha escondida dentro do programa não é segredo nenhum — e como blindar o seu código.**

Lab educativo da [CHDEVSEC](https://chdevsec.com.br). Aqui você vê, na prática, que **segredo
hardcoded** (senha, chave de API, chave de licença cravada no código/binário) é trivial de
achar com engenharia reversa — e sai com um **checklist pronto pra varrer o seu próprio
código**.

## O que este repo É
- Um binário de LAB **nosso** (`cofre-lab.exe`) com segredos plantados de propósito.
- A prova de que `strings` (um comando) já revela tudo em texto puro.
- A **defesa**: como parar de guardar segredo no cliente e como escanear seu código.

## O que este repo NÃO é
- Não é tutorial de pirataria, keygen, crack de DRM, nem de extrair segredo de produto de
  terceiro. Tudo roda num binário de treino **nosso**. Uso autorizado só — ver [ETICA.md](ETICA.md).

## Mostra rápido (10 segundos)

```bash
cd lab
./achar.sh        # compila o cofre-lab.exe e mostra os segredos que o `strings` revela
```

Você vai ver a senha, a chave de API e a chave de licença **em texto puro**, mais os nomes
das variáveis (`ADMIN_PASSWORD`, `API_KEY`). Nenhum deles estava "escondido" de verdade.

## Por que isso importa (não é raro)

- **28,65 milhões** de segredos novos foram cravados em commits públicos do GitHub só em 2025
  (+34% a/a) — GitGuardian, *State of Secrets Sprawl 2026*.
- Mais de **64%** das credenciais válidas em 2022 ainda funcionavam em 2026. Ninguém trocou.
- A doc do Android é direta: *"um atacante com ferramenta de engenharia reversa recupera um
  segredo hardcoded muito facilmente"*.

## A defesa

O código não protege o que você vê — ele **roda na máquina de quem ataca**. Então:

👉 **Segredo não vive no cliente.** Valida no servidor, guarda em cofre de segredos, bota um
scanner no teu CI e **rotaciona o que já vazou**. Ofuscar só atrasa, não esconde.

- Como blindar: [`defesa/README.md`](defesa/README.md)
- **Checklist pra varrer o teu código hoje:** [`defesa/checklist.md`](defesa/checklist.md)

## Licença
MIT — ver [LICENSE](LICENSE). Feito pela CHDEVSEC pra ensino de segurança na prática.
