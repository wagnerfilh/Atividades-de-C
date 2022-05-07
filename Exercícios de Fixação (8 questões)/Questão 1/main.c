/*1. (UFU) Faça um programa que leia um arquivo que contenha as dimensões
de uma matriz (linha e coluna), a quantidade de posições que serão
anuladas, e as posições a serem anuladas (linha e coluna). O programa lê
esse arquivo e, em seguida, produz um novo arquivo com a matriz com as
dimensões dadas no arquivo lido, e todas as posições especificadas no
arquivo ZERADAS e o restante recebendo o valor 1.
Ex: arquivo “matriz.txt”
3 3 2 /*3 e 3 dimensões da matriz e 2 posições que
serão anuladas*/ /*
1 0 1 2
/* /*Posições da matriz que serão anuladas.
arquivo “matriz saida.txt”
saída:
1 1 1
0 1 0
1 1 1*/
#include <stdio.h>
int main(){
	FILE *valores;
	int x, y, z, a, b, i, j;
	valores = fopen("matrizes.txt", "r");
	if(valores == NULL){
		printf("O arquivo nao pode ser aberto\n");
		return 0;
	}
	fscanf(valores, "%d %d %d ", &x, &y, &z);
	int matriz[x][y];	
	for (i=0; i<x; i++){
		for (j=0; j<y; j++){
			matriz[i][j] = 1;
		}
	}
	for(i=0; i<z; i++){
			fscanf(valores, "%d %d ", &a, &b);
			matriz[a][b] = 0;	
	}
	for (i=0; i<x; i++){
		for (j=0; j<y; j++){
			if(j<y-1){
				printf("%d ", matriz[i][j]);	
			}
			else{
				printf("%d ", matriz[i][j]);
				printf("\n");
			}	
		}
	}
	fclose(valores);	
	return 0;
}
