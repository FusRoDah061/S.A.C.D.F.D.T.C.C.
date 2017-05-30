programa
{
	inclua biblioteca Arquivos
	inclua biblioteca Texto
	inclua biblioteca Tipos

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
					cadeia chave_lida = Texto.extrair_subtexto(linha, 0, Texto.posicao_texto(" ", linha, 0) )
					
					se(chave_lida == chave){
						retorne Texto.extrair_subtexto(linha, Texto.posicao_texto(" ", linha, 0) + 1,  Texto.numero_caracteres(linha))
					}
					
				}
				
			}

			retorne ""
		}
		senao
		{
			retorne ""
		}
		
	}

	funcao inicio()
	{
		
		inteiro i

		i = grava_registro("E:/Usuarios/allex/Desktop/teste.txt", "teste1", Tipos.inteiro_para_cadeia(1256, 10))

		escreva(i,"\n")
		
		i = grava_registro("E:/Usuarios/allex/Desktop/teste.txt", "teste2", "valor2")

		escreva(i,"\n")

		i = grava_registro("E:/Usuarios/allex/Desktop/teste.txt", "teste3", Tipos.real_para_cadeia(1256.10))

		escreva(i,"\n")

		i = grava_registro("E:/Usuarios/allex/Desktop/teste.txt", "teste4", "valor4")

		escreva(i,"\n")

		escreva(ler_registro("E:/Usuarios/allex/Desktop/teste.txt", "teste3"))
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1813; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {conteudo_arquivo, 12, 10, 16}-{ac_linhas, 14, 11, 9}-{linha, 18, 11, 5}-{ultima_pos, 45, 11, 10}-{fim, 48, 12, 3}-{linha, 50, 11, 5}-{linha, 93, 11, 5}-{i, 118, 11, 1};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */