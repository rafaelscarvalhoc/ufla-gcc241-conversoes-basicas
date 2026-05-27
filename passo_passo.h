#ifndef PASSOPASSO_H
#define PASSOPASSO_H

#include <string>

void passo_passo_arquivo();
void passo_decimal_binario(double numero);
void passo_decimal_octa(double numero);
void passo_decimal_hexa(double numero);

void passo_binario_decimal(std::string entrada);
void passo_octal_decimal(std::string entrada);
void passo_hexa_decimal(std::string entrada);

std::string passo_binario_octa(std::string entrada, char tipo_entradaA);
std::string passo_binario_hexa(std::string entrada, char tipo_entradaB);

std::string passo_octal_hexa(std::string entrada);
std::string passo_hexa_octal(std::string entrada);

void passo_converterdecimal();

#endif