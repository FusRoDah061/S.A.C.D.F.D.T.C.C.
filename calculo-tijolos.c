#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 * Exibe uma lista de opções para que o usuário escolhe qual tipo
 * de tijolo deseja utilizar em sua construção
 *
 * Retorna:
 * A opção escolhida pelo usuário que corresponde ao tipo de
 * tijolo que este quer utilizar
 */
int escolhe_tipo_tijolo() {
	int usr_opt;

	do {
		printf("\nSelectione o tipo de tijolo: \n\n");

		printf(" 1 - Blocos\n");
		printf(" 2 - Tijolos Cerâmicos\n");
		printf(" 3 - Tijolos Maciços");

		printf("\n\nSua escolha: ");
		scanf("%d", &usr_opt);
	} while(usr_opt<1 || usr_opt>3);

	return usr_opt;
}

/*
 * Calcula a quantidade de tijolos necessária para construir uma
 * área de um metro quadrado com base nas medidas de altura e
 * comprimento do tijolo
 *
 * Parâmetros:
 * altura_tijolo: altura do tijolo
 * comprimento_tijolo: comrpimento do tijolo
 *
 * Retorna:
 * A quantidade de tijolos, arredondada para cima, necessária
 * para construir uma área de um metro quadrado
 */
int calcula_qtde_tijolos_por_metro_quadrado(float altura_tijolo, float comprimento_tijolo) {
    float area_tijolo = 0,
          qtde_tijolo_por_metro_quadrado = 0;

    area_tijolo = altura_tijolo * comprimento_tijolo;

    qtde_tijolo_por_metro_quadrado = 1/area_tijolo;

    return ceil(qtde_tijolo_por_metro_quadrado);
}

/*
 * Calcula a área das aberturas, como portas e janelas, existentes
 * em uma parede
 *
 * Parâmetros:
 * parede: número da parede na qual se encontram as aberturas
 *
 * Retorna:
 * A soma das áreas das aberturas existentes em uma parede
 */
float calcula_area_aberturas(int parede) {
    int qtde_aberturas = 0, i;

    float altura_abertura = 0,
          comprimento_abertura = 0,
          area_aberturas = 0;

    do {
        printf("\nQuantas aberturas a %da parede apresenta? ", parede);
        scanf("%d", &qtde_aberturas);
    } while (qtde_aberturas <= 0);

    for (i=0; i<qtde_aberturas; i++) {
        do {
			printf("\nAltura da %da abertura: ", i+1);
			scanf("%f", &altura_abertura);
        } while(altura_abertura <= 0);


        do {
            printf("Comprimento da %da abertura: ", i+1);
            scanf("%f", &comprimento_abertura);
        } while(comprimento_abertura <= 0);

        area_aberturas += (altura_abertura * comprimento_abertura);
    }

    return area_aberturas;
}

/*
 * Calcula a área de uma parede com base em sua altura e comprimento,
 * descontando a área ocupada pelas aberturas
 *
 * Parâmetros:
 * altura_parede: altura da parede
 * comrpimento_parede: comprimento da parede
 * area_aberturas: área total ocupada por aberturas em uma parede
 *
 * Retorna:
 * A área de uma parede, com desconto da área ocupada pelas aberturas
 */
float calcula_area_parede(float altura_parede, float comprimento_parede, float area_aberturas) {
    float area_parede = 0;

    area_parede = ((altura_parede * comprimento_parede) - area_aberturas);

    return area_parede;
}

/*
 * Calcula a área de um oitão com base em sua altura e no tamanho
 * de sua base
 *
 * Parâmetros:
 * altura_oitao: altura do oitão
 * base_oitao: tamanho da base do oitão
 *
 * Retorna:
 * A área de um oitão
 */
float calcula_area_oitao(float altura_oitao, float base_oitao) {
    float area_oitao = 0;

    area_oitao = ((base_oitao * altura_oitao)/2);

    return area_oitao;
}

/*
 * Calcula a quantidade de tijolos necessária para construir uma
 * parede com base em sua área e na quantidade tijolos necessária
 * construir uma área de um metro quadrado
 *
 * Parâmetros:
 * area_parede: área da parede que se deseja construir
 * qtde_tijolos_por_metro_quadrado quantidade de tijolos necessária
 * para construir uma área de um metro quadrado
 *
 * Retorna:
 * A quantidade de tijolos necessária para construir uma parede
 */
int calcula_qtde_tijolos_por_parede(float area_parede, int qtde_tijolos_por_metro_quadrado) {
    int qtde_tijolos_por_parede = 0;

    qtde_tijolos_por_parede = ceil(qtde_tijolos_por_metro_quadrado * area_parede);
    qtde_tijolos_por_parede = ceil(qtde_tijolos_por_parede + (0.10 * qtde_tijolos_por_parede));

    return qtde_tijolos_por_parede;
}

/*
 * Calcula a quantidade de tijolos necessária para construir umm
 * oitão com base em sua área e na quantidade tijolos necessária
 * construir uma área de um metro quadrado
 *
 * Parâmetros:
 * area_oitao: área do oitão que se deseja construir
 * qtde_tijolos_por_metro_quadrado quantidade de tijolos necessária
 * para construir uma área de um metro quadrado
 *
 * Retorna:
 * A quantidade de tijolos necessária para construir um oitão
 */
int calcula_qtde_tijolos_por_oitao(float area_oitao, int qtde_tijolos_por_metro_quadrado) {
    int qtde_tijolos_por_oitao = 0;

    qtde_tijolos_por_oitao = ceil(qtde_tijolos_por_metro_quadrado * area_oitao);
    qtde_tijolos_por_oitao = ceil((qtde_tijolos_por_oitao + (0.10 * qtde_tijolos_por_oitao)));

    return qtde_tijolos_por_oitao;
}

/* Solicita uma medida do tijolo, como altura, largura ou comprimento
 * ao usuário
 *
 * Parâmetro:
 * tipo_medida: tipo de medidade que o usuário deve informar
 *
 * Retorna:
 * O valor da medida fornecido pelo usuário
 */
float solicita_medida_tijolo(char tipo_medida[20]) {
    float medida = 0;
    do {
        printf("%s do tijolo em metros: ", tipo_medida);
        scanf("%f", &medida);
    } while(medida <= 0);

    return medida;
}

/* Solicita o preço unitário do tijolo ao usuário
 *
 * Retorna:
 * O valor do preço unitário do tijolo
 */
float solicita_preco_unitario() {
    float preco_unitario = 0;

    do {
        printf("\nPreço unitário do tijolo escolhido: R$ ");
        scanf("%f", &preco_unitario);
    } while(preco_unitario <= 0);

    return preco_unitario;
}

void main() {
    setlocale(LC_ALL, "");

    int usr_opt, //Recebe as escolhas do usuário quando este precisa escolher alguma opção
        qtde_paredes = 0, //Quantidade de paredes que o usuário deseja construir
        qtde_oitoes = 0, //Quantidade de oitões presente na construção
        qtde_tijolos_por_metro_quadrado = 0, //Quantidade de tijolos capaz de preencher um metro quadrado
        qtde_total_tijolos = 0, //Quantidade total de tijolos utilizada na construção (totas as paredes e oitões), com a taxa de perda de 10% já inclusa
        i = 0; //Índice utilizado para percorrer os vetores existentes

    float largura_tijolo = 0, //Largura do tipo de tijolo escolhido pelo usuário
          comprimento_tijolo = 0, //Comprimento do tijolo escolhido pelo usuário
          altura_tijolo = 0, //Altura do tijolo escolhido pelo usuário
          preco_unitario = 0, //Preço unitário do tijolo escolhido pelo usuário
          preco_total = 0; //Preço total dos tijlos

    char usr_rsp; //Recebe as resposas to usuário quando este deve escolher entre opç~es de "sim" ou "não"

    //Solicita a quantidade de tijolos que o usuário deseja construir
    do {
        printf("Digite a quantidade de paredes que deseja construir: ");
        scanf("%d", &qtde_paredes);
    } while(qtde_paredes <= 0);

    //Solicita a quantidade de oitões que estará presente na construção do usuário
    do {
            printf("\nQuantidade de oitões presentes em sua casa: ");
            scanf("%d", &qtde_oitoes);
    } while (qtde_oitoes <= 0);

    float areas_paredes[qtde_paredes], //Vetor que armazena a área de cada parede
          areas_oitoes[qtde_oitoes], //Vetor que armanazena a área de cada oitão
          areas_aberturas[qtde_paredes], //Vetor que armazena a área total das aberturas existentes em cada parede, como portas e janelas, em uma posição diferente de acordo com a parede na qual a abertura se encontra
          alturas_paredes[qtde_paredes], //Vetor que armazena a altura de cada parede
          comprimentos_paredes[qtde_paredes], //Vetor que armazena o comprimento de cada parede
          alturas_oitoes[qtde_oitoes], //Vetor que armazena a altura de cada oitão
          bases_oitoes[qtde_oitoes]; //Vetor que armazena o tamanho da base de cada oitão

    int qtde_tijolos_por_parede[qtde_paredes], //Vetor que armazena a quantidade de tijolos utilizada na construção de cada parede
        qtde_tijolos_por_oitao[qtde_oitoes]; //Vetor que armanzena a quantidade de tijolos utilizada na construção de cada oitão

    //Permite que o usuário escolha o tipo de tijolo que deseja utilizar em sua construção
    usr_opt = escolhe_tipo_tijolo();

    switch(usr_opt) {
        case 1:
            printf("\n--------------------\n");
            printf("Blocos\n");
            printf("--------------------\n");
            //Solicita as medidas (largura, altura e comprimento) do tijolo escolhido pelo usuário
            largura_tijolo = solicita_medida_tijolo("Largura");
            altura_tijolo = solicita_medida_tijolo("Altura");
            comprimento_tijolo = solicita_medida_tijolo("Comprimento");

            //Calcula a quantidade de tijolos necessária para preencher uma área de um metro quadrado
            //O cálculo é feito com base nas medidas do tijolo fornecidas pelo usuário
            qtde_tijolos_por_metro_quadrado = calcula_qtde_tijolos_por_metro_quadrado(altura_tijolo, comprimento_tijolo);
            printf("Os Blocos rendem %d tijolos por metro quadrado.\n", qtde_tijolos_por_metro_quadrado);

            //Solicita o preço unitário do tijolo escolhido pelo usuário
            preco_unitario = solicita_preco_unitario();

            //Solicita uma série de informações e realiza cálculos para cada parede que o usuário deseja construir
            for (i=0; i<qtde_paredes; i++) {
                printf("\n----- %dª parede -----\n", i+1);

                //Verifica se a parede possui alguma abertura, como portas e janelas
                do {
                    printf("\nA %dª parede apresenta aberturas como portas e janelas? ", i+1);
                    printf("\nS - Sim\nN - Não\n");
                    printf("Sua escolha: ");
                    scanf(" %c", &usr_rsp);
                } while (usr_rsp!='S' && usr_rsp!='s' && usr_rsp!='N' && usr_rsp!='n');

                //Havendo aberturas como portas e janelas na parede, é feito o cálculo da área ocupada pelas aberturas
                //A área ocupada pelas aberturas em cada parede é armazenada em um vetor de acordo com a respectiva parede na qual a abertura se encontra
                if (usr_rsp=='S' || usr_rsp=='s') {
                    areas_aberturas[i] = calcula_area_aberturas(i+1);
                } else {
                    areas_aberturas[i] = 0.0;
                }

                //Solicita a altura da parede em metros
                do {
                    printf("\nAltura da %dª parede em metros: ", i+1);
                    scanf("%f", &alturas_paredes[i]);
                } while(alturas_paredes[i] <= 0);

                //Solicita o comprimento da parede em metros
                do {
                    printf("Comprimento da %dª parede em metros: ", i+1);
                    scanf("%f", &comprimentos_paredes[i]);
                } while(comprimentos_paredes[i] <= 0);

                //Calcula a área da parede com base em sua altura e comprimento, descontando a área ocupada pelas aberturas
                areas_paredes[i] = calcula_area_parede(alturas_paredes[i], comprimentos_paredes[i], areas_aberturas[i]);

                printf("\nÁrea da %dª parede, com as áreas das aberturas descontadas é de: %.2fm²\n\n", i+1, areas_paredes[i]);
            }

            //Solicita uma série de informações e realiza cálculos para cada oitão presente na construção do usuário
            for (i=0; i<qtde_oitoes; i++) {
                printf("\n----- %dº oitão -----\n", i+1);

                //Solicita a altura do oitão em metros
                do {
                    printf("\nAltura do %dº oitão em metros: ", i+1);
                    scanf("%f", &alturas_oitoes[i]);
                } while(alturas_oitoes[i] <= 0);

                //Solicita o tamanho da base do oitão em metros
                do {
                    printf("Base do %dº oitão em metros: ", i+1);
                    scanf("%f", &bases_oitoes[i]);
                } while(bases_oitoes[i] <= 0);

                //Calcula a área de cada oitão com base em sua altura e no tamanho de sua base
                areas_oitoes[i] = calcula_area_oitao(alturas_oitoes[i], bases_oitoes[i]);

                printf("\nÁrea do %dº oitão: %.2fm²\n\n", i+1, areas_oitoes[i]);
            }

            //Calcula a quantidade de tijolos necessários para construir cada parede, individualmente, com base em sua área e na quantidade de tijolos necessários para preenher uma área de um metro quadrado.
            //Soma a quantidade de tijolos necessários para construir uma única parede à uma variável que armazena a quantidade total de tijolos a ser utilizada na constução
            printf("\n----- Quantidade de tijolos por parede -----");
            for (i=0; i<qtde_paredes; i++) {
                qtde_tijolos_por_parede[i] = calcula_qtde_tijolos_por_parede(areas_paredes[i], qtde_tijolos_por_metro_quadrado);
                qtde_total_tijolos += qtde_tijolos_por_parede[i];
                printf("\n %dª parede: %d", i+1, qtde_tijolos_por_parede[i]);
            }

            //Calcula a quantidade de tijolos necessários para construir cada oitão, individualmente, com base em sua área e na quantidade de tijolos necessários para preencher uma área de um metro quadrado
            //Soma a quantidade de tijolos necessários para construir um único oitão à uma variável que armazena a quantidade total de tijolos a ser utilizada na constução
            printf("\n\n----- Quantidade de tijolos por oitão -----");
            for (i=0; i<qtde_oitoes; i++) {
                qtde_tijolos_por_oitao[i] = calcula_qtde_tijolos_por_oitao(areas_oitoes[i], qtde_tijolos_por_metro_quadrado);
                qtde_total_tijolos += qtde_tijolos_por_oitao[i];
                printf("\n %dº oitão: %d", i+1, qtde_tijolos_por_oitao[i]);
            }

            //Exibe a quantidade total de tijolos a ser utilizada na construção (paredes + oitões)
            printf("\n\n----- Quantidade total de tijolos -----");
            printf("\n %d tijolos", qtde_total_tijolos);

            //Calcula e exibe o preço total utilizado em tijolos para a construção com base na quantidade total de tijolos e no preço unitário do tijolo escolhido pelo usuário
            preco_total = preco_unitario * qtde_total_tijolos;
            printf("\n\n----- Preço total -----");
            printf("\n R$ %.2f", preco_total);
            break;

        case 2:
            printf("\n--------------------\n");
            printf("Tijolo Cerâmico\n");
            printf("--------------------\n");
            //Solicita as medidas (largura, altura e comprimento) do tijolo escolhido pelo usuário
            largura_tijolo = solicita_medida_tijolo("Largura");
            altura_tijolo = solicita_medida_tijolo("Altura");
            comprimento_tijolo = solicita_medida_tijolo("Comprimento");

            //Calcula a quantidade de tijolos necessária para preencher uma área de um metro quadrado
            //O cálculo é feito com base nas medidas do tijolo fornecidas pelo usuário
            qtde_tijolos_por_metro_quadrado = calcula_qtde_tijolos_por_metro_quadrado(altura_tijolo, comprimento_tijolo);
            printf("O Tijolo Cerâmico rende %d tijolos por metro quadrado.\n", qtde_tijolos_por_metro_quadrado);

            //Solicita o preço unitário do tijolo escolhido pelo usuário
            preco_unitario = solicita_preco_unitario();

            //Solicita uma série de informações e realiza cálculos para cada parede que o usuário deseja construir
            for (i=0; i<qtde_paredes; i++) {
                printf("\n----- %dª parede -----\n", i+1);

                //Verifica se a parede possui alguma abertura, como portas e janelas
                do {
                    printf("\nA %dª parede apresenta aberturas como portas e janelas? ", i+1);
                    printf("\nS - Sim\nN - Não\n");
                    printf("Sua escolha: ");
                    scanf(" %c", &usr_rsp);
                } while (usr_rsp!='S' && usr_rsp!='s' && usr_rsp!='N' && usr_rsp!='n');

                //Havendo aberturas como portas e janelas na parede, é feito o cálculo da área ocupada pelas aberturas
                //A área ocupada pelas aberturas em cada parede é armazenada em um vetor de acordo com a respectiva parede na qual a abertura se encontra
                if (usr_rsp=='S' || usr_rsp=='s') {
                    areas_aberturas[i] = calcula_area_aberturas(i+1);
                } else {
                    areas_aberturas[i] = 0.0;
                }

                //Solicita a altura da parede em metros
                do {
                    printf("\nAltura da %dª parede em metros: ", i+1);
                    scanf("%f", &alturas_paredes[i]);
                } while(alturas_paredes[i] <= 0);

                //Solicita o comprimento da parede em metros
                do {
                    printf("Comprimento da %dª parede em metros: ", i+1);
                    scanf("%f", &comprimentos_paredes[i]);
                } while(comprimentos_paredes[i] <= 0);

                //Calcula a área da parede com base em sua altura e comprimento, descontando a área ocupada pelas aberturas
                areas_paredes[i] = calcula_area_parede(alturas_paredes[i], comprimentos_paredes[i], areas_aberturas[i]);

                printf("\nÁrea da %dª parede, com as áreas das aberturas descontadas é de: %.2fm²\n\n", i+1, areas_paredes[i]);
            }

            //Solicita uma série de informações e realiza cálculos para cada oitão presente na construção do usuário
            for (i=0; i<qtde_oitoes; i++) {
                printf("\n----- %dº oitão -----\n", i+1);

                //Solicita a altura do oitão em metros
                do {
                    printf("\nAltura do %dº oitão em metros: ", i+1);
                    scanf("%f", &alturas_oitoes[i]);
                } while(alturas_oitoes[i] <= 0);

                //Solicita o tamanho da base do oitão em metros
                do {
                    printf("Base do %dº oitão em metros: ", i+1);
                    scanf("%f", &bases_oitoes[i]);
                } while(bases_oitoes[i] <= 0);

                //Calcula a área de cada oitão com base em sua altura e no tamanho de sua base
                areas_oitoes[i] = calcula_area_oitao(alturas_oitoes[i], bases_oitoes[i]);

                printf("\nÁrea do %dº oitão: %.2fm²\n\n", i+1, areas_oitoes[i]);
            }

            //Calcula a quantidade de tijolos necessários para construir cada parede, individualmente, com base em sua área e na quantidade de tijolos necessários para preenher uma área de um metro quadrado.
            //Soma a quantidade de tijolos necessários para construir uma única parede à uma variável que armazena a quantidade total de tijolos a ser utilizada na constução
            printf("\n----- Quantidade de tijolos por parede -----");
            for (i=0; i<qtde_paredes; i++) {
                qtde_tijolos_por_parede[i] = calcula_qtde_tijolos_por_parede(areas_paredes[i], qtde_tijolos_por_metro_quadrado);
                qtde_total_tijolos += qtde_tijolos_por_parede[i];
                printf("\n %dª parede: %d", i+1, qtde_tijolos_por_parede[i]);
            }

            //Calcula a quantidade de tijolos necessários para construir cada oitão, individualmente, com base em sua área e na quantidade de tijolos necessários para preencher uma área de um metro quadrado
            //Soma a quantidade de tijolos necessários para construir um único oitão à uma variável que armazena a quantidade total de tijolos a ser utilizada na constução
            printf("\n\n----- Quantidade de tijolos por oitão -----");
            for (i=0; i<qtde_oitoes; i++) {
                qtde_tijolos_por_oitao[i] = calcula_qtde_tijolos_por_oitao(areas_oitoes[i], qtde_tijolos_por_metro_quadrado);
                qtde_total_tijolos += qtde_tijolos_por_oitao[i];
                printf("\n %dº oitão: %d", i+1, qtde_tijolos_por_oitao[i]);
            }

            //Exibe a quantidade total de tijolos a ser utilizada na construção (paredes + oitões)
            printf("\n\n----- Quantidade total de tijolos -----");
            printf("\n %d tijolos", qtde_total_tijolos);

            //Calcula e exibe o preço total utilizado em tijolos para a construção com base na quantidade total de tijolos e no preço unitário do tijolo escolhido pelo usuário
            preco_total = preco_unitario * qtde_total_tijolos;
            printf("\n\n----- Preço total -----");
            printf("\n R$ %.2f", preco_total);
            break;

        case 3:
            printf("\n--------------------\n");
            printf("Tijolo Maci�o\n");
            printf("--------------------\n");
            largura_tijolo = solicita_medida_tijolo("Largura");
            altura_tijolo = solicita_medida_tijolo("Altura");
            comprimento_tijolo = solicita_medida_tijolo("Comprimento");
            qtde_tijolos_por_metro_quadrado = calcula_qtde_tijolos_por_metro_quadrado(altura_tijolo, comprimento_tijolo);
            printf("O Tijolo Maci�o rende %d tijolos por metro quadrado.\n", qtde_tijolos_por_metro_quadrado);

            //Solicita o preço unitário do tijolo escolhido pelo usuário
            preco_unitario = solicita_preco_unitario();

            //Solicita uma série de informações e realiza cálculos para cada parede que o usuário deseja construir
            for (i=0; i<qtde_paredes; i++) {
                printf("\n----- %dª parede -----\n", i+1);

                //Verifica se a parede possui alguma abertura, como portas e janelas
                do {
                    printf("\nA %dª parede apresenta aberturas como portas e janelas? ", i+1);
                    printf("\nS - Sim\nN - Não\n");
                    printf("Sua escolha: ");
                    scanf(" %c", &usr_rsp);
                } while (usr_rsp!='S' && usr_rsp!='s' && usr_rsp!='N' && usr_rsp!='n');

                //Havendo aberturas como portas e janelas na parede, é feito o cálculo da área ocupada pelas aberturas
                //A área ocupada pelas aberturas em cada parede é armazenada em um vetor de acordo com a respectiva parede na qual a abertura se encontra
                if (usr_rsp=='S' || usr_rsp=='s') {
                    areas_aberturas[i] = calcula_area_aberturas(i+1);
                } else {
                    areas_aberturas[i] = 0.0;
                }

                //Solicita a altura da parede em metros
                do {
                    printf("\nAltura da %dª parede em metros: ", i+1);
                    scanf("%f", &alturas_paredes[i]);
                } while(alturas_paredes[i] <= 0);

                //Solicita o comprimento da parede em metros
                do {
                    printf("Comprimento da %dª parede em metros: ", i+1);
                    scanf("%f", &comprimentos_paredes[i]);
                } while(comprimentos_paredes[i] <= 0);

                //Calcula a área da parede com base em sua altura e comprimento, descontando a área ocupada pelas aberturas
                areas_paredes[i] = calcula_area_parede(alturas_paredes[i], comprimentos_paredes[i], areas_aberturas[i]);

                printf("\nÁrea da %dª parede, com as áreas das aberturas descontadas é de: %.2fm²\n\n", i+1, areas_paredes[i]);
            }

            //Solicita uma série de informações e realiza cálculos para cada oitão presente na construção do usuário
            for (i=0; i<qtde_oitoes; i++) {
                printf("\n----- %dº oitão -----\n", i+1);

                //Solicita a altura do oitão em metros
                do {
                    printf("\nAltura do %dº oitão em metros: ", i+1);
                    scanf("%f", &alturas_oitoes[i]);
                } while(alturas_oitoes[i] <= 0);

                //Solicita o tamanho da base do oitão em metros
                do {
                    printf("Base do %dº oitão em metros: ", i+1);
                    scanf("%f", &bases_oitoes[i]);
                } while(bases_oitoes[i] <= 0);

                //Calcula a área de cada oitão com base em sua altura e no tamanho de sua base
                areas_oitoes[i] = calcula_area_oitao(alturas_oitoes[i], bases_oitoes[i]);

                printf("\nÁrea do %dº oitão: %.2fm²\n\n", i+1, areas_oitoes[i]);
            }

            //Calcula a quantidade de tijolos necessários para construir cada parede, individualmente, com base em sua área e na quantidade de tijolos necessários para preenher uma área de um metro quadrado.
            //Soma a quantidade de tijolos necessários para construir uma única parede à uma variável que armazena a quantidade total de tijolos a ser utilizada na constução
            printf("\n----- Quantidade de tijolos por parede -----");
            for (i=0; i<qtde_paredes; i++) {
                qtde_tijolos_por_parede[i] = calcula_qtde_tijolos_por_parede(areas_paredes[i], qtde_tijolos_por_metro_quadrado);
                qtde_total_tijolos += qtde_tijolos_por_parede[i];
                printf("\n %dª parede: %d", i+1, qtde_tijolos_por_parede[i]);
            }

            //Calcula a quantidade de tijolos necessários para construir cada oitão, individualmente, com base em sua área e na quantidade de tijolos necessários para preencher uma área de um metro quadrado
            //Soma a quantidade de tijolos necessários para construir um único oitão à uma variável que armazena a quantidade total de tijolos a ser utilizada na constução
            printf("\n\n----- Quantidade de tijolos por oitão -----");
            for (i=0; i<qtde_oitoes; i++) {
                qtde_tijolos_por_oitao[i] = calcula_qtde_tijolos_por_oitao(areas_oitoes[i], qtde_tijolos_por_metro_quadrado);
                qtde_total_tijolos += qtde_tijolos_por_oitao[i];
                printf("\n %dº oitão: %d", i+1, qtde_tijolos_por_oitao[i]);
            }

            //Exibe a quantidade total de tijolos a ser utilizada na construção (paredes + oitões)
            printf("\n\n----- Quantidade total de tijolos -----");
            printf("\n %d tijolos", qtde_total_tijolos);

            //Calcula e exibe o preço total utilizado em tijolos para a construção com base na quantidade total de tijolos e no preço unitário do tijolo escolhido pelo usuário
            preco_total = preco_unitario * qtde_total_tijolos;
            printf("\n\n----- Preço total -----");
            printf("\n R$ %.2f", preco_total);
            break;
    }
}
