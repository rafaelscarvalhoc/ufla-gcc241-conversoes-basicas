#include "conversores.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// função pra converter decimal em binario
 string decimal_binario(double numero){
    int inteiro; 
    double fracao; 
    bool temFracao;
    int  inteirovt [64], fracaovt [64], i=0;
    int  c=0; // contador
    string resultado_decimal_binario= "";

        // separar o inteiro e o fracionado pq eles são diferentes ;)
    inteiro = numero; // int so aceita inteiros ent ela ja separa o inteiro
    fracao = numero - inteiro; // matematica basica so sobra o fracionado 
    temFracao = (fracao > 0); // para salvar a informação original se havia numeros apos o . ou a ,

  if (inteiro == 0) {
        inteirovt[0] = 0;
        i = 1;
        //if para o programa não dar erro caso a parte inteira seja 0 
     } else {
    
    // trasformar em binario a parte inteira
    while (inteiro>0 && i < 64){
        inteirovt[i] = inteiro%2;
        inteiro = inteiro/2;
        i++;
    }
}
    // trasformar em binario a parte decimal
    while (fracao>0.00001 && c<16){
        fracao= fracao*2;
        fracaovt[c] = (int)fracao;
        fracao = fracao - fracaovt [c];
        c++;
    }


     if (fracao>0.00001){
       resultado_decimal_binario= " Seu numero ultrapassou 16 numeros apos a virgula causando um truncamento. Contudo o numero gerado ate o truncamento foi: ";
    }

   for (int k = i - 1; k >= 0; k--) {
    resultado_decimal_binario += to_string(inteirovt[k]); // to_string trasforma int em string
}

if (temFracao){
    resultado_decimal_binario += ".";

    for (int k = 0; k < c; k++) {
       resultado_decimal_binario += to_string(fracaovt[k]);
    }

   }
   return resultado_decimal_binario;
}

// ============================================================================
// ============================================================================
// ============================================================================

//Função para fazer  decimal para octa
string decimal_octa(double numero ){
 int inteiro; 
    double fracao; 
    bool temFracao;
string resultado_decimal_octa= "";
     // separar o inteiro e o fracionado pq eles são diferentes ;)
    inteiro = numero; // int so aceita inteiros ent ela ja separa o inteiro
    fracao = numero - inteiro; // matematica basica so sobra o fracionado 
    temFracao = (fracao > 0); // para salvar a informação original se havia numeros apos o . ou a ,

    int  inteirovt [64], fracaovt [64], i=0;
    int  c=0; // contador

     if (inteiro == 0) {
        inteirovt[0] = 0;
        i = 1;
        //if para o programa não dar erro caso a parte inteira seja 0 
     } else {

    // trasformar em octal a parte inteira
    while (inteiro>0 && i < 64 ){
        inteirovt[i] = inteiro%8;
        inteiro = inteiro/8;
        i++;
    }
}
    // trasformar em octal a parte decimal
    while (fracao>0.00001 && c<16){ //0.00001 e so pra em caso de lixo de memoria ele não seguir ate o limite (16)
        fracao= fracao*8;
        fracaovt[c] = (int)fracao;
        fracao = fracao - fracaovt [c];
        c++;
    }

   if (fracao>0.00001){
      resultado_decimal_octa= " Seu numero ultrapassou 16 numeros apos a virgula causando um truncamento o numero gerado antes do truncamento e: ";
   }
   
   
   
   for (int k = i - 1; k >= 0; k--) {
   resultado_decimal_octa += to_string (inteirovt[k]);
    }

    if (temFracao){
    resultado_decimal_octa += ".";

    for (int k = 0; k < c; k++) {
        resultado_decimal_octa += to_string(fracaovt[k]);
        }
    }
    return resultado_decimal_octa;
}

// ============================================================================
// ============================================================================
// ============================================================================


string decimal_hexa(double numero){
//função pra converter decimal pra hexadecimal. achei que 1000 linhas fazia tudo eu nem terminei o conversor e ja tem umas 300 ;-;
    int inteiro; 
    double fracao; 
    bool temFracao;
    int  inteirovt [64], fracaovt [64], i=0;
    int  c=0; // contador
    string resultado_decimal_hexa= "";

      // separar o inteiro e o fracionado pq eles são diferentes ;)
    inteiro = numero; // int so aceita inteiros ent ela ja separa o inteiro
    fracao = numero - inteiro; // matematica basica so sobra o fracionado 
     temFracao = (fracao > 0); // para salvar a informação original se havia numeros apos o . ou a ,

    // guia pro programa escrever em hexa
    char tabela_hexa [] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

     if (inteiro == 0) {
        inteirovt[0] = 0;
        i = 1;
        //if para o programa não dar erro caso a parte inteira seja 0 
     } else {

    // trasformar em hexa a parte inteira
    while (inteiro>0.00001){
        inteirovt[i] = inteiro%16;
        inteiro = inteiro/16;
        i++;
    }
}
    // trasformar em hexa a parte decimal
    while (fracao>0 && c<16){
        fracao= fracao*16;
        fracaovt[c] = (int)fracao;
        fracao = fracao - fracaovt [c];
        c++;
    }

   if (fracao>0.00001){
     resultado_decimal_hexa = " Seu numero ultrapassou 16 numeros apos a virgula causando um truncamento";
   }
   
   for (int k = i - 1; k >= 0; k--) {
resultado_decimal_hexa  +=  (tabela_hexa[inteirovt[k]]);
    }

    if (temFracao){
   resultado_decimal_hexa += ".";

    for (int k = 0; k < c; k++) {
     resultado_decimal_hexa += tabela_hexa [fracaovt[k]];
    }
    
    }
    return resultado_decimal_hexa;
}
// ============================================================================
// ============================================================================
// ============================================================================

string  binario_decimal(string entrada){

int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0;
int casa_decimais = 0 ; //trava pra caso passe de 16 casas decimais 
int posicao_ponto = -1; 
//fica como menos 1 pq inicalmente eu to falando pro programa que esse ponto n exite.
//caso o ponto seja achado o posição ponto deve assumir aquele lugar,
// assim marcando onde se encontra o ponto 
bool e_binario = true; // isso e pra conferir se o numero se encaixa no binario, ele podendo ser 0 1 , ou . 
double resultado_decimal = 0.0;
string resultado_binario_decimal ="";
int tamanho_string = static_cast<int>(entrada.length()); // pra corrigir os erros de atribuição
for (size_t i=0; i< entrada.length(); i++){ //.lenght ele mede quantos caracteres tem a string e me fala o tamanho dela 
    //size_t serve pra igular o i ao tipo de entrada light pq tava dando erro pq o int poderia ser negativo ja entrada light não
    if (entrada [i] != '0' && entrada [i] != '1'&& entrada [i] != ',' && entrada [i] != '.'){
        e_binario = false;
    }

    if (entrada[i]== '.' || entrada[i]== ',' ){// lembrar dos ' '
        posicao_ponto = i;
    }
    }
    if (e_binario == false){
        resultado_binario_decimal += "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem binario. ";
    }
    else {

      // descobrir o final da parte inteira
        if (posicao_ponto == -1) {
            fim_inteiro = tamanho_string; // Se não tem ponto o fim e o fim do string entrada msm
        } else {
            fim_inteiro = posicao_ponto;   // Se tem ponto para no ponto
        }

        for (int k = fim_inteiro - 1; k >= 0; k--) {
            // legal esse metodo abaixo o computador guarda cada caracter em um numero ex:carcter zero =48 caracter 1 = 49. ent se voce tirar 
            // o carcter 0 (48) sobra so o numero puro ficando por exemplo carcter 1 - caracter 0 = numero 1
             digito = entrada[k] - '0'; 
            resultado_decimal = resultado_decimal + (digito * pow(2, potencia_inteiro)); 
            //A função pow faz (base, expoente) serve para elevar um número ao outro, sendo ela da biblioteca cmath. 
            //Ela precisa que você coloque dois valores dentro dos parênteses, separados por vírgula o primeiro e a base o 2 a potencia.
            potencia_inteiro++; // Vai subindo a potencia 0, 1, 2, ...
        }
        if(posicao_ponto != -1) {
         potencia_fracao = -1;
            for (int k = posicao_ponto + 1; k < tamanho_string; k++) {
                if (casa_decimais >= 16) {
                    resultado_binario_decimal += "Sua entrada gerou um resultado que ultrapassou 16 casas decimais, causando um truncamento, contudo o numero antes o travamento era: "; // uma pena meu nobre hihi
                        k = tamanho_string; // truque pra o for parar caso tenha passado
                }
                else {
                     digito = entrada[k] - '0'; // mesma logica de trasformar carcter em numero
                    resultado_decimal = resultado_decimal + (digito * pow(2, potencia_fracao));// mesmo que o 1 so mudando a potencia que e negativa como visto abaixo
                potencia_fracao--;
                casa_decimais++;
                }
            }
        }
                ostringstream stream; // para coverter double em stream
        stream << resultado_decimal;
        resultado_binario_decimal += stream.str();     
    }
    return resultado_binario_decimal;
}

// ============================================================================
// ============================================================================
// ============================================================================

string  octal_decimal(string entrada){ // como octal so muda a base o codigo pode ser copiado mudando so a base
int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0, posicao_ponto = -1, casa_decimais = 0; 
bool e_octal = true;
double resultado_decimal = 0.0;
string resultado_octal_decimal = "";
int tamanho_string = static_cast<int>(entrada.length());

for (size_t i=0; i< entrada.length(); i++){ //.lenght ele mede quantos caracteres tem a string e me fala o tamanho dela 
    if ((entrada [i] < '0' || entrada [i] > '7')&& entrada [i] != ',' && entrada [i] != '.'){ // && significa e || significa ou 
// mesma logica do diminuir um carcter zero, o programa ja entende as letras e o intervalo delas logo n e presciso "traduzir"
       e_octal = false;
    }

    if (entrada[i]== '.' || entrada[i]== ',' ){// lembrar dos ' '
        posicao_ponto = i;
    }
    }
    if (e_octal == false){
        resultado_octal_decimal = "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem octal";
    }
    else {

      // descobrir o final da parte inteira
        if (posicao_ponto == -1) {
            fim_inteiro = tamanho_string; 
        } else {
            fim_inteiro = posicao_ponto;   
        }

        for (int k = fim_inteiro - 1; k >= 0; k--) {
             digito = entrada[k] - '0'; 
            resultado_decimal = resultado_decimal + (digito * pow(8, potencia_inteiro)); 
         potencia_inteiro++;
        }
        if(posicao_ponto != -1) {
         potencia_fracao = -1;
            for (int k = posicao_ponto + 1; k < tamanho_string; k++) {
                if (casa_decimais >= 16) {
                    resultado_octal_decimal +="Sua entrada gerou um resultado que ultrapassou o limite de 16 casas decimais, causando um truncamento. Contudo o numero gerado antes do truncamento foi: "; // to sendo sabotado to programando lembrando da musica qual o plural de decimal? decimais decimais
                        k = tamanho_string; 
                }
                else {
                     digito = entrada[k] - '0'; 
                    resultado_decimal = resultado_decimal + (digito * pow(8, potencia_fracao));
                potencia_fracao--;
                casa_decimais++;
                }
                
            }
        }
       ostringstream stream; // para converter double em stream
        stream << resultado_decimal;
        resultado_octal_decimal += stream.str(); 
    }
    return resultado_octal_decimal;
}

// ============================================================================
// ============================================================================
// ============================================================================

string hexa_decimal(string entrada){
// Criamos a variável inteira para blindar o código contra o compilador da ufla que apresntou aviso ao compilar o programa
    int tamanho_string = static_cast<int>(entrada.length());
int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0, posicao_ponto = -1, casa_decimais = 0; 
bool e_hexa = true;
double resultado_decimal = 0.0;
char c;
string resultado_hexa_decimal;
// Criamos uma condição que diz tudo o que é em hexa
for (size_t i=0; i< entrada.length(); i++){ 
bool caractere_valido = (entrada[i] >= '0' && entrada[i] <= '9') ||
                        (entrada[i] >= 'A' && entrada[i] <= 'F') ||
                        (entrada[i] >= 'a' && entrada[i] <= 'f') ||
                        (entrada[i] == '.') || (entrada[i] == ',');

    if (!caractere_valido) {
        e_hexa = false;
    }
    if (entrada[i]== '.' || entrada[i]== ',' ){
        posicao_ponto = i;
    }
}
    
    if (e_hexa == false){
       resultado_hexa_decimal += "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem hexadecimal";
    }
    else {

     
        if (posicao_ponto == -1) {
            fim_inteiro = tamanho_string; 
        } else {
            fim_inteiro = posicao_ponto;   
        }

        for (int k = fim_inteiro - 1; k >= 0; k--) {
             c = entrada[k]; // Pega o caractere atual para facilitar a análise

if (c >= '0' && c <= '9') {
    digito = c - '0'; // Se for número de 0 a 9, faz o truque clássico
} 
else if (c >= 'A' && c <= 'F') {
    digito = c - 'A' + 10; // Se for maiúscula (A-F), calcula a partir do 10
} 
else if (c >= 'a' && c <= 'f') {
    digito = c - 'a' + 10; // Se for minúscula (a-f), calcula a partir do 10
}
            resultado_decimal = resultado_decimal + (digito * pow(16, potencia_inteiro)); 
         potencia_inteiro++;
        }
        // parte fracionada
        if(posicao_ponto != -1) {
         potencia_fracao = -1;
            for (int k = posicao_ponto + 1; k<tamanho_string; k++) {
                if (casa_decimais >= 16) {
                   resultado_hexa_decimal += "Sua entrada gerou uma resposta que ultrapassou 16 casas decimais, causando um truncamento, contudo o numero anterior ao truncamento era: "; 
                    k = tamanho_string;
                }
                else {
                    c = entrada[k]; // Pegamos o caractere atual da fração para analisar
    
    // O tradutor entrou aqui para salvar o dia caso o caractere seja uma letra!
                    if (c >= '0' && c <= '9') {
                         digito = c - '0'; 
                    } 
                    else if (c >= 'A' && c <= 'F') {
                    digito = c - 'A' + 10; 
                    } 
                    else if (c >= 'a' && c <= 'f') {
                     digito = c - 'a' + 10; 
                    }                    
                resultado_decimal = resultado_decimal + (digito * pow(16, potencia_fracao));
                potencia_fracao--;
                casa_decimais++;
                }
                
            }
        }
       ostringstream stream; 
        stream << resultado_decimal;
        resultado_hexa_decimal += stream.str();  
    }
    return resultado_hexa_decimal;
 }

 // ============================================================================
// ============================================================================
// ============================================================================

string binario_octa (string entrada, char tipo_entradaA){
int posicao_ponto = -1; 
string inteiro, fracao; 
bool e_fracao=false;
string tabela_binario[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
string resultado= "";

for (size_t i=0; i< entrada.length(); i++){
    if (entrada[i]== '.' || entrada[i]== ',' ){// lembrar dos ' '
        posicao_ponto = static_cast<int>(i);
        
    }    
}
    if (posicao_ponto == -1) {
            inteiro = entrada;
            fracao= "";
        } 
    else {
        inteiro = entrada.substr(0, posicao_ponto); // o substr funciona assim (inicio, tamanho do corte)
        fracao = entrada.substr(posicao_ponto + 1);
        e_fracao=true;
        }


    // Caso tenha escolhido  entrada em modo binario
if (tipo_entradaA == 'A' || tipo_entradaA =='a'){
    while (inteiro.length() % 3 != 0){ // Basicamente enquanto a divisao da entrada por 3 n for zero ele adiciona zero 
        inteiro= "0" + inteiro;
    }

if(e_fracao){
    while (fracao.length() % 3 != 0) { // mesma coisa so que pra parte fracionada
                fracao = fracao + "0";
            } 
        }
        // Passo 2: Fatiar e traduzir a parte inteira (pulando de 3 em 3)
        for (size_t i = 0; i < inteiro.length(); i += 3) {
            string grupo = inteiro.substr(i, 3);
            for (int j = 0; j < 8; j++) {
                if (tabela_binario[j] == grupo){
                     cout << j; // basicamente pega o numero joga na tabela e faz o cout e repete ate acabar
            resultado += to_string(j); // to_string pega o numero e trasforma em texto
                }
            }
        }


        // Passo 3: Fatiar e traduzir a parte fracionária igual em cima
        if (e_fracao) {
            
            resultado += ".";
            for (size_t i = 0; i < fracao.length(); i += 3) {
                string grupo = fracao.substr(i, 3);
                for (int j = 0; j < 8; j++) {
                    if (tabela_binario[j] == grupo){
                         cout << j;
                         resultado += to_string(j);
                        }
                    }
                }
            }
        }
    else{
// caso a entrada seja em octal
        for (size_t i = 0; i < inteiro.length(); i++) {
            int indice = inteiro[i] - '0'; 
            cout << tabela_binario[indice];
            resultado += tabela_binario[indice];
        }

        if (e_fracao) {
            resultado += ".";
            for (size_t i = 0; i < fracao.length(); i++) {
                int indice = fracao[i] - '0';
                cout << tabela_binario[indice];
                resultado += tabela_binario[indice];
            }
        }
    }
    return resultado;
}

 // ============================================================================
// ============================================================================
// ============================================================================

string binario_hexa(string entrada, char tipo_entradaB){
    int posicao_ponto = -1; 
    string inteiro, fracao; 
    bool e_fracao = false;
    string tabela_binario[] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    };
    string letras = "ABCDEF";
    string resultado= ""; 
// basicamente quase igual o de cima so adicionando a conversao de 10=a 11=b etc e mudando o agrupamento de 3 pra 4

    // Descobre se tem ponto ou vírgula
    for (size_t i = 0; i < entrada.length(); i++){
        if (entrada[i] == '.' || entrada[i] == ',' ){
            posicao_ponto = static_cast<int>(i); // proteçao contra warning
        }    
    }

    if (posicao_ponto == -1) {
        inteiro = entrada;
        fracao = "";
    } 
    else {
        inteiro = entrada.substr(0, posicao_ponto); 
        fracao = entrada.substr(posicao_ponto + 1);
        e_fracao = true;
    }

    // Caso tenha escolhido entrada em modo binario
    if (tipo_entradaB == 'A' || tipo_entradaB =='a'){
        while (inteiro.length() % 4 != 0){
            inteiro = "0" + inteiro;
        }

        if(e_fracao){
            while (fracao.length() % 4 != 0) {
                fracao = fracao + "0";
            } 
        }

        cout << "Resultado em hexadecimal: ";

        for (size_t i = 0; i < inteiro.length(); i += 4) {
            string grupo = inteiro.substr(i, 4);
            for (int j = 0; j < 16; j++) {
                if (tabela_binario[j] == grupo){
                    if (j < 10){
                        resultado += to_string(j);
                    }
                    else { 
                    resultado += letras[j - 10];
                    }
                }
            }
        }

        if (e_fracao) {
            cout << ".";
            resultado += ".";
            for (size_t i = 0; i < fracao.length(); i += 4) {
                string grupo = fracao.substr(i, 4);
                for (int j = 0; j < 16; j++) {
                    if (tabela_binario[j] == grupo){
                        if (j < 10){
                            resultado += to_string(j);
                        }
                        else {
                            resultado += letras[j - 10];
                        }
                    }
                }
            }
        }
       
    }
    else {
        // Caso a entrada seja em HEXADECIMAL (Hexa -> Binário)

        //trasforma a parte inteira
        for (size_t i = 0; i < inteiro.length(); i++) {
            int indice; 
            char atual = toupper(inteiro[i]); 

            if (atual >= '0' && atual <= '9') {
                indice = atual - '0';
            } else {
                indice = atual - 'A' + 10;
            }
           
            resultado += tabela_binario[indice];
        } 

        // trasforma a parte fracionada 
        if (e_fracao) {
           
            resultado += ".";
            for (size_t i = 0; i < fracao.length(); i++) {
                int indice;
                char atual = toupper(fracao[i]);

                if (atual >= '0' && atual <= '9') {
                    indice = atual - '0';
                } else {
                    indice = atual - 'A' + 10;
                }
             
                resultado += tabela_binario[indice];
            }
        }
    }
    return resultado;
}
 // ============================================================================
// ============================================================================
// ============================================================================

string octal_hexa(string entrada){
string conversao, resultado_final;

// primeiro octal para binario
conversao = binario_octa ( entrada, 'B');
//depois binario pra hexa
resultado_final = binario_hexa(conversao, 'A');

return resultado_final;


}

 // ============================================================================
// ============================================================================
// ============================================================================
 
string hexa_octal(string entrada){
string conversao, resultado_final;

// Primeiro hexa pra binario
conversao = binario_hexa ( entrada, 'B');
//depois binario pra octa
resultado_final = binario_octa(conversao, 'A');

return resultado_final;
}

// ============================================================================
// ============================================================================
// ============================================================================

string maximo_binario(int k) {
    long long max_decimal = static_cast<long long>(pow(2, k)) - 1;
    return decimal_binario(max_decimal);
}

// ============================================================================
// ============================================================================
// ============================================================================

string maximo_octal(int k) {
    long long max_decimal = static_cast<long long>(pow(8, k)) - 1;
    return decimal_octa(max_decimal);
}

// ============================================================================
// ============================================================================
// ============================================================================

string maximo_hexa(int k) {
    long long max_decimal = static_cast<long long>(pow(16, k)) - 1;
    return decimal_hexa(max_decimal);
}