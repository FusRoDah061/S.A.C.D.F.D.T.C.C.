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
	
	//Constante que define o tamanho m�ximo de paredes e oit�es que o usu�rio pode construir por vez.
	const inteiro QTDE_PAREDES = 100
	const inteiro QTDE_OITOES = 50  
	
	//Constantes correspondentes as chaves que ser�o salvas no arquivo
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
	inteiro g_inclinacao = 0//Inclina��o do telhado
	
	real g_largura_base = 0.0,//Largura da base do telhado (laje)
	      g_area_telhado_corrigida = 0.0,//�rea do telhado corrigida j� incluindo a inclina��o do teclado
	      g_comprimento_base = 0.0//Comprimento da base do telhado (laje)
	
	//Telhas
	inteiro g_qtde_telhas = 0//Quantidade de telhas no total
	cadeia g_tipo_telha = ""
	
	real g_custo_total = 0.0,//Custo total das telhas no final
	    g_preco_unit = 0.0,//Pre�o unit�rio de cada telha
	    g_qtde_telha_metro = 0.0//Quantidade de telhas por metro quadrado
	
	//Madeiramento
	inteiro g_qtde_tercas = 0, //Quantidade de ter�as para as duas �guas do telhado
	    g_qtde_caibros = 0,// Quantidade de caibros para o telhado
	    g_qtde_ripas = 0 //Quantidade de ripas para o telhado
	
	real g_tercas_espacamento = 0.0, //Espa�amento entre as ter�as
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
	*Fun��o converte() = Evita que o usu�rio entre com um valor que ir� alterar os calculos de uma estrutura real, por exemplo:
		- Usu�rio digita 21 (o programa entende como 21 metros), mas o calculo real precisa do valor em cent�metros, entao a fun��o verificaso o
	  valor dado precisa ser corrigido e o devolve com a corre��o feita, caso n�o necessite de corre��o, ela apenas retorna o valor para c�lculo.
	*parametros: valor real
	*/
	funcao real converte(real num)
	{
	
		inteiro aux
		real verify
	
		aux=num
		se (aux == 0 e aux != num){
			verify = num //O numero digitado n�o � inteiro, e j� est� em "cent�metros" - n�o fazer nada
		}
		senao se(aux > 0 e aux == num){
			verify = num/100 //O numero digitado n�o � inteiro e est� em "Metros", por isso, deve-se dividir por 100 para se ter a base em cm
		}
		senao se(aux > 0 e aux != num){
			verify = num/100 //O numero digitado n�o � inteiro e est� em "Metros", por isso, deve-se dividir por 100 para se ter a base em cm
		}
	
		retorne verify
	
	}
	
	/*
	*calcula a quantidade necessaria de cimento para a constru��o das estruturas da casa
	*
	*Par�metros:
	*deep = profundidade das colunas subterr�neas
	*dm = diametro das colunas/subterr�neas e sobterr�neas, j� que seguem as mesmas medidas
	*largura_baldrames = largura dos baldrames onde ser�o construidas as paredes
	*profundidade_baldrames = profundidade dos baldrames onde ser�o construidas as paredes
	*perimetro_total = soma de todas as paredes da casa em metros lineares
	*altura paredes = altura das paredes para base de calculo das colunas
	*g_qtde_colunas = quantidade de colunas da constru��o para calculo de cimento em m�
	*/
	funcao real calcula_cimento(real deep, real dm, real largura_baldrames, real profundidade_baldrames, real perimetro_total, real altura_paredes, inteiro qtde_colunas)
	{
	    real r, area_coluna_chao, area_coluna_parede, total, bald_total, tot_colunas
	
	    r = dm/2
	
	    area_coluna_chao = ( ( Matematica.PI * Matematica.potencia(r, 2.0) ) * deep ) //�rea das colunas subterr�neas
	
	    area_coluna_parede = ( ( Matematica.PI * Matematica.potencia(r, 2.0) ) * altura_paredes )//�rea das colunas que sobem acompanhando as paredes
	
	    tot_colunas = (area_coluna_chao + area_coluna_parede) * qtde_colunas//soma das colunas parede+ch�o
	
	    bald_total = largura_baldrames * profundidade_baldrames * perimetro_total * 2//�rea dos baldrames, multiplica - se por 2 pois existe o baldrame que sustenta a laje da casa, este possui praticamente a mesma �rea do que sustenta as paredes
	
	    total = bald_total + tot_colunas//soma de todas as �reas da estrutura
	
	    retorne total
	
	}
	
	/*
	*Calcula a quantidade de ferro 3/8 e 3/16 para a constru��o
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
				escreva("\nA largura do estribo n�o pode ser maior que a do baldrame!\nDigite um valor at� ", largura_baldrame-0.07, " metros\n")
			}
	
		}enquanto(larg_stribo > largura_baldrame-0.07)
	
		faca{
	
			escreva("Digite a altura do estribo: ")
			leia(altura_stribo)
	
			altura_stribo = converte(altura_stribo)//VERIFICA E CONVERTE
	
			//escreva("ALTURA = %.2f\n",altura_stribo)
	
			se(altura_stribo > profundidade_baldrame-0.04){
				escreva("\nA altura do estribo n�o pode ser maior que a do baldrame!\nDigite um valor at� %.2f metros\n",profundidade_baldrame-0.04)
			}
	
		}enquanto(altura_stribo > profundidade_baldrame-0.04)
	
		escreva("Digite o tamanho unit�rio da barra de ferro escolhida para estrutura: ")
		leia(tamanho_barra)
	
	
		escreva("Digite o tamanho unit�rio da barra de ferro escolhida para amara��o da estrutura: ")
		leia(tamanho_barra_amarra)
	
		faca{
	
			escreva("Digite o espa�amento entre as amarra��es do estribo: ")
			leia(espacamento)
	
			espacamento = converte(espacamento)
	
			//escreva("ESPA�AMENTO = %.2f\n", espacamento)
	
			se(espacamento > 0.201){
				escreva("O espa�amento n�o pode ser maior que 20 cent�metros!!! Digite um valor menor.\n")
			}
	
		}enquanto(espacamento > 0.201)
	
	
		qtde_ferro_estribo = ( ( larg_stribo * 2 + altura_stribo * 2 ) * perimetro / espacamento ) / tamanho_barra_amarra //quantidade em barras de ferro para amarra��o do estribo
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
	
			escreva("\nEscolha o tipo de piso:\n1 - CER�MICA\n2 - PORCELANATO\n3 - GRANITO\n4 - M�RMORE\n5 - LAMINADO DE MADEIRA\n6 - SILESTONE\n7 - T�BUA CORRIDA\n8 - TAC�O\n9 - LAJOTA\n10 - ARD�SIA\n11 - CIMENTO QUEIMADO\n12 - PEDRA PORTUGUESA\n13 - PEDRA S�O TOM�\n14 - GRANITINA\n15 - OUTRO\n\nSua escolha: ")
			leia(piso)
	
			se(piso != 15){
				escolha(piso)
				{
					caso 1:
						g_pisoS = "CER�MICA"
					pare
	
					caso 2:
						g_pisoS = "PORCELANATO"
					pare
	
					caso 3:
						g_pisoS = "GRANITO"
					pare
	
					caso 4:
						g_pisoS = "M�RMORE"
					pare
	
					caso 5:
						g_pisoS = "LAMINADO DE MADEIRA"
					pare
	
					caso 6:
						g_pisoS = "SILESTONE"
					pare
	
					caso 7:
						g_pisoS = "T�BUA CORRIDA"
					pare
	
					caso 8:
						g_pisoS = "TAC�O"
					pare
	
					caso 9:
						g_pisoS = "LAJOTA"
					pare
	
					caso 10:
						g_pisoS = "ARD�SIA"
					pare
	
					caso 11:
						g_pisoS = "CIMENTO QUEIMADO"
					pare
	
					caso 12:
						g_pisoS = "PEDRA PORTUGUESA"
					pare
	
					caso 13:
						g_pisoS = "PEDRA S�O TOM�"
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
	*Fun��o calcula gastos da estrutura/pisos
	*parametros:
	*area_casa: a ser construido
	*qt_piso: quantidade de piso em m�
	*qt_cimento: quantidade de cimento em m�
	*piso: tipo de piso definido na fun��o anterior
	*/
	funcao gastos(real area_casa, real area_piso, real qt_cimento, inteiro piso)
	{
	
		real precopiso, precoferro, precoferro_316, precocimento, precolaje, VALORpiso, VALORferro, VALORferro_316, VALORcimento, VALORlaje, total
	
		faca{
			escreva("Digite o pre�o do m� do piso escolhido: ")
			leia(precopiso)
	
			se(precopiso <= 0){
				escreva("Valor inv�lido\n")
			}
	
		}enquanto(precopiso <= 0)
	
		faca{
			escreva("Digite o pre�o da barra de ferro 3/8 (unidade): ")
			leia(precoferro)
	
			se(precoferro <= 0){
				escreva("Valor inv�lido\n")
			}
	
		}enquanto(precoferro <= 0)
	
		faca{
			escreva("Digite o pre�o da barra de ferro 3/16 (unidade): ")
			leia(precoferro_316)
	
			se(precoferro_316 <= 0){
				escreva("Valor inv�lido\n")
			}
	
		}enquanto(precoferro_316 <= 0)
	
		faca{
			escreva("Digite o preco do m� do cimento: ")
			leia(precocimento)
	
			se(precocimento <= 0){
				escreva("Valor inv�lido\n")
			}
	
		}enquanto(precocimento <= 0)
	
	
		faca{
			escreva("Digite o pre�o do m� da laje: ")
			leia(precolaje)
	
			se(precolaje <= 0){
				escreva("Valor inv�lido\n")
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
				escreva("Piso: M�RMORE")
			pare
	
			caso 5:
				escreva("Piso: LAMINADO DE MADEIRA")
			pare
	
			caso 6:
				escreva("Piso: SILESTONE")
			pare
	
			caso 7:
				escreva("Piso: T�BUA CORRIDA")
			pare
	
			caso 8:
				escreva("Piso: TAC�O")
			pare
	
			caso 9:
				escreva("Piso: LAJOTA")
			pare
	
			caso 10:
				escreva("Piso: ARD�SIA")
			pare
	
			caso 11:
				escreva("Piso: CIMENTO QUEIMADO")
			pare
	
			caso 12:
				escreva("Piso: PEDRA PORTUGUESA")
			pare
	
			caso 13:
				escreva("Piso: PEDRA S�O TOM�")
			pare
	
			caso 14:
				escreva("Piso: GRANITINA")
			pare
	
		}
	
		escreva("\nGASTO TOTAL: ",total)
	
	}
	
	/*
	*Fun��o calcula gastos da estrutura/pisos -> Esta fun��o s� sera utilizada caso o piso seja digitado como uma string...
	*parametros:
	*area_casa: a ser construido
	*area_piso: quantidade de piso em m�
	*qt_cimento: quantidade de cimento em m�
	*pisoS: tipo de piso definido na fun��o anterior por STRING
	*/
	funcao gastos_cond_2(real area_casa, real area_piso, real qt_cimento, cadeia pisoS)
	{
	
		real precopiso, precoferro, precoferro_316, precocimento, precolaje, VALORpiso, VALORferro, VALORferro_316, VALORcimento, VALORlaje, total
	
	  	faca{
	        escreva("Digite o pre�o do m� do piso escolhido: ")
	        leia(precopiso)
	
	        se(precopiso <= 0){
	            escreva("Valor inv�lido\n")
	        }
	
	  	}enquanto(precopiso <= 0)
	
		faca{
			escreva("Digite o pre�o da barra de ferro 3/8 (unidade): ")
			leia(precoferro)
	
			se(precoferro <= 0){
				escreva("Valor inv�lido\n")
			}
	
		}enquanto(precoferro <= 0)
	
	  	faca{
	  		escreva("Digite o pre�o da barra de ferro 3/16 (unidade): ")
	        leia(precoferro_316)
	
	    	se(precoferro_316 <= 0){
	            escreva("Valor inv�lido\n")
	        }
	
	  	}enquanto(precoferro_316 <= 0)
	
	  	faca{
	  		escreva("Digite o preco do m� do cimento: ")
	        leia(precocimento)
	
			se(precocimento <= 0){
				escreva("Valor inv�lido\n")
			}
	
	  	}enquanto(precocimento <= 0)
	
	
	  	faca{
	        escreva("Digite o pre�o do m� da laje: ")
	        leia(precolaje)
	
			se(precolaje <= 0){
				escreva("Valor inv�lido\n")
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
	 * Calcula a �rea do telhado, onde ficar�o as telhas, considerando a inclina��o
	 *
	 * Par�metros:
	 * inclinacao: Inclina��o do telhado (altura da cumeeira)
	 * largura_base: largura da base do telhado (largura da laje)
	 * comprimento_base: comprimento da base do telhado (comprimento da laje)
	 *
	 * Retorna:
	 * A �rea do telhado
	 */
	funcao real corrigir_area(inteiro l_inclinacao, real l_largura_base, real l_comprimento_base)
	{
	
	  real altura_cumeeira = (l_inclinacao * (l_largura_base / 2) / 100)
	
	  real largura_corrigida = Matematica.raiz( Matematica.potencia( (l_largura_base / 2), 2.0 ) + Matematica.potencia( altura_cumeeira, 2.0 ), 2.0)
	
	  retorne (largura_corrigida * l_comprimento_base) * 2
	
	}
	
	/*
	 * Calcula quantidade de telhas baseado na �rea do telhado(corrigida) e a quantidade de telhas por m�
	 *
	 * Par�metros:
	 * area_telhado: �rea do telhado
	 * telhas_metro_quad: quantidade de uma telha que ocupa 1 m�
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
	 * Calcula o pre�o das telhas
	 *
	 * Par�metros:
	 * qtde: quantidade de telhas calculadas
	 * preco_unit: pre�o unit�rio da telha
	 *
	 * Retorna:
	 * O pre�o das telhas no total
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
	
	        escreva("Escolha um m�todo:\n 1 - Dimens�es da telha\n 2 - Unidades por metro quadrado\n\nSua escolha: ")
	        leia(opt)
	
	        escolha(opt)
	        {
	
	            caso 1:
	
	                escreva("\nInforme as dimens�es da telha\n")
	
	                real a_largura, a_comprimento, area_telha
	
	                //Para telhas de amianto ou alum�nio as dimens?es podem variar, por isso o usu�rio � quem entra com essas dimens?es
	                escreva(" Digite a largura da telha (cm): ")
	                leia(a_largura)
	
	                escreva(" Digite a comprimento da telha (cm): ")
	                leia(a_comprimento)
	
	                //Calcula a �rea da telha
	                area_telha = (a_largura/100) * (a_comprimento/100)
	
	                telhas_p_metro = 1 / area_telha
	
	                pare
	
	            caso 2:
	
	                escreva("\nInforme a quantidade de telha por metro quadrado: ")
	                leia(telhas_p_metro)
	
	                pare
	
	            caso contrario:
	                escreva("\nOp��o inv�lida\n\n")
	
	        }
	
	    }enquanto(opt > 2)
	
	    escreva("\nDigite o nome da telha: ")
	    leia(g_tipo_telha)
	
	    escreva("\n")
	
	    retorne telhas_p_metro
	
	}
	
	/*
	 * Calcula a quantidade total de gal?es de tinta necess�rios para pintar a �rea interna da constru��o
	 * com base nas �reas das paredes existentes na casa, na �rea total do teto, na quantidade de dem�os
	 * que se deseja aplicar e no rendimento informado no gal�o de tinta escolhido pelo usu�rio.
	 *
	 * Par�metros:
	 * (inteiro) qtde_paredes: quantidade total de paredes presente na constru��o.
	 * (real) area_tetos: �rea total do teto.
	 *
	 * Retorna:
	 * (inteiro) qtde_total_galoes: quantidade total de gal?es de tinta necess�rios para pintar a �rea interna da constru��o.
	 */
	funcao real calcula_qtde_total_galoes_tinta(real area_tetos) {
	    real qtde_total_galoes = 0.0,
	    rendimento_tinta = 0.0,
	    area_total = 0.0
	      
	    inteiro qtde_demaos = 0
	      
	    faca {
	        escreva("\nQuantidade de dem�os que ir� aplicar: ")
	        leia(qtde_demaos)
	    } enquanto (qtde_demaos <= 0)
	      
	    faca {
	        escreva("\nRendimento da tinta informado no gal�o: ")
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
	 * Calcula a quantidade de revestimento (em unidades) necess�ria para revestir internamente cada
	 * parede da constru��o com base nas �reas de cada parede e na quantidade de revestimento (em
	 * unidades) necess�ria para revestir uma �rea de um metro quadrado.
	 * Armazena a quantidade de revestimento (em unidades) necess�ria para revestir internamente cada
	 * parede em uma vari�vel respons�vel por contabilizar a quantidade total de revestimento necess�ria
	 * para revestir internamente todas as paredes presentes na constru��o.
	 *
	 * Par�metros:
	 * (inteiro) qtde_paredes: quantidade de paredes presentes na constru��o.
	 */
	funcao calcula_qtde_revestimento_por_parede() {
	
	    escreva("\n----- Quantidade de revestimento por parede (em unidades) -----")
	
	    para (inteiro i = 0; i < g_qtde_paredes; i++) {
	        inteiro parede = i+1
	        g_qtde_revestimento_por_parede[i] = Matematica.arredondar((g_qtde_revestimento_metro_quadrado * g_areas_paredes[i]), 0)
	        g_qtde_total_revestimento += g_qtde_revestimento_por_parede[i]
	        escreva("\n " + parede + "� parede: " + g_qtde_revestimento_por_parede[i])
	    }
	}
	
	/*
	 * Calcula a quantidade de revestimento (em unidades) necess�ria para preencher uma �rea de um
	 * metro quadrado com base nas medidas do revestimento utilizado, sendo estas fornecidas pelo usu�rio.
	 *
	 * Retorna:
	 * (inteiro) qtde_revestimento_por_metro_quadrado: quantidade de revestimento (em unidades) necess�rioa para
	 *       preencher uma �rea de um metro quadrado.
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
	 * Exibe op�?es de revestimento para que o usu�rio possa escolher o revestimento que
	 * deseja utilizar em sua obra.
	 *
	 * Retorna:
	 * (inteiro) tipo_revestimento: tipo de revestimento escolhido pelo usu�rio.
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
	        escreva(" 4 - Revestimento ciment�cio\n")
	        escreva(" 5 - Ladrilho hidr�ulico\n")
	        escreva(" 6 - Azulejo comum\n")
	        escreva(" 7 - Outra op��o")
	
	        escreva("\n\nSua escolha: ")
	        leia(tipo_revestimento)
	    } enquanto (tipo_revestimento<1 ou tipo_revestimento>6)
	
	    retorne tipo_revestimento
	}
	
	/*
	 * Calcula a quantidade de tijolos necess�rios para construir cada oit�o com base nas �reas dos
	 * oit?es e na quantidade de tiolos necess�rios para preencher uma �rea de um metro quadrado.
	 * Armaneza a quantidade de tijolos necess�rios por oit�o em uma vari�vel respons�vel por
	 * contabilizar a quantidade total de tijolos necess�rios para construir todas as paredes e oit?es
	 * da constru��o.
	 *
	 * Par�metros:
	 * (inteiro) qtde_tijolos_por_oit�o: vetor que armazena em cada posi��o a quantidade de tijolos necess�ria para construir um oit�o.
	 * (inteiro) qtde_oitoes: quantidade total de oit?es presentes na constru��o.
	 * (inteiro) qtde_total_tijolos: vari�vel que contabiliza a quantidade total de tijolos necess�ria para toda a constru��o.
	 * (real) areas_oit?es: vetor que armazena em casa posi��o a �rea de cada oit�o individualmente.
	
	 */
	funcao calcula_qtde_tijolos_por_oitao(inteiro qtde_tijolos_por_oitao[], inteiro qtde_oitoes, inteiro &qtde_total_tijolos, real areas_oitoes[]) {
	
	    escreva("\n\n----- Quantidade de tijolos por oit�o -----")
	
	    para (inteiro i=0; i < qtde_oitoes; i++) {
	    		inteiro oitao = i + 1
	        qtde_tijolos_por_oitao[i] = Matematica.arredondar(g_qtde_tijolo_metro_quadrado * areas_oitoes[i], 0)
	        qtde_total_tijolos += qtde_tijolos_por_oitao[i]
	        escreva("\n " + oitao + "� oit�o: " + qtde_tijolos_por_oitao[i])
	    }
	}
	
	/*
	 * Calcula a quantidade de tijolos necess�rios para construir cada parede com base nas �reas das
	 * paredes e na quantidade de tiolos necess�rios para preencher uma �rea de um metro quadrado.
	 * Armaneza a quantidade de tijolos necess�rios por parede em uma vari�vel respons�vel por
	 * contabilizar a quantidade total de tijolos necess�rios para construir todas as paredes e oit?es
	 * da constru��o.
	 *
	 * Par�metros:
	 * (inteiro) qtde_tijolos_por_parede: vetor que armazena em cada posi��o a quantidade de tijolos necess�ria para construir uma parede.
	 * (inteiro) qtde_paredes: quantidade total de paredes presentes na constru��o.
	 * (inteiro) qtde_total_tijolos: vari�vel que contabiliza a quantidade total de tijolos necess�ria para toda a constru��o.
	 */
	funcao calcula_qtde_tijolos_por_parede(real &qtde_tijolos_por_parede[]) {
	    inteiro i
	
	    escreva("\n----- Quantidade de tijolos por parede -----")
	
	    para (i=0; i<g_qtde_paredes; i++) {
	    	inteiro parede = i + 1
	        qtde_tijolos_por_parede[i] = Matematica.arredondar(g_qtde_tijolo_metro_quadrado * g_areas_paredes[i], 0)
	        g_qtde_total_tijolos += qtde_tijolos_por_parede[i]
	        escreva("\n " + parede + "� parede: " + qtde_tijolos_por_parede[i])
	    }
	}
	
	/*
	 * Calcula a quantidade de tijolos necess�rios para preencher uma �rea de um metro quadrado
	 * com base nas medidas do tijolo utilizado, sendo estas fornecidas pelo usu�rio.
	 *
	 * Retorna:
	 * (inteiro) qtde_tijolos_por_metro_quadrado: quantidade de tijolos necess�rios para preencher
	 *       uma �rea de um metro quadrado.
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
	 * Calcula a �rea de um oit�o presente na casa com base no tamanho de sua altura e base,
	 * sendo ambas as medidas fornecidas pelo usu�rio.
	 *
	 * Retorna:
	 * (real) area_oitao: �rea do oit�o.
	 */
	funcao real calcula_area_oitao() {
	    real altura_oitao = 0.0,
	          base_oitao = 0.0,
	          area_oitao = 0.0
	
	    escreva("\nAltura do oit�o em metros: ")
	    leia(altura_oitao)
	
	    escreva("Base do oit�o em metros: ")
	    leia(base_oitao)
	
	    area_oitao = ((base_oitao * altura_oitao)/2)
	
	    retorne area_oitao
	}
	
	/*
	 * Calcula a �rea de uma parede, descontando a �rea das aberturas presentes nela,
	 * como portas e janelas.
	 *
	 * Par�metros:
	 * (real) area_aberturas: �rea total das aberturas presentes na parede, como portas e janelas.
	 *
	 * Retorna:
	 * (real) area_parede: �rea da parede com a �rea das aberturas descontada.
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
	 * Calcula a �rea das aberturas presentes nas paredes, como portas e janelas, uma vez
	 * que estas devem ser descontadas posteriormente no c�culo da �rea das paredes que
	 * ir�o receber tijolos.
	 *
	 * Retorna:
	 * (real) area_aberturas: �rea total das aberturas presentes em uma parede, como portas e janelas.
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
	            escreva("\nAltura da " + abertura + "� abertura em metros: ")
	            leia(altura_abertura)
	        } enquanto (altura_abertura <= 0)
	
	        faca {
	            escreva("Comprimento da " + abertura + "� abertura em metros: ")
	            leia(comprimento_abertura)
	        } enquanto (comprimento_abertura <= 0)
	
	        area_aberturas += (altura_abertura * comprimento_abertura)
	    }
	
	    retorne area_aberturas
	}
	
	/*
	 * Exibe op�?es de tijolos para que o usu�rio possa escolher o tijolo que
	 * deseja utilizar em sua obra.
	 *
	 * Retorna:
	 * (inteiro) tipo_tijolo: tipo de tijolo escolhido pelo usu�rio.
	 */
	funcao inteiro escolhe_tipo_tijolo() {
	    inteiro tipo_tijolo
	
	    escreva("\n--------------------\n")
	    escreva("Tipos de Tijolo\n")
	    escreva("--------------------\n")
	
	    faca {
	        escreva("\nSelecione o tipo do tijolo: \n\n")
	
	        escreva(" 1 - Blocos Cer�micos\n")
	        escreva(" 2 - Tijolos Maci�os\n")
	        escreva(" 3 - Tijolos de Adobe\n")
	        escreva(" 4 - Tijolos Laminados\n")
	        escreva(" 5 - Tijolos e Blocos de Concreto\n")
	        escreva(" 6 - Tijolos Ecol�gicos\n")
	
	
	        escreva("\n\nSua escolha: ")
	        leia(tipo_tijolo)
	    } enquanto (tipo_tijolo<1 ou tipo_tijolo>4)
	
	    retorne tipo_tijolo
	}
	
	/* Conta quantas ocorrencias um determinado caracter tem em uma determinada string
	 *
	 * Par�metros:
	 * (cadeia) str: string onde o caracter ser� contado
	 * (inteiro) str_length: tamanho da string
	 * (caracter) ch: caracter que ser� contado
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
	 * Par�metros:
	 * (cadeia) string: string que ser� dividida
	 * (inteiro) vetor_destino: vetor que receber� os valores da string
	 * (caracter) delimiter: caracter que indica o ponto de divis�o
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
	 * Par�metros:
	 * (cadeia) string: string que ser� dividida
	 * (real) vetor_destino: vetor que receber� os valores da string
	 * (caracter) delimiter: caracter que indica o ponto de divis�o
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
	
	/* Unifica um vetor de reais em uma string, cada elemento sendo separado por um padr�o especificado
	 *
	 * Par�metros:
	 * (real) array: vetor que ser� unificado
	 * (inteiro) array_length: tamanho do vetor que ser� unificado
	 * (cadeia) separator: padr�o que ir� separar os elementos na string
	 *
	 * Retorna:
	 * (cadeia) string: string contendo o conte�do j� unificado do vetor
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
	 * Escreve um registro no arquivo ou atualiza esse registro se ele j� existir
	 * 
	 * Par�metros:
	 * (cadeia) dir: diret�rio  do arquivo que ser� lido
	 * (cadeia) chave: identificador do registro a ser inserido
	 * (cadeia) valor: valor do registro a ser inserido
	 * 
	 * Retorna:
	 * (inteiro) 0: erro
	 * (inteiro) 1: criou o arquivo (logo s� existe um registro)
	 * (inteiro) 2: atualizou o registro ou o arquivo j� existe e o registro foi inserido
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

	/* L� um registro do arquivo
	 * 
	 * Par�metros:
	 * (cadeia) dir: diret�rio  do arquivo que ser� lido
	 * (cadeia) chave: identificador do registro buscado
	 * 
	 * Retorna:
	 * (cadeia): valor do registro, ou nulo caso o registro ou arquivo n�o existe
	 */
	funcao cadeia ler_registro(cadeia dir, cadeia chave){
	
		se(Arquivos.arquivo_existe(dir)){
			
			inteiro arquivo = Arquivos.abrir_arquivo(dir, Arquivos.MODO_LEITURA)

			enquanto(nao Arquivos.fim_arquivo(arquivo)){

				cadeia linha = Arquivos.ler_linha(arquivo)

				se(linha != ""){

					//Extrai a chave da linha lida a partir da posi��o do espa�o divisor da chave e valor
					cadeia chave_lida = Texto.extrair_subtexto(linha, 0, Texto.posicao_texto(";", linha, 0) )
					
					se(chave_lida == chave){

						Arquivos.fechar_arquivo(arquivo)
						//Extrai o valor da chave da linha lida, a partir da posi��o do espa�o que divide a chave e o valor
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
	
		escreva("\nDigite o diret�rio para salvar o arquivo: ")
		leia(diretorio)
	
		escreva("Escolher um nome para o arquivo?\n 1 - Sim\n 2 - N�o, usar um nome gen�rico\n\nSua escolha: ")
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
				escreva("\nOcorreram ", erro, " erros ao salvar o arquivo. Deseja tentar novamente?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
		        leia(usr_opt)
			}
	
		}enquanto(usr_opt == 1)
	
	}

	
	//Segue a rotina de criar um novo or�amento
	funcao novo_orcamento()
	{
	
	    //Geral
	    inteiro usr_opt = 0 //Usada para receber as escolhas do usu�rio quando forem apresentadas op�?es
	    
	    logico chave_mestra = falso // chave de decis�o para escolha de tipo de fun��o a ser passada
	
	    caracter usr_rsp //Armazena a resposa do usu�rio quando este deve responder com 'S - Sim' ou 'N - N�o'
	
	    //ESTRUTURAS
	    //ALGORITMO PARA CALCULO DE ESTRUTURAS DA CONSTRUCAO CIVIL BASEADO NO SOLO
	    faca{
	
	        escreva("--------------------\nCIMENTO PARA ESTRUTURAS\n--------------------\n")
	
	        faca{
	
	            escreva("Digite a �rea de constru��o (em metros): ")
	            leia(g_area_total)
	
	            se(g_area_total <= 0){
	                escreva("Valor inv�lido.\n")
	            }
	
	        }enquanto(g_area_total <= 0)
	
	        faca{
	
	            escreva("Digite a profundidade das colunas de acordo com o estudo de solo (em metros): ")
	            leia(g_profundidade_colunas)
	
	            se(g_profundidade_colunas <= 0){
	                escreva("Valor inv�lido.\n")
	            }
	
	        }enquanto(g_profundidade_colunas <= 0)
	
	        faca{
	
	            escreva("Digite o di�metro das colunas(em cent�metros): ")
	            leia(g_diametro_colunas)
	
	            se(g_diametro_colunas <= 0){
	                escreva("Valor inv�lido.\n")
	            }
	
	        }enquanto(g_diametro_colunas <= 0)
	
	        g_diametro_colunas = converte(g_diametro_colunas) //Fun��o converte virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usu�rio cometa algum erro de unidade de medida
	
	        //escreva("g_diametro_colunas = %.2f\n", g_diametro_colunas) - printfs apenas para verificar a veracidade dos dados...
	
	        faca{
	
	            escreva("Digite a largura dos baldrames (em cent�metros): ")
	            leia(g_larg_bald)
	
	            se(g_larg_bald <= 0){
	                escreva("Valor inv�lido.\n")
	            }
	
	        }enquanto(g_larg_bald <= 0)
	
	         g_larg_bald = converte(g_larg_bald) //Fun��o converte virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usu�rio cometa algum erro de unidade de medida
	
	         //escreva("LARGURA = %.2f\n", g_larg_bald)
	
	        faca{
	
	            escreva("Digite a profundidade dos baldrames (em cent�metros): ")
	            leia(g_prof_bald)
	
	            se(g_prof_bald <= 0){
	                escreva("Valor inv�lido.\n")
	            }
	
	        }enquanto(g_prof_bald <= 0)
	
	        g_prof_bald = converte(g_prof_bald)//Fun��o converte virifica e corrije se necessario, retornando um valor sempre em metros, para caso o usu�rio cometa algum erro de unidade de medida
	
	        //escreva("g_profundidade_colunas = %.2f\n", g_prof_bald)
	
	        faca{
	
	            escreva("Entre com perimetro de todas as paredes da casa (em metros): ")
	            leia(g_perimetro_total)
	
	            se(g_perimetro_total <= 0){
	                escreva("Valor inv�lido.\n")
	            }
	
	        }enquanto(g_perimetro_total <= 0)
	
	        faca{
	
	            escreva("Altura das paredes: ")
	            leia(g_alt_paredes)
	
	            se(g_alt_paredes <= 0){
	                escreva("Valor inv�lido.\n")
	            }
	
	        }enquanto(g_alt_paredes <= 0)
	
	
	        g_qtde_colunas = g_perimetro_total/3
	
	        g_qtde_cimento = calcula_cimento(g_profundidade_colunas, g_diametro_colunas, g_larg_bald, g_prof_bald, g_perimetro_total, g_alt_paredes, g_qtde_colunas)//calcula e armazena o valor retornado das �reas de estruturas (CALCULO CIMENTO)
	
	        escreva("\n------\n")
	        escreva("Conclu�do.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular este or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
	        leia(usr_opt)
	
	  	} enquanto (usr_opt == 1)
	
	    faca{
	
	        escreva("\n--------------------\nOR�AMENTO DAS FERRAGENS\n--------------------\n")
	
	        calcula_ferro(g_perimetro_total, g_profundidade_colunas, g_alt_paredes, g_qtde_colunas, g_larg_bald, g_prof_bald)//fun��o calcula a quantidade necess�ria de ferro 3/8 e 3/16, armazenando os dados num vetor global.
	
	        escreva("\n------\n")
	        escreva("Conclu�do.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular este or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
	        leia(usr_opt)
	
	  	} enquanto (usr_opt == 1)
	
	  	faca{
	
	        faca{
	
	            escreva("\nDigite a �rea que deseja colocar pisos: ")
	            leia(g_area_piso)
	
	            se(g_area_piso >= g_area_total){
	                escreva("A �rea do piso n�o pode ser maior do que a �rea total!!\n")
	            }
	
	        }enquanto(g_area_piso >= g_area_total)
	
	        // escreva("Quantidade m�nima de colunas: %d\n", g_qtde_colunas)
	        // escreva("total: %.2f m� de cimento",g_qtde_cimento)
	
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
	        escreva("Conclu�do.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular este or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
	        leia(usr_opt)
	
	  	} enquanto (usr_opt == 1)
	
	    faca
	    {
	
	    	escreva("\n--------------------\nOR�AMENTO DO TELHADO\n--------------------\n")
	
	        escreva("\nBASE DO TELHADO")
	        faca
	        {
	            escreva("\n------\n\n")
	            //L� a largura e comprimento da base do telhado (laje)
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
	            //L� a inclina��o desejada para o telhado em porcentagem.
	            //Com essa inclina��o ser� calculada a altura do centro do telhado (cumeerira, onde os "lados" do telhado se dividem (/|\)).
	            //Essa porcentagem � calculada em cima da metade da largura da laje.
	            escreva(" Informe a inclina��o desejada (deve ser maior que 30%): ")
	            leia(g_inclinacao)
	
	            //Inclina��o abaixo de 30% n�o � normatizada
	            se(g_inclinacao < 30)
	            {
	                escreva("\nInclina��o inv�lida. Deve ser maior que 30%.")
	            }
	
	        }enquanto(g_inclinacao < 30)
	
	        //Calcula a �rea do telhado considerando a inclina��o
	        g_area_telhado_corrigida = corrigir_area(g_inclinacao, g_largura_base, g_comprimento_base)
	
	        //Exibe a �rea da laje e a inclina��o calculados
	        escreva("\n�rea calculada: ", g_largura_base * g_comprimento_base)
	        escreva("\nInclina��o: ", g_inclinacao)
	        escreva("\n�rea do telhado corrigida, considerando a inclina��o: ", g_area_telhado_corrigida)
	
	        escreva("\n\nTELHAS")
	        escreva("\n------\n\n")
	
	        g_qtde_telha_metro = get_telhas_metro_quad()
	
	        //Calcula a quantidade de telha
	        g_qtde_telhas = calcula_qtde_telhas(g_area_telhado_corrigida, g_qtde_telha_metro)
	
	        escreva("Quantidade aproximada de telhas: ", g_qtde_telhas, "\n")
	
	        faca
	        {
	
	            escreva("\nInforme o preco unit�rio das telhas: ")
	            leia(g_preco_unit)
	
	            se(g_preco_unit <= 0.0)
	            {
	                escreva("\nO pre�o unit�rio deve ser maior que zero.\n\n")
	            }
	
	        }enquanto(g_preco_unit <= 0.0)
	
	        //Calcula o pre�o final das telhas
	        g_custo_total = calcula_preco(g_qtde_telhas, g_preco_unit)
	
	        escreva("Custo total das telhas: R$ ", g_custo_total)
	
	        escreva("\n\nMADEIRAMENTO")
	        escreva("\n------\n\n")
	
	        //Calcula a quantidade de ter�as
	        escreva("Ter�as:\n Digite o espa�amento das ter�as (m): ")
	        leia(g_tercas_espacamento)
	
	        g_qtde_tercas = Matematica.arredondar(g_largura_base / g_tercas_espacamento, 0)
	        g_metragem_tercas = g_comprimento_base * g_qtde_tercas
	
	        escreva(" Quantidade de ter�as de ", g_comprimento_base, " metros: ", g_qtde_tercas, "\n")
	        escreva(" Quantidade de metros de ter�as: ", g_metragem_tercas)
	
	        //Calcula a quantidade de pontaletes
	        escreva("\n\nPontaletes:\n")
	
	        g_metragem_pontaletes = (
		        ( ( (g_largura_base / 2) * g_inclinacao ) / 100 ) * 2 +
		        ( ( ( (g_largura_base / 2) / 2 ) * g_inclinacao ) / 100 ) * 6 // 3 pontaletes em cada �gua
		    )
	
	        escreva(" Quantidade de metros de pontaletes: ", g_metragem_pontaletes)
	
	        //Calcula a quantidade de ber�os
	        //Para cada pontalete h� 1 ber�o de 0.5m
	        escreva("\n\nBer�os:\n Quantidade de metros de ber�os: ", 8 * 0.5)
	
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
	        escreva("Conclu�do.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular este or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
	        leia(usr_opt)
	
	    }enquanto(usr_opt == 1)
	
	    inteiro tipo_tijolo = 0, //Armazena o tipo de tijolo selecionado pelo usu�rio.
	        tipo_revesitmento = 0, //Armanzena o tipo de revestimento selecionado pelo usu�rio.
	        qtde_oitoes = 0 //Quantidade total de oit�es presentes na constru��o.
	    
		  	faca {
			    escreva("--------------------\nOR�AMENTO DOS TIJOLOS\n--------------------\n")
	
			    faca {
			        escreva("Digite a quantidade de paredes que deseja construir: ")
			        leia(g_qtde_paredes)
			    } enquanto(g_qtde_paredes <= 0)
	
			    faca {
			        escreva("\nDigite a quantidade de oit?es presentes em sua casa: ")
			        leia(qtde_oitoes)
			    } enquanto(qtde_oitoes <= 0)
	
			    real areas_oitoes[QTDE_OITOES], //Vetor que armazena a �rea unit�ria de cada oit�o em cada posi��o.
	            areas_aberturas[QTDE_PAREDES], //Vetor que armazena a �rea das aberturas presentes por parede em cada posi��o.
	            qtde_tijolos_por_parede[QTDE_PAREDES], //Vetor que armazena a quantidade de tijolos necess�ria para construir cada parede em casa posi��o.
	            qtde_tijolos_por_oitao[QTDE_OITOES] //Vetor que armazena a quantidade de tijolos necess�ria para construir cada oit�o em cada posi��o.
	
			    para (inteiro i=0; i<g_qtde_paredes; i++) {
			        inteiro parede = i + 1
	                escreva("\n----- " + parede + "� parede -----\n")
	    
			        faca {
			            escreva("\nA ", parede, "� parede apresenta aberturas como portas e janelas?")
			            escreva("\n S - Sim\n N - N�o\n")
			            escreva("Sua escolha: ")
			            leia(usr_rsp)
			        } enquanto (usr_rsp!='S' e usr_rsp!='s' e usr_rsp!='N' e usr_rsp!='n')
	
			        se (usr_rsp=='S' ou usr_rsp=='s') {
			            areas_aberturas[i] = calcula_area_aberturas()
			        } senao {
			            areas_aberturas[i] = 0.0
			        }
	
			        g_areas_paredes[i] = calcula_area_parede(areas_aberturas[i])
	
			        escreva("\n�rea da ", parede, "� parede, com as �reas das aberturas descontadas � de: ", g_areas_paredes[i], "m�\n\n")
			    }
	
			    para (inteiro i=0; i<qtde_oitoes; i++) {
			        inteiro oitao = i+1
	                escreva("\n----- " + oitao + "� oit�o -----\n")
	    
			        areas_oitoes[i] = calcula_area_oitao()
	
			        escreva("\n�rea do ", oitao, "� oit�o: ", areas_oitoes[i], "m�\n\n")
			    }
	
			    tipo_tijolo = escolhe_tipo_tijolo()
	
			    escolha (tipo_tijolo) {
			        caso 1:
			            escreva("\n--------------------\n")
			            escreva("Blocos Cer�micos\n")
			            g_tipo_tijolo = "Blocos Cer�micos"
			            pare
	
			        caso 2:
			            escreva("\n--------------------\n")
			            escreva("Tijolos Maci�os\n")
			            g_tipo_tijolo = "Tijolos Maci�os"
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
			            escreva("Tijolos Ecol�gicos\n")
			            g_tipo_tijolo = "Tijolos Ecol�gicos"
			            pare
			    }
	
			    g_qtde_tijolo_metro_quadrado = calcula_qtde_tijolos_por_metro_quadrado()
	
			    escreva("\nRendimento: ", g_qtde_tijolo_metro_quadrado, " tijolos por metro quadrado.\n")
	
			    faca {
			        escreva("\nPre�o Unit�rio do Tijolo: R$ ")
			        leia(g_preco_unit_tijolo)
			    } enquanto (g_preco_unit_tijolo <= 0)
	
			    calcula_qtde_tijolos_por_parede(qtde_tijolos_por_parede)
	
			    calcula_qtde_tijolos_por_oitao(qtde_tijolos_por_oitao, qtde_oitoes, g_qtde_total_tijolos, areas_oitoes)
	
			    g_qtde_total_tijolos += (TAXA_DE_PERDA * g_qtde_total_tijolos)
	
			    escreva("\n\n----- Quantidade total de tijolos -----")
			    escreva("\n ", g_qtde_total_tijolos, " tijolos")
	
			    g_custo_total_tijolos = g_preco_unit_tijolo * g_qtde_total_tijolos
			    escreva("\n\n----- Pre�o total - Tijolos -----")
			    escreva("\n R$ ", g_custo_total_tijolos)
	
		        escreva("\n------\n")
		        escreva("Conclu�do.")
		        escreva("\n------\n")
	
		        escreva("\nRecalcular or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
		        leia(usr_opt)
	
		  	} enquanto (usr_opt == 1)
	
		  	faca {
			    escreva("\n--------------------\nOR�AMENTO DO REVESTIMENTO DE PISO\n--------------------\n")
	
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
			            escreva("Ladrilho hidr�ulico\n")
			            g_tipo_revestimento = "Ladrilho Hidr�ulico"
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
			        escreva("\nPre�o Unit�rio do Revestimento: R$ ")
			        leia(g_preco_unit_revestimento)
			    } enquanto (g_preco_unit_revestimento <= 0)
	
			    calcula_qtde_revestimento_por_parede()
	
			    g_qtde_total_revestimento += (TAXA_DE_PERDA * g_qtde_total_revestimento)
	
			    escreva("\n\n----- Quantidade total de revestimento -----")
			    escreva("\n ", g_qtde_total_revestimento, " unidades de revestimento")
	
			    g_custo_total_revestimento = g_preco_unit_revestimento * g_qtde_total_revestimento
			    escreva("\n\n----- Pre�o total - Revestimento -----")
			    escreva("\n R$ ", g_custo_total_revestimento, "\n")
	
		        escreva("\n------\n")
		        escreva("Conclu�do.")
		        escreva("\n------\n")
	
		        escreva("\nRecalcular or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
		        leia(usr_opt)
	
		  	} enquanto (usr_opt == 1)
	
		faca {
		    escreva("\n--------------------\nOR�AMENTO DA TINTA\n--------------------\n")
	
		    real area_tetos = 0.0 //Armazena a �rea total do teto da constru��o.
	
		    faca {
		        escreva("\n�rea total do teto presente na constru��o: ")
		        leia(area_tetos)
		    } enquanto (area_tetos <= 0)
	
		    g_qtde_total_galoes_tinta = calcula_qtde_total_galoes_tinta(area_tetos)
		    g_qtde_total_galoes_tinta += Matematica.arredondar(TAXA_DE_PERDA * g_qtde_total_galoes_tinta, 0)
	
		    escreva("\n\n----- Quantidade total de gal�es de tinta -----\n")
		    escreva(g_qtde_total_galoes_tinta, " gal�es de tinta")
	
		    faca {
		        escreva("\nPre�o Unit�rio do Gal�o de Tinta: R$ ")
		        leia(g_preco_unit_galao_tinta)
		    } enquanto (g_preco_unit_galao_tinta <= 0)
	
		    g_custo_total_galao_tinta = g_preco_unit_galao_tinta * g_qtde_total_galoes_tinta
		    escreva("\n\n----- Pre�o total - Tinta -----")
		    escreva("\n R$ ", g_custo_total_galao_tinta, "\n")
	
	        escreva("\n------\n")
	        escreva("Conclu�do.")
	        escreva("\n------\n")
	
	        escreva("\nRecalcular or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
	        leia(usr_opt)
	
	  	} enquanto (usr_opt == 1)
	
	  	escreva("\n\nDeseja salvar o or�amento?\n 1 - Sim\n 2 - N�o\n\nSua escolha: ")
	  	leia(usr_opt)
	
	  	se(usr_opt == 1){
	  		salvar_dados()
	  	}
	
	  	escreva("\n\nTudo finalizado!")
	
	}
	
	funcao carregar_orcamento()
	{
	
	    cadeia dir = "",
	        linha //vari�vel usada para armazenar temporariamente o valor lido do arquivo, especificamente para os dados relativos ?s paredes, que podem ser v�rias em uma linha
	
	    inteiro ctrl = 0, i
	
	    inteiro size // Vari�vel que armazena o tamanho dos vetores dos dados realtivos as paredes
	    real areas_paredes[QTDE_PAREDES] // Vetor que ir� armazenar as �reas de cada parede  lidas dos arquivos
	    inteiro qtd_revestimento_paredes[QTDE_PAREDES] // Vetor que ir� armazenar as quantidades de revestimento de cada parede lidas dos arquivos
	
	    faca{
	        ctrl = 0
	
	        escreva("Digite o diret�rio do arquivo, incluindo o nome do arquivo: ")
	        leia(dir)
	
	        se(Arquivos.arquivo_existe(dir)){
	
	            //Estruturas
	                escreva("\n\nESTRUTURAS\n\n")
	                escreva("Profundidade das colunas: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_PROFUNDIDAE_COLUNAS)), "m\n" )
	                escreva("Di�metro das colunas: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_DIAMETRO_COLUNAS)), "m\n")
	                escreva("Perimetro total das paredes: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_PERIMETRO_TOTAL)), "m\n")
	                escreva("Largura dos baldrames: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_LARGURA_BALDRAME)), "m\n")
	                escreva("Profundidade dos baldrames: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_PROFUNDIDADE_BALDRAME)), "m\n")
	                escreva("�rea total de constru��o: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_AREA_TOTAL_CONSTRUCAO)), "m�\n")
	                escreva("Quantidade de cimento: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESTRUT_QUANTIDADE_CIMENTO)), "m�\n")
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
	
	                escreva("�rea das paredes:\n")
	
	                linha = ler_registro(dir, C_AREA_PAREDES)
	
	                size = count_char(linha, Texto.numero_caracteres(linha), '#') + 1
	                split_string_float( linha, areas_paredes, '#' )
	
	                para(i = 0; i < size; i++){
	                    escreva("  Parede ", i + 1, ": ", areas_paredes[i], "m�\n")
	                }
	
	                escreva("Tipo de tijolo: ", ler_registro(dir, C_TIJOLO_TIPO), "\n")
	                escreva("Quantidade total de tijolos: ", ler_registro(dir, C_TIJOLO_QTDE), "\n")
	                escreva("Quantidade de tijolos por m�: ", ler_registro(dir, C_TIJOLO_QTDE_METRO), "\n")
	                escreva("Custo total de tijolos: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_TIJOLO_CUSTO_TOTAL)), "\n")
	                escreva("Pre�o unit�rio do tijolo: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_TIJOLO_PRECO_UNIT)), "\n\n")
	            //Fim Tijolos
	
	            //Revestimento
	                escreva("REVESTIMENTO\n\n")
	                escreva("Tipo de revestimento: ", ler_registro(dir, C_REVESTIMENTO_TIPO), "\n")
	                escreva("Quantidade total de revestimento: ", ler_registro(dir, C_REVESTIMENTO_QTDE), "\n")
	                escreva("Quantidade de revestimento por m�: ", ler_registro(dir, C_REVESTIMENTO_QTDE_METRO), "\n")
	
	                escreva("Quantidade de revestimento por parede:\n")
	
	                linha = ler_registro(dir, C_REVESTIMENTO_POR_PAREDE)
	
	                size = count_char(linha, Texto.numero_caracteres(linha), '#') + 1
	                split_string_int( linha, qtd_revestimento_paredes, '#' )
	
	                para(i = 0; i < size; i++){
	                    escreva("  Parede ", i + 1, ": ", qtd_revestimento_paredes[i], "\n")
	                }
	
	                escreva("Custo total do revestimento: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_REVESTIMENTO_CUSTO_TOTAL)), "\n" )
	                escreva("Pre�o unit�rio do revestimento: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_REVESTIMENTO_PRECO_UNIT)), "\n\n")
	            //Fim Revestimento
	
	            //Tinta
	                escreva("TINTA\n\n")
	                escreva("Quantidade de gal�es de tinta: ", ler_registro(dir, C_GALAO_TINTA_QTDE), "\n")
	                escreva("Custo total dos gal�es de tinta: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_GALAO_TINTA_CUSTO_TOTAL)), "\n")
	                escreva("Pre�o unit�rio do gal�o de tinta: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_GALAO_TINTA_PRECO_UNIT)), "\n\n")
	            //Fim Tinta
	
	            //Telhado
	                escreva("TELHADO\n\n")
	                escreva("Inclina��o: ", ler_registro(dir, C_TELHADO_INCLINACAO), "%\n")
	                escreva("Largura da laje: ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHADO_LARGURA_BASE)), "m\n")
	                escreva("Comprimento da laje: ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHADO_COMPRIMENTO_BASE)), "m\n")
	                escreva("�rea do telhado corrigida pela inclina��o: ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHADO_AREA_CORRIGIDA)), "m�\n\n")
	            //Fim Telhado
	
	            //Madeiramento
	                escreva("MADEIRAMENTO DO TELHADO\n\n")
	                escreva("Quantidade de ter�as: ", ler_registro(dir, C_MADEIRA_QTDE_TERCA), "\n")
	                escreva("Quantidade de caibros: ", ler_registro(dir, C_MADEIRA_QTDE_CAIBRO), "\n")
	                escreva("Quantidade de ripas: ", ler_registro(dir, C_MADEIRA_QTDE_RIPAS), "\n")
	                escreva("Metros de pontaletes: ", Tipos.cadeia_para_real(ler_registro(dir, C_MADEIRA_METROS_PONTALETES)), "\n")
	                escreva("Metros de caibros: ", Tipos.cadeia_para_real(ler_registro(dir, C_MADEIRA_METROS_CAIBROS)), "\n")
	                escreva("Metros de ripas: ", Tipos.cadeia_para_real(ler_registro(dir, C_MADEIRA_METROS_RIPAS)), "\n")
	                escreva("Metros de ter�as: ", Tipos.cadeia_para_real(ler_registro(dir, C_MADEIRA_METROS_TERCAS)), "\n")
	                escreva("Espa�amento entre as ter�as: ", Tipos.cadeia_para_real(ler_registro(dir, C_ESPACAMENTO_TERCAS)), "m\n")
	                escreva("Comprimento da garga: ", Tipos.cadeia_para_real(ler_registro(dir, C_COMRPRIMENTO_GARGA)), "m\n\n")
	            //Fim madeiramento
	
	            //Telhas
	                escreva("TELHAS\n\n")
	                escreva("Tipo de telha: ", ler_registro(dir, C_TELHA_TIPO), "\n")
	                escreva("Quantidade de telhas: ", ler_registro(dir, C_TELHA_QTDE), "\n")
	                escreva("Custo total das telhas: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHA_CUSTO_TOTAL)), "\n")
	                escreva("Pre�o unit�rio das telhas: R$ ", Tipos.cadeia_para_real(ler_registro(dir, C_TELHA_PRECO_UNIT)), "\n\n")
	            //Fim Telhas
	
	        }
	        senao{
	            escreva("\nO arquivo informado n�o existe.\n\n")
	            ctrl = 1
	        }
	
	    }enquanto(ctrl == 1)
	}
	
	//Exibe ajuda sobre o programa
	funcao ajuda()
	{
		
	     escreva("AJUDA\n-----\n�ndice:\n")
	     escreva("1 - INCLINA��O DO TELHADO\n")
	     escreva("2 - MADEIRAMENTO DO TELHADO\n")
	     escreva("3 - MODELOS DE TELHAS\n")
	  	escreva("4 - MODELOS DE TIJOLOS\n")
	  	escreva("5 - MODELOS DE REVESTIMENTO PARA PAREDE\n")
	  	escreva("6 - MODELOS DE PISO")
	
	    escreva("\n* Voc� pode usar as teclas num�ricas para navegar pelos itens.\n\n\n")
	
	    escreva("1. INCLINA��O DO TELHADO\n------------------------>\n")
	
	    escreva("* Pressione F1 para uma imagem ilustrativa.\n\n")

	    escreva(" A inclina��o do telhado � calculada com base na largura da laje (dividida por dois no\ncaso de telhado com duas �guas).O valor para a inclina��o � fornecido em porcentagem,\nessa porcentagem corresponde a por��o da base que ser� espelhada para compor a cumeeira.\n")
	    escreva(" Por exemplo, um telhado com base (laje) 12x10m, com inclina��o de 30% e duas �guas, temos:\n")
	    escreva("  a. Calculamos a metade da largura da base, nesse caso 6 (12/2 = 6);\n")
	    escreva("  b. Calculamos 30% do valor achado anteriormente, ficando com 1.8m (6 * 0.3 = 1.8).\n     Essa ser�a altura da cumeeira.\n\n")
	
	    escreva("\n2. MADEIRAMENTO DO TELHADO\n-------------------------->\n")
	
	    escreva("* Pressione F2 para uma imagem ilustrativa.\n\n")
	
	    escreva(" O madeiramento do telhado contempla toda a madeira usada para dar sustenta��o ao telhado:\n")
	    escreva(". Ter�a;\n. Pontalete;\n. Ber�o;\n. M�o Francesa;\n. Trama:\n  . Caibro;\n  . Ripas.\n\n")
	
	    escreva("\n3. MODELOS DE TELHAS\n-------------------->\n")
	
	    escreva("* Pressione F3 para uma imagem ilustrativa.\n\n")
	
	    escreva("\n TELHA PORTUGUESA\n----------------->\n")
	
	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 17 pe�as por metro quadrado\n")
	    escreva("   Dimens�es: 38x20")
	    escreva("   Peso: 2,6 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 35%\n\n")
	
	    escreva("\n TELHA ROMANA\n------------->\n")
	
	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 16 pe�as por metro quadrado\n")
	    escreva("   Dimens�es: 40x21")
	    escreva("   Peso: 2,7 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 35%\n\n")
	
	    escreva("\n TELHA AMERICANA\n---------------->\n")
	
	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 12 pe�as por metro quadrado\n")
	    escreva("   Dimens�es: 46x26cm")
	    escreva("   Peso: 2,9 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 30%\n\n")
	
	    escreva("\n TELHA FRANCESA\n--------------->\n")
	
	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 16 pe�as por metro quadrado\n")
	    escreva("   Dimens�es: 38x24")
	    escreva("   Peso: 2,8 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 45%\n\n")
	
	    escreva("\n TELHA ITALIANA\n--------------->\n")
	
	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 13 pe�as por metro quadrado\n")
	    escreva("   Dimens�es: 45x26")
	    escreva("   Peso: 3,4 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 30%\n\n")
	
	    escreva("\n TELHA GERM�NICA\n---------------->\n")
	
	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 40 pe�as por metro quadrado\n")
	    escreva("   Dimens�es:\n\tnormal 36x18,5cm\n\tcurta 24x18,5cm")
	    escreva("   Peso: 1,16 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 30%\n\n")
	
	    escreva("\n TELHA HOLANDESA\n---------------->\n")
	
	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 17 pe�as por metro quadrado\n")
	    escreva("   Dimens�es: 41x24cm")
	    escreva("   Peso: 2,5 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 30%\n\n")
	
	    escreva("\n TELHA URUGUAIA\n--------------->\n")

	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 16 pe�as por metro quadrado\n")
	    escreva("   Dimens�es: 28x19,5cm")
	    escreva("   Peso: 1 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 45%\n\n")
	
	    escreva("\n TELHA PLAN\n----------->\n")

	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 26 pe�as por metro quadrado\n")
	    escreva("   Dimens�es:\n\tcapa 48x16cm\n\tcanal: 48x19cm")
	    escreva("   Peso: 2,3 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 30%\n\n")
	
	    escreva("\n TELHA PAULISTA\n--------------->\n")

	    escreva("   Material: Cer�mica\n")
	    escreva("   Quantidade: 22 pe�as por metro quadrado\n")
	    escreva("   Dimens�es:\n\tcapa 48x17cm\n\tcanal: 48x20cm")
	    escreva("   Peso: 2,2 Kg por pe�a\n")
	    escreva("   Inclina��o M�nima: 30%\n")
	
	    escreva("\n\n4. MODELOS DE TIJOLOS\n--------------------->\n")
	
	    escreva("* Pressione F4 para uma imagem ilustrativa.\n\n")
	
	    escreva("\n BLOCO CER�MICO\n--------------->\n")
	
	  	escreva("   Os blocos cer�micos s�o feitas � base de argila cozida e s�o um itens mais utilizados na\nconstru��o de paredes de alvenaria, podendo haver varia��es em rela��o ao n�mero de furos e\ntamanho, sendo que os maiores s�o indicados para esturutras maiores.\n")
	  	escreva("   Os blocos furados s�o mais leves e baratos, por�m, s�o mais vulner�veis a quebras durante\na obra.")
	  	escreva("   � importante destacar que este material n�o � estrutural, ou seja, pode ser utilizado\napenas para o fechamento e n�o para sustenta��o de cobertura ou laje.\n")
	
	    escreva("\n TIJOLOS MACI�OS\n---------------->\n")
	
	    escreva("   Os tijolos maci�os s�o feitos � base de argila cozida e s�o um dos itens mais utilizados\nna constru��o de paredes de alvenaria.\n")
	  	escreva("   Possuem mais resist�ncia com rela��o aos blocos cer�micos, podendo ser deixados aparentes\nou serem divididos ao meio para serem usados como revestimento para as paredes.\n")
	
	    escreva("\n TIJOLOS DE ADOBE\n----------------->\n")
	
	    escreva("   S�o basicamente uma mistura de terra e �gua, com acr�scimo de palhas ou outros materiais\norg�nicos, feitos atrav�s de processo artesanal ou semi-industrial de moldagem e secagem.\n")
	  	escreva("   � um tijolo ecol�gico, porque dispensa o cozimento que gasta muita energia e emite muitos\ngases, mas n�o � muito resistente a interp�ries como chuva e vento, pois absorve muita �gua\ne pode se desfazer em contato direto e intenso com chuva.\n")
	
	    escreva("\n TIJOLOS LAMINADOS\n------------------>\n")
	
	    escreva("   Esta pe�a tamb�m � conhecida como tijolo de 21 furos devido � quantidade de orif�cios que\napresenta.\n")
	  	escreva("   Este tipo de tijolo apresenta melhor ader�ncia de argamassa, possibilitando uma estrutura\nmais firme e tamb�m tem alta durabilidade.\n")
	  	escreva("   Indica-se utilizar o modelo horizontalmente, para que apenas a parte lisa fique � mostra.\n� muito comum a utiliza��o deste tipo de tijolo em projetos com tijolo aparente, como fachadas,\npor exemplo.\n")
	
	    escreva("\n TIJOLOS E BLOCOS DE CONCRETO\n----------------------------->\n")
	
	    escreva("   Apresenta uma estrutura mais robusta, sendo comumente utilizado em constru��es maiores e\ntamb�m em alicerces para casas.\n")
		escreva("   A vantagem na utiliza��o de tijolos ou blocos de concreto � com rela��o � economia no consumo\nde argamassa, pois sua anatomia facilita a jun��o das pe�as.\n")
	
	  	escreva("\n TIJOLOS ECOL�GICOS\n------------------->\n")
	
	    escreva("   Produzido a partir de uma mistura de solo, cimento e �gua, � uma pe�a muito utilizada em\nconstru��es sustent�veis devido a sua tend�ncia ecol�gica.\n")
	  	escreva("   Suas vantagens s�o o baixo consumo de argamassa, isolamento t�rmico e ac�stico, f�cil encaixe\ne possibilidade de ficar aparente.\n")
		escreva("   Por�m, � uma pe�a que necessita de um profissional especializado e tamb�m n�o � indicada para\nlocais muito �midos.\n")
	
	  	escreva("\n\n5. MODELOS DE REVESTIMENTO PARA PAREDE\n-------------------------------------->\n")
	
	    escreva("* Pressione F5 para uma imagem ilustrativa.\n\n")
	
	    escreva("\n PAPEL DE PAREDE\n---------------->\n")
	
	    escreva("   Revestimento simples, facilmente encontrado e de f�cil instala��o.\n")
	  	escreva("   Este tipo de revestimento � indicado para regi�es e ambientes menos �midos, sendo assim,\n� ideal evitar a utiliza��o de papel de parede em banheiros e cozinhas.\n")
	
	    escreva("\n MADEIRA\n-------->\n")
	
	    escreva("   Este tipo de material possui uma grande variedade de cores e tonalidades e ajuda a\naquecer os c�modos, mantendo uma temperatura agrad�vel no ambiente.\n")
	
	    escreva("\n PASTILHAS\n---------->\n")
	
	    escreva("   As pastilhas s�o pequenas pe�as que podem ser feitas de cer�mica, resina ou vidro e\ns�o aplicadas �s paredes como se fossem pequenos azulejos.\n")
	
		escreva("\n LADRILHO HIDR�ULICO\n-------------------->\n")
	
	    escreva("   S�o azulejos que podem apresentar varia��es nos tamanhos, mas muito conhecidos por\nsuas estampas coloridas e bem detalhadas.\n")
	
	  	escreva("\n AZULEJO COMUM\n-------------->\n")
	
	    escreva("   S�o azuelejos que se apresentam no mesmo formato dos ladrilhos hidr�ulicos, um pouco\nmaiores �s vezes, mas n�o possuem um diferencial em espec�fico.\n")
	
	    escreva("\n\n6. TIPOS DE PISO\n---------------->\n")
	
	    escreva("* Pressione F6 para uma imagem ilustrativa.\n\n")
	
	    escreva("\n CER�MICO\n--------->\n")
	
	    escreva("   A cer�mica � o tipo de piso mais conhecido e usado no Brasil. S�o encontradas de\nv�rios tamanhos (desde 20�30, 40�40, 60�60, 80�80, 100�100), texturas, qualidades e pre�os. Podem ser\nutilizadas em �reas internas e externas.\n")
	
	    escreva("\n PORCELANATO\n------------>\n")
	
	    escreva("   O Porcelanato � produzido em massa �nica j� na sua colora��o e com mat�rias-primas\nnobres.Podem ser semi-polidos, polidos e pe�a r�stica. Tamb�m h� os porcelanatos esmaltados e os\nporcelanatos digitais polidos com a mais alta qualidade e com v�rias texturas, principalmente imitando\nmadeiras, m�rmores e granitos.\n")
	
	    escreva("\n GRANITO\n-------->\n")
	
	    escreva("   O granito � uma pedra muito indicada para pisos devido a sua beleza, resist�ncia\ne durabilidade. S�o utilizados desde resid�ncias at� em locais com grande movimenta��o de pessoas\ncomo shoppings, supermercados, aeroportos, etc. Possuem v�rias tonalidades e quanto mais raro mais caro.\n")
	
	    escreva("\n M�RMORE\n-------->\n")
	
	    escreva("   O m�rmore tamb�m � uma rocha metam�rfica, composta principalmente por minerais\nde calcita com colara��o mais uniforme e forma��o de veios definidos. � indicado para utiliza��o em\nambientes internos apenas.\n")
	
	    escreva("\n LAMINADO DE MADEIRA\n-------------------->\n")
	
	    escreva("   Esse piso tem esse nome porque s�o constitu�dos de l�minas de madeira. � um tipo\nde piso flutuante porque n�o � colado no contrapiso. S�o assentados sobre manta, em sistema de encaixe\ntipo click e presos pelos rodap�s que s�o colados.S�o sustent�veis por serem de madeira reflorestada.\n")
	
	    escreva("\n SILESTONE\n---------->\n")
	
	    escreva("   Silestone � um material composto por grande quantidade de quartzo, outros minerais\nem menor escala, resina de poli�ster e pigmentos. Com porosidade nula, possui v�rias texturas e um\ncusto muito elevado.\n")
	
	    escreva("\n T�BUA CORRIDA\n-------------->\n")
	
	    escreva("  Piso em madeira natural de lei, geralmente extra�da da Amaz�nia. Conferem muita beleza\ne conforto, mas n�o s�o sustent�veis. Sua instala��o � sobre um ripamento e possuem encaixe tipo\nmacho-f�mea.\n")
	
	    escreva("\n TAC�O\n------>\n")
	
	    escreva("   Os tacos foram sucesso nos anos 1960 a 1980. Atualmente s�o utilizados em ambientes mais\nespec�ficos e possuem custo elevado. Assim como a t�bua corrida, necessitam de raspar e\nsintecar. As madeiras mais comuns para tac�o s�o a gr�pia, cumaru e ip�.\n")
	
	    escreva("\n LAJOTA\n------->\n")
	
	    escreva("   Instaladas tanto em paredes internas como em fachadas, as lajotas apresentam in�meras\nvantagens, entre elas a �tima resist�ncia �s varia��es clim�ticas, a beleza e a rela��o\ncusto X benef�cio. As pe�as est�o cada vez mais inovadoras, com formas geom�tricas variadas e com pinturas\nde desenhos que conferem um charme todo especial ao ambiente.\n")
	
	    escreva("\n ARD�SIA\n-------->\n")
	
	    escreva("   Piso em pedra ard�sia foi largamente utilizado nos anos 1980 devido a sua durabilidade e\nbaixo custo. Podem ser utilizadas em pisos internos de �reas molhadas e �reas externas.\n")
	
	    escreva("\n CIMENTO QUEIMADO\n----------------->\n")
	
	    escreva("   Solu��o de baixo custo para pisos e quando bem feita confere �timo acabamento. Indicado\ntanto para �reas internas quanto para �reas externas. Muito utilizado em bares, boates e\ngalp�es industriais.\n")
	
	    escreva("\n PEDRA PORTUGUESA\n----------------->\n")
	
	    escreva("   Muito utilizadas em cal�adas a pedra portuguesa mais famosa do mundo � o cal�ad�o de\nCopacabana no Rio de Janeiro. A execu��o do trabalho � bastante demorada porque cada pedra �\nassentada uma a uma.\n")
	
	    escreva("\n PEDRA S�O TOM�\n--------------->\n")
	
	    escreva("  Com v�rios outros nomes pelo Brasil afora a Pedra S�o Tom� � o piso mais utilizado ao\nredor das piscinas. S�o vendidas em regulares 30x30cm e irregulares (retalhos).\n")
	
	    escreva("\n GRANITINA\n---------->\n")
	
	    escreva("  A granitina � uma massa de cimento misturada com pequenas pedrinhas de granito aplicadas\nno piso. Ap�s a cura do piso � polida com discos diamantados que conferem uma superf�cie\nlisa e brilhante. O piso em granitina � muito utilizado em �reas internas e externas de clubes, escolas,\naeroportos.\n")
	
	}
	
	funcao inicio()
	{
	
	    inteiro usr_opt
	
	    faca{
	
	        escreva("Selecione uma a��o:\n 1 - Criar um novo or�amento\n 2 - Visualizar um or�amento existente\n 3 - Ajuda\n\nSua escolha: ")
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
	                escreva("\nOp��o inv�lida\n\n")
	        }
	
	        escreva("\n\n")
	
	    }enquanto(verdadeiro)
	
	}

}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 66078; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */