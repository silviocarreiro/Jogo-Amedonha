## JOGO AMEDONHA ##

### Desenvolvido em C, o jogo Amedonha é baseado no clássico jogo “Adedonha”, mas com regras próprias e originais. A implementação foi feita seguindo os requisitos a seguir: ###

### Regras do Jogo
-  Nesse novo jogo, participam de 2 até 10 jogadores. No início do jogo, o
computador DEVE solicitar a indicação da quantidade de jogadores,
denominado N. O programa DEVE solicitar também o nome de cada um dos
jogadores. Para facilitar a visualização, cada nome poderá ter até 12 caracteres.
O programa DEVE validar este limite, solicitando novamente um nome até 12
caracteres caso um maior seja entrado.

-  Em seguida, o computador DEVE sortear uma letra (de A até Z, excluindo K, W
e Y).

-  Em cada rodada, o computador DEVE sortear e indicar a categoria, entre
“nomes de pessoas”, “nomes de cidade”, “nomes de animais”, “nomes de
comida” e “profissões”. De uma rodada para outra, as categorias NÃO DEVEM
se repetir.

-  Em seguida, o programa DEVE definir, por sorteio, a ordem de resposta dos N
jogadores, que DEVE mudar a cada rodada.

-  O primeiro jogador a responder, a ser chamado pelo nome, terá até (8 + 2 * N)
segundos para entrar a sua resposta pelo teclado. O segundo jogador terá 2
segundos a menos. O terceiro, 4 segundos a menos, e assim por diante.

-  Um jogador não é obrigado a utilizar todo o seu tempo para responder. Ao invés
disso, pode escolher responder o mais rapidamente possível, para dar menos
tempo para pensar ao próximo jogador.

-  Cada resposta deve conter até 30 caracteres. Caso esse limite seja extrapolado,
o programa deverá solicitar novamente, e só DEVE terminar a contagem do
tempo depois que uma resposta válida for entrada.

-  O programa DEVE verificar se a resposta entrada tem como inicial a letra
sorteada. Caso não seja, o programa DEVE solicitar novamente, e só deverá
terminar a contagem do tempo depois que uma resposta válida for entrada.

-  O tempo de resposta de cada jogador DEVE começar a ser contado a partir da
entrada da resposta do jogador anterior até que ele termine de entrar a sua
própria resposta.

-  Caso o jogador não consiga responder dentro do seu tempo, a resposta DEVE
ser ignorada.

-  Após a resposta de cada jogador, a tela deve ser limpa para que o programa
solicite a jogada do próximo jogador. Um jogador não deve ver a resposta de
seus antecessores.

-  As respostas da categoria “nome de pessoa” DEVEM ser de uma só palavra. Isto
é, respostas como “José Maria” ou “Antônio Carlos” NÃO DEVEM ser aceitas
Caso o usuário entre nomes compostos, apenas o primeiro nome deverá ser
considerado, se iniciar com a letra sorteada na rodada.

-  A pontuação de cada resposta equivale à quantidade de caracteres da resposta.

-  Caso dois ou mais jogadores entrem a mesma resposta, ignorando maiúsculas
e minúsculas, cada jogador terá como pontuação a fração da quantidade de
caracteres correspondente à quantidade de usuários com respostas iguais, com
arredondamento. Exemplo: Se quatro jogadores tiverem respondido
“Araraquara”, cada um fará jus a 10/4 = 2,5 = 3 pontos (arredondando).

-  Ao final de cada rodada, o programa deverá exibir as respostas de todos os
jogadores e, em seguida, uma tabela de pontuação parcial (caso ainda haja
rodada a ser jogada) ou final (caso seja o fim do jogo).

-  Caso seja o fim do jogo, o programa deverá indicar o jogador ganhador.

-  Caso haja empate em pontos de dois ou mais jogadores, o ganhador será
aquele que respondeu todas as rodadas no menor tempo, considerando a soma
dos tempos de todas as rodadas.

### Imagens do Jogo 

![image](https://user-images.githubusercontent.com/82840116/211883429-7f96539c-0f6a-4899-974d-2cd942595698.png)

![image](https://user-images.githubusercontent.com/82840116/211883613-eb63ebb3-aaa8-453e-8b05-4d3e3b18f5d9.png)

![image](https://user-images.githubusercontent.com/82840116/211883920-2eb739cd-2bd9-478e-bbd4-ef89c3f764fc.png)

![image](https://user-images.githubusercontent.com/82840116/211884487-1c49a087-f481-424d-9264-b7e557524634.png)

### Como Compilar 
- gcc -o nome_exec main.c amedonha.c
