#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Escreve um registro no arquivo ou atualiza esse registro se ele já existir
 *
 * Parâmetros:
 * (char *) dir: diretório  do arquivo que será lido
 * (char *) chave: identificador do registro a ser inserido
 * (char *) valor: valor do registro a ser inserido
 * (int) novo: 1 para limpar todo o conteúdo do arquivo
 *             0 para adicionar ao conteúdo já existente no arquivo
 *
 * Retorna:
 * (int) 0: erro
 * (int) 1: registro inserido
 */
int grava_registro(char * dir, char * chave, char * valor, int novo)
{

    FILE * arq;

    //Verifica se oarquivo deve ser limpo ou não
    //Em caso positivo, o arquivo é aberto um modo escrita, e isso causa o conteúdo do arquivo a ser apagado
    //Em caso negativo, o arquivo é aberto em modo anexar, assim o conteúdo não é modificado
    if(novo == 1){

         arq = fopen(dir, "w+");

    }
    else if(novo == 0){

         arq = fopen(dir, "a+");

    }

    //Verifica se o arquivo existe/foi aberto
    if(arq != NULL){

        //As funções fprintf e fputs não funcionaram.
        //fprintf(arq, "%s\n", strcat( strcat(chave, " "), valor ) );
        //fputs( strcat( strcat(chave, " "), strcat(valor, "\n") ), arq);

        //Unifica o conteudo a ser escrito no arquivo em uma só variável
        char linha[50];
        strcpy(linha, "");
        strcat(linha, chave);
        strcat(linha, ";");
        strcat(linha, valor);
        strcat(linha, "\n");
        //printf("linha: %s", linha);

        int i = 0;

        //Escreve o conteúdo no arquivo caracter por caracter
        while(linha[i] != '\0'){
            fputc(linha[i], arq);
            i++;
        }

        rewind(arq);
        fclose(arq);

        return 1;
    }

    rewind(arq);
    fclose(arq);
    return 0;

}

/* Lê um registro do arquivo
 *
 * Parâmetros:
 * (char *) dir: diretório  do arquivo que será lido
 * (char *) chave: identificador do registro buscado
 *
 * Retorna:
 * (char *): valor do registro, ou NULL caso o registro ou arquivo não existe
 */
char * ler_registro(char * dir, char * chave)
{
    FILE * arq = fopen(dir, "r");

    //Verifica se o arquivo existe
    if(arq != NULL){

        do{
            //É necessário ler a chave e o valor, independentemente do segundo ser usado ou não, para que o cursor se desloque no arquivo, caso contrário, o fim do arquivo nunca será atingido

            char chave_lida[25];
            char * chave_valor = malloc(sizeof(char) * 25);

             //Lê a chave e o valor no arquivo
            fscanf(arq, " %24[^;];%24[^\n]", chave_lida, chave_valor);


            if( strncmp(chave_lida, chave, 25) == 0 ){

                rewind(arq);
                fclose(arq);
                return (char *)chave_valor;

            }

        }while(!feof(arq));

    }

    rewind(arq);
    fclose(arq);
    //Retorna um valor nulo caso o arquivo não exista ou a chave procurada não exista
    return NULL;
}
