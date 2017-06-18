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

//Move o cursor do terminal para a posição x,y indicada nos parâmetros
void mgotoxy(int x, int y)
{
      COORD p={x,y};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);//COLOCA O CURSOR NA COLUNA E LINHA INDICADA MAIS ABAIXO
}

int main(void){

    setlocale(LC_ALL, "");

    printf("AJUDA\n-----\nÍndice:\n");
    printf("1 - INCLINAÇÃO DO TELHADO\n");
    printf("2 - MADEIRAMENTO DO TELHADO\n");
    printf("3 - MODELOS DE TELHAS\n");
  	printf("4 - MODELOS DE TIJOLOS\n");
  	printf("5 - MODELOS DE REVESTIMENTO PARA PAREDE\n");
  	printf("6 - MODELOS DE PISO");

    printf("\n* Você pode usar as teclas numéricas para navegar pelos itens.\n\n\n");

    printf("1. INCLINAÇÃO DO TELHADO\n------------------------>\n");

    printf("* Pressione F1 para uma imagem ilustrativa.\n\n");

    printf(" A inclinação do telhado é calculada com base na largura da laje (dividida por dois no\ncaso de telhado com duas águas).O valor para a inclinação é fornecido em porcentagem (%%),\nessa porcentagem corresponde a porção da base que será espelhada para compor a cumeeira.\n");
    printf(" Por exemplo, um telhado com base (laje) 12x10m, com inclinação de 30%% e duas águas, temos:\n");
    printf("  a. Calculamos a metade da largura da base, nesse caso 6 (12/2 = 6);\n");
    printf("  b. Calculamos 30%% do valor achado anteriormente, ficando com 1.8m (6 * 0.3 = 1.8).\n     Essa seráa altura da cumeeira.\n\n");

    printf("\n2. MADEIRAMENTO DO TELHADO\n-------------------------->\n");

    printf("* Pressione F2 para uma imagem ilustrativa.\n\n");

    printf(" O madeiramento do telhado contempla toda a madeira usada para dar sustentação ao telhado:\n");
    printf(". Terça;\n. Pontalete;\n. Berço;\n. Mão Francesa;\n. Trama:\n  . Caibro;\n  . Ripas.\n\n");

    printf("\n3. MODELOS DE TELHAS\n-------------------->\n");

    printf("* Pressione F3 para uma imagem ilustrativa.\n\n");

    printf("\n TELHA PORTUGUESA\n----------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 17 peças por metro quadrado\n");
    printf("   Dimensões: 38x20");
    printf("   Peso: 2,6 Kg por peça\n");
    printf("   Inclinação Mínima: 35%%\n\n");

    printf("\n TELHA ROMANA\n------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 16 peças por metro quadrado\n");
    printf("   Dimensões: 40x21");
    printf("   Peso: 2,7 Kg por peça\n");
    printf("   Inclinação Mínima: 35%%\n\n");

    printf("\n TELHA AMERICANA\n---------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 12 peças por metro quadrado\n");
    printf("   Dimensões: 46x26cm");
    printf("   Peso: 2,9 Kg por peça\n");
    printf("   Inclinação Mínima: 30%%\n\n");

    printf("\n TELHA FRANCESA\n--------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 16 peças por metro quadrado\n");
    printf("   Dimensões: 38x24");
    printf("   Peso: 2,8 Kg por peça\n");
    printf("   Inclinação Mínima: 45%%\n\n");

    printf("\n TELHA ITALIANA\n--------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 13 peças por metro quadrado\n");
    printf("   Dimensões: 45x26");
    printf("   Peso: 3,4 Kg por peça\n");
    printf("   Inclinação Mínima: 30%%\n\n");

    printf("\n TELHA GERMÂNICA\n---------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 40 peças por metro quadrado\n");
    printf("   Dimensões:\n\tnormal 36x18,5cm\n\tcurta 24x18,5cm");
    printf("   Peso: 1,16 Kg por peça\n");
    printf("   Inclinação Mínima: 30%%\n\n");

    printf("\n TELHA HOLANDESA\n---------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 17 peças por metro quadrado\n");
    printf("   Dimensões: 41x24cm");
    printf("   Peso: 2,5 Kg por peça\n");
    printf("   Inclinação Mínima: 30%%\n\n");

    printf("\n TELHA URUGUAIA\n--------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 16 peças por metro quadrado\n");
    printf("   Dimensões: 28x19,5cm");
    printf("   Peso: 1 Kg por peça\n");
    printf("   Inclinação Mínima: 45%%\n\n");

    printf("\n TELHA PLAN\n----------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 26 peças por metro quadrado\n");
    printf("   Dimensões:\n\tcapa 48x16cm\n\tcanal: 48x19cm");
    printf("   Peso: 2,3 Kg por peça\n");
    printf("   Inclinação Mínima: 30%%\n\n");

    printf("\n TELHA PAULISTA\n--------------->\n");

    printf("   Material: Cerâmica\n");
    printf("   Quantidade: 22 peças por metro quadrado\n");
    printf("   Dimensões:\n\tcapa 48x17cm\n\tcanal: 48x20cm");
    printf("   Peso: 2,2 Kg por peça\n");
    printf("   Inclinação Mínima: 30%%\n");

    printf("\n\n4. MODELOS DE TIJOLOS\n--------------------->\n");

    printf("* Pressione F4 para uma imagem ilustrativa.\n\n");

    printf("\n BLOCO CERÂMICO\n--------------->\n");

  	printf("   Os blocos cerâmicos são feitas à base de argila cozida e são um itens mais utilizados na\nconstrução de paredes de alvenaria, podendo haver variações em relação ao número de furos e\ntamanho, sendo que os maiores são indicados para esturutras maiores.\n");
  	printf("   Os blocos furados são mais leves e baratos, porém, são mais vulneráveis a quebras durante\na obra.");
  	printf("   É importante destacar que este material não é estrutural, ou seja, pode ser utilizado\napenas para o fechamento e não para sustentação de cobertura ou laje.\n");

    printf("\n TIJOLOS MACIÇOS\n---------------->\n");

    printf("   Os tijolos maciços são feitos à base de argila cozida e são um dos itens mais utilizados\nna construção de paredes de alvenaria.\n");
  	printf("   Possuem mais resistência com relação aos blocos cerâmicos, podendo ser deixados aparentes\nou serem divididos ao meio para serem usados como revestimento para as paredes.\n");

    printf("\n TIJOLOS DE ADOBE\n----------------->\n");

    printf("   São basicamente uma mistura de terra e água, com acréscimo de palhas ou outros materiais\norgânicos, feitos através de processo artesanal ou semi-industrial de moldagem e secagem.\n");
  	printf("   É um tijolo ecológico, porque dispensa o cozimento que gasta muita energia e emite muitos\ngases, mas não é muito resistente a interpéries como chuva e vento, pois absorve muita água\ne pode se desfazer em contato direto e intenso com chuva.\n");

    printf("\n TIJOLOS LAMINADOS\n------------------>\n");

    printf("   Esta peça também é conhecida como tijolo de 21 furos devido à quantidade de orifícios que\napresenta.\n");
  	printf("   Este tipo de tijolo apresenta melhor aderência de argamassa, possibilitando uma estrutura\nmais firme e também tem alta durabilidade.\n");
  	printf("   Indica-se utilizar o modelo horizontalmente, para que apenas a parte lisa fique à mostra.\nÉ muito comum a utilização deste tipo de tijolo em projetos com tijolo aparente, como fachadas,\npor exemplo.\n");

    printf("\n TIJOLOS E BLOCOS DE CONCRETO\n----------------------------->\n");

    printf("   Apresenta uma estrutura mais robusta, sendo comumente utilizado em construções maiores e\ntambém em alicerces para casas.\n");
	printf("   A vantagem na utilização de tijolos ou blocos de concreto é com relação à economia no consumo\nde argamassa, pois sua anatomia facilita a junção das peças.\n");

  	printf("\n TIJOLOS ECOLÓGICOS\n------------------->\n");

    printf("   Produzido a partir de uma mistura de solo, cimento e água, é uma peça muito utilizada em\nconstruções sustentáveis devido a sua tendência ecológica.\n");
  	printf("   Suas vantagens são o baixo consumo de argamassa, isolamento térmico e acústico, fácil encaixe\ne possibilidade de ficar aparente.\n");
	printf("   Porém, é uma peça que necessita de um profissional especializado e também não é indicada para\nlocais muito úmidos.\n");

  	printf("\n\n5. MODELOS DE REVESTIMENTO PARA PAREDE\n-------------------------------------->\n");

    printf("* Pressione F5 para uma imagem ilustrativa.\n\n");

    printf("\n PAPEL DE PAREDE\n---------------->\n");

    printf("   Revestimento simples, facilmente encontrado e de fácil instalação.\n");
  	printf("   Este tipo de revestimento é indicado para regiões e ambientes menos úmidos, sendo assim,\né ideal evitar a utilização de papel de parede em banheiros e cozinhas.\n");

    printf("\n MADEIRA\n-------->\n");

    printf("   Este tipo de material possui uma grande variedade de cores e tonalidades e ajuda a\naquecer os cômodos, mantendo uma temperatura agradável no ambiente.\n");

    printf("\n PASTILHAS\n---------->\n");

    printf("   As pastilhas são pequenas peças que podem ser feitas de cerâmica, resina ou vidro e\nsão aplicadas às paredes como se fossem pequenos azulejos.\n");

	printf("\n LADRILHO HIDRÁULICO\n-------------------->\n");

    printf("   São azulejos que podem apresentar variações nos tamanhos, mas muito conhecidos por\nsuas estampas coloridas e bem detalhadas.\n");

  	printf("\n AZULEJO COMUM\n-------------->\n");

    printf("   São azuelejos que se apresentam no mesmo formato dos ladrilhos hidráulicos, um pouco\nmaiores às vezes, mas não possuem um diferencial em específico.\n");

    printf("\n\n6. TIPOS DE PISO\n---------------->\n");

    printf("* Pressione F6 para uma imagem ilustrativa.\n\n");

    printf("\n CERÂMICO\n--------->\n");

    printf("   A cerâmica é o tipo de piso mais conhecido e usado no Brasil. São encontradas de\nvários tamanhos (desde 20×30, 40×40, 60×60, 80×80, 100×100), texturas, qualidades e preços. Podem ser\nutilizadas em áreas internas e externas.\n");

    printf("\n PORCELANATO\n------------>\n");

    printf("   O Porcelanato é produzido em massa única já na sua coloração e com matérias-primas\nnobres.Podem ser semi-polidos, polidos e peça rústica. Também há os porcelanatos esmaltados e os\nporcelanatos digitais polidos com a mais alta qualidade e com várias texturas, principalmente imitando\nmadeiras, mármores e granitos.\n");

    printf("\n GRANITO\n-------->\n");

    printf("   O granito é uma pedra muito indicada para pisos devido a sua beleza, resistência\ne durabilidade. São utilizados desde residências até em locais com grande movimentação de pessoas\ncomo shoppings, supermercados, aeroportos, etc. Possuem várias tonalidades e quanto mais raro mais caro.\n");

    printf("\n MÁRMORE\n-------->\n");

    printf("   O mármore também é uma rocha metamórfica, composta principalmente por minerais\nde calcita com colaração mais uniforme e formação de veios definidos. É indicado para utilização em\nambientes internos apenas.\n");

    printf("\n LAMINADO DE MADEIRA\n-------------------->\n");

    printf("   Esse piso tem esse nome porque são constituídos de lâminas de madeira. É um tipo\nde piso flutuante porque não é colado no contrapiso. São assentados sobre manta, em sistema de encaixe\ntipo click e presos pelos rodapés que são colados.São sustentáveis por serem de madeira reflorestada.\n");

    printf("\n SILESTONE\n---------->\n");

    printf("   Silestone é um material composto por grande quantidade de quartzo, outros minerais\nem menor escala, resina de poliéster e pigmentos. Com porosidade nula, possui várias texturas e um\ncusto muito elevado.\n");

    printf("\n TÁBUA CORRIDA\n-------------->\n");

    printf("  Piso em madeira natural de lei, geralmente extraída da Amazônia. Conferem muita beleza\ne conforto, mas não são sustentáveis. Sua instalação é sobre um ripamento e possuem encaixe tipo\nmacho-fêmea.\n");

    printf("\n TACÃO\n------>\n");

    printf("   Os tacos foram sucesso nos anos 1960 a 1980. Atualmente são utilizados em ambientes mais\nespecíficos e possuem custo elevado. Assim como a tábua corrida, necessitam de raspar e\nsintecar. As madeiras mais comuns para tacão são a grápia, cumaru e ipê.\n");

    printf("\n LAJOTA\n------->\n");

    printf("   Instaladas tanto em paredes internas como em fachadas, as lajotas apresentam inúmeras\nvantagens, entre elas a ótima resistência às variações climáticas, a beleza e a relação\ncusto X benefício. As peças estão cada vez mais inovadoras, com formas geométricas variadas e com pinturas\nde desenhos que conferem um charme todo especial ao ambiente.\n");

    printf("\n ARDÓSIA\n-------->\n");

    printf("   Piso em pedra ardósia foi largamente utilizado nos anos 1980 devido a sua durabilidade e\nbaixo custo. Podem ser utilizadas em pisos internos de áreas molhadas e áreas externas.\n");

    printf("\n CIMENTO QUEIMADO\n----------------->\n");

    printf("   Solução de baixo custo para pisos e quando bem feita confere ótimo acabamento. Indicado\ntanto para áreas internas quanto para áreas externas. Muito utilizado em bares, boates e\ngalpões industriais.\n");

    printf("\n PEDRA PORTUGUESA\n----------------->\n");

    printf("   Muito utilizadas em calçadas a pedra portuguesa mais famosa do mundo é o calçadão de\nCopacabana no Rio de Janeiro. A execução do trabalho é bastante demorada porque cada pedra é\nassentada uma a uma.\n");

    printf("\n PEDRA SÃO TOMÉ\n--------------->\n");

    printf("  Com vários outros nomes pelo Brasil afora a Pedra São Tomé é o piso mais utilizado ao\nredor das piscinas. São vendidas em regulares 30x30cm e irregulares (retalhos).\n");

    printf("\n GRANITINA\n---------->\n");

    printf("  A granitina é uma massa de cimento misturada com pequenas pedrinhas de granito aplicadas\nno piso. Após a cura do piso é polida com discos diamantados que conferem uma superfície\nlisa e brilhante. O piso em granitina é muito utilizado em áreas internas e externas de clubes, escolas,\naeroportos.\n");


  	//Posiciona o cursor no início do texto
    mgotoxy(0,0);

  	char key;

  	//Linhas que contém os títulos numerados, para as quais o cursor irá "pular"
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

        //Obtém os valores das teclas do teclado numérico (0, ..., 9);
        //A tecla 0 tem o código 48, e a tecla 9 tem o código 57, sendo assim a diferença entre o código da tecla e 48, resulta no valor da tecla de 1 a 9
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

