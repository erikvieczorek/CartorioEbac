#include <stdio.h> //biblioteca de comunica??o com o usu?rio
#include <stdlib.h> //biblioteca de aloca??o de espa?o em mem?ria
#include <locale.h> //biblioteca de aloca??es de texto por regi?o
#include <string.h> //biblioteca respons?vel por cuidar das string

	int registro() //Fun??o respons?vel por cadastrar os usu?rios no sistema
	
{	
	//In?cio cria??o de vari?veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria??o de vari?veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa??o do usu?rio
	scanf("%s", cpf); //%s Armazena a vari?vel string
	
	strcpy(arquivo, cpf); //Respons?vel para copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria um arquivo na pasta do sistema do tipo (write)
	fprintf(file,cpf); //salva o valor da vari?vel
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
			printf("\nN?o foi poss?vel abrir o arquivo, cadastro n?o localizado!\n\n");
		}	


	while(fgets(conteudo, 200, file) != NULL)
	
		{ 	
			printf("\nEssas s?o as informa??es do usu?rio: ");
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
	
	printf("Digite o CPF do usu?rio a ser deletado: \n");
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
			printf ("CPF n?o encontrado no sistema! \n\n");
		}

	system("pause");
	
}

	int main ()
	
{
	int opcao=0; //Definindo vari?veis
	int laco=1;
			
		for (laco=1;laco=1;)
	{
		
		system("cls"); //Limpar a tela
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf ("### Cart?rio da EBAC ###\n\n"); //In?cio do menu
		printf ("Escolha a op??o desejada do menu: \n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("\t4 - Sair do sistema\n\n");
		printf ("Op??o: "); //Fim de menu
			
		scanf("%d", &opcao); //Armazenando a escolha do usu?rio
			
		system("cls");
			
			switch (opcao) 
		{ //In?cio sele??o
		
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
				printf("Obrigado por utilizar o sistema!\n\n");
				system("pause");
				return 0;
				break;
				
				default:
				printf("Essa op??o n?o est? dispon?vel!\n");
				system ("pause");
				break;	
											
		} //Fim sele??o
						
	}
}

