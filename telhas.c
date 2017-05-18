#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include"headers/db.h"

float corrigir_area(int inclinacao, float largura_base, float comprimento_base){

	float altura_cumeeira = (inclinacao / 100) * (largura_base / 2);

	float largura_corrigida = sqrt( pow( (largura_base / 2), 2 ) + pow( altura_cumeeira, 2 ) );

	return (largura_corrigida * comprimento_base) * 2;

}

int calcula_qtd_telhas(float area_telhado, float telhas_metro_quad){

	int qtd_telhas = 0;

	qtd_telhas = ceil(area_telhado * telhas_metro_quad);
	qtd_telhas += ceil(qtd_telhas * 0.05);

	return qtd_telhas;

}

float calcula_preco(int qtd, float preco_unit){


	return qtd * preco_unit;
}

int main(void){

    setlocale(LC_ALL, "");

    int usr_opt = 0,
    	inclinacao = 0,
		qtd_telhas = 0;

    float largura_base = 0,
    	  comprimento_base = 0,
		  area_telhado_corrigida = 0,
		  custo_total = 0,
		  preco_unit = 0;

    char *tipo_telha = malloc(sizeof(char *));

    do{


    	do{

			printf("Digite a largura da base do telhado(m): ");
			scanf("%f", &largura_base);

			printf("Digite o comprimento da base do telhado(m): ");
			scanf("%f", &comprimento_base);

			do{

				printf("\nInforme a inclinação desejada (deve ser maior que 30%%): ");
				scanf("%d", &inclinacao);

				if(inclinacao < 30){
					printf("\nInclinação inválida. Deve ser maior que 30%%.");
				}

			}while(inclinacao < 30);

			printf("Área calculada: %.2f", largura_base * comprimento_base);
			printf("\nInclinação: %d%%", inclinacao);

			printf("\n\nContinuar?\n 1 - Sim\n 2 - Não");
			printf("\n\nSua escolha: ");
			scanf("%d", &usr_opt);

			if(usr_opt == 2){
				system("cls");
			}

		}while(usr_opt == 2);

		printf("\n------\n\n");

		do{

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

			switch(usr_opt){

				case 1:
					/*
					Americana:
					Inclinação mínima: 38%%\n\n
					Consumo médio: 12 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Americana\n");

					if(inclinacao < 38){
						printf("Inclinação mínima recomendada: 38%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 12);

					tipo_telha = "Cerâmica_Americana";

					break;

				case 2:
					/*
					Colonial Paulista:
					Inclinação mínima: 25%%\n\n
					Consumo médio: 26 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Colonial Paulista\n");

					if(inclinacao < 25){
						printf("Inclinação mínima recomendada: 25%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 26);

					tipo_telha = "Cerâmica_Colonial_Paulista";

					break;

				case 3:
					/*
					Colonial Paulista com trava:
					Inclinação mínima: 30%%\n\n
					Consumo médio: 22 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Colonial Paulista (com trava)\n");

					if(inclinacao < 30){
						printf("Inclinação aproximada mínima recomendada: 30%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 22);

					tipo_telha = "Cerâmica_Colonial_Paulista_(com_trava)";

					break;

				case 4:
					/*
					Colonial Paulista grande:
					Inclinação mínima: 25%%\n\n
					Consumo médio: 17 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Colonial Paulista (grande)\n");

					if(inclinacao < 25){
						printf("Inclinação mínima recomendada: 25%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 17);

					tipo_telha = "Cerâmica_Colonial_Paulista_(grande)";

					break;

				case 5:
					/*
					Italiana:
					Inclinação mínima: 30%%\n\n
					Consumo médio: 14 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Italiana\n");

					if(inclinacao < 30){
						printf("Inclinação mínima recomendada: 30%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 14);

					tipo_telha = "Cerâmica_Italiana";

					break;

				case 6:
					/*
					Romana:
					Inclinação mínima: 26%%\n\n
					Consumo médio: 16 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Romana\n");

					if(inclinacao < 26){
						printf("Inclinação mínima recomendada: 26%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 16);

					tipo_telha = "Cerâmica_Romana";

					break;

				case 7:
					/*
					Romana plan:
					Inclinação mínima: 26%%\n\n
					Consumo médio: 16 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Romana Plan\n");

					if(inclinacao < 26){
						printf("Inclinação mínima recomendada: 26%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 16);

					tipo_telha = "Cerâmica_Romana_Plan";

					break;

				case 8:
					/*
					Portuguesa:
					Inclinação mínima: 30%%\n\n
					Consumo médio: 16 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Portuguesa\n");

					if(inclinacao < 30){
						printf("Inclinação mínima recomendada: 30%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 16);

					tipo_telha = "Cerâmica_Portuguesa";

					break;

				case 9:
					/*
					Francesa:
					Inclinação mínima: 36%%\n\n
					Consumo médio: 17 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Francesa\n");

					if(inclinacao < 36){
						printf("Inclinação mínima recomendada: 36%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 17);

					tipo_telha = "Cerâmica_Francesa";

					break;

				case 10:
					/*
					Germânica:
					Inclinação mínima: 45%%\n\n
					Consumo médio: 32 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Germânica\n");

					if(inclinacao < 45){
						printf("Inclinação mínima recomendada: 45%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 32);

					tipo_telha = "Cerâmica_Germânica";

					break;

				case 11:
					/*
					Uruguaia:
					Inclinação mínima: 45%%\n\n
					Consumo médio: 30 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Uruguaia\n");

					if(inclinacao < 45){
						printf("Inclinação mínima recomendada: 45%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 30);

					tipo_telha = "Cerâmica_Uruguaia";

					break;

				case 12:
					/*
					Plan:
					Inclinação mínima: 27%%\n\n
					Consumo médio: 27 unidades / m²
					*/
					printf("\n------\n");
					printf("Cerâmica Plan\n");

					if(inclinacao < 27){
						printf("Inclinação mínima recomendada: 27%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 27);

					tipo_telha = "Cerâmica_Plan";

					break;

				case 13:
					/*
					Plana:
					Inclinação mínima: 36%%\n\n
					Consumo médio: 35 unidades / m².
					*/
					printf("\n------\n");
					printf("Telha Plana\n");

					if(inclinacao < 36){
						printf("Inclinação mínima recomendada: 36%%\n");
					}

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 35);

					tipo_telha = "Telha_Plana";

					break;

				case 14:
					/*
					Amianto:
					Inclinação mínima: 15%%\n\n
					*/
					printf("\n------\n");
					printf("Amianto/Alumínio\n");

					float a_largura, a_comprimento, area_telha;

					if(inclinacao < 15){
						printf("Inclinação mínima recomendada: 15%%\n");
					}

					printf("Digite a largura da telha (cm): ");
					scanf("%f", &a_largura);

					printf("Digite a comprimento da telha  (cm): ");
					scanf("%f", &a_comprimento);

					area_telha = a_largura/100 * a_comprimento/100;

					area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base);

					qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, 1 / area_telha);

					tipo_telha = "Amianto/Alumínio";

					break;

				default:

					printf("Opção inválida.");
					Sleep(300);
					system("cls");

					break;

			}

			printf("Quantidade aproximada de telhas: %d\n\n", qtd_telhas);

			printf("Informe o preco unitário do tipo de telha escolhido: ");
			scanf("%f", &preco_unit);

			custo_total = preco_unit * qtd_telhas;

			printf("Custo total das telhas: R$ %.2f\n\n", custo_total);

			printf("\n------\n\n");

			int opt = 0;

			setbuf(stdin, NULL);

			printf("Salvar os resultados obtidos?\n1 - Sim\n2 - Não\n\nSua escolha: ");
			scanf("%d", &opt);

			if(opt == 1){

				printf("\n------\n\n");
				printf("Salvando:\n");

				int status = 0;

				status = set_record("telhas.orc", "t_telha", tipo_telha);

				if(status == 0){
					printf(" Ocorreu um erro ao salvar o tipo de telha...\n");
				}
				else if(status == 1){
					printf(" Tipo de telha salvo...\n");
				}
				else if(status == 2){
					printf(" Tipo de telha atualizado...\n");
				}

				status = set_record("telhas.orc", "q_telha", int_to_char(qtd_telhas));

				if(status == 0){
					printf(" Ocorreu um erro ao salvar a quantidade de telhas...\n");
				}
				else if(status == 1){
					printf(" Quantidade de telhas salva...\n");
				}
				else if(status == 2){
					printf(" Quantidade de telhas atualizada...\n");
				}

				status = set_record("telhas.orc", "c_telha", float_to_char(custo_total));

				if(status == 0){
					printf(" Ocorreu um erro ao salvar o custo total das telhas...\n");
				}
				else if(status == 1){
					printf(" Custo total das telhas salvo...\n");
				}
				else if(status == 2){
					printf(" Custo total das telhas atualizado...\n");
				}

				status = set_record("telhas.orc", "p_telha", float_to_char(preco_unit));

				if(status == 0){
					printf(" Ocorreu um erro ao salvar o preço unitário das telhas...\n");
				}
				else if(status == 1){
					printf(" Preço unitário das telhas salvo...\n");
				}
				else if(status == 2){
					printf(" Preço unitário das telhas atualizado...\n");
				}

				status = set_record("telhas.orc", "inclinacao", int_to_char(inclinacao));

				if(status == 0){
					printf(" Ocorreu um erro ao salvar a inclinacao do telhado...\n");
				}
				else if(status == 1){
					printf(" Inclinacao do telhado salva...\n");
				}
				else if(status == 2){
					printf(" Inclinacao do telhado atualizada...\n");
				}

				status = set_record("telhas.orc", "l_base", float_to_char(largura_base));

				if(status == 0){
					printf(" Ocorreu um erro ao salvar a largura da base do telhado...\n");
				}
				else if(status == 1){
					printf(" Largura da base do telhado salva...\n");
				}
				else if(status == 2){
					printf(" Largura da base do telhado atualizada...\n");
				}

				status = set_record("telhas.orc", "c_base", float_to_char(comprimento_base));

				if(status == 0){
					printf(" Ocorreu um erro ao salvar o comprimento da base do telhado...\n");
				}
				else if(status == 1){
					printf(" Comprimento da base do telhado salvo...\n");
				}
				else if(status == 2){
					printf(" Comprimento da base do telhado atualizado...\n");
				}

				status = set_record("telhas.orc", "ac_base", float_to_char(area_telhado_corrigida));

				if(status == 0){
					printf(" Ocorreu um erro ao salvar a área corrigida do telhado...\n");
				}
				else if(status == 1){
					printf(" Área corrigida do telhado salva...\n");
				}
				else if(status == 2){
					printf(" Área corrigida do telhado atualizada...\n");
				}

			}

			printf("\nConcluído.\n\n");

		}while(usr_opt > 14);


    	printf("\nRecalcular?\n 1 - Sim\n 2 - Não\n\nSua escolha: ");
    	scanf("%d", &usr_opt);

    	if(usr_opt == 1){
    		system("cls");
    	}

    }while(usr_opt == 1);


    return 0;
}
