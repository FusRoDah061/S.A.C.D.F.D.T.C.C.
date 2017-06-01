#include<stdio.h>
#include<stdlib.h>
#include<windows.h> //COORD
#include<locale.h>
#include<string.h>
#include<locale.h>

//Quantidade de itens na lista
#define QTD_ITENS 7

//C�digo das teclas
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

#define TRUE 1
#define FALSE 0

//Linha na qual a lista come�a
#define LIST_START 4

//Estrutura que representa cada item da lista
typedef struct
{
    int x; //Coordenadas x da posi��o para a qual o cursor deve ser movido no console
    int y; //Coordenadas y da posi��o para a qual o cursor deve ser movido no console
    char value[15]; //Valor entrado pelo usu�rio
    char label[128]; //Descri��o do item que ser� mostrado na tela

}_NODE;

//Inicializa��o dos itens da lista.
//Novos itens s�o acrescentados aqui
void init_nodes(_NODE * nodes)
{
    //Item 1
    nodes[0].x = 9;
    nodes[0].y = 4;
    strcpy(nodes[0].value, "0");
    strcpy(nodes[0].label, "Item 1:");

    //Item 2
    nodes[1].x = 9;
    nodes[1].y = 5;
    strcpy(nodes[1].value, "0");
    strcpy(nodes[1].label, "Item 2:");

    //Item 3
    nodes[2].x = 9;
    nodes[2].y = 6;
    strcpy(nodes[2].value, "0");
    strcpy(nodes[2].label, "Item 3:");

    //Item 4
    nodes[3].x = 9;
    nodes[3].y = 7;
    strcpy(nodes[3].value, "0");
    strcpy(nodes[3].label, "Item 4:");

    //Item 5
    nodes[4].x = 9;
    nodes[4].y = 8;
    strcpy(nodes[4].value, "0");
    strcpy(nodes[4].label, "Item 5:");

    //Item 6
    nodes[5].x = 9;
    nodes[5].y = 9;
    strcpy(nodes[5].value, "0");
    strcpy(nodes[5].label, "Item 6:");

    //Item 7
    nodes[6].x = 9;
    nodes[6].y = 10;
    strcpy(nodes[6].value, "0");
    strcpy(nodes[6].label, "Item 7:");
}

//Move o cursor do terminal para a posi��o x,y indicada nos par�metros
void mgotoxy(int x, int y)
{
      COORD p={x,y};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

//Move o cursor para o item (especificado por "goto_node") da lista ("nodes")
void update_caret(_NODE node)
{
    int i;
    for(i = LIST_START; i < LIST_START + QTD_ITENS; i++){
        mgotoxy(0, i);
        printf(" ");
    }

    //Move o '>' para o inicio da linah do item
    mgotoxy(0, node.y);
    printf(">");
    //Move o cursor para a posi��o onde est� o valor
    mgotoxy(node.x, node.y);
}

//"Limpa" a linha especificada
void clear_line(int line)
{
    mgotoxy(0, line);
    printf("                                                       ");
}

//Local onde as regras de neg�cio referentes a cada item podem ser implementadas
void handle_ops(_NODE node, int index)
{

    mgotoxy(0, QTD_ITENS + 7);

    //index representa o �ndice do item, na ordem posi��o que este aparece na lista (come�ando em zero)
    switch(index){

    case 0:
        printf("\n------\nSoma:\n");
        int a, soma;

        printf("Digite A: ");
        scanf("%d", &a);

        soma = a + atoi(node.value) ;

        printf("\nSoma = %d\n", soma);
    }

}

int main(void)
{
    setlocale(LC_ALL, "");

    //Itens da lista
    _NODE nodes[QTD_ITENS];

    //Inicializa a lista
    init_nodes(nodes);

    int current_node = 0, //Item da lista no qual o cursor se encontra atualmente
        update_screen = TRUE; //Controla quando a lista deve ser atualizada. Inicia TRUE para que a lista seja desenhada na inicializa��o do programa

    char key; //Tecla pressionada no teclado

    do{

        if(update_screen == TRUE){

            //system("cls");

            mgotoxy(0, 0);

            printf("Navegue com as setas para cima e para baixo\nPressione ENTER em um item pra edit�-lo\nPressione a tecla ESC para sair\n");

            //Imprime a lista
            int i;
            for(i = 0; i < QTD_ITENS; i++){
                printf("\n %s %s", nodes[i].label, nodes[i].value);
            }

            //Move o cursor para o item especificado por "current_node"
            update_caret(nodes[current_node]);
            //Indica para n�o atualizar a lista
            update_screen = FALSE;

        }

        //L� a tecla pressionada no teclado
        key = getch();

        //Sobe um item na lista
        if(key == KEY_UP){

            //Sobe um item na lista. Caso j� esteja no primeiro item, indica o �ltimo item como pr�ximo.
            //Altera o valor do item, que ser� carregado ao final dessa itera��o
            if(current_node <= 0){
                current_node = QTD_ITENS - 1;
            }
            else{
                current_node--;
            }

        }
        //Desce um item na lista
        else if(key == KEY_DOWN){

            //Desce um item na lista. Caso j� esteja no �ltimo item, indica o primeiro item como pr�ximo.
            //Altera o valor do item, que ser� carregado ao final dessa itera��o
            if(current_node >= QTD_ITENS - 1){
                current_node = 0;
            }
            else{
                current_node++;
            }

        }
        //Seleciona um item na lista
        else if(key == KEY_ENTER){

            //Posiciona o cursor na posi��o de edi��o
            mgotoxy(0, QTD_ITENS + 5);
            printf("Digite um valor para o item: "); //Essa linha � apagada no final da edi��o

            //update_caret(coords, current_node);

            scanf("%14[^\n]", nodes[current_node].value);

            //Executa alguma opera��o adicional para o item
            handle_ops(nodes[current_node], current_node);

            //Limpa o buffer de entrada
            setbuf(stdin, NULL);
            fflush(stdin);

            //Limpa a linha de edi��o ( printf("Digite um valor para o item: "); )
            clear_line(QTD_ITENS + 5);

            update_screen = TRUE;
            update_caret(nodes[current_node]);

        }

        //DEBUG
        //mgotoxy(0, QTD_ITENS + 5);
        //printf("current_node: %d", current_node);

        //Atualiza o cursor para a posi��o do item atual (ao pressionar a tecla cima/baixo, o cursor � atualizado aqui)
        update_caret(nodes[current_node]);

    }while(key != KEY_ESC);

    //Ao pressionar ESC o programa � finalizado
    mgotoxy(0, QTD_ITENS + 5);

    system("pause");

    return 0;

}
