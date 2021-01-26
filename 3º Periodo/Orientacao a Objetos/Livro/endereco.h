#ifndef _ENDERECO_H
#define _ENDERECO_H

#include <string>

using namespace std;

class Endereco{
    private:
        string rua;
        string cep;
        string bairro;
        string cidade;
        string pais;
        int numero;

    public:
        
        string getRua();
        void setRua(const string & rua);

        string getCep();
        void setCep(const string & cep);
        
        string getBairro();
        void setBairro(const string & bairro);

        string getCidade();
        void setCidade(const string & cidade);

        int getNumero();
        void setNumero(const int & numero);

        string getPais();
        void setPais(const string & temp);

        Endereco(/* args */);
        ~Endereco();
};

#endif // !1