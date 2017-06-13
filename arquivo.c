#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

/*Converte um real para pointeiro char
 *
 * Parâmetros:
 * (float) n: número a ser convertido
 *
 * Retorna:
 * (char*) string de n
 */
char * float_to_char(float n)
{
    char *s = malloc(sizeof(char *));
    strcpy(s, "");

    snprintf(s, 16, "%f", n);

    return s;
}

/*Converte um inteiro para pointeiro char
 *
 * Parâmetros:
 * (int) n: número a ser convertido
 *
 * Retorna:
 * (char*) string de n
 */
char * int_to_char(int n)
{
    char *s = malloc(sizeof(char *));
    strcpy(s, "");

    snprintf(s, 8, "%d", n);

    return s;
}

/*
 * Escreve um registro no arquivo ou atualiza esse registro se ele já existir
 *
 * Parâmetros:
 * (char *) dir: diretório  do arquivo que será lido
 * (char *) chave: identificador do registro a ser inserido
 * (char *) valor: valor do registro a ser inserido
 * (int) limpar: 1 para limpar todo o conteúdo do arquivo
 *               0 para adicionar ao conteúdo já existente no arquivo
 *
 * Retorna:
 * (int) 0: erro
 * (int) 1: registro inserido
 */
int grava_registro(char * dir, char * chave, char * valor, int limpar)
{

    FILE * arq;

    //Verifica se oarquivo deve ser limpo ou não
    //Em caso positivo, o arquivo é aberto um modo escrita, e isso causa o conteúdo do arquivo a ser apagado
    //Em caso negativo, o arquivo é aberto em modo anexar, assim o conteúdo não é modificado
    if(limpar == 1){

         arq = fopen(dir, "w+");

    }
    else if(limpar == 0){

         arq = fopen(dir, "a+");

    }

    //Verifica se o arquivo existe/foi aberto
    if(arq != NULL){

        //As funções fprintf e fputs não funcionaram.
        //fprintf(arq, "%s\n", strcat( strcat(chave, " "), valor ) );
        //fputs( strcat( strcat(chave, " "), strcat(valor, "\n") ), arq);

        //Unifica o conteudo a ser escrito no arquivo em uma só variável
        char linha[40];
        strcpy(linha, "");
        strcat(linha, chave);
        strcat(linha, " ");
        strcat(linha, valor);
        strcat(linha, "\n");
        //printf("linha: %s", linha);

        int i = 0;

        //Escreve o conteúdo no arquivo caracter por caracter
        while(linha[i] != '\0'){
            fputc(linha[i], arq);
            i++;
        }

        fclose(arq);

        return 1;
    }

    return 0;

}

/* Lê um registro do arquivo
 *
 * Parâmetros:
 * (char *) dir: diretório  do arquivo que será lido
 * (char *) chave: identificador do registro buscado
 *
 * Retorna:
 * (char *): valor do registro, ou nulo caso o registro ou arquivo não existe
 */
char * ler_registro(char * dir, char * chave)
{
    FILE * arq = fopen(dir, "r");

    //Verifica se o arquivo existe
    if(arq != NULL){

        do{
            //É necessário ler a chave e o valor para que o cursor se desloque no arquivo, caso contrário, o fim do arquivo nunca será atingido
            //Lê a chave no arquivo
            char chave_lida[25];
            fscanf(arq, "%s", chave_lida);
            //Lê o valor no arquivo
            char * chave_valor = malloc(sizeof(char) * 15);
            fscanf(arq, "%s", chave_valor);

            if( strncmp(chave_lida, chave, 25) == 0 ){

                return (char *)chave_valor;

            }

        }while(!feof(arq));

    }

    //Retorna um valor nulo caso o arquivo não exista ou a chave procurada não exista
    return "";
}

//Exemplo de uso
int main()
{

    char *arq = "teste.txt";

    printf("Gravando\n");

    //O primeiro registro a ser inserido é passado com o parâmetro limpar = 1 para garantir que o arquivo é criado
    grava_registro(arq, "a", int_to_char(100), 1);

    grava_registro(arq, "b", float_to_char(21.5), 0);

    grava_registro(arq, "c", "teste", 0);

    grava_registro(arq, "d", int_to_char(10), 0);

    grava_registro(arq, "e", int_to_char(200), 0);

    grava_registro(arq, "fffff_f", "opaopaopaopa", 0);

    printf("\nLendo\n");

    printf("a: %d\n", atoi(ler_registro(arq, "a")) );

    printf("b: %f\n", atof(ler_registro(arq, "b")) );

    printf("c: %s\n", ler_registro(arq, "c") );

    printf("d: %d\n", atoi(ler_registro(arq, "d")) );

    printf("e: %d\n", atoi(ler_registro(arq, "e")) );

    printf("fffff_f: %s\n", ler_registro(arq, "fffff_f") );

    //delete_record(arq, "a");

    system("pause");

    return 0;
}

