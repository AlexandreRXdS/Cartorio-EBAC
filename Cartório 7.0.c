#include <stdio.h> //comunica��o com o usu�rio
#include <stdlib.h> //aloca��o de espa�os em mem�ria
#include <locale.h> //localiza��o de texto por regi�o
#include <string.h>	//biblioteca respons�vel pelas string

int registro() //Fun��o que controla o registro de usu�rios
{
	//inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf);	//respons�vel por copiar os valores das string

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		FILE *file;
		file = fopen(arquivo, "w");	//cria o arquivo
		fprintf(file,cpf); //salvo o valor da vari�vel
		fclose(file);	//fecho o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrador: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		printf("O usu�rio foi cadastrado com sucesso\n");
		system("pause");
	}
	else
	{
		printf("O usu�rio j� est� cadastrado\n");
		system("pause");
	}
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Insira o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi encontrado.\n");
		system("pause");
	} 
	else
	{
		fclose(file);
		remove(cpf);
		printf("O usu�rio foi deletado com sucesso.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
				
		printf("\tCart�rio EBAC\n\n");
		printf("Escolha a op��o desejada do menu: \n\n"); 		
		printf("1 - Registrar nomes\n"); 		
		printf("2 - Consultar nomes\n"); 		
		printf("3 - Deletar nomes\n");
		printf("4 - Sair do sistema\n\n");
		printf("Op��o: ");
		
		if(scanf("%d", &opcao) == 1)
		{
			system("cls");				
			
			//inicio da das fun��es
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
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
				
				default:
					printf("Essa op��o n�o est� dispon�vel\n");	
					system("pause");
					break;
				//fim das fun��es
			}
		}
		else
		{
			system("cls");
			printf("Essa op��o n�o est� dispon�vel\n");
			fflush(stdin);
			system("pause");
		}
	}
}
