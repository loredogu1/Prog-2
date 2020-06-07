
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include max_alunos 50
typedef struct{
	char nome[15];
    float nota[4];
    int ativo;
}aluno;
Aluno alunos [max_alunos];

void menu();
void cadastrar();
void remover();
void pesquisar();
void listar();

int main(int argc, cha const *argv[]) {
    menu();
    return 0;
}
void menu (){
    int op;
    do{
    system("cls");
    printf("\n1 -  Cadrastrar aluno\n2- remover alunos");
    printf("\n3 -  alunos reprovados\n4- pesquisar aluno");
    printf("\n5 listar alunos - sair\n");
    scanf("%d", &op);
    getchar();
    switch (op)
    {
    case 1:
    cadastrar();
        break;
    case 5:
    listar();
    break;

    }
    getchar();
     }while (op != 0);
    
}
void cadastrar(){

    char nome[50];
    float nota[4];
    int op;
    do
    {
        system ("cls");
        printf("\n Nome");
        fgets(nome, sizeof(nome),stdin);
        printf("\n1 bimestre");
        scanf("%f",&notas[0]);
        printf("\n2 bimestre");
        scanf("%f",&notas[1]);
        printf("\n3  bimestre");
        scanf("%f",&notas[2]);
        printf("\n4 bimestre");
        scanf("%f",&notas[3]);
        for (int i; i = 0; i < max_alunos; i++)
        {
            if (alunos[i].ativo==0){
                alunos[i].notas[0]= notas[0];
                alunos[i].notas[1]= notas[1];
                alunos[i].notas[2]= notas[2];
                alunos[i].notas[3]= notas[3];
                strcpy(alunos[i].nome, nome);
                alunos[i].ativo=1/
                break;
            }
        }
        
        printf("\n1-contunuar\n0 sair\n");
        scanf("%d", &op);
    } while (op!-0);
    

}
void remover();{

}
void pesquisar();{

}
void listar(){
    system ("cls");
    printf("\n lista de alunos\n")
for (int i; i = 0; i < max_alunos; i++)
{
   if(aluno[i].ativo==1){
         printf("\n Nome: %s\n",alunos[i].nome);
         printf("1 Bim: %f0.2\n", alunos[i].notas[0]);
         printf("2 Bim: %f0.2\n", alunos[i].notas[1]);
         printf("3 Bim: %f0.2\n", alunos[i].notas[2]);
         printf("3 Bim: %f0.2\n", alunos[i].notas[3]);
         printf("\n --------\n");
    }
}

}