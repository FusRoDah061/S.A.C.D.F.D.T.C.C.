#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

//Constante correspondente à taxa de perda que deve ser considerada ao calcular quantidades de materiais
//a serem utilizados em uma obra.
#define TAXA_DE_PERDA 0.10

/*
 * Calcula a quantidade total de galões de tinta necessários para pintar a área interna da construção
 * com base nas áreas das paredes existentes na casa, na área total do teto, na quantidade de demãos
 * que se deseja aplicar e no rendimento informado no galão de tinta escolhido pelo usuário.
 *
 * Parâmetros:
 * (float) areas_paredes: vetor que contém em cada posição a área de cada parede presente na construção.
 * (int) qtde_paredes: quantidade total de paredes presente na construção.
 * (float) area_tetos: área total do teto.
 *
 * Retorna:
 * (int) qtde_total_galoes: quantidade total de galões de tinta necessários para pintar a área interna da construção.
 */
int calcula_qtde_total_galoes_tinta(float * areas_paredes, int qtde_paredes, float area_tetos) {
    int qtde_total_galoes = 0,
        qtde_demaos = 0,
        i = 0;

    float rendimento_tinta = 0.0,
          area_total = 0.0;

    do {
        printf("\nQuantidade de demãos que irá aplicar: ");
        scanf("%d", &qtde_demaos);
    } while (qtde_demaos <= 0);

    do {
        printf("\nRendimento da tinta informado no galão: ");
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
 * Calcula a quantidade de revestimento (em unidades) necessária para revestir internamente cada
 * parede da construção com base nas áreas de cada parede e na quantidade de revestimento (em
 * unidades) necessária para revestir uma área de um metro quadrado.
 * Armazena a quantidade de revestimento (em unidades) necessária para revestir internamente cada
 * parede em uma variável responsável por contabilizar a quantidade total de revestimento necessária
 * para revestir internamente todas as paredes presentes na construção.
 *
 * Parâmetros:
 * (int) qtde_revestimento_por_parede: vetor que armazena em casa posição a quantidade de revestimento (em unidades) necessária para revestir uma parede.
 * (int) qtde_paredes: quantidade de paredes presentes na construção.
 * (int) qtde_total_revestimento: variável que contabiliza a quantidade total de revestimento para toda a construção.
 * (float) areas_paredes: vetor que armazena em casa posição a área de cada parede individualmente.
 * (int) qtde_revestimento_por_metro_quadrado: quantidade de revestimento necessária para preencher uma área de um metro quadrado.
 */
void calcula_qtde_revestimento_por_parede(int * qtde_revestimento_por_parede, int qtde_paredes, int * qtde_total_revestimento, float * areas_paredes, int qtde_revestimento_por_metro_quadrado) {
    int i;

    printf("\n----- Quantidade de revestimento por parede (em unidades) -----");

    for (i=0; i<qtde_paredes; i++) {
        qtde_revestimento_por_parede[i] = ceil(qtde_revestimento_por_metro_quadrado * areas_paredes[i]);
        *qtde_total_revestimento += qtde_revestimento_por_parede[i];
        printf("\n %dª parede: %d", i+1, qtde_revestimento_por_parede[i]);
    }
}

/*
 * Calcula a quantidade de revestimento (em unidades) necessária para preencher uma área de um
 * metro quadrado com base nas medidas do revestimento utilizado, sendo estas fornecidas pelo usuário.
 *
 * Retorna:
 * (int) qtde_revestimento_por_metro_quadrado: quantidade de revestimento (em unidades) necessárioa para
 *       preencher uma área de um metro quadrado.
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
 * Exibe opções de revestimento para que o usuário possa escolher o revestimento que
 * deseja utilizar em sua obra.
 *
 * Retorna:
 * (int) tipo_revestimento: tipo de revestimento escolhido pelo usuário.
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
        printf(" 4 - Revestimento cimentício\n");
        printf(" 5 - Ladrilho hidráulico\n");
        printf(" 6 - Azulejo comum\n");
        printf(" 7 - Outra opção");

        printf("\n\nSua escolha: ");
        scanf("%d", &tipo_revestimento);
    } while (tipo_revestimento<1 || tipo_revestimento>6);

    return tipo_revestimento;
}

/*
 * Calcula a quantidade de tijolos necessários para construir cada oitão com base nas áreas dos
 * oitões e na quantidade de tiolos necessários para preencher uma área de um metro quadrado.
 * Armaneza a quantidade de tijolos necessários por oitão em uma variável responsável por
 * contabilizar a quantidade total de tijolos necessários para construir todas as paredes e oitões
 * da construção.
 *
 * Parâmetros:
 * (int) qtde_tijolos_por_oitão: vetor que armazena em cada posição a quantidade de tijolos necessária para construir um oitão.
 * (int) qtde_oitoes: quantidade total de oitões presentes na construção.
 * (int) qtde_total_tijolos: variável que contabiliza a quantidade total de tijolos necessária para toda a construção.
 * (float) areas_oitões: vetor que armazena em casa posição a área de cada oitão individualmente.
 * (int) qtde_tijolos_por_metro_quadrado: quantidade de tijolos necessária para preencher uma área de um metro quadrado.
 */
void calcula_qtde_tijolos_por_oitao(int * qtde_tijolos_por_oitao, int qtde_oitoes, int * qtde_total_tijolos, float * areas_oitoes, int qtde_tijolos_por_metro_quadrado) {
    int i;

    printf("\n\n----- Quantidade de tijolos por oitão -----");

    for (i=0; i<qtde_oitoes; i++) {
        qtde_tijolos_por_oitao[i] = ceil(qtde_tijolos_por_metro_quadrado * areas_oitoes[i]);
        *qtde_total_tijolos += qtde_tijolos_por_oitao[i];
        printf("\n %dº oitão: %d", i+1, qtde_tijolos_por_oitao[i]);
    }
}

/*
 * Calcula a quantidade de tijolos necessários para construir cada parede com base nas áreas das
 * paredes e na quantidade de tiolos necessários para preencher uma área de um metro quadrado.
 * Armaneza a quantidade de tijolos necessários por parede em uma variável responsável por
 * contabilizar a quantidade total de tijolos necessários para construir todas as paredes e oitões
 * da construção.
 *
 * Parâmetros:
 * (int) qtde_tijolos_por_parede: vetor que armazena em cada posição a quantidade de tijolos necessária para construir uma parede.
 * (int) qtde_paredes: quantidade total de paredes presentes na construção.
 * (int) qtde_total_tijolos: variável que contabiliza a quantidade total de tijolos necessária para toda a construção.
 * (float) areas_paredes: vetor que armazena em casa posição a área de cada parede individualmente.
 * (int) qtde_tijolos_por_metro_quadrado: quantidade de tijolos necessária para preencher uma área de um metro quadrado.
 */
void calcula_qtde_tijolos_por_parede(int * qtde_tijolos_por_parede, int qtde_paredes, int * qtde_total_tijolos, float * areas_paredes, int qtde_tijolos_por_metro_quadrado) {
    int i;

    printf("\n----- Quantidade de tijolos por parede -----");

    for (i=0; i<qtde_paredes; i++) {
        qtde_tijolos_por_parede[i] = ceil(qtde_tijolos_por_metro_quadrado * areas_paredes[i]);
        *qtde_total_tijolos += qtde_tijolos_por_parede[i];
        printf("\n %dª parede: %d", i+1, qtde_tijolos_por_parede[i]);
    }
}

/*
 * Calcula a quantidade de tijolos necessários para preencher uma área de um metro quadrado
 * com base nas medidas do tijolo utilizado, sendo estas fornecidas pelo usuário.
 *
 * Retorna:
 * (int) qtde_tijolos_por_metro_quadrado: quantidade de tijolos necessários para preencher
 *       uma área de um metro quadrado.
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
 * Calcula a área de um oitão presente na casa com base no tamanho de sua altura e base,
 * sendo ambas as medidas fornecidas pelo usuário.
 *
 * Retorna:
 * (float) area_oitao: área do oitão.
 */
float calcula_area_oitao() {
    float altura_oitao = 0,
          base_oitao = 0,
          area_oitao = 0;

    printf("\nAltura do oitão em metros: ");
    scanf("%f", &altura_oitao);

    printf("Base do oitão em metros: ");
    scanf("%f", &base_oitao);

    area_oitao = ((base_oitao * altura_oitao)/2);

    return area_oitao;
}

/*
 * Calcula a área de uma parede, descontando a área das aberturas presentes nela,
 * como portas e janelas.
 *
 * Parâmetros:
 * (float) area_aberturas: área total das aberturas presentes na parede, como portas e janelas.
 *
 * Retorna:
 * (float) area_parede: área da parede com a área das aberturas descontada.
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
 * Calcula a área das aberturas presentes nas paredes, como portas e janelas, uma vez
 * que estas devem ser descontadas posteriormente no cáculo da área das paredes que
 * irão receber tijolos.
 *
 * Retorna:
 * (float) area_aberturas: área total das aberturas presentes em uma parede, como portas e janelas.
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
            printf("\nAltura da %dª abertura em metros: ", i+1);
            scanf("%f", &altura_abertura);
        } while (altura_abertura <= 0);

        do {
            printf("Comprimento da %dª abertura em metros: ", i+1);
            scanf("%f", &comprimento_abertura);
        } while (comprimento_abertura <= 0);

        area_aberturas += (altura_abertura * comprimento_abertura);
    }

    return area_aberturas;
}

/*
 * Exibe opções de tijolos para que o usuário possa escolher o tijolo que
 * deseja utilizar em sua obra.
 *
 * Retorna:
 * (int) tipo_tijolo: tipo de tijolo escolhido pelo usuário.
 */
int escolhe_tipo_tijolo() {
    int tipo_tijolo;

    printf("\n--------------------\n");
    printf("Tipos de Tijolo\n");
    printf("--------------------\n");

    do {
        printf("\nSelecione o tipo do tijolo: \n\n");

        printf(" 1 - Blocos\n");
        printf(" 2 - Tijolos Cerâmicos\n");
        printf(" 3 - Tijolos Maciços\n");
        printf(" 4 - Outra opção");

        printf("\n\nSua escolha: ");
        scanf("%d", &tipo_tijolo);
    } while (tipo_tijolo<1 || tipo_tijolo>4);

    return tipo_tijolo;
}

void main() {
    setlocale(LC_ALL, "");

    int tipo_tijolo = 0, //Armazena o tipo de tijolo selecionado pelo usuário.
        tipo_revesitmento = 0, //Armanzena o tipo de revestimento selecionado pelo usuário.
        qtde_paredes = 0, //Quantidade total de paredes presentes na construção.
        qtde_oitoes = 0, //Quantidade total de oitões presentes na construção.
        qtde_tijolos_por_metro_quadrado = 0, //Quantidade de tijolos necessária para preencher uma área de um metro quadrado.
        qtde_revestimento_por_metro_quadrado = 0, //Quantidade de revestimento (em unidades) necessária para preencher uma área de um metro quadrado.
        qtde_total_tijolos = 0, //Quantidade total de tijolos utilizada na construção.
        qtde_total_revestimento = 0, //Quantidade total de revestimento (em unidades) utilizada na construção.
        qtde_total_galoes_tinta = 0, //Quanidade total de galões de tinta necessária para pintar a área interna da casa.
        i = 0; //Contador utilizado para percorrer os vetores existentes na implementação.

    float preco_unitario_tijolo = 0.0, //Preço unirário do tijolo fornecido pelo usuário.
          preco_total_tijolos = 0.0, //Custo total dos tijolos utilizados na construção.
          preco_unitario_revestimento = 0.0, //Preço unitário do revestimento fornecido pelo usuário.
          preco_total_revestimento = 0.0, //Custo total do revestimento utilizado na construção.
          preco_unitario_galao_tinta = 0.0, //Preço unitátrio do galão de tinta.
          preco_total_galao_tinta = 0.0; //Cusuto total de todos os galões de tinta utilizados na construção.

    char usr_rsp; //Armazena a resposta do usuário quando este deve responder com 'S - Sim' ou 'N - Não'.

    printf("------------------------------------------------------------------------\n");
    printf("Orçamento de tijolos, revestimento e tinta para as paredes\n");
    printf("------------------------------------------------------------------------\n");


    do {
        printf("Digite a quantidade de paredes que deseja construir: ");
        scanf("%d", &qtde_paredes);
    } while(qtde_paredes <= 0);

    do {
        printf("\nDigite a quantidade de oitões presentes em sua casa: ");
        scanf("%d", &qtde_oitoes);
    } while(&qtde_oitoes <= 0);

    float areas_paredes[qtde_paredes], //Vetor que armazena a área unitária de cada parede (com desconto das áreas das aberturas presentes) em cada posição.
          areas_oitoes[qtde_oitoes], //Vetor que armazena a área unitária de cada oitão em cada posição.
          areas_aberturas[qtde_paredes], //Vetor que armazena a área das aberturas presentes por parede em cada posição.
          area_tetos = 0.0; //Armazena a área total do teto da construção.

    int qtde_tijolos_por_parede[qtde_paredes], //Vetor que armazena a quantidade de tijolos necessária para construir cada parede em casa posição.
        qtde_tijolos_por_oitao[qtde_oitoes], //Vetor que armazena a quantidade de tijolos necessária para construir cada oitão em cada posição.
        qtde_revestimento_por_parede[qtde_paredes]; //Vetor que armazena a quantidade de revestimento necessária para preencher cada parede em cada posição.

    for (i=0; i<qtde_paredes; i++) {
        printf("\n----- %dª parede -----\n", i+1);

        do {
            printf("\nA %dª parede apresenta aberturas como portas e janelas?", i+1);
            printf("\n S - Sim\n N - Não\n");
            printf("Sua escolha: ");
            scanf(" %c", &usr_rsp);
        } while (usr_rsp!='S' && usr_rsp!='s' && usr_rsp!='N' && usr_rsp!='n');

        if (usr_rsp=='S' || usr_rsp=='s') {
            areas_aberturas[i] = calcula_area_aberturas();
        } else {
            areas_aberturas[i] = 0.0;
        }

        areas_paredes[i] = calcula_area_parede(areas_aberturas[i]);

        printf("\nÁrea da %dª parede, com as áreas das aberturas descontadas é de: %.2fm²\n\n", i+1, areas_paredes[i]);
    }

    for (i=0; i<qtde_oitoes; i++) {
        printf("\n----- %dº oitão -----\n", i+1);

        areas_oitoes[i] = calcula_area_oitao();

        printf("\nÁrea do %dº oitão: %.2fm²\n\n", i+1, areas_oitoes[i]);
    }

    printf("\n\n------------------------------------------------------------------------\n");
    printf("Orçamento de Tijolos\n");
    printf("------------------------------------------------------------------------\n");

    tipo_tijolo = escolhe_tipo_tijolo();

    switch (tipo_tijolo) {
        case 1:
            printf("\n--------------------\n");
            printf("Blocos\n");
            break;

        case 2:
            printf("\n--------------------\n");
            printf("Tijolos Cerâmicos\n");
            break;

        case 3:
            printf("\n--------------------\n");
            printf("Tijolos Maciços\n");
            break;
    }

    qtde_tijolos_por_metro_quadrado = calcula_qtde_tijolos_por_metro_quadrado();

    printf("\nRendimento: %d tijolos por metro quadrado.\n", qtde_tijolos_por_metro_quadrado);

    do {
        printf("\nPreço Unitário do Tijolo: R$ ");
        scanf("%f", &preco_unitario_tijolo);
    } while (preco_unitario_tijolo <= 0);

    calcula_qtde_tijolos_por_parede(qtde_tijolos_por_parede, qtde_paredes, &qtde_total_tijolos, areas_paredes, qtde_tijolos_por_metro_quadrado);

    calcula_qtde_tijolos_por_oitao(qtde_tijolos_por_oitao, qtde_oitoes, &qtde_total_tijolos, areas_oitoes, qtde_tijolos_por_metro_quadrado);

    qtde_total_tijolos += (TAXA_DE_PERDA * qtde_total_tijolos);

    printf("\n\n----- Quantidade total de tijolos -----");
    printf("\n %d tijolos", qtde_total_tijolos);

    preco_total_tijolos = preco_unitario_tijolo * qtde_total_tijolos;
    printf("\n\n----- Preço total - Tijolos -----");
    printf("\n R$ %.2f", preco_total_tijolos);

    printf("\n\n------------------------------------------------------------------------\n");
    printf("Orçamento de Revestimento\n");
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
            printf("Revestimento cimentício\n");
            break;

        case 5:
            printf("\n--------------------\n");
            printf("Ladrilho hidráulico\n");
            break;

        case 6:
            printf("\n--------------------\n");
            printf("Azulejo comum\n");
            break;
    }

    qtde_revestimento_por_metro_quadrado = calcula_qtde_revestimento_por_metro_quadrado();

    printf("\nRendimento: %d unidade(s) de revestimento por metro quadrado.\n", qtde_revestimento_por_metro_quadrado);

    do {
        printf("\nPreço Unitário do Revestimento: R$ ");
        scanf("%f", &preco_unitario_revestimento);
    } while (preco_unitario_revestimento <= 0);

    calcula_qtde_revestimento_por_parede(qtde_revestimento_por_parede, qtde_paredes, &qtde_total_revestimento, areas_paredes, qtde_revestimento_por_metro_quadrado);

    qtde_total_revestimento += (TAXA_DE_PERDA * qtde_total_revestimento);

    printf("\n\n----- Quantidade total de revestimento -----");
    printf("\n %d unidades de revestimento", qtde_total_revestimento);

    preco_total_revestimento = preco_unitario_revestimento * qtde_total_revestimento;
    printf("\n\n----- Preço total - Revestimento -----");
    printf("\n R$ %.2f\n", preco_total_revestimento);

    printf("\n\n------------------------------------------------------------------------\n");
    printf("Orçamento de Tinta\n");
    printf("------------------------------------------------------------------------\n");

    do {
        printf("\nÁrea total do teto presenta na construção: ");
        scanf("%f", &area_tetos);
    } while (area_tetos <= 0);

    qtde_total_galoes_tinta = calcula_qtde_total_galoes_tinta(areas_paredes, qtde_paredes, area_tetos);
    qtde_total_galoes_tinta += ceil(TAXA_DE_PERDA * qtde_total_galoes_tinta);

    printf("\n\n----- Quantidade total de galões de tinta -----");
    printf("\n %d galões de tinta", qtde_total_galoes_tinta);

    do {
        printf("\nPreço Unitário do Galão de Tinta: R$ ");
        scanf("%f", &preco_unitario_galao_tinta);
    } while (preco_unitario_galao_tinta <= 0);

    preco_total_galao_tinta = preco_unitario_galao_tinta * qtde_total_galoes_tinta;
    printf("\n\n----- Preço total - Tinta -----");
    printf("\n R$ %.2f\n", preco_total_galao_tinta);
}
