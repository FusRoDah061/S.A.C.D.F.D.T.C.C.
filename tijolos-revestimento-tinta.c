#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

//Constante correspondente � taxa de perda que deve ser considerada ao calcular quantidades de materiais
//a serem utilizados em uma obra.
#define TAXA_DE_PERDA 0.10

/*
 * Calcula a quantidade total de gal�es de tinta necess�rios para pintar a �rea interna da constru��o
 * com base nas �reas das paredes existentes na casa, na �rea total do teto, na quantidade de dem�os
 * que se deseja aplicar e no rendimento informado no gal�o de tinta escolhido pelo usu�rio.
 *
 * Par�metros:
 * (float) areas_paredes: vetor que cont�m em cada posi��o a �rea de cada parede presente na constru��o.
 * (int) qtde_paredes: quantidade total de paredes presente na constru��o.
 * (float) area_tetos: �rea total do teto.
 *
 * Retorna:
 * (int) qtde_total_galoes: quantidade total de gal�es de tinta necess�rios para pintar a �rea interna da constru��o.
 */
int calcula_qtde_total_galoes_tinta(float * areas_paredes, int qtde_paredes, float area_tetos) {
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
        area_total += areas_paredes[i];
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
 * (int) qtde_revestimento_por_parede: vetor que armazena em casa posi��o a quantidade de revestimento (em unidades) necess�ria para revestir uma parede.
 * (int) qtde_paredes: quantidade de paredes presentes na constru��o.
 * (int) qtde_total_revestimento: vari�vel que contabiliza a quantidade total de revestimento para toda a constru��o.
 * (float) areas_paredes: vetor que armazena em casa posi��o a �rea de cada parede individualmente.
 * (int) qtde_revestimento_por_metro_quadrado: quantidade de revestimento necess�ria para preencher uma �rea de um metro quadrado.
 */
void calcula_qtde_revestimento_por_parede(int * qtde_revestimento_por_parede, int qtde_paredes, int * qtde_total_revestimento, float * areas_paredes, int qtde_revestimento_por_metro_quadrado) {
    int i;

    printf("\n----- Quantidade de revestimento por parede (em unidades) -----");

    for (i=0; i<qtde_paredes; i++) {
        qtde_revestimento_por_parede[i] = ceil(qtde_revestimento_por_metro_quadrado * areas_paredes[i]);
        *qtde_total_revestimento += qtde_revestimento_por_parede[i];
        printf("\n %d� parede: %d", i+1, qtde_revestimento_por_parede[i]);
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
 * Exibe op��es de revestimento para que o usu�rio possa escolher o revestimento que
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
 * oit�es e na quantidade de tiolos necess�rios para preencher uma �rea de um metro quadrado.
 * Armaneza a quantidade de tijolos necess�rios por oit�o em uma vari�vel respons�vel por
 * contabilizar a quantidade total de tijolos necess�rios para construir todas as paredes e oit�es
 * da constru��o.
 *
 * Par�metros:
 * (int) qtde_tijolos_por_oit�o: vetor que armazena em cada posi��o a quantidade de tijolos necess�ria para construir um oit�o.
 * (int) qtde_oitoes: quantidade total de oit�es presentes na constru��o.
 * (int) qtde_total_tijolos: vari�vel que contabiliza a quantidade total de tijolos necess�ria para toda a constru��o.
 * (float) areas_oit�es: vetor que armazena em casa posi��o a �rea de cada oit�o individualmente.
 * (int) qtde_tijolos_por_metro_quadrado: quantidade de tijolos necess�ria para preencher uma �rea de um metro quadrado.
 */
void calcula_qtde_tijolos_por_oitao(int * qtde_tijolos_por_oitao, int qtde_oitoes, int * qtde_total_tijolos, float * areas_oitoes, int qtde_tijolos_por_metro_quadrado) {
    int i;

    printf("\n\n----- Quantidade de tijolos por oit�o -----");

    for (i=0; i<qtde_oitoes; i++) {
        qtde_tijolos_por_oitao[i] = ceil(qtde_tijolos_por_metro_quadrado * areas_oitoes[i]);
        *qtde_total_tijolos += qtde_tijolos_por_oitao[i];
        printf("\n %d� oit�o: %d", i+1, qtde_tijolos_por_oitao[i]);
    }
}

/*
 * Calcula a quantidade de tijolos necess�rios para construir cada parede com base nas �reas das
 * paredes e na quantidade de tiolos necess�rios para preencher uma �rea de um metro quadrado.
 * Armaneza a quantidade de tijolos necess�rios por parede em uma vari�vel respons�vel por
 * contabilizar a quantidade total de tijolos necess�rios para construir todas as paredes e oit�es
 * da constru��o.
 *
 * Par�metros:
 * (int) qtde_tijolos_por_parede: vetor que armazena em cada posi��o a quantidade de tijolos necess�ria para construir uma parede.
 * (int) qtde_paredes: quantidade total de paredes presentes na constru��o.
 * (int) qtde_total_tijolos: vari�vel que contabiliza a quantidade total de tijolos necess�ria para toda a constru��o.
 * (float) areas_paredes: vetor que armazena em casa posi��o a �rea de cada parede individualmente.
 * (int) qtde_tijolos_por_metro_quadrado: quantidade de tijolos necess�ria para preencher uma �rea de um metro quadrado.
 */
void calcula_qtde_tijolos_por_parede(int * qtde_tijolos_por_parede, int qtde_paredes, int * qtde_total_tijolos, float * areas_paredes, int qtde_tijolos_por_metro_quadrado) {
    int i;

    printf("\n----- Quantidade de tijolos por parede -----");

    for (i=0; i<qtde_paredes; i++) {
        qtde_tijolos_por_parede[i] = ceil(qtde_tijolos_por_metro_quadrado * areas_paredes[i]);
        *qtde_total_tijolos += qtde_tijolos_por_parede[i];
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
 * Exibe op��es de tijolos para que o usu�rio possa escolher o tijolo que
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

        printf(" 1 - Blocos\n");
        printf(" 2 - Tijolos Cer�micos\n");
        printf(" 3 - Tijolos Maci�os\n");
        printf(" 4 - Outra op��o");

        printf("\n\nSua escolha: ");
        scanf("%d", &tipo_tijolo);
    } while (tipo_tijolo<1 || tipo_tijolo>4);

    return tipo_tijolo;
}

void main() {
    setlocale(LC_ALL, "");

    int tipo_tijolo = 0, //Armazena o tipo de tijolo selecionado pelo usu�rio.
        tipo_revesitmento = 0, //Armanzena o tipo de revestimento selecionado pelo usu�rio.
        qtde_paredes = 0, //Quantidade total de paredes presentes na constru��o.
        qtde_oitoes = 0, //Quantidade total de oit�es presentes na constru��o.
        qtde_tijolos_por_metro_quadrado = 0, //Quantidade de tijolos necess�ria para preencher uma �rea de um metro quadrado.
        qtde_revestimento_por_metro_quadrado = 0, //Quantidade de revestimento (em unidades) necess�ria para preencher uma �rea de um metro quadrado.
        qtde_total_tijolos = 0, //Quantidade total de tijolos utilizada na constru��o.
        qtde_total_revestimento = 0, //Quantidade total de revestimento (em unidades) utilizada na constru��o.
        qtde_total_galoes_tinta = 0, //Quanidade total de gal�es de tinta necess�ria para pintar a �rea interna da casa.
        i = 0; //Contador utilizado para percorrer os vetores existentes na implementa��o.

    float preco_unitario_tijolo = 0.0, //Pre�o unir�rio do tijolo fornecido pelo usu�rio.
          preco_total_tijolos = 0.0, //Custo total dos tijolos utilizados na constru��o.
          preco_unitario_revestimento = 0.0, //Pre�o unit�rio do revestimento fornecido pelo usu�rio.
          preco_total_revestimento = 0.0, //Custo total do revestimento utilizado na constru��o.
          preco_unitario_galao_tinta = 0.0, //Pre�o unit�trio do gal�o de tinta.
          preco_total_galao_tinta = 0.0; //Cusuto total de todos os gal�es de tinta utilizados na constru��o.

    char usr_rsp; //Armazena a resposta do usu�rio quando este deve responder com 'S - Sim' ou 'N - N�o'.

    printf("------------------------------------------------------------------------\n");
    printf("Or�amento de tijolos, revestimento e tinta para as paredes\n");
    printf("------------------------------------------------------------------------\n");


    do {
        printf("Digite a quantidade de paredes que deseja construir: ");
        scanf("%d", &qtde_paredes);
    } while(qtde_paredes <= 0);

    do {
        printf("\nDigite a quantidade de oit�es presentes em sua casa: ");
        scanf("%d", &qtde_oitoes);
    } while(&qtde_oitoes <= 0);

    float areas_paredes[qtde_paredes], //Vetor que armazena a �rea unit�ria de cada parede (com desconto das �reas das aberturas presentes) em cada posi��o.
          areas_oitoes[qtde_oitoes], //Vetor que armazena a �rea unit�ria de cada oit�o em cada posi��o.
          areas_aberturas[qtde_paredes], //Vetor que armazena a �rea das aberturas presentes por parede em cada posi��o.
          area_tetos = 0.0; //Armazena a �rea total do teto da constru��o.

    int qtde_tijolos_por_parede[qtde_paredes], //Vetor que armazena a quantidade de tijolos necess�ria para construir cada parede em casa posi��o.
        qtde_tijolos_por_oitao[qtde_oitoes], //Vetor que armazena a quantidade de tijolos necess�ria para construir cada oit�o em cada posi��o.
        qtde_revestimento_por_parede[qtde_paredes]; //Vetor que armazena a quantidade de revestimento necess�ria para preencher cada parede em cada posi��o.

    for (i=0; i<qtde_paredes; i++) {
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

        areas_paredes[i] = calcula_area_parede(areas_aberturas[i]);

        printf("\n�rea da %d� parede, com as �reas das aberturas descontadas � de: %.2fm�\n\n", i+1, areas_paredes[i]);
    }

    for (i=0; i<qtde_oitoes; i++) {
        printf("\n----- %d� oit�o -----\n", i+1);

        areas_oitoes[i] = calcula_area_oitao();

        printf("\n�rea do %d� oit�o: %.2fm�\n\n", i+1, areas_oitoes[i]);
    }

    printf("\n\n------------------------------------------------------------------------\n");
    printf("Or�amento de Tijolos\n");
    printf("------------------------------------------------------------------------\n");

    tipo_tijolo = escolhe_tipo_tijolo();

    switch (tipo_tijolo) {
        case 1:
            printf("\n--------------------\n");
            printf("Blocos\n");
            break;

        case 2:
            printf("\n--------------------\n");
            printf("Tijolos Cer�micos\n");
            break;

        case 3:
            printf("\n--------------------\n");
            printf("Tijolos Maci�os\n");
            break;
    }

    qtde_tijolos_por_metro_quadrado = calcula_qtde_tijolos_por_metro_quadrado();

    printf("\nRendimento: %d tijolos por metro quadrado.\n", qtde_tijolos_por_metro_quadrado);

    do {
        printf("\nPre�o Unit�rio do Tijolo: R$ ");
        scanf("%f", &preco_unitario_tijolo);
    } while (preco_unitario_tijolo <= 0);

    calcula_qtde_tijolos_por_parede(qtde_tijolos_por_parede, qtde_paredes, &qtde_total_tijolos, areas_paredes, qtde_tijolos_por_metro_quadrado);

    calcula_qtde_tijolos_por_oitao(qtde_tijolos_por_oitao, qtde_oitoes, &qtde_total_tijolos, areas_oitoes, qtde_tijolos_por_metro_quadrado);

    qtde_total_tijolos += (TAXA_DE_PERDA * qtde_total_tijolos);

    printf("\n\n----- Quantidade total de tijolos -----");
    printf("\n %d tijolos", qtde_total_tijolos);

    preco_total_tijolos = preco_unitario_tijolo * qtde_total_tijolos;
    printf("\n\n----- Pre�o total - Tijolos -----");
    printf("\n R$ %.2f", preco_total_tijolos);

    printf("\n\n------------------------------------------------------------------------\n");
    printf("Or�amento de Revestimento\n");
    printf("------------------------------------------------------------------------\n");

    tipo_revesitmento = escolhe_tipo_revestimento();

    switch (tipo_revesitmento) {

        case 1:
            printf("\n--------------------\n");
            printf("Papel de parede\n");
            break;

        case 2:
            printf("\n--------------------\n");
            printf("Madeira\n");
            break;

        case 3:
            printf("\n--------------------\n");
            printf("Pastilhas\n");
            break;

        case 4:
            printf("\n--------------------\n");
            printf("Revestimento ciment�cio\n");
            break;

        case 5:
            printf("\n--------------------\n");
            printf("Ladrilho hidr�ulico\n");
            break;

        case 6:
            printf("\n--------------------\n");
            printf("Azulejo comum\n");
            break;
    }

    qtde_revestimento_por_metro_quadrado = calcula_qtde_revestimento_por_metro_quadrado();

    printf("\nRendimento: %d unidade(s) de revestimento por metro quadrado.\n", qtde_revestimento_por_metro_quadrado);

    do {
        printf("\nPre�o Unit�rio do Revestimento: R$ ");
        scanf("%f", &preco_unitario_revestimento);
    } while (preco_unitario_revestimento <= 0);

    calcula_qtde_revestimento_por_parede(qtde_revestimento_por_parede, qtde_paredes, &qtde_total_revestimento, areas_paredes, qtde_revestimento_por_metro_quadrado);

    qtde_total_revestimento += (TAXA_DE_PERDA * qtde_total_revestimento);

    printf("\n\n----- Quantidade total de revestimento -----");
    printf("\n %d unidades de revestimento", qtde_total_revestimento);

    preco_total_revestimento = preco_unitario_revestimento * qtde_total_revestimento;
    printf("\n\n----- Pre�o total - Revestimento -----");
    printf("\n R$ %.2f\n", preco_total_revestimento);

    printf("\n\n------------------------------------------------------------------------\n");
    printf("Or�amento de Tinta\n");
    printf("------------------------------------------------------------------------\n");

    do {
        printf("\n�rea total do teto presenta na constru��o: ");
        scanf("%f", &area_tetos);
    } while (area_tetos <= 0);

    qtde_total_galoes_tinta = calcula_qtde_total_galoes_tinta(areas_paredes, qtde_paredes, area_tetos);
    qtde_total_galoes_tinta += ceil(TAXA_DE_PERDA * qtde_total_galoes_tinta);

    printf("\n\n----- Quantidade total de gal�es de tinta -----");
    printf("\n %d gal�es de tinta", qtde_total_galoes_tinta);

    do {
        printf("\nPre�o Unit�rio do Gal�o de Tinta: R$ ");
        scanf("%f", &preco_unitario_galao_tinta);
    } while (preco_unitario_galao_tinta <= 0);

    preco_total_galao_tinta = preco_unitario_galao_tinta * qtde_total_galoes_tinta;
    printf("\n\n----- Pre�o total - Tinta -----");
    printf("\n R$ %.2f\n", preco_total_galao_tinta);
}
