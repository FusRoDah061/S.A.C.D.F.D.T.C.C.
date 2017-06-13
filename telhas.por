programa
{
	
	inclua biblioteca Matematica --> mat
	inclua biblioteca Tipos --> tipos
	
	//Constantes correspondentes as chaves que serão salvas no arquivo
	//Telhas
	const cadeia C_TELHA_TIPO = "tipo_telha"
	const cadeia C_TELHA_QTD = "qtd_telha"
	const cadeia C_TELHA_CUSTO_TOTAL = "custo_telha"
	const cadeia C_TELHA_PRECO_UNIT = "preco_unit_telha"
	//Telhado
	const cadeia C_TELHADO_INCLINACAO = "inclinacao"
	const cadeia C_TELHADO_LARGURA_BASE = "larg_base"
	const cadeia C_TELHADO_COMPRIMENTO_BASE = "compr_base"
	const cadeia C_TELHADO_AREA_CORRIGIDA = "area_corr_base"
	//Madeiramento
	const cadeia C_MADEIRA_QTD_TERCA = "qtd_terca"
	const cadeia C_MADEIRA_QTD_CAIBRO = "qtd_caibro"
	const cadeia C_MADEIRA_QTD_RIPAS = "qtd_ripa"
	const cadeia C_MADEIRA_METROS_PONTALETES = "metros_pontalete"
	const cadeia C_MADEIRA_METROS_CAIBROS = "metros_caibro"
	const cadeia C_MADEIRA_METROS_RIPAS = "metros_ripas"
	const cadeia C_MADEIRA_METROS_TERCAS = "metros_tercas"
	const cadeia C_ESPACAMENTO_TERCAS = "espacamento_terca"
	const cadeia C_COMRPRIMENTO_GARGA = "compr_garga"
	
	const inteiro C_QTD_DADOS = 16

	//Dados a serem gravados no arquivo
	//Telhado
	inteiro g_inclinacao = 0//Inclinação do telhado
	
	real g_largura_base = 0.0,//Largura da base do telhado (laje)
	g_comprimento_base = 0.0,//Comprimento da base do telhado (laje)
	g_area_telhado_corrigida = 0.0//Área do telhado corrigida já incluindo a inclinação do teclado
	
	//Telhas
	inteiro g_qtd_telhas = 0//Quantidade de telhas no total
	
	real g_custo_total = 0.0,//Custo total das telhas no final
	g_preco_unit = 0.0,//Preço unitário de cada telha
	g_qtd_telha_metro = 0.0//Quantidade de telhas por metro quadrado
	
	//Madeiramento
	inteiro g_qtd_tercas = 0, //Quantidade de terças para as duas águas do telhado
	g_qtd_caibros = 0,// Quantidade de caibros para o telhado
	g_qtd_ripas = 0 //Quantidade de ripas para o telhado
	
	real g_tercas_espacamento = 0.0, //Espaçamento entre as terças
	g_metragem_pontaletes = 0.0,
	g_metragem_caibros = 0.0,
	g_metragem_ripas = 0.0,
	g_metragem_tercas = 0.0,
	g_comprimento_garga = 0.0
	
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
		
		real largura_corrigida = mat.raiz( mat.potencia( (l_largura_base / 2), 2.0 ) + mat.potencia( altura_cumeeira, 2.0 ), 2.0)
		
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
	funcao inteiro calcula_qtd_telhas(real l_area_telhado, real l_telhas_metro_quad)
	{
	
		inteiro qtd_telhas = 0
		
		qtd_telhas = tipos.real_para_inteiro( mat.arredondar( (l_area_telhado * l_telhas_metro_quad), 0) )
		qtd_telhas += tipos.real_para_inteiro( mat.arredondar( (qtd_telhas * 0.05), 0) )
		
		retorne qtd_telhas
	
	}
	
	/*
	* Calcula o preço das telhas
	*
	* Parâmetros:
	* qtd: quantidade de telhas calculadas
	* preco_unit: preço unitário da telha
	*
	* Retorna:
	* O preço das telhas no total
	*/
	funcao real calcula_preco(inteiro l_qtd, real l_preco_unit)
	{
		retorne l_qtd * l_preco_unit
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
					
					//Para telhas de amianto ou alumínio as dimensões podem variar, por isso o usuário é quem entra com essas dimensões
					escreva(" Digite a largura da telha (cm): ")
					leia(a_largura)
					
					escreva(" Digite a comprimento da telha  (cm): ")
					leia(a_comprimento)
					
					//Calcula a área da telha
					area_telha = a_largura/100 * a_comprimento/100
					
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
		
		escreva("\n")
		
		retorne telhas_p_metro
		
	}
	
	funcao inicio()
	{
	
		//Geral
		inteiro usr_opt = 0, //Usada para receber as escolhas do usuário quando forem apresentadas opções
		erros = 0//Contador de erros ao salvar e ler um arquivo
	
		faca
		{
			limpa()
			
			escreva("--------------------\nORÇAMENTO DO TELHADO\n--------------------\n")
			
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
			escreva("\nÁrea calculada: ", (g_largura_base * g_comprimento_base) )
			escreva("\nInclinação: ", g_inclinacao, "%")
			escreva("\nÁrea do telhado corrigida, considerando a inclinação: ", g_area_telhado_corrigida)
			
			escreva("\n\nTELHAS")
			escreva("\n------\n\n")
			
			g_qtd_telha_metro = get_telhas_metro_quad()
						
			//Calcula a quantidade de telha
			g_qtd_telhas = calcula_qtd_telhas(g_area_telhado_corrigida, g_qtd_telha_metro)
			
			escreva("\nQuantidade aproximada de telhas: ", g_qtd_telhas, "\n")
			
			faca
			{
				
				escreva("Informe o preco unitário do tipo de telha escolhido: ")
				leia(g_preco_unit)
				
				se(g_preco_unit <= 0.0)
				{
					escreva("\nO preço unitário deve ser maior que zero.\n\n")
				}
			
			}enquanto(g_preco_unit <= 0.0)
			
			//Calcula o preço final das telhas
			g_custo_total = calcula_preco(g_qtd_telhas, g_preco_unit)
			
			escreva("Custo total das telhas: R$ ", g_custo_total)
			
			escreva("\n\nMADEIRAMENTO")
			escreva("\n------\n\n")
			
			//Calcula a quantidade de terças
			escreva("Terças:\n Digite o espaçamento das terças (m): ")
			leia(g_tercas_espacamento)
			
			g_qtd_tercas = tipos.real_para_inteiro( mat.arredondar( (g_largura_base / g_tercas_espacamento), 0) )
			g_metragem_tercas = g_comprimento_base * g_qtd_tercas
			
			escreva(" Quantidade de terças de ", g_comprimento_base, " metros: ", g_qtd_tercas, "\n")
			escreva(" Quantidade de metros de terças: ", g_metragem_tercas)
			
			//Calcula a quantidade de pontaletes
			escreva("\n\nPontaletes:\n")
			
			g_metragem_pontaletes = (
				( ( (g_largura_base / 2) * g_inclinacao ) / 100 ) * 2 +
				( ( ( (g_largura_base / 2) / 2 ) * g_inclinacao ) / 100 ) * 6 // 3 pontaletes em cada água
			)
			
			escreva(" Quantidade de metros pontaletes (m): ", g_metragem_pontaletes)
			
			//Calcula a quantidade de berços
			//Para cada pontalete há 1 berço de 0.5m
			escreva("\n\nBerços:\n Quantidade de metros de berços (m): ", (8 * 0.5) )
			
			//Calcula a quantidade de madeira para a trama, que inclui os caibros e as ripas
			escreva("\n\nTrama:\n")
			
			//Calcula a quantidade de caibros
			escreva(" Caibros:\n")
			
			real altura_cumeeira = (g_inclinacao / 100) * (g_largura_base / 2)
			
			g_qtd_caibros = tipos.real_para_inteiro( mat.arredondar( ( (g_comprimento_base / 0.5) * 2 ), 0) )
			
			g_metragem_caibros = g_qtd_caibros * (g_largura_base / 2)
			
			escreva("  Quantidade de caibros: ", g_qtd_caibros, "\n")
			escreva("  Quantidade de metros de caibro: ", g_metragem_caibros )
			
			//Calcula a quantidade de ripas
			
			escreva("\n Ripas:\n")
			
			escreva("  Digite o comprimento da garga em metros: ")
			leia(g_comprimento_garga)
			
			g_qtd_ripas = 2 * tipos.real_para_inteiro( mat.arredondar( ( (g_largura_base / 2) / g_comprimento_garga), 0) )
			g_metragem_ripas = g_qtd_ripas * g_comprimento_base
			
			escreva("  Quantidade de ripas: ", g_qtd_ripas, "\n")
			escreva("  Quantidade de metros de ripas: ", g_metragem_ripas, "\n")
			
			escreva("\n------\n")
			escreva("Concluído.")
			escreva("\n------\n")
			
			escreva("\nRecalcular orçamento?\n 1 - Sim\n 2 - Não\n\nSua escolha: ")
			leia(usr_opt)
		
		}enquanto(usr_opt == 1)
	
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 9217; 
 * @DOBRAMENTO-CODIGO = [79, 89, 101, 111, 116, 122];
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */