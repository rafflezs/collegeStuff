#include "logica.h"

int Logica::menu() {
    cout << "[1] Cadastrar\n"
        << "[2] Pesquisar\n"
        << "[3] Exibir\n"
        << "[4] Alterar\n"
        << "[5] Excluir\n"
        << "Sua opcao: ";
    int op;
    cin >> op;
    return op;
}

void Logica::iniciar() {

    int op;
    do
    {
        op = menu();
        system("clear");
        switch (op)
        {
        case 1:{
            
            add(cria());
        
        }break;
        
        case 2:{

            void* obj = pesquisar(consultar());
            if(obj == NULL)
                cout << "Valor não encontrado";
            else exibeUnico(obj);

        }break;
        
        case 3:{
        
            exibeTodos();
        
        }break;
        
        case 4:{
        
            void* obj = pesquisar(consultar());
            if(obj == NULL)
                cout << "Valor não encontrado";
            else altera(obj);
        
        }break;
        
        case 5:{

            if(removeElemento(consultar()))
                cout << "Elemento removido com sucesso.\n";
            else cout << "Elemento não encontrado\n";

        }break;
        
        default: cout << "Opcao invalida\n";
            break;
        }
    } while (op != 0);
}

void Logica::add(void* obj){

    if(typeid(obj) == typeid(Empresario*)){
        this->empreLista.push_back((Empresario*) obj);
    }else{
        this->funcLista.push_back((Funcionario*) obj);
    }
}

void* Logica::cria(){
    cout << "É empresario? [S/N]: ";
    char boleano;
    cin >> boleano;
    cin.ignore();
    Endereco* newEnd = criaEndereco();
    vector<Email*> newEmail = criaEmails();
    Telefone* newTele = criaTelefone();

    cin.ignore();

    switch (boleano)
    {
        case ('s'):{
            Empresario* newEmp = new Empresario((*newEnd));
            
            cout << "Nome completo: ";
            string input;
            getline(cin, input);
            newEmp->set_nome(input);

            cout << "RG: ";
            getline(cin, input);
            newEmp->set_rg(input);

            cout << "Investimento inicial: ";
            getline(cin, input);
            newEmp->setInvestimento(stof(input));

            newEmp->set_endereco((*newEnd));
            newEmp->set_emails(newEmail);
            newEmp->set_telefone(newTele);

            return newEmp;
        }break;

        default:{
            Funcionario* newFun = new Funcionario((*newEnd));
            
            cout << "Nome completo: ";
            string input;
            getline(cin, input);
            newFun->set_nome(input);

            cout << "RG: ";
            getline(cin, input);
            newFun->set_rg(input);

            cout << "Salario base: ";
            getline(cin, input);
            newFun->set_salario(stof(input));

            newFun->set_endereco((*newEnd));
            newFun->set_emails(newEmail);
            newFun->set_telefone(newTele);

            return newFun;
        } 
    }
    return NULL;
}

string Logica::consultar(){
    cout << "Digite o RG para consulta: ";
    cin.ignore();
    string input;
    getline(cin, input);

    return input;
}

void* Logica::pesquisar(const string & RG){

    for(vector <Empresario*>::iterator it = empreLista.begin();
        it != empreLista.end(); it++){
            if((*it)->get_rg().compare(RG) == 0) return (*it);
    }

    for(vector <Funcionario*>::iterator it = funcLista.begin();
        it != funcLista.end(); it++){
            if((*it)->get_rg().compare(RG) == 0) return (*it);
    }

    return NULL;

}

void Logica::exibeUnico(void* obj){

    if(typeid(obj) == typeid(Empresario*)){
        Empresario* tempEmp = (Empresario*)obj;
        Endereco tempEnd = tempEmp->get_endereco();
        cout << tempEmp->get_nome() << "\n"
            << tempEmp->get_rg() << "\n"
            << tempEnd.get_cidade() << "\n"
            << tempEnd.get_cep() << "\n"
            << tempEnd.get_bairro() << "\n"
            << tempEnd.get_logradouro() << "\n"
            << tempEnd.get_numero() << endl;
    }else{
        Funcionario* tempEmp = (Funcionario*)obj;
        Endereco tempEnd = tempEmp->get_endereco();
        cout << tempEmp->get_nome() << "\n"
            << tempEmp->get_rg() << "\n"
            << tempEnd.get_cidade() << "\n"
            << tempEnd.get_cep() << "\n"
            << tempEnd.get_bairro() << "\n"
            << tempEnd.get_logradouro() << "\n"
            << tempEnd.get_numero() << endl;
    }

}

void Logica::exibeTodos(){

    int cont = 1;

    for(vector <Empresario*>::iterator it = empreLista.begin();
        it != empreLista.end(); it++, cont++){
            cout << "Pessoa " << cont << endl;
            exibeUnico(*it);
            cout << endl;
    }

    for(vector <Funcionario*>::iterator it = funcLista.begin();
        it != funcLista.end(); it++, cont++){
            cout << "Pessoa " << cont << endl;
            exibeUnico(*it);
            cout << endl;
    }    

}

void Logica::altera(void* obj){

    if(typeid(obj) == typeid(Empresario*)){
        Empresario* tempEmp = (Empresario*) obj;
        
        string input;
        
        cout << "Nome: ";
        getline(cin, input);
        tempEmp->set_nome(input);

        cout << "RG: ";
        getline(cin, input);
        tempEmp->set_rg(input);

        Endereco* tempEnd = criaEndereco();
        tempEmp->set_endereco(*tempEnd);

        vector<Email*> tempEmail = criaEmails();
        tempEmp->set_emails(tempEmail);

        Telefone* tempTele = criaTelefone();
        tempEmp->set_telefone(tempTele);

        cout << "Investimento Inicial: ";
        getline(cin, input);
        tempEmp->setInvestimento(stof(input));

    }else{
        Funcionario* tempEmp = (Funcionario*) obj;
        
        string input;
        
        cout << "Nome: ";
        getline(cin, input);
        tempEmp->set_nome(input);

        cout << "RG: ";
        getline(cin, input);
        tempEmp->set_rg(input);

        Endereco* tempEnd = criaEndereco();
        tempEmp->set_endereco(*tempEnd);

        vector<Email*> tempEmail = criaEmails();
        tempEmp->set_emails(tempEmail);

        Telefone* tempTele = criaTelefone();
        tempEmp->set_telefone(tempTele);

        cout << "Salario: ";
        getline(cin, input);
        tempEmp->set_salario(stof(input));
    }

}

bool Logica::removeElemento(const string & RG){

    for(vector <Empresario*>::iterator it = empreLista.begin();
        it != empreLista.end(); it++){
            if((*it)->get_rg().compare(RG) == 0){
                empreLista.erase(it);
                return true;
            }
    }

    for(vector <Funcionario*>::iterator it = funcLista.begin();
        it != funcLista.end(); it++){
            if((*it)->get_rg().compare(RG) == 0){
                funcLista.erase(it);
                return true;
            }
    }

    return false;    

}

Endereco* Logica::criaEndereco(){

    Endereco* newEnd = new Endereco();

    string input;
    cout << "Endereco - cidade: ";
    getline(cin, input);
    newEnd->set_cidade(input);
    
    cout << "Endereco - CEP: ";
    getline(cin, input);
    newEnd->set_cep(input);

    cout << "Endereco - Bairro: ";
    getline(cin, input);
    newEnd->set_bairro(input);

    cout << "Endereco - logradouro: ";
    getline(cin, input);
    newEnd->set_logradouro(input);    
    
    cout << "Endereco - Numero: ";
    getline(cin, input);
    newEnd->set_numero(stoi(input));

    return newEnd;
}

vector <Email*> Logica::criaEmails(){

    vector <Email*> emailList;

    char bolean;
    do
    {
        Email* newEmail = new Email();

        cout << "Deseja cadastrar email(s)? [S/N] : ";
        cin >> bolean;
        cin.ignore();

        switch (bolean)
        {
            case 'n':
                newEmail = NULL;
                break;

            default:{
                cout << "Digite o email : ";
                string input;
                getline(cin, input);
                newEmail->set_endereco(input);

                emailList.push_back(newEmail);
            } break;
        }

    } while (bolean == 'S' || bolean == 's');

    return emailList;   

}

Telefone* Logica::criaTelefone(){

    cout << "Possui telefone? [S/N] : ";
    char boleano;
    cin >> boleano;
    
    if(boleano == 'N' || boleano == 'n'){
        return NULL;
    }

    Telefone* newTele = new Telefone();

    cin.ignore();

    string input;
    cout << "Telefone - País: ";
    getline(cin, input);
    newTele->set_pais(input);

    cout << "DDD: ";
    getline(cin, input);
    newTele->set_ddd(input);

    cout << "Numero: ";
    getline(cin, input);
    newTele->set_numero(input);

    return newTele;
}