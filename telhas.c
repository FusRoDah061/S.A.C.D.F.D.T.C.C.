#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include"headers/db.h"

//Constantes correspondentes as chaves que serão salvas no arquivo
//Telhas
#define C_TELHA_TIPO "t_telha"
#define C_TELHA_QTD "q_telha"
#define C_TELHA_CUSTO_TOTAL "c_telha"
#define C_TELHA_PRECO_UNIT "p_telha"
//Telhado
#define C_TELHADO_INCLINACAO "inclinacao"
#define C_TELHADO_LARGURA_BASE "l_base"
#define C_TELHADO_COMPRIMENTO_BASE "c_base"
#define C_TELHADO_AREA_CORRIGIDA "ac_base"

/*
 * Calcula a área do telhado, onde ficarão as telhas, considerando a inclinação
 *
 * Parâmetros:
 * inclinacao: Inclinação do telhado (altura da cumeeira)
 * largura_base: largura da base do telhado (largura da laje)
 * comprimento_base: comprimento da base do telhado (comprimento da laje)
 *
 * Retorna:
 * A área do telhado
 */
float corrigir_area(int inclinacao, float largura_base, float comprimento_base){

	float altura_cumeeira = (inclinacao / 100) * (largura_base / 2);

	float largura_corrigida = sqrt( pow( (largura_base / 2), 2 ) + pow( altura_cumeeira, 2 ) );

	return (largura_corrigida * comprimento_base) * 2;

}

/*
 * Calcula quantidade de telhas baseado na área do telhado(corrigida) e a quantidade de telhas por m²
 *
 * Parâmetros:
 * area_telhado: área do telhado
 * telhas_metro_quad: quantidade de uma telha que ocupa 1 m²
 *
 * Retorna:
 * A quantidade de telhas no total
 */
int calcula_qtd_telhas(float area_telhado, float telhas_metro_quad){

	int qtd_telhas = 0;

	qtd_telhas = ceil(area_telhado * telhas_metro_quad);
	qtd_telhas += ceil(qtd_telhas * 0.05);

	return qtd_telhas;

}

/*
 * Calcula o preço das telhas
 *
 * Parâmetros:
 * qtd: quantidade de telhas calculadas
 * preco_unit: preço unitário da telha
 *
 * Retorna:
 * O preço das telhas no total
 */
float calcula_preco(int qtd, float preco_unit){

	return qtd * preco_unit;
}

/*
 * Retorna a quantidade de telhas por metro quadrado de um modelo de telha
 *
 * Parâmetros:
 * (int) modelo: modelo da telha selecionado pelo usuário. Varia de 1 a 14.
 * (int) print: controla quando mostrar algo na tela (1 = mostrar, 0 = não mostrar).
 *
 * Retorna:
 * (float) quantidade de telha por metro quadrado do modelo de telha escolhido
 * (float) 0 caso o modelo não exista
 */
float get_telhas_metro_quad(int modelo, int print){

	switch(modelo){

		case 1:
			/*
			Americana:
			Inclinação mínima: 38%
			Consumo médio: 12 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Americana\n");
				printf("Inclinação mínima recomendada: 38%%\n");
			}

			return 12;

			break;

		case 2:
			/*
			Colonial Paulista:
			Inclinação mínima: 25%
			Consumo médio: 26 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Colonial Paulista\n");
				printf("Inclinação mínima recomendada: 25%%\n");
			}

			return 26;

			break;

		case 3:
			/*
			Colonial Paulista com trava:
			Inclinação mínima: 30%
			Consumo médio: 22 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Colonial Paulista (com trava)\n");
				printf("Inclinação aproximada mínima recomendada: 30%%\n");
			}

			return 22;

			break;

		case 4:
			/*
			Colonial Paulista grande:
			Inclinação mínima: 25%
			Consumo médio: 17 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Colonial Paulista (grande)\n");
				printf("Inclinação mínima recomendada: 25%%\n");
			}

			return 17;

			break;

		case 5:
			/*
			Italiana:
			Inclinação mínima: 30%
			Consumo médio: 14 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Italiana\n");
				printf("Inclinação mínima recomendada: 30%%\n");
			}

			return 14;

			break;

		case 6:
			/*
			Romana:
			Inclinação mínima: 26%
			Consumo médio: 16 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Romana\n");
				printf("Inclinação mínima recomendada: 26%%\n");
			}

			return 16;

			break;

		case 7:
			/*
			Romana plan:
			Inclinação mínima: 26%
			Consumo médio: 16 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Romana Plan\n");
				printf("Inclinação mínima recomendada: 26%%\n");
			}

			return 16;

			break;

		case 8:
			/*
			Portuguesa:
			Inclinação mínima: 30%
			Consumo médio: 16 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Portuguesa\n");
				printf("Inclinação mínima recomendada: 30%%\n");
			}

			return 16;

			break;

		case 9:
			/*
			Francesa:
			Inclinação mínima: 36%
			Consumo médio: 17 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Francesa\n");
				printf("Inclinação mínima recomendada: 36%%\n");
			}

			return 17;

			break;

		case 10:
			/*
			Germânica:
			Inclinação mínima: 45%
			Consumo médio: 32 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Germânica\n");
				printf("Inclinação mínima recomendada: 45%%\n");
			}

			return 32;

			break;

		case 11:
			/*
			Uruguaia:
			Inclinação mínima: 45%
			Consumo médio: 30 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Uruguaia\n");
				printf("Inclinação mínima recomendada: 45%%\n");
			}

			return 30;

			break;

		case 12:
			/*
			Plan:
			Inclinação mínima: 27%
			Consumo médio: 27 unidades / m²
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Cerâmica Plan\n");
				printf("Inclinação mínima recomendada: 27%%\n");
			}

			return 27;

			break;

		case 13:
			/*
			Plana:
			Inclinação mínima: 36%
			Consumo médio: 35 unidades / m².
			*/

			if(print == 1){
				printf("\n------\n\n");
				printf("Telha Plana\n");
				printf("Inclinação mínima recomendada: 36%%\n");
			}

			return 35;

			break;

		case 14:
			/*
			Amianto:
			Inclinação mínima: 15%
			*/
			printf("\n------\n\n");
			printf("Amianto/Alumínio\n");
			printf("Inclinação mínima recomendada: 15%%\n");

			float a_largura, a_comprimento, area_telha;

			//Para telhas de amianto ou alumínio as dimensões podem variar, por isso o usuário é quem entra com essas dimensões
			printf("Digite a largura da telha (cm): ");
			scanf("%f", &a_largura);

			printf("Digite a comprimento da telha  (cm): ");
			scanf("%f", &a_comprimento);

			//Calcula a área da telha
			area_telha = a_largura/100 * a_comprimento/100;

			return 1 / area_telha;

			break;

		default:

			return 0;

			break;

	}

}

int main(void){

    setlocale(LC_ALL, "");

    int usr_opt = 0, //Usada para receber as escolhas do usuário quando forem apresentadas opções
    	inclinacao = 0,//Inclinação do telhado
		qtd_telhas = 0,//Quantidade de telhas no total
		tipo_telha = 0,//Modelo de telha escolhida pelo usuário
		erros = 0;//Contador de erros ao salvar e ler um arquivo

    float largura_base = 0.0,//Largura da base do telhado (laje)
    	  comprimento_base = 0.0,//Comprimento da base do telhado (laje)
		  area_telhado_corrigida = 0.0,//Área do telhado corrigida já incluindo a inclinação do teclado
		  custo_total = 0.0,//Custo total das telhas no final
		  preco_unit = 0.0,//Preço unitário de cada telha
		  qtd_telha_metro = 0.0;//Quantidade de telhas por metro quadrado

    //Armazena o tipo de telha para ser salvo no arquivo
    char *dir_arquivo = malloc(sizeof(char *));

    do{
    	system("cls");

		printf("--------------------\nORÇAMENTO DO TELHADO\n--------------------\n");

		printf("Escolha uma ação:\n 1 - Novo orçamento\n 2 - Editar orçamento existente\n 3 - Sair\n\nSua escolha: ");
		scanf("%d", &usr_opt);

		if(usr_opt == 3){
			printf("\n\nFinalizando.");
			break;
		}

		switch(usr_opt){

			//Começa um novo orçamento
			case 1:

				do{

					do{

						do{
							printf("\n------\n\n");
							//Lê a largura e comprimento da base do telhado (laje)
							printf("Digite a largura da base do telhado(m): ");
							scanf("%f", &largura_base);

							printf("Digite o comprimento da base do telhado(m): ");
							scanf("%f", &comprimento_base);

							if(largura_base <= 0 || comprimento_base <= 0){
								printf("\nA largura e comprimento da base devem ser ambos maiores que zero.\n");
							}

						}while(largura_base <= 0 || comprimento_base <= 0);

						do{
							printf("\n------\n\n");
							//Lê a inclinação desejada para o telhado em porcentagem.
							//Com essa inclinação será calculada a altura do centro do telhado (cumeerira, onde os "lados" do telhado se dividem (/|\)).
							//Essa porcentagem é calculada em cima da metade da largura da laje.
							printf("Informe a inclinação desejada (deve ser maior que 30%%): ");
							scanf("%d", &inclinacao);

							//Inclinação abaixo de 30% não é normatizada
							if(inclinacao < 30){
								printf("\nInclinação inválida. Deve ser maior que 30%%.");
							}

						}while(inclinacao < 30);

						//Exibe a área da laje e a inclinação calculados
						printf("\nÁrea calculada: %.2f", largura_base * comprimento_base);
						printf("\nInclinação: %d%%", inclinacao);

						printf("\n\nContinuar?\n 1 - Sim\n 2 - Não");
						printf("\n\nSua escolha: ");
						scanf("%d", &usr_opt);

						if(usr_opt == 2){
							system("cls");
						}

					}while(usr_opt == 2);

					do{

						printf("\n------\n\n");
						printf("Selecione o tipo de telha:\n\n");

						printf(" 1 - Cerâmica Americana\n");
						printf(" 2 - Cerâmica Colonial Paulista\n");
						printf(" 3 - Cerâmica Colonial Paulista (com trava)\n");
						printf(" 4 - Cerâmica Colonial Paulista (grande)\n");
						printf(" 5 - Cerâmica Italiana\n");
						printf(" 6 - Cerâmica Romana\n");
						printf(" 7 - Cerâmica Romana Plan\n");
						printf(" 8 - Cerâmica Portuguesa\n");
						printf(" 9 - Cerâmica Francesa\n");
						printf(" 10 - Cerâmica Germânica\n");
						printf(" 11 - Cerâmica Uruguaia\n");
						printf(" 12 - Cerâmica Plan\n");
						printf(" 13 - Plana\n");
						printf(" 14 - Amianto/Alumínio");

						printf("\n\nSua escolha: ");
						scanf("%d", &usr_opt);

						if(usr_opt <= 14){
							//Salva o tipo de telha escolhido
							tipo_telha = usr_opt;
							qtd_telha_metro = get_telhas_metro_quad(tipo_telha, 1);

							//Calcula a área do telhado considerando a inclinação
							area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

							//Calcula a quantidade de telha
							qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, qtd_telha_metro);
						}
						else{
							printf("Opção inválida.");
							Sleep(300);
						}

					}while(usr_opt > 14);


					printf("\nQuantidade aproximada de telhas: %d\n", qtd_telhas);

					do{

						printf("\n------\n\n");
						printf("Informe o preco unitário do tipo de telha escolhido: ");
						scanf(" %f", &preco_unit);

						if(preco_unit <= 0.0){
							printf("\nO preço unitário deve ser maior que zero.\n");
						}

						setbuf(stdin, NULL);

					}while(preco_unit <= 0.0);

					//Calcula o preço final das telhas
					custo_total = calcula_preco(qtd_telhas, preco_unit);

					printf("Custo total das telhas: R$ %.2f", custo_total);

					printf("\n------\n\n");

					int opt = 0;

					//Reseta o buffer pois por algum motivo o próximo scanf não estava sendo executado
					setbuf(stdin, NULL);

					printf("Salvar os resultados obtidos?\n1 - Sim\n2 - Não\n\nSua escolha: ");
					scanf("%d", &opt);


					//Salva os resultados obtidos
					if(opt == 1){

						do{

							erros = 0;
							printf("\n------\n\n");
							printf("Salvando:\n");

							setbuf(stdin, NULL);

							printf("Digite um nome para o arquivo: ");
							gets(dir_arquivo);

							strcat(dir_arquivo, ".txt");

							printf("\nRegistros serão salvos em '%s'\n", dir_arquivo);

							setbuf(stdin, NULL);

							int status = 0;

							//Salva o tipo de telha
							status = set_record(dir_arquivo, C_TELHA_TIPO, int_to_char(tipo_telha));

							if(status == 0){
								erros++;
								printf(" Ocorreu um erro ao salvar o tipo de telha...\n");
							}
							else if(status == 1){
								printf(" Tipo de telha salvo...\n");
							}
							else if(status == 2){
								printf(" Tipo de telha atualizado...\n");
							}

							//Salva a quantidade de telhas
							status = set_record(dir_arquivo, C_TELHA_QTD, int_to_char(qtd_telhas));

							if(status == 0){
								erros++;
								printf(" Ocorreu um erro ao salvar a quantidade de telhas...\n");
							}
							else if(status == 1){
								printf(" Quantidade de telhas salva...\n");
							}
							else if(status == 2){
								printf(" Quantidade de telhas atualizada...\n");
							}

							//Salva o custo total das telhas
							status = set_record(dir_arquivo, C_TELHA_CUSTO_TOTAL, float_to_char(custo_total));

							if(status == 0){
								erros++;
								printf(" Ocorreu um erro ao salvar o custo total das telhas...\n");
							}
							else if(status == 1){
								printf(" Custo total das telhas salvo...\n");
							}
							else if(status == 2){
								printf(" Custo total das telhas atualizado...\n");
							}

							//Salva o preço unitário das telhas
							status = set_record(dir_arquivo, C_TELHA_PRECO_UNIT, float_to_char(preco_unit));

							if(status == 0){
								erros++;
								printf(" Ocorreu um erro ao salvar o preço unitário das telhas...\n");
							}
							else if(status == 1){
								printf(" Preço unitário das telhas salvo...\n");
							}
							else if(status == 2){
								printf(" Preço unitário das telhas atualizado...\n");
							}

							//Salva a inclinação do telhado
							status = set_record(dir_arquivo, C_TELHADO_INCLINACAO, int_to_char(inclinacao));

							if(status == 0){
								erros++;
								printf(" Ocorreu um erro ao salvar a inclinacao do telhado...\n");
							}
							else if(status == 1){
								printf(" Inclinacao do telhado salva...\n");
							}
							else if(status == 2){
								printf(" Inclinacao do telhado atualizada...\n");
							}

							//Salva a largura da base
							status = set_record(dir_arquivo, C_TELHADO_LARGURA_BASE, float_to_char(largura_base));

							if(status == 0){
								erros++;
								printf(" Ocorreu um erro ao salvar a largura da base do telhado...\n");
							}
							else if(status == 1){
								printf(" Largura da base do telhado salva...\n");
							}
							else if(status == 2){
								printf(" Largura da base do telhado atualizada...\n");
							}

							//Salva o comprimento da base
							status = set_record(dir_arquivo, C_TELHADO_COMPRIMENTO_BASE, float_to_char(comprimento_base));

							if(status == 0){
								erros++;
								printf(" Ocorreu um erro ao salvar o comprimento da base do telhado...\n");
							}
							else if(status == 1){
								printf(" Comprimento da base do telhado salvo...\n");
							}
							else if(status == 2){
								printf(" Comprimento da base do telhado atualizado...\n");
							}

							//Salva área do telhado corrigida
							status = set_record(dir_arquivo, C_TELHADO_AREA_CORRIGIDA, float_to_char(area_telhado_corrigida));

							if(status == 0){
								erros++;
								printf(" Ocorreu um erro ao salvar a área corrigida do telhado...\n");
							}
							else if(status == 1){
								printf(" Área corrigida do telhado salva...\n");
							}
							else if(status == 2){
								printf(" Área corrigida do telhado atualizada...\n");
							}

							if(erros > 0){
								printf("\n\nOcorreram %d erros ao salvar os registros. Deseja tentar novamente?\n(Registros não salvos podem causar problemas no futuro)\n 1 - Sim\n 2 - Não\n\nSua escolha: ", erros);
								scanf("%d", &usr_opt);
							}

						}while(erros > 0 && usr_opt == 1);

					}

					printf("\nConcluído.");

					printf("\n\n------\n");

					printf("\nRecalcular orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ");
					scanf("%d", &usr_opt);

					if(usr_opt == 1){
						system("cls");
					}

				}while(usr_opt == 1);

				break;

			//------------------------------
			//Carrega um orçamento existente
			case 2:

				do{
					setbuf(stdin, NULL);

					printf("\n------\n\n");
					printf("Digite o diretório do arquivo com o orçamento salvo: ");
					gets(dir_arquivo);

					printf("\nConfirmar diretório?\n'%s'\n 1 - Sim\n 2 - Não\n\nSua escolha: ", dir_arquivo);
					scanf("%d", &usr_opt);

				}while(usr_opt == 2);

				do{
					usr_opt = 0;
					erros = 0;

					//Lê os dados salvos no arquivo
					largura_base = atof( get_record(dir_arquivo, C_TELHADO_LARGURA_BASE) );

					if(largura_base == 0){
						erros++;
					}

					comprimento_base = atof( get_record(dir_arquivo, C_TELHADO_COMPRIMENTO_BASE) );

					if(comprimento_base == 0){
						erros++;
					}

					inclinacao = atoi( get_record(dir_arquivo, C_TELHADO_INCLINACAO) );

					if(inclinacao == 0){
						erros++;
					}

					tipo_telha = atoi( get_record(dir_arquivo, C_TELHA_TIPO) );

					if(tipo_telha == 0){
						erros++;
					}

					preco_unit = atof( get_record(dir_arquivo, C_TELHA_PRECO_UNIT) );

					if(preco_unit == 0){
						erros++;
					}

					printf("Registros lidos do arquivo:\n\n");
					printf(" Largura da base: %.2f\n", largura_base);
					printf(" Comprimento base: %.2f\n", comprimento_base);
					printf(" Inclinacao do telhado: %d\n", inclinacao);
					printf(" Modelo de telha: %d\n", tipo_telha);
					printf(" Preço unitário da telha: %f\n", preco_unit);

					if(erros > 0){
						printf("\n------\n\n");
						printf("Ocorreram %d erros ao ler os registros salvos. Deseja tentar novamente?\n(Não será possível prosseguir sem os registros)\n 1 - Sim\n 2 - Não\n\nSua escolha: ", erros);
						scanf("%d", &usr_opt);
					}
					else{
						printf("\nRegistros recuperados com sucesso.");
					}

				}while(usr_opt == 1);

				if(erros == 0){

					do{

						printf("\n------\n\n");
						printf("Selecione o item que deseja editar:\n");

						printf(" 1 - Dimensões do telhado\n");
						printf(" 2 - Inclinação do telhado\n");
						printf(" 3 - Modelo da telha\n");
						printf(" 4 - Preço unitário da telha\n\n");

						printf(" 5 - Salvar modificações\n");

						printf(" 6 - Voltar ao início\n");

						printf("\n\nSua escolha: ");
						scanf("%d", &usr_opt);

						if(usr_opt > 6){
							printf("Opção inválida.");
							Sleep(300);
							continue;
						}
						else if(usr_opt == 6){
							continue;
						}

						switch(usr_opt){
							//Dimensões do telhado
							case 1:
								do{
									printf("\n------\n\n");
									//Lê a largura e comprimento da base do telhado (laje)
									printf("Digite a largura da base do telhado(m): ");
									scanf("%f", &largura_base);

									printf("Digite o comprimento da base do telhado(m): ");
									scanf("%f", &comprimento_base);

									if(largura_base <= 0 || comprimento_base <= 0){
										printf("\nA largura e comprimento da base devem ser ambos maiores que zero.\n");
									}

								}while(largura_base <= 0 || comprimento_base <= 0);

								break;

							//------------------------------
							//Inclinação
							case 2:

								do{
									printf("\n------\n\n");
									//Lê a inclinação desejada para o telhado em porcentagem.
									//Com essa inclinação será calculada a altura do centro do telhado (cumeerira, onde os "lados" do telhado se dividem (/|\)).
									//Essa porcentagem é calculada em cima da metade da largura da laje.
									printf("Informe a inclinação desejada (deve ser maior que 30%%): ");
									scanf("%d", &inclinacao);

									//Inclinação abaixo de 30% não é normatizada
									if(inclinacao < 30){
										printf("\nInclinação inválida. Deve ser maior que 30%%.");
									}

								}while(inclinacao < 30);

								break;

							//------------------------------
							//Modelo da telha
							case 3:

								do{

									printf("\n------\n\n");
									printf("Selecione o tipo de telha:\n\n");

									printf(" 1 - Cerâmica Americana\n");
									printf(" 2 - Cerâmica Colonial Paulista\n");
									printf(" 3 - Cerâmica Colonial Paulista (com trava)\n");
									printf(" 4 - Cerâmica Colonial Paulista (grande)\n");
									printf(" 5 - Cerâmica Italiana\n");
									printf(" 6 - Cerâmica Romana\n");
									printf(" 7 - Cerâmica Romana Plan\n");
									printf(" 8 - Cerâmica Portuguesa\n");
									printf(" 9 - Cerâmica Francesa\n");
									printf(" 10 - Cerâmica Germânica\n");
									printf(" 11 - Cerâmica Uruguaia\n");
									printf(" 12 - Cerâmica Plan\n");
									printf(" 13 - Plana\n");
									printf(" 14 - Amianto/Alumínio");

									printf("\n\nSua escolha: ");
									scanf("%d", &usr_opt);

									if(usr_opt <= 14){
										//Salva o tipo de telha escolhido
										tipo_telha = usr_opt;
									}
									else{
										printf("Opção inválida.");
										Sleep(300);
									}

									//Obtem a quantidade de telhas por metro quadrado
									qtd_telha_metro = get_telhas_metro_quad(tipo_telha, 0);

								}while(usr_opt > 14);

								break;

							//------------------------------
							//Preço da telha
							case 4:

								do{
									printf("\n------\n\n");
									printf("Informe o preco unitário do tipo de telha escolhido: ");
									scanf("%f", &preco_unit);

									if(preco_unit <= 0){
										printf("\nO preço unitário deve ser maior que zero.\n");
									}

								}while(preco_unit <= 0);

								break;

							//------------------------------
							//Salvar alterações
							case 5:

								//Calcula a área do telhado considerando a inclinação
								area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

								//Calcula a quantidade de telha
								qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, qtd_telha_metro);

								//Calcula o preço total das telhas
								custo_total = calcula_preco(qtd_telhas, preco_unit);


								do{

									erros = 0;
									printf("\n------\n\n");
									printf("Salvando:\n");

									printf("\nRegistros serão salvos em '%s'\n", dir_arquivo);

									setbuf(stdin, NULL);

									int status = 0;

									//Salva o tipo de telha
									status = set_record(dir_arquivo, C_TELHA_TIPO, int_to_char(tipo_telha));

									if(status == 0){
										erros++;
										printf(" Ocorreu um erro ao salvar o tipo de telha...\n");
									}
									else if(status == 1){
										printf(" Tipo de telha salvo...\n");
									}
									else if(status == 2){
										printf(" Tipo de telha atualizado...\n");
									}

									//Salva a quantidade de telhas
									status = set_record(dir_arquivo, C_TELHA_QTD, int_to_char(qtd_telhas));

									if(status == 0){
										erros++;
										printf(" Ocorreu um erro ao salvar a quantidade de telhas...\n");
									}
									else if(status == 1){
										printf(" Quantidade de telhas salva...\n");
									}
									else if(status == 2){
										printf(" Quantidade de telhas atualizada...\n");
									}

									//Salva o custo total das telhas
									status = set_record(dir_arquivo, C_TELHA_CUSTO_TOTAL, float_to_char(custo_total));

									if(status == 0){
										erros++;
										printf(" Ocorreu um erro ao salvar o custo total das telhas...\n");
									}
									else if(status == 1){
										printf(" Custo total das telhas salvo...\n");
									}
									else if(status == 2){
										printf(" Custo total das telhas atualizado...\n");
									}

									//Salva o preço unitário das telhas
									status = set_record(dir_arquivo, C_TELHA_PRECO_UNIT, float_to_char(preco_unit));

									if(status == 0){
										erros++;
										printf(" Ocorreu um erro ao salvar o preço unitário das telhas...\n");
									}
									else if(status == 1){
										printf(" Preço unitário das telhas salvo...\n");
									}
									else if(status == 2){
										printf(" Preço unitário das telhas atualizado...\n");
									}

									//Salva a inclinação do telhado
									status = set_record(dir_arquivo, C_TELHADO_INCLINACAO, int_to_char(inclinacao));

									if(status == 0){
										erros++;
										printf(" Ocorreu um erro ao salvar a inclinacao do telhado...\n");
									}
									else if(status == 1){
										printf(" Inclinacao do telhado salva...\n");
									}
									else if(status == 2){
										printf(" Inclinacao do telhado atualizada...\n");
									}

									//Salva a largura da base
									status = set_record(dir_arquivo, C_TELHADO_LARGURA_BASE, float_to_char(largura_base));

									if(status == 0){
										erros++;
										printf(" Ocorreu um erro ao salvar a largura da base do telhado...\n");
									}
									else if(status == 1){
										printf(" Largura da base do telhado salva...\n");
									}
									else if(status == 2){
										printf(" Largura da base do telhado atualizada...\n");
									}

									//Salva o comprimento da base
									status = set_record(dir_arquivo, C_TELHADO_COMPRIMENTO_BASE, float_to_char(comprimento_base));

									if(status == 0){
										erros++;
										printf(" Ocorreu um erro ao salvar o comprimento da base do telhado...\n");
									}
									else if(status == 1){
										printf(" Comprimento da base do telhado salvo...\n");
									}
									else if(status == 2){
										printf(" Comprimento da base do telhado atualizado...\n");
									}

									//Salva área do telhado corrigida
									status = set_record(dir_arquivo, C_TELHADO_AREA_CORRIGIDA, float_to_char(area_telhado_corrigida));

									if(status == 0){
										erros++;
										printf(" Ocorreu um erro ao salvar a área corrigida do telhado...\n");
									}
									else if(status == 1){
										printf(" Área corrigida do telhado salva...\n");
									}
									else if(status == 2){
										printf(" Área corrigida do telhado atualizada...\n");
									}

									if(erros > 0){
										printf("\n\nOcorreram %d erros ao salvar os registros. Deseja tentar novamente?\n(Registros não salvos podem causar problemas no futuro)\n 1 - Sim\n 2 - Não\n\nSua escolha: ", erros);
										scanf("%d", &usr_opt);
									}

								}while(erros > 0 && usr_opt == 1);

								printf("\nOrçamento atualizado.");

								break;

						}

					}while(1);

				}

				break;

			//------------------------------
			default:

				printf("Opção inválida.");
				Sleep(300);
				//system("cls");

				break;

		}//switch(usr_opt)

    }while(1);

    return 0;
}
