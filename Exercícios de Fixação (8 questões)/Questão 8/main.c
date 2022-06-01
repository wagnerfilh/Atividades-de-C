/*8. (Linhares, 2016) Uma loja possui 4 filiais, cada uma com um código de 1 a 4.
Um arquivo contendo todas as vendas feitas durante o dia nas quatro filiais
é gerado a partir de uma planilha, sendo que cada linha do arquivo contém
o número da filial e o valor de uma venda efetuada, separados por tab. Ex.:
1 1920.80
1 41.50
3 89.90
4 109.50
No exemplo acima a filial 1 fez 2 vendas, a primeira totalizando R$1920,80 e
a segunda R$ 41,50. A filial 3 fez uma venda de R$89,90, e a filial 4 fez uma
venda de R$109,90. Faça um programa que leia este arquivo e informe, ao
final, o total e o valor médio das vendas de cada filial.*/
#include <stdio.h>
#include <string.h>
int main(){
	FILE *filiais;
	FILE *auxiliar;
	auxiliar = fopen("filiais.txt", "r");
	filiais = fopen("filiais.txt", "r");
	if(filiais == NULL){
		printf("O arquivo nao pode ser aberto\n");
		return 0;
	}	
	int i=0, x = 0, n = 100;
	char frases[n];
	while (fgets(frases, n, auxiliar) != NULL){
		x++;
	}
	fclose(auxiliar);
	float filial1, filial2, filial3, filial4, filial;
	int vendas1, vendas2, vendas3, vendas4; 
	int aux;
	
	for(i=0; i<x; i++){
		fscanf(filiais, "%i	", &aux);
		
		if(aux==1){
			fscanf(filiais, " %lf", &filial1);
			 //filial;
			vendas1++;
			//printf("%lf\n\n", filial);
			filial = 0;
		}
		if(aux==2){
			fscanf(filiais, "%lf", &filial);
			filial2 += filial;
			vendas2++;
		}
		if(aux==3){
			fscanf(filiais, "%lf", &filial);
			filial3 += filial;
			vendas3++;
		}
		if(aux==4){
			fscanf(filiais, "%lf", &filial);
			filial4 += filial;
			vendas4++;
		}
		printf("%d\n",aux);
	}
	fclose(filiais);
	printf("%g",filial1);
	return 0;	
}
