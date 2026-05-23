#include <iostream> 
#include <cmath>
#include <string>

using namespace std;

// So pra dar uma mensagem de inicio mais bonitinha e separada
void inicializador(){
    cout<<"============================================================================================================="<<endl;
    cout<<endl;
    cout<<"                 Ola usuario, este programa foi feito para converter bases numericas";
    cout<<endl;
    cout<<"============================================================================================================="<<endl;
}  


// função do menu principal, void pq não prescisa retornar valor pra main e sim chamar outras funções (conferir depois)
void menu_principal(){

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



//mesma logica do menu principal, esta  função não nescessita de dar return pq ela so encaminha para outras funções
void conversor(){ 

    char escolha, conversor;

   
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
        cout<<"opção invalida, por favor tente novamente";
        break;
    }


void converterdecimal(){

    float numero;
    
    string binario= ""; // o string normalmente e usado pra palavras, mais o mesmo pode ser usado pra guardar

   



}
        



