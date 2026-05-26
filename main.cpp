#include <iostream> 
#include <cmath>
#include <string>

using namespace std;

// conversão E MENU da letra a do menu  conversor
//================================================================================================================================
//================================================================================================================================
//================================================================================================================================
//================================================================================================================================





// função pra converter decimal em binario
 void decimal_binario(int inteiro, double fracao, bool temFracao){

    int  inteirovt [16], fracaovt [16], i=0;
    int  c=0; // contador

  if (inteiro == 0) {
        inteirovt[0] = 0;
        i = 1;
        //if para o programa não dar erro caso a parte inteira seja 0 
     } else {
    
    // trasformar em binario a parte inteira
    while (inteiro>0){
        inteirovt[i] = inteiro%2;
        inteiro = inteiro/2;
        i++;
    }
}
    // trasformar em binario a parte decimal
    while (fracao>0 && c<16){
        fracao= fracao*2;
        fracaovt[c] = (int)fracao;
        fracao = fracao - fracaovt [c];
        c++;
    }


     if (fracao>0){
        cout<< endl  <<" Seu numero ultrapassou 16 numeros apos a virgula causando um truncamento"<<endl;

    }

    cout<<"Seu numero em binario e: ";

   for (int k = i - 1; k >= 0; k--) {
    cout << inteirovt[k];
}

if (temFracao){
    cout << ".";

    for (int k = 0; k < c; k++) {
        cout << fracaovt[k];
    }

   }
}



//Função para fazer  decimal para octa
void decimal_octa(int inteiro, double fracao, bool temFracao){

    int  inteirovt [16], fracaovt [16], i=0;
    int  c=0; // contador

     if (inteiro == 0) {
        inteirovt[0] = 0;
        i = 1;
        //if para o programa não dar erro caso a parte inteira seja 0 
     } else {

    // trasformar em binario a parte inteira
    while (inteiro>0){
        inteirovt[i] = inteiro%8;
        inteiro = inteiro/8;
        i++;
    }
}
    // trasformar em octal a parte decimal
    while (fracao>0 && c<16){
        fracao= fracao*8;
        fracaovt[c] = (int)fracao;
        fracao = fracao - fracaovt [c];
        c++;
    }

   if (fracao>0){
        cout<< endl  <<" Seu numero ultrapassou 16 numeros apos a virgula causando um truncamento"<<endl;
   }
    cout<<"Seu numero em octal e: ";
   
   
   for (int k = i - 1; k >= 0; k--) {
    cout << inteirovt[k];
    }

    if (temFracao){
    cout << ".";

    for (int k = 0; k < c; k++) {
        cout << fracaovt[k];
    }
    
    }
    
}


void decimal_hexa(int inteiro, double fracao, bool temFracao){
//função pra converter decimal pra hexadecimal. achei que 1000 linhas fazia tudo eu nem terminei o conversor e ja tem umas 300 ;-;
    int  inteirovt [16], fracaovt [16], i=0;
    int  c=0; // contador

    // guia pro programa escrever em hexa
    char tabela_hexa [] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

     if (inteiro == 0) {
        inteirovt[0] = 0;
        i = 1;
        //if para o programa não dar erro caso a parte inteira seja 0 
     } else {

    // trasformar em binario a parte inteira
    while (inteiro>0){
        inteirovt[i] = inteiro%16;
        inteiro = inteiro/16;
        i++;
    }
}
    // trasformar em octal a parte decimal
    while (fracao>0 && c<16){
        fracao= fracao*16;
        fracaovt[c] = (int)fracao;
        fracao = fracao - fracaovt [c];
        c++;
    }

   if (fracao>0){
        cout<< endl  <<" Seu numero ultrapassou 16 numeros apos a virgula causando um truncamento"<<endl;
   }
    cout<<"Seu numero em hexadecimal e: ";
   
   
   for (int k = i - 1; k >= 0; k--) {
  cout << tabela_hexa[inteirovt[k]];
    }

    if (temFracao){
    cout << ".";

    for (int k = 0; k < c; k++) {
       cout << tabela_hexa[fracaovt[k]];
    }
    
    }
    
}

//função para chamar as conversoões de binario octa e hexa
void converterdecimal (){

    double numero = 0.0;
    double fracao = 0.0;
    int inteiro = 0;

    cout<< "Insira seu numero em DECIMAL";
    cin>>numero;
    
    // separar o inteiro e o fracionado pq eles são diferentes ;)
    inteiro = numero; // int so aceita inteiros ent ela ja separa o inteiro
    fracao = numero - inteiro; // matematica basica so sobra o fracionado 
    bool temFracao = (fracao > 0); // para salvar a informação original se havia numeros apos o . ou a ,

        decimal_binario ( inteiro, fracao, temFracao);
        decimal_octa( inteiro, fracao, temFracao); 
        decimal_hexa ( inteiro, fracao, temFracao);

}

// conversão E MENU da letra a do menu  conversor EM CIMA
//================================================================================================================================
//================================================================================================================================
//================================================================================================================================
//================================================================================================================================





// conversãoes E MENU da letra B do menu  conversor EM BAIXO
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
void  binario_decimal(string entrada){

int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0;
int casa_decimais = 0 ; //trava pra caso passe de 16 casas decimais 
int posicao_ponto = -1; 
//fica como menos 1 pq inicalmente eu to falando pro programa que esse ponto n exite.
//caso o ponto seja achado o posição ponto deve assumir aquele lugar,
// assim marcando onde se encontra o ponto 
bool e_binario = true; // isso e pra conferir se o numero se encaixa no binario, ele podendo ser 0 1 , ou . 
double resultado_decimal = 0.0;

for (int i=0; i< entrada.length(); i++){ //.lenght ele mede quantos caracteres tem a string e me fala o tamanho dela 
    if (entrada [i] != '0' && entrada [i] != '1'&& entrada [i] != ',' && entrada [i] != '.'){
        e_binario = false;
    }

    if (entrada[i]== '.' || entrada[i]== ',' ){// lembrar dos ' '
        posicao_ponto = i;
    }
    }
    if (e_binario == false){
        cout<< "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem binario"<<endl;
    }
    else {

      // descobrir o final da parte inteira
        if (posicao_ponto == -1) {
            fim_inteiro = entrada.length(); // Se não tem ponto o fim e o fim do string entrada msm
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
            for (int k = posicao_ponto + 1; k < entrada.length(); k++) {
                if (casa_decimais >= 16) {
                    cout << endl <<"Sua entrada gerou um resultado que ultrapassou 16 casas decimais, causando um truncamento"; // uma pena meu nobre hihi
                        k = entrada.length(); // truque pra o for parar caso tenha passado
                }
                else {
                     digito = entrada[k] - '0'; // mesma logica de trasformar carcter em numero
                    resultado_decimal = resultado_decimal + (digito * pow(2, potencia_fracao));// mesmo que o 1 so mudando a potencia que e negativa como visto abaixo
                potencia_fracao--;
                casa_decimais++;
                }
                
            }
        }
        cout << "O numero convertido para decimal e: " << resultado_decimal << endl;    
    }
}


void  octal_decimal(string entrada){ // como octal so muda a base o codigo pode ser copiado mudando so a base
int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0, posicao_ponto = -1, casa_decimais = 0; 
bool e_octal = true;
double resultado_decimal = 0.0;

for (int i=0; i< entrada.length(); i++){ //.lenght ele mede quantos caracteres tem a string e me fala o tamanho dela 
    if ((entrada [i] < '0' || entrada [i] > '7')&& entrada [i] != ',' && entrada [i] != '.'){ // && significa e || significa ou 
// mesma logica do diminuir um carcter zero, o programa ja entende as letras e o intervalo delas logo n e presciso "traduzir"
       e_octal = false;
    }

    if (entrada[i]== '.' || entrada[i]== ',' ){// lembrar dos ' '
        posicao_ponto = i;
    }
    }
    if (e_octal == false){
        cout<< "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem octal"<<endl;
    }
    else {

      // descobrir o final da parte inteira
        if (posicao_ponto == -1) {
            fim_inteiro = entrada.length(); 
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
            for (int k = posicao_ponto + 1; k < entrada.length(); k++) {
                if (casa_decimais >= 16) {
                    cout << endl <<"Sua entrada gerou um resultado que ultrapassou o limite de 16 casas decimais, causando um truncamento"; // to sendo sabotado to programando lembrando da musica qual o plural de decimal? decimais decimais
                        k = entrada.length(); 
                }
                else {
                     digito = entrada[k] - '0'; 
                    resultado_decimal = resultado_decimal + (digito * pow(8, potencia_fracao));
                potencia_fracao--;
                casa_decimais++;
                }
                
            }
        }
        cout << "O numero convertido para decimal e: " << resultado_decimal << endl;    
    }
}

void hexa_decimal(string entrada){

int fim_inteiro=0 , potencia_inteiro = 0, potencia_fracao = 0 , digito=0, posicao_ponto = -1, casa_decimais = 0; 
bool e_hexa = true;
double resultado_decimal = 0.0;
char c;
// Criamos uma condição que diz tudo o que é em hexa
for (int i=0; i< entrada.length(); i++){ 
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
        cout<< "O numero digitado não pode ser convertido pois o mesmo não faz parte do sistem hexadecimal"<<endl;
    }
    else {

     
        if (posicao_ponto == -1) {
            fim_inteiro = entrada.length(); 
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
            for (int k = posicao_ponto + 1; k < entrada.length(); k++) {
                if (casa_decimais >= 16) {
                    cout << endl <<"Sua entrada gerou uma resposta que ultrapassou 16 casas decimais, causando um truncamento"; 
                    k = entrada.length();
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
        cout << "O numero convertido para decimal e: " << resultado_decimal << endl;    
    }
 }

//função para chamar as conversoões de binario octa e hexa
void converter_para_decimal(){
     char escolha;
     string entrada;

    cout<<" Qual seu tipo de entrada?"<<endl;
    cout<<"Caso seja binario digite a letra A."<<endl;
    cout<<"Caso seja octal digite a letra B."<<endl;
    cout<<"Caso seja hexadecimal digite a letra C."<<endl;
    cin>>escolha;
    cout<< "Agora digite a sua entrada: ";
    cin>>entrada;

 switch (escolha){
        case 'a':
        case 'A':

        binario_decimal(entrada); // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

       octal_decimal(entrada);
        break;

        case 'c':
        case 'C':
        hexa_decimal(entrada);
        break;

    default:
        cout<<"Opção invalida, por favor tente novamente";
        break;



    }
}


// conversãoes E MENU da letra B do menu  conversor EM  CIMA
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================


// conversãoes E MENU da letra C do menu  conversor EM  BAIXO
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================

string binario_octa (string entrada, char tipo_entradaA){
int posicao_ponto = -1; 
string inteiro, fracao; 
bool e_fracao=false;
string tabela_binario[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
string resultado= "";
for (int i=0; i< entrada.length(); i++){

    if (entrada[i]== '.' || entrada[i]== ',' ){// lembrar dos ' '
        posicao_ponto = i;
        
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

cout << "Resultado em Octal: ";

        // Passo 2: Fatiar e traduzir a parte inteira (pulando de 3 em 3)
        for (int i = 0; i < inteiro.length(); i += 3) {
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
            cout << ".";
            resultado += ".";
            for (int i = 0; i < fracao.length(); i += 3) {
                string grupo = fracao.substr(i, 3);
                for (int j = 0; j < 8; j++) {
                    if (tabela_binario[j] == grupo){
                         cout << j;
                         resultado += to_string(j);
                        }
                    }
                }
            }
          cout << endl;
        }
    else{
// caso a entrada seja em octal

        cout << "Resultado em Binario: ";

        for (int i = 0; i < inteiro.length(); i++) {
            int indice = inteiro[i] - '0'; 
            cout << tabela_binario[indice];
            resultado += tabela_binario[indice];
        }

        if (e_fracao) {
            cout << ".";
            resultado += ".";
            for (int i = 0; i < fracao.length(); i++) {
                int indice = fracao[i] - '0';
                cout << tabela_binario[indice];
                resultado += tabela_binario[indice];
            }
        }
        cout << endl;

    }
    return resultado;
}

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
    for (int i = 0; i < entrada.length(); i++){
        if (entrada[i] == '.' || entrada[i] == ',' ){
            posicao_ponto = i;
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

        for (int i = 0; i < inteiro.length(); i += 4) {
            string grupo = inteiro.substr(i, 4);
            for (int j = 0; j < 16; j++) {
                if (tabela_binario[j] == grupo){
                    if (j < 10){
                    cout << j;
                        resultado += to_string(j);
                    }
                    else { 
                    cout << letras[j - 10];
                    resultado += letras[j - 10];
                    }
                }
            }
        }

        if (e_fracao) {
            cout << ".";
            resultado += ".";
            for (int i = 0; i < fracao.length(); i += 4) {
                string grupo = fracao.substr(i, 4);
                for (int j = 0; j < 16; j++) {
                    if (tabela_binario[j] == grupo){
                        if (j < 10){
                            cout << j;
                            resultado += to_string(j);
                        }
                        else {
                            cout << letras[j - 10]; 
                            resultado += letras[j - 10];
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    else {
        // Caso a entrada seja em HEXADECIMAL (Hexa -> Binário)
        cout << "Resultado em Binario: ";

        //trasforma a parte inteira
        for (int i = 0; i < inteiro.length(); i++) {
            int indice; 
            char atual = toupper(inteiro[i]); 

            if (atual >= '0' && atual <= '9') {
                indice = atual - '0';
            } else {
                indice = atual - 'A' + 10;
            }
            cout << tabela_binario[indice];
            resultado += tabela_binario[indice];
        } 

        // trasforma a parte fracionada 
        if (e_fracao) {
            cout << ".";
            resultado += ".";
            for (int i = 0; i < fracao.length(); i++) {
                int indice;
                char atual = toupper(fracao[i]);

                if (atual >= '0' && atual <= '9') {
                    indice = atual - '0';
                } else {
                    indice = atual - 'A' + 10;
                }
                cout << tabela_binario[indice];
                resultado += tabela_binario[indice];
            }
        }
        cout << endl;
    }
    return resultado;
}





    


void converter_bo_bh(){

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
        return;
    }
}
else if (modo == 'b'|| modo == 'B'){
cout<<"Sua entrada e binaria ou hexadecimal?"<<endl;
cout<<"Letra A caso sua entrada seja binaria"<<endl;
cout<<"Letra B caso sua entrada seja hexadecimal"<<endl;
cin>>tipo_entradaB;
    if (tipo_entradaB != 'A' && tipo_entradaB != 'a' && tipo_entradaB != 'B' && tipo_entradaB != 'b'){
        cout <<" Sua escolha não e uma opção. Por favor tente novamente"<<endl;
        return;
    }
}
else{
    cout<<endl<<"Opção invelida, por favor tente novamente";
    return;
}
    cout<<endl<<"Agora por favor digite sua entrada: ";
    cin>>entrada;
     switch (modo){
        case 'a':
        case 'A':

        binario_octa(entrada, tipo_entradaA);
        break; 

        case 'b':
        case 'B':

       binario_hexa(entrada, tipo_entradaB);
        break;

    default:
        cout<<endl<<"Opção invalida, por favor tente novamente"<<endl;
        break;
    
    }


}

// conversãoes E MENU da letra C do menu  conversor EM  CIMA
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================


// conversãoes E MENU da letra D do menu  conversor EM  baixo
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=======================================================
string octal_hexa(string entrada){
string conversao, resultado_final;

// primeiro octal para binario
conversao = binario_octa ( entrada, 'B');
//depois binario pra hexa
resultado_final = binario_hexa(conversao, 'A');

cout<<"Seu resultado final e: ";

return resultado_final;


}

string hexa_octal(string entrada){
string conversao, resultado_final;

// Primeiro hexa pra binario
conversao = binario_hexa ( entrada, 'B');
//depois binario pra octa
resultado_final = binario_octa(conversao, 'A');

cout<<"Seu resultado final e: ";

return resultado_final;


}


void converter_OH(){

    char modo, confere;
    string entrada;

    cout<<"Qual tipo de entrada você deseja utilizar?"<<endl;
    cout<<"Letra A = octal"<<endl;
    cout<<"Letra B = hexadecima "<<endl;
    cin>>modo;
    
    if (modo != 'A' && modo != 'a' && modo != 'B' && modo != 'b'){
        cout<<"Modo invalido por favor tente novamente: ";
        return; //como a função e void ela n tem retorno ent ela volta pro menu principal
    }
    cout<<"Agora diga a sua entrada: ";
    cin>> entrada; 
    
    //confere se ele e octal
    if (modo == 'a' || modo == 'A'){
        for (int i = 0; i < entrada.length(); i++) {
            // Se for o ponto ou a vírgula da fração, pula pro próximo caractere
            if (entrada[i] == '.' || entrada[i] == ',') continue;
            
            // Se não estiver entre '0' e '7', está errado
            if (entrada[i] < '0' || entrada[i] > '7'){
                cout << "Seu numero nao e octal ou nao e suportado pelo programa." << endl;
                return;
            }
        }
    }
    // confere se e hexa
    if (modo == 'b' || modo == 'B'){
        for (int i = 0; i < entrada.length(); i++) {
            if (entrada[i] == '.' || entrada[i] == ',') continue;
            
            char atual = toupper(entrada[i]); // Garante que a letra tá em maiúsculo para checar
            
            // Checa se o caractere NÃO é um número de 0-9 E TAMBÉM NÃO é uma letra de A-F
            if ( !(atual >= '0' && atual <= '9') && !(atual >= 'A' && atual <= 'F') ) {
                 cout << "Seu numero nao e hexadecimal ou nao e suportado pelo programa." << endl;
                 return;
            }
        }
     }
  
    switch (modo){
        case 'a':
        case 'A':

        octal_hexa(entrada); // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

       hexa_octal(entrada);
        break;

       default:
       cout<<"Opção invalida, por favor tente novamente";
       return;
        break;
    }
}



// conversãoes E MENU da letra D do menu  conversor EM  cima
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================
//=================================================================================================================================================



void conversor(){ 

// função para o usuario escolher qual conversor e de seu desejo 

    char escolha;

    cout<<"Por favor insira abaixo oque deseja fazer "<<endl;
    cout<<"Letra A = Converter decimal → binário/octal/hexadecimal"<<endl; // Função converterdecimal
    cout<<"Letra B = Converter binário/octal/hexadecimal → decimal"<<endl;// Função  converter_para_decimal
    cout<<"Letra C = Converter binário ↔ octal e  binário ↔ hexadecimal "<<endl; //converter_bo_bh
    cout<<"Letra D = octal ↔ hexadecima "<<endl; //Função converter_OH
    
    cin>>escolha;

    // Mesmo sistema do menu principal.
    // Assim como no menu principal  seria possivel usar ifs como.
    // if (escolha == 'a' || escolha=='A'){ 
    //converter.....();}
    
     switch (escolha){
        case 'a':
        case 'A':

        converterdecimal(); // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

       converter_para_decimal();
        break;

        case 'c':
        case 'C':

        converter_bo_bh();
        break;

          case 'd':
        case 'D':

        converter_OH(); 
        break; 

        // Trava para caso o usuario escolha uma opção não suportada.
        default:
        cout<<"Opção invalida, por favor tente novamente";
        break;
    }
}
// menus em desenvolvimento
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
void passo_passo() {
    cout << "\n[Modo Passo a Passo em desenvolvimento...]\n" << endl;
}

void batch() {
    cout << "\n[Modo Batch em desenvolvimento...]\n" << endl;
}

void quiz() {
    cout << "\n[Modo Quiz em desenvolvimento...]\n" << endl;
}

void calculadora() {
    cout << "\n[Calculadora de Maximos em desenvolvimento...]\n" << endl;
    // Aqui depois faremos a pergunta: "Quantos bits deseja analisar?"
}

// menus em desenvolvimento
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================

void menu_principal(){
// função do menu principal, void pq não prescisa retornar valor pra main e sim chamar outras funções

    char escolhaMP; 
    
     cout<<"Por favor insira abaixo oque deseja fazer (São aceitas letras maiusculas e minusculas)"<<endl;
     cout<<"Letra A= Modo conversor."<<endl;
     cout<<"Letra B= Modo passo a passo."<<endl;// esse vai ficar pra depois
     cout<<"Letra C= Modo batch."<<endl; // tambem fica pra depois 
     cout<<"Letra D= Modo quiz."<<endl; // tambem fica pra depois ;) 
     cout<<"Letra E= Calculadora de máximos."<<endl; // tambem fica pra depois ;) 
     
    cin>>escolhaMP;

    //switch feito para selecionar a função correta de acordo com a escolha do usuario :)
    switch (escolhaMP){
        case 'a':
        case 'A':

        conversor(); //para converter
        break; //Para parar o codigo 

        case 'b':
        case 'B':

        passo_passo();
        break;

        case 'c':
        case 'C':

        batch();
        break;

          case 'd':
        case 'D':

        quiz(); 
        break; 

        case 'e':
        case 'E':

        calculadora();
        break;

        // Trava para caso o usuario escolha uma opção não suportada.
        default:
        cout<<"opção invalida, por favor tente novamente";
        break;
        
    }

}
// So pra dar uma mensagem de inicio mais bonitinha e separada
void inicializador(){
    cout<<"============================================================================================================="<<endl;
    cout<<endl;
    cout<<"                 Ola usuario, este programa foi feito para converter bases numericas";
    cout<<endl;
    cout<<"============================================================================================================="<<endl;
}  

int main (){
// Função principal com opção de reiniciar o codigo
 char continuar;
    // ta fora porque so prescisa aparecer 1 vez
    inicializador();
 
    do{ 
// do para o programa fazer isto pelo menos uma vez o famoso do while

     menu_principal();

    cout<<"voce deseja continuar? S/N"<<endl;
    cin>>continuar;

            if (continuar == 's' || continuar == 'S'){
            cout << "O codigo sera reiniciado\n\n"; 
            }
        }while (continuar == 's' || continuar == 'S');
        
            
    cout<<"Obrigado por utilizar nosso codigo adeus S2";
    
    return 0; 
}
