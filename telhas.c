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
        printf("�rea calculada: %.2f", area_base);

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

        printf("\nInclina��o calculada: %d%", inclinacao);

        printf("\n\nContinuar? (Sim = 1, N�o = 2): ");
        scanf("%d", &usr_opt);

        if(usr_opt == 2){
            system("cls");
        }

    }while(usr_opt == 2);

    printf("\n\n------\n\n");

    do{

        printf("Selecione o tipo de telha:\n\n");

        printf("1 - Cer�mica Americana\n");
        printf("2 - Cer�mica Colonial\n");
        printf("3 - Cer�mica Italiana\n");
        printf("4 - Cer�mica Romana\n");
        printf("5 - Cer�mica Portuguesa\n");
        printf("6 - Cer�mica Francesa\n");
        printf("7 - Plana\n");
        printf("8 - Amianto/Alum�nio");

        printf("\n\nSua escolha: ");
        scanf("%d", &usr_opt);

        int qtd_telhas = 0, largura_telhado = 0, metade_largura = 0, altura_centro_telhado = 0;
        float area_telha = 0;

        switch(usr_opt){
            case 1:
                /*
                Americana:
                Inclina��o m�nima: 30%
                Consumo m�dio: 16 unidades / m�
                Dimens�es: 43cm x 26cm
                */
                printf("\n------\n");
                printf("Cer�mica Americana\n");

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
                Inclina��o m�nima: 30%
                Consumo m�dio: 24 unidades / m�
                Dimens�es: 48cm x 20cm
                */
                printf("\n------\n");
                printf("Cer�mica Colonial\n");

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
                Inclina��o m�nima: 30%
                Consumo m�dio: 14 unidades / m�
                Dimens�es: 45cm x 26cm
                */
                printf("\n------\n");
                printf("Cer�mica Italiana\n");

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
                Inclina��o m�nima: 30%
                Consumo m�dio: 16 unidades / m�
                Dimens�es: 40cm x 21cm
                */
                printf("\n------\n");
                printf("Cer�mica Romana\n");

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
                Inclina��o m�nima: 30%
                Consumo m�dio: 17 unidades / m�
                Dimens�es: 39cm x 20cm
                */
                printf("\n------\n");
                printf("Cer�mica Portuguesa\n");

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
                Inclina��o m�nima: 36%
                Consumo m�dio: 16 unidades / m�
                Dimens�es: 38cm x 24cm
                */
                printf("\n------\n");
                printf("Cer�mica Francesa\n");

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
                Inclina��o m�nima: 36%
                Dimens�es: 42cm x 34cm
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
                Inclina��o m�nima: 15%
                */
                printf("\n------\n");
                printf("Amianto/Alum�nio\n");

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

                printf("Quantidade de telhas: %d\nInclina��o m�nima: 15%\n", qtd_telhas);
                system("pause");
                break;

            default:
                printf("Op��o inv�lida.");
                Sleep(300);
                system("cls");
                break;
        }

    }while(usr_opt > 6);

    return 0;
}
