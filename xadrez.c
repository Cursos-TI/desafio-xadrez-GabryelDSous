#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
    Eu divide cada peça como uma função para que
    fique mais facil de dar manutenção conforme 
    o código cresce
*/
void main(){
    setlocale(0, "Portuguese");
    int escolha = 1;
    do{
        printf("\n-----------------------------\n");
        mostrarMenu(); // Função para exibir o menu
        printf("Qual peça você quer mover: ");
        scanf("%d", &escolha);

        // Estrutura switch para facilitar as escolhas
        switch(escolha){
        case 1:
            printf("-----------------------------\n");
            moverTorre();
        break;
        case 2:
            printf("-----------------------------\n");
            moverBispo();
        break;
        case 3:
            moverRainha();
        break;
        default:
            escolha = 0;
        }

    }while(escolha);
}
// Função que mostrar o Menu
void mostrarMenu(){
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Rainha\n");
    printf("4 - Sair\n");
}

// Função para movimento da peça Torre
void moverTorre(){
    // Obtendo os dados de direção e movimento da peça
    int direcao, qtdMovimento;
    printf("Movendo TORRE | Direções: horizontal/vertical\nQuantidade de movimentos maximo: 5\n");
    printf("1 - Direita\n2 - Esquerda\n3 - Cima\n4 - Baixo\n");
    printf("Direção: ");
    scanf("%d", &direcao);
    printf("Movimentos: ");
    scanf("%d", &qtdMovimento);

    // Definindo limites para caso o usuário tente um valor que exceda o movimento da peça
    if(qtdMovimento < 1 || qtdMovimento > 5){
        printf("A peça Torre só pode se mover de 1 a 5 vezes!\n");
        qtdMovimento = 3;
    }

    // Direção de movimento
    char movimento[10];
    switch (direcao){
    case 1:
        strcpy(movimento, "Direita");
    break;
    case 2:
        strcpy(movimento, "Esqueda");
    break;
    case 3:
        strcpy(movimento, "Cima");
    break;
    case 4:
        strcpy(movimento, "Baixo");
    break;
    default:
        printf("Existem apenas 4 direções para a peça Bispo! Moveremos a peça para Cima\n");
        strcpy(movimento, "Cima");
    }

    // Resultado visual do movimento
    imprimirMovendoPecas(movimento, qtdMovimento);
}

// Função para movimento da peça Bispo
void moverBispo(){

    // Obtendo os dados de direção e movimento da peça
    int direcao, qtdMovimento;
    printf("Movendo BISPO | Direções: diagonal\nQuantidade de movimentos maximo: 5\n");
    printf("1 - Cima-Direita\n2 - Cima-Esqueda\n3 - Baixo-Direito\n4 - Baixo-Esquedo\n");
    printf("Direção: ");
    scanf("%d", &direcao);
    printf("Movimentos: ");
    scanf("%d", &qtdMovimento);
    
    // Definindo limites para caso o usuário tente um valor que excede o movimento da peça
    if(qtdMovimento < 1 || qtdMovimento > 5){
        printf("A peça Bispo só pode se mover de 1 a 5 vezes!\n");
        qtdMovimento = 3;
    }

    // Direção de movimento
    char movimento[15];
    switch (direcao){
    case 1:
        strcpy(movimento, "Cima-Direita");
    break;
    case 2:
        strcpy(movimento, "Cima-Esquerda");
    break;
    case 3:
        strcpy(movimento, "Baixo-Direita");
    break;
    case 4:
        strcpy(movimento, "Baixo-Esquerda");
    break;
    default:
        printf("Existem apenas 4 direções para a peça Bispo! Moveremos a peça para Cima\n");
        strcpy(movimento, "Cima");
    }

    // Resultado visual do movimento
    imprimirMovendoPecas(movimento, qtdMovimento);
}


// Função para movimento da peça Rainha
void moverRainha(){
    // Obtendo os dados de direção e movimento da peça
    int direcao, qtdMovimento;
    printf("Movendo Rainha | Direções: Todas | 8 movimentos maximos\n");
    printf("1 - Cima-Esqueda\n2 - Cima \n3 - Cima-Direita\n4 - Direita\n5 - Baixo-Direita\n6 - Baixo\n7 - Baixo-Esquerda\n8 - Esquerda\n");
    printf("Direção: ");
    scanf("%d", &direcao);
    printf("Movimentos: ");
    scanf("%d", &qtdMovimento);

    // Definindo limites para caso o usuário tente um valor que excede o movimento da peça
    if(qtdMovimento < 1 || qtdMovimento > 8){
        printf("A peça Rainha só pode se mover de 1 a 8 vezes!\n");
        qtdMovimento = 2;
    }

    // Direção de movimento
    char movimento[20];
    switch (direcao){
    case 1:
        strcpy(movimento, "Cima-Esquerda");
    break;
    case 2:
        strcpy(movimento, "Cima");
    break;
    case 3:
        strcpy(movimento, "Cima-Direita");
    break;
    case 4:
        strcpy(movimento, "Direita");
    break;
    case 5:
        strcpy(movimento, "Baixo-Direita");
    break;
    case 6:
        strcpy(movimento, "Baixo");
    break;
    case 7:
        strcpy(movimento, "Baixo-Esquerda");
    break;
    case 8:
        strcpy(movimento, "Esquerda");
    default:
        printf("Não é possivel realizar esse tipo de movimento! Moveremos a peça para Cima\n");
        strcpy(movimento, "Cima");
    }

    // Resultado visual do movimento
    imprimirMovendoPecas(movimento, qtdMovimento);

}

// Função para imprimir os o movimento
void imprimirMovendoPecas(char* direcao, int qtdMovimentos){
    printf("Movendo para a direção: %s ", direcao);
    for(int cont = 0; cont < qtdMovimentos; cont++){
        printf("%d.. ", (cont+1));
    }
    printf("Vezes");
}
