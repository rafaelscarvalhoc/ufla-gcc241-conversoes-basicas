#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

#include "conversores.h"
#include "quiz.h"

using namespace std;

// Nossa durelli que trabalho complexo e dificil em a gente passou ja umas 24 horas em frente ao vs code so nesse trabalho :(

void iniciar_quiz() {
    static bool inicializado = false;
    if (!inicializado) {
        srand(time(0));
        inicializado = true;
        // inicializador e mecanismo pra evitar repetição
    }

    int pontuacao = 0;
    int total_niveis = 5;
// pontuação e niveis

    cout << "\n--- QUIZ DE BASES: MODO TOTAL ---" << endl;

    for (int nivel = 1; nivel <= total_niveis; nivel++) {
    // Loop pra controla o número de perguntas do quiz
        int limite = (int)pow(10, nivel);
        if (limite < 10) limite = 10;

        int num_decimal = 1 + rand() % (limite - 1);

        int tipo = rand() % 6;
    // sorteia qual o metodo da conversão

        string resposta_usuario, resposta_correta, enunciado;

        switch (tipo) {
            // parte bruta do quiz
            case 0:
                enunciado = "Decimal " + to_string(num_decimal) + " para BINARIO";
                resposta_correta = decimal_binario((double)num_decimal);
                break;

            case 1:
                enunciado = "Decimal " + to_string(num_decimal) + " para OCTAL";
                resposta_correta = decimal_octa((double)num_decimal);
                break;

            case 2:
                enunciado = "Decimal " + to_string(num_decimal) + " para HEXADECIMAL";
                resposta_correta = decimal_hexa((double)num_decimal);
                break;

            case 3:
                enunciado = "Binario " + decimal_binario((double)num_decimal) + " para DECIMAL";
                resposta_correta = to_string(num_decimal);
                break;

            case 4:
                enunciado = "Octal " + decimal_octa((double)num_decimal) + " para DECIMAL";
                resposta_correta = to_string(num_decimal);
                break;

            case 5:
                enunciado = "Hexa " + decimal_hexa((double)num_decimal) + " para DECIMAL";
                resposta_correta = to_string(num_decimal);
                break;
        }

        cout << "\n[Nivel " << nivel << "] Converta: " << enunciado << endl;
        cout << "Sua resposta: ";
        cin >> resposta_usuario;

       // sistema de resposta

        resposta_usuario.erase(
            remove(resposta_usuario.begin(), resposta_usuario.end(), ' '),
            resposta_usuario.end()
        );

        resposta_correta.erase(
            remove(resposta_correta.begin(), resposta_correta.end(), ' '),
            resposta_correta.end()
        );

        for (char &c : resposta_usuario)
            if (c >= 'a' && c <= 'z')
                c = c - 32;

        for (char &c : resposta_correta)
            if (c >= 'a' && c <= 'z')
                c = c - 32;

        // -----------------------------
        // COMPARAÇÃO
        // -----------------------------

        if (resposta_usuario == resposta_correta) {
            cout << "\n✔ Correto! (+1 ponto)" << endl;
            pontuacao++;
        } else {
            cout << "\n✖ Errado! Resposta correta: " << resposta_correta << endl;
        }
    }

    cout << "\n======================================" << endl;
    cout << "FIM DO QUIZ! Pontuacao final: "
         << pontuacao << "/" << total_niveis << endl;
    cout << "======================================" << endl;
}