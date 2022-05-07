/*2. (UFU) Faça um programa que receba do usuário um arquivo texto e mostre
na tela quantas linhas esse arquivo possui.*/
#include <stdio.h>
int main(){
	FILE *texto;
	texto = fopen("linhas.txt", "r");
	if(texto == NULL){
		printf("O arquivo nao pode ser aberto\n");
		return 0;
	}
	int count = 0, n = 100;
	char frases[n];
	while (fgets(frases, n, texto) != NULL){
		count++;
	}
	fclose(texto);
	printf("O seu arquivo de texto tem %d linha(as).", count);
	return 0;
}
