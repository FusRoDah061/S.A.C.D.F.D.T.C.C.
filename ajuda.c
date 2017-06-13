#include<stdio.h>
#include<locale.h>
#include<windows.h> //COORD

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_F1 59
#define QTD_ANCORAS 10

//Move o cursor do terminal para a posi��o x,y indicada nos par�metros
void mgotoxy(int x, int y)
{
      COORD p={x,y};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);//COLOCA O CURSOR NA COLUNA E LINHA INDICADA MAIS ABAIXO
}

void move_cursor(int pos, int ult_pos){

}

main(){

    setlocale(LC_ALL, "");

    printf("AJUDA\n-----\n�ndice:\n");
    printf("1 - INCLINA��O DO TELHADO\n");
    printf("2 - MADEIRAMENTO DO TELHADO\n");
    printf("3 - MODELOS DE TELHAS\n");

    printf("* Voc� pode usar as teclas num�ricas para navegar pelos itens.\n\n\n");

    printf("1. INCLINA��O DO TELHADO\n------------------------\n");

    printf(" A inclina��o do telhado � calculada com base na largura da laje (dividida por dois no\ncaso de telhado com duas �guas).O valor para a inclina��o � fornecido em porcentagem (%%),\nessa porcentagem corresponde a por��o da base que ser� espelhada para compor a cumeeira.\n");
    printf(" Por exemplo, um telhado com base (laje) 12x10m, com inclina��o de 30%% e duas �guas, temos:\n");
    printf("  a. Calculamos a metade da largura da base, nesse caso 6 (12/2 = 6);\n");
    printf("  b. Calculamos 30%% do valor achado anteriormente, ficando com 1.8m (6 * 0.3 = 1.8).\n     Essa ser�a altura da cumeeira.\n\n");

    printf("\n2. MADEIRAMENTO DO TELHADO\n--------------------------\n");

    printf("* Pressione F1 para uma imagem ilustrativa.\n");
    printf(" O madeiramento do telhado contempla toda a madeira usada para dar sustenta��o ao telhado:\n");
    printf(". Ter�a;\n. Pontalete;\n. Ber�o;\n. M�o Francesa;\n. Trama:\n  . Caibro;\n  . Ripas.\n\n");

    printf("\n3. MODELOS DE TELHAS\n-----------------\n");

    printf("\n TELHA PORTUGUESA\n-----------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 17 pe�as por metro quadrado\n");
    printf("   Dimens�es: 38x20");
    printf("   Peso: 2,6 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 35%\n\n");

    printf("\n TELHA ROMANA\n-------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 16 pe�as por metro quadrado\n");
    printf("   Dimens�es: 40x21");
    printf("   Peso: 2,7 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 35%\n\n");

    printf("\n TELHA AMERICANA\n-----------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 12 pe�as por metro quadrado\n");
    printf("   Dimens�es: 46x26cm");
    printf("   Peso: 2,9 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%\n\n");

    printf("\n TELHA FRANCESA\n--------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 16 pe�as por metro quadrado\n");
    printf("   Dimens�es: 38x24");
    printf("   Peso: 2,8 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 45%\n\n");

    printf("\n TELHA ITALIANA\n---------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 13 pe�as por metro quadrado\n");
    printf("   Dimens�es: 45x26");
    printf("   Peso: 3,4 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%\n\n");

    printf("\n TELHA GERM�NICA\n----------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 40 pe�as por metro quadrado\n");
    printf("   Dimens�es:\n\tnormal 36x18,5cm\n\tcurta 24x18,5cm");
    printf("   Peso: 1,16 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%\n\n");

    printf("\n TELHA HOLANDESA\n----------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 17 pe�as por metro quadrado\n");
    printf("   Dimens�es: 41x24cm");
    printf("   Peso: 2,5 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%\n\n");

    printf("\n TELHA URUGUAIA\n---------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 16 pe�as por metro quadrado\n");
    printf("   Dimens�es: 28x19,5cm");
    printf("   Peso: 1 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 45%\n\n");

    printf("\n TELHA PLAN\n-----------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 26 pe�as por metro quadrado\n");
    printf("   Dimens�es:\n\tcapa 48x16cm\n\tcanal: 48x19cm");
    printf("   Peso: 2,3 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%\n\n");

    printf("\n TELHA PAULISTA\n---------------\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 22 pe�as por metro quadrado\n");
    printf("   Dimens�es:\n\tcapa 48x17cm\n\tcanal: 48x20cm");
    printf("   Peso: 2,2 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%\n");

    //mgotoxy(0,0);

    do{
        char key;
        key = getch();

        //Obt�m os valores das teclas do teclado num�rico (0, ..., 9);
        //A tecla 0 tem o c�digo 48, e a tecla 9 tem o c�digo 57, sendo assim a diferen�a entre o c�digo da tecla e 48, resulta no valor da tecla de 1 a 9
        if(key >= 48 && key <= 57){
            printf("%d\n", key - 48);
        }

        if(key == KEY_F1){
            system("res\\madeiramento.png");
        }
    }while(1);

}
