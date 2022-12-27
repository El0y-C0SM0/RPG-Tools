#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define VERSAO   "1.0.0"
#define TAM_DADO 1000

typedef struct {
    char *lance;
    int *valores;
    int quant_dados;
    int mod;
} Lance;

typedef struct {
    Lance *lances;
    int quant_lances;
} Sequencia_Lances;

int gera_numero(int valor_max, int aux) {
    int numeros[70], escolhido;

    srand(time(NULL)+aux);

    for(register int i = 0; i < 70; i++) {
        numeros[i] = rand() % valor_max + 1;
    }

    escolhido = rand() % 70;

    return numeros[escolhido];
}

void escolhe_dado(Lance *lance) {
    char *aux = strchr(lance->lance, 'd');
    char dado[50];
    strcpy(dado, aux);

    if(strpbrk(dado, "+-") != NULL)
        *strpbrk(dado, "+-") = '\0';

    for(int i = 0; i < lance->quant_dados; i++) {
        if(strcmp(dado, "d2") == 0)
            lance->valores[i] = gera_numero(1, i);
        else if(strcmp(dado, "d3") == 0)
            lance->valores[i] = gera_numero(2, i);
        else if(strcmp(dado, "d4") == 0)
            lance->valores[i] = gera_numero(3, i);
        else if(strcmp(dado, "d6") == 0)
            lance->valores[i] = gera_numero(5, i);
        else if(strcmp(dado, "d8") == 0)
            lance->valores[i] = gera_numero(7, i);
        else if(strcmp(dado, "d10") == 0)
            lance->valores[i] = gera_numero(9, i);
        else if(strcmp(dado, "d12") == 0)
            lance->valores[i] = gera_numero(11, i);
        else if(strcmp(dado, "d20") == 0)
            lance->valores[i] = gera_numero(19, i);
        else if(strcmp(dado, "d100") == 0)
            lance->valores[i] = gera_numero(99, i);
        else if(strcmp(dado, "d1000") == 0)
            lance->valores[i] = gera_numero(999, i);
    }
}

void faz_lance(char *lances, Sequencia_Lances *vtr_lance) {
    vtr_lance->quant_lances = 1;

    char *espacos = strchr(lances, ' ');

    while (espacos != NULL) {
        if(lances[strlen(lances) - 1] != ' ')
            vtr_lance->quant_lances++;
        else
            lances[strlen(lances) - 1] = '\0';

        espacos = strchr(espacos + 1, ' ');
    }
    
    vtr_lance->lances = (Lance*) malloc(sizeof(Lance) * (vtr_lance->quant_lances));
    
    char *dados = strtok(lances, " ");

    for(int i = 0; dados != NULL; i++) {
        vtr_lance->lances[i].lance = dados;
        vtr_lance->lances[i].mod = 0;
        char *mod = strpbrk(dados, "-+");

        if(mod != NULL) {
            vtr_lance->lances[i].mod += atoi(strpbrk(mod, "1234567890"));
            if(*mod == '-') 
                vtr_lance->lances[i].mod *= -1;
        }

        if(dados[0] != 'd') {
            char cpy[10];
            strcpy(cpy, dados);
            char *aux = strchr(cpy, 'd');
            *aux = '\0';
            vtr_lance->lances[i].quant_dados = atoi(cpy);
            vtr_lance->lances[i].valores = (int*) calloc(vtr_lance->lances[i].quant_dados + 1, sizeof(int));
        } else {
            vtr_lance->lances[i].quant_dados = 1;
            vtr_lance->lances[i].valores = (int*) calloc(2, sizeof(int));
        }
        
        dados = strtok(NULL, " ");

        escolhe_dado(&vtr_lance->lances[i]);
    }
}

void printa_resultados(Sequencia_Lances *lances) {
    int total = 0;
    for(int i = 0; i < lances->quant_lances; i++) {
        int soma = lances->lances[i].mod;
        for(int j = 0; lances->lances[i].valores[j] != 0; j++)
            soma += lances->lances[i].valores[j];
        printf("[%d] <-", soma);
        printf(" %d", lances->lances[i].valores[0]);
        for(int j = 1; lances->lances[i].valores[j] != 0; j++)
            printf(" + %d", lances->lances[i].valores[j]);
        if(lances->lances[i].mod > 0)
            printf(" + %d", lances->lances[i].mod);
        else if(lances->lances[i].mod < 0)
            printf(" - %d", lances->lances[i].mod * (-1));
        printf(" (%s)\n", lances->lances[i].lance);
        total += soma;
    }
    printf("[%d] <- (total)\n", total);
}

void help() {
    puts("Comandos:");
    puts("-info ou -i: exibe informações gerais acerca do programa\n-h ou -help: exibe comandos e informações de ajuda ao usuário\n-v ou -version: exibe versão do programa\n-roll: faz a rolagem dos dados solicitados\nexit: encerra o programa\n");
    puts("Como solicitar rolagens:");
    puts("indique a quantidade de dados(opicional) com um numero antes do \"d\"; indique o dado com o nome dele (obrigatório) e indique o modificador com o sinal de soma ou subtração (+ ou -) e o valor dele (opicional). Caso vá pedir mais de um tipo de dado no mesmo comando, separe eles com um espaço.\nExemplos de entradas:");
    puts("d6\n2d4\n2d4+2\nd20 2d10\n");
    puts("Como será a saida:");
    puts("A saida irá apresentar o valor da soma dos dados rolados e do possivel modificador entre colchetes [], logo depois mostrará o valor da rolagem de cada dado e o tipo do dado entre parenteses (). No final mostrará o total dos dados de todos os tipos e seus modificadores.\n");
    puts("Quais são os tipos de dados:");
    puts("d2 - valores entre 1 e 2\nd3 - valores entre 1 e 3\nd4 - valores entre 1 e 4\nd6 - valores entre 1 e 6\nd8 - valores entre 1 e 8\nd10 - valores entre 1 e 10\nd12 - valores entre 1 e 12\nd20 - valores entre 1 e 20\nd100 - valores entre 1 e 100\nd1000 - valores entre 1 e 1000\n");
}

void info() {
    puts("Rolagem de Dados - RPG Tools");
    printf("V:%s\n", VERSAO);
    puts("Autor: El0y-c0smo");
    puts("Github:");
    puts("Este é um programa feito inicialmente para estudo da linguagem C mas que também tem o intuito de ajudar jogadores de rpg's de todos os tipo. O programa realiza rolagem de dados dos tipos d2, d3, d4, d6, d8, d10, d12, d20, d100 e d1000; podendo ser solicitado a rolagem de mais de um tipo no mesmo comando e com uma quantidade segura de até 100 dados de cada tipo. Para mais informação de como dar os comandos digite: -help");
}

int main() {
    char prompt[15];

    setlocale(LC_ALL, "Portuguese_Brazil");

    while (scanf("%s", prompt) != EOF) {
        if(strcmp(prompt, "-roll") == 0) {
            Sequencia_Lances *lance = (Sequencia_Lances*) malloc(1 * sizeof(Sequencia_Lances));
            char dados[TAM_DADO];

            scanf(" %[^\n]s", dados);

            faz_lance(dados, lance);

            printa_resultados(lance);

        } else if(strcmp(prompt, "-v") == 0 || strcmp(prompt, "-version") == 0) {
            printf("Versão: %s\n", VERSAO);
        } else if(strcmp(prompt, "-h") == 0 || strcmp(prompt, "-help") == 0) {
            help();
        } else if(strcmp(prompt, "-i") == 0 || strcmp(prompt, "-info") == 0) {
            info();
        } else if(strcmp(prompt, "-exit") == 0 || strcmp(prompt, "exit") == 0) {
            return 0;
        } else {
            puts("esse comando não e reconhecido!");
        }
    }
    
    
    return 0;
}