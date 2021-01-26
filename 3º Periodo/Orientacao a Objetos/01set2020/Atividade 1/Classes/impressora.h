#ifndef _IMPRESSORA_H
#define _IMPRESSORA_H

#include <string>
#include <iostream>

class Impressora {

	private:
		std::string marca;
		std::string modelo;
		bool colorida;
		float peso;
	public:

		void setMarca(const std::string &);
		std::string getMarca();

		void setModelo(const std::string&);
		std::string getModelo();

		void setColorida(const bool&);
		bool isColorida();

		void setPeso(const float&);
		float getPeso();
};

#endif // !_IMPRESSORA_H