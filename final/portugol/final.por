programa
{

	inclua biblioteca Tipos
	inclua biblioteca Matematica
	inclua biblioteca Texto
	inclua biblioteca Util
	inclua biblioteca Arquivos
	
	//Constante correspondente a taxa de perda que deve ser considerada ao calcular quantidades de materiais
	//a serem utilizados em uma obra.
	const real TAXA_DE_PERDA = 0.10
	
	//Constante que define o tamanho máximo de paredes e oitões que o usuário pode construir por vez.
	const inteiro QTDE_PAREDES = 100
	const inteiro QTDE_OITOES = 50  
	
	//Constantes correspondentes as chaves que serão salvas no arquivo
	//Telhas
	const cadeia C_TELHA_TIPO = "tipo_telha"
	const cadeia C_TELHA_QTDE = "qtde_telha"
	const cadeia C_TELHA_CUSTO_TOTAL = "custo_telha"
	const cadeia C_TELHA_PRECO_UNIT = "preco_unit_telha"
	
	//Telhado
	const cadeia C_TELHADO_INCLINACAO = "inclinacao"
	const cadeia C_TELHADO_LARGURA_BASE = "largura_base"
	const cadeia C_TELHADO_COMPRIMENTO_BASE = "comprimento_base"
	const cadeia C_TELHADO_AREA_CORRIGIDA = "area_corrigida_base"
	
	//Madeiramento
	const cadeia C_MADEIRA_QTDE_TERCA = "qtde_terca"
	const cadeia C_MADEIRA_QTDE_CAIBRO = "qtde_caibro"
	const cadeia C_MADEIRA_QTDE_RIPAS = "qtde_ripa"
	const cadeia C_MADEIRA_METROS_PONTALETES = "metros_pontalete"
	const cadeia C_MADEIRA_METROS_CAIBROS = "metros_caibro"
	const cadeia C_MADEIRA_METROS_RIPAS = "metros_ripas"
	const cadeia C_MADEIRA_METROS_TERCAS = "metros_tercas"
	const cadeia C_ESPACAMENTO_TERCAS = "espacamento_terca"
	const cadeia C_COMRPRIMENTO_GARGA = "comprimento_garga"
	
	//Tijolos
	const cadeia C_QTDE_PAREDES = "qtde_paredes"
	const cadeia C_TIJOLO_TIPO = "tipo_tijolo"
	const cadeia C_TIJOLO_QTDE = "qtde_total_tijolos"
	const cadeia C_TIJOLO_QTDE_METRO = "qtde_tijolos_por_metro_quadrado"
	const cadeia C_TIJOLO_CUSTO_TOTAL = "preco_total_tijolos"
	const cadeia C_TIJOLO_PRECO_UNIT = "preco_unitario_tijolo"
	
	//Revestimento das paredes
	const cadeia C_REVESTIMENTO_TIPO = "tipo_revestimento"
	const cadeia C_REVESTIMENTO_QTDE = "qtde_total_revestimento"
	const cadeia C_REVESTIMENTO_QTDE_METRO = "qtde_revestimento_por_metro_quadrado"
	const cadeia C_REVESTIMENTO_CUSTO_TOTAL = "preco_total_revestimento"
	const cadeia C_REVESTIMENTO_PRECO_UNIT = "preco_unitario_revestimento"
	const cadeia C_REVESTIMENTO_POR_PAREDE = "qtde_revestimento_por_parede"
	
	//Tinta
	const cadeia C_GALAO_TINTA_QTDE = "qtde_total_galoes_tinta"
	const cadeia C_GALAO_TINTA_CUSTO_TOTAL = "preco_total_galoes_tinta"
	const cadeia C_GALAO_TINTA_PRECO_UNIT = "preco_unitario_galao_tinta"
	
	//Estruturas
	const cadeia C_ESTRUT_PROFUNDIDAE_COLUNAS = "profundidade_colunas"
	const cadeia C_ESTRUT_DIAMETRO_COLUNAS = "diametro_colunas"
	const cadeia C_ESTRUT_PERIMETRO_TOTAL = "perimetro_total_paredes"
	const cadeia C_ESTRUT_LARGURA_BALDRAME = "largura_baldrames"
	const cadeia C_ESTRUT_PROFUNDIDADE_BALDRAME = "profundidade_baldrames"
	const cadeia C_ESTRUT_AREA_TOTAL_CONSTRUCAO = "area_total_construcao"
	const cadeia C_ESTRUT_QUANTIDADE_CIMENTO = "quantidade_cimento"
	const cadeia C_ESTRUT_ALTURA_PAREDES = "altura_paredes"
	const cadeia C_ESTRUT_QTDE_FERRO_3_8 = "qtde_ferro_3_8"
	const cadeia C_ESTRUT_QTDE_FERRO_3_16 = "qtde_ferro_3_16"
	const cadeia C_ESTRUT_QTDE_COLUNAS = "qtde_colunas"
	const cadeia C_ESTRUT_AREA_PISO = "area_piso"
	const cadeia C_ESTRUT_PISO = "piso"
	
	const cadeia C_AREA_PAREDES = "area_das_paredes"
	
	//Dados a serem gravados no arquivo
	//Telhado
	inteiro g_inclinacao = 0//Inclinação do telhado
	
	real g_largura_base = 0.0,//Largura da base do telhado (laje)
	      g_area_telhado_corrigida = 0.0,//Área do telhado corrigida já incluindo a inclinação do teclado
	      g_comprimento_base = 0.0//Comprimento da base do telhado (laje)
	
	//Telhas
	inteiro g_qtde_telhas = 0//Quantidade de telhas no total
	cadeia g_tipo_telha = ""
	
	real g_custo_total = 0.0,//Custo total das telhas no final
	    g_preco_unit = 0.0,//Preço unitário de cada telha
	    g_qtde_telha_metro = 0.0//Quantidade de telhas por metro quadrado
	
	//Madeiramento
	inteiro g_qtde_tercas = 0, //Quantidade de terças para as duas águas do telhado
	    g_qtde_caibros = 0,// Quantidade de caibros para o telhado
	    g_qtde_ripas = 0 //Quantidade de ripas para o telhado
	
	real g_tercas_espacamento = 0.0, //Espaçamento entre as terças
	    g_metragem_pontaletes = 0.0,
	    g_metragem_caibros = 0.0,
	    g_metragem_ripas = 0.0,
	    g_metragem_tercas = 0.0,
	    g_comprimento_garga = 0.0
	
	//Estruturas
	real g_profundidade_colunas = 0.0,
	      g_diametro_colunas = 0.0,
	      g_perimetro_total = 0.0,
	      g_larg_bald = 0.0,
	      g_prof_bald = 0.0,
	      g_area_total = 0.0,
	      g_qtde_cimento = 0.0,
	      g_area_piso = 0.0,
	      g_alt_paredes = 0.0
	
	inteiro  g_ferro[2] = {0,0}, //[1] 3/8  [0] 3/16
	     g_qtde_colunas = 0,
	     g_piso = 0
	
	cadeia g_pisoS = ""
	
	//Tijolos
	cadeia g_tipo_tijolo = ""
	
	inteiro g_qtde_paredes = 0,
	    g_qtde_total_tijolos = 0
	
	real g_qtde_tijolo_metro_quadrado = 0.0,
	    g_custo_total_tijolos = 0.0,
	    g_preco_unit_tijolo = 0.0
	
	//Revestimento das paredes
	cadeia g_tipo_revestimento = ""
	
	real g_qtde_total_revestimento = 0.0,
	    g_qtde_revestimento_metro_quadrado = 0.0,
	    g_qtde_revestimento_por_parede[QTDE_PAREDES],
	    g_custo_total_revestimento = 0.0,
	    g_preco_unit_revestimento = 0.0
	
	//Tinta
	real g_qtde_total_galoes_tinta = 0.0,
	    g_custo_total_galao_tinta = 0.0,
	    g_preco_unit_galao_tinta = 0.0
	
	//Gerais
	real g_areas_paredes[QTDE_PAREDES]
	
	/*
	*Função converte() = Evita que o usuário entre com um valor que irá alterar os calculos de uma estrutura real, por exemplo:
		- Usuário digita 21 (o programa entende como 21 metros), mas o calculo real precisa do valor em centímetros, entao a função verificaso o
	  valor dado precisa ser corrigido e o devolve com a correção feita, caso não necessite de correção, ela apenas retorna o valor para cálculo.
	*parametros: valor real
	*/
	funcao real converte(real num)
	{
	
		inteiro aux
		real verify
	
		aux=num
		se (aux == 0 e aux != num){
			verify = num //O numero digitado não é inteiro, e já está em "centímetros" - não fazer nada
		}
		senao se(aux > 0 e aux == num){
			verify = num/100 //O numero digitado não é inteiro e está em "Metros", por isso, deve-se dividir por 100 para se ter a base em cm
		}
		senao se(aux > 0 e aux != num){
			verify = num/100 //O numero digitado não é inteiro e está em "Metros", por isso, deve-se dividir por 100 para se ter a base em cm
		}
	
		retorne verify
	
	}
	
	/*
	*calcula a quantidade necessaria de cimento para a construção das estruturas da casa
	*
	*Parâmetros:
	*deep = profundidade das colunas subterrâneas
	*dm = diametro das colunas/subterrâneas e sobterrâneas, já que seguem as mesmas medidas
	*largura_baldrames = largura dos baldrames onde serão construidas as paredes
	*profundidade_baldrames = profundidade dos baldrames onde serão construidas as paredes
	*perimetro_total = soma de todas as paredes da casa em metros lineares
	*altura paredes = altura das paredes para base de calculo das colunas
	*g_qtde_colunas = quantidade de colunas da construção para calculo de cimento em m³
	*/
	funcao real calcula_cimento(real deep, real dm, real largura_baldrames, real profundidade_baldrames, real perimetro_total, real altura_paredes, inteiro qtde_colunas)
	{
	    real r, area_coluna_chao, area_coluna_parede, total, bald_total, tot_colunas
	
	    r = dm/2
	
	    area_coluna_chao = ( ( Matematica.PI * Matematica.potencia(r, 2.0) ) * deep ) //área das colunas subterrâneas
	
	    area_coluna_parede = ( ( Matematica.PI * Matematica.potencia(r, 2.0) ) * altura_paredes )//área das colunas que sobem acompanhando as paredes
	
	    tot_colunas = (area_coluna_chao + area_coluna_parede) * qtde_colunas//soma das colunas parede+chão
	
	    bald_total = largura_baldrames * profundidade_baldrames * perimetro_total * 2//área dos baldrames, multiplica - se por 2 pois existe o baldrame que sustenta a laje da casa, este possui praticamente a mesma área do que sustenta as paredes
	
	    total = bald_total + tot_colunas//soma de todas as áreas da estrutura
	
	    retorne total
	
	}
	
	/*
	*Calcula a quantidade de ferro 3/8 e 3/16 para a construção
	*parametros:
	*perimetro da casa
	*profundidade colunaaredes
	*qparedesunas
	*largura baldrame
	*profundidade baldrame
	*/
	funcao calcula_ferro(real perimetro, real profundidade, real altura, inteiro qtde_colunas, real largura_baldrame, real profundidade_baldrame)
	{
	
		inteiro qtde_ferro_estribo, qtde_ferro, total_ferro
		real larg_stribo, altura_stribo, espacamento = 0.0, tamanho_barra, tamanho_barra_amarra
	
		faca{
	
			escreva("Digite a largura do estribo: ")
			leia(larg_stribo)
	
			larg_stribo = converte(larg_stribo)//VERIFICA E CONVERTE
	
			//escreva("LARG STRIBO = ", larg_stribo, "\n")
	
			se(larg_stribo > largura_baldrame-0.07){
				escreva("\nA largura do estribo não pode ser maior que a do baldrame!\nDigite um valor até ", largura_baldrame-0.07, " metros\n")
			}
	
		}enquanto(larg_stribo > largura_baldrame-0.07)
	
		faca{
	
			escreva("Digite a altura do estribo: ")
			leia(altura_stribo)
	
			altura_stribo = converte(altura_stribo)//VERIFICA E CONVERTE
	
			//escreva("ALTURA = %.2f\n",altura_stribo)
	
			se(altura_stribo > profundidade_baldrame-0.04){
				escreva("\nA altura do estribo não pode ser maior que a do baldrame!\nDigite um valor até %.2f metros\n",profundidade_baldrame-0.04)
			}
	
		}enquanto(altura_stribo > profundidade_baldrame-0.04)
	
		escreva("Digite o tamanho unitário da barra de ferro escolhida para estrutura: ")
		leia(tamanho_barra)
	
	
		escreva("Digite o tamanho unitário da barra de ferro escolhida para amaração da estrutura: ")
		leia(tamanho_barra_amarra)
	
		faca{
	
			escreva("Digite o espaçamento entre as amarrações do estribo: ")
			leia(espacamento)
	
			espacamento = converte(espacamento)
	
			//escreva("ESPAÇAMENTO = %.2f\n", espacamento)
	
			se(espacamento > 0.201){
				escreva("O espaçamento não pode ser maior que 20 centímetros!!! Digite um valor menor.\n")
			}
	
		}enquanto(espacamento > 0.201)
	
	
		qtde_ferro_estribo = ( ( larg_stribo * 2 + altura_stribo * 2 ) * perimetro / espacamento ) / tamanho_barra_amarra //quantidade em barras de ferro para amarração do estribo
		qtde_ferro = ( ( perimetro * 2 + ( profundidade + altura ) * qtde_colunas) * 4 ) / tamanho_barra //retorna a quantidade de ferros para estruturas
	
		escreva("Estribo: ", qtde_ferro_estribo, " barras\n")
		escreva("Ferro: ", qtde_ferro, " barras\n")
	
		total_ferro = qtde_ferro_estribo + qtde_ferro
	
		g_ferro[0] = qtde_ferro_estribo
		g_ferro[1] = qtde_ferro
	
	}
	
	funcao inteiro escolhe_piso()
	{
	
		inteiro piso
	
		faca{
	
			escreva("\nEscolha o tipo de piso:\n1 - CERÂMICA\n2 - PORCELANATO\n3 - GRANITO\n4 - MÁRMORE\n5 - LAMINADO DE MADEIRA\n6 - SILESTONE\n7 - TÁBUA CORRIDA\n8 - TACÃO\n9 - LAJOTA\n10 - ARDÓSIA\n11 - CIMENTO QUEIMADO\n12 - PEDRA PORTUGUESA\n13 - PEDRA SãO TOMÉ\n14 - GRANITINA\n15 - OUTRO\n\nSua escolha: ")
			leia(piso)
	
			se(piso != 15){
				escolha(piso)
				{
					caso 1:
						g_pisoS = "CERÂMICA"
					pare
	
					caso 2:
						g_pisoS = "PORCELANATO"
					pare
	
					caso 3:
						g_pisoS = "GRANITO"
					pare
	
					caso 4:
						g_pisoS = "MÁRMORE"
					pare
	
					caso 5:
						g_pisoS = "LAMINADO DE MADEIRA"
					pare
	
					caso 6:
						g_pisoS = "SILESTONE"
					pare
	
					caso 7:
						g_pisoS = "TÁBUA CORRIDA"
					pare
	
					caso 8:
						g_pisoS = "TACÃO"
					pare
	
					caso 9:
						g_pisoS = "LAJOTA"
					pare
	
					caso 10:
						g_pisoS = "ARDÓSIA"
					pare
	
					caso 11:
						g_pisoS = "CIMENTO QUEIMADO"
					pare
	
					caso 12:
						g_pisoS = "PEDRA PORTUGUESA"
					pare
	
					caso 13:
						g_pisoS = "PEDRA SãO TOMÉ"
					pare
	
					caso 14:
						g_pisoS = "GRANITINA"
					pare
	
				}
			}
	
		}enquanto(piso > 15 ou piso < 0)
	
		retorne piso
	
	}
	
	/*
	*Função calcula gastos da estrutura/pisos
	*parametros:
	*area_casa: a ser construido
	*qt_piso: quantidade de piso em m²
	*qt_cimento: quantidade de cimento em m³
	*piso: tipo de piso definido na função anterior
	*/
	funcao gastos(real area_casa, real area_piso, real qt_cimento, inteiro piso)
	{
	
		real precopiso, precoferro, precoferro_316, precocimento, precolaje, VALORpiso, VALORferro, VALORferro_316, VALORcimento, VALORlaje, total
	
		faca{
			escreva("Digite o preço do m² do piso escolhido: ")
			leia(precopiso)
	
			se(precopiso <= 0){
				escreva("Valor inválido\n")
			}
	
		}enquanto(precopiso <= 0)
	
		faca{
			escreva("Digite o preço da barra de ferro 3/8 (unidade): ")
			leia(precoferro)
	
			se(precoferro <= 0){
				escreva("Valor inválido\n")
			}
	
		}enquanto(precoferro <= 0)
	
		faca{
			escreva("Digite o preço da barra de ferro 3/16 (unidade): ")
			leia(precoferro_316)
	
			se(precoferro_316 <= 0){
				escreva("Valor inválido\n")
			}
	
		}enquanto(precoferro_316 <= 0)
	
		faca{
			escreva("Digite o preco do m³ do cimento: ")
			leia(precocimento)
	
			se(precocimento <= 0){
				escreva("Valor inválido\n")
			}
	
		}enquanto(precocimento <= 0)
	
	
		faca{
			escreva("Digite o preço do m² da laje: ")
			leia(precolaje)
	
			se(precolaje <= 0){
				escreva("Valor inválido\n")
			}
	
		}enquanto(precolaje <= 0)
	
		escreva("\nGASTO APROXIMADO:\n")
	
		VALORpiso = precopiso * area_piso
		VALORferro = g_ferro[1] * precoferro
		VALORferro_316 = g_ferro[0] * precoferro_316
		VALORcimento = qt_cimento * precocimento
		VALORlaje = area_casa * precolaje
	
		escreva("Valor piso: ", VALORpiso, "\n")
		escreva("Valor ferro 3/8: ", VALORferro, "\n")
		escreva("Valor ferro 3/16: ", VALORferro_316, "\n")
		escreva("Valor cimento: ", VALORcimento, "\n")
		escreva("Valor laje: ", VALORlaje, "\n")
	
		total = VALORpiso + VALORferro + VALORferro_316 + VALORcimento + VALORlaje
	
		escolha(piso)
		{
			caso 1:
				escreva("Piso: CERAMICA")
			pare
	
			caso 2:
				escreva("Piso: PORCELANATO")
			pare
	
			caso 3:
				escreva("Piso: GRANITO")
			pare
	
			caso 4:
				escreva("Piso: MÁRMORE")
			pare
	
			caso 5:
				escreva("Piso: LAMINADO DE MADEIRA")
			pare
	
			caso 6:
				escreva("Piso: SILESTONE")
			pare
	
			caso 7:
				escreva("Piso: TÁBUA CORRIDA")
			pare
	
			caso 8:
				escreva("Piso: TACÃO")
			pare
	
			caso 9:
				escreva("Piso: LAJOTA")
			pare
	
			caso 10:
				escreva("Piso: ARDÓSIA")
			pare
	
			caso 11:
				escreva("Piso: CIMENTO QUEIMADO")
			pare
	
			caso 12:
				escreva("Piso: PEDRA PORTUGUESA")
			pare
	
			caso 13:
				escreva("Piso: PEDRA SãO TOMÉ")
			pare
	
			caso 14:
				escreva("Piso: GRANITINA")
			pare
	
		}
	
		escreva("\nGASTO TOTAL: ",total)
	
	}
	
	/*
	*Função calcula gastos da estrutura/pisos -> Esta função só sera utilizada caso o piso seja digitado como uma string...
	*parametros:
	*area_casa: a ser construido
	*area_piso: quantidade de piso em m²
	*qt_cimento: quantidade de cimento em m³
	*pisoS: tipo de piso definido na função anterior por STRING
	*/
	funcao gastos_cond_2(real area_casa, real area_piso, real qt_cimento, cadeia pisoS)
	{
	
		real precopiso, precoferro, precoferro_316, precocimento, precolaje, VALORpiso, VALORferro, VALORferro_316, VALORcimento, VALORlaje, total
	
	  	faca{
	        escreva("Digite o preço do m² do piso escolhido: ")
	        leia(precopiso)
	
	        se(precopiso <= 0){
	            escreva("Valor inválido\n")
	        }
	
	  	}enquanto(precopiso <= 0)
	
		faca{
			escreva("Digite o preço da barra de ferro 3/8 (unidade): ")
			leia(precoferro)
	
			se(precoferro <= 0){
				escreva("Valor inválido\n")
			}
	
		}enquanto(precoferro <= 0)
	
	  	faca{
	  		escreva("Digite o preço da barra de ferro 3/16 (unidade): ")
	        leia(precoferro_316)
	
	    	se(precoferro_316 <= 0){
	            escreva("Valor inválido\n")
	        }
	
	  	}enquanto(precoferro_316 <= 0)
	
	  	faca{
	  		escreva("Digite o preco do m³ do cimento: ")
	        leia(precocimento)
	
			se(precocimento <= 0){
				escreva("Valor inválido\n")
			}
	
	  	}enquanto(precocimento <= 0)
	
	
	  	faca{
	        escreva("Digite o preço do m² da laje: ")
	        leia(precolaje)
	
			se(precolaje <= 0){
				escreva("Valor inválido\n")
			}
	
	  	}enquanto(precolaje <= 0)
	
	    escreva("\nGASTO APROXIMADO:\n")
	
		VALORpiso = precopiso * area_piso
		VALORferro = g_ferro[1] * precoferro
		VALORferro_316 = g_ferro[0] * precoferro_316
		VALORcimento = qt_cimento * precocimento
		VALORlaje = area_casa * precolaje
	
		escreva("Valor piso: ", VALORpiso, "\n")
		escreva("Valor ferro 3/8: ", VALORferro, "\n")
		escreva("Valor ferro 3/16: ", VALORferro_316, "\n")
		escreva("Valor cimento: ", VALORcimento, "\n")
		escreva("Valor laje: ", VALORlaje, "\n")
	
		total = VALORpiso + VALORferro + VALORcimento + VALORlaje
	
		escreva("\nPISO: ", pisoS)
		escreva("\nGASTO TOTAL: ", total)
	
	}
	
	/*
	 * Calcula a área do telhado, onde ficarão as telhas, considerando a inclinação
	 *
	 * Parâmetros:
	 * inclinacao: Inclinação do telhado (altura da cumeeira)
	 * largura_base: largura da base do telhado (largura da laje)
	 * comprimento_base: comprimento da base do telhado (comprimento da laje)
	 *
	 * Retorna:
	 * A área do telhado
	 */
	funcao real corrigir_area(inteiro l_inclinacao, real l_largura_base, real l_comprimento_base)
	{
	
	  real altura_cumeeira = (l_inclinacao * (l_largura_base / 2) / 100)
	
	  real largura_corrigida = Matematica.raiz( Matematica.potencia( (l_largura_base / 2), 2.0 ) + Matematica.potencia( altura_cumeeira, 2.0 ), 2.0)
	
	  retorne (largura_corrigida * l_comprimento_base) * 2
	
	}
	
	/*
	 * Calcula quantidade de telhas baseado na área do telhado(corrigida) e a quantidade de telhas por m²
	 *
	 * Parâmetros:
	 * area_telhado: área do telhado
	 * telhas_metro_quad: quantidade de uma telha que ocupa 1 m²
	 *
	 * Retorna:
	 * A quantidade de telhas no total
	 */
	funcao inteiro calcula_qtde_telhas(real l_area_telhado, real l_telhas_metro_quad)
	{
	
	  inteiro qtde_telhas = 0
	
	  qtde_telhas = Matematica.arredondar(l_area_telhado * l_telhas_metro_quad, 0)
	  qtde_telhas += Matematica.arredondar(qtde_telhas * 0.05, 0)
	
	  retorne qtde_telhas
	
	}
	
	/*
	 * Calcula o preço das telhas
	 *
	 * Parâmetros:
	 * qtde: quantidade de telhas calculadas
	 * preco_unit: preço unitário da telha
	 *
	 * Retorna:
	 * O preço das telhas no total
	 */
	funcao real calcula_preco(inteiro l_qtde, real l_preco_unit)
	{
	
	  retorne l_qtde * l_preco_unit
	}
	
	/*
	 * Retorna a quantidade de telhas por metro quadrado de um modelo de telha
	 *
	 * Retorna:
	 * (real) quantidade de telha por metro quadrado do modelo de telha escolhido
	 */
	funcao real get_telhas_metro_quad()
	{
	    inteiro opt
	    real telhas_p_metro
	
	    faca
	    {
	
	        escreva("Escolha um método:\n 1 - Dimensões da telha\n 2 - Unidades por metro quadrado\n\nSua escolha: ")
	        leia(opt)
	
	        escolha(opt)
	        {
	
	            caso 1:
	
	                escreva("\nInforme as dimensões da telha\n")
	
	                real a_largura, a_comprimento, area_telha
	
	                //Para telhas de amianto ou alumínio as dimens?es podem variar, por isso o usuário é quem entra com essas dimens?es
	                escreva(" Digite a largura da telha (cm): ")
	                leia(a_largura)
	
	                escreva(" Digite a comprimento da telha (cm): ")
	                leia(a_comprimento)
	
	                //Calcula a área da telha
	                area_telha = (a_largura/100) * (a_comprimento/100)
	
	                telhas_p_metro = 1 / area_telha
	
	                pare
	
	            caso 2:
	
	                escreva("\nInforme a quantidade de telha por metro quadrado: ")
	                leia(telhas_p_metro)
	
	                pare
	
	            caso contrario:
	                escreva("\nOpção inválida\n\n")
	
	        }
	
	    }enquanto(opt > 2)
	
	    escreva("\nDigite o nome da telha: ")
	    leia(g_tipo_telha)
	
	    escreva("\n")
	
	    retorne telhas_p_metro
	
	}
	
	/*
	 * Calcula a quantidade total de gal?es de tinta necessários para pintar a área interna da construção
	 * com base nas áreas das paredes existentes na casa, na área total do teto, na quantidade de demãos
	 * que se deseja aplicar e no rendimento informado no galão de tinta escolhido pelo usuário.
	 *
	 * Parâmetros:
	 * (inteiro) qtde_paredes: quantidade total de paredes presente na construção.
	 * (real) area_tetos: área total do teto.
	 *
	 * Retorna:
	 * (inteiro) qtde_total_galoes: quantidade total de gal?es de tinta necessários para pintar a área interna da construção.
	 */
	funcao real calcula_qtde_total_galoes_tinta(real area_tetos) {
	    real qtde_total_galoes = 0.0,
	    rendimento_tinta = 0.0,
	    area_total = 0.0
	      
	    inteiro qtde_demaos = 0
	      
	    faca {
	        escreva("\nQuantidade de demãos que irá aplicar: ")
	        leia(qtde_demaos)
	    } enquanto (qtde_demaos <= 0)
	      
	    faca {
	        escreva("\nRendimento da tinta informado no galão: ")
	        leia(rendimento_tinta)
	    } enquanto (rendimento_tinta <= 0)
	      
	    para (inteiro i=0; i<g_qtde_paredes; i++) {
	      area_total += g_areas_paredes[i]
	    }
	  
	    area_total += area_tetos
	    
	    qtde_total_galoes = ((area_total * qtde_demaos) / rendimento_tinta)
	    
	    retorne qtde_total_galoes
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
	 * (inteiro) qtde_paredes: quantidade de paredes presentes na construção.
	 */
	funcao calcula_qtde_revestimento_por_parede() {
	
	    escreva("\n----- Quantidade de revestimento por parede (em unidades) -----")
	
	    para (inteiro i = 0; i < g_qtde_paredes; i++) {
	        inteiro parede = i+1
	        g_qtde_revestimento_por_parede[i] = Matematica.arredondar((g_qtde_revestimento_metro_quadrado * g_areas_paredes[i]), 0)
	        g_qtde_total_revestimento += g_qtde_revestimento_por_parede[i]
	        escreva("\n " + parede + "ª parede: " + g_qtde_revestimento_por_parede[i])
	    }
	}
	
	/*
	 * Calcula a quantidade de revestimento (em unidades) necessária para preencher uma área de um
	 * metro quadrado com base nas medidas do revestimento utilizado, sendo estas fornecidas pelo usuário.
	 *
	 * Retorna:
	 * (inteiro) qtde_revestimento_por_metro_quadrado: quantidade de revestimento (em unidades) necessárioa para
	 *       preencher uma área de um metro quadrado.
	 */
	funcao real calcula_qtde_revestimento_por_metro_quadrado() {
	    real qtde_revestimento_por_metro_quadrado = 0,
	    	 area_revestimento = 0,
	         altura_revestimento = 0,
	         comprimento_revestimento = 0
	
	    faca {
	        escreva("\nAltura do revestimento em metros: ")
	        leia(altura_revestimento)
	    } enquanto (altura_revestimento <= 0)
	
	    faca {
	        escreva("Comprimento do revestimento em metros: ")
	        leia(comprimento_revestimento)
	    } enquanto (comprimento_revestimento <=0 )
	
	    area_revestimento = altura_revestimento * comprimento_revestimento
	
	    qtde_revestimento_por_metro_quadrado = Matematica.arredondar(1/area_revestimento, 0)
	
	    retorne qtde_revestimento_por_metro_quadrado
	}
	
	/*
	 * Exibe opç?es de revestimento para que o usuário possa escolher o revestimento que
	 * deseja utilizar em sua obra.
	 *
	 * Retorna:
	 * (inteiro) tipo_revestimento: tipo de revestimento escolhido pelo usuário.
	 */
	funcao inteiro escolhe_tipo_revestimento() {
	    inteiro tipo_revestimento
	
	    escreva("\n--------------------\n")
	    escreva("Tipos de Revestimento\n")
	    escreva("--------------------\n")
	
	    faca {
	        escreva("\nSelecione o tipo do revestimento: \n\n")
	
	        escreva(" 1 - Papel de parede\n")
	        escreva(" 2 - Madeira\n")
	        escreva(" 3 - Pastilhas\n")
	        escreva(" 4 - Revestimento cimentício\n")
	        escreva(" 5 - Ladrilho hidráulico\n")
	        escreva(" 6 - Azulejo comum\n")
	        escreva(" 7 - Outra opção")
	
	        escreva("\n\nSua escolha: ")
	        leia(tipo_revestimento)
	    } enquanto (tipo_revestimento<1 ou tipo_revestimento>6)
	
	    retorne tipo_revestimento
	}
	
	/*
	 * Calcula a quantidade de tijolos necessários para construir cada oitão com base nas áreas dos
	 * oit?es e na quantidade de tiolos necessários para preencher uma área de um metro quadrado.
	 * Armaneza a quantidade de tijolos necessários por oitão em uma variável responsável por
	 * contabilizar a quantidade total de tijolos necessários para construir todas as paredes e oit?es
	 * da construção.
	 *
	 * Parâmetros:
	 * (inteiro) qtde_tijolos_por_oitão: vetor que armazena em cada posição a quantidade de tijolos necessária para construir um oitão.
	 * (inteiro) qtde_oitoes: quantidade total de oit?es presentes na construção.
	 * (inteiro) qtde_total_tijolos: variável que contabiliza a quantidade total de tijolos necessária para toda a construção.
	 * (real) areas_oit?es: vetor que armazena em casa posição a área de cada oitão individualmente.
	
	 */
	funcao calcula_qtde_tijolos_por_oitao(inteiro qtde_tijolos_por_oitao[], inteiro qtde_oitoes, inteiro &qtde_total_tijolos, real areas_oitoes[]) {
	
	    escreva("\n\n----- Quantidade de tijolos por oitão -----")
	
	    para (inteiro i=0; i < qtde_oitoes; i++) {
	    		inteiro oitao = i + 1
	        qtde_tijolos_por_oitao[i] = Matematica.arredondar(g_qtde_tijolo_metro_quadrado * areas_oitoes[i], 0)
	        qtde_total_tijolos += qtde_tijolos_por_oitao[i]
	        escreva("\n " + oitao + "º oitão: " + qtde_tijolos_por_oitao[i])
	    }
	}
	
	/*
	 * Calcula a quantidade de tijolos necessários para construir cada parede com base nas áreas das
	 * paredes e na quantidade de tiolos necessários para preencher uma área de um metro quadrado.
	 * Armaneza a quantidade de tijolos necessários por parede em uma variável responsável por
	 * contabilizar a quantidade total de tijolos necessários para construir todas as paredes e oit?es
	 * da construção.
	 *
	 * Parâmetros:
	 * (inteiro) qtde_tijolos_por_parede: vetor que armazena em cada posição a quantidade de tijolos necessária para construir uma parede.
	 * (inteiro) qtde_paredes: quantidade total de paredes presentes na construção.
	 * (inteiro) qtde_total_tijolos: variável que contabiliza a quantidade total de tijolos necessária para toda a construção.
	 */
	funcao calcula_qtde_tijolos_por_parede(real &qtde_tijolos_por_parede[]) {
	    inteiro i
	
	    escreva("\n----- Quantidade de tijolos por parede -----")
	
	    para (i=0; i<g_qtde_paredes; i++) {
	    	inteiro parede = i + 1
	        qtde_tijolos_por_parede[i] = Matematica.arredondar(g_qtde_tijolo_metro_quadrado * g_areas_paredes[i], 0)
	        g_qtde_total_tijolos += qtde_tijolos_por_parede[i]
	        escreva("\n " + parede + "ª parede: " + qtde_tijolos_por_parede[i])
	    }
	}
	
	/*
	 * Calcula a quantidade de tijolos necessários para preencher uma área de um metro quadrado
	 * com base nas medidas do tijolo utilizado, sendo estas fornecidas pelo usuário.
	 *
	 * Retorna:
	 * (inteiro) qtde_tijolos_por_metro_quadrado: quantidade de tijolos necessários para preencher
	 *       uma área de um metro quadrado.
	 */
	funcao real calcula_qtde_tijolos_por_metro_quadrado() {
	    real qtde_tijolos_por_metro_quadrado = 0.0,
	        area_tijolo = 0.0,
	        altura_tijolo = 0.0,
	        comprimento_tijolo = 0.0
	
	    faca {
	        escreva("\nAltura do tijolo em metros: ")
	        leia(altura_tijolo)
	    } enquanto (altura_tijolo <= 0)
	
	    faca {
	        escreva("Comprimento do tijolo em metros: ")
	        leia(comprimento_tijolo)
	    } enquanto (comprimento_tijolo <=0 )
	
	    area_tijolo = altura_tijolo * comprimento_tijolo
	
	    qtde_tijolos_por_metro_quadrado = Matematica.arredondar(1/area_tijolo, 0)
	
	    retorne qtde_tijolos_por_metro_quadrado
	}
	
	/*
	 * Calcula a área de um oitão presente na casa com base no tamanho de sua altura e base,
	 * sendo ambas as medidas fornecidas pelo usuário.
	 *
	 * Retorna:
	 * (real) area_oitao: área do oitão.
	 */
	funcao real calcula_area_oitao() {
	    real altura_oitao = 0.0,
	          base_oitao = 0.0,
	          area_oitao = 0.0
	
	    escreva("\nAltura do oitão em metros: ")
	    leia(altura_oitao)
	
	    escreva("Base do oitão em metros: ")
	    leia(base_oitao)
	
	    area_oitao = ((base_oitao * altura_oitao)/2)
	
	    retorne area_oitao
	}
	
	/*
	 * Calcula a área de uma parede, descontando a área das aberturas presentes nela,
	 * como portas e janelas.
	 *
	 * Parâmetros:
	 * (real) area_aberturas: área total das aberturas presentes na parede, como portas e janelas.
	 *
	 * Retorna:
	 * (real) area_parede: área da parede com a área das aberturas descontada.
	 */
	funcao real calcula_area_parede(real area_aberturas) {
	    real altura_parede = 0.0,
	          comprimento_parede = 0.0,
	          area_parede = 0.0
	
	    faca {
	        escreva("\nAltura da parede em metros: ")
	        leia(altura_parede)
	    } enquanto (altura_parede <= 0)
	
	    faca {
	        escreva("Comprimento da parede em metros: ")
	        leia(comprimento_parede)
	    } enquanto (comprimento_parede <= 0)
	
	    area_parede = ((altura_parede * comprimento_parede) - area_aberturas)
	
	    retorne area_parede
	}
	
	/*
	 * Calcula a área das aberturas presentes nas paredes, como portas e janelas, uma vez
	 * que estas devem ser descontadas posteriormente no cáculo da área das paredes que
	 * irão receber tijolos.
	 *
	 * Retorna:
	 * (real) area_aberturas: área total das aberturas presentes em uma parede, como portas e janelas.
	 */
	funcao real calcula_area_aberturas() {
	    inteiro qtde_aberturas = 0
	
	    real altura_abertura = 0.0,
	         comprimento_abertura = 0.0,
	         area_aberturas = 0.0
	
	    faca {
	        escreva("\nQuantas aberturas a parede apresenta? ")
	        leia(qtde_aberturas)
	    } enquanto (qtde_aberturas <= 0)
	
	    para (inteiro i=0; i<qtde_aberturas; i++) {
	    	inteiro abertura = i+1
	        faca {
	            escreva("\nAltura da " + abertura + "ª abertura em metros: ")
	            leia(altura_abertura)
	        } enquanto (altura_abertura <= 0)
	
	        faca {
	            escreva("Comprimento da " + abertura + "ª abertura em metros: ")
	            leia(comprimento_abertura)
	        } enquanto (comprimento_abertura <= 0)
	
	        area_aberturas += (altura_abertura * comprimento_abertura)
	    }
	
	    retorne area_aberturas
	}
	
	/*
	 * Exibe opç?es de tijolos para que o usuário possa escolher o tijolo que
	 * deseja utilizar em sua obra.
	 *
	 * Retorna:
	 * (inteiro) tipo_tijolo: tipo de tijolo escolhido pelo usuário.
	 */
	funcao inteiro escolhe_tipo_tijolo() {
	    inteiro tipo_tijolo
	
	    escreva("\n--------------------\n")
	    escreva("Tipos de Tijolo\n")
	    escreva("--------------------\n")
	
	    faca {
	        escreva("\nSelecione o tipo do tijolo: \n\n")
	
	        escreva(" 1 - Blocos Cerâmicos\n")
	        escreva(" 2 - Tijolos Maciços\n")
	        escreva(" 3 - Tijolos de Adobe\n")
	        escreva(" 4 - Tijolos Laminados\n")
	        escreva(" 5 - Tijolos e Blocos de Concreto\n")
	        escreva(" 6 - Tijolos Ecológicos\n")
	
	
	        escreva("\n\nSua escolha: ")
	        leia(tipo_tijolo)
	    } enquanto (tipo_tijolo<1 ou tipo_tijolo>4)
	
	    retorne tipo_tijolo
	}
	
	/* Conta quantas ocorrencias um determinado caracter tem em uma determinada string
	 *
	 * Parâmetros:
	 * (cadeia) str: string onde o caracter será contado
	 * (inteiro) str_length: tamanho da string
	 * (caracter) ch: caracter que será contado
	 *
	 * Retorno:
	 * (inteiro) quantidade de caracteres ch na string str
	 */
	funcao inteiro count_char(cadeia str, inteiro str_length, caracter ch)
	{
	    inteiro i, count = 0
	
	    para(i = 0; i < str_length; i++){
	        se(Texto.obter_caracter(str, i) == ch){
	            count++
	        }
	    }
	
	    retorne count
	}

	/* Transforma uma string em um vetor de inteiros. Divide a string nos pontos demarcados por um determinado caracter e coloca em um vetor inteiro
	 *
	 * Parâmetros:
	 * (cadeia) string: string que será dividida
	 * (inteiro) vetor_destino: vetor que receberá os valores da string
	 * (caracter) delimiter: caracter que indica o ponto de divisão
	 */
	funcao split_string_int(cadeia string, inteiro &vetor_destino[], caracter delimiter)
	{
	
	    inteiro last_occurence = 0,
	        array_index_counter = 0,
	        length = Texto.numero_caracteres(string)
	
	    para(inteiro i = 0; i < length; i++){
	        se(Texto.obter_caracter(string, i) == delimiter ou i == length - 1){
	
	            se(i == length - 1)
	                i++
	
	            vetor_destino[array_index_counter] = Tipos.cadeia_para_inteiro( Texto.extrair_subtexto(string, last_occurence, i), 10)
	
	            last_occurence = i + 1
	            array_index_counter++
	        }
	    }
	
	}
	
	/* Transforma uma string em um vetor de reais. Divide a string nos pontos demarcados por um determinado caracter e coloca em um vetor real
	 *
	 * Parâmetros:
	 * (cadeia) string: string que será dividida
	 * (real) vetor_destino: vetor que receberá os valores da string
	 * (caracter) delimiter: caracter que indica o ponto de divisão
	 */
	funcao split_string_float(cadeia string, real &vetor_destino[], caracter delimiter)
	{
	    inteiro last_occurence = 0,
	        array_index_counter = 0,
	        length = Texto.numero_caracteres(string)
	
	    para(inteiro i = 0; i < length; i++){
	        se(Texto.obter_caracter(string, i) == delimiter ou i == length - 1){
	
	            se(i == length - 1)
	                i++
	
	            vetor_destino[array_index_counter] = Tipos.cadeia_para_real( Texto.extrair_subtexto(string, last_occurence, i) )
	
	            last_occurence = i + 1
	            array_index_counter++
	        }
	    }
	}
	
	/* Unifica um vetor de reais em uma string, cada elemento sendo separado por um padrão especificado
	 *
	 * Parâmetros:
	 * (real) array: vetor que será unificado
	 * (inteiro) array_length: tamanho do vetor que será unificado
	 * (cadeia) separator: padrão que irá separar os elementos na string
	 *
	 * Retorna:
	 * (cadeia) string: string contendo o conteúdo já unificado do vetor
	 */
	funcao cadeia split_float_array(real array[], inteiro array_length, cadeia separator) 
	{
	    cadeia string = ""
	
	    para(inteiro i = 0; i < array_length; i++){
	        cadeia num = Tipos.real_para_cadeia(array[i])
	
	        string += num
	
	        se(i != array_length - 1){
	            string += separator
	        }
	    }
	
	    retorne string
	
	}
	
	/*
	 * Escreve um registro no arquivo ou atualiza esse registro se ele já existir
	 * 
	 * Parâmetros:
	 * (cadeia) dir: diretório  do arquivo que será lido
	 * (cadeia) chave: identificador do registro a ser inserido
	 * (cadeia) valor: valor do registro a ser inserido
	 * 
	 * Retorna:
	 * (inteiro) 0: erro
	 * (inteiro) 1: criou o arquivo (logo só existe um registro)
	 * (inteiro) 2: atualizou o registro ou o arquivo já existe e o registro foi inserido
	 */
	funcao inteiro grava_registro(cadeia dir, cadeia chave, cadeia valor){

		se(Arquivos.arquivo_existe(dir)){

			inteiro arquivo = Arquivos.abrir_arquivo(dir, Arquivos.MODO_LEITURA)
			cadeia conteudo_arquivo = ""
			logico atualizou = falso
			inteiro ac_linhas = 0
			
			faca{
				
				cadeia linha = Arquivos.ler_linha(arquivo)

				se(linha != ""){
					
					cadeia chave_lida = Texto.extrair_subtexto(linha, 0, Texto.posicao_texto(";", linha, 0) )
					
					se(chave_lida == chave){
						
						conteudo_arquivo += chave + ";" + valor + "&"
						atualizou = verdadeiro
						
					}
					senao{
						
						conteudo_arquivo += linha + "&"
						
					}

					ac_linhas++
					
				}
				
			}enquanto(nao Arquivos.fim_arquivo(arquivo))

			se(nao atualizou){ 
				
				conteudo_arquivo += chave + ";" + valor + "&"
				ac_linhas++
				
			}

			Arquivos.fechar_arquivo(arquivo)

			arquivo = Arquivos.abrir_arquivo(dir, Arquivos.MODO_ESCRITA)

			inteiro ultima_pos = 0
			para(inteiro i = 0; i < ac_linhas; i++){
				
				inteiro fim = Texto.posicao_texto("&", conteudo_arquivo, ultima_pos)
				
				cadeia linha = Texto.extrair_subtexto(conteudo_arquivo, ultima_pos, fim)
				
				Arquivos.escrever_linha(linha + "\n", arquivo)

				ultima_pos = fim + 1
				
			}
		
			Arquivos.fechar_arquivo(arquivo)
			
			retorne 2
			
		}
		senao{
			
			inteiro arquivo = Arquivos.abrir_arquivo(dir, Arquivos.MODO_ESCRITA)

			Arquivos.escrever_linha(chave + ";" + valor + "\n", arquivo)

			Arquivos.fechar_arquivo(arquivo)

			retorne 1
		}

		retorne 0
		
	}

	/* Lê um registro do arquivo
	 * 
	 * Parâmetros:
	 * (cadeia) dir: diretório  do arquivo que será lido
	 * (cadeia) chave: identificador do registro buscado
	 * 
	 * Retorna:
	 * (cadeia): valor do registro, ou nulo caso o registro ou arquivo não existe
	 */
	funcao cadeia ler_registro(cadeia dir, cadeia chave){
	
		se(Arquivos.arquivo_existe(dir)){
			
			inteiro arquivo = Arquivos.abrir_arquivo(dir, Arquivos.MODO_LEITURA)

			enquanto(nao Arquivos.fim_arquivo(arquivo)){

				cadeia linha = Arquivos.ler_linha(arquivo)

				se(linha != ""){

					//Extrai a chave da linha lida a partir da posição do espaço divisor da chave e valor
					cadeia chave_lida = Texto.extrair_subtexto(linha, 0, Texto.posicao_texto(";", linha, 0) )
					
					se(chave_lida == chave){

						Arquivos.fechar_arquivo(arquivo)
						//Extrai o valor da chave da linha lida, a partir da posição do espaço que divide a chave e o valor
						retorne Texto.extrair_subtexto(linha, Texto.posicao_texto(";", linha, 0) + 1,  Texto.numero_caracteres(linha))
						
					}
					
				}
				
			}
			
		}

		retorne ""

	}
		

	// Salva os registros em um arquivo .csv
	funcao salvar_dados()
	{
	
		cadeia diretorio = "", valor = "", nome_arq = ""
		inteiro erro = 0, status = 0, usr_opt = 0
	
		escreva("\nDigite o diretório para salvar o arquivo: ")
		leia(diretorio)
	
		escreva("Escolher um nome para o arquivo?\n 1 - Sim\n 2 - Não, usar um nome genérico\n\nSua escolha: ")
		leia(usr_opt)
	
		se(usr_opt == 1){
			escreva("Digite o nome do arquivo: ")
			leia(nome_arq)
	
		}
		senao{
			//gera o nome do arquivo com um numero aleatorio
			nome_arq = "orc" + Tipos.inteiro_para_cadeia( Util.sorteia(0, 2000000), 10)
		}
	
		se( Texto.obter_caracter(diretorio, Texto.numero_caracteres(diretorio) - 1 ) == '\\'){
	        diretorio += nome_arq + ".csv"
		}
		senao{
			diretorio += "\\" + nome_arq + ".csv"
		}
	
		faca{
	
			usr_opt = 0
	
			escreva("\nSalvando...")
	
			//Telhas
	            status = grava_registro(diretorio, C_TELHA_TIPO, g_tipo_telha)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.inteiro_para_cadeia(g_qtde_telhas, 10)
				status = grava_registro(diretorio, C_TELHA_QTDE, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_custo_total, 2) )
				status = grava_registro(diretorio, C_TELHA_CUSTO_TOTAL, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_preco_unit, 2) )
				status = grava_registro(diretorio, C_TELHA_PRECO_UNIT, valor)
	
				se(status == 0){
					erro++
				}
			//Fim Telhas
	
			//Telhado
				valor = Tipos.inteiro_para_cadeia(g_inclinacao, 10)
				status = grava_registro(diretorio, C_TELHADO_INCLINACAO, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_largura_base, 2))
				status = grava_registro(diretorio, C_TELHADO_LARGURA_BASE, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_comprimento_base, 2))
				status = grava_registro(diretorio, C_TELHADO_COMPRIMENTO_BASE, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_area_telhado_corrigida, 2))
				status = grava_registro(diretorio, C_TELHADO_AREA_CORRIGIDA, valor)
	
				se(status == 0){
					erro++
				}
			//Fim Telhado
	
			//Madeiramento
				valor = Tipos.inteiro_para_cadeia(g_qtde_tercas, 10)
				status = grava_registro(diretorio, C_MADEIRA_QTDE_TERCA, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.inteiro_para_cadeia(g_qtde_caibros, 10)
				status = grava_registro(diretorio, C_MADEIRA_QTDE_CAIBRO, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.inteiro_para_cadeia(g_qtde_ripas, 10)
				status = grava_registro(diretorio, C_MADEIRA_QTDE_RIPAS, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_metragem_pontaletes, 2))
				status = grava_registro(diretorio, C_MADEIRA_METROS_PONTALETES, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_metragem_caibros, 2))
				status = grava_registro(diretorio, C_MADEIRA_METROS_CAIBROS, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_metragem_ripas, 2))
				status = grava_registro(diretorio, C_MADEIRA_METROS_RIPAS, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_metragem_tercas, 2))
				status = grava_registro(diretorio, C_MADEIRA_METROS_TERCAS, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_tercas_espacamento, 2))
				status = grava_registro(diretorio, C_ESPACAMENTO_TERCAS, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_comprimento_garga, 2))
				status = grava_registro(diretorio, C_COMRPRIMENTO_GARGA, valor)
	
				se(status == 0){
					erro++
				}
			//Fim Madeiramento
	
			//Tijolos
				status = grava_registro(diretorio, C_TIJOLO_TIPO, g_tipo_tijolo)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.inteiro_para_cadeia(g_qtde_paredes, 10)
				status = grava_registro(diretorio, C_QTDE_PAREDES, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.inteiro_para_cadeia(g_qtde_total_tijolos, 10)
				status = grava_registro(diretorio, C_TIJOLO_QTDE, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_qtde_tijolo_metro_quadrado, 2))
				status = grava_registro(diretorio, C_TIJOLO_QTDE_METRO, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_custo_total_tijolos, 2))
				status = grava_registro(diretorio, C_TIJOLO_CUSTO_TOTAL, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_preco_unit_tijolo, 2))
				status = grava_registro(diretorio, C_TIJOLO_PRECO_UNIT, valor)
	
				se(status == 0){
					erro++
				}
			//Fim Tijolos
	
			//Revestimento
				status = grava_registro(diretorio, C_REVESTIMENTO_TIPO, g_tipo_revestimento)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_qtde_total_revestimento, 2))
				status = grava_registro(diretorio, C_REVESTIMENTO_QTDE, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_qtde_revestimento_metro_quadrado, 2))
				status = grava_registro(diretorio, C_REVESTIMENTO_QTDE_METRO, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_custo_total_revestimento, 2))
				status = grava_registro(diretorio, C_REVESTIMENTO_CUSTO_TOTAL, valor)
	
				se(status == 0){
					erro++
				}
		
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_preco_unit_revestimento, 2))
				status = grava_registro(diretorio, C_REVESTIMENTO_PRECO_UNIT, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = split_float_array(g_qtde_revestimento_por_parede, g_qtde_paredes, "#")
				status = grava_registro(diretorio, C_REVESTIMENTO_POR_PAREDE, valor)
	
				se(status == 0){
					erro++
				}
			//Fim Revestimento
	
			//Tinta
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_qtde_total_galoes_tinta, 2))
				status = grava_registro(diretorio, C_GALAO_TINTA_QTDE, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_custo_total_galao_tinta, 2))
				status = grava_registro(diretorio, C_GALAO_TINTA_CUSTO_TOTAL, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_preco_unit_galao_tinta, 2))
				status = grava_registro(diretorio, C_GALAO_TINTA_PRECO_UNIT, valor)
	
				se(status == 0){
					erro++
				}
			//Fim Tinta
	
			//Estruturas
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_profundidade_colunas, 2))
				status = grava_registro(diretorio, C_ESTRUT_PROFUNDIDAE_COLUNAS, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_diametro_colunas, 2))
				status = grava_registro(diretorio, C_ESTRUT_DIAMETRO_COLUNAS, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_perimetro_total , 2))
				status = grava_registro(diretorio, C_ESTRUT_PERIMETRO_TOTAL, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_larg_bald, 2))
				status = grava_registro(diretorio, C_ESTRUT_LARGURA_BALDRAME, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_prof_bald, 2))
				status = grava_registro(diretorio, C_ESTRUT_PROFUNDIDADE_BALDRAME, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_area_total, 2))
				status = grava_registro(diretorio, C_ESTRUT_AREA_TOTAL_CONSTRUCAO, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_qtde_cimento, 2))
				status = grava_registro(diretorio, C_ESTRUT_QUANTIDADE_CIMENTO, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_alt_paredes, 2))
				status = grava_registro(diretorio, C_ESTRUT_ALTURA_PAREDES, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.inteiro_para_cadeia(g_ferro[0], 10)
				status = grava_registro(diretorio, C_ESTRUT_QTDE_FERRO_3_16, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.inteiro_para_cadeia(g_ferro[1], 10)
				status = grava_registro(diretorio, C_ESTRUT_QTDE_FERRO_3_8, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.inteiro_para_cadeia(g_qtde_colunas, 10)
				status = grava_registro(diretorio, C_ESTRUT_QTDE_COLUNAS, valor)
	
				se(status == 0){
					erro++
				}
	
				valor = Tipos.real_para_cadeia( Matematica.arredondar(g_area_piso, 2))
				status = grava_registro(diretorio, C_ESTRUT_AREA_PISO, valor)
	
				se(status == 0){
					erro++
				}
	
				status = grava_registro(diretorio, C_ESTRUT_PISO, g_pisoS)
	
				se(status == 0){
					erro++
				}
			//Fim Estruturas
	
			valor = split_float_array(g_areas_paredes, g_qtde_paredes, "#")
			status = grava_registro(diretorio, C_AREA_PAREDES, valor)
	
			se(status == 0){
				erro++
			}
	
			se(erro > 0){
				escreva("\nOcorreram ", erro, " erros ao salvar o arquivo. Deseja tentar novamente?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
		        leia(usr_opt)
			}
	
		}enquanto(usr_opt == 1)
	
	}

	
	//Segue a rotina de criar um novo orçamento
	funcao novo_orcamento()
	{
	
	    //Geral
	    inteiro usr_opt = 0 //Usada para receber as escolhas do usuário quando forem apresentadas opç?es
	    
	    logico chave_mestra = falso // chave de decisão para escolha de tipo de função a ser passada
	
	    caracter usr_rsp //Armazena a resposa do usuário quando este deve responder com 'S - Sim' ou 'N - Não'
	
	    //ESTRUTURAS
	    //ALGORITMO PARA CALCULO DE ESTRUTURAS DA CONSTRUCAO CIVIL BASEADO NO SOLO
	    faca{
	
	        escreva("--------------------\nCIMENTO PARA ESTRUTURAS\n--------------------\n")
	
	        faca{
	
	            escreva("Digite a área de construção (em metros): ")
	            leia(g_area_total)
	
	            se(g_area_total <= 0){
	                escreva("Valor inválido.\n")
	            }
	
	        }enquanto(g_area_total <= 0)
	
	        faca{
	
	            escreva("Digite a profundidade das colunas de acordo com o estudo de solo (em metros): ")
	            leia(g_profundidade_colunas)
	
	            se(g_profundidade_colunas <= 0){
	                escreva("Valor inválido.\n")
	            }
	
	        }enquanto(g_profundidade_colunas <= 0)
	
	        faca{
	
	            escreva("Digite o diâmetro das colunas(em centímetros): ")
	            leia(g_diametro_colunas)
	
	            se(g_diametro_colunas <= 0){
	                escreva("Valor inválido.\n")
	            }
	
	        }enquanto(g_diametro_colunas <= 0)
	
	        g_diametro_colunas = converte(g_diametro_colunas) //Função converte virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usuário cometa algum erro de unidade de medida
	
	        //escreva("g_diametro_colunas = %.2f\n", g_diametro_colunas) - printfs apenas para verificar a veracidade dos dados...
	
	        faca{
	
	            escreva("Digite a largura dos baldrames (em centímetros): ")
	            leia(g_larg_bald)
	
	            se(g_larg_bald <= 0){
	                escreva("Valor inválido.\n")
	            }
	
	        }enquanto(g_larg_bald <= 0)
	
	         g_larg_bald = converte(g_larg_bald) //Função converte virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usuário cometa algum erro de unidade de medida
	
	         //escreva("LARGURA = %.2f\n", g_larg_bald)
	
	        faca{
	
	            escreva("Digite a profundidade dos baldrames (em centímetros): ")
	            leia(g_prof_bald)
	
	            se(g_prof_bald <= 0){
	                escreva("Valor inválido.\n")
	            }
	
	        }enquanto(g_prof_bald <= 0)
	
	        g_prof_bald = converte(g_prof_bald)//Função converte virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usuário cometa algum erro de unidade de medida
	
	        //escreva("g_profundidade_colunas = %.2f\n", g_prof_bald)
	
	        faca{
	
	            escreva("Entre com perimetro de todas as paredes da casa (em metros): ")
	            leia(g_perimetro_total)
	
	            se(g_perimetro_total <= 0){
	                escreva("Valor inválido.\n")
	            }
	
	        }enquanto(g_perimetro_total <= 0)
	
	        faca{
	
	            escreva("Altura das paredes: ")
	            leia(g_alt_paredes)
	
	            se(g_alt_paredes <= 0){
	                escreva("Valor inválido.\n")
	            }
	
	        }enquanto(g_alt_paredes <= 0)
	
	
	        g_qtde_colunas = g_perimetro_total/3
	
	        g_qtde_cimento = calcula_cimento(g_profundidade_colunas, g_diametro_colunas, g_larg_bald, g_prof_bald, g_perimetro_total, g_alt_paredes, g_qtde_colunas)//calcula e armazena o valor retornado das áreas de estruturas (CALCULO CIMENTO)
	
	        escreva("\n------\n")
	        escreva("Concluído.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular este orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
	        leia(usr_opt)
	
	  	} enquanto (usr_opt == 1)
	
	    faca{
	
	        escreva("\n--------------------\nORÇAMENTO DAS FERRAGENS\n--------------------\n")
	
	        calcula_ferro(g_perimetro_total, g_profundidade_colunas, g_alt_paredes, g_qtde_colunas, g_larg_bald, g_prof_bald)//função calcula a quantidade necessária de ferro 3/8 e 3/16, armazenando os dados num vetor global.
	
	        escreva("\n------\n")
	        escreva("Concluído.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular este orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
	        leia(usr_opt)
	
	  	} enquanto (usr_opt == 1)
	
	  	faca{
	
	        faca{
	
	            escreva("\nDigite a área que deseja colocar pisos: ")
	            leia(g_area_piso)
	
	            se(g_area_piso >= g_area_total){
	                escreva("A área do piso não pode ser maior do que a área total!!\n")
	            }
	
	        }enquanto(g_area_piso >= g_area_total)
	
	        // escreva("Quantidade mínima de colunas: %d\n", g_qtde_colunas)
	        // escreva("total: %.2f m³ de cimento",g_qtde_cimento)
	
	        g_piso = escolhe_piso()
	
	        se(g_piso == 15){
	
	            escreva("\nDigite o piso escolhido: ")
	            leia(g_pisoS)
	
	            gastos_cond_2(g_area_total, g_area_piso, g_qtde_cimento, g_pisoS)
	
	            chave_mestra = verdadeiro
	        }
	
	
	        se(chave_mestra == falso){
	
	            gastos(g_area_total, g_area_piso, g_qtde_cimento, g_piso)
	
	        }
	
	        escreva("\n------\n")
	        escreva("Concluído.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular este orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
	        leia(usr_opt)
	
	  	} enquanto (usr_opt == 1)
	
	    faca
	    {
	
	    	escreva("\n--------------------\nORÇAMENTO DO TELHADO\n--------------------\n")
	
	        escreva("\nBASE DO TELHADO")
	        faca
	        {
	            escreva("\n------\n\n")
	            //Lê a largura e comprimento da base do telhado (laje)
	            escreva(" Digite a largura da base do telhado(m): ")
	            leia(g_largura_base)
	
	            escreva(" Digite o comprimento da base do telhado(m): ")
	            leia(g_comprimento_base)
	
	            se(g_largura_base <= 0 ou g_comprimento_base <= 0)
	            {
	                escreva("\nA largura e comprimento da base devem ser ambos maiores que zero.\n")
	            }
	
	        }enquanto(g_largura_base <= 0 ou g_comprimento_base <= 0)
	
	        faca
	        {
	            //Lê a inclinação desejada para o telhado em porcentagem.
	            //Com essa inclinação será calculada a altura do centro do telhado (cumeerira, onde os "lados" do telhado se dividem (/|\)).
	            //Essa porcentagem é calculada em cima da metade da largura da laje.
	            escreva(" Informe a inclinação desejada (deve ser maior que 30%): ")
	            leia(g_inclinacao)
	
	            //Inclinação abaixo de 30% não é normatizada
	            se(g_inclinacao < 30)
	            {
	                escreva("\nInclinação inválida. Deve ser maior que 30%.")
	            }
	
	        }enquanto(g_inclinacao < 30)
	
	        //Calcula a área do telhado considerando a inclinação
	        g_area_telhado_corrigida = corrigir_area(g_inclinacao, g_largura_base, g_comprimento_base)
	
	        //Exibe a área da laje e a inclinação calculados
	        escreva("\nÁrea calculada: ", g_largura_base * g_comprimento_base)
	        escreva("\nInclinação: ", g_inclinacao)
	        escreva("\nÁrea do telhado corrigida, considerando a inclinação: ", g_area_telhado_corrigida)
	
	        escreva("\n\nTELHAS")
	        escreva("\n------\n\n")
	
	        g_qtde_telha_metro = get_telhas_metro_quad()
	
	        //Calcula a quantidade de telha
	        g_qtde_telhas = calcula_qtde_telhas(g_area_telhado_corrigida, g_qtde_telha_metro)
	
	        escreva("Quantidade aproximada de telhas: ", g_qtde_telhas, "\n")
	
	        faca
	        {
	
	            escreva("\nInforme o preco unitário das telhas: ")
	            leia(g_preco_unit)
	
	            se(g_preco_unit <= 0.0)
	            {
	                escreva("\nO preço unitário deve ser maior que zero.\n\n")
	            }
	
	        }enquanto(g_preco_unit <= 0.0)
	
	        //Calcula o preço final das telhas
	        g_custo_total = calcula_preco(g_qtde_telhas, g_preco_unit)
	
	        escreva("Custo total das telhas: R$ ", g_custo_total)
	
	        escreva("\n\nMADEIRAMENTO")
	        escreva("\n------\n\n")
	
	        //Calcula a quantidade de terças
	        escreva("Terças:\n Digite o espaçamento das terças (m): ")
	        leia(g_tercas_espacamento)
	
	        g_qtde_tercas = Matematica.arredondar(g_largura_base / g_tercas_espacamento, 0)
	        g_metragem_tercas = g_comprimento_base * g_qtde_tercas
	
	        escreva(" Quantidade de terças de ", g_comprimento_base, " metros: ", g_qtde_tercas, "\n")
	        escreva(" Quantidade de metros de terças: ", g_metragem_tercas)
	
	        //Calcula a quantidade de pontaletes
	        escreva("\n\nPontaletes:\n")
	
	        g_metragem_pontaletes = (
		        ( ( (g_largura_base / 2) * g_inclinacao ) / 100 ) * 2 +
		        ( ( ( (g_largura_base / 2) / 2 ) * g_inclinacao ) / 100 ) * 6 // 3 pontaletes em cada água
		    )
	
	        escreva(" Quantidade de metros de pontaletes: ", g_metragem_pontaletes)
	
	        //Calcula a quantidade de berços
	        //Para cada pontalete há 1 berço de 0.5m
	        escreva("\n\nBerços:\n Quantidade de metros de berços: ", 8 * 0.5)
	
	        //Calcula a quantidade de madeira para a trama, que inclui os caibros e as ripas
	        escreva("\n\nTrama:\n")
	
	        //Calcula a quantidade de caibros
	        escreva(" Caibros:\n")
	
	        real altura_cumeeira = (g_inclinacao / 100) * (g_largura_base / 2)
	
	        g_qtde_caibros = Matematica.arredondar( (g_comprimento_base / 0.5) * 2 , 0)
	
	        g_metragem_caibros = g_qtde_caibros * (g_largura_base / 2)
	
	        escreva("  Quantidade de caibros: ", g_qtde_caibros, "\n")
	        escreva("  Quantidade de metros de caibro: ", g_metragem_caibros )
	
	        //Calcula a quantidade de ripas
	
	        escreva("\n Ripas:\n")
	
	        escreva("  Digite o comprimento da garga em metros: ")
	        leia(g_comprimento_garga)
	
	        g_qtde_ripas = 2 * Matematica.arredondar((g_largura_base / 2) / g_comprimento_garga, 0)
	        g_metragem_ripas = g_qtde_ripas * g_comprimento_base
	
	        escreva("  Quantidade de ripas: ", g_qtde_ripas)
	        escreva("\n  Quantidade de metros de ripas: ", g_metragem_ripas, "\n")
	
	        escreva("\n------\n")
	        escreva("Concluído.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular este orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
	        leia(usr_opt)
	
	    }enquanto(usr_opt == 1)
	
	    inteiro tipo_tijolo = 0, //Armazena o tipo de tijolo selecionado pelo usuário.
	        tipo_revesitmento = 0, //Armanzena o tipo de revestimento selecionado pelo usuário.
	        qtde_oitoes = 0 //Quantidade total de oitões presentes na construção.
	    
		  	faca {
			    escreva("--------------------\nORÇAMENTO DOS TIJOLOS\n--------------------\n")
	
			    faca {
			        escreva("Digite a quantidade de paredes que deseja construir: ")
			        leia(g_qtde_paredes)
			    } enquanto(g_qtde_paredes <= 0)
	
			    faca {
			        escreva("\nDigite a quantidade de oit?es presentes em sua casa: ")
			        leia(qtde_oitoes)
			    } enquanto(qtde_oitoes <= 0)
	
			    real areas_oitoes[QTDE_OITOES], //Vetor que armazena a área unitária de cada oitão em cada posição.
	            areas_aberturas[QTDE_PAREDES], //Vetor que armazena a área das aberturas presentes por parede em cada posição.
	            qtde_tijolos_por_parede[QTDE_PAREDES], //Vetor que armazena a quantidade de tijolos necessária para construir cada parede em casa posição.
	            qtde_tijolos_por_oitao[QTDE_OITOES] //Vetor que armazena a quantidade de tijolos necessária para construir cada oitão em cada posição.
	
			    para (inteiro i=0; i<g_qtde_paredes; i++) {
			        inteiro parede = i + 1
	                escreva("\n----- " + parede + "ª parede -----\n")
	    
			        faca {
			            escreva("\nA ", parede, "ª parede apresenta aberturas como portas e janelas?")
			            escreva("\n S - Sim\n N - Não\n")
			            escreva("Sua escolha: ")
			            leia(usr_rsp)
			        } enquanto (usr_rsp!='S' e usr_rsp!='s' e usr_rsp!='N' e usr_rsp!='n')
	
			        se (usr_rsp=='S' ou usr_rsp=='s') {
			            areas_aberturas[i] = calcula_area_aberturas()
			        } senao {
			            areas_aberturas[i] = 0.0
			        }
	
			        g_areas_paredes[i] = calcula_area_parede(areas_aberturas[i])
	
			        escreva("\nÁrea da ", parede, "ª parede, com as áreas das aberturas descontadas é de: ", g_areas_paredes[i], "m²\n\n")
			    }
	
			    para (inteiro i=0; i<qtde_oitoes; i++) {
			        inteiro oitao = i+1
	                escreva("\n----- " + oitao + "º oitão -----\n")
	    
			        areas_oitoes[i] = calcula_area_oitao()
	
			        escreva("\nÁrea do ", oitao, "º oitão: ", areas_oitoes[i], "m²\n\n")
			    }
	
			    tipo_tijolo = escolhe_tipo_tijolo()
	
			    escolha (tipo_tijolo) {
			        caso 1:
			            escreva("\n--------------------\n")
			            escreva("Blocos Cerâmicos\n")
			            g_tipo_tijolo = "Blocos Cerâmicos"
			            pare
	
			        caso 2:
			            escreva("\n--------------------\n")
			            escreva("Tijolos Maciços\n")
			            g_tipo_tijolo = "Tijolos Maciços"
			            pare
	
			        caso 3:
			            escreva("\n--------------------\n")
			            escreva("Tijolos de Adobe\n")
			            g_tipo_tijolo = "Tijolos de Adobe"
			            pare
	
			        caso 4:
			            escreva("\n--------------------\n")
			            escreva("Tijolos Laminados\n")
			            g_tipo_tijolo = "Tijolos Laminados"
			            pare
	
			        caso 5:
			            escreva("\n--------------------\n")
			            escreva("Tijolos e Blocos de Concreto\n")
			            g_tipo_tijolo = "Tijolos e Blocos de Concreto"
			            pare
	
			        caso 6:
			            escreva("\n--------------------\n")
			            escreva("Tijolos Ecológicos\n")
			            g_tipo_tijolo = "Tijolos Ecológicos"
			            pare
			    }
	
			    g_qtde_tijolo_metro_quadrado = calcula_qtde_tijolos_por_metro_quadrado()
	
			    escreva("\nRendimento: ", g_qtde_tijolo_metro_quadrado, " tijolos por metro quadrado.\n")
	
			    faca {
			        escreva("\nPreço Unitário do Tijolo: R$ ")
			        leia(g_preco_unit_tijolo)
			    } enquanto (g_preco_unit_tijolo <= 0)
	
			    calcula_qtde_tijolos_por_parede(qtde_tijolos_por_parede)
	
			    calcula_qtde_tijolos_por_oitao(qtde_tijolos_por_oitao, qtde_oitoes, g_qtde_total_tijolos, areas_oitoes)
	
			    g_qtde_total_tijolos += (TAXA_DE_PERDA * g_qtde_total_tijolos)
	
			    escreva("\n\n----- Quantidade total de tijolos -----")
			    escreva("\n ", g_qtde_total_tijolos, " tijolos")
	
			    g_custo_total_tijolos = g_preco_unit_tijolo * g_qtde_total_tijolos
			    escreva("\n\n----- Preço total - Tijolos -----")
			    escreva("\n R$ ", g_custo_total_tijolos)
	
		        escreva("\n------\n")
		        escreva("Concluído.")
		        escreva("\n------\n")
	
		        escreva("\nRecalcular orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
		        leia(usr_opt)
	
		  	} enquanto (usr_opt == 1)
	
		  	faca {
			    escreva("\n--------------------\nORÇAMENTO DO REVESTIMENTO DE PISO\n--------------------\n")
	
			    tipo_revesitmento = escolhe_tipo_revestimento()
	
			    escolha (tipo_revesitmento) {
	
			        caso 1:
			            escreva("\n--------------------\n")
			            escreva("Papel de parede\n")
			            g_tipo_revestimento = "Papel de Parede"
			            pare
	
			        caso 2:
			            escreva("\n--------------------\n")
			            escreva("Madeira\n")
						g_tipo_revestimento = "Madeira"
			            pare
	
			        caso 3:
			            escreva("\n--------------------\n")
			            escreva("Pastilhas\n")
			            g_tipo_revestimento = "Pastilhas"
			            pare
	
			        caso 4:
			            escreva("\n--------------------\n")
			            escreva("Ladrilho hidráulico\n")
			            g_tipo_revestimento = "Ladrilho Hidráulico"
			            pare
	
			        caso 5:
			            escreva("\n--------------------\n")
			            escreva("Azulejo comum\n")
			            g_tipo_revestimento = "Azulejo Comum"
			            pare
			    }
	
			    g_qtde_revestimento_metro_quadrado = calcula_qtde_revestimento_por_metro_quadrado()
	
			    escreva("\nRendimento: ", g_qtde_revestimento_metro_quadrado, " unidade(s) de revestimento por metro quadrado.\n")
	
			    faca {
			        escreva("\nPreço Unitário do Revestimento: R$ ")
			        leia(g_preco_unit_revestimento)
			    } enquanto (g_preco_unit_revestimento <= 0)
	
			    calcula_qtde_revestimento_por_parede()
	
			    g_qtde_total_revestimento += (TAXA_DE_PERDA * g_qtde_total_revestimento)
	
			    escreva("\n\n----- Quantidade total de revestimento -----")
			    escreva("\n ", g_qtde_total_revestimento, " unidades de revestimento")
	
			    g_custo_total_revestimento = g_preco_unit_revestimento * g_qtde_total_revestimento
			    escreva("\n\n----- Preço total - Revestimento -----")
			    escreva("\n R$ ", g_custo_total_revestimento, "\n")
	
		        escreva("\n------\n")
		        escreva("Concluído.")
		        escreva("\n------\n")
	
		        escreva("\nRecalcular orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
		        leia(usr_opt)
	
		  	} enquanto (usr_opt == 1)
	
		faca {
		    escreva("\n--------------------\nORÇAMENTO DA TINTA\n--------------------\n")
	
		    real area_tetos = 0.0 //Armazena a área total do teto da construção.
	
		    faca {
		        escreva("\nÁrea total do teto presente na construção: ")
		        leia(area_tetos)
		    } enquanto (area_tetos <= 0)
	
		    g_qtde_total_galoes_tinta = calcula_qtde_total_galoes_tinta(area_tetos)
		    g_qtde_total_galoes_tinta += Matematica.arredondar(TAXA_DE_PERDA * g_qtde_total_galoes_tinta, 0)
	
		    escreva("\n\n----- Quantidade total de galões de tinta -----\n")
		    escreva(g_qtde_total_galoes_tinta, " galões de tinta")
	
		    faca {
		        escreva("\nPreço Unitário do Galão de Tinta: R$ ")
		        leia(g_preco_unit_galao_tinta)
		    } enquanto (g_preco_unit_galao_tinta <= 0)
	
		    g_custo_total_galao_tinta = g_preco_unit_galao_tinta * g_qtde_total_galoes_tinta
		    escreva("\n\n----- Preço total - Tinta -----")
		    escreva("\n R$ ", g_custo_total_galao_tinta, "\n")
	
	        escreva("\n------\n")
	        escreva("Concluído.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
	        leia(usr_opt)
	
	  	} enquanto (usr_opt == 1)
	
	  	escreva("\n\nDeseja salvar o orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
	  	leia(usr_opt)
	
	  	se(usr_opt == 1){
	  		salvar_dados()
	  	}
	
	  	escreva("\n\nTudo finalizado!")
	
	}
	
	funcao carregar_orcamento()
	{
	
	    cadeia dir = "",
	        linha //variável usada para armazenar temporariamente o valor lido do arquivo, especificamente para os dados relativos ?s paredes, que podem ser várias em uma linha
	
	    inteiro ctrl = 0, i
	
	    inteiro size // Variável que armazena o tamanho dos vetores dos dados realtivos as paredes
	    real areas_paredes[QTDE_PAREDES] // Vetor que irá armazenar as áreas de cada parede  lidas dos arquivos
	    inteiro qtd_revestimento_paredes[QTDE_PAREDES] // Vetor que irá armazenar as quantidades de revestimento de cada parede lidas dos arquivos
	
	    faca{
	        ctrl = 0
	
	        escreva("Digite o diretório do arquivo, incluindo o nome do arquivo: ")
	        leia(dir)
	
	        se(Arquivos.arquivo_existe(dir)){
	
	            //Estruturas
	                escreva("\n\nESTRUTURAS\n\n")
	                escreva("Profundidade das colunas: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_PROFUNDIDAE_COLUNAS)), "m\n" )
	                escreva("Diâmetro das colunas: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_DIAMETRO_COLUNAS)), "m\n")
	                escreva("Perimetro total das paredes: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_PERIMETRO_TOTAL)), "m\n")
	                escreva("Largura dos baldrames: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_LARGURA_BALDRAME)), "m\n")
	                escreva("Profundidade dos baldrames: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_PROFUNDIDADE_BALDRAME)), "m\n")
	                escreva("Área total de construção: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_AREA_TOTAL_CONSTRUCAO)), "m²\n")
	                escreva("Quantidade de cimento: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_QUANTIDADE_CIMENTO)), "m³\n")
	                escreva("Altura das paredes: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_ALTURA_PAREDES)), "\nm")
	                escreva("Quantidade de ferro 3/8: ", ler_registro(dir, C_ESTRUT_QTDE_FERRO_3_8), "\n")
	                escreva("Quantidade de ferro 3/16: ", ler_registro(dir, C_ESTRUT_QTDE_FERRO_3_16), "\n")
	                escreva("Quantidade de colunas: ", ler_registro(dir, C_ESTRUT_QTDE_COLUNAS), "\n")
	                escreva("Quantidade de piso: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_AREA_PISO)), "\n")
	                escreva("Piso: ", ler_registro(dir, C_ESTRUT_PISO), "\n\n")
	            //Fim Estruturas
	
	            //Tijolos
	                escreva("TIJOLOS\n\n")
	                escreva("Quantidade de paredes: ", ler_registro(dir, C_QTDE_PAREDES), "\n")
	
	                escreva("Área das paredes:\n")
	
	                linha = ler_registro(dir, C_AREA_PAREDES)
	
	                size = count_char(linha, Texto.numero_caracteres(linha), '#') + 1
	                split_string_float( linha, areas_paredes, '#' )
	
	                para(i = 0; i < size; i++){
	                    escreva("  Parede ", i + 1, ": ", areas_paredes[i], "m²\n")
	                }
	
	                escreva("Tipo de tijolo: ", ler_registro(dir, C_TIJOLO_TIPO), "\n")
	                escreva("Quantidade total de tijolos: ", ler_registro(dir, C_TIJOLO_QTDE), "\n")
	                escreva("Quantidade de tijolos por m²: ", ler_registro(dir, C_TIJOLO_QTDE_METRO), "\n")
	                escreva("Custo total de tijolos: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_TIJOLO_CUSTO_TOTAL)), "\n")
	                escreva("Preço unitário do tijolo: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_TIJOLO_PRECO_UNIT)), "\n\n")
	            //Fim Tijolos
	
	            //Revestimento
	                escreva("REVESTIMENTO\n\n")
	                escreva("Tipo de revestimento: ", ler_registro(dir, C_REVESTIMENTO_TIPO), "\n")
	                escreva("Quantidade total de revestimento: ", ler_registro(dir, C_REVESTIMENTO_QTDE), "\n")
	                escreva("Quantidade de revestimento por m²: ", ler_registro(dir, C_REVESTIMENTO_QTDE_METRO), "\n")
	
	                escreva("Quantidade de revestimento por parede:\n")
	
	                linha = ler_registro(dir, C_REVESTIMENTO_POR_PAREDE)
	
	                size = count_char(linha, Texto.numero_caracteres(linha), '#') + 1
	                split_string_int( linha, qtd_revestimento_paredes, '#' )
	
	                para(i = 0; i < size; i++){
	                    escreva("  Parede ", i + 1, ": ", qtd_revestimento_paredes[i], "\n")
	                }
	
	                escreva("Custo total do revestimento: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_REVESTIMENTO_CUSTO_TOTAL)), "\n" )
	                escreva("Preço unitário do revestimento: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_REVESTIMENTO_PRECO_UNIT)), "\n\n")
	            //Fim Revestimento
	
	            //Tinta
	                escreva("TINTA\n\n")
	                escreva("Quantidade de galões de tinta: ", ler_registro(dir, C_GALAO_TINTA_QTDE), "\n")
	                escreva("Custo total dos galões de tinta: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_GALAO_TINTA_CUSTO_TOTAL)), "\n")
	                escreva("Preço unitário do galão de tinta: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_GALAO_TINTA_PRECO_UNIT)), "\n\n")
	            //Fim Tinta
	
	            //Telhado
	                escreva("TELHADO\n\n")
	                escreva("Inclinação: ", ler_registro(dir, C_TELHADO_INCLINACAO), "%\n")
	                escreva("Largura da laje: ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHADO_LARGURA_BASE)), "m\n")
	                escreva("Comprimento da laje: ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHADO_COMPRIMENTO_BASE)), "m\n")
	                escreva("Área do telhado corrigida pela inclinação: ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHADO_AREA_CORRIGIDA)), "m²\n\n")
	            //Fim Telhado
	
	            //Madeiramento
	                escreva("MADEIRAMENTO DO TELHADO\n\n")
	                escreva("Quantidade de terças: ", ler_registro(dir, C_MADEIRA_QTDE_TERCA), "\n")
	                escreva("Quantidade de caibros: ", ler_registro(dir, C_MADEIRA_QTDE_CAIBRO), "\n")
	                escreva("Quantidade de ripas: ", ler_registro(dir, C_MADEIRA_QTDE_RIPAS), "\n")
	                escreva("Metros de pontaletes: ", Tipos.cadeia_para_real(ler_registro(dir, C_MADEIRA_METROS_PONTALETES)), "\n")
	                escreva("Metros de caibros: ", Tipos.cadeia_para_real(ler_registro(dir, C_MADEIRA_METROS_CAIBROS)), "\n")
	                escreva("Metros de ripas: ", Tipos.cadeia_para_real(ler_registro(dir, C_MADEIRA_METROS_RIPAS)), "\n")
	                escreva("Metros de terças: ", Tipos.cadeia_para_real(ler_registro(dir, C_MADEIRA_METROS_TERCAS)), "\n")
	                escreva("Espaçamento entre as terças: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESPACAMENTO_TERCAS)), "m\n")
	                escreva("Comprimento da garga: ", Tipos.cadeia_para_real(ler_registro(dir, C_COMRPRIMENTO_GARGA)), "m\n\n")
	            //Fim madeiramento
	
	            //Telhas
	                escreva("TELHAS\n\n")
	                escreva("Tipo de telha: ", ler_registro(dir, C_TELHA_TIPO), "\n")
	                escreva("Quantidade de telhas: ", ler_registro(dir, C_TELHA_QTDE), "\n")
	                escreva("Custo total das telhas: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHA_CUSTO_TOTAL)), "\n")
	                escreva("Preço unitário das telhas: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHA_PRECO_UNIT)), "\n\n")
	            //Fim Telhas
	
	        }
	        senao{
	            escreva("\nO arquivo informado não existe.\n\n")
	            ctrl = 1
	        }
	
	    }enquanto(ctrl == 1)
	}
	
	//Exibe ajuda sobre o programa
	funcao ajuda()
	{
		
	     escreva("AJUDA\n-----\nÍndice:\n")
	     escreva("1 - INCLINAÇÃO DO TELHADO\n")
	     escreva("2 - MADEIRAMENTO DO TELHADO\n")
	     escreva("3 - MODELOS DE TELHAS\n")
	  	escreva("4 - MODELOS DE TIJOLOS\n")
	  	escreva("5 - MODELOS DE REVESTIMENTO PARA PAREDE\n")
	  	escreva("6 - MODELOS DE PISO")
	
	    escreva("\n* Você pode usar as teclas numéricas para navegar pelos itens.\n\n\n")
	
	    escreva("1. INCLINAÇÃO DO TELHADO\n------------------------>\n")
	
	    escreva("* Pressione F1 para uma imagem ilustrativa.\n\n")

	    escreva(" A inclinação do telhado é calculada com base na largura da laje (dividida por dois no\ncaso de telhado com duas águas).O valor para a inclinação é fornecido em porcentagem,\nessa porcentagem corresponde a porção da base que será espelhada para compor a cumeeira.\n")
	    escreva(" Por exemplo, um telhado com base (laje) 12x10m, com inclinação de 30% e duas águas, temos:\n")
	    escreva("  a. Calculamos a metade da largura da base, nesse caso 6 (12/2 = 6);\n")
	    escreva("  b. Calculamos 30% do valor achado anteriormente, ficando com 1.8m (6 * 0.3 = 1.8).\n     Essa seráa altura da cumeeira.\n\n")
	
	    escreva("\n2. MADEIRAMENTO DO TELHADO\n-------------------------->\n")
	
	    escreva("* Pressione F2 para uma imagem ilustrativa.\n\n")
	
	    escreva(" O madeiramento do telhado contempla toda a madeira usada para dar sustentação ao telhado:\n")
	    escreva(". Terça;\n. Pontalete;\n. Berço;\n. Mão Francesa;\n. Trama:\n  . Caibro;\n  . Ripas.\n\n")
	
	    escreva("\n3. MODELOS DE TELHAS\n-------------------->\n")
	
	    escreva("* Pressione F3 para uma imagem ilustrativa.\n\n")
	
	    escreva("\n TELHA PORTUGUESA\n----------------->\n")
	
	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 17 peças por metro quadrado\n")
	    escreva("   Dimensões: 38x20")
	    escreva("   Peso: 2,6 Kg por peça\n")
	    escreva("   Inclinação Mínima: 35%\n\n")
	
	    escreva("\n TELHA ROMANA\n------------->\n")
	
	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 16 peças por metro quadrado\n")
	    escreva("   Dimensões: 40x21")
	    escreva("   Peso: 2,7 Kg por peça\n")
	    escreva("   Inclinação Mínima: 35%\n\n")
	
	    escreva("\n TELHA AMERICANA\n---------------->\n")
	
	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 12 peças por metro quadrado\n")
	    escreva("   Dimensões: 46x26cm")
	    escreva("   Peso: 2,9 Kg por peça\n")
	    escreva("   Inclinação Mínima: 30%\n\n")
	
	    escreva("\n TELHA FRANCESA\n--------------->\n")
	
	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 16 peças por metro quadrado\n")
	    escreva("   Dimensões: 38x24")
	    escreva("   Peso: 2,8 Kg por peça\n")
	    escreva("   Inclinação Mínima: 45%\n\n")
	
	    escreva("\n TELHA ITALIANA\n--------------->\n")
	
	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 13 peças por metro quadrado\n")
	    escreva("   Dimensões: 45x26")
	    escreva("   Peso: 3,4 Kg por peça\n")
	    escreva("   Inclinação Mínima: 30%\n\n")
	
	    escreva("\n TELHA GERMÂNICA\n---------------->\n")
	
	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 40 peças por metro quadrado\n")
	    escreva("   Dimensões:\n\tnormal 36x18,5cm\n\tcurta 24x18,5cm")
	    escreva("   Peso: 1,16 Kg por peça\n")
	    escreva("   Inclinação Mínima: 30%\n\n")
	
	    escreva("\n TELHA HOLANDESA\n---------------->\n")
	
	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 17 peças por metro quadrado\n")
	    escreva("   Dimensões: 41x24cm")
	    escreva("   Peso: 2,5 Kg por peça\n")
	    escreva("   Inclinação Mínima: 30%\n\n")
	
	    escreva("\n TELHA URUGUAIA\n--------------->\n")

	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 16 peças por metro quadrado\n")
	    escreva("   Dimensões: 28x19,5cm")
	    escreva("   Peso: 1 Kg por peça\n")
	    escreva("   Inclinação Mínima: 45%\n\n")
	
	    escreva("\n TELHA PLAN\n----------->\n")

	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 26 peças por metro quadrado\n")
	    escreva("   Dimensões:\n\tcapa 48x16cm\n\tcanal: 48x19cm")
	    escreva("   Peso: 2,3 Kg por peça\n")
	    escreva("   Inclinação Mínima: 30%\n\n")
	
	    escreva("\n TELHA PAULISTA\n--------------->\n")

	    escreva("   Material: Cerâmica\n")
	    escreva("   Quantidade: 22 peças por metro quadrado\n")
	    escreva("   Dimensões:\n\tcapa 48x17cm\n\tcanal: 48x20cm")
	    escreva("   Peso: 2,2 Kg por peça\n")
	    escreva("   Inclinação Mínima: 30%\n")
	
	    escreva("\n\n4. MODELOS DE TIJOLOS\n--------------------->\n")
	
	    escreva("* Pressione F4 para uma imagem ilustrativa.\n\n")
	
	    escreva("\n BLOCO CERÂMICO\n--------------->\n")
	
	  	escreva("   Os blocos cerâmicos são feitas à base de argila cozida e são um itens mais utilizados na\nconstrução de paredes de alvenaria, podendo haver variações em relação ao número de furos e\ntamanho, sendo que os maiores são indicados para esturutras maiores.\n")
	  	escreva("   Os blocos furados são mais leves e baratos, porém, são mais vulneráveis a quebras durante\na obra.")
	  	escreva("   É importante destacar que este material não é estrutural, ou seja, pode ser utilizado\napenas para o fechamento e não para sustentação de cobertura ou laje.\n")
	
	    escreva("\n TIJOLOS MACIÇOS\n---------------->\n")
	
	    escreva("   Os tijolos maciços são feitos à base de argila cozida e são um dos itens mais utilizados\nna construção de paredes de alvenaria.\n")
	  	escreva("   Possuem mais resistência com relação aos blocos cerâmicos, podendo ser deixados aparentes\nou serem divididos ao meio para serem usados como revestimento para as paredes.\n")
	
	    escreva("\n TIJOLOS DE ADOBE\n----------------->\n")
	
	    escreva("   São basicamente uma mistura de terra e água, com acréscimo de palhas ou outros materiais\norgânicos, feitos através de processo artesanal ou semi-industrial de moldagem e secagem.\n")
	  	escreva("   É um tijolo ecológico, porque dispensa o cozimento que gasta muita energia e emite muitos\ngases, mas não é muito resistente a interpéries como chuva e vento, pois absorve muita água\ne pode se desfazer em contato direto e intenso com chuva.\n")
	
	    escreva("\n TIJOLOS LAMINADOS\n------------------>\n")
	
	    escreva("   Esta peça também é conhecida como tijolo de 21 furos devido à quantidade de orifícios que\napresenta.\n")
	  	escreva("   Este tipo de tijolo apresenta melhor aderência de argamassa, possibilitando uma estrutura\nmais firme e também tem alta durabilidade.\n")
	  	escreva("   Indica-se utilizar o modelo horizontalmente, para que apenas a parte lisa fique à mostra.\nÉ muito comum a utilização deste tipo de tijolo em projetos com tijolo aparente, como fachadas,\npor exemplo.\n")
	
	    escreva("\n TIJOLOS E BLOCOS DE CONCRETO\n----------------------------->\n")
	
	    escreva("   Apresenta uma estrutura mais robusta, sendo comumente utilizado em construções maiores e\ntambém em alicerces para casas.\n")
		escreva("   A vantagem na utilização de tijolos ou blocos de concreto é com relação à economia no consumo\nde argamassa, pois sua anatomia facilita a junção das peças.\n")
	
	  	escreva("\n TIJOLOS ECOLÓGICOS\n------------------->\n")
	
	    escreva("   Produzido a partir de uma mistura de solo, cimento e água, é uma peça muito utilizada em\nconstruções sustentáveis devido a sua tendência ecológica.\n")
	  	escreva("   Suas vantagens são o baixo consumo de argamassa, isolamento térmico e acústico, fácil encaixe\ne possibilidade de ficar aparente.\n")
		escreva("   Porém, é uma peça que necessita de um profissional especializado e também não é indicada para\nlocais muito úmidos.\n")
	
	  	escreva("\n\n5. MODELOS DE REVESTIMENTO PARA PAREDE\n-------------------------------------->\n")
	
	    escreva("* Pressione F5 para uma imagem ilustrativa.\n\n")
	
	    escreva("\n PAPEL DE PAREDE\n---------------->\n")
	
	    escreva("   Revestimento simples, facilmente encontrado e de fácil instalação.\n")
	  	escreva("   Este tipo de revestimento é indicado para regiões e ambientes menos úmidos, sendo assim,\né ideal evitar a utilização de papel de parede em banheiros e cozinhas.\n")
	
	    escreva("\n MADEIRA\n-------->\n")
	
	    escreva("   Este tipo de material possui uma grande variedade de cores e tonalidades e ajuda a\naquecer os cômodos, mantendo uma temperatura agradável no ambiente.\n")
	
	    escreva("\n PASTILHAS\n---------->\n")
	
	    escreva("   As pastilhas são pequenas peças que podem ser feitas de cerâmica, resina ou vidro e\nsão aplicadas às paredes como se fossem pequenos azulejos.\n")
	
		escreva("\n LADRILHO HIDRÁULICO\n-------------------->\n")
	
	    escreva("   São azulejos que podem apresentar variações nos tamanhos, mas muito conhecidos por\nsuas estampas coloridas e bem detalhadas.\n")
	
	  	escreva("\n AZULEJO COMUM\n-------------->\n")
	
	    escreva("   São azuelejos que se apresentam no mesmo formato dos ladrilhos hidráulicos, um pouco\nmaiores às vezes, mas não possuem um diferencial em específico.\n")
	
	    escreva("\n\n6. TIPOS DE PISO\n---------------->\n")
	
	    escreva("* Pressione F6 para uma imagem ilustrativa.\n\n")
	
	    escreva("\n CERÂMICO\n--------->\n")
	
	    escreva("   A cerâmica é o tipo de piso mais conhecido e usado no Brasil. São encontradas de\nvários tamanhos (desde 20×30, 40×40, 60×60, 80×80, 100×100), texturas, qualidades e preços. Podem ser\nutilizadas em áreas internas e externas.\n")
	
	    escreva("\n PORCELANATO\n------------>\n")
	
	    escreva("   O Porcelanato é produzido em massa única já na sua coloração e com matérias-primas\nnobres.Podem ser semi-polidos, polidos e peça rústica. Também há os porcelanatos esmaltados e os\nporcelanatos digitais polidos com a mais alta qualidade e com várias texturas, principalmente imitando\nmadeiras, mármores e granitos.\n")
	
	    escreva("\n GRANITO\n-------->\n")
	
	    escreva("   O granito é uma pedra muito indicada para pisos devido a sua beleza, resistência\ne durabilidade. São utilizados desde residências até em locais com grande movimentação de pessoas\ncomo shoppings, supermercados, aeroportos, etc. Possuem várias tonalidades e quanto mais raro mais caro.\n")
	
	    escreva("\n MÁRMORE\n-------->\n")
	
	    escreva("   O mármore também é uma rocha metamórfica, composta principalmente por minerais\nde calcita com colaração mais uniforme e formação de veios definidos. É indicado para utilização em\nambientes internos apenas.\n")
	
	    escreva("\n LAMINADO DE MADEIRA\n-------------------->\n")
	
	    escreva("   Esse piso tem esse nome porque são constituídos de lâminas de madeira. É um tipo\nde piso flutuante porque não é colado no contrapiso. São assentados sobre manta, em sistema de encaixe\ntipo click e presos pelos rodapés que são colados.São sustentáveis por serem de madeira reflorestada.\n")
	
	    escreva("\n SILESTONE\n---------->\n")
	
	    escreva("   Silestone é um material composto por grande quantidade de quartzo, outros minerais\nem menor escala, resina de poliéster e pigmentos. Com porosidade nula, possui várias texturas e um\ncusto muito elevado.\n")
	
	    escreva("\n TÁBUA CORRIDA\n-------------->\n")
	
	    escreva("  Piso em madeira natural de lei, geralmente extraída da Amazônia. Conferem muita beleza\ne conforto, mas não são sustentáveis. Sua instalação é sobre um ripamento e possuem encaixe tipo\nmacho-fêmea.\n")
	
	    escreva("\n TACÃO\n------>\n")
	
	    escreva("   Os tacos foram sucesso nos anos 1960 a 1980. Atualmente são utilizados em ambientes mais\nespecíficos e possuem custo elevado. Assim como a tábua corrida, necessitam de raspar e\nsintecar. As madeiras mais comuns para tacão são a grápia, cumaru e ipê.\n")
	
	    escreva("\n LAJOTA\n------->\n")
	
	    escreva("   Instaladas tanto em paredes internas como em fachadas, as lajotas apresentam inúmeras\nvantagens, entre elas a ótima resistência às variações climáticas, a beleza e a relação\ncusto X benefício. As peças estão cada vez mais inovadoras, com formas geométricas variadas e com pinturas\nde desenhos que conferem um charme todo especial ao ambiente.\n")
	
	    escreva("\n ARDÓSIA\n-------->\n")
	
	    escreva("   Piso em pedra ardósia foi largamente utilizado nos anos 1980 devido a sua durabilidade e\nbaixo custo. Podem ser utilizadas em pisos internos de áreas molhadas e áreas externas.\n")
	
	    escreva("\n CIMENTO QUEIMADO\n----------------->\n")
	
	    escreva("   Solução de baixo custo para pisos e quando bem feita confere ótimo acabamento. Indicado\ntanto para áreas internas quanto para áreas externas. Muito utilizado em bares, boates e\ngalpões industriais.\n")
	
	    escreva("\n PEDRA PORTUGUESA\n----------------->\n")
	
	    escreva("   Muito utilizadas em calçadas a pedra portuguesa mais famosa do mundo é o calçadão de\nCopacabana no Rio de Janeiro. A execução do trabalho é bastante demorada porque cada pedra é\nassentada uma a uma.\n")
	
	    escreva("\n PEDRA SÃO TOMÉ\n--------------->\n")
	
	    escreva("  Com vários outros nomes pelo Brasil afora a Pedra São Tomé é o piso mais utilizado ao\nredor das piscinas. São vendidas em regulares 30x30cm e irregulares (retalhos).\n")
	
	    escreva("\n GRANITINA\n---------->\n")
	
	    escreva("  A granitina é uma massa de cimento misturada com pequenas pedrinhas de granito aplicadas\nno piso. Após a cura do piso é polida com discos diamantados que conferem uma superfície\nlisa e brilhante. O piso em granitina é muito utilizado em áreas internas e externas de clubes, escolas,\naeroportos.\n")
	
	}
	
	funcao inicio()
	{
	
	    inteiro usr_opt
	
	    faca{
	
	        escreva("Selecione uma ação:\n 1 - Criar um novo orçamento\n 2 - Visualizar um orçamento existente\n 3 - Ajuda\n\nSua escolha: ")
	        leia(usr_opt)
	
	        escolha(usr_opt){
	            caso 1:
	
	                novo_orcamento()
	
	                pare
	
	            caso 2:
	
	                carregar_orcamento()
	
	                pare
	
	            caso 3:
	
	                ajuda()
	
	                pare
	
	            caso contrario:
	                escreva("\nOpção inválida\n\n")
	        }
	
	        escreva("\n\n")
	
	    }enquanto(verdadeiro)
	
	}

}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 66078; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */