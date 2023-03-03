
#include "amedonha.h"

// função para limpar tela 
void limpatela(){
   system("clear");
}

//função para sortear os nomes dos jogadores
int sorteajogs(int quantjog){
	int x = rand() % quantjog;
	return x;
}

// Função que não permite que os jogadores se repitam
void jogrodada(int quantjog, char **nomesjog, int *v){
	int k, y, i, j;
	int cont;
	int *vetor;
    vetor = (int*)malloc(quantjog*sizeof(int));

	for (i = 0; i < quantjog; i++){
		k = sorteajogs(quantjog);
		if (i == 0){
			vetor[i] = k;
		}
		else{
			for (j = 0; j < i; j++){
				if (vetor[j] == k){
					cont = 1;
				}
			}
			if (cont == 0){
				vetor[i] = k;
			}
			else{
				while (cont != 0){
					cont = 0;
					k = sorteajogs(quantjog);
					for ( j = 0; j < i; j++){
						if (vetor[j] == k){
							cont = 1;
						}
					}
				}
				vetor[i] = k;
			}
		}
	}
	printf("\nA ordem desta rodada sera:\n");
	for (y = 0; y < quantjog; y++){
		printf("\n%i. %s", y + 1, nomesjog[vetor[y]]);
	}
	for (y = 0; y < quantjog; y++){ 
		v[y] = vetor[y];
	}
  free(vetor);
}

//função para sortear o indice das categorias 
int sortCategoria(){
	int x = rand() % 5;
	return x;
}

//função que permite que as categorias não se repitam durante as rodadas
void verificCateg(int quantrodada, int *vetor, int *indice){
	int cont = 0;
  int i;
	int recebsort = sortCategoria();
	if (quantrodada == 0){
		vetor[quantrodada] = recebsort;
	}
	else{
		for (i = 0; i < quantrodada; i++){
			if (vetor[i] == recebsort){
				cont = 1;
			}
		}
		if (cont == 0){
			vetor[quantrodada] = recebsort;
		}
		else{
			while (cont != 0){
				cont = 0;
				recebsort = sortCategoria();
				for (i = 0; i < quantrodada; i++){
					if (vetor[i] == recebsort){
						cont = 1;
					}
				}
			}
			vetor[quantrodada] = recebsort;
		}
	}
	static const char *categ[] = {"Nomes de pessoas", "Nomes de cidade", "Nomes de Animais", "Nomes de Comida", "Profissoes"};
	*indice = recebsort;
	printf("\nA categoria desta rodada e: %s", categ[recebsort]);
}

//função para sortear o indice das letras
int sortearLet(){
	int x = rand() % 23;
	return x;
}

//função que permite que as letras não se repitam durante as rodadas
void verificLet(int quantrodada, int *vetor, int *indice){
	int cont = 0;
  int i;
	int recebsort = sortearLet();
	if (quantrodada == 0){
		vetor[quantrodada] = recebsort;
	}
	else{
		for (i = 0; i < quantrodada; i++){
			if (vetor[i] == recebsort){
				cont = 1;
			}
		}
		if (cont == 0){
			vetor[quantrodada] = recebsort;
		}
		else{
			while (cont != 0){
				cont = 0;
				recebsort = sortearLet();
				for (i = 0; i < quantrodada; i++){
					if (vetor[i] == recebsort){
						cont = 1;
					}
				}
			}
			vetor[quantrodada] = recebsort;
		}
	}
	static const char *letras[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Z"};
	*indice = recebsort;
	printf("\nA letra desta rodada e: %s", letras[recebsort]);
}

//função para verificar se a resposta dos jogadores inicia com a letra sorteada da rodada.
bool comecaLetra(const char *restrict string, const char *restrict comecoResp){
	while (*comecoResp){
		if (*comecoResp++ != *string++){
      	return 0;
    }
	}
	return 1;
}

//função que coloca caracteres de uma string em caixa alta
void upper(char *str){
  for(int i = 0; str[i]; i++){
    str[i] = toupper(str[i]);
  }
}

//função que separa o primeiro nome caso seja nome composto
void nomeComposto(char respostadojog[10][81],int indice_categoria, int i){
  if(indice_categoria == 0){
      char *primeiro_nome;
      primeiro_nome = (char *) malloc(81*sizeof(char));
      //[81];

      int j;
      int verifica = 0; //verifica se a palavra tem espaço ou não
      for(j= 0; j<strlen(respostadojog[i]); j++){
        if(respostadojog[i][j] == ' '){
          verifica = 1;
        }
      }

      //se tiver espaço pega só o priumeiro nome
      if(verifica==1){
        int caracter = 0;
        while(respostadojog[i][caracter] != ' '){
          primeiro_nome[caracter] = respostadojog[i][caracter];
          caracter++;
        }
        strcpy(respostadojog[i],primeiro_nome);
        }
        free(primeiro_nome);
    }
}

//função que verifica se a palavra é repetida e conta quantas iguais a ela tem no vetor de respostas dos jogadores
int conta_repeticao(char respostas[10][81], int i, int qtd_jogadores){
  int k,j;
  int res; //repetições
	// passa tudo pra upper
	for(k = 0; k < qtd_jogadores; k++) {
		upper(respostas[k]);
	}

	res = 0;
	for(j = 0; j < qtd_jogadores; j++) {
		if(strcmp(respostas[j], respostas[i]) == 0){
			res++;
    }
	}
	return res;
}

//função que calcula a pontuação dos jogadores
void pontuacaoJogadores(int *tempo_dos_jog, float *vetTempoJog,char respostadojog[10][81], int quantjog,int *vetordeordem, float *pontos_partida, jogador *jog, int controdada){
  for (int i = 0; i < quantjog; i++) { 
    //numero de repetições
    int repeticoes = conta_repeticao(respostadojog, i, quantjog); 

    
    if (tempo_dos_jog[i] > vetTempoJog[i]){ //caso em que passa do tempo
			pontos_partida[i] = 0;
		}
		else{
      int j;
			float espacos = 0;
			int tamanho_original = strlen(respostadojog[i]);
			for (j = 0; j < tamanho_original; j++){
				if (respostadojog[i][j] == ' '){
					espacos++;
				}
			}
			pontos_partida[i] = ceil((tamanho_original - espacos)/repeticoes);  
		}
    //colcoca a pontuação do jogador daquela rodada no seu vetor de pontos da struct.
    jog[vetordeordem[i]].pontos_rodadas[controdada] = pontos_partida[i]; 

    //soma os pontos na struct
		jog[vetordeordem[i]].pontos = jog[vetordeordem[i]].pontos + pontos_partida[i]; 
  }
}

//Função: Determina o tempo dos jogadores, recebe as respostas dos jogadores, calcula a pontuação dos jogadores
void tempojogadores(int *vetordeordem, int quantjog, int *indice_letra, int *indice_categoria, char **nomesjog, jogador *jog, int controdada,int *guardCtegOrdem){
	int i,decremento;
	//int verificatempo;

	char respostadojog[10][81];


  int *tempo_dos_jog;
  tempo_dos_jog = (int*)malloc(quantjog*sizeof(int));
  //guarda os tempos que cada jogador demorou pra responder;

	struct timeval inicio, fim;
	double tempo;
	float tamanho;
  
  float *pontos_partida;
  pontos_partida = (float*)malloc(quantjog*sizeof(float));//vetor com pontuação dos jogadores na partida

	static const char *categ[] = {"Nomes de pessoas", "Nomes de cidade", "Nomes de Animais", "Nomes de Comida", "Profissoes"};

	static const char *letras[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Z"};

	decremento = 2;

  //Calcula o tempo que cada jogador tem pra responder e guarda no vetor vetTempo
	float *vetTempoJog;
  vetTempoJog = (float*)malloc(quantjog*sizeof(float));

	for (i = 0; i < quantjog; i++){
		if (i == 0){
			vetTempoJog[i] = 8 + 2 * quantjog;
		}
		else{
			vetTempoJog[i] = (8 + 2 * quantjog - decremento);
			decremento += 2;
		}
	}

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Recebe as respostas dos jogadores e analisa as situações: Quantidade de caracteres de resposta acima de 30 e respostas que não inciam com a letra sorteada. Verifica se passou do tempo limite e soma o tempo dos usuários na struct.
	for (i = 0; i < quantjog; i++){
		gettimeofday(&inicio, NULL);
  
		printf("\n");
		printf("\n%s, voce deve entrar com um(a) '%s' com a letra '%s' em %0.f segundos: ", jog[vetordeordem[i]].nome, categ[*indice_categoria], letras[*indice_letra], vetTempoJog[i]);

		fgets(respostadojog[i], 81, stdin);

    respostadojog[i][strlen(respostadojog[i]) - 1] = 0; //Retirando o newline 
    limpatela();
    
    //[81]; //string que vai receber a resposta do jogador para ser colocada em caixa alta
    char *comparador;
    comparador = (char *) malloc(81*sizeof(char));
    
    //copia a resposta do jogador para a string comparador.
    strcpy(comparador, respostadojog[i]); 

    upper(comparador); //deixando resposta em caixa alta

		while (strlen(respostadojog[i]) > 30 || comecaLetra(comparador, letras[*indice_letra]) == 0){
      if(strlen(respostadojog[i]) > 30){
        printf("\nVoce excedeu o limite de caracteres! Digite outra resposta com no maximo 30 caracteres que inicie com a letra '%s' \n ",letras[*indice_letra] );
      }
		  if(comecaLetra(comparador, letras[*indice_letra]) == 0){
        printf("\nA sua resposta não inicia com a letra sorteada nesta rodada! Digite uma resposta com a letra '%s'\n ",letras[*indice_letra]);
      }
      printf("\nDigite a sua resposta: ");
			fgets(respostadojog[i], 81, stdin);
			respostadojog[i][strlen(respostadojog[i]) - 1] = 0;
      strcpy(comparador, respostadojog[i]); //colocando nova resposta no comparador
      upper(comparador); //colocando comparador em caixa alta
			//gettimeofday(&fim, NULL);
      limpatela();
		}

    //nomeComposto(char respostadojog[10][81],int indice_categoria, int i)
    //Verifica se a categoria é 'Nome de pessoas', pois se for nome composto ele recebe apenas o primeiro nome.
    nomeComposto(respostadojog, *indice_categoria, i);
    
		gettimeofday(&fim, NULL);
    limpatela();
		tempo = (double)(fim.tv_usec - inicio.tv_usec) / 1000000 + (double)(fim.tv_sec - inicio.tv_sec);
    tempo_dos_jog[i] = tempo; //coloca o tempo dos jogadores na ordem do vetor vetordeordem
    if (tempo_dos_jog[i] > vetTempoJog[i]){
      int j;
			for (j = 0; j < 81; j++){
				respostadojog[i][j] = '\0';
			}
			printf("\nVocê levou %0.f segundos para digitar a sua resposta! Sua resposta não será considerada nesta categoria.\n", tempo);
		}

    //coloca o tempo acumulado de cada jogador na struct.
    jog[vetordeordem[i]].tempo_total = jog[vetordeordem[i]].tempo_total + tempo; 
	}

  //printando as jogadas realizadas
  printf("\nJogadas realizadas:");
  for(i=0; i<quantjog; i++){
    printf("\n%s: %s",jog[vetordeordem[i]].nome, respostadojog[i]);
  }
  
  //contando a pontuação de cada jogador na rodada
  pontuacaoJogadores( tempo_dos_jog, vetTempoJog, respostadojog, quantjog, vetordeordem, pontos_partida, jog, controdada);

  free(pontos_partida);
  free(vetTempoJog);
}
 
//Imprimindo tabela de pontuação dos jogadores: tabela de escores e tabela final.
void mostraTabela(int *guardCtegOrdem,int *indice_categoria, int controdada, jogador *jog, int quantjog){
  static const char *categ[] = {"Nomes de pessoas", "Nomes de cidade ", "Nomes de Animais", "Nomes de Comida ", "   Profissoes   "};
  
  int j,i;
  guardCtegOrdem[controdada] = *indice_categoria;
  if(controdada == 4){
    printf("\n\n\nRESULTADO FINAL:\n\n");
  }else{
    printf("\n\nConcluida a rodada, essa e a tabela de escores:\n\n");
  }
  printf("             ");
  for(j=0; j<=controdada; j++){
    printf(" %16s|", categ[guardCtegOrdem[j]]);
  }
  printf("  Total parcial  |\n");
  for(i = 0; i<quantjog; i++){
    printf("%12s:", jog[i].nome);
    for(int j=0; j<=controdada; j++){
      printf("%9i", jog[i].pontos_rodadas[j]);
      printf("        |");
    }
    printf("%9i", jog[i].pontos);
    printf("        |\n");
  }
}

//Função que mostra quem foi o jogador ganhador (ganhando por mais pontos ou por desempate de menor tempo).
void mostraResultado(jogador *jog, int n_jogadores){
  int indice_maior; //indice do ganhador
  int i;

  printf("\nTempo total dos Jogadores:\n");
  for(i=0; i<n_jogadores;i++){
    printf("%12s: %8is\n",jog[i].nome, jog[i].tempo_total);
  }

  int maior_pontuacao = 0; //maior valor 
  int tempo_do_ganhador = 0; //tempo do ganhador (ganha quem tiver menor tempo no desempate)
  for(i=0; i<n_jogadores; i++){
    if(jog[i].pontos > maior_pontuacao){
      indice_maior=i;
      maior_pontuacao = jog[i].pontos;
      tempo_do_ganhador = jog[i].tempo_total;
    }
    if(jog[i].pontos == maior_pontuacao){
      if(tempo_do_ganhador > jog[i].tempo_total){
        indice_maior=i;
        tempo_do_ganhador = jog[i].tempo_total;
      }
    }
  }
  
  printf("\n\nO ganhador é: %s\n", jog[indice_maior].nome);
}

//função para iniciar a nova rodada e limpar a tela do usuário.
void enterLimpTela2(int controdada){
  char *resposta;
  resposta = (char *) malloc(100*sizeof(char));;
  if(controdada == 0){
     printf("\nTecle [Enter] para iniciar a rodada: ");
     fgets(resposta, 100, stdin);
    while(resposta[0] !=  '\n') {
        printf("\nTecle [Enter] para iniciar a rodada: ");
        fgets(resposta, 100, stdin);
    }
  limpatela();
  }else{
     printf("\nTecle [Enter] para iniciar a proxima rodada: ");
     fgets(resposta, 100, stdin);
    while(resposta[0] !=  '\n') {
        printf("\nTecle [Enter] para iniciar a proxima rodada: ");
        fgets(resposta, 100, stdin);
    }
  limpatela();
  }
  free(resposta);
}