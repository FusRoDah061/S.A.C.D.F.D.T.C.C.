#include<stdio.h>
#include<locale.h>
#include<windows.h> //COORD

#define KEY_F1 59
#define KEY_F2 60
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F5 63
#define KEY_F6 64
#define QTD_ANCORAS 6

//Move o cursor do terminal para a posi��o x,y indicada nos par�metros
void mgotoxy(int x, int y)
{
      COORD p={x,y};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);//COLOCA O CURSOR NA COLUNA E LINHA INDICADA MAIS ABAIXO
}

int main(void){

    setlocale(LC_ALL, "");

    printf("AJUDA\n-----\n�ndice:\n");
    printf("1 - INCLINA��O DO TELHADO\n");
    printf("2 - MADEIRAMENTO DO TELHADO\n");
    printf("3 - MODELOS DE TELHAS\n");
  	printf("4 - MODELOS DE TIJOLOS\n");
  	printf("5 - MODELOS DE REVESTIMENTO PARA PAREDE\n");
  	printf("6 - MODELOS DE PISO");

    printf("\n* Voc� pode usar as teclas num�ricas para navegar pelos itens.\n\n\n");

    printf("1. INCLINA��O DO TELHADO\n------------------------>\n");

    printf("* Pressione F1 para uma imagem ilustrativa.\n\n");

    printf(" A inclina��o do telhado � calculada com base na largura da laje (dividida por dois no\ncaso de telhado com duas �guas).O valor para a inclina��o � fornecido em porcentagem (%%),\nessa porcentagem corresponde a por��o da base que ser� espelhada para compor a cumeeira.\n");
    printf(" Por exemplo, um telhado com base (laje) 12x10m, com inclina��o de 30%% e duas �guas, temos:\n");
    printf("  a. Calculamos a metade da largura da base, nesse caso 6 (12/2 = 6);\n");
    printf("  b. Calculamos 30%% do valor achado anteriormente, ficando com 1.8m (6 * 0.3 = 1.8).\n     Essa ser�a altura da cumeeira.\n\n");

    printf("\n2. MADEIRAMENTO DO TELHADO\n-------------------------->\n");

    printf("* Pressione F2 para uma imagem ilustrativa.\n\n");

    printf(" O madeiramento do telhado contempla toda a madeira usada para dar sustenta��o ao telhado:\n");
    printf(". Ter�a;\n. Pontalete;\n. Ber�o;\n. M�o Francesa;\n. Trama:\n  . Caibro;\n  . Ripas.\n\n");

    printf("\n3. MODELOS DE TELHAS\n-------------------->\n");

    printf("* Pressione F3 para uma imagem ilustrativa.\n\n");

    printf("\n TELHA PORTUGUESA\n----------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 17 pe�as por metro quadrado\n");
    printf("   Dimens�es: 38x20");
    printf("   Peso: 2,6 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 35%%\n\n");

    printf("\n TELHA ROMANA\n------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 16 pe�as por metro quadrado\n");
    printf("   Dimens�es: 40x21");
    printf("   Peso: 2,7 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 35%%\n\n");

    printf("\n TELHA AMERICANA\n---------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 12 pe�as por metro quadrado\n");
    printf("   Dimens�es: 46x26cm");
    printf("   Peso: 2,9 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%%\n\n");

    printf("\n TELHA FRANCESA\n--------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 16 pe�as por metro quadrado\n");
    printf("   Dimens�es: 38x24");
    printf("   Peso: 2,8 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 45%%\n\n");

    printf("\n TELHA ITALIANA\n--------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 13 pe�as por metro quadrado\n");
    printf("   Dimens�es: 45x26");
    printf("   Peso: 3,4 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%%\n\n");

    printf("\n TELHA GERM�NICA\n---------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 40 pe�as por metro quadrado\n");
    printf("   Dimens�es:\n\tnormal 36x18,5cm\n\tcurta 24x18,5cm");
    printf("   Peso: 1,16 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%%\n\n");

    printf("\n TELHA HOLANDESA\n---------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 17 pe�as por metro quadrado\n");
    printf("   Dimens�es: 41x24cm");
    printf("   Peso: 2,5 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%%\n\n");

    printf("\n TELHA URUGUAIA\n--------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 16 pe�as por metro quadrado\n");
    printf("   Dimens�es: 28x19,5cm");
    printf("   Peso: 1 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 45%%\n\n");

    printf("\n TELHA PLAN\n----------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 26 pe�as por metro quadrado\n");
    printf("   Dimens�es:\n\tcapa 48x16cm\n\tcanal: 48x19cm");
    printf("   Peso: 2,3 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%%\n\n");

    printf("\n TELHA PAULISTA\n--------------->\n");

    printf("   Material: Cer�mica\n");
    printf("   Quantidade: 22 pe�as por metro quadrado\n");
    printf("   Dimens�es:\n\tcapa 48x17cm\n\tcanal: 48x20cm");
    printf("   Peso: 2,2 Kg por pe�a\n");
    printf("   Inclina��o M�nima: 30%%\n");

    printf("\n\n4. MODELOS DE TIJOLOS\n--------------------->\n");

    printf("* Pressione F4 para uma imagem ilustrativa.\n\n");

    printf("\n BLOCO CER�MICO\n--------------->\n");

  	printf("   Os blocos cer�micos s�o feitas � base de argila cozida e s�o um itens mais utilizados na\nconstru��o de paredes de alvenaria, podendo haver varia��es em rela��o ao n�mero de furos e\ntamanho, sendo que os maiores s�o indicados para esturutras maiores.\n");
  	printf("   Os blocos furados s�o mais leves e baratos, por�m, s�o mais vulner�veis a quebras durante\na obra.");
  	printf("   � importante destacar que este material n�o � estrutural, ou seja, pode ser utilizado\napenas para o fechamento e n�o para sustenta��o de cobertura ou laje.\n");

    printf("\n TIJOLOS MACI�OS\n---------------->\n");

    printf("   Os tijolos maci�os s�o feitos � base de argila cozida e s�o um dos itens mais utilizados\nna constru��o de paredes de alvenaria.\n");
  	printf("   Possuem mais resist�ncia com rela��o aos blocos cer�micos, podendo ser deixados aparentes\nou serem divididos ao meio para serem usados como revestimento para as paredes.\n");

    printf("\n TIJOLOS DE ADOBE\n----------------->\n");

    printf("   S�o basicamente uma mistura de terra e �gua, com acr�scimo de palhas ou outros materiais\norg�nicos, feitos atrav�s de processo artesanal ou semi-industrial de moldagem e secagem.\n");
  	printf("   � um tijolo ecol�gico, porque dispensa o cozimento que gasta muita energia e emite muitos\ngases, mas n�o � muito resistente a interp�ries como chuva e vento, pois absorve muita �gua\ne pode se desfazer em contato direto e intenso com chuva.\n");

    printf("\n TIJOLOS LAMINADOS\n------------------>\n");

    printf("   Esta pe�a tamb�m � conhecida como tijolo de 21 furos devido � quantidade de orif�cios que\napresenta.\n");
  	printf("   Este tipo de tijolo apresenta melhor ader�ncia de argamassa, possibilitando uma estrutura\nmais firme e tamb�m tem alta durabilidade.\n");
  	printf("   Indica-se utilizar o modelo horizontalmente, para que apenas a parte lisa fique � mostra.\n� muito comum a utiliza��o deste tipo de tijolo em projetos com tijolo aparente, como fachadas,\npor exemplo.\n");

    printf("\n TIJOLOS E BLOCOS DE CONCRETO\n----------------------------->\n");

    printf("   Apresenta uma estrutura mais robusta, sendo comumente utilizado em constru��es maiores e\ntamb�m em alicerces para casas.\n");
	printf("   A vantagem na utiliza��o de tijolos ou blocos de concreto � com rela��o � economia no consumo\nde argamassa, pois sua anatomia facilita a jun��o das pe�as.\n");

  	printf("\n TIJOLOS ECOL�GICOS\n------------------->\n");

    printf("   Produzido a partir de uma mistura de solo, cimento e �gua, � uma pe�a muito utilizada em\nconstru��es sustent�veis devido a sua tend�ncia ecol�gica.\n");
  	printf("   Suas vantagens s�o o baixo consumo de argamassa, isolamento t�rmico e ac�stico, f�cil encaixe\ne possibilidade de ficar aparente.\n");
	printf("   Por�m, � uma pe�a que necessita de um profissional especializado e tamb�m n�o � indicada para\nlocais muito �midos.\n");

  	printf("\n\n5. MODELOS DE REVESTIMENTO PARA PAREDE\n-------------------------------------->\n");

    printf("* Pressione F5 para uma imagem ilustrativa.\n\n");

    printf("\n PAPEL DE PAREDE\n---------------->\n");

    printf("   Revestimento simples, facilmente encontrado e de f�cil instala��o.\n");
  	printf("   Este tipo de revestimento � indicado para regi�es e ambientes menos �midos, sendo assim,\n� ideal evitar a utiliza��o de papel de parede em banheiros e cozinhas.\n");

    printf("\n MADEIRA\n-------->\n");

    printf("   Este tipo de material possui uma grande variedade de cores e tonalidades e ajuda a\naquecer os c�modos, mantendo uma temperatura agrad�vel no ambiente.\n");

    printf("\n PASTILHAS\n---------->\n");

    printf("   As pastilhas s�o pequenas pe�as que podem ser feitas de cer�mica, resina ou vidro e\ns�o aplicadas �s paredes como se fossem pequenos azulejos.\n");

	printf("\n LADRILHO HIDR�ULICO\n-------------------->\n");

    printf("   S�o azulejos que podem apresentar varia��es nos tamanhos, mas muito conhecidos por\nsuas estampas coloridas e bem detalhadas.\n");

  	printf("\n AZULEJO COMUM\n-------------->\n");

    printf("   S�o azuelejos que se apresentam no mesmo formato dos ladrilhos hidr�ulicos, um pouco\nmaiores �s vezes, mas n�o possuem um diferencial em espec�fico.\n");

    printf("\n\n6. TIPOS DE PISO\n---------------->\n");

    printf("* Pressione F6 para uma imagem ilustrativa.\n\n");

    printf("\n CER�MICO\n--------->\n");

    printf("   A cer�mica � o tipo de piso mais conhecido e usado no Brasil. S�o encontradas de\nv�rios tamanhos (desde 20�30, 40�40, 60�60, 80�80, 100�100), texturas, qualidades e pre�os. Podem ser\nutilizadas em �reas internas e externas.\n");

    printf("\n PORCELANATO\n------------>\n");

    printf("   O Porcelanato � produzido em massa �nica j� na sua colora��o e com mat�rias-primas\nnobres.Podem ser semi-polidos, polidos e pe�a r�stica. Tamb�m h� os porcelanatos esmaltados e os\nporcelanatos digitais polidos com a mais alta qualidade e com v�rias texturas, principalmente imitando\nmadeiras, m�rmores e granitos.\n");

    printf("\n GRANITO\n-------->\n");

    printf("   O granito � uma pedra muito indicada para pisos devido a sua beleza, resist�ncia\ne durabilidade. S�o utilizados desde resid�ncias at� em locais com grande movimenta��o de pessoas\ncomo shoppings, supermercados, aeroportos, etc. Possuem v�rias tonalidades e quanto mais raro mais caro.\n");

    printf("\n M�RMORE\n-------->\n");

    printf("   O m�rmore tamb�m � uma rocha metam�rfica, composta principalmente por minerais\nde calcita com colara��o mais uniforme e forma��o de veios definidos. � indicado para utiliza��o em\nambientes internos apenas.\n");

    printf("\n LAMINADO DE MADEIRA\n-------------------->\n");

    printf("   Esse piso tem esse nome porque s�o constitu�dos de l�minas de madeira. � um tipo\nde piso flutuante porque n�o � colado no contrapiso. S�o assentados sobre manta, em sistema de encaixe\ntipo click e presos pelos rodap�s que s�o colados.S�o sustent�veis por serem de madeira reflorestada.\n");

    printf("\n SILESTONE\n---------->\n");

    printf("   Silestone � um material composto por grande quantidade de quartzo, outros minerais\nem menor escala, resina de poli�ster e pigmentos. Com porosidade nula, possui v�rias texturas e um\ncusto muito elevado.\n");

    printf("\n T�BUA CORRIDA\n-------------->\n");

    printf("  Piso em madeira natural de lei, geralmente extra�da da Amaz�nia. Conferem muita beleza\ne conforto, mas n�o s�o sustent�veis. Sua instala��o � sobre um ripamento e possuem encaixe tipo\nmacho-f�mea.\n");

    printf("\n TAC�O\n------>\n");

    printf("   Os tacos foram sucesso nos anos 1960 a 1980. Atualmente s�o utilizados em ambientes mais\nespec�ficos e possuem custo elevado. Assim como a t�bua corrida, necessitam de raspar e\nsintecar. As madeiras mais comuns para tac�o s�o a gr�pia, cumaru e ip�.\n");

    printf("\n LAJOTA\n------->\n");

    printf("   Instaladas tanto em paredes internas como em fachadas, as lajotas apresentam in�meras\nvantagens, entre elas a �tima resist�ncia �s varia��es clim�ticas, a beleza e a rela��o\ncusto X benef�cio. As pe�as est�o cada vez mais inovadoras, com formas geom�tricas variadas e com pinturas\nde desenhos que conferem um charme todo especial ao ambiente.\n");

    printf("\n ARD�SIA\n-------->\n");

    printf("   Piso em pedra ard�sia foi largamente utilizado nos anos 1980 devido a sua durabilidade e\nbaixo custo. Podem ser utilizadas em pisos internos de �reas molhadas e �reas externas.\n");

    printf("\n CIMENTO QUEIMADO\n----------------->\n");

    printf("   Solu��o de baixo custo para pisos e quando bem feita confere �timo acabamento. Indicado\ntanto para �reas internas quanto para �reas externas. Muito utilizado em bares, boates e\ngalp�es industriais.\n");

    printf("\n PEDRA PORTUGUESA\n----------------->\n");

    printf("   Muito utilizadas em cal�adas a pedra portuguesa mais famosa do mundo � o cal�ad�o de\nCopacabana no Rio de Janeiro. A execu��o do trabalho � bastante demorada porque cada pedra �\nassentada uma a uma.\n");

    printf("\n PEDRA S�O TOM�\n--------------->\n");

    printf("  Com v�rios outros nomes pelo Brasil afora a Pedra S�o Tom� � o piso mais utilizado ao\nredor das piscinas. S�o vendidas em regulares 30x30cm e irregulares (retalhos).\n");

    printf("\n GRANITINA\n---------->\n");

    printf("  A granitina � uma massa de cimento misturada com pequenas pedrinhas de granito aplicadas\nno piso. Ap�s a cura do piso � polida com discos diamantados que conferem uma superf�cie\nlisa e brilhante. O piso em granitina � muito utilizado em �reas internas e externas de clubes, escolas,\naeroportos.\n");


  	//Posiciona o cursor no in�cio do texto
    mgotoxy(0,0);

  	char key;

  	//Linhas que cont�m os t�tulos numerados, para as quais o cursor ir� "pular"
    int linhas_ancoras[QTD_ANCORAS];

    linhas_ancoras[0] = 12;
    linhas_ancoras[1] = 25;
    linhas_ancoras[2] = 39;
    linhas_ancoras[3] = 130;
    linhas_ancoras[4] = 186;
    linhas_ancoras[5] = 218;

    do{
        char key;
        key = getch();

        //Obt�m os valores das teclas do teclado num�rico (0, ..., 9);
        //A tecla 0 tem o c�digo 48, e a tecla 9 tem o c�digo 57, sendo assim a diferen�a entre o c�digo da tecla e 48, resulta no valor da tecla de 1 a 9
        if(key >= 48 && key <= 57){
            //printf("%%d\n", key - 48);
            int num = (key - 48) - 1;

            if(num < QTD_ANCORAS){
                mgotoxy(0, linhas_ancoras[num]);
            }

        }
        else if(key == KEY_F1){
            system("res\\inclinacao.jpg");
        }
        else if(key == KEY_F2){
            system("res\\madeiramento.png");
        }
        else if(key == KEY_F3){
            system("res\\telhas.jpg");
        }
        else if(key == KEY_F4){
            system("res\\tijolos.png");
        }
        else if(key == KEY_F5){
            system("res\\revestimento.png");
        }
        else if(key == KEY_F6){
            system("res\\pisos.png");
        }
        else if(key == 27){
            exit(1);
        }

    }while(1);

    return 1;

}

