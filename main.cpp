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
void  binario_decimal(){
    
    string entrada;

    cout<< "Por favor digite a sua entrada em binario: "<<endl;
    cin>>entrada;







}

void  octal_decimal(){







}
void hexa_decimal(){







}


//função para chamar as conversoões de binario octa e hexa


void converter_para_decimal(){
     char escolha;

    cout<<" Qual seu tipo de entrada?"<<endl;
    cout<<"Caso seja binario digite a letra A."<<endl;
    cout<<"Caso seja octal digite a letra B."<<endl;
    cout<<"Caso seja hexadecimal digite a letra C."<<endl;

 switch (escolha){
        case 'a':
        case 'A':

        binario_decimal(); // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

       octal_decimal();
        break;

        case 'c':
        case 'C':
        hexa_decimal();
        break;

    default:
        cout<<"Opção invalida, p.or favor tente novamente";
        break;



    }
}













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