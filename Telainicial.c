#include <stdio.h> // Comunicação com o usuário.
#include <stdlib.h> // Alocação em espaço de memória.
#include <locale.h> // Alocação de texto por região.
#include <string.h> // Responsável pelas strings.
#include <stdbool.h> // Armazena os bools.


	// ========================================================
	
	int registro() //FUNÇÃO DE REGISTRO.
	{ 
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
	
		// Criação das variáveis.
		char arquivo[40]; 
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo [40];
		char confirmar [40];
		int loop = 1; 
	
		//----
		
		while (loop) // Começo do loop.
		{
		
			printf("\n\tVocê escolheu a opção de registro!\n");
	
			printf("\n\tDigite o CPF que deseja registrar: "); // CPF.
			scanf("%s", cpf);
		
			strcpy(arquivo, cpf); // Copia os valores das strings.
	
			FILE *file; // Cria o arquivo no banco de dados.
			file = fopen(arquivo, "w"); // Cria o arquivo e escreve com o "W".
			fprintf(file, cpf); // Salva o valor da variável.
			fclose(file); // Fecha o arquivo.
	
			file = fopen(arquivo,"a"); // Vírgula.
			fprintf(file,", ");
			fclose(file); // Fecha o arquivo.
	
	
			//----
			printf("\tDigite o nome que deseja registrar: "); // Nome.
			scanf("%s", nome);
	
			file = fopen(arquivo,"a");
			fprintf(file,nome);
			fclose(file); // Fecha o arquivo.
	
	
			//----
			file = fopen(arquivo,"a"); // Vírgula.
			fprintf(file,", ");
			fclose(file); // Fecha o arquivo.
	
	
			//----
			printf("\tDigite o sobrenome que deseja registrar: "); // Sobrenome.
			scanf("%s", sobrenome);
		
			file = fopen(arquivo,"a");
			fprintf(file,sobrenome);
			fclose(file); // Fecha o arquivo.
	
	
			//----
			file = fopen(arquivo,"a"); // Vírgula.
			fprintf(file,", ");
			fclose(file); // Fecha o arquivo.
		
	
			//----
			printf("\tDigite o cargo que deseja registrar: "); // Cargo.
			scanf("%s",cargo);
			printf("\n\n");
			
		
	
			file = fopen(arquivo,"a");
			fprintf(file,cargo);
			fclose(file); // Fecha o aqruivo.
	
	
			//---- REGISTRAR MAIS USUÁRIOS.
			printf("\tDeseja registrar mais usuários?\n");
			printf("\tDigite 'sim' para registrar e 'não' para voltar ao menu: ");
		
			scanf("%s", confirmar); // Lê o "sim".
		
			if (strcmp(confirmar, "sim") == 0 || strcmp(confirmar, "Sim") == 0) { // Confirma a escolha.
			
				loop = 1; // Volta pro loop.
				system("cls"); // Limpa a tela.
			
			}
			 	
			else { // Se não o loop é quebrado.
				
				printf("\n\n\t");
				loop = 0;	
				
			}
			
		}
		
		system("pause"); // Pausa a tela do registro.
	
	}
	
	// ========================================================
	
	int consulta() //FUNÇÃO DE CONSULTA.
	{ 
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
	
		printf("\n\tVocê escolheu consultar um nome!\n");
	
		// Criação das variáveis.
		char cpf[40];
		char conteudo[250];
		char confirmar[40];
		int loop = 1;
		
		while (loop) // Começo do loop;
		{
		
	
			printf("\n\tDigite o CPF a ser consultado: "); // CPF.
			scanf("%s",cpf); // "%s" Armazena a string.
	
			FILE *file; // Cria o arquivo no banco de dados.
			file = fopen(cpf,"r");
	
			//----
		
			if(file == NULL){ // Caso o nome consultado não exista.
	 
				printf("\n\tArquivo não localizado!\n");
		
			}
		
		
			while(fgets(conteudo,250, file) != NULL ) // Buscando informações.
			{
			
				printf("\n\tEssas são as informações do usuário:\n ");
				printf("\tCPF, Nome, Sobrenome e Cargo: %s",conteudo);
				printf("\n\n");
			
			}
		
			//----
		
			fclose(file); // Fecha o arquivo após ler.
			
			
			//---- CONSULTAR MAIS USUÁRIOS.
			printf("\tDeseja consultar mais usuários?\n");
			printf("\tDigite 'sim' para consultar e 'não' para voltar ao menu: ");
		
			scanf("%s", confirmar); // Lê o "sim".
		
			if (strcmp(confirmar, "sim") == 0 || strcmp(confirmar, "Sim") == 0) { // Confirma a escolha.
			
				loop = 1; // Volta pro loop.
				system("cls"); // Limpa a tela.
			
			}
			 	
			else { // Se não o loop é quebrado.
				
				printf("\n\n\t");
				loop = 0;	
				
			}
		}
		
		system("pause"); // Pausa a tela da consulta.
	
	}
	
	// ========================================================
	
	int deletar(){ //FUNÇÃO DE DELETAR.
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
			
		printf("\n\tVocê escolheu deletar um nome.\n");
		
		// Criação das variáveis.
		char cpf[40]; 
		char confirmacao[30]; // Armazena a confirmação.
		bool confirme = false;
		char confirmar[40]; // Confirmação do loop.
		int loop = 1;
		
		
		while (loop) 
		{
		
			printf("\n\tDigite o CPF a ser deletado: "); // Digite pra deletar.
			scanf("%s", cpf);
		
			printf("\n\tDigite 'confirmar' ou 'negar': ");
			scanf("%s", confirmacao); // Registra a string de confirmar.
		
			if (strcmp(confirmacao, "confirmar") == 0 || strcmp(confirmacao, "Confirmar") == 0 ) { //Confirma a escolha.
			
        		confirme = true;
    		}
    	
    		//----
    	
    		if (confirme == true){ // Se confirmar for digitado.
    		
    		
    			if(remove(cpf) == 0){ // CPF sendo removido.
    			
    			printf("\n\tConfirmação recebida. Deletando usuário.");
    			printf("\n\n");
    		
    			
				}
    		
    			FILE *file;
    			file = fopen(cpf, "r");
    		
    			if(file == NULL){ // Se o arquivo não for encontrado.
    		
    			printf("\n\tO usuário não se encontra no sistema.\n"); // Mensagem de não se encontra no sistema.
    			
				}
			
    		} 	
		
			else {
			
        		printf("\n\tAção cancelada pelo usuário.\n"); // Texto de cancelar a ação.
        		printf("\n\n");
        	
    		}
    		
    		
    		//---- DELETAR MAIS USUÁRIOS.
			printf("\n\tDeseja deletar mais usuários?\n");
			printf("\tDigite 'sim' para deletar e 'não' para voltar ao menu: ");
		
			scanf("%s", confirmar); // Lê o "sim".
		
			if (strcmp(confirmar, "sim") == 0 || strcmp(confirmar, "Sim") == 0) { // Confirma a escolha.
			
				loop = 1; // Volta pro loop.
				system("cls"); // Limpa a tela.
			
			}
			 	
			else { // Se não o loop é quebrado.
				
				printf("\n\n\t");
				loop = 0;	
    		
    		}	
    	}
    	
		system("pause"); // Pausa do "delete."
		
	}
		

	// =========================================================!
	
	
int main() // Tela inicial.
{ 				
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
	
	// Criação das variáveis.
	int escolha = 0;
	int comparacao;
	int loop = 1; 
	char senha[] ="a";
	
	
	printf("\n\n        --- Cartório da EBAC ---\n\n "); // Senha pra acesso.
	printf("\n\t Login de administrador.");
	printf("\n\t Digite sua senha: ");
	
	scanf("%s", senha); // Lê a comparação abaixo.
	comparacao = strcmp(senha,"admin");
	if(comparacao == 0 ) // Concede acesso se a comparação for certa.
	{
	
	
	
	
			for(loop=1;loop=1;) // Loop da tela.
		{
		
			system("cls");
	
			setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
	
				printf("\n\n        --- Cartório da EBAC ---\n\n ");  // Começo da interface do Menu.
				printf("\n    Escolha a opção desejada do menu:\n\n");
	
				printf("\t 1 - Registrar nomes.\n");
				printf("\t 2 - Consultar nomes.\n");
				printf("\t 3 - Deletar nomes.\n\n ");
				printf("\t 4 - Sair do sistema.\n\n ");
				printf("\t Número de escolha: ");		// Fim da interface do Menu.
	
	
			scanf("%d",&escolha); // Armazena o número e permite a escolha.
			system("cls"); // Limpa a tela.
	
			// Começo da interface de seleção. 
			switch(escolha){
			
				case 1: // Registrar nomes.
				registro();
				break;
			
				case 2: // Consultar nomes.
				consulta();
				break;
			
				case 3: // Apagar nomes.
				deletar();
				break;
			
				case 4: // Sair do sistema.
				printf("\n\tEncerrando o sistema!\n");
				return 0;
				break;
			
				default: //Opção acima de 3 ou abaixo de 1: Não disponíveis.
				printf("\n\t Essa opção não existe.\n");
				system("pause");
				break;
			
			}// Fim da interface de seleção.
		}
	
	} 
	
	else
	printf("\n\t Senha incorreta!\n\n");
	
}	
	
	
