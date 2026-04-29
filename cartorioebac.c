#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define ARQUIVO "nomes.txt"
#define TAM_NOME 100

void trim(char *str) {
    int i;
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (fim >= 0 && (str[fim] == ' ' || str[fim] == '\n' || str[fim] == '\r' || str[fim] == '\t')) {
        str[fim] = '\0';
        fim--;
    }

    while (str[inicio] == ' ' || str[inicio] == '\t') {
        inicio++;
    }

    if (inicio > 0) {
        for (i = 0; str[inicio + i] != '\0'; i++) {
            str[i] = str[inicio + i];
        }
        str[i] = '\0';
    }
}

void registrarNome() {
    char nome[TAM_NOME];
    FILE *arquivo;

    printf("=== Registrar Nome ===\n\n");
    printf("Digite o nome a ser registrado: ");
    scanf(" %[^\n]", nome);
    trim(nome);

    arquivo = fopen(ARQUIVO, "a");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        system("pause");
        return;
    }

    fprintf(arquivo, "%s\n", nome);
    fclose(arquivo);

    printf("\nNome registrado com sucesso!\n");
    system("pause");
}

void consultarNomes() {
    char nome[TAM_NOME];
    FILE *arquivo;
    int contador = 1;

    printf("=== Consultar Nomes ===\n\n");

    arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("Nenhum nome registrado ainda.\n");
        system("pause");
        return;
    }

    printf("Nomes registrados:\n\n");
    while (fgets(nome, TAM_NOME, arquivo) != NULL) {
        trim(nome);
        printf("  %d. %s\n", contador++, nome);
    }

    if (contador == 1) {
        printf("  (nenhum nome encontrado)\n");
    }

    fclose(arquivo);
    printf("\n");
    system("pause");
}

void deletarNome() {
    char nomeBusca[TAM_NOME];
    char nomeLinha[TAM_NOME];
    FILE *arquivo, *temp;
    int encontrado = 0;

    printf("=== Deletar Nome ===\n\n");
    printf("Digite o nome que deseja deletar: ");
    scanf(" %[^\n]", nomeBusca);
    trim(nomeBusca);

    arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("\nNenhum nome registrado ainda.\n");
        system("pause");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("\nErro ao criar arquivo temporario!\n");
        fclose(arquivo);
        system("pause");
        return;
    }

    while (fgets(nomeLinha, TAM_NOME, arquivo) != NULL) {
        trim(nomeLinha);

        if (strcmp(nomeLinha, nomeBusca) == 0 && !encontrado) {
            encontrado = 1;
        } else {
            fprintf(temp, "%s\n", nomeLinha);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(ARQUIVO);
    rename("temp.txt", ARQUIVO);

    if (encontrado) {
        printf("\nNome deletado com sucesso!\n");
    } else {
        printf("\nNome nao encontrado!\n");
    }

    system("pause");
}

int main() {
    int opcao = 0;

    setlocale(LC_ALL, "portuguese");

    while (1) {
        system("cls");

        printf("### Cartorio da EBAC ###\n\n");
        printf("Escolha a opcao desejada do menu:\n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar os Nomes\n");
        printf("\t3 - Deletar os Nomes\n");
        printf("\t0 - Sair\n\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registrarNome();
                break;
            case 2:
                consultarNomes();
                break;
            case 3:
                deletarNome();
                break;
            case 0:
                printf("Encerrando o sistema. Ate logo!\n");
                system("pause");
                return 0;
            default:
                printf("Essa opcao nao esta disponivel!\n");
                system("pause");
                break;
        }
    }
}
