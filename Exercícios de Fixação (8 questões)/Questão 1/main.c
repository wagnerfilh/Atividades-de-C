/*1. (UFU) Fa�a um programa que leia um arquivo que contenha as dimens�es
de uma matriz (linha e coluna), a quantidade de posi��es que ser�o
anuladas, e as posi��es a serem anuladas (linha e coluna). O programa l�
esse arquivo e, em seguida, produz um novo arquivo com a matriz com as
dimens�es dadas no arquivo lido, e todas as posi��es especificadas no
arquivo ZERADAS e o restante recebendo o valor 1.
Ex: arquivo �matriz.txt�
3 3 2 /*3 e 3 dimens�es da matriz e 2 posi��es que
ser�o anuladas*/ /*
1 0 1 2
/* /*Posi��es da matriz que ser�o anuladas.
arquivo �matriz saida.txt�
sa�da:
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
