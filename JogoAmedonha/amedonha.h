
#ifndef amedonha_h
#define amedonha_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

typedef struct {
	char nome[100];
	int pontos;
  int pontos_rodadas[5];
  int tempo_total;
}jogador;

void limpatela();

int sorteajogs(int quantjog);

void jogrodada(int quantjog, char **nomesjog, int *v);

int sortCategoria();

void verificCateg(int quantrodada, int *vetor, int *indice);

int sortearLet();

void verificLet(int quantrodada, int *vetor, int *indice);

bool comecaLetra(const char *restrict string, const char *restrict comecoResp);

void upper(char *str);

void nomeComposto(char respostadojog[10][81],int indice_categoria, int i);

int conta_repeticao(char respostas[10][81], int i, int qtd_jogadores);

void pontuacaoJogadores(int *tempo_dos_jog, float *vetTempoJog,char respostadojog[10][81], int quantjog,int *vetordeordem, float *pontos_partida, jogador *jog, int controdada);

void tempojogadores(int *vetordeordem, int quantjog, int *indice_letra, int *indice_categoria, char **nomesjog, jogador *jog, int controdada,int *guardCtegOrdem);

void mostraTabela(int *guardCtegOrdem,int *indice_categoria, int controdada, jogador *jog,int quantjog);

void mostraResultado(jogador *jog, int n_jogadores);

void enterLimpTela2(int controdada);




#endif /*jogo_h */