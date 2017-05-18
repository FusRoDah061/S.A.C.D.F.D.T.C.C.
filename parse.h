#include<stdio.h>
#include<stdlib.h>

/*Converte um real para pointeiro char
 *
 * Par�metros:
 * (float) n: n�mero a ser convertido
 *
 * Retorna:
 * (char*) string de n
 */
char *float_to_char(float n)
{
	 char *s = malloc(sizeof(char*));

	 sprintf(s, "%f", n);

     return s;

     free(s);
}

/*Converte um inteiro para pointeiro char
 *
 * Par�metros:
 * (int) n: n�mero a ser convertido
 *
 * Retorna:
 * (char*) string de n
 */
 char *int_to_char(int n)
 {
	 char *s = malloc(sizeof(char*));

     sprintf(s, "%d", n);

     return s;

     free(s);
 }
