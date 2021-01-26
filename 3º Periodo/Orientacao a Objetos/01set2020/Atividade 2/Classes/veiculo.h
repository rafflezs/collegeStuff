#ifndef _VEICULO_H
#define _VEICULO_H

#include <string>

using namespace std;

class Veiculo{

    private:
        string modelo;
        int numLugares;
        int comprimento;
        int ano;
        string cor;

    public:
        void setModelo(const string &);
        void setNumLugares(const int &);
        void setComprimento(const int &);
        void setAno(const int &);
        void setCor(const string &);

        string getModelo();
        int getNumLugares();
        int getComprimento();
        int getAno();
        string getCor();
};

#endif