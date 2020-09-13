#ifndef _PRODUTO_H
#define _PRODUTO_H

#include <string>

class Produto{

    private:
        int barCode;
        std::string desc;
        float preco;
    public:
        int getBarCode();
        void setBarCode(const int &);
        std::string getDesc();
        void setDesc(const std::string &);
        float getPreco();
        void setPreco(const float &);

};

#endif