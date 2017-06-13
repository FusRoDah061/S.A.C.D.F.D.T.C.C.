#include<stdio.h>
#include<locale.h>
#include<windows.h> //COORD

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_F1 59
#define QTD_ANCORAS 10

//Move o cursor do terminal para a posição x,y indicada nos parâmetros
void mgotoxy(int x, int y)
{
      COORD p={x,y};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);//COLOCA O CURSOR NA COLUNA E LINHA INDICADA MAIS ABAIXO
}

void move_cursor(int pos, int ult_pos){

}

main(){

    setlocale(LC_ALL, "");

    printf("AJUDA\n-----\nÍndice:\n");
    printf("1 - INCLINAÇÃO DO TELHADO\n");
    printf("2 - MADEIRAMENTO DO TELHADO\n");
    printf("3 - MODELOS DE TELHAS\n");

    printf("* Você pode usar as teclas numéricas para navegar pelos itens.\n\n\n");

    printf("1. INCLINAÇÃO DO TELHADO\n------------------------\n");

    printf(" A inclinação do telhado é calculada com base na largura da laje (dividida por dois no\ncaso de telhado com duas águas).O valor para a inclinação é fornecido em porcentagem (%%),\nessa porcentagem corresponde a porção da base que será espelhada para compor a cumeeira.\n");
    printf(" Por exemplo, um telhado com base (laje) 12x10m, com inclinação de 30%% e duas águas, temos:\n");
    printf("  a. Calculamos a metade da largura da base, nesse caso 6 (12/2 = 6);\n");
    printf("  b. Calculamos 30%% do valor achado anteriormente, ficando com 1.8m (6 * 0.3 = 1.8).\n     Essa seráa altura da cumeeira.\n\n");

    printf("\n2. MADEIRAMENTO DO TELHADO\n--------------------------\n");

    printf("* Pressione F1 para uma imagem ilustrativa.\n");
    printf(" O madeiramento do telhado contempla toda a madeira usada para dar sustentação ao telhado:\n");
    printf(". Terça;\n. Pontalete;\n. Berço;\n. Mão Francesa;\n. Trama:\n  . Caibro;\n  . Ripas.\n\n");

    printf("\n3. MODELOS DE TELHAS\n-----------------\n");

    printf("\n TELHA PORTUGUESA\n-----------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 17 peças por metro quadrado\n");
    printf("   Dimensões: 38x20");
    printf("   Peso: 2,6 Kg por peça\n");
    printf("   Inclinação Mínima: 35%\n\n");

    printf("\n TELHA ROMANA\n-------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 16 peças por metro quadrado\n");
    printf("   Dimensões: 40x21");
    printf("   Peso: 2,7 Kg por peça\n");
    printf("   Inclinação Mínima: 35%\n\n");

    printf("\n TELHA AMERICANA\n-----------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 12 peças por metro quadrado\n");
    printf("   Dimensões: 46x26cm");
    printf("   Peso: 2,9 Kg por peça\n");
    printf("   Inclinação Mínima: 30%\n\n");

    printf("\n TELHA FRANCESA\n--------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 16 peças por metro quadrado\n");
    printf("   Dimensões: 38x24");
    printf("   Peso: 2,8 Kg por peça\n");
    printf("   Inclinação Mínima: 45%\n\n");

    printf("\n TELHA ITALIANA\n---------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 13 peças por metro quadrado\n");
    printf("   Dimensões: 45x26");
    printf("   Peso: 3,4 Kg por peça\n");
    printf("   Inclinação Mínima: 30%\n\n");

    printf("\n TELHA GERMÂNICA\n----------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 40 peças por metro quadrado\n");
    printf("   Dimensões:\n\tnormal 36x18,5cm\n\tcurta 24x18,5cm");
    printf("   Peso: 1,16 Kg por peça\n");
    printf("   Inclinação Mínima: 30%\n\n");

    printf("\n TELHA HOLANDESA\n----------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 17 peças por metro quadrado\n");
    printf("   Dimensões: 41x24cm");
    printf("   Peso: 2,5 Kg por peça\n");
    printf("   Inclinação Mínima: 30%\n\n");

    printf("\n TELHA URUGUAIA\n---------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 16 peças por metro quadrado\n");
    printf("   Dimensões: 28x19,5cm");
    printf("   Peso: 1 Kg por peça\n");
    printf("   Inclinação Mínima: 45%\n\n");

    printf("\n TELHA PLAN\n-----------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 26 peças por metro quadrado\n");
    printf("   Dimensões:\n\tcapa 48x16cm\n\tcanal: 48x19cm");
    printf("   Peso: 2,3 Kg por peça\n");
    printf("   Inclinação Mínima: 30%\n\n");

    printf("\n TELHA PAULISTA\n---------------\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 22 peças por metro quadrado\n");
    printf("   Dimensões:\n\tcapa 48x17cm\n\tcanal: 48x20cm");
    printf("   Peso: 2,2 Kg por peça\n");
    printf("   Inclinação Mínima: 30%\n");

    //mgotoxy(0,0);

    do{
        char key;
        key = getch();

        //Obtém os valores das teclas do teclado numérico (0, ..., 9);
        //A tecla 0 tem o código 48, e a tecla 9 tem o código 57, sendo assim a diferença entre o código da tecla e 48, resulta no valor da tecla de 1 a 9
        if(key >= 48 && key <= 57){
            printf("%d\n", key - 48);
        }

        if(key == KEY_F1){
            system("res\\madeiramento.png");
        }
    }while(1);

}
