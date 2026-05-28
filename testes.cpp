#include <iostream>
#include <string>
#include <iomanip>
#include "conversores.h"

using namespace std;

// Contador para rastrear os testes
int totalTestes = 0;
int acertos = 0;

void verificar(string nome, string obtido, string esperado) {
    totalTestes++;
    if (obtido == esperado) {
        acertos++;
        cout << "[✅ SUCESSO] Teste #" << setfill('0') << setw(2) << totalTestes << ": " << nome << endl;
    } else {
        cout << "[❌ FALHA  ] Teste #" << setfill('0') << setw(2) << totalTestes << ": " << nome << endl;
        cout << "            -> Esperado: [" << esperado << "]" << endl;
        cout << "            -> Recebido: [" << obtido << "]" << endl;
    }
}

int main() {
    cout << "====================================================" << endl;
    cout << "          SUITE DE 50 TESTES (PRONTO PARA GRAVAR)   " << endl;
    cout << "====================================================" << endl;

    cout << "\n--- 1. DECIMAL PARA BASES ---" << endl;
    verificar("Conversao de Decimal 0 para Binario", decimal_binario(0), "0");
    verificar("Conversao de Decimal 1 para Binario", decimal_binario(1), "1");
    verificar("Conversao de Decimal 7 para Binario", decimal_binario(7), "111");
    verificar("Conversao de Decimal 10 para Binario", decimal_binario(10), "1010");
    verificar("Conversao de Decimal 15 para Binario", decimal_binario(15), "1111");
    verificar("Conversao de Decimal 32 para Binario", decimal_binario(32), "100000");
    verificar("Conversao de Decimal 8 para Octal", decimal_octa(8), "10");
    verificar("Conversao de Decimal 15 para Octal", decimal_octa(15), "17");
    verificar("Conversao de Decimal 64 para Octal", decimal_octa(64), "100");
    verificar("Conversao de Decimal 512 para Octal", decimal_octa(512), "1000");
    verificar("Conversao de Decimal 10 para Hexadecimal", decimal_hexa(10), "A");
    verificar("Conversao de Decimal 15 para Hexadecimal", decimal_hexa(15), "F");
    verificar("Conversao de Decimal 255 para Hexadecimal", decimal_hexa(255), "FF");
    verificar("Conversao de Decimal 16 para Hexadecimal", decimal_hexa(16), "10");

    cout << "\n--- 2. BASES PARA DECIMAL ---" << endl;
    verificar("Conversao de Binario 101 para Decimal", binario_decimal("101"), "5");
    verificar("Conversao de Binario 1111 para Decimal", binario_decimal("1111"), "15");
    verificar("Conversao de Binario 10000 para Decimal", binario_decimal("10000"), "16");
    verificar("Conversao de Octal 12 para Decimal", octal_decimal("12"), "10");
    verificar("Conversao de Octal 77 para Decimal", octal_decimal("77"), "63");
    verificar("Conversao de Octal 100 para Decimal", octal_decimal("100"), "64");
    verificar("Conversao de Hexadecimal A para Decimal", hexa_decimal("A"), "10");
    verificar("Conversao de Hexadecimal 1A para Decimal", hexa_decimal("1A"), "26");
    verificar("Conversao de Hexadecimal FF para Decimal", hexa_decimal("FF"), "255");

    cout << "\n--- 3. BINARIO E HEXADECIMAL/OCTAL ---" << endl;
    verificar("Conversao de Binario 110 para Octal", binario_octa("110", 'A'), "6");
    verificar("Conversao de Octal 6 para Binario", binario_octa("6", 'B'), "110");
    verificar("Conversao de Binario 111 para Octal", binario_octa("111", 'A'), "7");
    verificar("Conversao de Octal 7 para Binario", binario_octa("7", 'B'), "111");
    verificar("Conversao de Binario 1010 para Hexadecimal", binario_hexa("1010", 'A'), "A");
    verificar("Conversao de Hexadecimal A para Binario", binario_hexa("A", 'B'), "1010");
    verificar("Conversao de Binario 1111 para Hexadecimal", binario_hexa("1111", 'A'), "F");
    verificar("Conversao de Hexadecimal F para Binario", binario_hexa("F", 'B'), "1111");

    cout << "\n--- 4. TESTES DE LIMITE (MAXIMOS) ---" << endl;
    verificar("Calculo do Maximo Binario para 4 bits", maximo_binario(4), "1111");
    verificar("Calculo do Maximo Octal para 4 bits", maximo_octal(4), "17");
    verificar("Calculo do Maximo Hexadecimal para 4 bits", maximo_hexa(4), "F");
    verificar("Calculo do Maximo Binario para 8 bits", maximo_binario(8), "11111111");
    verificar("Calculo do Maximo Octal para 8 bits", maximo_octal(8), "377");
    verificar("Calculo do Maximo Hexadecimal para 8 bits", maximo_hexa(8), "FF");
    verificar("Calculo do Maximo Binario para 16 bits", maximo_binario(16), "1111111111111111");
    verificar("Calculo do Maximo Hexadecimal para 16 bits", maximo_hexa(16), "FFFF");

    cout << "\n--- 5. CASOS EXTRAS DE VERIFICACAO ---" << endl;
    verificar("Conversao de Decimal 3 para Binario", decimal_binario(3), "11");
    verificar("Conversao de Decimal 4 para Binario", decimal_binario(4), "100");
    verificar("Conversao de Decimal 5 para Binario", decimal_binario(5), "101");
    verificar("Conversao de Decimal 7 para Octal", decimal_octa(7), "7");
    verificar("Conversao de Decimal 9 para Octal", decimal_octa(9), "11");
    verificar("Conversao de Hexadecimal 0 para Decimal", hexa_decimal("0"), "0");
    verificar("Conversao de Octal 1 para Decimal", octal_decimal("1"), "1");
    verificar("Conversao de Binario 1 para Decimal", binario_decimal("1"), "1");
    verificar("Conversao de Decimal 6 para Binario", decimal_binario(6), "110");
    verificar("Conversao de Decimal 5 para Octal", decimal_octa(5), "5");
    verificar("Conversao de Hexadecimal 10 para Decimal", hexa_decimal("10"), "16");

    cout << "\n====================================================" << endl;
    cout << "   TESTES FINALIZADOS: " << acertos << "/" << totalTestes << " PASSARAM." << endl;
    if (acertos == totalTestes) {
    cout << "TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
}
    cout << "====================================================" << endl;

    return 0;
}