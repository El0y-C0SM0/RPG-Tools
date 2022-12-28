#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define VERSAO "1.0.0"

void help() {
    puts("Comandos:");
    puts("-info ou -i: exibe informações gerais acerca do programa\n-h ou -help: exibe comandos e informacões de ajuda ao usuário\n-v ou -version: exibe a versão do programa\n-rolagem: inicia o programa para rolar dados\n-armas: inicia o registro de armas\n-calculadora: inicia a calculadora\n-exit: encerra o programa\n\n");
    puts("Aviso:");
    puts("Não altere os locais dos arquivos nem edite nada sem saber exatamente o que está fazendo\n");
}

void info() {
    puts("RPG Tools");
    printf("V:%s\n", VERSAO);
    puts("Autor: El0y-c0smo");
    puts("Github: https://github.com/El0y-C0SM0/RPG-Tools.git");
    puts("RPG Tools é um programa composto por outros programas que tem a intenção de ajudar jogadores de rpg nas tarefas de rolar dados, calcular valores e registrar armas. Cada um dos programas a parte pode ser executado individualmente ou pode usar esse gerenciador para executalos.\nPara mais informações de como usar digite \"-help\"\nPara outras informações visite o Github do projeto\n");
}

void executa_rolagem() {
    puts("inicializando rolagem.exe...\n");
    system("\"rolagem.exe\"");
    puts("retornando o gerenciador RPG Tools\n");
}

void executa_registro_armas() {
    puts("inicializando registro_armas.exe...\n");
    system("\"registro_armas.exe\"");
    puts("retornando o gerenciador RPG Tools\n");
}

void executa_calculadora() {
    puts("inicializando calculadora.exe...\n");
    system("\"calculadora.exe\"");
    puts("retornando o gerenciador RPG Tools\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    puts("Bem Vindo ao RPG Tools!");
    puts("-info ou -i: exibe informações gerais acerca do programa\n-h ou -help: exibe comandos e informacões de ajuda ao usuário\n-v ou -version: exibe a versão do programa\n-rolagem: inicia o programa para rolar dados\n-armas: inicia o registro de armas\n-calculadora: inicia a calculadora\n-exit: encerra o programa\n");
    puts("Digite o comando respectivo ao programa que deseja abrir");

    while(1) {
        char prompt[21];

        scanf(" %s", prompt);

        if(strcmp(prompt, "-rolagem") == 0) {
            executa_rolagem();
        } else if(strcmp(prompt, "-armas") == 0) {
            executa_registro_armas();
        } else if(strcmp(prompt, "-calculadora") == 0) {
            executa_calculadora();
        } else if(strcmp(prompt, "-help") == 0 || strcmp(prompt, "-h") == 0) {
            help();
        } else if(strcmp(prompt, "-info") == 0 || strcmp(prompt, "-i") == 0) {
            info();
        } else if(strcmp(prompt, "-version") == 0 || strcmp(prompt, "-v") == 0) {
            printf("Versão: %s\n\n", VERSAO);
        } else if(strcmp(prompt, "-exit") == 0 || strcmp(prompt, "exit") == 0) {
            return 0;
        } else {
            puts("esse comando não é reconhecido. Digite \"-help\" para ver os comandos");
        }
        puts("Digite o comando respectivo ao programa que deseja abrir");
    }

    return 0;
}