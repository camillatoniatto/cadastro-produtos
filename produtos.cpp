#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

struct produto{
	int id;
	char nome[99];
	float valor;
	int qtde;
};

//variaveis globais
struct produto p;
int questao;

void cadastro(){
	printf("\nCadastro de produtos");
	printf("\nDigite nome do produto: ");
	fflush(stdin);
	gets(p.nome);
	fflush(stdin);
	printf("\nDigite o valor: ");
	scanf("%f",&p.valor);
	printf("\nQuantidade: ");
	scanf("%d",&p.qtde);
	system("cls");
}

void getall(){
	char str[255];
	FILE *arq;
	arq = fopen("produtos.txt", "r");
	while ( !feof(arq) ) { /* imprime todo o arquivo no monitor */
		fgets(str, 255, arq);
		printf("%s", str);
	}
	fclose(arq);
}

/*int getbyid(){
	system("cls");
	char str[3];
	int id;
	printf("\nDigite o id do projeto: ");
	scanf("%d",&p.id);
	FILE *arq;
	arq = fopen("produtos.txt", "r");
	while ( !feof(arq) ) {
		fgets(str, 3, arq);
		printf("%s", str);
	}
	fclose(arq);
}*/

FILE* abre_arquivo(char caminho[50], char modo[2]){
	FILE *arquivo;
	arquivo = fopen(caminho, modo);
	if(arquivo == NULL){
		printf("Não foi possivel abrir o arquivo");
	}
	return arquivo;
}

void fecha_arquivo(FILE *arquivo){
	fclose(arquivo);	
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	do{
		printf("Menu:\n-----------------------------------\n1- Cadastrar produto \n2- Todos os produtos \n3- Busca por Id \n4- Alterar qualtidade \n5- Sair\n-----------------------------------\n\nEscolha: ");
		scanf("%d",&questao);
		if((questao==1)||(questao==2)||(questao==3)||(questao==4)){
			
			switch(questao){
				case 1:		
					FILE *arquivo;								
					cadastro();
					arquivo = fopen("produtos.txt","a");
					fprintf(arquivo,"Nome: %s \nValor: %2.f \nQuantidade: %d\n-----------------------------------\n",p.nome, p.valor, p.qtde);
					fclose(arquivo);
					system ("Pause");
				break;
				
				case 2:										
					getall();
				break;
				
				case 3:
					//getbyid();
				break;
				
				case 4:
					printf("Saindo...\n");
				break;
				
				case 5:
					printf("Saindo...\n");
				break;
			}
		}
		else{
			printf("\nOpçao Invalida.\n");
			/*system("pause");
			system("cls");*/
		}
	}while(questao!=5);

	return 0;
}
