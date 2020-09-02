#include "logica.h"

int Logica::menu(){
    int op;

    cout << "[1] Cadastrar\n"
        << "[2] Exibir relatório individual\n"
        << "[3] Exibir relatório total\n"
        << "[4] Alterar registro\n"
        << "[5] Excluir registro\n"
        << "Sua opcao: ";
    cin >> op;
    return op;
};

void Logica::iniciar(){
    int op;

    do
    {
        op = menu();

        system("clear");

        switch (op)
        {
            case 1:{
                add(cria());
            } break;
            case 2:{
                cout << "[1] Consulta por index\n[2] Consulta por nome\n Sua opcao: ";
                int aaaa;
                cin >> aaaa;
                cin.ignore();
/* 
                switch (aaaa)
                {
                case 1:{
                    int index = (int) consultar();
                    break;
                }
                case 2:{
                    string teste = (string) consultar();
                    break;
                }
                default:
                    break;
                }
 */
            } break;
            case 3:{
                exibeTodos();
            } break;
            case 4:{

            } break;
            case 5:{

            } break;
            default: cout << "Opcao invalida\n";
                break;
        }

    } while (op != 0);
    
};

void Logica::add(void* obj){

    if(obj == NULL){
        cout << "Operacao mal-sucedida\n";

    }else if(typeid(obj) == typeid(Pessoa*)){

        this->pessoaLista.push_back((Pessoa*)obj);

    }else if(typeid(obj) == typeid(Fornecedor*)){

        this->forLista.push_back((Fornecedor*)obj);
        this->pessoaLista.push_back((Pessoa*)obj);

    }else if(typeid(obj) == typeid(Empregado*)){

        this->empreLista.push_back((Empregado*)obj);
        this->pessoaLista.push_back((Pessoa*)obj);

    }else if(typeid(obj) == typeid(Administrador*)){

        this->admLista.push_back((Administrador*) obj);
        this->pessoaLista.push_back((Pessoa*)obj);

    }else if(typeid(obj) == typeid(Cliente*)){

        this->clienteLista.push_back((Cliente*)obj);
        this->pessoaLista.push_back((Pessoa*)obj);

    }else if(typeid(obj) == typeid(Operario*)){

        this->opLista.push_back((Operario*)obj);
        this->pessoaLista.push_back((Pessoa*)obj);

    }else if(typeid(obj) == typeid(Vendedor*)){

        this->vendLista.push_back((Vendedor*) obj);
        this->pessoaLista.push_back((Pessoa*)obj);

    }

};

void* Logica::cria(){
    string op;
    cout << "Cadastro simples\n" 
        << "[P]essoa\n[F]ornecedor\n[E]mpregado\n[A]dministrador\n[C]liente\n[O]perario\n[V]endedor\n"
        << "Sua opcao: ";
    cin >> op;

    cin.ignore();

    switch (op[0])
    {
            case 'p':{

                Pessoa* temp = new Pessoa();

                getline(cin, op);
                temp->setIdade(stoi(op));

                getline(cin, op);
                temp->setNome(op);

                getline(cin, op);
                temp->setNumContribuinte(op);

                return temp;

            } break;
            case 'f':{

                Fornecedor* temp = new Fornecedor();

                getline(cin, op);
                temp->setIdade(stoi(op));

                getline(cin, op);
                temp->setNome(op);

                getline(cin, op);
                temp->setNumContribuinte(op);

                getline(cin, op);
                temp->setPlafond(stof(op));

                getline(cin, op);
                temp->setValorDivida(stof(op));

                temp->obterSaldo();

                return temp;

            } break;
            case 'e':{

                Empregado* temp = new Empregado();

                getline(cin, op);
                temp->setIdade(stoi(op));

                getline(cin, op);
                temp->setNome(op);

                getline(cin, op);
                temp->setNumContribuinte(op);

                getline(cin, op);
                temp->setIrs(stof(op));

                getline(cin, op);
                temp->setNumeroSecao(op);

                getline(cin, op);
                temp->setSalarioBase(stof(op));

                return temp;

            } break;
            case 'a':{

                Administrador* temp = new Administrador();

                getline(cin, op);
                temp->setIdade(stoi(op));

                getline(cin, op);
                temp->setNome(op);

                getline(cin, op);
                temp->setNumContribuinte(op);

                getline(cin, op);
                temp->setIrs(stof(op));

                getline(cin, op);
                temp->setNumeroSecao(op);

                getline(cin, op);
                temp->setSalarioBase(stof(op));

                getline(cin, op);
                temp->setAjudaCusto(stof(op));            

                temp->calcularSalario();

                return temp;

            } break;
            case 'c':{

                Cliente* temp = new Cliente();

                getline(cin, op);
                temp->setIdade(stoi(op));

                getline(cin, op);
                temp->setNome(op);

                getline(cin, op);
                temp->setNumContribuinte(op);

                getline(cin, op);
                temp->setPlafond(stof(op));

                getline(cin, op);
                temp->setValorDivida(stof(op));     

                temp->obterSaldo();           

                return temp;

            } break;
            case 'o':{

                Operario* temp = new Operario();

                getline(cin, op);
                temp->setIdade(stoi(op));

                getline(cin, op);
                temp->setNome(op);

                getline(cin, op);
                temp->setNumContribuinte(op);

                getline(cin, op);
                temp->setNumeroSecao(op);

                getline(cin, op);
                temp->setSalarioBase(stof(op));

                getline(cin, op);
                temp->setValorProducao(stof(op));

                getline(cin, op);
                temp->setIrs(stof(op));

                temp->calcularSalario();

                return temp;

            } break;
            case 'v':{

                Vendedor* temp = new Vendedor();

                getline(cin, op);
                temp->setIdade(stoi(op));

                getline(cin, op);
                temp->setNome(op);

                getline(cin, op);
                temp->setNumContribuinte(op);

                getline(cin, op);
                temp->setComissao(stof(op));

                getline(cin, op);
                temp->setSalarioBase(stof(op));

                getline(cin, op);
                temp->setValorVendas(stof(op));

                temp->calcularSalario();

                return temp;

            } break;

            default: cout << "Opcao de resgistro nao encontrada.\n";
                break;
    }

    return NULL;

};

void* Logica::consultar(){
    return NULL;
};

void* Logica::pesquisar(void* var){
    return NULL;
};

void Logica::exibeUnico(void* obj){

    Pessoa* temp = (Pessoa*) obj;

    temp->getIdade();
    temp->getNome();
    temp->getNumContribuinte();

};

void Logica::exibeTodos(){

    for(vector<Pessoa*>::iterator it = pessoaLista.begin();
        it != pessoaLista.end(); it++){
            exibeUnico(*it);
    }

}; 

void Logica::altera(void* obj){

};

bool Logica::removeElemento(void* var){
    return NULL;
};
