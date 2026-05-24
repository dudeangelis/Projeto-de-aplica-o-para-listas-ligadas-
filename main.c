#include "lista.h"

int main() {
    t_lista fila;
    inicia_lista(&fila);

    int opcao;
    int proxSenha    = 1;    // contador senhas comuns
    int proxSenhaVIP = 100;  // contador senhas VIP

    do {
        printf("\n===== FILA DE ATENDIMENTO =====\n");
        printf("1. Emitir nova senha\n");
        printf("2. Chamar proximo\n");
        printf("3. Ver fila atual\n");
        printf("4. Quantas pessoas na fila?\n");  // Extensão 1
        printf("5. Emitir senha VIP\n");           // Extensão 2
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                insere_fim(&fila, proxSenha);
                printf("Senha %d emitida!\n", proxSenha);
                proxSenha++;
                break;

            case 2:
                if (lista_vazia(&fila)) {
                    printf("Fila vazia, ninguem aguardando.\n");
                } else {
                    int atendido = remove_inicio(&fila);
                    printf("Chamando senha: %d\n", atendido);
                }
                break;

            case 3:
                printf("Fila atual:\n");
                exibe_lista(&fila);
                break;

            case 4:  // Extensão 1
                printf("Pessoas na fila: %d\n", tamanho_lista(&fila));
                break;

            case 5:  // Extensão 2
                insere_inicio(&fila, proxSenhaVIP);
                printf("Senha VIP %d emitida!\n", proxSenhaVIP);
                proxSenhaVIP++;
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}