#include <iostream>
#include <cmath>
#include <string>
#include "passo_passo.h"

using namespace std;

void passo_decimal_binario(double numero) {
    long long inteiro; 
    double fracao; 
    bool temFracao;
    int inteirovt[64], fracaovt[64], i = 0;
    int c = 0; 

    // Separar o inteiro e o fracionado
    inteiro = (long long)numero; 
    fracao = numero - inteiro; 
    temFracao = (fracao > 0); 

    cout << "\n===========================================================\n";
    cout << "   PASSO A PASSO: DECIMAL PARA BINARIO" << endl;
    cout << "   Numero Original: " << numero << endl;
    cout << "===========================================================\n";

    cout << "\n[PASSO 1] Separando as partes:" << endl;
    cout << "Parte inteira: " << inteiro << endl;
    if (temFracao) cout << "Parte fracionaria: " << fracao << endl;

    // ---------------------------------------------------------
    // CONVERSÃO DA PARTE INTEIRA
    // ---------------------------------------------------------
    cout << "\n[PASSO 2] Convertendo a parte inteira (Divisoes sucessivas por 2):" << endl;
    
    if (inteiro == 0) {
        cout << "O numero inteiro ja e 0. Resto = 0." << endl;
        inteirovt[0] = 0;
        i = 1;
    } else {
        cout << "-----------------------------------------------------------" << endl;
        cout << "Divisao\t\tQuociente\tResto (Bit)" << endl;
        cout << "-----------------------------------------------------------" << endl;
        
        long long temp_inteiro = inteiro;
        while (temp_inteiro > 0 && i < 64) {
            inteirovt[i] = temp_inteiro % 2;
            long long quociente = temp_inteiro / 2;
            
            // Imprime a linha da tabela
            cout << temp_inteiro << " / 2\t\t" << quociente << "\t\t" << inteirovt[i] << endl;
            
            temp_inteiro = quociente;
            i++;
        }
    }

    cout << "\n-> Agrupamento da parte inteira (lendo os restos de baixo para cima): ";
    string resultado_inteiro = "";
    for (int k = i - 1; k >= 0; k--) {
        resultado_inteiro += to_string(inteirovt[k]);
    }
    cout << resultado_inteiro << endl;

    // ---------------------------------------------------------
    // CONVERSÃO DA PARTE FRACIONÁRIA
    // ---------------------------------------------------------
    string resultado_fracao = "";
    if (temFracao) {
        cout << "\n[PASSO 3] Convertendo a parte fracionaria (Multiplicacoes sucessivas por 2):" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Conta\t\tResultado\tInteiro (Bit)\tNova Fracao" << endl;
        cout << "-----------------------------------------------------------" << endl;
        
        double temp_fracao = fracao;
        while (temp_fracao > 0.00001 && c < 16) {
            double multiplicacao = temp_fracao * 2;
            fracaovt[c] = (int)multiplicacao; // Pega só a parte inteira (0 ou 1)
            double nova_fracao = multiplicacao - fracaovt[c]; // Pega o que sobrou

            // Imprime a linha da tabela
            cout << temp_fracao << " * 2\t=\t" << multiplicacao << "\t\t" << fracaovt[c] << "\t\t" << nova_fracao << endl;

            temp_fracao = nova_fracao;
            c++;
        }

        if (temp_fracao > 0.00001) {
            cout << "\n(Aviso: O numero ultrapassou 16 casas decimais. Truncamento aplicado.)" << endl;
        }

        cout << "\n-> Agrupamento da parte fracionaria (lendo os bits de cima para baixo): 0.";
        for (int k = 0; k < c; k++) {
            resultado_fracao += to_string(fracaovt[k]);
        }
        cout << resultado_fracao << endl;
    }

    // ---------------------------------------------------------
    // RESULTADO FINAL
    // ---------------------------------------------------------
    cout << "\n[PASSO 4] Resultado Final (Juntando as partes):" << endl;
    cout << resultado_inteiro;
    if (temFracao) {
        cout << "." << resultado_fracao;
    }
    cout << " (Base 2)\n" << endl;
}
//========================================================================
//========================================================================
//========================================================================
//Função para fazer  decimal para octa
void passo_decimal_octa(double numero ){
 long long inteiro; //substituição do int porl ong long devido a calculadora
    double fracao; 
    bool temFracao;
string resultado_decimal_octa= "";

    cout << "\n===========================================================\n";
    cout << "   PASSO A PASSO: DECIMAL PARA OCTAL" << endl;
    cout << "===========================================================\n";

     // separar o inteiro e o fracionado pq eles são diferentes ;)
    inteiro = numero; // int so aceita inteiros ent ela ja separa o inteiro
    fracao = numero - inteiro; // matematica basica so sobra o fracionado 
    temFracao = (fracao > 0); // para salvar a informação original se havia numeros apos o . ou a ,

    cout << "\n[PASSO 1] Parte inteira: " << inteiro;
    if (temFracao) cout << " | Parte fracionaria: " << fracao;
    cout << endl;

    int  inteirovt [64], fracaovt [64], i=0;
    int  c=0; // contador

     if (inteiro == 0) {
        cout << "\n[PASSO 2] Parte inteira = 0. Resto = 0." << endl;
        inteirovt[0] = 0;
        i = 1;
        //if para o programa não dar erro caso a parte inteira seja 0 
     } else {

    cout << "\n[PASSO 2] Divisoes sucessivas por 8 (Parte inteira):" << endl;
    cout << "Divisao\t\tQuociente\tResto" << endl;
    cout << "-----------------------------------------------------------" << endl;

    // trasformar em octal a parte inteira
    while (inteiro>0 && i < 64 ){
        long long temp_atual = inteiro; // salva so pra imprimir na tabela
        inteirovt[i] = inteiro%8;
        inteiro = inteiro/8;
        
        cout << temp_atual << " / 8\t\t" << inteiro << "\t\t" << inteirovt[i] << endl;
        i++;
    }
}

    if (temFracao) {
        cout << "\n[PASSO 3] Multiplicacoes sucessivas por 8 (Parte fracionaria):" << endl;
        cout << "Conta\t\tResultado\tInteiro\tNova Fracao" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }

    // trasformar em octal a parte decimal
    while (fracao>0.00001 && c<16){ //0.00001 e so pra em caso de lixo de memoria ele não seguir ate o limite (16)
        double fracao_antiga = fracao; // salva pra imprimir
        fracao= fracao*8;
        fracaovt[c] = (int)fracao;
        fracao = fracao - fracaovt [c];
        
        cout << fracao_antiga << " * 8\t=\t" << fracao_antiga * 8 << "\t\t" << fracaovt[c] << "\t" << fracao << endl;
        c++;
    }

   if (fracao>0.00001){
      cout << "\n(Aviso: O numero ultrapassou 16 casas decimais causando um truncamento)" << endl;
      resultado_decimal_octa= "Seu numero ultrapassou 16 numeros apos a virgula causando um truncamento o numero gerado antes do truncamento e: ";
   }
   
   cout << "\n[PASSO 4] Agrupamento (Inteiro de baixo pra cima, Fracao de cima pra baixo):" << endl;
   cout << "Resultado Final: ";
   
   for (int k = i - 1; k >= 0; k--) {
   resultado_decimal_octa += to_string (inteirovt[k]);
    }

    if (temFracao){
    resultado_decimal_octa += ".";

    for (int k = 0; k < c; k++) {
        resultado_decimal_octa += to_string(fracaovt[k]);
        }
    }
    
    cout << resultado_decimal_octa << " (Base 8)\n" << endl;
}

//========================================================================
//========================================================================
//========================================================================
//função pra converter decimal pra hexadecimal. achei que 1000 linhas fazia tudo eu nem terminei o conversor e ja tem umas 300 ;-;
void passo_decimal_hexa(double numero){
    long long inteiro; // subistituição int por long long devido a calculadora
    double fracao; 
    bool temFracao;
    int  inteirovt [64], fracaovt [64], i=0;
    int  c=0; // contador
    string resultado_decimal_hexa= "";

    cout << "\n===========================================================\n";
    cout << "   PASSO A PASSO: DECIMAL PARA HEXADECIMAL" << endl;
    cout << "===========================================================\n";

      // separar o inteiro e o fracionado pq eles são diferentes ;)
    inteiro = numero; // int so aceita inteiros ent ela ja separa o inteiro
    fracao = numero - inteiro; // matematica basica so sobra o fracionado 
     temFracao = (fracao > 0); // para salvar a informação original se havia numeros apos o . ou a ,

    cout << "\n[PASSO 1] Parte inteira: " << inteiro;
    if (temFracao) cout << " | Parte fracionaria: " << fracao;
    cout << endl;

    // guia pro programa escrever em hexa
    char tabela_hexa [] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

     if (inteiro == 0) {
        cout << "\n[PASSO 2] Parte inteira = 0. Resto = 0." << endl;
        inteirovt[0] = 0;
        i = 1;
        //if para o programa não dar erro caso a parte inteira seja 0 
     } else {

    cout << "\n[PASSO 2] Divisoes sucessivas por 16 (Parte inteira):" << endl;
    cout << "Divisao\t\tQuociente\tResto\t(Hexa)" << endl;
    cout << "-----------------------------------------------------------" << endl;

    // trasformar em hexa a parte inteira
    while (inteiro>0 && i < 64){
        long long temp_atual = inteiro;
        inteirovt[i] = inteiro%16;
        inteiro = inteiro/16;
        
        cout << temp_atual << " / 16\t\t" << inteiro << "\t\t" << inteirovt[i] << "\t(" << tabela_hexa[inteirovt[i]] << ")" << endl;
        i++;
    }
}
    
    if (temFracao) {
        cout << "\n[PASSO 3] Multiplicacoes sucessivas por 16 (Parte fracionaria):" << endl;
        cout << "Conta\t\tResultado\tInteiro\t(Hexa)\tNova Fracao" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }

    // trasformar em hexa a parte decimal
    while (fracao>0 && c<16){
        double fracao_antiga = fracao;
        fracao= fracao*16;
        fracaovt[c] = (int)fracao;
        fracao = fracao - fracaovt [c];
        
        cout << fracao_antiga << " * 16\t=\t" << fracao_antiga * 16 << "\t\t" << fracaovt[c] << "\t(" << tabela_hexa[fracaovt[c]] << ")\t" << fracao << endl;
        c++;
    }

   if (fracao>0.00001){
     cout << "\n(Aviso: O numero ultrapassou 16 casas decimais causando um truncamento)" << endl;
     resultado_decimal_hexa = " Seu numero ultrapassou 16 numeros apos a virgula causando um truncamento";
   }
   
   cout << "\n[PASSO 4] Agrupamento (Inteiro de baixo pra cima, Fracao de cima pra baixo):" << endl;
   cout << "Resultado Final: ";
   
   for (int k = i - 1; k >= 0; k--) {
resultado_decimal_hexa  +=  (tabela_hexa[inteirovt[k]]);
    }

    if (temFracao){
   resultado_decimal_hexa += ".";

    for (int k = 0; k < c; k++) {
     resultado_decimal_hexa += tabela_hexa [fracaovt[k]];
    }
    
    }
    
    cout << resultado_decimal_hexa << " (Base 16)\n" << endl;
}
//========================================================================
//========================================================================
//========================================================================
void passo_binario_decimal(string entrada){

int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0;
int casa_decimais = 0 ; //trava pra caso passe de 16 casas decimais 
int posicao_ponto = -1; 
//fica como menos 1 pq inicalmente eu to falando pro programa que esse ponto n exite.
//caso o ponto seja achado o posição ponto deve assumir aquele lugar,
// assim marcando onde se encontra o ponto 
bool e_binario = true; // isso e pra conferir se o numero se encaixa no binario, ele podendo ser 0 1 , ou . 
double resultado_decimal = 0.0;

    cout << "\n===========================================================\n";
    cout << "   PASSO A PASSO: BINARIO PARA DECIMAL" << endl;
    cout << "===========================================================\n";

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
        cout << "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem binario.\n";
        return; // Retorna para parar a execução
    }
    else {

        cout << "\n[PASSO 1] Identificando as posicoes dos bits..." << endl;

      // descobrir o final da parte inteira
        if (posicao_ponto == -1) {
            fim_inteiro = tamanho_string; // Se não tem ponto o fim e o fim do string entrada msm
        } else {
            fim_inteiro = posicao_ponto;   // Se tem ponto para no ponto
        }

        cout << "\n[PASSO 2] Somatorio Posicional (Parte Inteira):" << endl;
        cout << "Bit\t\tPosicao\t\tConta\t\t\tValor" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for (int k = fim_inteiro - 1; k >= 0; k--) {
            // legal esse metodo abaixo o computador guarda cada caracter em um numero ex:carcter zero =48 caracter 1 = 49. ent se voce tirar 
            // o carcter 0 (48) sobra so o numero puro ficando por exemplo carcter 1 - caracter 0 = numero 1
             digito = entrada[k] - '0'; 
             double valor_posicao = digito * pow(2, potencia_inteiro); // Calculei separado so pra poder imprimir na tabela
            resultado_decimal = resultado_decimal + valor_posicao; 
            //A função pow faz (base, expoente) serve para elevar um número ao outro, sendo ela da biblioteca cmath. 
            //Ela precisa que você coloque dois valores dentro dos parênteses, separados por vírgula o primeiro e a base o 2 a potencia.
            
            cout << digito << "\t\t" << potencia_inteiro << "\t\t" << digito << " * 2^" << potencia_inteiro << "\t\t" << valor_posicao << endl;
            
            potencia_inteiro++; // Vai subindo a potencia 0, 1, 2, ...
        }
        
        if(posicao_ponto != -1) {
            cout << "\n[PASSO 3] Somatorio Posicional (Parte Fracionaria):" << endl;
            cout << "Bit\t\tPosicao\t\tConta\t\t\tValor" << endl;
            cout << "-----------------------------------------------------------" << endl;
            
         potencia_fracao = -1;
            for (int k = posicao_ponto + 1; k < tamanho_string; k++) {
                if (casa_decimais >= 16) {
                    cout << "\n(Aviso: Sua entrada gerou um resultado que ultrapassou 16 casas decimais, causando um truncamento, contudo o numero antes o travamento era:)" << endl; // uma pena meu nobre hihi
                        k = tamanho_string; // truque pra o for parar caso tenha passado
                }
                else {
                     digito = entrada[k] - '0'; // mesma logica de trasformar carcter em numero
                     double valor_posicao = digito * pow(2, potencia_fracao);
                    resultado_decimal = resultado_decimal + valor_posicao;// mesmo que o 1 so mudando a potencia que e negativa como visto abaixo
                    
                    cout << digito << "\t\t" << potencia_fracao << "\t\t" << digito << " * 2^(" << potencia_fracao << ")\t" << valor_posicao << endl;
                    
                potencia_fracao--;
                casa_decimais++;
                }
            }
        }
        
        cout << "\n[PASSO 4] Somando tudo:" << endl;
        // ostringstream stream; // para coverter double em stream
        // stream << resultado_decimal;
        // resultado_binario_decimal += stream.str();
        
        // Como agora e void e so imprimir na tela, o cout ja faz o trabalho da stream!
        cout << "Resultado Final: " << resultado_decimal << " (Base 10)\n" << endl;
    }
}
//========================================================================
//========================================================================
//========================================================================
void passo_octal_decimal(string entrada){ // como octal so muda a base o codigo pode ser copiado mudando so a base
int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0, posicao_ponto = -1, casa_decimais = 0; 
bool e_octal = true;
double resultado_decimal = 0.0;
int tamanho_string = static_cast<int>(entrada.length());

    cout << "\n===========================================================\n";
    cout << "   PASSO A PASSO: OCTAL PARA DECIMAL" << endl;
    cout << "===========================================================\n";

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
        cout << "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem octal\n";
        return; // Retorna para parar a execucao
    }
    else {

        cout << "\n[PASSO 1] Identificando as posicoes dos algarismos..." << endl;

      // descobrir o final da parte inteira
        if (posicao_ponto == -1) {
            fim_inteiro = tamanho_string; 
        } else {
            fim_inteiro = posicao_ponto;   
        }

        cout << "\n[PASSO 2] Somatorio Posicional (Parte Inteira):" << endl;
        cout << "Digito\t\tPosicao\t\tConta\t\t\tValor" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for (int k = fim_inteiro - 1; k >= 0; k--) {
             digito = entrada[k] - '0'; 
             double valor_posicao = digito * pow(8, potencia_inteiro); // Calculo separado pra tabela
            resultado_decimal = resultado_decimal + valor_posicao; 
            
            cout << digito << "\t\t" << potencia_inteiro << "\t\t" << digito << " * 8^" << potencia_inteiro << "\t\t" << valor_posicao << endl;
            
         potencia_inteiro++;
        }
        
        if(posicao_ponto != -1) {
            cout << "\n[PASSO 3] Somatorio Posicional (Parte Fracionaria):" << endl;
            cout << "Digito\t\tPosicao\t\tConta\t\t\tValor" << endl;
            cout << "-----------------------------------------------------------" << endl;
            
         potencia_fracao = -1;
            for (int k = posicao_ponto + 1; k < tamanho_string; k++) {
                if (casa_decimais >= 16) {
                    cout << "\n(Aviso: Sua entrada gerou um resultado que ultrapassou o limite de 16 casas decimais, causando um truncamento. Contudo o numero gerado antes do truncamento foi:)" << endl; // to sendo sabotado to programando lembrando da musica qual o plural de decimal? decimais decimais
                        k = tamanho_string; 
                }
                else {
                     digito = entrada[k] - '0'; 
                     double valor_posicao = digito * pow(8, potencia_fracao);
                    resultado_decimal = resultado_decimal + valor_posicao;
                    
                    cout << digito << "\t\t" << potencia_fracao << "\t\t" << digito << " * 8^(" << potencia_fracao << ")\t" << valor_posicao << endl;
                    
                potencia_fracao--;
                casa_decimais++;
                }
                
            }
        }
        
        cout << "\n[PASSO 4] Somando tudo:" << endl;
        cout << "Resultado Final: " << resultado_decimal << " (Base 10)\n" << endl;
    }
}

//========================================================================
//========================================================================
//========================================================================
void passo_hexa_decimal(string entrada){
// Criamos a variável inteira para blindar o código contra o compilador da ufla que apresntou aviso ao compilar o programa
    int tamanho_string = static_cast<int>(entrada.length());
int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0, posicao_ponto = -1, casa_decimais = 0; 
bool e_hexa = true;
double resultado_decimal = 0.0;
char c;

    cout << "\n===========================================================\n";
    cout << "   PASSO A PASSO: HEXADECIMAL PARA DECIMAL" << endl;
    cout << "===========================================================\n";

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
       cout << "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem hexadecimal\n";
       return; // Retorna para parar a execucao
    }
    else {

        cout << "\n[PASSO 1] Identificando as posicoes dos algarismos..." << endl;
     
        if (posicao_ponto == -1) {
            fim_inteiro = tamanho_string; 
        } else {
            fim_inteiro = posicao_ponto;   
        }

        cout << "\n[PASSO 2] Somatorio Posicional (Parte Inteira):" << endl;
        cout << "Digito\t\tPosicao\t\tConta\t\t\tValor" << endl;
        cout << "-----------------------------------------------------------" << endl;

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
             double valor_posicao = digito * pow(16, potencia_inteiro); // Calculo separado pra tabela
             resultado_decimal = resultado_decimal + valor_posicao; 
             
             // Imprime o caractere, o valor traduzido entre parenteses, e a conta
             cout << c << " (" << digito << ")\t" << potencia_inteiro << "\t\t" << digito << " * 16^" << potencia_inteiro << "\t\t" << valor_posicao << endl;
             
         potencia_inteiro++;
        }
        
        // parte fracionada
        if(posicao_ponto != -1) {
            cout << "\n[PASSO 3] Somatorio Posicional (Parte Fracionaria):" << endl;
            cout << "Digito\t\tPosicao\t\tConta\t\t\tValor" << endl;
            cout << "-----------------------------------------------------------" << endl;
            
         potencia_fracao = -1;
            for (int k = posicao_ponto + 1; k<tamanho_string; k++) {
                if (casa_decimais >= 16) {
                   cout << "\n(Aviso: Sua entrada gerou uma resposta que ultrapassou 16 casas decimais, causando um truncamento, contudo o numero anterior ao truncamento era:)" << endl; 
                    k = tamanho_string; // Truque para o for parar
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
                
                double valor_posicao = digito * pow(16, potencia_fracao);
                resultado_decimal = resultado_decimal + valor_posicao;
                
                cout << c << " (" << digito << ")\t" << potencia_fracao << "\t\t" << digito << " * 16^(" << potencia_fracao << ")\t" << valor_posicao << endl;
                
                potencia_fracao--;
                casa_decimais++;
                }
                
            }
        }
        
        cout << "\n[PASSO 4] Somando tudo:" << endl;
        cout << "Resultado Final: " << resultado_decimal << " (Base 10)\n" << endl;
    }
 }
//========================================================================
//========================================================================
//========================================================================
string passo_binario_octa(string entrada, char tipo_entradaA) {
    int posicao_ponto = -1; 
    string inteiro, fracao; 
    bool e_fracao = false;
    string tabela_binario[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    string resultado = "";

    for (size_t i = 0; i < entrada.length(); i++) {
        if (entrada[i] == '.' || entrada[i] == ',') {
            posicao_ponto = static_cast<int>(i);
        }    
    }

    if (posicao_ponto == -1) {
        inteiro = entrada;
        fracao = "";
    } else {
        inteiro = entrada.substr(0, posicao_ponto);
        fracao = entrada.substr(posicao_ponto + 1);
        e_fracao = true;
    }

    if (tipo_entradaA == 'A' || tipo_entradaA == 'a') {
        cout << "\n===========================================================\n";
        cout << "   PASSO A PASSO: BINARIO PARA OCTAL" << endl;
        cout << "===========================================================\n";
        cout << "\n[PASSO 1] Agrupamento de Bits (Multiplos de 3):" << endl;
        
        while (inteiro.length() % 3 != 0) inteiro = "0" + inteiro;
        if (e_fracao) while (fracao.length() % 3 != 0) fracao = fracao + "0";

        cout << "Inteiro ajustado: " << inteiro << "\nFracao ajustada: " << fracao << endl;
        cout << "\n[PASSO 2] Traducao (Tabela de agrupamento):" << endl;
        cout << "Grupo (Bin)\t->\tDigito (Octal)" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for (size_t i = 0; i < inteiro.length(); i += 3) {
            string grupo = inteiro.substr(i, 3);
            for (int j = 0; j < 8; j++) {
                if (tabela_binario[j] == grupo) {
                    cout << grupo << "\t\t->\t" << j << endl;
                    resultado += to_string(j);
                }
            }
        }
        if (e_fracao) {
            resultado += ".";
            for (size_t i = 0; i < fracao.length(); i += 3) {
                string grupo = fracao.substr(i, 3);
                for (int j = 0; j < 8; j++) {
                    if (tabela_binario[j] == grupo) {
                        cout << grupo << "\t\t->\t" << j << endl;
                        resultado += to_string(j);
                    }
                }
            }
        }
    } else {
        cout << "\n===========================================================\n";
        cout << "   PASSO A PASSO: OCTAL PARA BINARIO" << endl;
        cout << "===========================================================\n";
        cout << "\n[PASSO 1] Expansao de digitos (Cada octal = 3 bits):" << endl;
        cout << "Digito (Octal)\t->\tGrupo (Bin)" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for (size_t i = 0; i < inteiro.length(); i++) {
            int indice = inteiro[i] - '0'; 
            cout << inteiro[i] << "\t\t->\t" << tabela_binario[indice] << endl;
            resultado += tabela_binario[indice];
        }
        if (e_fracao) {
            resultado += ".";
            for (size_t i = 0; i < fracao.length(); i++) {
                int indice = fracao[i] - '0';
                cout << fracao[i] << "\t\t->\t" << tabela_binario[indice] << endl;
                resultado += tabela_binario[indice];
            }
        }
    }
    
    cout << "\nResultado Final: " << resultado << endl;
    return resultado; 
}
//========================================================================
//========================================================================
//========================================================================
string passo_binario_hexa(string entrada, char tipo_entradaB) {
    int posicao_ponto = -1; 
    string inteiro, fracao; 
    bool e_fracao = false;
    string tabela_binario[] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    };
    string letras = "ABCDEF";
    string resultado = ""; 

    // Descobre se tem ponto ou vírgula
    for (size_t i = 0; i < entrada.length(); i++){
        if (entrada[i] == '.' || entrada[i] == ',' ){
            posicao_ponto = static_cast<int>(i);
        }    
    }

    if (posicao_ponto == -1) {
        inteiro = entrada;
        fracao = "";
    } else {
        inteiro = entrada.substr(0, posicao_ponto); 
        fracao = entrada.substr(posicao_ponto + 1);
        e_fracao = true;
    }

    // Caso tenha escolhido entrada em modo binario
    if (tipo_entradaB == 'A' || tipo_entradaB == 'a'){
        cout << "\n===========================================================\n";
        cout << "   PASSO A PASSO: BINARIO PARA HEXADECIMAL" << endl;
        cout << "===========================================================\n";
        cout << "\n[PASSO 1] Ajuste de bits (Multiplos de 4):" << endl;
        
        while (inteiro.length() % 4 != 0) inteiro = "0" + inteiro;
        if (e_fracao) while (fracao.length() % 4 != 0) fracao = fracao + "0";

        cout << "\n[PASSO 2] Traducao (Tabela de agrupamento):" << endl;
        cout << "Grupo (Bin)\t->\tDigito (Hexa)" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for (size_t i = 0; i < inteiro.length(); i += 4) {
            string grupo = inteiro.substr(i, 4);
            for (int j = 0; j < 16; j++) {
                if (tabela_binario[j] == grupo){
                    cout << grupo << "\t\t->\t" << (j < 10 ? to_string(j) : string(1, letras[j-10])) << endl;
                    resultado += (j < 10 ? to_string(j) : string(1, letras[j - 10]));
                }
            }
        }
        if (e_fracao) {
            resultado += ".";
            for (size_t i = 0; i < fracao.length(); i += 4) {
                string grupo = fracao.substr(i, 4);
                for (int j = 0; j < 16; j++) {
                    if (tabela_binario[j] == grupo){
                        resultado += (j < 10 ? to_string(j) : string(1, letras[j - 10]));
                    }
                }
            }
        }
    } else {
        // Caso a entrada seja HEXADECIMAL (Hexa -> Binário)
        cout << "\n===========================================================\n";
        cout << "   PASSO A PASSO: HEXADECIMAL PARA BINARIO" << endl;
        cout << "===========================================================\n";
        cout << "\n[PASSO 1] Expansao de digitos (Cada hexa = 4 bits):" << endl;
        
        for (size_t i = 0; i < inteiro.length(); i++) {
            char atual = toupper(inteiro[i]); 
            int indice = (atual >= '0' && atual <= '9') ? (atual - '0') : (atual - 'A' + 10);
            cout << atual << "\t\t->\t" << tabela_binario[indice] << endl;
            resultado += tabela_binario[indice];
        } 
        if (e_fracao) {
            resultado += ".";
            for (size_t i = 0; i < fracao.length(); i++) {
                char atual = toupper(fracao[i]);
                int indice = (atual >= '0' && atual <= '9') ? (atual - '0') : (atual - 'A' + 10);
                cout << atual << "\t\t->\t" << tabela_binario[indice] << endl;
                resultado += tabela_binario[indice];
            }
        }
    }
    
    cout << "\nResultado Final: " << resultado << endl;
    return resultado; // Agora ela retorna a string para o seu fluxo de conversao
}
//========================================================================
//========================================================================
//========================================================================
string passo_octal_hexa(string entrada) {
    string conversao, resultado_final;

    cout << "\n===========================================================\n";
    cout << "   INICIANDO CONVERSAO: OCTAL -> HEXADECIMAL" << endl;
    cout << "   (Via binario como ponte)" << endl;
    cout << "===========================================================\n";

    // 1. Octal para Binário
    // Ao chamar a função, ela já vai imprimir o rastro (passo a passo) na tela
    conversao = passo_binario_octa(entrada, 'B');

    cout << "\n\n--- PONTE CONCLUIDA: Resultado intermediario em binario: " << conversao << " ---" << endl;

    // 2. Binário para Hexadecimal
    // A função binario_hexa também imprime seu rastro automaticamente
    resultado_final = passo_binario_hexa(conversao, 'A');

    cout << "\n===========================================================\n";
    cout << "   CONVERSAO FINALIZADA" << endl;
    cout << "   Resultado: " << entrada << " (Base 8) = " << resultado_final << " (Base 16)" << endl;
    cout << "===========================================================\n";

    return resultado_final;
}
//========================================================================
//========================================================================
//========================================================================
string passo_hexa_octal(string entrada) {
    string conversao, resultado_final;

    cout << "\n===========================================================\n";
    cout << "   INICIANDO CONVERSAO: HEXADECIMAL -> OCTAL" << endl;
    cout << "   (Via binario como ponte)" << endl;
    cout << "===========================================================\n";

    // 1. Hexadecimal para Binário (Expansão de 4 bits)
    // O rastro detalhado (tabela de mapeamento) aparece aqui
    conversao = passo_binario_hexa(entrada, 'B');

    cout << "\n\n--- PONTE CONCLUIDA: Resultado intermediario em binario: " << conversao << " ---" << endl;

    // 2. Binário para Octal (Agrupamento de 3 bits)
    // O rastro detalhado (agrupamento e somatório) aparece aqui
    resultado_final = passo_binario_octa(conversao, 'A');

    cout << "\n===========================================================\n";
    cout << "   CONVERSAO FINALIZADA" << endl;
    cout << "   Resultado: " << entrada << " (Base 16) = " << resultado_final << " (Base 8)" << endl;
    cout << "===========================================================\n";

    return resultado_final;
}
//========================================================================
//========================================================================
//========================================================================
void passo_converterdecimal (){

    double numero = 0.0;
    double fracao = 0.0;
    int inteiro = 0;

    cout<< "Insira seu numero em DECIMAL";
    cin>>numero;
    
    passo_decimal_binario(numero);
    passo_decimal_octa(numero);
    passo_decimal_hexa(numero);
}




//função para chamar as conversoões de binario octa e hexa
void passo_converter_para_decimal(){
     char escolha;
     string entrada;

    cout<<" Qual seu tipo de entrada?"<<endl;
    cout<<"Caso seja binario digite a letra A."<<endl;
    cout<<"Caso seja octal digite a letra B."<<endl;
    cout<<"Caso seja hexadecimal digite a letra C."<<endl;
    cin>>escolha;
        cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

    cout<< "Agora digite a sua entrada: ";
    cin>>entrada;
    cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

 switch (escolha){
        case 'a':
        case 'A':
        
        passo_binario_decimal(entrada);
         // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

       passo_octal_decimal(entrada);
      
        break;

        case 'c':
        case 'C':
        passo_hexa_decimal(entrada);
        break;

    default:
        cout<<"Opção invalida, por favor tente novamente"<<endl;
        cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        break;
    }
}

// converter binario em octa e binario em hexa e vice versa
void passo_converter_bo_bh(){

    char modo, tipo_entradaA, tipo_entradaB;
    string entrada;

    cout<<"Qual tipo de conversão você deseja utilizar?"<<endl;
    cout<<"Letra A = Converter binário ↔ octal"<<endl;
    cout<<"Letra B = binario ↔ hexadecima "<<endl;
    cin>>modo;

if(modo == 'a'|| modo == 'A'){
cout<<"Sua entrada e binaria ou octal?"<<endl;
cout<<"Letra A caso sua entrada seja binaria"<<endl;
cout<<"Letra B caso sua entrada seja octal"<<endl;
cin>>tipo_entradaA;
    if (tipo_entradaA != 'A' && tipo_entradaA != 'a' && tipo_entradaA != 'B' && tipo_entradaA != 'b'){
        cout <<" Sua escolha não e uma opção. Por favor tente novamente"<<endl;
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        return;
    }
}
else if (modo == 'b'|| modo == 'B'){
cout<<"Sua entrada e binaria ou hexadecimal?"<<endl;
cout<<"Letra A caso sua entrada seja binaria"<<endl;
cout<<"Letra B caso sua entrada seja hexadecimal"<<endl;
cin>>tipo_entradaB;
    cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

    if (tipo_entradaB != 'A' && tipo_entradaB != 'a' && tipo_entradaB != 'B' && tipo_entradaB != 'b'){
        cout <<" Sua escolha não e uma opção. Por favor tente novamente"<<endl;
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        return;
    }
}
else{
    cout<<endl<<"Opção invelida, por favor tente novamente";
            cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
    return;
}
    cout<<endl<<"Agora por favor digite sua entrada: ";
    cin>>entrada;
    
    if (modo == 'a' || modo == 'A') {
        if (tipo_entradaA == 'a' || tipo_entradaA == 'A') { // Espera Binário
            for (size_t i = 0; i < entrada.length(); i++) {
                if (entrada[i] == '.' || entrada[i] == ',') continue;
                if (entrada[i] != '0' && entrada[i] != '1') {
                    cout << "Seu numero nao e binario. Por favor tente novamente." << endl;
                            cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
                    return;
                }
            }
        } else { // Espera Octal
            for (size_t i = 0; i < entrada.length(); i++) {
                if (entrada[i] == '.' || entrada[i] == ',') continue;
                if (entrada[i] < '0' || entrada[i] > '7') {
                    cout << "Seu numero nao e octal. Por favor tente novamente." << endl;
                            cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
                    return;
                }
            }
        }
    }
    else if (modo == 'b' || modo == 'B') {
        if (tipo_entradaB == 'a' || tipo_entradaB == 'A') { // Espera Binário
            for (size_t i = 0; i < entrada.length(); i++) {
                if (entrada[i] == '.' || entrada[i] == ',') continue;
                if (entrada[i] != '0' && entrada[i] != '1') {
                    cout << "Seu numero nao e binario. Por favor tente novamente." << endl;
                            cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
                    return;
                }
            }
        } else { // Espera Hexadecimal
            for (size_t i = 0; i < entrada.length(); i++) {
                if (entrada[i] == '.' || entrada[i] == ',') continue;
                char atual = toupper(entrada[i]);
                if (!(atual >= '0' && atual <= '9') && !(atual >= 'A' && atual <= 'F')) {
                    cout << "Seu numero nao e hexadecimal. Por favor tente novamente." << endl;
                            cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
                    return;
                }
            }
        }
    }
     switch (modo){
        case 'a':
        case 'A':{ //este switch em especifico e nescessario criação de {} pq ele cria funções dentro dele então e nescessario isolar pra n dar erro no c++
            string origem  = (tipo_entradaA == 'a' || tipo_entradaA == 'A') ? "Binario" : "Octal";
            string destino = (tipo_entradaA == 'a' || tipo_entradaA == 'A') ? "Octal" : "Binario";
            
        passo_binario_octa(entrada, tipo_entradaA);
        break; 
        }
        case 'b':
        case 'B':{
            string origem  = (tipo_entradaB == 'a' || tipo_entradaB == 'A') ? "Binario" : "Hexadecimal";
            string destino = (tipo_entradaB == 'a' || tipo_entradaB == 'A') ? "Hexadecimal" : "Binario";
            
        passo_binario_hexa(entrada, tipo_entradaB);
        break;
        }
    default:
        cout<<endl<<"Opção invalida, por favor tente novamente"<<endl;
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        break;
    
    }


}


void passo_converter_OH(){

    char modo, confere;
    string entrada;

    cout<<"Qual tipo de entrada você deseja utilizar?"<<endl;
    cout<<"Letra A = octal"<<endl;
    cout<<"Letra B = hexadecima "<<endl;
    cin>>modo;
        cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

    if (modo != 'A' && modo != 'a' && modo != 'B' && modo != 'b'){
        cout<<"Modo invalido por favor tente novamente: ";
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        return; //como a função e void ela n tem retorno ent ela volta pro menu principal
    }
    cout<<"Agora diga a sua entrada: ";
    cin>> entrada; 
    
    //confere se ele e octal
    if (modo == 'a' || modo == 'A'){
        for (size_t i = 0; i < entrada.length(); i++) {
            // Se for o ponto ou a vírgula da fração, pula pro próximo caractere
            if (entrada[i] == '.' || entrada[i] == ',') continue;
            
            // Se não estiver entre '0' e '7', está errado
            if (entrada[i] < '0' || entrada[i] > '7'){
                cout << "Seu numero nao e octal ou nao e suportado pelo programa." << endl;
                        cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
                return;
            }
        }
    }
    // confere se e hexa
    if (modo == 'b' || modo == 'B'){
        for (size_t i = 0; i < entrada.length(); i++) {
            if (entrada[i] == '.' || entrada[i] == ',') continue;
            
            char atual = toupper(entrada[i]); // Garante que a letra tá em maiúsculo para checar
            
            // Checa se o caractere NÃO é um número de 0-9 E TAMBÉM NÃO é uma letra de A-F
            if ( !(atual >= '0' && atual <= '9') && !(atual >= 'A' && atual <= 'F') ) {
                 cout << "Seu numero nao e hexadecimal ou nao e suportado pelo programa." << endl;
                         cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
                 return;
            }
        }
     }
  
    switch (modo){
        case 'a':
        case 'A':

       passo_octal_hexa(entrada); // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

        passo_hexa_octal(entrada);
        break;

       default:
       cout<<"Opção invalida, por favor tente novamente";
               cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
       return;
        break;
    }
}

    void passo_conversor(){ 



    char escolha;

    cout<<"Por favor insira abaixo oque deseja fazer (passo a passo) "<<endl;
    cout<<"Letra A = Converter decimal → binário/octal/hexadecimal (passo a passo)"<<endl; // Função converterdecimal
    cout<<"Letra B = Converter binário/octal/hexadecimal → decimal (passo a passo)"<<endl;// Função  converter_para_decimal
    cout<<"Letra C = Converter binário ↔ octal e  binário ↔ hexadecimal (passo a passo)"<<endl; //converter_bo_bh
    cout<<"Letra D = octal ↔ hexadecima (passo a passo)"<<endl; //Função converter_OH
    
    cin>>escolha;
    cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

    // Mesmo sistema do menu principal.
    // Assim como no menu principal  seria possivel usar ifs como.
    // if (escolha == 'a' || escolha=='A'){ 
    //converter.....();}
    
     switch (escolha){
        case 'a':
        case 'A':

        passo_converterdecimal(); // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

       passo_converter_para_decimal();
        break;

        case 'c':
        case 'C':

        passo_converter_bo_bh();
        break;

          case 'd':
        case 'D':

        passo_converter_OH(); 
        break; 

        // Trava para caso o usuario escolha uma opção não suportada.
        default:
        cout<<"Opção invalida, por favor tente novamente";
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        break;
    }
}

void passo_passo_arquivo(){
    passo_conversor();
}