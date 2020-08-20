#include "logica.h"

int Logica::menu(){

    int op;
    cout << "[1] CADASTRAR Autor" << endl;
    cout << "[2] CADASTRAR Livro" << endl;
    cout << "[3] ALTERAR Autor" << endl;
    cout << "[4] ALTERAR Livro" << endl;
    cout << "[5] EXCLUI Autor" << endl;
    cout << "[6] EXCLUI Livro" << endl;
    cout << "[7] EXIBE Autor" << endl;
    cout << "[8] EXIBE Livro" << endl;
    cout << "Escolha uma opção: ";
    cin >> op;

    return op;

}

void Logica::start(){

    int op;

    do{

    op = menu();
        switch (op){
                case 1:{
                
                string temp;
    
                cin >> temp;
    
                Autor* aut = criaAutor(temp);
    
                autores.push_back(aut);
            }break;
            case 2:{

                string temp;

                cin >> temp;

                Livro* liv = criaLiv(autores[0]);

                livros.push_back(liv);
            }break;

        }
    } while (op != 0);
}

Autor* Logica::criaAutor(string temp){

    Endereco* end = new Endereco();

    Autor* aut = new Autor(end, temp);

    return aut;
}

vector<Capitulo*> Logica::criaCap(){

    vector<Capitulo*> caps;

    return caps;
}

Livro* Logica::criaLiv(Autor* aut){

    vector <Capitulo*> disc = criaCap();
    Editora* ed = new Editora(aut->getEndereco());
    Livro* liv = new Livro(disc, ed, aut);

    return liv;
}

