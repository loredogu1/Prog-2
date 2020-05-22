#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
// bibliotecas. obs usei  c++ por conta que esatva fanzendo pelo celular

#define AGUA '~'
#define ERRO 'X'
#define TAMANHO 10
#define SUBMARINO 'S'
#define DESTROYER 'D'
#define HIDROAVIAO 'H'
#define PORTAAVIAO 'P'
//definição de 
char arena[TAMANHO][TAMANHO], arena_inimigo[TAMANHO][TAMANHO];
int linha, coluna,i,j;

typedef enum {BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,
              LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE
             } COLORS;

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

void textcolor (int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}

//Dados das embarcações do jogador
struct embarcacoes
{
    int submarino;
    int destroyer;
    int hidro_aviao;
    int porta_aviao;
};

typedef struct embarcacoes barcos;

barcos qt_barcos = {3, 3, 2, 2};

//Dados do jogador
struct almirante
{
    char nome[100];
    int placar;
    int disparos;
    struct embarcacoes;
};

struct almirante jogador = {.disparos = 999};
int vida_inimiga;

vida_inimiga = 36;

void menu () //Exibe menu principal do jogo
{
    textcolor(YELLOW);
    char opcao;

    puts("                      -------------------------------------------");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |             BATALHA NAVAL               |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |              1 - JOGAR                  |");
    puts("                      |              2 - MULTIPLAYER            |");
    puts("                      |              3 - CRÉDITOS               |");
    puts("                      |              4 - SAIR                   |");
    puts("                      |                                         |");
    puts("                      |              PROGRAMADO POR             |");
    puts("                      |              |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      -------------------------------------------");

    opcao = getch();

    switch(opcao)
    {
    case '1' :
        system("cls");
        introducao();
        break;

    case '3' :
        system("cls");
        creditos();
        break;

    case '4' :
        exit(1);

    default :
        system("cls");
        menu();
        break;
    }
}


void creditos () //Exibe os nomes dos criadores do jogo
{
    textcolor(YELLOW);
    char opcao;

   printf ("                      -------------------------------------------");
    puts("                      |                                         |");
    puts("                      |                CREDITOS                 |");
    puts("                      |                                         |");
    puts("                      |              PROGRAMADORES              |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |              GAME DESIGN                |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |                                         |");
    puts("                      |  1 - Voltar                             |");
    puts("                      |                                         |");
    puts("                      -------------------------------------------");

    opcao = getch();

    switch(opcao)
    {

    case '1' :
        system("cls");
        menu();
        break;

    default :
        system("cls");
        creditos();
        break;
    }

}


void introducao () //Vai explicar a historia do jogo e pedir os nomes
{

    char frase1[] = "Bem-vindo ao Batalha Naval";
    char frase2[] = "\nVocê é um almirante que tem a missão de derrubar as embarcações inimigas e dar vantagem para o seu país na guerra";
    char frase3[] = "\n\nQual seu nome? ";
    int cont;

    //Laços que irão imprimir os três vetores
    for(cont = 0; frase1[cont] != '\0'; cont = cont + 1)
    {
        putchar(frase1[cont]);
        Sleep(20);
    }

    for(cont = 0 ; frase2[cont] != '\0'; cont = cont + 1)
    {
        putchar(frase2[cont]);
        Sleep(20);
    }

    for(cont = 0; frase3[cont] != '\0'; cont = cont + 1)
    {
        putchar(frase3[cont]);
        Sleep(20);
    }

    fflush(stdin);
    fgets(jogador.nome, 100, stdin);
    system("cls");
    prepara_tabuleiro();
    imprime_submarino();
    imprime_destroyer();
    imprime_hidroaviao();
    imprime_portaaviao();
    imprimeTabuleiro();
    controles();
}

//Define e imprime tabuleiro
void imprime_submarino ()
{
    int l, c;

    do
    {
        l = rand() % TAMANHO;
        c = rand() % TAMANHO;

        if(arena_inimigo[l][c] == AGUA)
        {
            arena_inimigo[l][c] = SUBMARINO;
            qt_barcos.submarino--;
        }
    }
    while(qt_barcos.submarino != 0);
}

//Define e imprime Destroyer
void imprime_destroyer ()
{
    int l, c, direcao;

    do
    {
        direcao = rand() % 2;
        l = rand() % TAMANHO;
        c = rand() % TAMANHO;

        if(direcao == 0)
        {
            if(l == TAMANHO || l > TAMANHO - 2)
            {
                if(arena_inimigo[l][c] == AGUA && arena_inimigo[l - 1][c] == AGUA)
                for(i = l; i < l + 2; i++)
                {
                        arena_inimigo[i - 2][c] = DESTROYER;
                }
                qt_barcos.destroyer--;

            }
            else
            {
                if(arena_inimigo[l][c] == AGUA && arena_inimigo[l + 1][c] == AGUA)
                for(i = l; i < l + 2; i++)
                {
                        arena_inimigo[i][c] = DESTROYER;
                }
                qt_barcos.destroyer--;

            }

        }
        else
        {
            if(c == TAMANHO || c > TAMANHO - 2)
            {
                if(arena_inimigo[l][c] == AGUA && arena_inimigo[l][c - 1] == AGUA)
                for(i = c; i < c + 2; i++)
                {
                        arena_inimigo[l][i - 2] = DESTROYER;
                }
                qt_barcos.destroyer--;

            }
            else
            {
                if(arena_inimigo[l][c] == AGUA && arena_inimigo[l][c + 1] == AGUA)
                for(i = c; i < c + 2; i++)
                {
                        arena_inimigo[l][i] = DESTROYER;
                }
                qt_barcos.destroyer--;

            }
        }

    } while (qt_barcos.destroyer != 0);
}

//Define e imprime Hidro-Avião
void imprime_hidroaviao ()
{
    int l, c;

    do
    {
        l = rand() % TAMANHO;
        c = rand() % TAMANHO;

        if(l == 0 && c == 0 && arena_inimigo[l][c] == AGUA &&
           arena_inimigo[l + 1][c + 1] == AGUA && arena_inimigo[l][c + 2] == AGUA)
        {
                arena_inimigo[l][c] = HIDROAVIAO;
                arena_inimigo[l + 1][c + 1] = HIDROAVIAO;
                arena_inimigo[l][c + 2] = HIDROAVIAO;
                qt_barcos.hidro_aviao--;

        } else if(l == 0 && c == TAMANHO && arena_inimigo[l][c] == AGUA &&
                  arena_inimigo[l - 1][c - 1] == AGUA && arena_inimigo[l - 1][c + 1] == AGUA)
        {
            arena_inimigo[l][c] = HIDROAVIAO;
            arena_inimigo[l - 1][c - 1] = HIDROAVIAO;
            arena_inimigo[l - 1][c + 1] = HIDROAVIAO;
            qt_barcos.hidro_aviao--;

        } else if(l == TAMANHO && c == 0 && arena_inimigo[l][c] == AGUA &&
                  arena_inimigo[l + 1][c - 1] == AGUA && arena_inimigo[l][c - 2] == AGUA)
        {
            arena_inimigo[l][c] = HIDROAVIAO;
            arena_inimigo[l + 1][c - 1] = HIDROAVIAO;
            arena_inimigo[l][c - 2] = HIDROAVIAO;
            qt_barcos.hidro_aviao--;

        } else if(l == TAMANHO && c == TAMANHO && arena_inimigo[l][c] == AGUA &&
                   arena_inimigo[l - 1][c - 1] == AGUA && arena_inimigo[l][c - 2] == AGUA)
        {
            arena_inimigo[l][c] = HIDROAVIAO;
            arena_inimigo[l - 1][c - 1] = HIDROAVIAO;
            arena_inimigo[l][c - 2] = HIDROAVIAO;
            qt_barcos.hidro_aviao--;

        } else if(l < TAMANHO && c <= TAMANHO - 2 &&
                  arena_inimigo[l][c] == AGUA && arena_inimigo[l + 1][c + 1] == AGUA
                  && arena_inimigo[l][c + 2] == AGUA)
        {
            arena_inimigo[l][c] = HIDROAVIAO;
            arena_inimigo[l + 1][c + 1] = HIDROAVIAO;
            arena_inimigo[l][c + 2] = HIDROAVIAO;
            qt_barcos.hidro_aviao--;

        } else if(l > 0 && (c > 0 || c < TAMANHO) &&
                  arena_inimigo[l][c] == AGUA && arena_inimigo[l + 1][c - 1] == AGUA
                  && arena_inimigo[l + 1][c + 1] == AGUA)
        {
            arena_inimigo[l][c] = HIDROAVIAO;
            arena_inimigo[l + 1][c - 1] = HIDROAVIAO;
            arena_inimigo[l + 1][c + 1] = HIDROAVIAO;
            qt_barcos.hidro_aviao--;

        } else if(l < TAMANHO - 2 && (c > 2 || c < TAMANHO - 8) &&
                  arena_inimigo[l][c] == AGUA && arena_inimigo[l + 1][c + 1] == AGUA
                  && arena_inimigo[l + 2][c] == AGUA)
        {
            arena_inimigo[l][c] = HIDROAVIAO;
            arena_inimigo[l + 1][c + 1] = HIDROAVIAO;
            arena_inimigo[l + 2][c] = HIDROAVIAO;
            qt_barcos.hidro_aviao--;

        } else if (l < TAMANHO - 2 && c > 0 &&
                   arena_inimigo[l][c] == AGUA && arena_inimigo[l + 1][c - 1] == AGUA
                   && arena_inimigo[l + 2][c] == AGUA)
        {
            arena_inimigo[l][c] = HIDROAVIAO;
            arena_inimigo[l + 1][c - 1] = HIDROAVIAO;
            arena_inimigo[l + 2][c] = HIDROAVIAO;
            qt_barcos.hidro_aviao--;
        }
    } while(qt_barcos.hidro_aviao != 0);
}

//Define e imprime Porta-Avião
void imprime_portaaviao ()
{
    int l, c, direcao;

    do
    {
        direcao = rand() % 2;
        l = rand() % TAMANHO;
        c = rand() % TAMANHO;

        if(direcao == 0)
        {
            if((l == TAMANHO || l > TAMANHO - 4))
            {
                if(arena_inimigo[l][c] == AGUA && arena_inimigo[l - 1][c] == AGUA &&
                arena_inimigo[l - 2][c] == AGUA && arena_inimigo[l - 3][c] == AGUA)
                {
                    for(i = l; i < l + 4; i++)
                    {
                        arena_inimigo[i - 4][c] = PORTAAVIAO;
                    }
                    qt_barcos.porta_aviao--;

                }
            }
            else
            {
                if(arena_inimigo[l][c] == AGUA && arena_inimigo[l + 1][c] == AGUA &&
                arena_inimigo[l + 2][c] == AGUA && arena_inimigo[l + 3][c] == AGUA)
                for(i = l; i < l + 4; i++)
                {
                        arena_inimigo[i][c] = PORTAAVIAO;
                }
                qt_barcos.porta_aviao--;
            }
        }
        else
        {
            if(c == TAMANHO || c > TAMANHO - 4)
            {
                if(arena_inimigo[l][c] == AGUA && arena_inimigo[l][c - 1] == AGUA &&
                arena_inimigo[l][c - 2] == AGUA && arena_inimigo[l][c - 3] == AGUA)
                {
                    for(i = c; i < c + 4; i++)
                    {
                        arena_inimigo[l][i - 4] = PORTAAVIAO;
                    }
                    qt_barcos.porta_aviao--;
                }
            }
            else
            {
                if(arena_inimigo[l][c] == AGUA && arena_inimigo[l][c + 1] == AGUA &&
                arena_inimigo[l][c + 2] == AGUA && arena_inimigo[l][c + 3] == AGUA)
                {
                    for(i = c; i < c + 4; i++)
                    {
                        arena_inimigo[l][i] = PORTAAVIAO;
                    }
                    qt_barcos.porta_aviao--;
                }

            }
        }
    } while (qt_barcos.porta_aviao != 0);
}

//Prepara Tabuleiro
void prepara_tabuleiro ()
{
    int l, c;

    for(l = 0; l < TAMANHO; l++)
    {
        for(c = 0; c < TAMANHO; c++)
        {
            if(arena[l][c] == '\0' && arena_inimigo[l][c] == '\0')
                arena_inimigo[l][c] = AGUA;
                arena        [l][c] = AGUA;
        }
    }
}

//Imprime tabuleiro
void imprimeTabuleiro ()
{
    int l, c;
    system("cls");
    printf("     meu mapa                       mapa inimigo\n");
    textcolor (YELLOW);
    for(l = 0; l < TAMANHO; l++)
    {
        for(c = 0; c < TAMANHO; c++)
        {
            printf(" %c", arena[l][c]);
        }
        printf("    |    ");
        for(c=0; c< TAMANHO; c++)
            printf(" %c",arena_inimigo[l][c]);
        printf("\n");
    }
    textcolor (WHITE);

    //Exibe principais informações na tela
    printf("Almirante %s\n", jogador.nome);
    printf("Disparo Restantes: %i/46\n", jogador.disparos);
    printf("Vida Inimiga: %i/36\n\n", vida_inimiga);
}

//Controles do jogador
int controles ()
{
    int l, c;

    do
    {
        printf("Informe a linha: ");
        scanf("%i", &l);
        printf("Informe a coluna: ");
        scanf("%i", &c);
        printf("\n");

        l--;
        c--;

        if(l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO)
        {
            switch(arena_inimigo[l][c])
            {
            case AGUA:
                arena[l][c] = ERRO;
                system("cls");
                imprimeTabuleiro();
                printf("Errou!...    \n");
                jogador.disparos--;
                break;

            case SUBMARINO:
                arena[l][c] = 'S';
                system("cls");
                imprimeTabuleiro();
                printf("Acertou no Submarino!...    \n");
                jogador.disparos--;
                vida_inimiga--;
                break;

            case HIDROAVIAO:
                arena[l][c] = 'H';
                system("cls");
                imprimeTabuleiro();
                printf("Acertou no Hidroaviao!...     \n");
                jogador.disparos--;
                vida_inimiga--;
                break;

            case DESTROYER:
                arena[l][c] = 'D';
                system("cls");
                imprimeTabuleiro();
                printf("Acertou no Destoryer!...     \n");
                jogador.disparos--;
                vida_inimiga--;
                break;

            case PORTAAVIAO:
                arena[l][c] = 'P';
                system("cls");
                imprimeTabuleiro();
                printf("Acertou no Portaavião!...    \n");
                jogador.disparos--;
                vida_inimiga--;
                break;

            default:
                printf("ErrROU!\n");
            }
        }
        else
        {
            system("cls");
            imprimeTabuleiro();
            printf("Coordenadas invalidas\n");
        }

        if(vida_inimiga == 0)
        {
            system("cls");
            puts("FIM DO JOGO");
            puts("VOCÊ VENCEU!");
            puts("");
            jogador.placar = jogador.placar + 1;
            printf("Jogador: %s\nPlacar: %i", jogador.nome, jogador.placar);
            puts("");
            getchar();
            exit(1);
        }

        if(jogador.disparos == 0)
        {
            system("cls");
            puts("FIM DO JOGO");
            puts("VOCÊ PERDEU");
            jogador.placar = jogador.placar + 0;
            printf("Jogador: %s\nPlacar: %i", jogador.nome, jogador.placar);
            puts("");
            getchar();
            exit(1);
        }
    }
    while (vida_inimiga != 0 && jogador.disparos != 0);

}

int main ()
{
    setlocale(LC_ALL,"portuguese");
    srand((unsigned)time(NULL));
    menu();
    creditos();
    introducao();
    prepara_tabuleiro();
    imprime_submarino();
    imprime_destroyer();
    imprime_hidroaviao();
    imprime_portaaviao();
    imprimeTabuleiro();
    controles();
    getch();
    return 0;
}