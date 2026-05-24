#include "lista.h"

void inicia_lista(t_lista *pl){
    pl->primeiro = NULL;
}
int lista_vazia(t_lista *pl){
    return pl->primeiro == NULL;
}

/*
Inserção de inicio tem dois cenarios
Cenário 1:
-----> // (VAZIO)
primeiro-v
        [8]
novo |^
Cenário 2:
Antes:
-->[10]-->[2]-->[4]-|   (Multiplos elementos)
prim                =

Durante
-x>[10]-->[2]-->[4]-|
prim\               =
     >[15]

Depois
-->[15]-->[10]-->[2]-->[4]-|
prim                       =
*/
void insere_inicio(t_lista *pl, int e){
    t_no * novo = constroi_no(e);
    if(!lista_vazia(pl))
        novo->proximo = pl->primeiro;
    pl->primeiro = novo;
}
void insere_fim(t_lista *pl, int e){
    t_no * novo = constroi_no(e);
    if(lista_vazia(pl)){
        pl->primeiro = novo;
    }
    else{
        t_no *runner = pl->primeiro;
        while (runner->proximo != NULL){
            runner = runner->proximo;
        }
        runner->proximo = novo;
    }
}
int remove_inicio(t_lista *pl){
        int copia_valor = pl->primeiro->info;
        t_no * copia_endereco = pl->primeiro;
        pl->primeiro = pl->primeiro->proximo;
        free(copia_endereco);
        return copia_valor;
}
int remove_fim(t_lista *pl){
    int copia_valor;
    t_no * copia_endereco;
    if (pl->primeiro->proximo == NULL){ //tem um elemento só
        copia_valor = pl->primeiro->info;
        copia_endereco = pl->primeiro;
        pl->primeiro = NULL; //esvaziou a lista 
    }else{
        t_no *runner = pl->primeiro;
        while(runner->proximo->proximo != NULL){
            runner = runner->proximo;
        }
        copia_valor = runner->proximo->info;
        copia_endereco = runner->proximo;
        runner->proximo = NULL;
    }
    free(copia_endereco);
    return copia_valor;
}
void exibe_lista(t_lista *pl){
    if(lista_vazia(pl))
        printf("lista_vazia\n");
    else{
        t_no * runner = pl->primeiro;
        while (runner != NULL){
            printf("%d -> ", runner->info);
            runner = runner->proximo;
        }
        printf("//\n");
    }
}

int tamanho_lista(t_lista *pl) {
    int contador = 0;
    if(lista_vazia(pl)){
        printf("Lista está vazia");
    }else{
        t_no * runner = pl->primeiro;
        while(runner != NULL){
            contador++;
            runner = runner->proximo;
        }
    }
    return contador;
}
