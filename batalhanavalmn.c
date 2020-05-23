#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//inclusao de bibliotecas obs: usei umas paradas de c++ por conta para rodar, isso por conta de esta usando o celular

char* tabuleiroJ1[10][10];
char* tabuleiroJ2[10][10];
int tabuleiroJ1navios[14][2];
int tabuleiroJ2navios[14][2];
//tamanho do tabuleiro
using namespace std;

void pos_navios() {
  srand(time(NULL));
  // geração de numero aleatorio para a posilççao dos barcos
  int cont = 0;
  int coluna, linha, espacosNavio, sentido;

  int tamanho = 2;
  while (tamanho < 6) {
    sentido = rand() % 2;
    if (sentido == 0) {
      linha = rand() % 10;
      coluna = rand() % ((10 - tamanho) + 1);

      for (int i = 0; i < 14; i++) {
        if ( linha == tabuleiroJ1navios[i][0] && (coluna == tabuleiroJ1navios[i][1] || coluna + (tamanho - 1) >= tabuleiroJ1navios[i][1])  ) {
          linha = rand() % 10;
          coluna = rand() % ((10 - tamanho) + 1);
          i = 0;
        }
      }

    } else {
      linha = rand() % ((10 - tamanho) + 1);
      coluna = rand() % 10;


      for (int i = 0; i < 14; i++) {
        if ( (linha == tabuleiroJ1navios[i][0] || linha + (tamanho - 1) >= tabuleiroJ1navios[i][0] ) && coluna == tabuleiroJ1navios[i][1]) {
          linha = rand() % ((10 - tamanho) + 1);
          coluna = rand() % 10;
          i = 0;
        }
      }
    }

    espacosNavio = 0;
    while (espacosNavio < tamanho) {

      if (sentido == 0) {
        tabuleiroJ1navios[cont][0] = linha;
        tabuleiroJ1navios[cont][1] = coluna + espacosNavio;
      } else {
        tabuleiroJ1navios[cont][0] = linha + espacosNavio;
        tabuleiroJ1navios[cont][1] = coluna;
      }
	//preencher o barcos no tabuleiro
      espacosNavio++;
      cont++;
    }
    tamanho++;
  }

  cont = 0;
  tamanho = 2;
  while (tamanho < 6) {
    int sentido = rand() % 2;
    if (sentido == 0) {

      linha = rand() % 10;
      coluna = rand() % ((10 - tamanho) + 1);
      //gerandop de novo um numero aleatorio

      for (int i = 0; i < 14; i++) {

        if ( linha == tabuleiroJ2navios[i][0] && (coluna == tabuleiroJ2navios[i][1] || coluna + (tamanho - 1) >= tabuleiroJ2navios[i][1])  ) {
          linha = rand() % 10;
          coluna = rand() % ((10 - tamanho) + 1);
          i = 0;
        }
      }

    } else {
      linha = rand() % ((10 - tamanho) + 1);
      coluna = rand() % 10;

      for (int i = 0; i < 14; i++) {

        if (  (linha == tabuleiroJ2navios[i][0] || linha + (tamanho - 1) >= tabuleiroJ2navios[i][0] ) && coluna == tabuleiroJ2navios[i][1]) {
          linha = rand() % ((10 - tamanho) + 1);
          coluna = rand() % 10;
          i = 0;
        }
      }
    }

    espacosNavio = 0;
    while (espacosNavio < tamanho) {
      if (sentido == 0) {
        tabuleiroJ2navios[cont][0] = linha;
        tabuleiroJ2navios[cont][1] = coluna + espacosNavio;
      } else {
        tabuleiroJ2navios[cont][0] = linha + espacosNavio;
        tabuleiroJ2navios[cont][1] = coluna;
      }
      cont++;
      espacosNavio++;
    }
    tamanho++;
  }
}

void resetarTabuleiros() {
  for (int linha = 0; linha < 10; linha++)
    for (int coluna = 0; coluna < 10; coluna++)
      tabuleiroJ1[linha][coluna] = (char*)"  ~ |";

  for (int linha = 0; linha < 10; linha++)
    for (int coluna = 0; coluna < 10; coluna++)
      tabuleiroJ2[linha][coluna] = (char*)"  ~ |";
}

void printar_tabuleiro(char* tabuleiro[][10]) {
  int linha, coluna;

  printf("    0    1    2    3    4    5    6    7    8    9\n");
  printf("\n");
  for (linha = 0 ; linha < 10 ; linha++) {
    printf("%d ", linha);
    for (coluna = 0 ; coluna < 10 ; coluna++ ) {
      cout << tabuleiro[linha][coluna];
    }
    printf("\n");
    cout << "  --------------------------------------------------" << '\n';
    // foi usado cout e cin para substituir o printf e scanf
  }
  printf("\n");
}

void batalhaNaval() {
  resetarTabuleiros();
  pos_navios();
  int acertosJ1 = 0, acertosJ2 = 0;
  int tiro[2];
  char jogar;
  bool acerto;

  cout << "\t   BATALHA NAVAL" << '\n';

  while (acertosJ1 < 14 && acertosJ2 < 14) {
    cout << "Jogador 1 escolha a linha alvo do tiro" << '\n' << "Linha: ";
    cin >> tiro[0];
    cout << "Jogador 1 escolha a coluna alvo do tiro" << '\n' << "Coluna: ";
    cin >> tiro[1];

    while (tabuleiroJ2[tiro[0]][tiro[1]] != "  ~ |" ) {
      cout << "Voce ja atirou nessa posicao anteriormente. Verifique e tente novamente. \n\n";
      cout << "Jogador 1 escolha a linha alvo do tiro" << '\n' << "Linha: ";
      cin >> tiro[0];
      cout << "Jogador 1 escolha a coluna alvo do tiro" << '\n' << "Coluna: ";
      cin >> tiro[1];
    }

    for (int linha = 0; linha < 14; linha++) {
      if (tiro[0] == tabuleiroJ2navios[linha][0] && tiro[1] == tabuleiroJ2navios[linha][1] ) {
        tabuleiroJ2[tiro[0]][tiro[1]] = (char*)"  X |";
        acertosJ1++;
        cout << acertosJ1;
        acerto = true;
        break;
      } else {
        tabuleiroJ2[tiro[0]][tiro[1]] = (char*)"  E |";
        acerto = false;
      }
    }

    if (acerto) {
      cout << "Jogador 1 acertou um alvo!\n";
    } else {
      cout << "Jogador 1 atirou no mar.\n";
    }
    printar_tabuleiro(tabuleiroJ2);

    cout << "Jogador 2 escolha a linha alvo do tiro" << '\n' << "Linha: ";
    cin >> tiro[0];
    cout << "Jogador 2 escolha a coluna alvo do tiro" << '\n' << "Coluna: ";
    cin >> tiro[1];

    while (tabuleiroJ1[tiro[0]][tiro[1]] != "  ~ |" ) {
      cout << "Voce ja atirou nessa posicao anteriormente. Verifique e tente novamente. \n";
      cout << "Jogador 2 escolha a linha alvo do tiro" << '\n' << "Linha: ";
      cin >> tiro[0];
      cout << "Jogador 2 escolha a coluna alvo do tiro" << '\n' << "Coluna: ";
      cin >> tiro[1];
    }

    for (int linha = 0; linha < 14; linha++) {
      if (tiro[0] == tabuleiroJ1navios[linha][0] && tiro[1] == tabuleiroJ1navios[linha][1] ) {
        tabuleiroJ1[tiro[0]][tiro[1]] = (char*)"  X |";
        cout << acertosJ2;
        acerto = true;
        break;
      } else {
        tabuleiroJ1[tiro[0]][tiro[1]] = (char*)"  E |";
        acerto = false;
      }
      // confere se o jogador
    }

    if (acerto) {
      cout << "Jogador 2 acertou um alvo!\n";
    } else {
      cout << "Jogador 2 atirou no mar.\n";
    }

    printar_tabuleiro(tabuleiroJ1);
  }
  if (acertosJ1 == 14) {
    cout << "Jogador 1 venceu a partida. Parabens!\n";
  } else if (acertosJ2 == 14) {
    cout << "Jogador 2 venceu a partida. Parabens!\n";
  } else {
    cout << "A partida terminou em empate\n";
  }

  cout << "\nDeseja jogar novamente? (S/N): ";
  cin >> jogar;
  while (jogar != 'S' && jogar != 'N') {
    cout << "\nDigite apenas S para sim e N para nao. Perceba que ambos estao em caixa alta: ";
    cin >> jogar;
}
  if (jogar == 'S') {
    batalhaNaval();
  }
}

int main() {
  batalhaNaval();
}
