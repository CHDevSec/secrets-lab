/*
  cofre-lab.exe — binário de LAB da CHDEVSEC (NÃO é produto real).
  Serve só pra demonstrar que SEGREDO HARDCODED num binário é trivial de achar com `strings`.
  NUNCA faça isso de verdade: senha, chave de API e chave de licença NÃO podem viver no código.
*/
#include <stdio.h>
#include <string.h>

/* credenciais "escondidas" dentro do app (anti-exemplo de propósito) */
static const char *ADMIN_PASSWORD      = "S3nhaSecreta@2026";
static const char *API_KEY             = "sk_live_9f2c7a1b4e8d6f3a0c5b9e2d";
static const char *LICENSE_SIGNING_KEY = "CHDV-SIGN-7b3f-9a21-ee04";

int main(void) {
    char input[128];
    printf("CHDEVSEC Cofre v1.0\n");
    printf("Senha: ");
    if (!fgets(input, sizeof(input), stdin)) return 1;
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, ADMIN_PASSWORD) == 0) {
        printf("Acesso liberado. (api=%s)\n", API_KEY);
        return 0;
    }
    printf("Senha incorreta.\n");
    (void)LICENSE_SIGNING_KEY;
    return 1;
}
