#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define ARMAS_ARQUIVO_BI  "arquivos dos programas\\armas_bi.txt"
#define ARMAS_ARQUIVO_TXT "arquivos dos programas\\armas.txt"
#define VERSAO "1.0.2"

#define ERR_ABRIR_ARQUIVO 1
#define ERR_SALVAR_NO_ARQUIVO 2
#define ERR_ACHAR_NO_ARQUIVO 3

typedef struct {
    char nome[40];
    unsigned int key;
    char dano[31];
    char descricao[105];
} Arma;

unsigned int faz_hash(char *string) {
    int tam = strlen(string);
    unsigned int hash = 0;

    for(register int i = 0; i < tam; i++) {
        hash += string[i] * (i + 1);
    }

    return hash;
}

void le_arma(Arma *arma) {
    puts("Digite o nome da arma at? 30 caracteres");
    scanf(" %[^\n]s", arma->nome);
    puts("Digite o dano da arma no formato de dados e modificador. Para mais informa??es digite \"-help\"");
    scanf(" %[^\n]s", arma->dano);
    puts("Digite a descri??o da arma at? 100 caracteres");
    scanf(" %[^\n]s", arma->descricao);

    arma->key = faz_hash(arma->nome);

    printf("Chave da arma: %u\n", arma->key);
}

void printa_arma(Arma arma) {
    puts(arma.nome);
    printf("%u\n", arma.key);
    puts(arma.dano);
    puts(arma.descricao);
}

void delete_arquivos() {
    printf("Isso ir? deletar arquivo %s e %s!\nDeseja mesmo fazer isso? Se sim digite: SIM\nNa pr?xima grava??o seram criados arquivos com os mesmo endere?os mas com o novo conteudo.\n", ARMAS_ARQUIVO_BI, ARMAS_ARQUIVO_TXT);

    char confirmacao[5];

    scanf("%s", confirmacao);

    if(strcmp(confirmacao, "SIM") != 0) {
        puts("Arquivos N?O foram deletados");
        return;
    }

    remove(ARMAS_ARQUIVO_BI);
    remove(ARMAS_ARQUIVO_TXT);

    puts("Arquivos deletados");
}

void salva_armas_txt(Arma arma) {
    FILE *arquivo_armas;

    arquivo_armas = fopen(ARMAS_ARQUIVO_TXT, "a");
    if(arquivo_armas == NULL) {
        puts("erro ao abrir para escrita");
        fclose(arquivo_armas);
        return;
    }

    fprintf(arquivo_armas, "Nome: %s\nChave: %u\nDano: %s\nDescri??o: %s\n", arma.nome, arma.key, arma.dano, arma.descricao);
    fputs("==================================================\n", arquivo_armas);

    fclose(arquivo_armas);
}

Arma *procura_arma(unsigned int chave) {
    Arma *arma = (Arma*) malloc(sizeof(Arma));
    FILE *arquivo_armas = fopen(ARMAS_ARQUIVO_BI, "rb");

    if(arquivo_armas == NULL) {
        puts("erro ao abrir para leitura");
        fclose(arquivo_armas);
        return NULL;
    }

    while(fread(arma, sizeof(Arma), 1, arquivo_armas) == 1 || !feof(arquivo_armas)) {
        if(arma->key == chave) {
            fclose(arquivo_armas);
            return arma;
        }
    }

    fclose(arquivo_armas);
    return NULL;
}

int verifica_arma(Arma arma) {
    Arma *verificador = procura_arma(arma.key);

    if(verificador == NULL)
        return 0;
    return 1;
}

int salvar_arma() {
    Arma arma;
    FILE *arquivo_armas;
    int erro;

    arquivo_armas = fopen(ARMAS_ARQUIVO_BI, "a+b");
    if(arquivo_armas == NULL) {
        puts("erro ao abrir para escrita");
        fclose(arquivo_armas);
        return ERR_ABRIR_ARQUIVO;
    }

    le_arma(&arma);

    if(verifica_arma(arma)) {
        puts("Essa arma j? existe");
        return ERR_SALVAR_NO_ARQUIVO;
    }


    erro = fwrite(&arma, sizeof(Arma), 1, arquivo_armas);
    if(erro != 1){
        puts("erro ao salvar no arquivo");
        fclose(arquivo_armas);
        return ERR_SALVAR_NO_ARQUIVO;
    }

    salva_armas_txt(arma);

    fclose(arquivo_armas);

    return 0;
}

void abrir_arquivo() {
    system("\"arquivos dos programas\\armas.txt\"");
}

void info() {
    puts("Registro de Armas - RPG Tools");
    printf("V:%s\n", VERSAO);
    puts("Autor: El0y-c0smo");
    puts("Github: https://github.com/El0y-C0SM0/RPG-Tools.git");
    puts("Um programa em que o usu?rio salva algumas armas usadas por ele em jogos de rpg.\nPara mais informa??es de como dar os comandos digite: -help\n");
}

void help() {
    puts("Comandos:");
    puts("-info ou -i: exibe informa??es gerais acerca do programa\n-h ou -help: exibe comandos e informa??es de ajuda ao usu?rio\n-v ou -version: exibe vers?o do programa\n-registra ou -r: para salvar novas armas\n-buscar ou -b: para achar uma arma j? salva\n-open ou -o: abre o arquivo onde est?o salvas as armas\n-delete: deleta o que j? foi salvo\nexit: encerra o programa\n");
    puts("Como salvar");
    puts("insira o nome, com no m?ximo 30 caracteres, sem acentos ou caracteres especiais. Depois insira o dano no formato de lan?amento de dados, exemplo: \"2d8+4\", caso seja diferente n?o ser? possivel usar o rolador de dados para essa arma. Depois deixe uma breve descri??o de no m?ximo 100 caracteres e em uma linha\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    puts("Bem vindo ao registro de armas\n");

    char prompt[15];

    while (scanf(" %s", prompt) != EOF) {
        if(strcmp(prompt, "-registrar") == 0 || strcmp(prompt, "-r") == 0) {
            salvar_arma();
        } else if(strcmp(prompt, "-v") == 0 || strcmp(prompt, "-version") == 0) {
            printf("Vers?o: %s\n\n", VERSAO);
        } else if(strcmp(prompt, "-b") == 0 || strcmp(prompt, "-buscar") == 0) {
            Arma *arma;
            char escolha[8];
            
            puts("Procurar por chave, digite [chave], ou procurar por nome, digite [nome],");
            scanf(" %s", escolha);

            if(strcmp(escolha, "chave") == 0) {
                printf("insira a chave: ");
                unsigned int chave;
                scanf(" %u", &chave);
                arma = procura_arma(chave);
            } else if(strcmp(escolha, "nome") == 0) {
                printf("insira o nome: ");
                char nome[40];
                scanf(" %[^\n]s", nome);
                unsigned int chave = faz_hash(nome);
                arma = procura_arma(chave);
            }

            if(arma != NULL)
                printa_arma(*arma);
            else
                puts("Arma n?o encontrada");
        } else if(strcmp(prompt, "-open") == 0 || strcmp(prompt, "-o") == 0) {
            abrir_arquivo();
        } else if(strcmp(prompt, "-delete") == 0) {
            delete_arquivos();
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