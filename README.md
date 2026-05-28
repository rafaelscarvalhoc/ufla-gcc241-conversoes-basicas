# Sistema de Conversão de Bases Numéricas

Aluno Rafael Souza Carvalho 202610901


Este projeto é um projeto feito em C++, desenvolvido usando a ferramenta visual studio code, o programa serve para realizar conversões entre os sistemas de numeração mais utilizados na computação: Decimal, Binário, Octal e Hexadecimal.

## Funcionalidades

O sistema permite as seguintes operações:

* Decimal para:** Binário, Octal e Hexadecimal.
* Binário para:** Decimal, Octal e Hexadecimal.
* Octal para:** Decimal e Hexadecimal.
* Hexadecimal para:** Decimal e Octal.
* Cálculo de Máximos:** Determina o valor máximo representável em diferentes bases para um dado número de bits (k).
* Modo batch feito para ler arquivos e rescrever em um novo.
* modo quiz para testar os conhecimentos do usuario.
* Modo passo a passo mostrando cada processo para chegar ao resultado da operação.
  
## Estrutura do Projeto

* main.cpp: Onde esta localizado os menus do arquivo e o encaminhamento para os modos e conversões solicitadas.
* conversores.h: Guia com as definições das funções.
* conversores.cpp: Funções para realização de calculos e seus retornos
* testes.cpp: Area de testes automatizados que valida o funcionamento das funções.
* quiz.h: encaminhamento para o modo quiz
* quiz.cpp: função criada para fazer o modo quiz utilizando das funções presentes no conversores.cpp
* entrada.csv: arquivo de texto para leitura no modo batch
* passo_passo.h: encaminhamento e declaração das funções do modo passo a passo
* formatador.cpp: arquivo função para ordenamento das saidas (couts) do codigo

  ## Decisões de Projeto e Limitações Conhecidas
Como parte da especificação técnica, foram feitas algumas escolhas de arquitetura:
* **Precisão Numérica:** Utilizamos o tipo double para o tratamento de números fracionários. Reconhecemos que, devido à sua natureza podem existir imprecisões em dízimas binárias extremas.
* **Escopo de Bits:** O sistema foi otimizado para arquiteturas de até 64 bits, visando o desempenho padrão dos processadores atuais.
* **Números Negativos:** O foco do projeto foi a magnitude dos valores (magnitudes positivas). O tratamento de sinal (complemento de dois) não foi implementado nesta versão, sendo uma oportunidade de expansão futura.
* **Implementação Manual:** Seguindo as restrições da disciplina, não foram utilizadas funções de conversão automática da biblioteca padrão (como `std::hex`, `strtol` ou similares), garantindo que toda a lógica aritmética seja original.
## Como Compilar e Executar

Para compilar e rodar o projeto, certifique-se de ter o `g++` instalado. Abra o terminal na pasta do projeto e execute os comandos abaixo:

# Sistema de Conversão de Bases Numéricas

## 1. Compilação e execução

Abra o terminal na pasta do projeto e execute:

```bash
g++ main.cpp conversores.cpp formatador.cpp quiz.cpp passo_passo.cpp -o sistema
```

### Executar no Windows (PowerShell)

```bash
.\sistema.exe
```

### Executar no Linux / Git Bash

```bash
./sistema
```

O programa irá abrir o menu principal contendo:

* Conversor de bases
* Passo a passo
* Modo batch
* Quiz
* Calculadora de máximos

---

## 2. Suíte de testes

Para compilar os testes automatizados, execute:

```bash
g++ testes.cpp conversores.cpp -o testes
```

### Executar no Windows (PowerShell)

```bash
.\testes.exe
```

### Executar no Linux / Git Bash

```bash
./testes
```

A suíte de testes executa automaticamente os casos de teste do sistema de conversão.
o codigo deve abrir a area de testes e dar o protocolo de revisão com sua taxa de acerto

link do video no youtube com apresentação do trabalho https://youtu.be/hJHl4Ig744k
