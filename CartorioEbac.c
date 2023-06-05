#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel de cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite seu CPF a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel de copiar os valores das string (cpf para arquivo)
		
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar
	fprintf (file, ","); //escreve a "," para separar as informa��es
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:"); // coletando informa��o do usu�rio
	scanf("%s", nome); //salva o nome na string
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf (file, nome); // escreve o 	nome no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf(file, ","); //escreve a "," para separar as informa��es
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:"); // coletando informa��o do usu�rio
	scanf("%s", sobrenome); // salva o sobrenome na string
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf(file, sobrenome); //escreve o sobrenome no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf(file, ","); //escreve a "," para separar as informa��es
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s", cargo); // salva o cargo na string
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf(file, cargo); //escreve o cargo no arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	//inicio da cria��o de vari�veis/string
	char cpf [40];
	char conteudo [200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado:"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string, salva o cpf na string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e "r" significa ler o arquivo
	
	if(file == NULL) //condi��o quando arquivo for nulo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); // passando informa��o para a empresa
	}
	
	while(fgets(conteudo, 200, file) != NULL) //repetir enquanto for nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //passando informa��o para a empresa
		printf("%s", conteudo);  //informando o conteudo da string
		printf("\n\n");	//pulando linha
	}
	
	system("pause");
}

int deletar ()
{
	char cpf[40]; // cria��o de vari�veis/string
	
	printf("Digite o cpf do usu�rio a ser deletado:"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string, salva o cpf na string
	
	remove(cpf); //deletar
	
	FILE *file; // arquivo
	file = fopen(cpf,"r"); //abre o arquivo e "r" singinfica ler
	
	if (file == NULL) //condi��o quando o arquivo for nulo
	{
		printf("O usu�rio n�o se encontra no sistema!\n"); // informando para a empresa
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
			
		setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n"); 
		printf("Op��o:"); //fim do menu

		scanf("%d", &opcao); //armazenando a esolha do usu�rio
	
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao) // in�cio da sele��o do menu
		{
			case 1:
			registro(); // chamada de fun��es
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause"); 
			break; //fim da sele��o							
		}
	}
}
