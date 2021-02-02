#include <stdio.h>
#include <string.h>

int gravar_arquivo(char *arq,int cod, char *nome, float nota1, float nota2, float media, char *resultado){
    FILE *arquivo;
    arquivo = fopen(arq,"a+");
        if(arquivo==NULL) return 0;
            fprintf(arquivo,"%d;%s;%0.2f;%0.2f;%0.2f;%s\n",cod,nome,nota1,nota2,media,resultado);
            fclose(arquivo);
    return 1;
}

///////////////////////////////////////////////////

int ler_arquivo(char *arq){
    int cod;
    char nome[100];
    float nota1, nota2;
    FILE *arquivo;//ponteiro de arquivo
    arquivo = fopen(arq,"r+");//abrir o arquivo
        if(arquivo==NULL) {
            printf("Erro ao abrir o arquivo\n");
            return 0;
        }
    int i=0;
    printf("CÃ³digo;Nome;Nota1;Nota2;MÃ©dia;Resultado\n");
        while(fscanf(arquivo,"%d;",&cod)!=EOF){
            fscanf(arquivo,"%[^;];",nome);
            fscanf(arquivo,"%f;",&nota1);
            fscanf(arquivo,"%f",&nota2);
            printf("%d ",cod);
            printf("%s ",nome);
            printf("%0.2f ",nota1);
            printf("%0.2f ",nota2);
        float media;
        media=(nota1+nota2)/2;
        printf("%0.2f ",media);
        char resultado[20];
            if(media>=6){
                strcpy(resultado,"Aprovado");
            }
            else {
                strcpy(resultado,"Reprovado");;
            }
            printf("%s\n",resultado);
            if(gravar_arquivo("boletim.csv",cod,nome,nota1,nota2,media,resultado)){
            printf("Registro salvo com sucesso\n");
            }
            else{
                printf("Erro ao gravar\n");
            }
        i++;
    }
    fclose(arquivo);//fechar o arquivo
    return i;
}

///////////////////////////////////////////////////////////////////////////

int main(){
    int t;
    t=ler_arquivo("notas.csv");
    printf("Total de alunos: %d\n",t);
    return 0;
}




//////////////////////////////////////////









