#include <stdio.h> //comunicação com o usuário
#include <stdlib.h> //alocação de espaços em memória
#include <locale.h> //localização de texto por região
#include <string.h>	//biblioteca responsável pelas string

int registro() //Função que controla o registro de usuários
{
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf);	//responsável por copiar os valores das string

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		FILE *file;
		file = fopen(arquivo, "w");	//cria o arquivo
		fprintf(file,cpf); //salvo o valor da variável
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
		
		printf("O usuário foi cadastrado com sucesso\n");
		system("pause");
	}
	else
	{
		printf("O usuário já está cadastrado\n");
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
		printf("CPF não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Insira o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não foi encontrado.\n");
		system("pause");
	} 
	else
	{
		fclose(file);
		remove(cpf);
		printf("O usuário foi deletado com sucesso.\n");
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
				
		printf("\tCartório EBAC\n\n");
		printf("Escolha a opção desejada do menu: \n\n"); 		
		printf("1 - Registrar nomes\n"); 		
		printf("2 - Consultar nomes\n"); 		
		printf("3 - Deletar nomes\n");
		printf("4 - Sair do sistema\n\n");
		printf("Opção: ");
		
		if(scanf("%d", &opcao) == 1)
		{
			system("cls");				
			
			//inicio da das funções
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
					printf("Essa opção não está disponível\n");	
					system("pause");
					break;
				//fim das funções
			}
		}
		else
		{
			system("cls");
			printf("Essa opção não está disponível\n");
			fflush(stdin);
			system("pause");
		}
	}
}
