#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<wchar.h>
#include"parse.h"

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

	do{
		//L� um caracter do arquivo
		ch = fgetc(file);

		//Verifica se chegou no final da linha (\n) e incrementa +1 no contador de linhas
		if(ch == '\n'){

			line_count++;

		}

	}while(!feof(file));

	rewind(file);
	return line_count;

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
		 *line = malloc(sizeof(char *)),
		 *in_val = malloc(sizeof(char *)),
		 *file_content = malloc(sizeof(char *));

	int i = 1,
		total_lines;

	if(file != NULL){

		total_lines = get_file_line_count(file);

		strcpy(file_content, "");

		//L� todo o arquivo e salva o conte�do deste me mem�ria, para depois reescrever esse conte�do salvo atualizado
		do{

			if(i <= total_lines){
				//L� a chave e o seu valor do arquivo
				fscanf(file, "%s", in_key);
				fscanf(file, "%s", in_val);

				printf("\ni: %d\ntotal_lines: %d\nin_key: %s\nin_val: %s\n", i, total_lines, in_key, in_val);

				//Compara a chave lida com a chave em busca
				if(strcmp(in_key, key) == 0){
					//Se as chaves forem iguais, salva o novo valor, ao inv�s do valor atual

					strcpy(line, in_key);
					strcat(line, " ");
					//Atualiza o valor
					strcat(line, new_val);
					strcat(line, "\n");

					strcat(file_content, line);

					printf("if: ");
					printf("\nfile_content: %s", file_content);
				}
				else{

					//Se as chaves forem diferentes, n�o modifica nada
					strcpy(line, in_key);
					strcat(line, " ");
					//N�o atualiza o valor
					strcat(line, in_val);
					strcat(line, "\n");

					strcat(file_content, line);

					printf("else: ");
					printf("\nfile_content: %s", file_content);
				}

				printf("\nline: %s\n---", line);

			}
			else{
				//L� a �ltima linha do arquivo para sair do do...while
				fscanf(file, "%s", in_key);
			}

			i++;

		}while(!feof(file));

		fclose(file);

		printf("\nfim:\nfile_content: %s", file_content);

		printf("\n1");

		file = fopen("temp.txt", "w+");

		if(file != NULL){

			printf("\n2");

			//Reescreve o conte�do no arquivo, agora com o valor atualizado
			fprintf(file, "%s", file_content);

			printf("\n221");
			//fputs(file_content, file);

			printf("\n4");

			fclose(file);

			remove(file_name);

			rename("temp.txt", file_name);

			free(key);
			free(file_name);
			free(in_key);
			free(in_val);
			free(line);
			free(file_content);

			return 1;

		}

		free(key);
		free(file_name);
		free(in_key);
		free(in_val);
		free(line);
		free(file_content);

		return 0;

	}

	printf("nao abriu");

	free(key);
	free(file_name);
	free(in_key);
	free(in_val);
	free(line);
	free(file_content);

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

	if(file != NULL){

		//Subtrai 1 do total de linhas pois 1 registros ser� removido
		int total_lines = get_file_line_count(file) - 1,
			i = 0;

        char *in_key = malloc(sizeof(char *)),
        	 *content = malloc(sizeof(char *)),
			 *in_val = malloc(sizeof(char *));

		//Vetor que ir� manter o conte�do do arquivo salvo
        char *conteudo[total_lines];

		rewind(file);

		do{

			//L� a chave e o valor da chave
			fscanf(file, "%s %s", in_key, in_val);

			//Compara a chave lida com a chave em busca
			if(strcmp(in_key, key) != 0){

				//Se as chaves forem diferentes, salva em mem�ria
				//Isso � o mesmo que remover a chave do arquivo
				strcpy(content, in_key);
				strcat(content, " ");
				strcat(content, in_val);

				conteudo[i] = malloc(sizeof(char *));
				conteudo[i] = content;

				i++;
			}

		}while(!feof(file));

		fclose(file);

		file = fopen(file_name, "w");

		//Reescreve o conte�do no arquivo, agora com o registro apagado
		for(i = 0; i < total_lines; i++){
            fprintf(file, "%s\n", conteudo[i]);
		}

		for(i = 0; i < total_lines; i++){
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

	if(file != NULL){

		//Percorre o arquivo para verificar se a chave j� existe
		do{

			//L� a chave atual
			fscanf(file, "%s", in_key);

			//E compara a chave com a chave que ser� inserida
			if(strcmp(in_key, key) == 0){

				fclose(file);

				int stat = update_record(file_name, key, val);

				free(key);
				free(file_name);
				free(in_key);
				free(val);

				return (stat == 1) ? 2 : 0;
			}
			else{

				fscanf(file, "%s", in_key);

			}

		}while(!feof(file));

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

    rewind(file);

    char *in_key = malloc(sizeof(char *)),
		 *val = malloc(sizeof(char *));

    //Verifica se o arquivo existe
    if(file != NULL){

    	//L� o arquivo at� o fim
		do{

			setbuf(stdin, NULL);
			//L� a chave
			fscanf(file, "%s", in_key);

			//Compara a chave lida com a chave em busca
			if(strcmp(in_key, key) == 0){

				setbuf(stdin, NULL);
				//L� o valor da chave
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
				setbuf(stdin, NULL);
				fscanf(file, "%s", val);
			}

		}while(!feof(file));

    }

	fclose(file);

	free(key);
	free(file_name);
	free(in_key);
	free(val);

    return NULL;

}
