#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "headers/arquivo.h"

//Constante correspondente a taxa de perda que deve ser considerada ao calcular quantidades de materiais
//a serem utilizados em uma obra.
#define TAXA_DE_PERDA 0.10

//Constantes correspondentes as chaves que ser�o salvas no arquivo
//Telhas
#define C_TELHA_TIPO "tipo_telha"
#define C_TELHA_QTDE "qtde_telha"
#define C_TELHA_CUSTO_TOTAL "custo_telha"
#define C_TELHA_PRECO_UNIT "preco_unit_telha"

//Telhado
#define C_TELHADO_INCLINACAO "inclinacao"
#define C_TELHADO_LARGURA_BASE "largura_base"
#define C_TELHADO_COMPRIMENTO_BASE "comprimento_base"
#define C_TELHADO_AREA_CORRIGIDA "area_corrigida_base"

//Madeiramento
#define C_MADEIRA_QTDE_TERCA "qtde_terca"
#define C_MADEIRA_QTDE_CAIBRO "qtde_caibro"
#define C_MADEIRA_QTDE_RIPAS "qtde_ripa"
#define C_MADEIRA_METROS_PONTALETES "metros_pontalete"
#define C_MADEIRA_METROS_CAIBROS "metros_caibro"
#define C_MADEIRA_METROS_RIPAS "metros_ripas"
#define C_MADEIRA_METROS_TERCAS "metros_tercas"
#define C_ESPACAMENTO_TERCAS "espacamento_terca"
#define C_COMRPRIMENTO_GARGA "comprimento_garga"

//Tijolos
#define C_QTDE_PAREDES "qtde_paredes"
#define C_TIJOLO_TIPO "tipo_tijolo"
#define C_TIJOLO_QTDE "qtde_total_tijolos"
#define C_TIJOLO_QTDE_METRO "qtde_tijolos_por_metro_quadrado"
#define C_TIJOLO_CUSTO_TOTAL "preco_total_tijolos"
#define C_TIJOLO_PRECO_UNIT "preco_unitario_tijolo"

//Revestimento das paredes
#define C_REVESTIMENTO_TIPO "tipo_revestimento"
#define C_REVESTIMENTO_QTDE "qtde_total_revestimento"
#define C_REVESTIMENTO_QTDE_METRO "qtde_revestimento_por_metro_quadrado"
#define C_REVESTIMENTO_CUSTO_TOTAL "preco_total_revestimento"
#define C_REVESTIMENTO_PRECO_UNIT "preco_unitario_revestimento"
#define C_REVESTIMENTO_POR_PAREDE "qtde_revestimento_por_parede"

//Tinta
#define C_GALAO_TINTA_QTDE "qtde_total_galoes_tinta"
#define C_GALAO_TINTA_CUSTO_TOTAL "preco_total_galoes_tinta"
#define C_GALAO_TINTA_PRECO_UNIT "preco_unitario_galao_tinta"

//Estruturas
#define C_ESTRUT_PROFUNDIDAE_COLUNAS "profundidade_colunas"
#define C_ESTRUT_DIAMETRO_COLUNAS "diametro_colunas"
#define C_ESTRUT_PERIMETRO_TOTAL "perimetro_total_paredes"
#define C_ESTRUT_LARGURA_BALDRAME "largura_baldrames"
#define C_ESTRUT_PROFUNDIDADE_BALDRAME "profundidade_baldrames"
#define C_ESTRUT_AREA_TOTAL_CONSTRUCAO "area_total_construcao"
#define C_ESTRUT_QUANTIDADE_CIMENTO "quantidade_cimento"
#define C_ESTRUT_ALTURA_PAREDES "altura_paredes"
#define C_ESTRUT_QTDE_FERRO_3_8 "qtde_ferro_3_8"
#define C_ESTRUT_QTDE_FERRO_3_16 "qtde_ferro_3_16"
#define C_ESTRUT_QTDE_COLUNAS "qtde_colunas"
#define C_ESTRUT_AREA_PISO "area_piso"
#define C_ESTRUT_PISO "piso"

#define C_AREA_PAREDES "area_das_paredes"

//Dados a serem gravados no arquivo
//Telhado
int g_inclinacao = 0;//Inclina��o do telhado

float g_largura_base = 0.0,//Largura da base do telhado (laje)
      g_area_telhado_corrigida = 0.0,//�rea do telhado corrigida j� incluindo a inclina��o do teclado
      g_comprimento_base = 0.0;//Comprimento da base do telhado (laje)

//Telhas
int g_qtde_telhas = 0;//Quantidade de telhas no total
char g_tipo_telha[51];

float g_custo_total = 0.0,//Custo total das telhas no final
    g_preco_unit = 0.0,//Pre�o unit�rio de cada telha
    g_qtde_telha_metro = 0.0;//Quantidade de telhas por metro quadrado

//Madeiramento
int g_qtde_tercas = 0, //Quantidade de ter�as para as duas �guas do telhado
    g_qtde_caibros = 0,// Quantidade de caibros para o telhado
    g_qtde_ripas = 0; //Quantidade de ripas para o telhado

float g_tercas_espacamento = 0.0, //Espa�amento entre as ter�as
    g_metragem_pontaletes = 0.0,
    g_metragem_caibros = 0.0,
    g_metragem_ripas = 0.0,
    g_metragem_tercas = 0.0,
    g_comprimento_garga = 0.0;

//Estruturas
float g_profundidade_colunas = 0.0,
      g_diametro_colunas = 0.0,
      g_perimetro_total = 0.0,
      g_larg_bald = 0.0,
      g_prof_bald = 0.0,
      g_area_total = 0.0,
      g_qtde_cimento = 0.0,
      g_area_piso = 0.0,
      g_alt_paredes = 0.0;

int  g_ferro[2] = {0,0}, //[1] 3/8  [0] 3/16
     g_qtde_colunas = 0,
     g_piso = 0;

char g_pisoS[51];

//Tijolos
char g_tipo_tijolo[30];

int g_qtde_paredes = 0,
    g_qtde_total_tijolos = 0,
    g_qtde_tijolo_metro_quadrado = 0;

float g_custo_total_tijolos = 0.0,
    g_preco_unit_tijolo = 0.0;

//Revestimento das paredes
char g_tipo_revestimento[20];

int g_qtde_total_revestimento = 0,
  g_qtde_revestimento_metro_quadrado = 0,
  *g_qtde_revestimento_por_parede;

float g_custo_total_revestimento = 0.0,
    g_preco_unit_revestimento = 0.0;

//Tinta
int g_qtde_total_galoes_tinta = 0;

float g_custo_total_galao_tinta = 0.0,
    g_preco_unit_galao_tinta = 0.0;

//Gerais
float *g_areas_paredes;

/* Unifica um vetor de inteiros em uma string, cada elemento sendo separado por um padr�o especificado
 *
 * Par�metros:
 * (int *) array: vetor que ser� unificado
 * (int) array_length: tamanho do vetor que ser� unificado
 * (char *) separator: padr�o que ir� separar os elementos na string
 *
 * Retorna:
 * (char *) string: string contendo o conte�do j� unificado do vetor
 */
char * split_int_array(int * array, int array_length, char * separator)
{
	int i;
	char * string = malloc(sizeof(char) * ( (array_length - 1) * strlen(separator) ) );
	strcpy(string, "");

	for(i = 0; i < array_length; i++){
		char num[10];
		sprintf(num, "%d", array[i]);

		strcat(string, num);

		if(i != array_length - 1){
			strcat(string, separator);
		}
	}

	return string;

}

/* Unifica um vetor de reais em uma string, cada elemento sendo separado por um padr�o especificado
 *
 * Par�metros:
 * (float *) array: vetor que ser� unificado
 * (int) array_length: tamanho do vetor que ser� unificado
 * (char *) separator: padr�o que ir� separar os elementos na string
 *
 * Retorna:
 * (char *) string: string contendo o conte�do j� unificado do vetor
 */
char * split_float_array(float * array, int array_length, char * separator)
{
	int i;
	char * string = malloc(sizeof(char) * ( (array_length - 1) * strlen(separator) ) );
	strcpy(string, "");

	for(i = 0; i < array_length; i++){
		char num[10];
		sprintf(num, "%f", array[i]);

		strcat(string, num);

		if(i != array_length - 1){
			strcat(string, separator);
		}
	}

	return string;

}

// Salva os registros em um arquivo .csv
void salvar_dados()
{

	char diretorio[255], valor[100], nome_arq[55];
	int erro = 0, status = 0, usr_opt = 0;

	printf("\nDigite o diret�rio para salvar o arquivo: ");
	scanf(" %199[^\n]", diretorio);

	printf("Escolher um nome para o arquivo?\n 1 - Sim\n 2 - N�o, usar um nome gen�rico\n\nSua escolha: ");
	scanf("%d", &usr_opt);

	if(usr_opt == 1){

        setbuf(stdin, NULL);

		printf("Digite o nome do arquivo: ");
		scanf("%50[^\n]", nome_arq);

	}
	else{
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		//gera o nome do arquivo baseado na data e hora atual
		sprintf(nome_arq, "orc%d-%d-%d@%d_%d_%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	}

	if( diretorio[strlen(diretorio) - 1] == '\\'){
        strcat(diretorio, nome_arq);
        strcat(diretorio, ".csv");
	}
	else{
        strcat(diretorio, "\\");
        strcat(diretorio, nome_arq);
        strcat(diretorio, ".csv");
	}

	do{

		usr_opt = 0;

		printf("\nSalvando...");

		//Telhas
            status = grava_registro(diretorio, C_TELHA_TIPO, g_tipo_telha, 1);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_telhas);
			status = grava_registro(diretorio, C_TELHA_QTDE, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_custo_total);
			status = grava_registro(diretorio, C_TELHA_CUSTO_TOTAL, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_preco_unit);
			status = grava_registro(diretorio, C_TELHA_PRECO_UNIT, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;
		//Fim Telhas

		//Telhado
			sprintf(valor, "%d", g_inclinacao);
			status = grava_registro(diretorio, C_TELHADO_INCLINACAO, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_largura_base);
			status = grava_registro(diretorio, C_TELHADO_LARGURA_BASE, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_comprimento_base);
			status = grava_registro(diretorio, C_TELHADO_COMPRIMENTO_BASE, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_area_telhado_corrigida);
			status = grava_registro(diretorio, C_TELHADO_AREA_CORRIGIDA, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;
		//Fim Telhado

		//Madeiramento
			sprintf(valor, "%d", g_qtde_tercas);
			status = grava_registro(diretorio, C_MADEIRA_QTDE_TERCA, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_caibros);
			status = grava_registro(diretorio, C_MADEIRA_QTDE_CAIBRO, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_ripas);
			status = grava_registro(diretorio, C_MADEIRA_QTDE_RIPAS, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_metragem_pontaletes);
			status = grava_registro(diretorio, C_MADEIRA_METROS_PONTALETES, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_metragem_caibros);
			status = grava_registro(diretorio, C_MADEIRA_METROS_CAIBROS, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_metragem_ripas);
			status = grava_registro(diretorio, C_MADEIRA_METROS_RIPAS, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_metragem_tercas);
			status = grava_registro(diretorio, C_MADEIRA_METROS_TERCAS, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_tercas_espacamento);
			status = grava_registro(diretorio, C_ESPACAMENTO_TERCAS, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_comprimento_garga);
			status = grava_registro(diretorio, C_COMRPRIMENTO_GARGA, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;
		//Fim Madeiramento

		//Tijolos
			status = grava_registro(diretorio, C_TIJOLO_TIPO, g_tipo_tijolo, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_paredes);
			status = grava_registro(diretorio, C_QTDE_PAREDES, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_total_tijolos);
			status = grava_registro(diretorio, C_TIJOLO_QTDE, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_tijolo_metro_quadrado);
			status = grava_registro(diretorio, C_TIJOLO_QTDE_METRO, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_custo_total_tijolos);
			status = grava_registro(diretorio, C_TIJOLO_CUSTO_TOTAL, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_preco_unit_tijolo);
			status = grava_registro(diretorio, C_TIJOLO_PRECO_UNIT, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;
		//Fim Tijolos

		//Revestimento
			status = grava_registro(diretorio, C_REVESTIMENTO_TIPO, g_tipo_revestimento, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_total_revestimento);
			status = grava_registro(diretorio, C_REVESTIMENTO_QTDE, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_revestimento_metro_quadrado);
			status = grava_registro(diretorio, C_REVESTIMENTO_QTDE_METRO, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_custo_total_revestimento);
			status = grava_registro(diretorio, C_REVESTIMENTO_CUSTO_TOTAL, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_preco_unit_revestimento);
			status = grava_registro(diretorio, C_REVESTIMENTO_PRECO_UNIT, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			strcpy(valor, split_int_array(g_qtde_revestimento_por_parede, g_qtde_paredes, "#") );
			status = grava_registro(diretorio, C_REVESTIMENTO_POR_PAREDE, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;
		//Fim Revestimento

		//Tinta
			sprintf(valor, "%d", g_qtde_total_galoes_tinta);
			status = grava_registro(diretorio, C_GALAO_TINTA_QTDE, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_custo_total_galao_tinta);
			status = grava_registro(diretorio, C_GALAO_TINTA_CUSTO_TOTAL, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_preco_unit_galao_tinta);
			status = grava_registro(diretorio, C_GALAO_TINTA_PRECO_UNIT, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;
		//Fim Tinta

		//Estruturas
			sprintf(valor, "%.2f", g_profundidade_colunas);
			status = grava_registro(diretorio, C_ESTRUT_PROFUNDIDAE_COLUNAS, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_diametro_colunas);
			status = grava_registro(diretorio, C_ESTRUT_DIAMETRO_COLUNAS, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_perimetro_total);
			status = grava_registro(diretorio, C_ESTRUT_PERIMETRO_TOTAL, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_larg_bald);
			status = grava_registro(diretorio, C_ESTRUT_LARGURA_BALDRAME, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_prof_bald);
			status = grava_registro(diretorio, C_ESTRUT_PROFUNDIDADE_BALDRAME, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_area_total);
			status = grava_registro(diretorio, C_ESTRUT_AREA_TOTAL_CONSTRUCAO, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_qtde_cimento);
			status = grava_registro(diretorio, C_ESTRUT_QUANTIDADE_CIMENTO, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_alt_paredes);
			status = grava_registro(diretorio, C_ESTRUT_ALTURA_PAREDES, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_ferro[0]);
			status = grava_registro(diretorio, C_ESTRUT_QTDE_FERRO_3_16, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_ferro[1]);
			status = grava_registro(diretorio, C_ESTRUT_QTDE_FERRO_3_8, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%d", g_qtde_colunas);
			status = grava_registro(diretorio, C_ESTRUT_QTDE_COLUNAS, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			sprintf(valor, "%.2f", g_area_piso);
			status = grava_registro(diretorio, C_ESTRUT_AREA_PISO, valor, 0);

			erro = (status == 0) ? (erro + 1) : erro;

			status = grava_registro(diretorio, C_ESTRUT_PISO, g_pisoS, 0);

			erro = (status == 0) ? (erro + 1) : erro;
		//Fim Estruturas

		strcpy(valor, split_float_array(g_areas_paredes, g_qtde_paredes, "#") );
		status = grava_registro(diretorio, C_AREA_PAREDES, valor, 0);

		erro = (status == 0) ? (erro + 1) : erro;

		if(erro > 0){
			printf("\nOcorreram %d erros ao salvar o arquivo. Deseja tentar novamente?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ", erro);
	        scanf("%d", &usr_opt);
		}

	}while(usr_opt == 1);

}

//FUN�OES CORRELATAS As ESTRUTURAS;
/*
*Fun��o metro_para_centimentro() = Evita que o usu�rio entre com um valor que ir� alterar os calculos de uma estrutura real, por exemplo:
	- Usu�rio digita 21 (o programa entende como 21 metros), mas o calculo real precisa do valor em cent�metros, entao a fun��o verificase o
  valor dado precisa ser corrigido e o devolve com a corre��o feita, caso n�o necessite de corre��o, ela apenas retorna o valor para c�lculo.
*parametros: valor real
*/
float metro_para_centimentro(float num)
{

	int aux;
	float verify;

	aux=num;
	if (aux==0 && aux!= num){
		verify = (float)num; //O numero digitado n�o � inteiro, e j� est� em "cent�metros" - n�o fazer nada
	}
	else if(aux>0 && aux == num){
		verify = num/100; //O numero digitado n�o � inteiro e est� em "Metros", por isso, deve-se dividir por 100 para se ter a base em cm
	}
	else if(aux>0 && aux != num){
		verify = num/100; //O numero digitado n�o � inteiro e est� em "Metros", por isso, deve-se dividir por 100 para se ter a base em cm
	}

	return verify;

}

/*
*calcula a quantidade necessaria de cimento para a constru��o das estruturas da casa
*
*Par�metros:
*deep = profundidade das colunas subterr�neas
*dm = diametro das colunas/subterr�neas e sobterr�neas, j� que seguem as mesmas medidas
*largura_baldrames = largura dos baldrames onde ser�o construidas as paredes
*profundidade_baldrames = profundidade dos baldrames onde ser�o construidas as paredes
*perimetro_total = soma de todas as paredes da casa em metros lineares
*altura paredes = altura das paredes para base de calculo das colunas
*g_qtde_colunas = quantidade de colunas da constru��o para calculo de cimento em m�
*/
float calcula_cimento(float deep, float dm, float largura_baldrames, float profundidade_baldrames, float perimetro_total, float altura_paredes, int qtde_colunas)
{
    float r, area_coluna_chao, area_coluna_parede, total, bald_total, tot_colunas;

    r = dm/2;

    area_coluna_chao = ( ( M_PI * pow(r, 2) ) * deep ); //�rea das colunas subterr�neas

    area_coluna_parede = ( ( M_PI * pow(r, 2) ) * altura_paredes );//�rea das colunas que sobem acompanhando as paredes

    tot_colunas = (area_coluna_chao + area_coluna_parede) * qtde_colunas;//soma das colunas parede+ch�o

    bald_total = largura_baldrames * profundidade_baldrames * perimetro_total * 2;//�rea dos baldrames, multiplica - se por 2 pois existe o baldrame que sustenta a laje da casa, este possui praticamente a mesma �rea do que sustenta as paredes

    total = bald_total + tot_colunas;//soma de todas as �reas da estrutura

    return total;

}

/*
*Calcula a quantidade de ferro 3/8 e 3/16 para a constru��o
*parametros:
*perimetro da casa
*profundidade colunaaredes
*qparedesunas
*largura baldrame
*profundidade baldrame
*/
void calcula_ferro(float perimetro, float profundidade, float altura, int qtde_colunas, float largura_baldrame, float profundidade_baldrame)
{

	int qtde_ferro_estribo, qtde_ferro, total_ferro;
	float larg_stribo, altura_stribo, espacamento = 0.0, tamanho_barra, tamanho_barra_amarra;

	do{

		printf("Digite a largura do estribo: ");
		scanf("%f", &larg_stribo);

		larg_stribo = metro_para_centimentro(larg_stribo);//VERIFICA E CONVERTE

		//printf("LARG STRIBO = %.2f\n", larg_stribo);

		if(larg_stribo > largura_baldrame-0.07){
			printf("\nA largura do estribo n�o pode ser maior que a do baldrame!\nDigite um valor at� %.2f metros\n",largura_baldrame-0.07);
		}

	}while((float)larg_stribo > (float)(largura_baldrame-0.07) );

	do{

		printf("Digite a altura do estribo: ");
		scanf("%f", &altura_stribo);

		altura_stribo = metro_para_centimentro(altura_stribo);//VERIFICA E CONVERTE

		//printf("ALTURA = %.2f\n",altura_stribo);

		if(altura_stribo > profundidade_baldrame-0.04){
			printf("\nA altura do estribo n�o pode ser maior que a do baldrame!\nDigite um valor at� %.2f metros\n",profundidade_baldrame-0.04);
		}

	}while(altura_stribo > profundidade_baldrame-0.04);

	printf("Digite o tamanho unit�rio da barra de ferro escolhida para estrutura: ");
	scanf("%f", &tamanho_barra);


	printf("Digite o tamanho unit�rio da barra de ferro escolhida para amara��o da estrutura: ");
	scanf("%f", &tamanho_barra_amarra);

	do{

		printf("Digite o espa�amento entre as amarra�oes do estribo: ");
		scanf("%f", &espacamento);

		espacamento = metro_para_centimentro(espacamento);

		//printf("ESPA�AMENTO = %.2f\n", espacamento);

		if(espacamento > 0.201){
			printf("O espa�amento n�o pode ser maior que 20 cent�metros!!! Digite um valor menor.\n");
		}

	}while(espacamento > 0.201);


	qtde_ferro_estribo = ( ( larg_stribo * 2 + altura_stribo * 2 ) * perimetro / espacamento ) / tamanho_barra_amarra;//quantidade em barras de ferro para amarra��o do estribo
	qtde_ferro = ( ( perimetro * 2 + ( profundidade + altura ) * qtde_colunas) * 4 ) / tamanho_barra;//retorna a quantidade de ferros para estruturas

	printf("Estribo: %d barras\n", qtde_ferro_estribo);
	printf("Ferro: %d barras\n", qtde_ferro);


	g_ferro[0] = qtde_ferro_estribo;
	g_ferro[1] = qtde_ferro;

}

int escolhe_piso()
{

	int piso;

	do{

		printf("\nEscolha o tipo de piso:\n1 - CER�MICA\n2 - PORCELANATO\n3 - GRANITO\n4 - M�RMORE\n5 - LAMINADO DE MADEIRA\n6 - SILESTONE\n7 - T�BUA CORRIDA\n8 - TAC�O\n9 - LAJOTA\n10 - ARD�SIA\n11 - CIMENTO QUEIMADO\n12 - PEDRA PORTUGUESA\n13 - PEDRA S�O TOM�\n14 - GRANITINA\n15 - OUTRO\n\nSua escolha: ");
		scanf("%d",&piso);

		if(piso != 15){
			switch(piso)
			{
				case 1:strcpy(g_pisoS, "CER�MICA");
				break;

				case 2:strcpy(g_pisoS, "PORCELANATO");
				break;

				case 3:strcpy(g_pisoS, "GRANITO");
				break;

				case 4:strcpy(g_pisoS, "M�RMORE");
				break;

				case 5:strcpy(g_pisoS, "LAMINADO DE MADEIRA");
				break;

				case 6:strcpy(g_pisoS, "SILESTONE");
				break;

				case 7:strcpy(g_pisoS, "T�BUA CORRIDA");
				break;

				case 8:strcpy(g_pisoS, "TAC�O");
				break;

				case 9:strcpy(g_pisoS, "LAJOTA");
				break;

				case 10:strcpy(g_pisoS, "ARD�SIA");
				break;

				case 11:strcpy(g_pisoS, "CIMENTO QUEIMADO");
				break;

				case 12:strcpy(g_pisoS, "PEDRA PORTUGUESA");
				break;

				case 13:strcpy(g_pisoS, "PEDRA S�O TOM�");
				break;

				case 14:strcpy(g_pisoS, "GRANITINA");
				break;

			}
		}

	}while(piso > 15 || piso < 0);

	return piso;

}

/*
*Fun��o calcula gastos da estrutura/pisos
*parametros:
*area_casa: a ser construido
*qt_piso: quantidade de piso em m�
*qt_cimento: quantidade de cimento em m�
*piso: tipo de piso definido na fun��o anterior
*/
void gastos(float area_casa, float area_piso, float qt_cimento, int piso)
{

	float precopiso, precoferro, precoferro_316, precocimento, precolaje, VALORpiso, VALORferro, VALORferro_316, VALORcimento, VALORlaje, total;

	do{
		printf("Digite o pre�o do m� do piso escolhido: ");
		scanf("%f", &precopiso);

		if(precopiso <= 0){
			printf("Valor inv�lido\n");
		}

	}while(precopiso <= 0);

	do{
		printf("Digite o pre�o da barra de ferro 3/8 (unidade): ");
		scanf("%f", &precoferro);

		if(precoferro <= 0){
			printf("Valor inv�lido\n");
		}

	}while(precoferro <= 0);

	do{
		printf("Digite o pre�o da barra de ferro 3/16 (unidade): ");
		scanf("%f", &precoferro_316);

		if(precoferro_316 <= 0){
			printf("Valor inv�lido\n");
		}

	}while(precoferro_316 <= 0);

	do{
		printf("Digite o preco do m� do cimento: ");
		scanf("%f", &precocimento);

		if(precocimento <= 0){
			printf("Valor inv�lido\n");
		}

	}while(precocimento <= 0);


	do{
		printf("Digite o pre�o do m� da laje: ");
		scanf("%f", &precolaje);

		if(precolaje <= 0){
			printf("Valor inv�lido\n");
		}

	}while(precolaje <= 0);

	printf("\nGASTO APROXIMADO:\n");

	VALORpiso = precopiso * area_piso;
	VALORferro = g_ferro[1] * precoferro;
	VALORferro_316 = g_ferro[0] * precoferro_316;
	VALORcimento = qt_cimento * precocimento;
	VALORlaje = area_casa * precolaje;

	printf("Valor piso: %.2f\n", VALORpiso);
	printf("Valor ferro 3/8: %.2f\n", VALORferro);
	printf("Valor ferro 3/16: %.2f\n", VALORferro_316);
	printf("Valor cimento: %.2f\n", VALORcimento);
	printf("Valor laje: %.2f\n", VALORlaje);

	total = VALORpiso + VALORferro + VALORferro_316 + VALORcimento + VALORlaje;

	switch(piso)
	{
		case 1:printf("Piso: CERAMICA");
		break;

		case 2:printf("Piso: PORCELANATO");
		break;

		case 3:printf("Piso: GRANITO");
		break;

		case 4:printf("Piso: M�RMORE");
		break;

		case 5:printf("Piso: LAMINADO DE MADEIRA");
		break;

		case 6:printf("Piso: SILESTONE");
		break;

		case 7:printf("Piso: T�BUA CORRIDA");
		break;

		case 8:printf("Piso: TAC�O");
		break;

		case 9:printf("Piso: LAJOTA");
		break;

		case 10:printf("Piso: ARD�SIA");
		break;

		case 11:printf("Piso: CIMENTO QUEIMADO");
		break;

		case 12:printf("Piso: PEDRA PORTUGUESA");
		break;

		case 13:printf("Piso: PEDRA S�O TOM�");
		break;

		case 14:printf("Piso: GRANITINA");
		break;

	}

	printf("\nGASTO TOTAL: %.2f",total);

}

/*
*Fun��o calcula gastos da estrutura/pisos -> Esta fun��o s� sera utilizada caso o piso seja digitado como uma string...
*parametros:
*area_casa: a ser construido
*area_piso: quantidade de piso em m�
*qt_cimento: quantidade de cimento em m�
*pisoS: tipo de piso definido na fun��o anterior por STRING
*/
void gastos_cond_2(float area_casa, float area_piso, float qt_cimento, char * pisoS)
{

	float precopiso, precoferro, precoferro_316, precocimento, precolaje, VALORpiso, VALORferro, VALORferro_316, VALORcimento, VALORlaje, total;

  	do{
        printf("Digite o pre�o do m� do piso escolhido: ");
        scanf("%f", &precopiso);

        if(precopiso <= 0){
            printf("Valor inv�lido\n");
        }

  	}while(precopiso <= 0);

	do{
		printf("Digite o pre�o da barra de ferro 3/8 (unidade): ");
		scanf("%f", &precoferro);

		if(precoferro <= 0){
			printf("Valor inv�lido\n");
		}

	}while(precoferro <= 0);

  	do{
  		printf("Digite o pre�o da barra de ferro 3/16 (unidade): ");
        scanf("%f", &precoferro_316);

    	if(precoferro_316 <= 0){
            printf("Valor inv�lido\n");
        }

  	}while(precoferro_316 <= 0);

  	do{
  		printf("Digite o preco do m� do cimento: ");
        scanf("%f", &precocimento);

		if(precocimento <= 0){
			printf("Valor inv�lido\n");
		}

  	}while(precocimento <= 0);


  	do{
        printf("Digite o pre�o do m� da laje: ");
        scanf("%f", &precolaje);

		if(precolaje <= 0){
			printf("Valor inv�lido\n");
		}

  	}while(precolaje <= 0);

    printf("\nGASTO APROXIMADO:\n");

	printf("valor piso: %.2f\n", VALORpiso = precopiso * area_piso);
	printf("Valor ferro 3/8: %.2f\n", VALORferro = g_ferro[1] * precoferro);
	printf("Valor ferro 3/16: %.2f\n", VALORferro_316 = g_ferro[0] * precoferro_316);
	printf("Valor cimento: %.2f\n", VALORcimento = qt_cimento * precocimento);
	printf("Valor laje: %.2f\n", VALORlaje = area_piso * precolaje);

	total = VALORpiso + VALORferro + VALORcimento + VALORlaje;

	printf("PISO: %s", pisoS);
	printf("\nGASTO TOTAL: %.2f",total);

}

/*
 * Calcula a �rea do telhado, onde ficar�o as telhas, considerando a inclina��o
 *
 * Par�metros:
 * inclinacao: Inclina��o do telhado (altura da cumeeira)
 * largura_base: largura da base do telhado (largura da laje)
 * comprimento_base: comprimento da base do telhado (comprimento da laje)
 *
 * Retorna:
 * A �rea do telhado
 */
float corrigir_area(int l_inclinacao, float l_largura_base, float l_comprimento_base)
{

  float altura_cumeeira = (l_inclinacao * (l_largura_base / 2) / 100);

  float largura_corrigida = sqrt( pow( (l_largura_base / 2), 2 ) + pow( altura_cumeeira, 2 ) );

  return (largura_corrigida * l_comprimento_base) * 2;

}

/*
 * Calcula quantidade de telhas baseado na �rea do telhado(corrigida) e a quantidade de telhas por m�
 *
 * Par�metros:
 * area_telhado: �rea do telhado
 * telhas_metro_quad: quantidade de uma telha que ocupa 1 m�
 *
 * Retorna:
 * A quantidade de telhas no total
 */
int calcula_qtde_telhas(float l_area_telhado, float l_telhas_metro_quad)
{

  int qtde_telhas = 0;

  qtde_telhas = ceil(l_area_telhado * l_telhas_metro_quad);
  qtde_telhas += ceil(qtde_telhas * 0.05);

  return qtde_telhas;

}

/*
 * Calcula o pre�o das telhas
 *
 * Par�metros:
 * qtde: quantidade de telhas calculadas
 * preco_unit: pre�o unit�rio da telha
 *
 * Retorna:
 * O pre�o das telhas no total
 */
float calcula_preco(int l_qtde, float l_preco_unit)
{

  return l_qtde * l_preco_unit;
}

/*
 * Retorna a quantidade de telhas por metro quadrado de um modelo de telha
 *
 * Retorna:
 * (float) quantidade de telha por metro quadrado do modelo de telha escolhido
 */
float get_telhas_metro_quad()
{
    int opt;
    float telhas_p_metro;

    do
    {

        printf("Escolha um m�todo:\n 1 - Dimensoes da telha\n 2 - Unidades por metro quadrado\n\nSua escolha: ");
        scanf("%d", &opt);

        switch(opt)
        {

            case 1:

                printf("\nInforme as dimensoes da telha\n");

                float a_largura, a_comprimento, area_telha;

                //Para telhas de amianto ou alum�nio as dimensoes podem variar, por isso o usu�rio � quem entra com essas dimensoes
                printf(" Digite a largura da telha (cm): ");
                scanf(" %f", &a_largura);

                printf(" Digite a comprimento da telha (cm): ");
                scanf(" %f", &a_comprimento);

                //Calcula a �rea da telha
                area_telha = (a_largura/100) * (a_comprimento/100);

                telhas_p_metro = 1 / area_telha;

                break;

            case 2:

                printf("\nInforme a quantidade de telha por metro quadrado: ");
                scanf("%f", &telhas_p_metro);

                break;

            default:
                printf("\nOp��o inv�lida\n\n");

        }

    }while(opt > 2);

    printf("\nDigite o nome da telha: ");
    scanf(" %50[^\n]", g_tipo_telha);

    printf("\n");

    return telhas_p_metro;

}

/*
 * Calcula a quantidade total de galoes de tinta necess�rios para pintar a �rea interna da constru��o
 * com base nas �reas das paredes existentes na casa, na �rea total do teto, na quantidade de dem�os
 * que se deseja aplicar e no rendimento informado no gal�o de tinta escolhido pelo usu�rio.
 *
 * Par�metros:
 * (int) qtde_paredes: quantidade total de paredes presente na constru��o.
 * (float) area_tetos: �rea total do teto.
 *
 * Retorna:
 * (int) qtde_total_galoes: quantidade total de galoes de tinta necess�rios para pintar a �rea interna da constru��o.
 */
int calcula_qtde_total_galoes_tinta(int qtde_paredes, float area_tetos) {
    int qtde_total_galoes = 0,
        qtde_demaos = 0,
        i = 0;

    float rendimento_tinta = 0.0,
          area_total = 0.0;

    do {
        printf("\nQuantidade de dem�os que ir� aplicar: ");
        scanf("%d", &qtde_demaos);
    } while (qtde_demaos <= 0);

    do {
        printf("\nRendimento da tinta informado no gal�o: ");
        scanf("%f", &rendimento_tinta);
    } while (rendimento_tinta <= 0);

    for (i=0; i<qtde_paredes; i++) {
        area_total += g_areas_paredes[i];
    }

    area_total += area_tetos;

    qtde_total_galoes = ((area_total * qtde_demaos) / rendimento_tinta);

    return qtde_total_galoes;
}

/*
 * Calcula a quantidade de revestimento (em unidades) necess�ria para revestir internamente cada
 * parede da constru��o com base nas �reas de cada parede e na quantidade de revestimento (em
 * unidades) necess�ria para revestir uma �rea de um metro quadrado.
 * Armazena a quantidade de revestimento (em unidades) necess�ria para revestir internamente cada
 * parede em uma vari�vel respons�vel por contabilizar a quantidade total de revestimento necess�ria
 * para revestir internamente todas as paredes presentes na constru��o.
 *
 * Par�metros:
 * (int) qtde_paredes: quantidade de paredes presentes na constru��o.
 */
void calcula_qtde_revestimento_por_parede() {
    int i;

    printf("\n----- Quantidade de revestimento por parede (em unidades) -----");

    for (i=0; i<g_qtde_paredes; i++) {
        g_qtde_revestimento_por_parede[i] = ceil(g_qtde_revestimento_metro_quadrado * g_areas_paredes[i]);
        g_qtde_total_revestimento += g_qtde_revestimento_por_parede[i];
        printf("\n %d� parede: %d", i+1, g_qtde_revestimento_por_parede[i]);
    }
}

/*
 * Calcula a quantidade de revestimento (em unidades) necess�ria para preencher uma �rea de um
 * metro quadrado com base nas medidas do revestimento utilizado, sendo estas fornecidas pelo usu�rio.
 *
 * Retorna:
 * (int) qtde_revestimento_por_metro_quadrado: quantidade de revestimento (em unidades) necess�rioa para
 *       preencher uma �rea de um metro quadrado.
 */
int calcula_qtde_revestimento_por_metro_quadrado() {
    int qtde_revestimento_por_metro_quadrado = 0;
    float area_revestimento = 0,
          altura_revestimento = 0,
          comprimento_revestimento = 0;

    do {
        printf("\nAltura do revestimento em metros: ");
        scanf("%f", &altura_revestimento);
    } while (altura_revestimento <= 0);

    do {
        printf("Comprimento do revestimento em metros: ");
        scanf("%f", &comprimento_revestimento);
    } while (comprimento_revestimento <=0 );

    area_revestimento = altura_revestimento * comprimento_revestimento;

    qtde_revestimento_por_metro_quadrado = ceil(1/area_revestimento);

    return qtde_revestimento_por_metro_quadrado;
}

/*
 * Exibe op�oes de revestimento para que o usu�rio possa escolher o revestimento que
 * deseja utilizar em sua obra.
 *
 * Retorna:
 * (int) tipo_revestimento: tipo de revestimento escolhido pelo usu�rio.
 */
int escolhe_tipo_revestimento() {
    int tipo_revestimento;

    printf("\n--------------------\n");
    printf("Tipos de Revestimento\n");
    printf("--------------------\n");

    do {
        printf("\nSelecione o tipo do revestimento: \n\n");

        printf(" 1 - Papel de parede\n");
        printf(" 2 - Madeira\n");
        printf(" 3 - Pastilhas\n");
        printf(" 4 - Revestimento ciment�cio\n");
        printf(" 5 - Ladrilho hidr�ulico\n");
        printf(" 6 - Azulejo comum\n");
        printf(" 7 - Outra op��o");

        printf("\n\nSua escolha: ");
        scanf("%d", &tipo_revestimento);
    } while (tipo_revestimento<1 || tipo_revestimento>6);

    return tipo_revestimento;
}

/*
 * Calcula a quantidade de tijolos necess�rios para construir cada oit�o com base nas �reas dos
 * oitoes e na quantidade de tiolos necess�rios para preencher uma �rea de um metro quadrado.
 * Armaneza a quantidade de tijolos necess�rios por oit�o em uma vari�vel respons�vel por
 * contabilizar a quantidade total de tijolos necess�rios para construir todas as paredes e oitoes
 * da constru��o.
 *
 * Par�metros:
 * (int) qtde_tijolos_por_oit�o: vetor que armazena em cada posi��o a quantidade de tijolos necess�ria para construir um oit�o.
 * (int) qtde_oitoes: quantidade total de oitoes presentes na constru��o.
 * (int) qtde_total_tijolos: vari�vel que contabiliza a quantidade total de tijolos necess�ria para toda a constru��o.
 * (float) areas_oitoes: vetor que armazena em casa posi��o a �rea de cada oit�o individualmente.

 */
void calcula_qtde_tijolos_por_oitao(int * qtde_tijolos_por_oitao, int qtde_oitoes, int * qtde_total_tijolos, float * areas_oitoes) {
    int i;

    printf("\n\n----- Quantidade de tijolos por oit�o -----");

    for (i=0; i<qtde_oitoes; i++) {
        qtde_tijolos_por_oitao[i] = ceil(g_qtde_tijolo_metro_quadrado * areas_oitoes[i]);
        *qtde_total_tijolos += qtde_tijolos_por_oitao[i];
        printf("\n %d� oit�o: %d", i+1, qtde_tijolos_por_oitao[i]);
    }
}

/*
 * Calcula a quantidade de tijolos necess�rios para construir cada parede com base nas �reas das
 * paredes e na quantidade de tiolos necess�rios para preencher uma �rea de um metro quadrado.
 * Armaneza a quantidade de tijolos necess�rios por parede em uma vari�vel respons�vel por
 * contabilizar a quantidade total de tijolos necess�rios para construir todas as paredes e oitoes
 * da constru��o.
 *
 * Par�metros:
 * (int) qtde_tijolos_por_parede: vetor que armazena em cada posi��o a quantidade de tijolos necess�ria para construir uma parede.
 * (int) qtde_paredes: quantidade total de paredes presentes na constru��o.
 * (int) qtde_total_tijolos: vari�vel que contabiliza a quantidade total de tijolos necess�ria para toda a constru��o.
 */
void calcula_qtde_tijolos_por_parede(int * qtde_tijolos_por_parede) {
    int i;

    printf("\n----- Quantidade de tijolos por parede -----");

    for (i=0; i<g_qtde_paredes; i++) {
        qtde_tijolos_por_parede[i] = ceil(g_qtde_tijolo_metro_quadrado * g_areas_paredes[i]);
        g_qtde_total_tijolos += qtde_tijolos_por_parede[i];
        printf("\n %d� parede: %d", i+1, qtde_tijolos_por_parede[i]);
    }
}

/*
 * Calcula a quantidade de tijolos necess�rios para preencher uma �rea de um metro quadrado
 * com base nas medidas do tijolo utilizado, sendo estas fornecidas pelo usu�rio.
 *
 * Retorna:
 * (int) qtde_tijolos_por_metro_quadrado: quantidade de tijolos necess�rios para preencher
 *       uma �rea de um metro quadrado.
 */
int calcula_qtde_tijolos_por_metro_quadrado() {
    int qtde_tijolos_por_metro_quadrado = 0;
    float area_tijolo = 0,
          altura_tijolo = 0,
          comprimento_tijolo = 0;

    do {
        printf("\nAltura do tijolo em metros: ");
        scanf("%f", &altura_tijolo);
    } while (altura_tijolo <= 0);

    do {
        printf("Comprimento do tijolo em metros: ");
        scanf("%f", &comprimento_tijolo);
    } while (comprimento_tijolo <=0 );

    area_tijolo = altura_tijolo * comprimento_tijolo;

    qtde_tijolos_por_metro_quadrado = ceil(1/area_tijolo);

    return qtde_tijolos_por_metro_quadrado;
}

/*
 * Calcula a �rea de um oit�o presente na casa com base no tamanho de sua altura e base,
 * sendo ambas as medidas fornecidas pelo usu�rio.
 *
 * Retorna:
 * (float) area_oitao: �rea do oit�o.
 */
float calcula_area_oitao() {
    float altura_oitao = 0,
          base_oitao = 0,
          area_oitao = 0;

    printf("\nAltura do oit�o em metros: ");
    scanf("%f", &altura_oitao);

    printf("Base do oit�o em metros: ");
    scanf("%f", &base_oitao);

    area_oitao = ((base_oitao * altura_oitao)/2);

    return area_oitao;
}

/*
 * Calcula a �rea de uma parede, descontando a �rea das aberturas presentes nela,
 * como portas e janelas.
 *
 * Par�metros:
 * (float) area_aberturas: �rea total das aberturas presentes na parede, como portas e janelas.
 *
 * Retorna:
 * (float) area_parede: �rea da parede com a �rea das aberturas descontada.
 */
float calcula_area_parede(float area_aberturas) {
    float altura_parede = 0,
          comprimento_parede = 0,
          area_parede = 0;

    do {
        printf("\nAltura da parede em metros: ");
        scanf("%f", &altura_parede);
    } while (altura_parede <= 0);

    do {
        printf("Comprimento da parede em metros: ");
        scanf("%f", &comprimento_parede);
    } while (comprimento_parede <= 0);

    area_parede = ((altura_parede * comprimento_parede) - area_aberturas);

    return area_parede;
}

/*
 * Calcula a �rea das aberturas presentes nas paredes, como portas e janelas, uma vez
 * que estas devem ser descontadas posteriormente no c�culo da �rea das paredes que
 * ir�o receber tijolos.
 *
 * Retorna:
 * (float) area_aberturas: �rea total das aberturas presentes em uma parede, como portas e janelas.
 */
float calcula_area_aberturas() {
    int qtde_aberturas = 0,
        i;

    float altura_abertura = 0,
          comprimento_abertura = 0,
          area_aberturas = 0;

    do {
        printf("\nQuantas aberturas a parede apresenta? ");
        scanf("%d", &qtde_aberturas);
    } while (qtde_aberturas <= 0);

    for (i=0; i<qtde_aberturas; i++) {
        do {
            printf("\nAltura da %d� abertura em metros: ", i+1);
            scanf("%f", &altura_abertura);
        } while (altura_abertura <= 0);

        do {
            printf("Comprimento da %d� abertura em metros: ", i+1);
            scanf("%f", &comprimento_abertura);
        } while (comprimento_abertura <= 0);

        area_aberturas += (altura_abertura * comprimento_abertura);
    }

    return area_aberturas;
}

/*
 * Exibe op�oes de tijolos para que o usu�rio possa escolher o tijolo que
 * deseja utilizar em sua obra.
 *
 * Retorna:
 * (int) tipo_tijolo: tipo de tijolo escolhido pelo usu�rio.
 */
int escolhe_tipo_tijolo() {
    int tipo_tijolo;

    printf("\n--------------------\n");
    printf("Tipos de Tijolo\n");
    printf("--------------------\n");

    do {
        printf("\nSelecione o tipo do tijolo: \n\n");

        printf(" 1 - Blocos Cer�micos\n");
        printf(" 2 - Tijolos Maci�os\n");
        printf(" 3 - Tijolos de Adobe\n");
        printf(" 4 - Tijolos Laminados\n");
        printf(" 5 - Tijolos e Blocos de Concreto\n");
        printf(" 6 - Tijolos Ecol�gicos\n");


        printf("\n\nSua escolha: ");
        scanf("%d", &tipo_tijolo);
    } while (tipo_tijolo<1 || tipo_tijolo>4);

    return tipo_tijolo;
}

/* Conta quantas ocorrencias um determinado caracter tem em uma determinada string
 *
 * Par�metros:
 * (char *) str: string onde o caracter ser� contado
 * (int) str_length: tamanho da string
 * (char) ch: caracter que ser� contado
 *
 * Retorno:
 * (int) quantidade de caracteres ch na string str
 */
int count_char(char * str, int str_length, char ch)
{
    int i, count = 0;

    for(i = 0; i < str_length; i++){
        if(str[i] == ch){
            count++;
        }
    }

    return count;
}

/* Retorna o intervalo a partir de start com length numero de caracteres como uma nova string
 *
 * Par�metros:
 * (char *) str: string da qual o sgmento do texto ser� extra�do
 * (int) str_length: tamanho da string
 * (int) start: posi��o inicial do trecho que ser� extra�do
 * (int) length: quantidade de caracteres que ser�o extra�dos a partir da posi��o inicial
 *
 * Retorno:
 * (char *) segmento do texto que foi extra�do
 */
char * strsub(char * str, int str_length, int start, int length)
{
    char * substr = malloc(sizeof(char) * (length + 1) );
    int i;

    strcpy(substr, "");

    for(i = 0; i < length; i++){
        substr[i] = str[start + i];
    }

    return substr;
}

/* Transforma uma string em um vetor de inteiros. Divide a string nos pontos demarcados por um determinado caracter e coloca em um vetor inteiro
 *
 * Par�metros:
 * (char *) string: string que ser� dividida
 * (int) string_length: tamanho da string
 * (char) delimiter: caracter que indica o ponto de divis�o
 *
 * Retorno:
 * (int *) vetor de inteiros contendo os valore obtidos da string
 */
int * split_string_int(char * string, int string_length, char delimiter)
{

    int i,
        delimiter_occurences = count_char(string, string_length, delimiter),
        last_occurence = 0,
        array_index_counter = 0;

    int * array = malloc(sizeof(int) * (delimiter_occurences + 1) );

    for(i = 0; i < string_length; i++){
        if(string[i] == delimiter || i == string_length - 1){

            if(i == string_length - 1)
                i++;

            array[array_index_counter] = atoi( strsub(string, string_length, last_occurence, i - last_occurence) );

            last_occurence = i + 1;
            array_index_counter++;
        }
    }

    return array;

}

/* Transforma uma string em um vetor de reais. Divide a string nos pontos demarcados por um determinado caracter e coloca em um vetor real
 *
 * Par�metros:
 * (char *) string: string que ser� dividida
 * (int) string_length: tamanho da string
 * (char) delimiter: caracter que indica o ponto de divis�o
 *
 * Retorno:
 * (float *) vetor de reais contendo os valore obtidos da string
 */
float * split_string_float(char * string, int string_length, char delimiter)
{
    int i,
        delimiter_occurences = count_char(string, string_length, delimiter),
        last_occurence = 0,
        array_index_counter = 0;

    float * array = malloc(sizeof(float) * (delimiter_occurences + 1) );

    for(i = 0; i < string_length; i++){
        if(string[i] == delimiter || i == string_length - 1){

            if(i == string_length - 1)
                i++;

            array[array_index_counter] = atof( strsub(string, string_length, last_occurence, i - last_occurence) );

            last_occurence = i + 1;
            array_index_counter++;
        }
    }

    return array;

}

//Segue a rotina de criar um novo or�amento
void novo_orcamento()
{

    //Geral
    int usr_opt = 0, //Usada para receber as escolhas do usu�rio quando forem apresentadas op�oes
    	chave_mestra = 0;

    char usr_rsp; //Armazena a resposa do usu�rio quando este deve responder com 'S - Sim' ou 'N - N�o'

    system("cls");

    //ESTRUTURAS
    //ALGORITMO PARA CALCULO DE ESTRUTURAS DA CONSTRUCAO CIVIL BASEADO NO SOLO
    do{

        printf("--------------------\nCIMENTO PARA ESTRUTURAS\n--------------------\n");

        do{

            printf("Digite a �rea de constru��o (em metros): ");
            scanf("%f", &g_area_total);

            if(g_area_total <= 0){
                printf("Valor inv�lido.\n");
            }

        }while(g_area_total <= 0);

        do{

            printf("Digite a profundidade das colunas de acordo com o estudo de solo (em metros): ");
            scanf("%f", &g_profundidade_colunas);

            if(g_profundidade_colunas <= 0){
                printf("Valor inv�lido.\n");
            }

        }while(g_profundidade_colunas <= 0);

        do{

            printf("Digite o di�metro das colunas(em cent�metros): ");
            scanf("%f", &g_diametro_colunas);

            if(g_diametro_colunas <= 0){
                printf("Valor inv�lido.\n");
            }

        }while(g_diametro_colunas <= 0);

        g_diametro_colunas = metro_para_centimentro(g_diametro_colunas); //Fun��o metro_para_centimentro virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usu�rio cometa algum erro de unidade de medida;

        //printf("g_diametro_colunas = %.2f\n", g_diametro_colunas); - printfs apenas para verificar a veracidade dos dados...;

        do{

            printf("Digite a largura dos baldrames (em cent�metros): ");
            scanf("%f", &g_larg_bald);

            if(g_larg_bald <= 0){
                printf("Valor inv�lido.\n");
            }

        }while(g_larg_bald <= 0);

         g_larg_bald = metro_para_centimentro(g_larg_bald); //Fun��o metro_para_centimentro virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usu�rio cometa algum erro de unidade de medida;

         //printf("LARGURA = %.2f\n", g_larg_bald);

        do{

            printf("Digite a profundidade dos baldrames (em cent�metros): ");
            scanf("%f", &g_prof_bald);

            if(g_prof_bald <= 0){
                printf("Valor inv�lido.\n");
            }

        }while(g_prof_bald <= 0);

        g_prof_bald = metro_para_centimentro(g_prof_bald);//Fun��o metro_para_centimentro virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usu�rio cometa algum erro de unidade de medida;

        //printf("g_profundidade_colunas = %.2f\n", g_prof_bald);

        do{

            printf("Entre com perimetro de todas as paredes da casa (em metros): ");
            scanf("%f", &g_perimetro_total);

            if(g_perimetro_total <= 0){
                printf("Valor inv�lido.\n");
            }

        }while(g_perimetro_total <= 0);

        do{

            printf("Altura das paredes: ");
            scanf("%f", &g_alt_paredes);

            if(g_alt_paredes <= 0){
                printf("Valor inv�lido.\n");
            }

        }while(g_alt_paredes <= 0);


        g_qtde_colunas = g_perimetro_total/3;

        g_qtde_cimento = calcula_cimento(g_profundidade_colunas, g_diametro_colunas, g_larg_bald, g_prof_bald, g_perimetro_total, g_alt_paredes, g_qtde_colunas);//calcula e armazena o valor retornado das �reas de estruturas (CALCULO CIMENTO)

        printf("\n------\n");
        printf("Conclu�do.");
        printf("\n------\n");

        printf("\nRecalcular este or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ");
        scanf("%d", &usr_opt);

  	} while (usr_opt == 1);

    do{

        printf("\n--------------------\nOR�AMENTO DAS FERRAGENS\n--------------------\n");

        calcula_ferro(g_perimetro_total, g_profundidade_colunas, g_alt_paredes, g_qtde_colunas, g_larg_bald, g_prof_bald);//fun��o calcula a quantidade necess�ria de ferro 3/8 e 3/16, armazenando os dados num vetor global.

        printf("\n------\n");
        printf("Conclu�do.");
        printf("\n------\n");

        printf("\nRecalcular este or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ");
        scanf("%d", &usr_opt);

  	} while (usr_opt == 1);

  	do{

        do{

            printf("\nDigite a �rea que deseja colocar pisos: ");
            scanf("%f", &g_area_piso);

            if(g_area_piso >= g_area_total){
                printf("A �rea do piso n�o pode ser maior do que a �rea total!!\n");
            }

        }while(g_area_piso >= g_area_total);

        // printf("Quantidade m�nima de colunas: %d\n", g_qtde_colunas);
        // printf("total: %.2f m� de cimento",g_qtde_cimento);

        g_piso = escolhe_piso();

        if(g_piso == 15){

            printf("\nDigite o piso escolhido: ");
            fflush(stdin);//limpa buffer -> string
            fgets(g_pisoS,51,stdin);
            fflush(stdin);//limpa buffer -> string

            // puts(pisoS);

            gastos_cond_2(g_area_total, g_area_piso, g_qtde_cimento, g_pisoS);

            chave_mestra = 1;
        }


        if(chave_mestra == 0){

            gastos(g_area_total, g_area_piso, g_qtde_cimento, g_piso);

        }

        printf("\n------\n");
        printf("Conclu�do.");
        printf("\n------\n");

        printf("\nRecalcular este or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ");
        scanf("%d", &usr_opt);

  	} while (usr_opt == 1);

    do
    {

    	printf("\n--------------------\nOR�AMENTO DO TELHADO\n--------------------\n");

        printf("\nBASE DO TELHADO");
        do
        {
            printf("\n------\n\n");
            //L� a largura e comprimento da base do telhado (laje)
            printf(" Digite a largura da base do telhado(m): ");
            scanf("%f", &g_largura_base);

            printf(" Digite o comprimento da base do telhado(m): ");
            scanf("%f", &g_comprimento_base);

            if(g_largura_base <= 0 || g_comprimento_base <= 0)
            {
                printf("\nA largura e comprimento da base devem ser ambos maiores que zero.\n");
            }

        }while(g_largura_base <= 0 || g_comprimento_base <= 0);

        do
        {
            //L� a inclina��o desejada para o telhado em porcentagem.
            //Com essa inclina��o ser� calculada a altura do centro do telhado (cumeerira, onde os "lados" do telhado se dividem (/|\)).
            //Essa porcentagem � calculada em cima da metade da largura da laje.
            printf(" Informe a inclina��o desejada (deve ser maior que 30%%): ");
            scanf("%d", &g_inclinacao);

            //Inclina��o abaixo de 30% n�o � normatizada
            if(g_inclinacao < 30)
            {
                printf("\nInclina��o inv�lida. Deve ser maior que 30%%.");
            }

        }while(g_inclinacao < 30);

        //Calcula a �rea do telhado considerando a inclina��o
        g_area_telhado_corrigida = corrigir_area(g_inclinacao, g_largura_base, g_comprimento_base);

        //Exibe a �rea da laje e a inclina��o calculados
        printf("\n�rea calculada: %.2f", g_largura_base * g_comprimento_base);
        printf("\nInclina��o: %d%%", g_inclinacao);
        printf("\n�rea do telhado corrigida, considerando a inclina��o: %.2f", g_area_telhado_corrigida);

        setbuf(stdin, NULL);

        printf("\n\nTELHAS");
        printf("\n------\n\n");

        g_qtde_telha_metro = get_telhas_metro_quad();

        //Calcula a quantidade de telha
        g_qtde_telhas = calcula_qtde_telhas(g_area_telhado_corrigida, g_qtde_telha_metro);

        printf("Quantidade aproximada de telhas: %d\n", g_qtde_telhas);

        do
        {

            printf("\nInforme o preco unit�rio das telhas: ");
            scanf(" %f", &g_preco_unit);

            if(g_preco_unit <= 0.0)
            {
                printf("\nO pre�o unit�rio deve ser maior que zero.\n\n");
            }

            setbuf(stdin, NULL);

        }while(g_preco_unit <= 0.0);

        //Calcula o pre�o final das telhas
        g_custo_total = calcula_preco(g_qtde_telhas, g_preco_unit);

        printf("Custo total das telhas: R$ %.2f", g_custo_total);

        //Reseta o buffer pois por algum motivo o pr�ximo scanf n�o estava sendo executado
        setbuf(stdin, NULL);

        printf("\n\nMADEIRAMENTO");
        printf("\n------\n\n");

        //Calcula a quantidade de ter�as
        printf("Ter�as:\n Digite o espa�amento das ter�as (m): ");
        scanf("%f", &g_tercas_espacamento);

        g_qtde_tercas = ceil(g_largura_base / g_tercas_espacamento);
        g_metragem_tercas = g_comprimento_base * g_qtde_tercas;

        printf(" Quantidade de ter�as de %.2f metros: %d\n", g_comprimento_base, g_qtde_tercas);
        printf(" Quantidade de metros de ter�as: %2.f", g_metragem_tercas);

        //Calcula a quantidade de pontaletes
        printf("\n\nPontaletes:\n");

        g_metragem_pontaletes = (
	        ( ( (g_largura_base / 2) * g_inclinacao ) / 100 ) * 2 +
	        ( ( ( (g_largura_base / 2) / 2 ) * g_inclinacao ) / 100 ) * 6 // 3 pontaletes em cada �gua
	    );

        printf(" Quantidade de metros de pontaletes: %.2f", g_metragem_pontaletes);

        //Calcula a quantidade de ber�os
        //Para cada pontalete h� 1 ber�o de 0.5m
        printf("\n\nBer�os:\n Quantidade de metros de ber�os: %.2f", 8 * 0.5);

        //Calcula a quantidade de madeira para a trama, que inclui os caibros e as ripas
        printf("\n\nTrama:\n");

        //Calcula a quantidade de caibros
        printf(" Caibros:\n");

        float altura_cumeeira = (g_inclinacao / 100) * (g_largura_base / 2);

        g_qtde_caibros = ceil( (g_comprimento_base / 0.5) * 2 );

        g_metragem_caibros = g_qtde_caibros * (g_largura_base / 2);

        printf("  Quantidade de caibros: %d\n", g_qtde_caibros);
        printf("  Quantidade de metros de caibro: %.2f", g_metragem_caibros );

        //Calcula a quantidade de ripas

        printf("\n Ripas:\n");

        printf("  Digite o comprimento da garga eme metros: ");
        scanf("%f", &g_comprimento_garga);

        g_qtde_ripas = 2 * ceil((g_largura_base / 2) / g_comprimento_garga);
        g_metragem_ripas = g_qtde_ripas * g_comprimento_base;

        printf("  Quantidade de ripas: %d\n", g_qtde_ripas);
        printf("  Quantidade de metros de ripas: %.2f\n", g_metragem_ripas);

        printf("\n------\n");
        printf("Conclu�do.");
        printf("\n------\n");

        printf("\nRecalcular este or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ");
        scanf("%d", &usr_opt);

    }while(usr_opt == 1);

    int tipo_tijolo = 0, //Armazena o tipo de tijolo selecionado pelo usu�rio.
        tipo_revesitmento = 0, //Armanzena o tipo de revestimento selecionado pelo usu�rio.
        qtde_paredes = 0, //Quantidade total de paredes presentes na constru��o.
        qtde_oitoes = 0, //Quantidade total de oitoes presentes na constru��o.
        i = 0; //Contador utilizado para percorrer os vetores existentes na implementa��o.

	  	do {
	    printf("--------------------\nOR�AMENTO DOS TIJOLOS\n--------------------\n");

	    do {
	        printf("Digite a quantidade de paredes que deseja construir: ");
	        scanf("%d", &g_qtde_paredes);
	    } while(g_qtde_paredes <= 0);

	    do {
	        printf("\nDigite a quantidade de oitoes presentes em sua casa: ");
	        scanf("%d", &qtde_oitoes);
	    } while(qtde_oitoes <= 0);

	    float areas_oitoes[qtde_oitoes], //Vetor que armazena a �rea unit�ria de cada oit�o em cada posi��o.
	          areas_aberturas[g_qtde_paredes]; //Vetor que armazena a �rea das aberturas presentes por parede em cada posi��o.

	    int qtde_tijolos_por_parede[g_qtde_paredes], //Vetor que armazena a quantidade de tijolos necess�ria para construir cada parede em casa posi��o.
	        qtde_tijolos_por_oitao[qtde_oitoes]; //Vetor que armazena a quantidade de tijolos necess�ria para construir cada oit�o em cada posi��o.

	    g_areas_paredes = (float *)malloc(g_qtde_paredes);

	    for (i=0; i<g_qtde_paredes; i++) {
	        printf("\n----- %d� parede -----\n", i+1);

	        do {
	            printf("\nA %d� parede apresenta aberturas como portas e janelas?", i+1);
	            printf("\n S - Sim\n N - N�o\n");
	            printf("Sua escolha: ");
	            scanf(" %c", &usr_rsp);
	        } while (usr_rsp!='S' && usr_rsp!='s' && usr_rsp!='N' && usr_rsp!='n');

	        if (usr_rsp=='S' || usr_rsp=='s') {
	            areas_aberturas[i] = calcula_area_aberturas();
	        } else {
	            areas_aberturas[i] = 0.0;
	        }

	        g_areas_paredes[i] = calcula_area_parede(areas_aberturas[i]);

	        printf("\n�rea da %d� parede, com as �reas das aberturas descontadas � de: %.2fm�\n\n", i+1, g_areas_paredes[i]);
	    }

	    for (i=0; i<qtde_oitoes; i++) {
	        printf("\n----- %d� oit�o -----\n", i+1);

	        areas_oitoes[i] = calcula_area_oitao();

	        printf("\n�rea do %d� oit�o: %.2fm�\n\n", i+1, areas_oitoes[i]);
	    }

	    tipo_tijolo = escolhe_tipo_tijolo();

	    switch (tipo_tijolo) {
	        case 1:
	            printf("\n--------------------\n");
	            printf("Blocos Cer�micos\n");
	            strcpy(g_tipo_tijolo, "Blocos Cer�micos");
	            break;

	        case 2:
	            printf("\n--------------------\n");
	            printf("Tijolos Maci�os\n");
	            strcpy(g_tipo_tijolo, "Tijolos Maci�os");
	            break;

	        case 3:
	            printf("\n--------------------\n");
	            printf("Tijolos de Adobe\n");
	            strcpy(g_tipo_tijolo, "Tijolos de Adobe");
	            break;

	        case 4:
	            printf("\n--------------------\n");
	            printf("Tijolos Laminados\n");
	            strcpy(g_tipo_tijolo, "Tijolos Laminados");
	            break;

	        case 5:
	            printf("\n--------------------\n");
	            printf("Tijolos e Blocos de Concreto\n");
	            strcpy(g_tipo_tijolo, "Tijolos e Blocos de Concreto");
	            break;

	        case 6:
	            printf("\n--------------------\n");
	            printf("Tijolos Ecol�gicos\n");
	            strcpy(g_tipo_tijolo, "Tijolos Ecol�gicos");
	            break;
	    }

	    g_qtde_tijolo_metro_quadrado = calcula_qtde_tijolos_por_metro_quadrado();

	    printf("\nRendimento: %d tijolos por metro quadrado.\n", g_qtde_tijolo_metro_quadrado);

	    do {
	        printf("\nPre�o Unit�rio do Tijolo: R$ ");
	        scanf("%f", &g_preco_unit_tijolo);
	    } while (g_preco_unit_tijolo <= 0);

	    calcula_qtde_tijolos_por_parede(qtde_tijolos_por_parede);

	    calcula_qtde_tijolos_por_oitao(qtde_tijolos_por_oitao, qtde_oitoes, &g_qtde_total_tijolos, areas_oitoes);

	    g_qtde_total_tijolos += (TAXA_DE_PERDA * g_qtde_total_tijolos);

	    printf("\n\n----- Quantidade total de tijolos -----");
	    printf("\n %d tijolos", g_qtde_total_tijolos);

	    g_custo_total_tijolos = g_preco_unit_tijolo * g_qtde_total_tijolos;
	    printf("\n\n----- Pre�o total - Tijolos -----");
	    printf("\n R$ %.2f", g_custo_total_tijolos);

        printf("\n------\n");
        printf("Conclu�do.");
        printf("\n------\n");

        printf("\nRecalcular or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ");
        scanf("%d", &usr_opt);

  	} while (usr_opt == 1);

	  	do {
	    printf("\n--------------------\nOR�AMENTO DO REVESTIMENTO DE PISO\n--------------------\n");

	    tipo_revesitmento = escolhe_tipo_revestimento();

	    switch (tipo_revesitmento) {

	        case 1:
	            printf("\n--------------------\n");
	            printf("Papel de parede\n");
	            strcpy(g_tipo_revestimento, "Papel de Parede");
	            break;

	        case 2:
	            printf("\n--------------------\n");
	            printf("Madeira\n");
				strcpy(g_tipo_revestimento, "Madeira");
	            break;

	        case 3:
	            printf("\n--------------------\n");
	            printf("Pastilhas\n");
	            strcpy(g_tipo_revestimento, "Pastilhas");
	            break;

	        case 4:
	            printf("\n--------------------\n");
	            printf("Ladrilho hidr�ulico\n");
	            strcpy(g_tipo_revestimento, "Ladrilho Hidr�ulico");
	            break;

	        case 5:
	            printf("\n--------------------\n");
	            printf("Azulejo comum\n");
	            strcpy(g_tipo_revestimento, "Azulejo Comum");
	            break;
	    }

	    g_qtde_revestimento_metro_quadrado = calcula_qtde_revestimento_por_metro_quadrado();

	    printf("\nRendimento: %d unidade(s) de revestimento por metro quadrado.\n", g_qtde_revestimento_metro_quadrado);

	    do {
	        printf("\nPre�o Unit�rio do Revestimento: R$ ");
	        scanf("%f", &g_preco_unit_revestimento);
	    } while (g_preco_unit_revestimento <= 0);

	    g_qtde_revestimento_por_parede = (int *)malloc(g_qtde_paredes);

	    calcula_qtde_revestimento_por_parede();

	    g_qtde_total_revestimento += (TAXA_DE_PERDA * g_qtde_total_revestimento);

	    printf("\n\n----- Quantidade total de revestimento -----");
	    printf("\n %d unidades de revestimento", g_qtde_total_revestimento);

	    g_custo_total_revestimento = g_preco_unit_revestimento * g_qtde_total_revestimento;
	    printf("\n\n----- Pre�o total - Revestimento -----");
	    printf("\n R$ %.2f\n", g_custo_total_revestimento);

        printf("\n------\n");
        printf("Conclu�do.");
        printf("\n------\n");

        printf("\nRecalcular or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ");
        scanf("%d", &usr_opt);

  	} while (usr_opt == 1);

	do {
	    printf("\n--------------------\nOR�AMENTO DA TINTA\n--------------------\n");

	    float area_tetos = 0.0; //Armazena a �rea total do teto da constru��o.

	    do {
	        printf("\n�rea total do teto presente na constru��o: ");
	        scanf("%f", &area_tetos);
	    } while (area_tetos <= 0);

	    g_qtde_total_galoes_tinta = calcula_qtde_total_galoes_tinta(qtde_paredes, area_tetos);
	    g_qtde_total_galoes_tinta += ceil(TAXA_DE_PERDA * g_qtde_total_galoes_tinta);

	    printf("\n\n----- Quantidade total de galoes de tinta -----");
	    printf("\n %d galoes de tinta", g_qtde_total_galoes_tinta);

	    do {
	        printf("\nPre�o Unit�rio do Gal�o de Tinta: R$ ");
	        scanf("%f", &g_preco_unit_galao_tinta);
	    } while (g_preco_unit_galao_tinta <= 0);

	    g_custo_total_galao_tinta = g_preco_unit_galao_tinta * g_qtde_total_galoes_tinta;
	    printf("\n\n----- Pre�o total - Tinta -----");
	    printf("\n R$ %.2f\n", g_custo_total_galao_tinta);

        printf("\n------\n");
        printf("Conclu�do.");
        printf("\n------\n");

        printf("\nRecalcular or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ");
        scanf("%d", &usr_opt);

  	} while (usr_opt == 1);

  	printf("\n\nDeseja salvar o or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ");
  	scanf("%d", &usr_opt);

  	if(usr_opt == 1){
  		salvar_dados();
  	}

  	printf("\n\nTudo finalizado!");

}

void carregar_orcamento()
{

    char dir[310],
        linha[101]; //vari�vel usada para armazenar temporariamente o valor lido do arquivo, especificamente para os dados relativos rs paredes, que podem ser v�rias em uma linha

    int ctrl = 0, i;

    int size; // Vari�vel que armazena o tamanho dos vetores dos dados realtivos as paredes
    float * areas_paredes; // Vetor que ir� armazenar as �reas de cada parede  lidas dos arquivos
    int * qtd_revestimento_paredes; // Vetor que ir� armazenar as quantidades de revestimento de cada parede lidas dos arquivos

    system("cls");

    do{
        ctrl = 0;
        strcpy(dir, "");

        printf("Digite o diret�rio do arquivo, incluindo o nome do arquivo: ");
        scanf(" %309[^\n]", dir);

        FILE * arq = fopen(dir, "r");

        if(arq){
            fclose(arq);

            //Estruturas
                printf("\n\nESTRUTURAS\n\n");
                printf("Profundidade das colunas: %sm\n", ler_registro(dir, C_ESTRUT_PROFUNDIDAE_COLUNAS) );
                printf("Di�metro das colunas: %sm\n", ler_registro(dir, C_ESTRUT_DIAMETRO_COLUNAS) );
                printf("Perimetro total das paredes: %sm\n", ler_registro(dir, C_ESTRUT_PERIMETRO_TOTAL) );
                printf("Largura dos baldrames: %sm\n", ler_registro(dir, C_ESTRUT_LARGURA_BALDRAME) );
                printf("Profundidade dos baldrames: %sm\n", ler_registro(dir, C_ESTRUT_PROFUNDIDADE_BALDRAME) );
                printf("�rea total de constru��o: %sm�\n", ler_registro(dir, C_ESTRUT_AREA_TOTAL_CONSTRUCAO) );
                printf("Quantidade de cimento: %sm�\n", ler_registro(dir, C_ESTRUT_QUANTIDADE_CIMENTO) );
                printf("Altura das paredes: %s\nm", ler_registro(dir, C_ESTRUT_ALTURA_PAREDES) );
                printf("Quantidade de ferro 3/8: %s\n", ler_registro(dir, C_ESTRUT_QTDE_FERRO_3_8) );
                printf("Quantidade de ferro 3/16: %s\n", ler_registro(dir, C_ESTRUT_QTDE_FERRO_3_16) );
                printf("Quantidade de colunas: %s\n", ler_registro(dir, C_ESTRUT_QTDE_COLUNAS) );
                printf("Quantidade de piso: %s\n", ler_registro(dir, C_ESTRUT_AREA_PISO) );
                printf("Piso: %s\n\n", ler_registro(dir, C_ESTRUT_PISO) );
            //Fim Estruturas

            //Tijolos
                printf("TIJOLOS\n\n");
                printf("Quantidade de paredes: %s\n", ler_registro(dir, C_QTDE_PAREDES) );

                printf("�rea das paredes:\n");

                strcpy(linha, ler_registro(dir, C_AREA_PAREDES) );

                size = count_char(linha, strlen(linha), '#') + 1;
                areas_paredes = split_string_float( linha, strlen(linha), '#' );

                for(i = 0; i < size; i++){
                    printf("  Parede %d: %.2fm�\n", i + 1, areas_paredes[i]);
                }

                printf("Tipo de tijolo: %s\n", ler_registro(dir, C_TIJOLO_TIPO) );
                printf("Quantidade total de tijolos: %s\n", ler_registro(dir, C_TIJOLO_QTDE) );
                printf("Quantidade de tijolos por m�: %s\n", ler_registro(dir, C_TIJOLO_QTDE_METRO) );
                printf("Custo total de tijolos: R$ %s\n", ler_registro(dir, C_TIJOLO_CUSTO_TOTAL) );
                printf("Pre�o unit�rio do tijolo: R$ %s\n\n", ler_registro(dir, C_TIJOLO_PRECO_UNIT) );
            //Fim Tijolos

            //Revestimento
                printf("REVESTIMENTO\n\n");
                printf("Tipo de revestimento: %s\n", ler_registro(dir, C_REVESTIMENTO_TIPO) );
                printf("Quantidade total de revestimento: %s\n", ler_registro(dir, C_REVESTIMENTO_QTDE) );
                printf("Quantidade de revestimento por m�: %s\n", ler_registro(dir, C_REVESTIMENTO_QTDE_METRO) );

                printf("Quantidade de revestimento por parede:\n");

                strcpy(linha, ler_registro(dir, C_REVESTIMENTO_POR_PAREDE) );

                size = count_char(linha, strlen(linha), '#') + 1;
                qtd_revestimento_paredes = split_string_int( linha, strlen(linha), '#' );

                for(i = 0; i < size; i++){
                    printf("  Parede %d: %d\n", i + 1, qtd_revestimento_paredes[i]);
                }

                printf("Custo total do revestimento: R$ %s\n", ler_registro(dir, C_REVESTIMENTO_CUSTO_TOTAL) );
                printf("Pre�o unit�rio do revestimento: R$ %s\n\n", ler_registro(dir, C_REVESTIMENTO_PRECO_UNIT) );
            //Fim Revestimento

            //Tinta
                printf("TINTA\n\n");
                printf("Quantidade de galoes de tinta: %s\n", ler_registro(dir, C_GALAO_TINTA_QTDE) );
                printf("Custo total dos galoes de tinta: R$ %s\n", ler_registro(dir, C_GALAO_TINTA_CUSTO_TOTAL) );
                printf("Pre�o unit�rio do gal�o de tinta: R$ %s\n\n", ler_registro(dir, C_GALAO_TINTA_PRECO_UNIT) );
            //Fim Tinta

            //Telhado
                printf("TELHADO\n\n");
                printf("Inclina��o: %s%%\n", ler_registro(dir, C_TELHADO_INCLINACAO) );
                printf("Largura da laje: %sm\n", ler_registro(dir, C_TELHADO_LARGURA_BASE) );
                printf("Comprimento da laje: %sm\n", ler_registro(dir, C_TELHADO_COMPRIMENTO_BASE) );
                printf("�rea do telhado corrigida pela inclina��o: %sm�\n\n", ler_registro(dir, C_TELHADO_AREA_CORRIGIDA) );
            //Fim Telhado

            //Madeiramento
                printf("MADEIRAMENTO DO TELHADO\n\n");
                printf("Quantidade de ter�as: %s\n", ler_registro(dir, C_MADEIRA_QTDE_TERCA) );
                printf("Quantidade de caibros: %s\n", ler_registro(dir, C_MADEIRA_QTDE_CAIBRO) );
                printf("Quantidade de ripas: %s\n", ler_registro(dir, C_MADEIRA_QTDE_RIPAS) );
                printf("Metros de pontaletes: %s\n", ler_registro(dir, C_MADEIRA_METROS_PONTALETES) );
                printf("Metros de caibros: %s\n", ler_registro(dir, C_MADEIRA_METROS_CAIBROS) );
                printf("Metros de ripas: %s\n", ler_registro(dir, C_MADEIRA_METROS_RIPAS) );
                printf("Metros de ter�as: %s\n", ler_registro(dir, C_MADEIRA_METROS_TERCAS) );
                printf("Espa�amento entre as ter�as: %sm\n", ler_registro(dir, C_ESPACAMENTO_TERCAS) );
                printf("Comprimento da garga: %sm\n\n", ler_registro(dir, C_COMRPRIMENTO_GARGA) );
            //Fim madeiramento

            //Telhas
                printf("TELHAS\n\n");
                printf("Tipo de telha: %s\n", ler_registro(dir, C_TELHA_TIPO) );
                printf("Quantidade de telhas: %s\n", ler_registro(dir, C_TELHA_QTDE) );
                printf("Custo total das telhas: R$ %s\n", ler_registro(dir, C_TELHA_CUSTO_TOTAL) );
                printf("Pre�o unit�rio das telhas: R$ %s\n\n", ler_registro(dir, C_TELHA_PRECO_UNIT) );
            //Fim Telhas

        }
        else{
            printf("\nO arquivo informado n�o existe.\n\n");
            ctrl = 1;
        }

    }while(ctrl == 1);
}

int main(void)
{

    setlocale(LC_ALL, "");

    int usr_opt;

    do{
        system("cls");

        printf("Selecione uma a��o:\n 1 - Criar um novo or�amento\n 2 - Visualizar um or�amento existente\n 3 - Ajuda\n\nSua escolha: ");
        scanf("%d", &usr_opt);

        switch(usr_opt){
            case 1:

                novo_orcamento();

                break;

            case 2:

                carregar_orcamento();

                break;

            case 3:

                system("start ajuda");

                break;

            default:
                printf("\nOp��o inv�lida\n\n");
        }

        printf("\n\n");
        system("pause");

    }while(1);

    return 1;
}

