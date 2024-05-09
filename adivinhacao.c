#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// imprime cabeçalho do nosso jogo
int main() {
    // imprimindo cabecalho bonito do jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    int segundos = time(0); // pega o número de segundos atuais que se passaram desde 01/01/1970
    srand(segundos); // gera sempre números de segundos/sementes novos(a) (com base nos segundos atuais )
    int numeroGrande = rand(); // numeroGrande = número aleatório gerado por srand
    int numeroSecreto = numeroGrande % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numeroDeTentativas;
    switch(nivel){
        case 1:
            numeroDeTentativas = 20;
            break;

        case 2:
            numeroDeTentativas = 12;
            break;

        default:
            numeroDeTentativas = 6;
            break;
    }
    

    for(int i = 1; i<= numeroDeTentativas; i++){

            printf("Tentativa %d\n", tentativas);
            printf("Qual o seu chute? ");

            scanf("%d", &chute);
            printf("Seu chute foi %d.", chute);

            if(chute < 0){
                printf("Você não pode chutar números negativos!\n");

                continue;
            }
            

            acertou = (chute == numeroSecreto);
            int maior = (chute > numeroSecreto);

            if(acertou){
                break;
            }

            else if(maior){
                printf("Seu chute foi maior que o número secreto.\n");

            }

            else{
                 printf("Seu chute foi menor que o númerro secreto.\n");

            }
            tentativas++;

            // A função "abs" transforma o valor em seu valor absoluto, ou seja, seu valor positivo
            double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
            pontos = pontos - pontosPerdidos;
    }
    printf("Fim de jogo!");
    if(acertou){
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        
        printf("\nParabéns! Você acertou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Tolta de pontos: %.1lf\n", pontos);
    }else{
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("Você perdeu! Tente novamente.\n\n");
    }



}