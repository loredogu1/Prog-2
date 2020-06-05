   //Guilherme Pereria Loredo - USP Sap Carlos
   //Codigos de um gerenciamentos de dados de alunos

    #include <stdio.h>
    #include <stdlib.h>

    int main(void) {
      FILE *dados;
      char nome[14],snome[14], numneroa [];
      float npri, nseg, ntrab, media;
      int c;


       printf("Criar turma? Digite 1");
       scanf()
      //abrindo o arquivo com tipo de abertura w
      pont_arq = fopen("arquivo_palavra.txt", "w");
      
      //testando se o arquivo foi realmente criado
      if(pont_arq == NULL)
      {
      printf("Erro na abertura do arquivo!");
      return 1;
      }
      
      printf("Escreva o nome do aluno: ");
      scanf("%s", nome);
      scanf("%s", numeroa);
      
      fprintf(dados, "%s", nome);
      fprintf(dados, "%s", numeroa)
      
      //usando fclose para fechar o arquivo
      fclose(dados);
      
      printf("Dados gravados com sucesso!");
      
      getch();
      return(0);
    }

    int criar(){

    }