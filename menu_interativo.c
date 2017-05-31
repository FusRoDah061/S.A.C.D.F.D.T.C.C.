#include<stdio.h>
#include<stdlib.h>
#include<windows.h> //COORD
#include<locale.h>

//Quantidade de itens na lista
#define QTD_ITENS 7

//Código das teclas
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

#define TRUE 1
#define FALSE 0

//Move o cursor d oterminal para a posição x,y indicada nos parâmetros
void mgotoxy(int x, int y)
{
      COORD p={x,y};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);//COLOCA O CURSOR NA COLUNA E LINHA INDICADA MAIS ABAIXO
}

//Move o cursor para o item (especificado por "goto_node") da lista ("nodes")
void update_caret(int nodes[QTD_ITENS][2], int goto_node)
{
    //Limpa o indicador do primeiro item
    if(goto_node != 0){
        mgotoxy(0, nodes[0][1]);
        printf(" ");
    }

    //Limpa o indicador de um item antes do atual
    mgotoxy(0, nodes[goto_node - 1][1]);
    printf(" ");

    //Limpa o indicador de um item depois do atual
    mgotoxy(0, nodes[goto_node + 1][1]);
    printf(" ");

    //Limpa o indicador do último item
    if(goto_node != QTD_ITENS - 1){
        mgotoxy(0, nodes[QTD_ITENS - 1][1]);
        printf(" ");
    }

    //Move o '>' para o inicio da linah do item
    mgotoxy(0, nodes[goto_node][1]);
    printf(">");
    //Move o cursor para a posição onde está o valor
    mgotoxy(nodes[goto_node][0], nodes[goto_node][1]);
}

//"Limpa" a linha especificada
void clear_line(int line){

    mgotoxy(0, line);
    printf("                                                       ");

}

int main(void)
{

    //Coordenadas x,y da posição para a qual o cursor deve ser movido no console
    int coords[QTD_ITENS][2] = {
        {9, 4}, //Item 1
        {9, 5}, //Item 2
        {9, 6}, //Item 3
        {9, 7}, //Item 4
        {9, 8}, //Item 5
        {9, 9}, //Item 6
        {9, 10} //Item 7
    };

    int current_node = 0, //Item da lista no qual o cursor se encontra atualmente
        update_screen = TRUE; //Controla quando a lista deve ser atualizada. Inicia TRUE para que a lista seja desenhada na inicialização do programa

    char key; //Tecla pressionada no teclado

    //Cada item necessita de uma variável individual, para possibilitar a edição dos valores
    int item1 = 0,
        item2 = 0,
        item4 = 0,
        item5 = 0;
    float item3 = 0.0,
        item6 = 0.0,
        item7 = 0.0;

    do{

        if(update_screen == TRUE){

            system("cls");

            printf("Navegue com as setas para cima e para baixo\nPressione ENTER em um item pra editá-lo\nPressione a tecla ESC para sair\n");

            printf("\n Item 1: %d", item1);
            printf("\n Item 2: %d", item2);
            printf("\n Item 3: %f", item3);
            printf("\n Item 4: %d", item4);
            printf("\n Item 5: %d", item5);
            printf("\n Item 6: %f", item6);
            printf("\n Item 7: %f", item7);

            //Move o cursor para o item especificado por "current_node"
            update_caret(coords, current_node);
            //Indica para não atualizar a lista
            update_screen = FALSE;

        }

        //Lê a tecla pressionada no teclado
        key = getch();

        //Sobe um item na lista
        if(key == KEY_UP){

            //Sobe um item na lista. Caso já esteja no primeiro item, indica o último item como próximo.
            //Altera o valor do item, que será carregado ao final dessa iteração
            if(current_node <= 0){
                current_node = QTD_ITENS - 1;
            }
            else{
                current_node--;
            }

        }
        //Desce um item na lista
        else if(key == KEY_DOWN){

            //Desce um item na lista. Caso já esteja no último item, indica o primeiro item como próximo.
            //Altera o valor do item, que será carregado ao final dessa iteração
            if(current_node >= QTD_ITENS - 1){
                current_node = 0;
            }
            else{
                current_node++;
            }

        }
        //Seleciona um item na lista
        else if(key == KEY_ENTER){

            //Posiciona o cursor na posição de edição
            mgotoxy(0, QTD_ITENS + 5);
            printf("Digite um valor para o item: "); //Essa linha é apagada no final da edição

            //update_caret(coords, current_node);

            //Identifica o item atual e direciona para a leitura deste
            switch(current_node){

                //Cada caso representa um item na lista
                case 0:
                    scanf("%d", &item1);
                break;

                case 1:
                    scanf("%d", &item2);
                break;

                case 2:
                    scanf("%f", &item3);
                break;

                case 3:
                    scanf("%d", &item4);
                break;

                case 4:
                    scanf("%d", &item5);
                break;

                case 5:
                    scanf("%f", &item6);
                break;

                case 6:
                    scanf("%f", &item7);
                break;
            }

            //Limpa o buffer de entrada
            setbuf(stdin, NULL);
            fflush(stdin);

            //Limpa a linha de edição ( printf("Digite um valor para o item: "); )
            clear_line(QTD_ITENS + 5);

            update_screen = TRUE;
            update_caret(coords, current_node);

        }

        //DEBUG
        //mgotoxy(0, QTD_ITENS + 5);
        //printf("current_node: %d", current_node);

        //Atualiza o cursor para a posição do item atual (ao pressionar a tecla cima/baixo, o cursor é atualizado aqui)
        update_caret(coords, current_node);

    }while(key != KEY_ESC);

    //Ao pressionar ESC o programa é finalizado
    mgotoxy(0, QTD_ITENS + 5);

    system("pause");

    return 0;

}
