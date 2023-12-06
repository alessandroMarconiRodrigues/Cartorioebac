#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região/País
#include <string.h>

int registro()//Função responsavel por cadastrar os usuarios no sistema
{
	// inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	 //final da criação de variaveis
	 setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	 
	printf("Digite o cpf a ser cadastrado:\n");//coletando informações do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever.
	fprintf(file, cpf);// salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ",");//alterando o arquivo para que não fique tudo na mesma linha as informações
	fclose(file);// Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:\n");//coleta informações do usuario
	scanf("%s", nome);//coleta oq o ususario digito e arazena na variavel.
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ",");//alterando arquivo para que não fique na mesma linha todas as alterações
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:\n");//coleta informações do usuario
	scanf("%s", sobrenome);//armazena as informções na variavel
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, sobrenome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, "\n");//altera informações no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:\n");//coleta informações do usuario
	scanf("%s", cargo);//armazena informações na variavel
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o programa para o usuario conseguir ler as informações
	
}//Fim da Função

int consulta()
{

//Inicio da função	
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	//Inicio da  criação da variavel/string	
	char cpf[40];//
	char conteudo[200];
	//final da criação variavel/string
	printf("Digite o CPF a ser consultado:");//colentando informações do usuario
	scanf("%s", cpf);//Armazenando as informações na variavel
	
	FILE *file;//Buscando arquivo
	file = fopen(cpf ,"r");//abrindo arquivo
	
	if(file == NULL)//estrutura de condição caso usuario digite algo nulo
	{
		printf("Não foi possivel abrir o arquivo, arquivo não localizado!\n\n");//comunicando ao usuario que a opção é invalida	
	}
	
	while(fgets/*busca o arquivo*/(conteudo, 200, file)!= NULL)//estrutura de repetição para buscar o arquivo, na base do banco de dados
	{
		printf("\nEssas são as informações do cpf:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");// pause para o usuario ler as infromações
	
}//Fim da função consulta

int deleta()
{//inicio da Função deleta

	//inicio da variavel/string
	char cpf[40];
	//fim da variavel/string
	printf("Digite o CPF do usuario a ser deletado: \n");//coletando informações do usuario
	scanf("%s", cpf);//arameza as infromações na variavel
	
	remove(cpf);//função para apagar
	
	FILE *file;//chamada de arquivo, pedindo pro computador achar o arquivo
	file, fopen(cpf, "r");//abre o arquivo
	
	if(file == NULL)//estrutura condicional para informar ao usuario que a opção é nula
	{
		printf("Usuario não se encontra no sistema!");
		
		system("pause");//pause para usuario ler as informações printadas na tela
	}
	
	
}// fim da função deleta

int main()//função principal

{
	int opcao = 0;// Definindo a varivel
	int laco = 1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");// Definindo Linguagem
	
		printf("### Cartório De Consulta de Nomes EBAC ### \n\n");// Inicio do menu
	
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes:\n");
		printf("\t2- Consultar nomes:\n");
		printf("\t3 - Deletar nomes:\n\n");
		printf("Opção: ");// Fim do menu
	
		scanf("%d", &opcao);// armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)//estrutura condicional
		{
			case 1:
				registro();//chamada de funções
				break;
			
			case 2:
				consulta();	
				break;
				
			case 3:
				deleta();	
				break;
				
			
			default:// fim da seleção
			
				printf("Essa opção não existe.");// seleção invalida
				system("pause");
				break;
		}//fim da condicional
		
		
		
		/*
		if(opcao == 1)// inicio da seleção
		{
			printf("Você escolheu registrar nomes \n\n");
			system("pause");
		}
		if(opcao == 2)
		{
	 		printf("Você escolheu consultar os nomes\n\n");	
	 		system("pause");
		}
		if(opcao == 3)
		{
			printf("Você escolheu deletar nomes\n\n");
			system("pause");
		}
		
		if(opcao >=4 || opcao <=0)
		{
			printf("Essa opção não existe\n\n");// fim da seleção
			system("pause");
		}
		*/
			printf("Esse software é de livre uso dos alunos EBAC\n\n");

}
}

