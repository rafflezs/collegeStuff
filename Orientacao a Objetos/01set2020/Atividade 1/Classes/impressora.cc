#include "impressora.h"

void Impressora::setMarca(const std::string& input) {
	this->marca = input;
}

std::string Impressora::getMarca() {
	return this->marca;
}

void Impressora::setModelo(const std::string& input) {
	this->modelo = input;
}

std::string Impressora::getModelo() {
	return this->modelo;
}

void Impressora::setColorida(const bool& input) {
	this->colorida = input;
}

bool Impressora::isColorida() {
	return this->colorida;
}

void Impressora::setPeso(const float& input) {
	this->peso = input;
}

float Impressora::getPeso() {
	return this->peso;
}