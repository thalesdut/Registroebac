#include <stdio.h> //biblio de comunicação com o usuário
#include <stdlib.h> // biblio de alocação de espaço em memória
#include <locale.h> // biblio de alocações de texto por região
#include <string.h> // bibilio que cuida das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf); // Comando que armazena as strings
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings (ex: arquivo copia cpf)
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Primeira instrução ao abrir o arquivo (Neste caso usa a função "w" para transcrever uma variavel)
	fprintf(file, cpf); // Transcreve ao arquivo a variavel designada (ex: transcreve em file a string cpf)
	fclose(file); // Fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Função "a" utilizada para adicionar novas strings ao arquivo que já foi criado previamente
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
}

int consulta()
{		

	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	char *casa;
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo, agora com a função R para ler as informações dentro do mesmo
	
	if(file == NULL) //O que será exibido no ato da não identificação da informaçõ
	{
		printf("O CPF digitado não foi localizado em nosso sistema! Por favor insira um CPF valido.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nConfira abaixo as informações do usuário: \n\n");
		
		casa = strtok(conteudo,","); //Variavel que divide a string em linhas baseado no caracter estipulado, neste caso ","
		printf("CPF: %s\n", casa);
		
		casa = strtok(NULL,",");
		printf("Nome: %s\n", casa);
		
		casa = strtok(NULL,",");
		printf("Sobrenome: %s\n", casa);
		
		casa = strtok(NULL,",");
		printf("Ocupação: %s\n", casa);
		
	}
	
	fclose(file); //Adicionado para fechar o arquivo que foi previamente aberto e não correr o risco de gerar conflito com outras funções do programa
	printf("\n\n");
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
    
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		fclose(file);
		printf("O CPF digitado não se encontra em nosso sistema!\n");
		system("pause");
	}	
	
	else if (file != NULL)
	{
		fclose(file);
		printf("O CPF do usuário solciitado foi deletado com sucesso!\n");
		system("pause");
		remove(cpf);
	}
}

int main ()
{
	int opcao=0; // Definindo a variavel de seleção
	int x=1; // Definindo a variavel de repetição da página
	
	for(x=1;x=1;)
	{
		
		system("cls"); // Comando para limpar a página
		
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	  
	    printf("#### TERMINAL DE REGISTRO DA EBAC ####\n\n"); //Mensagem inicial do Menu
	    printf("Escolha a opção desejada \n\n");
	    printf("\t1 - Registrar Nomes. \n");
	    printf("\t2 - Consultar Nomes. \n");
	    printf("\t3 - Deletar Nomes. \n\n");
	    printf("\t4 - Sair do sistema. \n\n");
	    printf("Opção:"); // Mensagem de inserção da variavel (fim do menu)
	    
	    scanf("%d", &opcao); // Comando que armazena variaveis
	    
	    system("cls");
	    
	    switch(opcao) // Switchcase utilizado para processar a opção baseado na variavel
	    {
	    	case 1:
	    	registro(); //Chamada das funções dividida em 3 por switchase
	    	break;
	    	
	    	case 2:
	    	consulta();
	    	break;
	    	
	    	case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema, volte sempre!");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível! Iremos lhe redirecionar para o menu.\n");
			system("pause");
			break;
	    			
		}
    }
}

