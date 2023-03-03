
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h> 
#include <locale.h>
#include "amedonha.h" 


int main(void){
  limpatela();
  srand(time(NULL));
  int *vetordemjogs;
  vetordemjogs = (int*)malloc(10*sizeof(int));
	int *vetCateg;
  vetCateg = (int*)malloc(5*sizeof(int));
	int *vetLet;
  vetLet= (int*)malloc(5*sizeof(int));
  int *guardCtegOrdem;
  guardCtegOrdem = (int*)malloc(5*sizeof(int));
	int guardletra;
	int guardCteg;
	int n;
	int i; 
  int controdada;    

  
	printf("\n *** JOGO AMEDONHA *** \n\n");
	printf("Quantos jogadores? ");
	scanf("%i", &n);
	while (n < 2 || n > 10){
		printf("\nNesse jogo participam de 2 até 10 jogadores! Insira outra quantidade de jogadores: ");
		scanf("%i", &n);
	} 
	jogador *j = (jogador *)malloc(n * sizeof(jogador)); //vetor de struct com informações sobre os jogadores

  //Matriz que guarda os nomes dos jogadores.
	char **nomesjog;
	nomesjog = malloc(n * sizeof(char *));
	for (i = 0; i < n; i++){
		nomesjog[i] = malloc(13 * sizeof(char));
	}

	for (i = 0; i < n; i++){
		printf("\nQual o nome do jogador %i? ", i + 1);
		scanf("%s", j[i].nome);
		while (strlen(j[i].nome) > 12){
			printf("\nERROR: O nome do jogador %i ultrapassa o limite de 12 letras por nome de jogador, digite outro nome: ", i + 1);
			scanf("%s", j[i].nome);
		}
    strcpy(nomesjog[i], j[i].nome);
	}

	controdada = 0; //conta a quantidade de rodadas que sempre serão 5, ou seja uma partida inteira.
  
	getchar(); // consumir o newline character
	for (i = 0; i < 5; i++){
    if(i == 0){
      verificLet(controdada, vetLet, &guardletra); // determina a letra
		  verificCateg(controdada, vetCateg, &guardCteg); // determina a categoria
		  jogrodada(n, nomesjog, vetordemjogs); //determina a ordem dos jogadores
      printf("\n");
      enterLimpTela2(controdada);
		  tempojogadores(vetordemjogs, n, &guardletra, &guardCteg, nomesjog, j,controdada, guardCtegOrdem); // recebe as respostas dos jogadores, calcula o tempo de cada jogador, calcula a potuação dos jogadores.
      mostraTabela(guardCtegOrdem, &guardCteg, controdada, j, n);
    }else{
      enterLimpTela2(controdada);
      verificLet(controdada, vetLet, &guardletra); // determina a letra
		  verificCateg(controdada, vetCateg, &guardCteg); // determina a categoria
		  jogrodada(n, nomesjog, vetordemjogs); //determina a ordem dos jogadores
      printf("\n");
      enterLimpTela2(controdada);
		  tempojogadores(vetordemjogs, n, &guardletra, &guardCteg, nomesjog, j,controdada, guardCtegOrdem);
       // recebe as respostas dos jogadores, calcula o tempo de cada jogador, calcula a potuação dos jogadores.
      mostraTabela(guardCtegOrdem, &guardCteg, controdada, j, n);
    }
		controdada += 1;
	}
  mostraResultado(j,n); // determina o jogador ganhador.

	for (i = 0; i < n; i++){
		free(nomesjog[i]);
	}
	free(nomesjog);
  free(vetordemjogs);
  free(vetCateg);
  free(vetLet);
  free(guardCtegOrdem);
}