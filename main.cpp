#include <iostream> 
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <cctype>
#include <clocale> // para corrigir os assentos do cout
#include "conversores.h" //conecta a main com os outros conversores
#include "passo_passo.h" // conecta o passo a passo
#include <cstdlib> // Para rand
#include <ctime>   // Para time
#include "quiz.h"

using namespace std;


//função para chamar as conversoões de binario octa e hexa
void converterdecimal (){

    double numero = 0.0;
    double fracao = 0.0;
    int inteiro = 0;

    cout<< "Insira seu numero em DECIMAL";
    cin>>numero;
    
   exibir_resultado_conversao(decimal_binario(numero), "Decimal", "Binario");
    exibir_resultado_conversao(decimal_octa(numero), "Decimal", "Octal");
    exibir_resultado_conversao(decimal_hexa(numero), "Decimal", "Hexadecimal");
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
        cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

    cout<< "Agora digite a sua entrada: ";
    cin>>entrada;
    cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

 switch (escolha){
        case 'a':
        case 'A':
        
        exibir_resultado_conversao(binario_decimal(entrada), "Binario", "Decimal");
         // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

        exibir_resultado_conversao(octal_decimal(entrada), "Octal", "Decimal");
      
        break;

        case 'c':
        case 'C':
        exibir_resultado_conversao(hexa_decimal(entrada), "Hexadecimal", "Decimal");
        break;

    default:
        cout<<"Opção invalida, por favor tente novamente"<<endl;
        cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        break;
    }
}

// converter binario em octa e binario em hexa e vice versa
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
            
            exibir_resultado_conversao(binario_octa(entrada, tipo_entradaA), origem, destino);
        break; 
        }
        case 'b':
        case 'B':{
            string origem  = (tipo_entradaB == 'a' || tipo_entradaB == 'A') ? "Binario" : "Hexadecimal";
            string destino = (tipo_entradaB == 'a' || tipo_entradaB == 'A') ? "Hexadecimal" : "Binario";
            
            exibir_resultado_conversao(binario_hexa(entrada, tipo_entradaB), origem, destino);
        break;
        }
    default:
        cout<<endl<<"Opção invalida, por favor tente novamente"<<endl;
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        break;
    
    }


}


void converter_OH(){

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

        exibir_resultado_conversao(octal_hexa(entrada), "Octal", "Hexadecimal"); // conta escolhida do usuario
        break; //Para parar o codigo 

        case 'b':
        case 'B':

        exibir_resultado_conversao(hexa_octal(entrada), "Hexadecimal", "Octal");
        break;

       default:
       cout<<"Opção invalida, por favor tente novamente";
               cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
       return;
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
    cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

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
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        break;
    }
}


void calculadora() {
    int k;

    cout << "=== CALCULADORA DE MAXIMOS ===" << endl;
    cout << "Digite a quantidade de digitos/bits (k): ";
    cin >> k;

    // Validação pra saber se a entrada e valida
    if (k <= 0) {
        cout << "Quantidade invalida! Por favor, digite um numero maior que zero." << endl;
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
        return; // Retorna para o menu principal
    }
        if (k >= 64) {
        k = 64;
    }
    unsigned long long max_decimal;
if (k == 64) {
        max_decimal = 18446744073709551615ULL; // Teto absoluto
    } else {
        max_decimal = (1ULL << k) - 1;         // Fórmula matemática (2^k - 1)
    }
    // Guardamos o resultado dos cálculos em variáveis do tipo string
    
    string max_binario = maximo_binario(k);
    string max_octal   = maximo_octal(k);
    string max_hexa    = maximo_hexa(k);
    
    //chamada resultado
    exibir_resultado_calculadora(to_string(max_decimal),max_binario, max_octal, max_hexa, k);
}

void passo_passo() {
   passo_passo_arquivo();
}

void batch() {

    ifstream entrada("entrada.csv");
    ofstream saida("saida.csv");

    string valor;
    string origem;
    string destino;

    string resultado;

    if(!entrada){

        cout << "Erro ao abrir entrada.csv" << endl;
        return;
    }

    while(

        getline(entrada, valor, ';') &&
        getline(entrada, origem, ';') &&
        getline(entrada, destino)

    ){

        resultado = "Conversao nao suportada";

        if(origem == "decimal" && destino == "binario"){

            resultado = decimal_binario(stod(valor));
        }

        else if(origem == "decimal" && destino == "octal"){

            resultado = decimal_octa(stod(valor));
        }

        else if(origem == "decimal" && destino == "hexa"){

            resultado = decimal_hexa(stod(valor));
        }

        else if(origem == "binario" && destino == "decimal"){

            resultado = binario_decimal(valor);
        }

        else if(origem == "octal" && destino == "decimal"){

            resultado = octal_decimal(valor);
        }

        else if(origem == "hexa" && destino == "decimal"){

            resultado = hexa_decimal(valor);
        }

        else if(origem == "binario" && destino == "octal"){

            resultado = binario_octa(valor, 'A');
        }

        else if(origem == "octal" && destino == "binario"){

            resultado = binario_octa(valor, 'B');
        }

        else if(origem == "binario" && destino == "hexa"){

            resultado = binario_hexa(valor, 'A');
        }

        else if(origem == "hexa" && destino == "binario"){

            resultado = binario_hexa(valor, 'B');
        }

        else if(origem == "octal" && destino == "hexa"){

            resultado = octal_hexa(valor);
        }

        else if(origem == "hexa" && destino == "octal"){

            resultado = hexa_octal(valor);
        }

        saida << valor << ";"
              << origem << ";"
              << resultado << ";"
              << destino << endl;
    }

    entrada.close();
    saida.close();

    cout << "\nArquivo saida.csv gerado com sucesso!\n";
}


void quiz() {
    iniciar_quiz();
}

void menu_principal(){
// função do menu principal, void pq não prescisssa retornar valor pra main e sim chamar outras funções

    char escolhaMP; 
    
     cout<<"Por favor insira abaixo oque deseja fazer (São aceitas letras maiusculas e minusculas)"<<endl;
     cout<<"Letra A= Modo conversor."<<endl;
     cout<<"Letra B= Modo passo a passo."<<endl;// esse vai ficar pra depois
     cout<<"Letra C= Modo batch."<<endl; // tambem fica pra depois 
     cout<<"Letra D= Modo quiz."<<endl; // tambem fica pra depois ;) 
     cout<<"Letra E= Calculadora de máximos."<<endl; // tambem fica pra depois ;) 
     
    cin>>escolhaMP;
    cin.ignore(10000, '\n'); // pra caso o usuario digite algo amais que 1 carcter o cin limpe apos ser lido 

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
        cout<<"Opção invalida, por favor tente novamente"<<endl;
                cin.clear();           // pra limpar o cin em caso de erro
        cin.ignore(10000, '\n'); // limpa o resto da sujeira(garantia)
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
    setlocale(LC_ALL, "pt_BR.UTF-8"); // pra resolver os assentos do terminal ;)
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
