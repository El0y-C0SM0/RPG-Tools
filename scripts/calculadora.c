#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

#define VERSAO "1.0.0"

int calc() {
    double valor, valor_aux, resultado = 0;
    int erro = 0;
    char operador;

    scanf("%lf %c %lf", &valor, &operador, &valor_aux);

    switch (operador) {
    case '+':
        resultado = valor + valor_aux;
        break;
    case '-':
        resultado = valor - valor_aux;
        break;
    case '*':
        resultado = valor * valor_aux;
        break;
    case '/':
        resultado = valor / valor_aux;
        break;
    case '^':
        resultado = pow(valor, valor_aux);
        break;
    case '%':
        resultado = valor_aux * (valor / 100);
        break;
    default:
        puts("opera??o n?o reconhecida! Digite \"-help\" para ver os comandos.");
        erro = 1;
        break;
    }

    int aux = resultado;
    if(aux == resultado && !erro) 
        printf("%d ", aux);
    else if(!erro)
        printf("%.2f ", resultado);
    else {
        erro = 0;
        return erro;
    }


    while (1) {
        scanf(" %c", &operador);

        if(operador == '=')
            break;

        scanf("%lf", &valor);

        switch (operador) {
        case '+':
            resultado += valor;
            break;
        case '-':
            resultado -= valor;
            break;
        case '*':
            resultado *= valor;
            break;
        case '/':
            resultado /= valor;
            break;
        case '^':
            resultado = pow(resultado, valor);
            break;
        case '%':
            resultado = valor * (resultado / 100);
            break;
        default:
            puts("\nopera??o n?o reconhecida!");
            break;
        }

        int aux = resultado;
        if(aux == resultado)
            printf("%d ", aux);
        else
            printf("%.2f ", resultado);
    }
    
    aux = resultado;
    if(aux == resultado)
        printf("%d\n\n", aux);
    else
        printf("%.2f\n\n", resultado);

    return erro;
}

void info() {
    puts("Calculadora - RPG Tools");
    printf("V:%s\n", VERSAO);
    puts("Autor: El0y-c0smo");
    puts("Github: https://github.com/El0y-C0SM0/RPG-Tools.git");
    puts("Uma calculadora simples que realiza os calculos na ordem que s?o inseridos. Tem o objetivo de ajudar jogadores de rpg a fazer calculos simples com agilidade.\nPara mais informa??es de como dar os comandos digite: -help\n");
}

void help() {
    puts("Comandos:");
    puts("-info ou -i: exibe informa??es gerais acerca do programa\n-h ou -help: exibe comandos e informac?es de ajuda ao usu?rio\n-v ou -version: exibe vers?o do programa\n-calc ou -c: para inserir os calculos\nexit: encerra o programa\n");
    puts("Como calcular:");
    puts("insira o numero, o operador e outro numero, caso queira outra opera?o a partir do resultado da opera??o anterior ? s? digitar outro operador e outro valor. A opera??o incerra com o operador igual (=). As contas s?o realizadas na ordem das entradas\n");
    puts("Quais opera??es s?o validas:");
    puts("soma +\nsubtra??o -\nmultiplica??o *\ndivis?o /\nexponencia??o ^\nporcentagem %\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    puts("Bem vindo a calculadora!");
    
    char prompt[15];

    while (scanf(" %s", prompt) != EOF) {
        if(strcmp(prompt, "-calc") == 0 || strcmp(prompt, "-c") == 0) {
            int aux;
            do {
                aux = calc();
            } while(aux);
        } else if(strcmp(prompt, "-v") == 0 || strcmp(prompt, "-version") == 0) {
            printf("Vers?o: %s\n\n", VERSAO);
        } else if(strcmp(prompt, "-h") == 0 || strcmp(prompt, "-help") == 0) {
            help();
        } else if(strcmp(prompt, "-i") == 0 || strcmp(prompt, "-info") == 0) {
            info();
        } else if(strcmp(prompt, "-exit") == 0 || strcmp(prompt, "exit") == 0) {
            return 0;
        } else {
            puts("esse comando n?o e reconhecido! Digite \"-help\" para ver os comandos.");
        }
    }

    return 0;
}