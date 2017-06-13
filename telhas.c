#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>

//Constantes correspondentes as chaves que serão salvas no arquivo
//Telhas
#define C_TELHA_TIPO "tipo_telha"
#define C_TELHA_QTD "qtd_telha"
#define C_TELHA_CUSTO_TOTAL "custo_telha"
#define C_TELHA_PRECO_UNIT "preco_unit_telha"
//Telhado
#define C_TELHADO_INCLINACAO "inclinacao"
#define C_TELHADO_LARGURA_BASE "larg_base"
#define C_TELHADO_COMPRIMENTO_BASE "compr_base"
#define C_TELHADO_AREA_CORRIGIDA "area_corr_base"
//Madeiramento
#define C_MADEIRA_QTD_TERCA "qtd_terca"
#define C_MADEIRA_QTD_CAIBRO "qtd_caibro"
#define C_MADEIRA_QTD_RIPAS "qtd_ripa"
#define C_MADEIRA_METROS_PONTALETES "metros_pontalete"
#define C_MADEIRA_METROS_CAIBROS "metros_caibro"
#define C_MADEIRA_METROS_RIPAS "metros_ripas"
#define C_MADEIRA_METROS_TERCAS "metros_tercas"
#define C_ESPACAMENTO_TERCAS "espacamento_terca"
#define C_COMRPRIMENTO_GARGA "compr_garga"

#define C_QTD_DADOS 16

//Dados a serem gravados no arquivo
//Telhado
int g_inclinacao = 0;//Inclinação do telhado

float g_largura_base = 0.0,//Largura da base do telhado (laje)
    g_area_telhado_corrigida = 0.0,//Área do telhado corrigida já incluindo a inclinação do teclado
    g_comprimento_base = 0.0;//Comprimento da base do telhado (laje)

//Telhas
int g_qtd_telhas = 0;//Quantidade de telhas no total

float g_custo_total = 0.0,//Custo total das telhas no final
    g_preco_unit = 0.0,//Preço unitário de cada telha
    g_qtd_telha_metro = 0.0;//Quantidade de telhas por metro quadrado

//Madeiramento
int g_qtd_tercas = 0, //Quantidade de terças para as duas águas do telhado
    g_qtd_caibros = 0,// Quantidade de caibros para o telhado
    g_qtd_ripas = 0; //Quantidade de ripas para o telhado

float g_tercas_espacamento = 0.0, //Espaçamento entre as terças
    g_metragem_pontaletes = 0.0,
    g_metragem_caibros = 0.0,
    g_metragem_ripas = 0.0,
    g_metragem_tercas = 0.0,
    g_comprimento_garga = 0.0;

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
float corrigir_area(int l_inclinacao, float l_largura_base, float l_comprimento_base)
{

	float altura_cumeeira = (l_inclinacao * (l_largura_base / 2) / 100);

	float largura_corrigida = sqrt( pow( (l_largura_base / 2), 2 ) + pow( altura_cumeeira, 2 ) );

	return (largura_corrigida * l_comprimento_base) * 2;

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
int calcula_qtd_telhas(float l_area_telhado, float l_telhas_metro_quad)
{

	int qtd_telhas = 0;

	qtd_telhas = ceil(l_area_telhado * l_telhas_metro_quad);
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
float calcula_preco(int l_qtd, float l_preco_unit)
{

	return l_qtd * l_preco_unit;
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

        printf("Escolha um método:\n 1 - Dimensões da telha\n 2 - Unidades por metro quadrado\n\nSua escolha: ");
        scanf("%d", &opt);

        switch(opt)
        {

            case 1:

                printf("\nInforme as dimensões da telha\n");

                float a_largura, a_comprimento, area_telha;

                //Para telhas de amianto ou alumínio as dimensões podem variar, por isso o usuário é quem entra com essas dimensões
                printf(" Digite a largura da telha (cm): ");
                scanf(" %f", &a_largura);

                printf(" Digite a comprimento da telha  (cm): ");
                scanf(" %f", &a_comprimento);

                //Calcula a área da telha
                area_telha = a_largura/100 * a_comprimento/100;

                telhas_p_metro = 1 / area_telha;

                break;

            case 2:

                printf("\nInforme a quantidade de telha por metro quadrado: ");
                scanf("%f", &telhas_p_metro);

                break;

            default:
                printf("\nOpção inválida\n\n");

        }

    }while(opt > 2);

    printf("\n");

    return telhas_p_metro;

}

int main(void)
{
    setlocale(LC_ALL, "");

    //Geral
    int usr_opt = 0, //Usada para receber as escolhas do usuário quando forem apresentadas opções
    	erros = 0;//Contador de erros ao salvar e ler um arquivo

    do
    {
    	system("cls");

		printf("--------------------\nORÇAMENTO DO TELHADO\n--------------------\n");

        printf("\nBASE DO TELHADO");
        do
        {
            printf("\n------\n\n");
            //Lê a largura e comprimento da base do telhado (laje)
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
            //Lê a inclinação desejada para o telhado em porcentagem.
            //Com essa inclinação será calculada a altura do centro do telhado (cumeerira, onde os "lados" do telhado se dividem (/|\)).
            //Essa porcentagem é calculada em cima da metade da largura da laje.
            printf(" Informe a inclinação desejada (deve ser maior que 30%%): ");
            scanf("%d", &g_inclinacao);

            //Inclinação abaixo de 30% não é normatizada
            if(g_inclinacao < 30)
            {
                printf("\nInclinação inválida. Deve ser maior que 30%%.");
            }

        }while(g_inclinacao < 30);

        //Calcula a área do telhado considerando a inclinação
        g_area_telhado_corrigida = corrigir_area(g_inclinacao, g_largura_base, g_comprimento_base);

        //Exibe a área da laje e a inclinação calculados
        printf("\nÁrea calculada: %.2f", g_largura_base * g_comprimento_base);
        printf("\nInclinação: %d%%", g_inclinacao);
        printf("\nÁrea do telhado corrigida, considerando a inclinação: %.2f", g_area_telhado_corrigida);

        setbuf(stdin, NULL);

        printf("\n\nTELHAS");
        printf("\n------\n\n");

        g_qtd_telha_metro = get_telhas_metro_quad();

        //Calcula a quantidade de telha
        g_qtd_telhas = calcula_qtd_telhas(g_area_telhado_corrigida, g_qtd_telha_metro);

        printf("Quantidade aproximada de telhas: %d\n", g_qtd_telhas);

        do
        {

            printf("\nInforme o preco unitário das telhas: ");
            scanf(" %f", &g_preco_unit);

            if(g_preco_unit <= 0.0)
            {
                printf("\nO preço unitário deve ser maior que zero.\n\n");
            }

            setbuf(stdin, NULL);

        }while(g_preco_unit <= 0.0);

        //Calcula o preço final das telhas
        g_custo_total = calcula_preco(g_qtd_telhas, g_preco_unit);

        printf("Custo total das telhas: R$ %.2f", g_custo_total);

        //Reseta o buffer pois por algum motivo o próximo scanf não estava sendo executado
        setbuf(stdin, NULL);

        printf("\n\nMADEIRAMENTO");
        printf("\n------\n\n");

        //Calcula a quantidade de terças
        printf("Terças:\n Digite o espaçamento das terças (m): ");
        scanf("%f", &g_tercas_espacamento);

        g_qtd_tercas = ceil(g_largura_base / g_tercas_espacamento);
        g_metragem_tercas = g_comprimento_base * g_qtd_tercas;

        printf(" Quantidade de terças de %.2f metros: %d\n", g_comprimento_base, g_qtd_tercas);
        printf(" Quantidade de metros de terças: %2.f", g_metragem_tercas);

        //Calcula a quantidade de pontaletes
        printf("\n\nPontaletes:\n");

        g_metragem_pontaletes = (
				( ( (g_largura_base / 2) * g_inclinacao ) / 100 ) * 2 +
				( ( ( (g_largura_base / 2) / 2 ) * g_inclinacao ) / 100 ) * 6 // 3 pontaletes em cada água
			);

        printf(" Quantidade de metros de pontaletes: %.2f", g_metragem_pontaletes);

        //Calcula a quantidade de berços
        //Para cada pontalete há 1 berço de 0.5m
        printf("\n\nBerços:\n Quantidade de metros de berços: %.2f", 8 * 0.5);

        //Calcula a quantidade de madeira para a trama, que inclui os caibros e as ripas
        printf("\n\nTrama:\n");

        //Calcula a quantidade de caibros
        printf(" Caibros:\n");

        float altura_cumeeira = (g_inclinacao / 100) * (g_largura_base / 2);

        g_qtd_caibros = ceil( (g_comprimento_base / 0.5) * 2 );

        g_metragem_caibros = g_qtd_caibros * (g_largura_base / 2);

        printf("  Quantidade de caibros: %d\n", g_qtd_caibros);
        printf("  Quantidade de metros de caibro: %.2f", g_metragem_caibros );

        //Calcula a quantidade de ripas

        printf("\n Ripas:\n");

        printf("  Digite o comprimento da garga eme metros: ");
        scanf("%f", &g_comprimento_garga);

        g_qtd_ripas = 2 * ceil((g_largura_base / 2) / g_comprimento_garga);
        g_metragem_ripas = g_qtd_ripas * g_comprimento_base;

        printf("  Quantidade de ripas: %d\n", g_qtd_ripas);
        printf("  Quantidade de metros de ripas: %.2f\n", g_metragem_ripas);

        printf("\n------\n");
        printf("Concluído.");
        printf("\n------\n");

        printf("\nRecalcular orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ");
        scanf("%d", &usr_opt);

        if(usr_opt == 1)
        {
            system("cls");
        }

    }while(usr_opt == 1);

    return 0;
}
