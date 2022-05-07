/*5. (UFU) Faça um programa que receba do usuário um arquivo texto e um
caractere. Mostre na tela quantas vezes aquele caractere ocorre dentro do
arquivo.*/
#include <stdio.h>
#include <string.h>
int main(){
	FILE *texto;
	texto = fopen("textos.txt", "r");
	if(texto == NULL){
		printf("O arquivo nao pode ser aberto\n");
		return 0;
	}
	int i; 
	int count = 0;
	char *caract[1];
	char frases[100];
	fscanf(texto, "%c", caract);
	fgets(frases, 100, texto);
	printf("%s", frases);
	while(fgets(frases, 100, texto)!=NULL){
		for(i=0; i < strlen(frases); i++){
			if(*caract== frases[i]){
				count++;
			}
			//Caso queira tanto maiúsculas quanto minúsculas é só ativar o "if" abaixo e desativar o de cima.
			//Como diz "caractere" na questão eu botei somente a versão que for considerada no arquivo, mas
			//eu fiz a versão mais completa também... 
			/*if(tolower(*caract)== frases[i] || toupper(*caract)==frases[i]){
				count++;
			}*/
		}
		printf("%s", frases);
	}
	fclose(texto);
	printf("\nO caractere '%c'aparece %i vez(es) no texto do arquivo", *caract, count);
	return 0;
}
