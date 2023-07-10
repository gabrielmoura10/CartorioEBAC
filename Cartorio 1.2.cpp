#include <stdio.h>  //biblioteca de comunica��o com o us�ario 
#include <stdlib.h>  //bilioteca de aloca��o de espa�o em memoria 
#include <locale.h>  // Biblioteca de aloca��o de textos por regi�o
#include <string.h> // biblioteca responsavel pelas strings

int registro()
{
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf);// responsavel por copiar o valor das strings 
	
	FILE *file; // este comando cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo na pasta de destino (Program_EBAC) 
	fprintf (file,cpf);// salvo o valor da variavel  	 
	fclose(file);// fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado no sistema: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");	
	}
	
	while(fgets(conteudo, 200,file)!= NULL )
	{
		printf("\nEssas s�o as informa��es do Us�ario: ");
		printf("%s",conteudo);
		printf("\n\n"); 
	}
	system("pause");
		
}

int deletar()
{
	printf("Voc� escolheu a op��o deletar nomes\n");
	system("pause");
}


int main ()
{
	int opcao=0;//Definindo variaveis 
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls");	
	
		setlocale(LC_ALL, "Portuguese");// set PT_BR 
	
		printf(" ### Cart�rio da EBAC ###\n\n");//inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
		
		scanf("%d",&opcao);	//armazenando a escolha do us�ario
	
		system("cls");
	
		switch(opcao)
		{
			case 1:
			registro();
			break; 
			
			case 2:
			consulta();		
			break; 
			
			case 3:
			deletar(); 
			break; 
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0; 
			break; 
			
			default:
			printf("Opa, essa op��o n�o est� disponivel.\n");
			system("pause");
			break; 
								
		}
	
}


}
