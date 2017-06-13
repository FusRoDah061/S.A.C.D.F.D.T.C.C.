programa
{
	inclua biblioteca Arquivos
	inclua biblioteca Texto
	inclua biblioteca Tipos

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
					
					cadeia chave_lida = Texto.extrair_subtexto(linha, 0, Texto.posicao_texto(" ", linha, 0) )
					
					se(chave_lida == chave){
						
						conteudo_arquivo += chave + " " + valor + "#"
						atualizou = verdadeiro
						
					}
					senao{
						
						conteudo_arquivo += linha + "#"
						
					}

					ac_linhas++
					
				}
				
			}enquanto(nao Arquivos.fim_arquivo(arquivo))

			se(nao atualizou){ 
				
				conteudo_arquivo += chave + " " + valor + "#"
				ac_linhas++
				
			}

			Arquivos.fechar_arquivo(arquivo)

			arquivo = Arquivos.abrir_arquivo(dir, Arquivos.MODO_ESCRITA)

			inteiro ultima_pos = 0
			para(inteiro i = 0; i < ac_linhas; i++){
				
				inteiro fim = Texto.posicao_texto("#", conteudo_arquivo, ultima_pos)
				
				cadeia linha = Texto.extrair_subtexto(conteudo_arquivo, ultima_pos, fim)
				
				Arquivos.escrever_linha(linha + "\n", arquivo)

				ultima_pos = fim + 1
				
			}
		
			Arquivos.fechar_arquivo(arquivo)
			
			retorne 2
			
		}
		senao{
			
			inteiro arquivo = Arquivos.abrir_arquivo(dir, Arquivos.MODO_ESCRITA)

			Arquivos.escrever_linha(chave + " " + valor + "\n", arquivo)

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
					cadeia chave_lida = Texto.extrair_subtexto(linha, 0, Texto.posicao_texto(" ", linha, 0) )
					
					se(chave_lida == chave){
						//Extrai o valor da chave da linha lida, a partir da posição do espaço que divide a chave e o valor
						retorne Texto.extrair_subtexto(linha, Texto.posicao_texto(" ", linha, 0) + 1,  Texto.numero_caracteres(linha))
						
					}
					
				}
				
			}
			
		}

		retorne ""
		
	}

	funcao inicio()
	{
		
		inteiro i
		cadeia dir

		leia(dir)

		i = grava_registro(dir, "teste1", Tipos.inteiro_para_cadeia(1256, 10))

		escreva(i,"\n")
		
		i = grava_registro(dir, "teste2", "valor2")

		escreva(i,"\n")

		i = grava_registro(dir, "teste3", Tipos.real_para_cadeia(1256.10))

		escreva(i,"\n")

		i = grava_registro(dir, "teste4", "valor4")

		escreva(i,"\n")

		escreva(ler_registro(dir, "teste3"))
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 2820; 
 * @DOBRAMENTO-CODIGO = [19, 138];
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {conteudo_arquivo, 25, 10, 16}-{ac_linhas, 27, 11, 9}-{linha, 31, 11, 5}-{ultima_pos, 66, 11, 10}-{fim, 69, 12, 3}-{linha, 71, 11, 5}-{linha, 116, 11, 5}-{i, 142, 11, 1};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */