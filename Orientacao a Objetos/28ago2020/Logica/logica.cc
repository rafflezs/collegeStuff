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
        switch (op)
        {
        case 1:{
            add(cria());
        }break;
        case 2:{
            
        }break;
        case 3:{
            
        }break;
        case 4:{
            
        }break;
        case 5:{
            
        }break;
        default: cout << "Opcao invalida\n";
            break;
        }
    } while (op != 0);
}

void Logica::add(Funcionario* func){
    this->funcLista.push_back(func);
}

void Logica::add(Empresario* empre){
    this->empreLista.push_back(empre);
}

void* Logica::cria(){
    cout << "É empresario? [S/N]: ";
    char boleano;
    cin >> boleano;

    Endereco* newEnd = criaEndereco();
    vector<Email*> newEmail = criaEmails();
    Telefone* newTele = criaTelefone();

    switch (boleano)
    {
        case ('s'):{
            Empresario* newEmp = new Empresario((*newEnd));
            
            string input;
            cin >> input;
            newEmp->set_nome(input);

            cin >> input;
            newEmp->set_rg(input);

            cin >> input;
            newEmp->setInvestimento(stof(input));

            newEmp->set_endereco((*newEnd));
            newEmp->set_emails(newEmail);
            newEmp->set_telefone(newTele);

            return newEmp;
        }break;

        default:{
            Funcionario* newFun = new Funcionario((*newEnd));
            
            string input;
            cin >> input;
            newFun->set_nome(input);

            cin >> input;
            newFun->set_rg(input);

            cin >> input;
            newFun->set_salario(stof(input));

            newFun->set_endereco((*newEnd));
            newFun->set_emails(newEmail);
            newFun->set_telefone(newTele);

            return newFun;
        } 
    }
    return NULL;
}

Endereco* Logica::criaEndereco(){

    Endereco* newEnd = new Endereco();

    string input;
    cin >> input;
    newEnd->set_cidade(input);
    
    cin >> input;
    newEnd->set_logradouro(input);

    cin >> input;
    newEnd->set_cep(input);
    
    cin >> input;
    newEnd->set_bairro(input);
    
    cin >> input;
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

        switch (bolean)
        {
            case 'n':
                newEmail = NULL;
                break;

            default:{
                string input;
                cin >> input;
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

    string input;
    cin >> input;
    newTele->set_pais(input);

    cin >> input;
    newTele->set_ddd(input);

    cin >> input;
    newTele->set_numero(input);

    return newTele;
}