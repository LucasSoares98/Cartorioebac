#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel de cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/string
	
	printf("Digite seu CPF a ser cadastrado:"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável de copiar os valores das string (cpf para arquivo)
		
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar
	fprintf (file, ","); //escreve a "," para separar as informações
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:"); // coletando informação do usuário
	scanf("%s", nome); //salva o nome na string
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf (file, nome); // escreve o 	nome no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf(file, ","); //escreve a "," para separar as informações
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:"); // coletando informação do usuário
	scanf("%s", sobrenome); // salva o sobrenome na string
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf(file, sobrenome); //escreve o sobrenome no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf(file, ","); //escreve a "," para separar as informações
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informação do usuário
	scanf("%s", cargo); // salva o cargo na string
	
	file = fopen(arquivo, "a"); //abre o aqruivo e "a" significa atualizar
	fprintf(file, cargo); //escreve o cargo no arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	//inicio da criação de variáveis/string
	char cpf [40];
	char conteudo [200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado:"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string, salva o cpf na string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e "r" significa ler o arquivo
	
	if(file == NULL) //condição quando arquivo for nulo
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); // passando informação para a empresa
	}
	
	while(fgets(conteudo, 200, file) != NULL) //repetir enquanto for nulo
	{
		printf("\nEssas são as informações do usuário: "); //passando informação para a empresa
		printf("%s", conteudo);  //informando o conteudo da string
		printf("\n\n");	//pulando linha
	}
	
	system("pause");
}

int deletar ()
{
	char cpf[40]; // criação de variáveis/string
	
	printf("Digite o cpf do usuário a ser deletado:"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string, salva o cpf na string
	
	remove(cpf); //deletar
	
	FILE *file; // arquivo
	file = fopen(cpf,"r"); //abre o arquivo e "r" singinfica ler
	
	if (file == NULL) //condição quando o arquivo for nulo
	{
		printf("O usuário não se encontra no sistema!\n"); // informando para a empresa
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
			
		setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n"); 
		printf("Opção:"); //fim do menu

		scanf("%d", &opcao); //armazenando a esolha do usuário
	
		system("cls"); // responsável por limpar a tela
		
		switch(opcao) // início da seleção do menu
		{
			case 1:
			registro(); // chamada de funções
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause"); 
			break; //fim da seleção							
		}
	}
}
