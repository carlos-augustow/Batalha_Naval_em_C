#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nLinhas = 20;
int nColunas = 20;
void populaMatriz(char matriz[nLinhas][nColunas]) {
  int linha;
  int coluna;
  printf("\t");
  for (linha = 0; linha < nLinhas; linha++) {
    for (coluna = 0; coluna < nColunas; coluna++) {
      matriz[linha][coluna] = '#';
    }
  }
}
void limpaTela() { system("clear"); };
void imprimeMatriz(char matriz[nLinhas][nColunas]) {
  printf("\e[H\e[2J");
  int linha, coluna;
  for (int numeros = 0; numeros <= nColunas; numeros++) {
    if (numeros == 0) {
      printf("%c\t", ' ');
      numeros++;
    }
    printf("%d\t", numeros);
  }
  printf("\n");
  char alphabet[27] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (linha = 0; linha < nLinhas; linha++) {
    printf("%c\t", alphabet[linha + 1]);
    for (coluna = 0; coluna < nColunas; coluna++) {
      printf("%c\t", matriz[linha][coluna]);
    }
    printf("\n");
  }
}
int trocaLetraPorNumero(char letra) {
  int numero;
  if (letra == 'a' || letra == 'A') {
    numero = 0;
  } else if ((letra == 'b' || letra == 'B')) {
    numero = 1;
  } else if ((letra == 'c' || letra == 'C')) {
    numero = 2;
  } else if ((letra == 'd' || letra == 'D')) {
    numero = 3;
  } else if ((letra == 'e' || letra == 'E')) {
    numero = 4;
  } else if ((letra == 'f' || letra == 'F')) {
    numero = 5;
  } else if ((letra == 'g' || letra == 'G')) {
    numero = 6;
  } else if ((letra == 'h' || letra == 'H')) {
    numero = 7;
  } else if ((letra == 'i' || letra == 'I')) {
    numero = 8;
  } else if ((letra == 'j' || letra == 'J')) {
    numero = 9;
  } else if ((letra == 'k' || letra == 'K')) {
    numero = 10;
  } else if ((letra == 'l' || letra == 'L')) {
    numero = 11;
  } else if ((letra == 'm' || letra == 'M')) {
    numero = 12;
  } else if ((letra == 'n' || letra == 'N')) {
    numero = 13;
  } else if ((letra == 'o' || letra == 'O')) {
    numero = 14;
  } else if ((letra == 'p' || letra == 'P')) {
    numero = 15;
  } else if ((letra == 'q' || letra == 'Q')) {
    numero = 16;
  } else if ((letra == 'r' || letra == 'R')) {
    numero = 17;
  } else if ((letra == 's' || letra == 'S')) {
    numero = 18;
  } else if ((letra == 't' || letra == 'T')) {
    numero = 19;
  } else if ((letra == 'u' || letra == 'U')) {
    numero = 20;
  } else if ((letra == 'v' || letra == 'V')) {
    numero = 21;
  } else if ((letra == 'w' || letra == 'W')) {
    numero = 22;
  } else if ((letra == 'x' || letra == 'X')) {
    numero = 23;
  } else if ((letra == 'y' || letra == 'Y')) {
    numero = 24;
  } else if ((letra == 'z' || letra == 'Z')) {
    numero = 25;
  }
  return numero;
};

void colocaNavio(char matriz[nLinhas][nColunas], int i, char *jogador1,
                 char *jogador2, int rodadas) {
  char letraLin;
  int numeroCol;
  char verticalOuHorizontal;
  int cont = 0;
  char jogadorDaVez[50];
  if ((rodadas % 2) == 1) {
    strcpy(jogadorDaVez, jogador2);
  } else {
    strcpy(jogadorDaVez, jogador1);
  }
  printf("Quem coloca os navios desta vez: %s\n", jogadorDaVez);
  printf("Você quer que o navio seja posicionado virtical ou horizontalmente? "
         "digite v ou h\t");
  scanf("%c", &verticalOuHorizontal);
  getchar();
  if (verticalOuHorizontal == 'v' || verticalOuHorizontal == 'V') {
    printf("Digite a linha (letra) desejada:\t");
    scanf("%c", &letraLin);
    getchar();
    printf("\n");
    printf("Digite a coluna (numero) desejada:\t");
    scanf("%d", &numeroCol);
    printf("%c\n", letraLin);
    printf("%d\n", numeroCol);
    getchar();
    numeroCol = numeroCol - 1;
    printf("\n");
    int novaLinha = trocaLetraPorNumero(letraLin);
    int maxLinha = novaLinha + 5;
    for (int minLin = novaLinha; minLin < maxLinha; minLin++) {
      matriz[minLin][numeroCol] = '@';
      imprimeMatriz(matriz);
    }
  } else if (verticalOuHorizontal == 'h' || verticalOuHorizontal == 'H') {
    printf("Digite a linha (letra) desejada:\t");
    scanf("%c", &letraLin);
    getchar();
    printf("\n");
    printf("Digite a coluna (numero) desejada:\t");
    scanf("%d", &numeroCol);
    printf("%c\n", letraLin);
    printf("%d\n", numeroCol);
    getchar();
    numeroCol = numeroCol - 1;
    printf("\n");
    printf("\n");
    int novaLinha = trocaLetraPorNumero(letraLin);
    int maxColuna = numeroCol + 5;
    for (int minCol = numeroCol; minCol < maxColuna; minCol++) {
      matriz[novaLinha][minCol] = '@';
      imprimeMatriz(matriz);
    }
  }
}

void zeraMatriz(char matriz[nLinhas][nColunas]) {
  for (int linha = 0; linha < nLinhas; linha++) {
    for (int coluna = 0; coluna < nColunas; coluna++) {
      matriz[linha][coluna] = '#';
    }
  }
  imprimeMatriz(matriz);
}

int quantidadeNavios(char board[nLinhas][nColunas]){
  int j;
  int navios=0; 
  int acertos=0; 
  int linhas; 
  int colunas;

  //Verifico na horizontal
  for(linhas=0 ; linhas < nLinhas ; linhas++ ){
    for(colunas=0 ; colunas < nColunas ; colunas++ ){
      if (acertos==5){
        navios++;
        acertos=0;
      }
      if(board[linhas][colunas]=='*'){ //Se o tiro acertou
        acertos++;
      }else {
        acertos=0;
      }
    }
    printf("\n");
  }
  acertos=0;
  //Verifico na vertical
  for(colunas=0 ; colunas < nColunas ; colunas++ ){
    for(linhas=0 ; linhas < nLinhas ; linhas++ ){
      if (acertos==5){
        navios++;
        acertos=0;
      }
      if(board[linhas][colunas]=='*'){ //Se o tiro acertou
        acertos++;
      }else {
        acertos=0;
      }
    }
    printf("\n");
  }
  return navios;
}

int palpitesPosicoes(char matriz[nLinhas][nColunas],
                     char matrizPalipites[nLinhas][nColunas], int rodadas,
                     char *jogador1, char *jogador2) {
  int contadorAcertos = 0;
  int chances = 30;
  int contadorErros = 0;
  int contadorTentativas = 0;
  int contadorNavios = 0;
  char jogadorDaVez[50];
  if ((rodadas % 2) == 1) {
    strcpy(jogadorDaVez, jogador1);
  } else {
    strcpy(jogadorDaVez, jogador2);
  }

  for (int i = 0; i < 30; i++) {
    char a;
    char palpiteLinha;
    int palpiteColuna;
    printf("\n");
    printf("Quem joga: %s\n", jogadorDaVez);
    printf("Chances: %d\n", chances);
    printf("Tentativas: %d\n", contadorTentativas);
    printf("Acertos: %d\n", contadorAcertos);
    printf("Erros: %d\n", contadorErros);
    printf("Navios: %d\n", contadorNavios);
    printf("Digite a linha (Letra) do palpite:\t");
    scanf("%c", &palpiteLinha);
    getchar();
    printf("\n");
    printf("Digite a coluna (numero) do palpite:\t");
    scanf("%d", &palpiteColuna);
    getchar();
    palpiteColuna = palpiteColuna - 1;
    palpiteLinha = trocaLetraPorNumero(palpiteLinha);
    // verifica se o paplpite está correto ou errado
    if (matriz[palpiteLinha][palpiteColuna] == '@') {
      chances--;
      printf("Acertou!\n");
      printf("Digite qualquer letra para continuar\t");
      scanf("%c", &a);
      getchar();
      printf("\n");
      // printf("Você ainda tem %d chances\n", chances);
      contadorAcertos++;
      matrizPalipites[palpiteLinha][palpiteColuna] = '*';
      // verifica se o navio foi destruido e soma o contador de navios
      contadorNavios = quantidadeNavios(matrizPalipites);
      if (contadorAcertos == 15) {
        limpaTela();
        printf("Parabéns %s você ganhou!\n", jogadorDaVez);
        return 1;
        break;
      }
    } else {
      chances--;
      printf("Errou!\n");
      printf("Digite qualquer letra paraa continuar\t");
      scanf("%c", &a);
      getchar();
      printf("\n");
      // printf("Você ainda tem %d chances\n", chances);
      contadorErros++;
      matrizPalipites[palpiteLinha][palpiteColuna] = 'X';
    }
    if (chances == 0) {
      return 2;
      break;
    }
    imprimeMatriz(matrizPalipites);
    contadorTentativas++;
    }
  return 0;
}

int main() {
  // declara variaveis para receber os nomes dos jogadores
  limpaTela();
  char jogador1[50];
  char jogador2[50];
  char jogadorDaVez[50];
  int vezesGanhasJogador1;
  int vezesGanhasJogador2;
  char deNovo;
  char apagar;
  int rodada = 1;
  printf("Digite o nome do jogador 1:");
  scanf("%s", jogador1);
  getchar();
  printf("\n");
  printf("Digite o nome do jogador 2:");
  scanf("%s", jogador2);

  getchar();
  printf("\n");
  limpaTela();
  char **matriz;
  matriz = malloc(nLinhas);
  for (int i = 0; i < nLinhas; i++) {
    matriz[i] = malloc(nColunas);
  };

  do {
    populaMatriz(matriz);
    imprimeMatriz(matriz);
    char **matrizPalpites;
    matrizPalpites = malloc(nLinhas);
    for (int i = 0; i < nLinhas; i++) {
      matrizPalpites[i] = malloc(nColunas);
    };
    populaMatriz(matrizPalpites);
    printf("\n");
    for (int i = 0; i < 3; i++) {
      colocaNavio(matriz, i, jogador1, jogador2, rodada);
    };
    printf("Deseja esconder o tabuleiro?");
    scanf("%c", &apagar);
    getchar();
    if (apagar == 'v' || apagar == 'V') {
      limpaTela();
    }
    int ganhadorPaplipte =
        palpitesPosicoes(matriz, matrizPalpites, rodada, jogador1, jogador2);
    if (ganhadorPaplipte == 1) {
      vezesGanhasJogador1++;
    } else if (ganhadorPaplipte == 2) {
      vezesGanhasJogador2++;
    }
    printf("Rodadas jogadas: %d\n", rodada);
    printf("Rodadas ganhas pelo %s: ", jogador1);
    printf("%d\n", vezesGanhasJogador1);
    printf("Rodadas ganhas pelo %s: ", jogador2);
    printf("%d\n", vezesGanhasJogador2);
    printf("\n");

    printf("Desejam jogar uma nova rodada? S/N:\t");
    scanf("%c", &deNovo);
    getchar();
    if (deNovo == 's' || deNovo == 'S') {
      rodada++;
    }
    zeraMatriz(matriz);
    zeraMatriz(matrizPalpites);
  } while (deNovo == 's' || deNovo == 'S');
  printf("Fim de jogo");
  if (vezesGanhasJogador1 > vezesGanhasJogador2) {
    printf("Parabens %s! Você ganhou!", jogador1);
  } else {
    printf("Parabens %s! Você ganhou!", jogador2);
  }
  char qualquercoisa;
  printf("Digite qualquer letra para encerrar");
  scanf("%c", &qualquercoisa);

  return 0;
}