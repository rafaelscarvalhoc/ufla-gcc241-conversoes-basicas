#ifndef CONVERSORES_H
#define CONVERSORES_H

#include <string>

// ============================================================================
// nucleo das conversões
// ============================================================================

std::string decimal_binario(double numero);
std::string decimal_octa(double numero);
std::string decimal_hexa(double numero);

std::string binario_decimal(std::string entrada);
std::string octal_decimal(std::string entrada);
std::string hexa_decimal(std::string entrada);

std::string binario_octa(std::string entrada, char tipo_entradaA);
std::string binario_hexa(std::string entrada, char tipo_entradaB);

std::string octal_hexa(std::string entrada);
std::string hexa_octal(std::string entrada);

// modos calculadora de maximos
// === DECLARAÇÃO DAS FUNÇÕES DE MÁXIMOS ===
std::string maximo_binario(int k);
std::string maximo_octal(int k);
std::string maximo_hexa(int k);

// ============================================================================
//formatador de saida , arquivo especializado em couts pra fica bonitinho 
// ============================================================================

void exibir_resultado_conversao(std::string resultado, std::string base_origem, std::string base_destino);
void exibir_resultado_calculadora(std::string max_bin, std::string max_oct, std::string max_hex, int k);

// ============================================================================
// INTERFACE menus e modos que estão na menu.cpp
// ============================================================================
void menu_principal();
void inicializador();
void conversor();
void calculadora();
void passo_passo();
void batch();
void quiz();

#endif