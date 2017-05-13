#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>

int main(){

    setlocale(LC_ALL, "");

    int usr_opt = 0, inclinacao = 0;
    float largura_base = 0, comprimento_base = 0, area_base = 0;

    do{

        printf("Digite a largura da base do telhado(m): ");
        scanf("%f", &largura_base);

        printf("Digite o comprimento da base do telhado(m): ");
        scanf("%f", &comprimento_base);

        area_base = largura_base * comprimento_base;
        printf("Área calculada: %.2f", area_base);

        int metade_largura = (largura_base / 2);

        if(metade_largura <= 2){
            inclinacao = 30;
        }
        else if(metade_largura <= 4){
            inclinacao = 33;
        }
        else if(metade_largura <= 6){
            inclinacao = 36;
        }
        else if(metade_largura <= 8){
            inclinacao = 39;
        }
        else if(metade_largura >= 10){
            inclinacao = 43;
        }

        printf("\nInclinação calculada: %d%", inclinacao);

        printf("\n\nContinuar? (Sim = 1, Não = 2): ");
        scanf("%d", &usr_opt);

        if(usr_opt == 2){
            system("cls");
        }

    }while(usr_opt == 2);

    printf("\n\n------\n\n");

    do{

        printf("Selecione o tipo de telha:\n\n");

        printf("1 - Cerâmica Americana\n");
        printf("2 - Cerâmica Colonial\n");
        printf("3 - Cerâmica Italiana\n");
        printf("4 - Cerâmica Romana\n");
        printf("5 - Cerâmica Portuguesa\n");
        printf("6 - Cerâmica Francesa\n");
        printf("7 - Plana\n");
        printf("8 - Amianto/Alumínio");

        printf("\n\nSua escolha: ");
        scanf("%d", &usr_opt);

        int qtd_telhas = 0, largura_telhado = 0, metade_largura = 0, altura_centro_telhado = 0;
        float area_telha = 0;

        switch(usr_opt){
            case 1:
                /*
                Americana:
                Inclinação mínima: 30%
                Consumo médio: 16 unidades / m²
                Dimensões: 43cm x 26cm
                */
                printf("\n------\n");
                printf("Cerâmica Americana\n");

                metade_largura = (largura_base / 2);
                altura_centro_telhado = tan(inclinacao) * metade_largura;

                largura_telhado = sqrt( pow(metade_largura, 2) + pow(altura_centro_telhado, 2) ) + 0.1;

                area_telha = 0.33 * 0.26;
                qtd_telhas = ceil( (comprimento_base * largura_telhado) / area_telha);

                printf("Quantidade de telhas: %d\n", qtd_telhas);
                system("pause");
                break;

            case 2:
                /*
                Colonial:
                Inclinação mínima: 30%
                Consumo médio: 24 unidades / m²
                Dimensões: 48cm x 20cm
                */
                printf("\n------\n");
                printf("Cerâmica Colonial\n");

                metade_largura = (largura_base / 2);
                altura_centro_telhado = tan(inclinacao) * metade_largura;

                largura_telhado = sqrt( pow(metade_largura, 2) + pow(altura_centro_telhado, 2) ) + 0.1;

                area_telha = 0.38 * 0.20;

                qtd_telhas = ceil( (comprimento_base * largura_telhado) / area_telha);

                printf("Quantidade de telhas: %d\n", qtd_telhas);
                system("pause");
                break;

            case 3:
                /*
                Italiana:
                Inclinação mínima: 30%
                Consumo médio: 14 unidades / m²
                Dimensões: 45cm x 26cm
                */
                printf("\n------\n");
                printf("Cerâmica Italiana\n");

                metade_largura = (largura_base / 2);
                altura_centro_telhado = tan(inclinacao) * metade_largura;

                largura_telhado = sqrt( pow(metade_largura, 2) + pow(altura_centro_telhado, 2) ) + 0.1;

                area_telha = 0.35 * 0.26;

                qtd_telhas = ceil( (comprimento_base * largura_telhado) / area_telha);

                printf("Quantidade de telhas: %d\n", qtd_telhas);
                system("pause");
                break;

            case 4:
                /*
                Romana:
                Inclinação mínima: 30%
                Consumo médio: 16 unidades / m²
                Dimensões: 40cm x 21cm
                */
                printf("\n------\n");
                printf("Cerâmica Romana\n");

                metade_largura = (largura_base / 2);
                altura_centro_telhado = tan(inclinacao) * metade_largura;

                largura_telhado = sqrt( pow(metade_largura, 2) + pow(altura_centro_telhado, 2) ) + 0.1;

                area_telha = 0.30 * 0.21;

                qtd_telhas = ceil( (comprimento_base * largura_telhado) / area_telha);

                printf("Quantidade de telhas: %d\n", qtd_telhas);
                system("pause");
                break;

            case 5:
                /*
                Portuguesa:
                Inclinação mínima: 30%
                Consumo médio: 17 unidades / m²
                Dimensões: 39cm x 20cm
                */
                printf("\n------\n");
                printf("Cerâmica Portuguesa\n");

                metade_largura = (largura_base / 2);
                altura_centro_telhado = tan(inclinacao) * metade_largura;

                largura_telhado = sqrt( pow(metade_largura, 2) + pow(altura_centro_telhado, 2) ) + 0.1;

                area_telha = 0.29 * 0.20;

                qtd_telhas = ceil( (comprimento_base * largura_telhado) / area_telha);

                printf("Quantidade de telhas: %d\n", qtd_telhas);
                system("pause");
                break;

            case 6:
                /*
                Francesa:
                Inclinação mínima: 36%
                Consumo médio: 16 unidades / m²
                Dimensões: 38cm x 24cm
                */
                printf("\n------\n");
                printf("Cerâmica Francesa\n");

                metade_largura = (largura_base / 2);
                altura_centro_telhado = tan(inclinacao) * metade_largura;

                largura_telhado = sqrt( pow(metade_largura, 2) + pow(altura_centro_telhado, 2) ) + 0.1;

                area_telha = 0.28 * 0.24;

                qtd_telhas = ceil( (comprimento_base * largura_telhado) / area_telha);

                printf("Quantidade de telhas: %d\n", qtd_telhas);
                system("pause");
                break;

            case 7:
                /*
                Plana:
                Inclinação mínima: 36%
                Dimensões: 42cm x 34cm
                */
                printf("\n------\n");
                printf("Telha Plana\n");

                metade_largura = (largura_base / 2);
                altura_centro_telhado = tan(inclinacao) * metade_largura;

                largura_telhado = sqrt( pow(metade_largura, 2) + pow(altura_centro_telhado, 2) ) + 0.1;

                area_telha = 0.32 * 0.34;

                qtd_telhas = ceil( (comprimento_base * largura_telhado) / area_telha);

                printf("Quantidade de telhas: %d\n", qtd_telhas);
                system("pause");
                break;

            case 8:
                /*
                Amianto:
                Inclinação mínima: 15%
                */
                printf("\n------\n");
                printf("Amianto/Alumínio\n");

                float a_largura, a_comprimento;

                printf("Digite a largura da telha: ");
                scanf("%f", &a_largura);

                printf("Digite a comprimento da telha: ");
                scanf("%f", &a_comprimento);

                area_telha = a_largura/100 * a_comprimento/100;

                metade_largura = (largura_base / 2);
                altura_centro_telhado = tan(inclinacao) * metade_largura;

                largura_telhado = sqrt( pow(metade_largura, 2) + pow(altura_centro_telhado, 2) ) + 0.1;

                qtd_telhas = ceil( (comprimento_base * largura_telhado) / area_telha);

                printf("Quantidade de telhas: %d\nInclinação mínima: 15%\n", qtd_telhas);
                system("pause");
                break;

            default:
                printf("Opção inválida.");
                Sleep(300);
                system("cls");
                break;
        }

    }while(usr_opt > 6);

    return 0;
}
