#include <iostream>
#include <string>
#include "conversores.h"

using namespace std;

// função para mostrar na tela o resultado de qualquer conversão comum
void exibir_resultado_conversao(string resultado, string base_origem, string base_destino) {
    cout << endl;
    cout << "==================================================" << endl;
    cout << "               RESULTADO DA CONVERSAO             " << endl;
    cout << "==================================================" << endl;
    cout << "  Base de Origem:  " << base_origem << endl;
    cout << "  Base de Destino: " << base_destino << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "  O numero convertido e: " << resultado << endl;
    cout << "==================================================" << endl;
    cout << endl;
}
// Função que apenas recebe os textos calculados e joga na tela
void exibir_resultado_calculadora(string max_dec, string max_bin, string max_oct, string max_hex, int k) {
    cout << endl;
    cout << "==================================================" << endl;
    cout << "    VALORES MAXIMOS COM " << k << " DIGITOS " << endl;
    cout << "==================================================" << endl;
    cout << "  Maximo em Decimal:     " << max_dec << endl;
    cout << "  Maximo em Binario:     " << max_bin << endl;
    cout << "  Maximo em Octal:       " << max_oct << endl;
    cout << "  Maximo em Hexadecimal: " << max_hex << endl;
    cout << "==================================================" << endl;
    cout << endl;
}