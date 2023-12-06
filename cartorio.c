#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o/Pa�s
#include <string.h>

int registro()//Fun��o responsavel por cadastrar os usuarios no sistema
{
	// inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	 //final da cria��o de variaveis
	 setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	 
	printf("Digite o cpf a ser cadastrado:\n");//coletando informa��es do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever.
	fprintf(file, cpf);// salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ",");//alterando o arquivo para que n�o fique tudo na mesma linha as informa��es
	fclose(file);// Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:\n");//coleta informa��es do usuario
	scanf("%s", nome);//coleta oq o ususario digito e arazena na variavel.
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ",");//alterando arquivo para que n�o fique na mesma linha todas as altera��es
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:\n");//coleta informa��es do usuario
	scanf("%s", sobrenome);//armazena as inform��es na variavel
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, sobrenome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, "\n");//altera informa��es no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:\n");//coleta informa��es do usuario
	scanf("%s", cargo);//armazena informa��es na variavel
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o programa para o usuario conseguir ler as informa��es
	
}//Fim da Fun��o

int consulta()
{

//Inicio da fun��o	
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	//Inicio da  cria��o da variavel/string	
	char cpf[40];//
	char conteudo[200];
	//final da cria��o variavel/string
	printf("Digite o CPF a ser consultado:");//colentando informa��es do usuario
	scanf("%s", cpf);//Armazenando as informa��es na variavel
	
	FILE *file;//Buscando arquivo
	file = fopen(cpf ,"r");//abrindo arquivo
	
	if(file == NULL)//estrutura de condi��o caso usuario digite algo nulo
	{
		printf("N�o foi possivel abrir o arquivo, arquivo n�o localizado!\n\n");//comunicando ao usuario que a op��o � invalida	
	}
	
	while(fgets/*busca o arquivo*/(conteudo, 200, file)!= NULL)//estrutura de repeti��o para buscar o arquivo, na base do banco de dados
	{
		printf("\nEssas s�o as informa��es do cpf:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");// pause para o usuario ler as infroma��es
	
}//Fim da fun��o consulta

int deleta()
{//inicio da Fun��o deleta

	//inicio da variavel/string
	char cpf[40];
	//fim da variavel/string
	printf("Digite o CPF do usuario a ser deletado: \n");//coletando informa��es do usuario
	scanf("%s", cpf);//arameza as infroma��es na variavel
	
	remove(cpf);//fun��o para apagar
	
	FILE *file;//chamada de arquivo, pedindo pro computador achar o arquivo
	file, fopen(cpf, "r");//abre o arquivo
	
	if(file == NULL)//estrutura condicional para informar ao usuario que a op��o � nula
	{
		printf("Usuario n�o se encontra no sistema!");
		
		system("pause");//pause para usuario ler as informa��es printadas na tela
	}
	
	
}// fim da fun��o deleta

int main()//fun��o principal

{
	int opcao = 0;// Definindo a varivel
	int laco = 1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");// Definindo Linguagem
	
		printf("### Cart�rio De Consulta de Nomes EBAC ### \n\n");// Inicio do menu
	
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes:\n");
		printf("\t2- Consultar nomes:\n");
		printf("\t3 - Deletar nomes:\n\n");
		printf("Op��o: ");// Fim do menu
	
		scanf("%d", &opcao);// armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)//estrutura condicional
		{
			case 1:
				registro();//chamada de fun��es
				break;
			
			case 2:
				consulta();	
				break;
				
			case 3:
				deleta();	
				break;
				
			
			default:// fim da sele��o
			
				printf("Essa op��o n�o existe.");// sele��o invalida
				system("pause");
				break;
		}//fim da condicional
		
		
		
		/*
		if(opcao == 1)// inicio da sele��o
		{
			printf("Voc� escolheu registrar nomes \n\n");
			system("pause");
		}
		if(opcao == 2)
		{
	 		printf("Voc� escolheu consultar os nomes\n\n");	
	 		system("pause");
		}
		if(opcao == 3)
		{
			printf("Voc� escolheu deletar nomes\n\n");
			system("pause");
		}
		
		if(opcao >=4 || opcao <=0)
		{
			printf("Essa op��o n�o existe\n\n");// fim da sele��o
			system("pause");
		}
		*/
			printf("Esse software � de livre uso dos alunos EBAC\n\n");

}
}

