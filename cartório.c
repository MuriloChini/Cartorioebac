#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaçõ em memória 
#include <locale.h> //biblioteca de alocação de texto por região

int main ()
    {
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{

	  system ("cls");
	
	  setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	
	  printf("### Cartório da EBAC ### \n\n"); //inicio do menu
	  printf("Escolha a opção desejada do menu: \n\n");
	  printf("\t1 - Registrar Nomes \n");
	  printf("\t2 - Consultar os Nomes \n");
	  printf("\t3 - Deletar os Nomes \n\n");	
	  printf("Opção: ");//final do menu
	
	  scanf("%d", &opcao); //armazenando a escolha do usuário
	
	  system ("cls");
	  
	  switch(opcao)
	  {
	  case 1: 
	  printf ("Você escolheu o registro de nomes\n");
		system("pause");
		break;
	  case 2: 
	  printf ("Você escolheu consultar os nomes\n");
		system("pause");
		break;
	  case 3: 
	  printf ("Você escolhe deletar os nomes\n");
		system("pause");
		break;
	  default: 
	  printf ("Essa opção não está disponível!\n");
		system("pause");
		break;	
      }
		
    }
}
