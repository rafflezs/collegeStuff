#ifndef _PEDIDO_H
#define _PEDIDO_H

#include "Produto.h"

#include <vector>

class Pedido{
    private:
        std::vector <Produto*> lista;

        int num;
        std::string data;
        int qtdItens;

    public:
        int getNum();
        void setNum(const int &);

        std::string getData();
        void setData(const std::string &);

        int getQtd();
        void setQtd(const int &);

        void criaPedido(Produto* prod);
};

#endif