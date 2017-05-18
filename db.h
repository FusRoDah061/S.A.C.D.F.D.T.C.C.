#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<wchar.h>
#include"parse.h"

#define MAX_RECORD_SIZE 102
#define MAX_ITEM_SIZE 51

/**
 * Biblioteca para adicionar, remover, atualizar, e apagar registros em um arquivo de texto simples.
 * Os registros s�o armazenados como "chave valor"
 */

/*
 * Obt�m a quantidade de linhas em um arquivo
 *
 * Par�metros:
 * file: arquivo do qual as linhas ser�o contadas
 *
 * Retorna:
 * (int) n�mero de linhas no arquivo
 * (int) 0: erro
 */
int get_file_line_count(FILE *file){

	int line_count = 0;

	char ch;

	if(file){

		do{
			//L� um caracter do arquivo
			ch = fgetc(file);

			//Verifica se chegou no final da linha (\n) e incrementa +1 no contador de linhas
			if(ch == '\n'){

				line_count++;

			}

		}while(!feof(file));

		return line_count;

	}

	return 0;

}


/*
 * Atualiza um registro no arquivo
 *
 * Par�metros:
 * file_name: Diret�rio + nome do arquivo onde o regitro est�
 * key: chave do registro a ser buscado
 * new_val: novo valor para a chave
 *
 * Retorna:
 * (int) 1: atualizou o registro
 * (int) 0: erro
 */
int update_record(char *file_name, char *key, char *new_val){

	FILE *file = fopen(file_name, "r");

	char *in_key = malloc(sizeof(char *)),
		 *content = malloc(sizeof(char *)),
		 *in_val = malloc(sizeof(char *));

	if(file){

		int total_lines = get_file_line_count(file),
			i = 0;

		//Vetor que ir� manter o conte�do do arquivo salvo
		char **conteudo = malloc(sizeof(char *) * total_lines);

		rewind(file);

		i = 0;

		for(i = 0; i < total_lines; i++){

			//L� a chave
			fscanf(file, "%s", in_key);

			//L� o valor da chave
			fscanf(file, "%s", in_val);

			//Compara a chave lida com a chave em busca
			if(strcmp(in_key, key) == 0){
				//Se as chaves forem iguais, salva o novo valor, ao inv�s do valor atual

				strcat(content, in_key);
				strcat(content, " ");
				strcat(content, new_val);

				strcpy(conteudo[i], content);

				//DEBUG
				//printf("\n\n\nconteudo[i]=%s\ncontent=%s\nin_key=%s\nin_val=%s\n\n", conteudo[i], content, in_key, new_val);

			}
			else{

				//Se as chaves forem diferentes, n�o modifica nada
				strcat(content, in_key);
				strcat(content, " ");
				strcat(content, in_val);

				strcpy(conteudo[i], content);

			}

		}

		fclose(file);

		file = fopen(file_name, "w");

		//Reescreve o conte�do no arquivo, agora com o valor atualizado
		for(i = 0; i < total_lines; i++){

			fprintf(file, "%s\n", conteudo[i]);
			free(conteudo[i]);
		}

		fclose(file);

		free(key);
		free(file_name);
		free(in_key);
		free(in_val);
		free(content);

		return 1;

	}

	free(key);
	free(file_name);
	free(in_key);
	free(in_val);
	free(content);

	return 0;

}


/*
 * Remove um registro
 *
 * Par�metros:
 * file_name: arquivo com o registro
 * key: chave do registro
 *
 * Retorna:
 * (int) 0: erro
 * (int) 1: Removeu registro
 */
int delete_record(char *file_name, char *key){

	FILE *file = fopen(file_name, "r");

	if(file){

		int total_lines = get_file_line_count(file),
			i = 0;

        char *in_key = malloc(sizeof(char *)),
        	 *content = malloc(sizeof(char *)),
			  *in_val = malloc(sizeof(char *));

		//Vetor que ir� manter o conte�do do arquivo salvo
        char **conteudo = malloc(sizeof(char*) * total_lines);

		rewind(file);

		i = 0;

		do{

			//L� a chave
			fscanf(file, "%s", in_key);

			//L� o valor da chave
			fscanf(file, "%s", in_val);

			//Compara a chave lida com a chave em busca
			if(strcmp(in_key, key) != 0){

				//Se as chaves forem diferentes, salva em mem�ria
				//Isso � o mesmo que remover a chave do arquivo
				strcat(content, in_key);
				strcat(content, " ");
				strcat(content, in_val);

				strcpy(conteudo[i], content);

				i++;
			}

		}while(!feof(file));

		fclose(file);

		file = fopen(file_name, "w");

		//Reescreve o conte�do no arquivo, agora com o registro apagado
		for(i = 0; i < total_lines; i++){

            fprintf(file, "%s\n", conteudo[i]);
            free(conteudo[i]);

		}

		fclose(file);

		return 1;

		free(key);
		free(file_name);
		free(in_key);

	}
	else{
		return 0;

		free(key);
		free(file_name);
	}

	return 0;
}

/*
 * Adiciona um registro do tipo texto.
 *
 * Par�metros:
 * file_name: Diret�rio + nome do arquivo onde o regitro ser� inserido
 * key: nome da chave para o registro
 * val: valor do registro
 * append: valor inteiro 1 para adicionar o registro ao final do arquivo ou 0 para apagar todo o arquivo e inserir o registro
 *
 * Retorna:
 * (int) 0: erro
 * (int) 1: adicionou registro
 * (int) 2: atualizou registro
 */
int set_record(char *file_name, char *key, char *val){

	//Abre o arquivo em modo de leitura, escrita e cria o arquivo se necess�rio
	FILE *file = fopen(file_name, "a+");

	char *in_key = malloc(sizeof(char *));

	if(file){

		//Percorre o arquivo para verificar se a chave j� existe
		do{

			//L� a chave atual
			fscanf(file, "%s", in_key);

			//E compara a chave com a chave que ser� inserida
			if(strcmp(in_key, key) == 0){

				update_record(file_name, key, val);

				free(key);
				free(file_name);
				free(in_key);
				free(val);

				return 2;

			}
			else{

				fscanf(file, "%s", in_key);

			}

		}while(!feof(file));

		fclose(file);

		file = fopen(file_name, "a");

		//Escreve o registro no arquivo
		fprintf(file, "%s %s\n", key, val);

		fclose(file);

		free(key);
		free(file_name);
		free(in_key);
		free(val);

		return 1;

	}

	free(key);
	free(file_name);
	free(in_key);
	free(val);

	return 0;

}


/*
 * L� um registro do arquivo
 *
 * Par�metros:
 * file_name: Diret�rio + nome do arquivo onde o regitro est�
 * key: chave do registro a ser buscado
 *  *
 * Retorna:
 * (char *) o valor da chave ou nada se a chave n�o existir
 */
char * get_record(char *file_name, char *key){

    FILE *file = fopen(file_name, "r");

    char *in_key = malloc(sizeof(char *)),
		 *val = malloc(sizeof(char *));

    //Verifica se o arquivo existe
    if(file){
    	//L� o arquivo at� o fim
		do{

			//L� o valor da chave
			fscanf(file, "%s", in_key);

			//Compara a chave lida com a chave em busca
			if(strcmp(in_key, key) == 0){
				//Caso sejam iguais, l� o valor dessa chave

				fscanf(file, "%s", val);

				//fecha o arquivo
				fclose(file);

				free(key);
				free(file_name);
				free(in_key);

				//Retorna o valor da chave
				return val;

			}
			else{
				//Caso n�o seja, l� o valor da chave, para que na pr�xima itera��o a pr�xima chave seja lida
				fscanf(file, "%s", val);

			}

		}while(!feof(file));

    }

	fclose(file);
	free(key);
	free(file_name);

    return "";

}
