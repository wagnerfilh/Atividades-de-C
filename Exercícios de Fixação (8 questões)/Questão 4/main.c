/*4. (UFU) Faça um programa que receba do usuário um arquivo texto e mostre
na tela quantas letras são vogais e quantas são consoantes.*/
#include <stdio.h>
#include <string.h>
int main(){
	FILE *vogal;
	vogal = fopen("vogais.txt", "r");
	if(vogal == NULL){
		printf("O arquivo nao pode ser aberto\n");
		return 0;
	}	
	int count = 0, count2 = 0, i, j, n = 1000;
	char consoantes[] = "bcdfghjklmnpqrstvxywzBCDFGHJKLMNPQRSTVXYWZ";
	char vogais[] = "aeiouAEIOU";
	char frases[n];
	while (fgets(frases, n, vogal)!=NULL){
		for (i = 0; frases[i] != '\0'; i++){
			for(j = 0; j < strlen(vogais); j++){
				if(frases[i]==vogais[j]){
					count++;
				}
			}
			for(j = 0; j < strlen(consoantes); j++){
				if(frases[i]==consoantes[j]){
					count2++;
				}
			}
		}
	}
	fclose(vogal);
	printf("O seu arquivo de texto tem %d vogal(ais).", count);
	printf("\nO seu arquivo de texto tem %d consoante(es).", count2);
	return 0;
}
