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
	funcao real corrigir_area(inteiro inclinacao, real largura_base, real comprimento_base)
	{
	
		real altura_cumeeira = (inclinacao / 100) * (largura_base / 2)
		
		real largura_corrigida = mat.raiz( mat.potencia( (largura_base / 2), 2.0 ) + mat.potencia( altura_cumeeira, 2.0 ), 2.0)
		
		retorne (largura_corrigida * comprimento_base) * 2
	
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
	funcao inteiro calcula_qtd_telhas(real area_telhado, real telhas_metro_quad)
	{
	
		inteiro qtd_telhas = 0
		
		qtd_telhas = tipos.real_para_inteiro( mat.arredondar( (area_telhado * telhas_metro_quad), 0) )
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
	funcao real calcula_preco(inteiro qtd, real preco_unit)
	{
		retorne qtd * preco_unit
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
		
		//Telhado
		inteiro inclinacao = 0//Inclinação do telhado
		
		real largura_base = 0.0,//Largura da base do telhado (laje)
		comprimento_base = 0.0,//Comprimento da base do telhado (laje)
		area_telhado_corrigida = 0.0//Área do telhado corrigida já incluindo a inclinação do teclado
		
		//Telhas
		inteiro qtd_telhas = 0//Quantidade de telhas no total
		
		real custo_total = 0.0,//Custo total das telhas no final
		preco_unit = 0.0,//Preço unitário de cada telha
		qtd_telha_metro = 0.0//Quantidade de telhas por metro quadrado
		
		//Madeiramento
		inteiro qtd_tercas = 0, //Quantidade de terças para as duas águas do telhado
		qtd_caibros = 0,// Quantidade de caibros para o telhado
		qtd_ripas = 0 //Quantidade de ripas para o telhado
		
		real tercas_espacamento = 0.0, //Espaçamento entre as terças
		metragem_pontaletes = 0.0,
		metragem_caibros = 0.0,
		metragem_ripas = 0.0,
		metragem_tercas = 0.0,
		comprimento_garga = 0.0
		
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
				leia(largura_base)
				
				escreva(" Digite o comprimento da base do telhado(m): ")
				leia(comprimento_base)
				
				se(largura_base <= 0 ou comprimento_base <= 0)
				{
					escreva("\nA largura e comprimento da base devem ser ambos maiores que zero.\n")
				}
			
			}enquanto(largura_base <= 0 ou comprimento_base <= 0)
			
			faca
			{
				//Lê a inclinação desejada para o telhado em porcentagem.
				//Com essa inclinação será calculada a altura do centro do telhado (cumeerira, onde os "lados" do telhado se dividem (/|\)).
				//Essa porcentagem é calculada em cima da metade da largura da laje.
				escreva(" Informe a inclinação desejada (deve ser maior que 30%): ")
				leia(inclinacao)
				
				//Inclinação abaixo de 30% não é normatizada
				se(inclinacao < 30)
				{
					escreva("\nInclinação inválida. Deve ser maior que 30%.")
				}
			
			}enquanto(inclinacao < 30)
			
			//Exibe a área da laje e a inclinação calculados
			escreva("\nÁrea calculada: ", (largura_base * comprimento_base) )
			escreva("\nInclinação: ", inclinacao, "%")
			
			escreva("\n\nTELHAS")
			escreva("\n------\n\n")
			
			qtd_telha_metro = get_telhas_metro_quad()
			
			//Calcula a área do telhado considerando a inclinação
			area_telhado_corrigida = corrigir_area(inclinacao, largura_base, comprimento_base)
			
			//Calcula a quantidade de telha
			qtd_telhas = calcula_qtd_telhas(area_telhado_corrigida, qtd_telha_metro)
			
			escreva("Área do telhado corrigida, considerando a inclinação: ", area_telhado_corrigida)
			escreva("\nQuantidade aproximada de telhas: ", qtd_telhas, "\n")
			
			faca
			{
				
				escreva("Informe o preco unitário do tipo de telha escolhido: ")
				leia(preco_unit)
				
				se(preco_unit <= 0.0)
				{
					escreva("\nO preço unitário deve ser maior que zero.\n\n")
				}
			
			}enquanto(preco_unit <= 0.0)
			
			//Calcula o preço final das telhas
			custo_total = calcula_preco(qtd_telhas, preco_unit)
			
			escreva("Custo total das telhas: R$ ", custo_total)
			
			escreva("\n\nMADEIRAMENTO")
			escreva("\n------\n\n")
			
			//Calcula a quantidade de terças
			escreva("Terças:\n Digite o espaçamento das terças (m): ")
			leia(tercas_espacamento)
			
			qtd_tercas = tipos.real_para_inteiro( mat.arredondar( (largura_base / tercas_espacamento), 0) )
			metragem_tercas = comprimento_base * qtd_tercas
			
			escreva(" Quantidade de terças de ", comprimento_base, " metros: ", qtd_tercas, "\n")
			escreva(" Quantidade de metros de terças: ", metragem_tercas)
			
			//Calcula a quantidade de pontaletes
			escreva("\n\nPontaletes:\n")
			
			metragem_pontaletes = (
				( (largura_base / 2) * inclinacao ) * 2 +
				( ( (largura_base / 2) / 2 ) * inclinacao ) * 6 // 3 pontaletes em cada água
			)
			
			escreva(" Quantidade de pontaletes (m): ", metragem_pontaletes)
			
			//Calcula a quantidade de berços
			//Para cada pontalete há 1 berço de 0.5m
			escreva("\n\nBerços:\n Quantidade de berços (m): ", (6 * 0.5) )
			
			//Calcula a quantidade de madeira para a trama, que inclui os caibros e as ripas
			escreva("\n\nTrama:\n")
			
			//Calcula a quantidade de caibros
			escreva(" Caibros:\n")
			
			real altura_cumeeira = (inclinacao / 100) * (largura_base / 2)
			
			qtd_caibros = tipos.real_para_inteiro( mat.arredondar( ( (comprimento_base / 0.5) * 2 ), 0) )
			
			metragem_caibros = qtd_caibros * (largura_base / 2)
			
			escreva("  Quantidade de caibros: ", qtd_caibros, "\n")
			escreva("  Quantidade de metros de caibro: ", metragem_caibros )
			
			//Calcula a quantidade de ripas
			
			escreva("\n Ripas:\n")
			
			escreva("  Digite o comprimento da garga: ")
			leia(comprimento_garga)
			
			qtd_ripas = 2 * tipos.real_para_inteiro( mat.arredondar( ( (largura_base / 2) / comprimento_garga), 0) )
			metragem_ripas = qtd_ripas * comprimento_base
			
			escreva("  Quantidade de ripas: ", qtd_ripas, "\n")
			escreva("  Quantidade de metros de ripas: ", metragem_ripas, "\n")
			
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
 * @POSICAO-CURSOR = 5079; 
 * @DOBRAMENTO-CODIGO = [95];
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */