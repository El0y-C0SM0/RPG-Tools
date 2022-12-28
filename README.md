# RPG-Tools ![versão](https://img.shields.io/badge/vers%C3%A3o-1.0.0-blue?style=flat-square) ![status](https://img.shields.io/badge/status-em%20desenvolvimento-brightgreen?style=flat-square)

## O que é?

RPG Tools é uma série de programas que visa auxiliar jogadores de rpg, independente do rpg jogado, desde D&D a Ordem Paranormal. Atualmente tem três programas sendo eles: um sistema de rolagem de dados; Um sistema de registro de armas que guarda o nome, o dano e uma descrição curta; Uma calculadora básica para fazer calculos simples rapidamente. 

## Como foi feito?

RPG tools é feito em linguagem C e seu código está todo na pasta [scripts](https://github.com/El0y-C0SM0/RPG-Tools/tree/main/scripts) para quem quiser ver, fazer alterações ou contribuir resolvendo erros.

## Como Baixar?

Para baixar o programa basta clicar nesse [link](https://github.com/El0y-C0SM0/RPG-Tools/archive/refs/heads/main.zip), depois decompacte e salve a pasta referente ao seu sistema operacional (atualmente só está disponivel para windows) e salva-la no lugar que desejar. Para usar basta executar o arquivo rpg_tools.exe que está dentro da pasta que você salvou, esse programa é um gerenciador dos outros programas e com ele é possivel executar os demais através de comandos simples. Sendo assim, caso queira uma abordagem mais rápida e/ou só vá usar um programa, pode executar esse programa especifico dentro da pasta.

## Como Usar?

O código está divido em quatro executaveis e abaixo vou descrever como fazer uso e para que server cada um, caso queira ir direto para o uso clique nos links:

- [como usar o rpg_tools]()
- [como usar o sistema de rolagem]()
- [como usar o registro de armas]()
- [como usar a calculadora]()

## Programas
### Rpg_tools

Este é o software responsável por gerenciar e abrir os demais. Seus comandos são:

- `-help` ou `-h`: exibe comandos e informações de ajuda ao usuário
- `-info` ou `-i`: exibe informações sobre o programa
- `-version` ou `-v`: exibe versão do programa
- `-rolagem`: inicia o sistema de rolagem de dados
- `-armas`: inicia o registro de armas
- `-calculadora`: inicia a calculadora
- `-exit`: encerra o programa

### Sistema de Rolagem

É um programa onde é possivel solicitar rolagem de varios dados e calcular modificadores com um único comando, também é possivel rolar dano de armas que estejam registradas.
Com ele é possivel rolar os segintes tipos de dados:

- d2
- d3
- d4
- d6
- d8
- d10
- d12
- d20
- d100
- d1000

Os comandos são:

- `-help` ou `-h`: exibe comandos e informações de ajuda ao usuário
- `-info` ou `-i`: exibe informações sobre o programa
- `-version` ou `-v`: exibe versão do programa
- `-roll` ou `-r`: para solicitar a rolagem
- `-roll-arma`: para rolar dano de alguma arma já registrada.
- `-exit`: encerra o programa

Após o comando `-roll`, antes ou depois de dar enter, escolha o dado informando os nomes especificados acima, exemplo `-roll d20` ou `-roll` dê enter `d20`.
Para acresentar modificador a um dado basta adicionar o sinar de adição ou subtração (+ ou -) e o valor do modificador ao comando do dado (tudo sem espaço), exemplo `-roll d100-25` ou `-roll` dê enter `d4+2`.
Para solicitar mais de um dado basta acrescentar o numero da quantidade de dados antes do dado, exemplo `-roll 5d6` ou `-roll` dê enter `2d10`.
Pada pedir mais de um tipo de dado com o mesmo lançamento separe-os com um espaço, exemplo `-roll d20 4d6+4` ou `-roll` dê enter `4d20+15 d100`.

A saida indicará a soma total dos dados de determinado tipo, o valor individual de cada dado e do mod separados pelo sinal de soma o subitração e no final, entre parenteses a rolagem solicitada (quantidade de dados, tipo do dado e mod). Na ultima linha mostrará o valor total da soma de todos os dados e seus mods. exemplo:
`-roll 2d20 4d6+4`

    [12] <- 10 + 2 (2d20)
    [17] <- 4 + 3 + 4 + 2 + 4 (4d6+4)
    [29] <- (total)

Para rolar o dano de uma arma, o dano precisa estar registrado no formato de rolagem de dados (sem o -roll, apenas os dados). 


