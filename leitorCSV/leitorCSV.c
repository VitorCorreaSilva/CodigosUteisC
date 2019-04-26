#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *arquivo;
	char vetor[2];

	char *palavra;
	palavra = malloc(sizeof(palavra));

	arquivo = fopen("info.csv", "r");
	
	while(fgets(palavra, sizeof(palavra), arquivo) != NULL)
		printf("%s", palavra);

	return 0;
}
