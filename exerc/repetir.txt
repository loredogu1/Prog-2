

// dados a ser inceridos 
typedef struct
{
    char nome[15];
    char snome[14];
    int nota1, nota2, trab;
    float media;
} aluno; // Define o nome do novo tipo criado


 for(i=0;i<nalunos;i++){
        if(strcmp((log+i)->dataAcesso,"2020-23-05 10:20")==0){
            printf("\t Nome do aluno: %s\n",(log+i)->dataAcesso);
            printf("\t Usuario: %s\n",(log+i)->usuario);
            printf("\t Sistem: %s\n", (log+i)->sistema);
            printf("----------------------------\n");
        }
    }