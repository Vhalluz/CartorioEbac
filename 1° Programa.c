#include <stdio.h> //Biblioteca de cumunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memoria.
#include <locale.h> //Biblioteca de alocações de texto por região.
#include <string.h> //Biblioteca responsavel pela criação de strings.

int registro() //Função responsavel pelo registro.
{
	char arquivo[40]; //Variáveis.
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //Escaneia o valor a ser recebido / "%s" escaneia uma string.
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings.
	
	FILE *file; //Cria o arquivo.
	file = fopen(arquivo, "w"); //Abre o arquivo / "w" cria um novo arquivo.
	fprintf(file, cpf); //armazena / salva o valor da variavel.
	fclose(file); //Fecha o arquivo após o armazenamento.
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" atualiza o arquivo.
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //Da um pause no sistema.
}

int consulta() //Função responsavel pela consuta.
{
	setlocale(LC_ALL, "portuguese"); //Define a linguagem.
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //Verifica se o CPF é existênte dentro do arquivo.
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //While: enquanto/espera. fgets:Busca
	{
		printf("\nEssas são as informações do usuario: "); //Mostra as informações caso o CPF esteja no arquivo.
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Função responsavel por deletar usúarios.
{	
	setlocale(LC_ALL, "portuguese"); //Define a linguagem.

	char cpf[40];
	
	printf("Digite o CPF do usúario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //Deleta um arquivo.
		
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usúario não se encontra no sistema!\n");
		system("pause");
	}
}

int main() //Função "main" sempre será a primeira a rodar.
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;) //Coloca o programa em um loop, para que sempre volte ao inicio.
	{
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); //Define a linguagem.
	
		printf("### Consultório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 Registrar nomes\n");
		printf("\t2 Consultar nomes\n");
		printf("\t3 Deletar nomes\n");
		printf("\t4 Sair do programa\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao);
	
		system("cls");
	
		switch(opcao) //Determina qual opção foi selecionada.
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
				break;
				
			default:
				printf("Essa opção não esta disponivel\n");
				system("pause");
				break;
		}
    }
}
