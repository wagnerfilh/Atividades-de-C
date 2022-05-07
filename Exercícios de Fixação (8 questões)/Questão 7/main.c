/*7. (Linhares, 2016) Fazer um programa em C que:
a. Receba o nome, o código e as duas notas bimestrais de N alunos
para uma determinada matéria.
b. Salve estes dados em um arquivo. Os dados devem ser salvos
registro a registro, obedecendo o seguinte formato:
I. número inteiro contendo o tamanho em char do nome do aluno.
II. sequência de chars correspondente à string que contém o nome
do aluno.
III. código na forma de número inteiro
IV. duas notas na forma de números inteiros.
c. ler os dados contidos no arquivo gerado pelo programa anterior

d. calcular e mostrar: quais alunos foram aprovados, quais foram
reprovados e a média da turma.*/
#include <stdio.h>
#include <string.h>
int main(){
	FILE *alunos;
	alunos = fopen("alunos.txt", "w");
	char nome[100];
	int codigo, nAlunos, i, j;
	int nota1, nota2;
	printf("Quantidade de alunos: ");
	scanf("%d", &nAlunos);
	for(i=0; i<nAlunos; i++){
		printf("\n");
		printf("Nome: ");
		scanf("%s", nome);
		fprintf(alunos,"%i", strlen(nome));
		fprintf(alunos, "\n");
		fprintf(alunos,"%s", nome);	
		fprintf(alunos, "\n");
		printf("\nDigite o seu codigo: ");
		scanf("%i", &codigo);
		fprintf(alunos,"%i", codigo);
		fprintf(alunos, "\n");
		printf("\nNota 1 Bimestral: ");
		scanf("%d", &nota1);
		fprintf(alunos,"%d", nota1);
		fprintf(alunos, "\n");
		printf("\nNota 2 Bimestral: ");
		scanf("%d", &nota2);
		fprintf(alunos,"%d", nota2);
		fprintf(alunos, "\n");
	}
	fclose(alunos);
	printf("\n\n#############################################################################\n\n");	
	FILE *media;
	media = fopen("alunos.txt", "r");
	if(media == NULL){
		printf("O arquivo nao pode ser aberto\n");
		return 0;
	}
	int tamanhoNome[nAlunos];
	char nome2[nAlunos][100];
	int senha[nAlunos];
	int primeiraNota[nAlunos];
	int segundaNota[nAlunos];
	int mediaFinal = 0;
	for(i=0; i<nAlunos;i++){
		fscanf(media, "%d %s %d %d %d", &tamanhoNome[i], nome2[i], &senha[i], &primeiraNota[i], &segundaNota[i]);
	}
	printf("Aprovados:####################\n");
	for(i=0; i<nAlunos;i++){
		if(nota1+nota2>=14){
			printf("O aluno %s com media %d\n", nome2[i], (primeiraNota[i]+segundaNota[i])/2);
		}		
	}
	printf("\n\n");
	printf("Reprovados:###################\n");
	for(i=0; i<nAlunos;i++){
		if(nota1+nota2<14){
			printf("O aluno %s com media %d\n", nome2[i], (primeiraNota[i]+segundaNota[i])/2);
		}
	}
	printf("\n\n");
	printf("Media da turma: ##############\n");
	for(i=0; i<nAlunos;i++){
		mediaFinal+=(primeiraNota[i]+segundaNota[i]);
	}
	printf("A media dessa turma foi de: %d", mediaFinal/(nAlunos*2));
	fclose(media);
	return 0;	
}
