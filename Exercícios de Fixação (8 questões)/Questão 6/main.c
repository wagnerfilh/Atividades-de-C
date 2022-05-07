/*6. (UFU) Faça um programa que receba do usuário um arquivo texto e mostre
na tela quantas vezes cada letra do alfabeto aparece dentro do arquivo.*/
#include <stdio.h>
#include <string.h>
int main(){
	FILE *texto;
	texto = fopen("textos.txt", "r");
	if(texto == NULL){
		printf("O arquivo nao pode ser aberto\n");
		return 0;
	}
	char alfabeto[26]="abcdefghijklmnopqrstuvwxyz";
	char frases[100];
	int i, j, count = 0;
	for(i=0;i<26;i++){
		count = 0;
		fgets(frases, 100, texto);
		for(j=0; j < strlen(frases); j++){
			if(alfabeto[i]== frases[j] || toupper(alfabeto[i])==frases[j]){
				count++;
			}
		}	
		printf("A letra '%c' apareceu %i vez(es) no texto\n", alfabeto[i], count);
	}
	fclose(texto);
	return 0;
}
