# Lab: o cofre que não esconde nada

`cofre.c` é um app de treino que pede uma senha. Dentro dele tem, cravado no código:

| Segredo | Valor (plantado de propósito) |
|---|---|
| Senha de admin | `S3nhaSecreta@2026` |
| Chave de API | `sk_live_9f2c7a1b4e8d6f3a0c5b9e2d` |
| Chave de licença | `CHDV-SIGN-7b3f-9a21-ee04` |

Nada disso é real — é tudo de laboratório, pra demonstração.

## Rodar

```bash
./achar.sh
```

Ele compila (`gcc`) e roda `strings cofre-lab.exe`. A saída mostra os três segredos em texto
puro, no meio das strings do binário, e até os nomes das variáveis (`ADMIN_PASSWORD`,
`API_KEY`). `strings` lista só ASCII por padrão — por isso o segredo plantado é ASCII; num
app real, descompilador de APK/.NET/Java faz o mesmo com strings UTF-16 e lógica.

## Agora inverta (a parte que importa)

O erro não é a senha ser fraca — é ela **existir no cliente**. Mesmo uma senha gigante e
aleatória apareceria igual no `strings`. O conserto não é "esconder melhor": é **tirar o
segredo do código** e validar no servidor. Ver [`../defesa/`](../defesa/).

> Ofuscação (ProGuard/R8 etc.) **renomeia identificadores, não cifra o valor** do segredo. Só
> atrasa. Não é segurança.
