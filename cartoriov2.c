#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

	int registro() //Função responsável por cadastrar os usuários no sistema
	
{	
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s Armazena a variável string
	
	strcpy(arquivo, cpf); //Responsável para copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria um arquivo na pasta do sistema do tipo (write)
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
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
	scanf("%s", sobrenome);	
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
	
}

	int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	
		{
			printf("\nNão foi possível abrir o arquivo, cadastro não localizado!\n\n");
		}	


	while(fgets(conteudo, 200, file) != NULL)
	
		{ 	
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
	fclose(file);			
	system("pause");
	fclose(file);		

}


	int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file)
	
		{
			printf("\n");
			printf ("CPF deletado com sucesso! \n\n");
			fclose(file);
			remove(cpf);
		}
	
	else 
		
		{
			printf("\n");
			printf ("CPF não encontrado no sistema! \n\n");
		}

	system("pause");
	
}

	int main ()
	
{
	int opcao=0; //Definindo variáveis
	int laco=1;
			
		for (laco=1;laco=1;)
	{
		
		system("cls"); //Limpar a tela
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf ("### Cartório da EBAC ###\n\n"); //Início do menu
		printf ("Escolha a opção desejada do menu: \n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("Opção: "); //Fim de menu
			
		scanf("%d", &opcao); //Armazenando a escolha do usuário
			
		system("cls");
			
			switch (opcao) 
		{ //Início seleção
		
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:	
				deletar();
				break;
				
				default:
				printf("Essa opção não está disponível!\n");
				system ("pause");
				break;	
											
		} //Fim seleção
						
	}
}

