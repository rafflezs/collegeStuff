#include "logica.h"

void Logica::iniciar() {
    int op;
    do
    {
        switch (op = menu())
        {
        case 1:{
            adciona(cria());
        }break;
        case 2:{
            exibeTodos();
        }break;
        default:
               cout << "Opção inválida!";
            break;
        }
    } while (op != 0);
    
}

int Logica::menu() {
    cout << "[1] Criar objeto\n" << "[2] Exibir lista de objetos\nSua opção: "; 
    int op;
    cin >> op;

    return op;
}

void* Logica::cria() {

    cin.ignore();

    cout << "[Cachorro | Gato | Coelho]";
    string tipo;
    getline(cin, tipo);

    if(tipo == "cachorro" || tipo == "Cachorro"){

        Cachorro* obj = new Cachorro();

        getline(cin, tipo);
        obj->setCor(tipo);

        getline(cin, tipo);
        obj->setFaro(stof(tipo));

        
        getline(cin, tipo);
        obj->setLatido(stoi(tipo));

        getline(cin, tipo);
        obj->setNasc(tipo);

        getline(cin, tipo);
        obj->setPreco(stof(tipo));

        getline(cin, tipo);
        obj->setRaca(tipo);

        return obj;
    }else if(tipo == "Coelho" || tipo == "Coelho"){

        Coelho* obj = new Coelho();

        getline(cin, tipo);
        obj->setCor(tipo);

        getline(cin, tipo);
        obj->setPeloLongo(stoi(tipo));

        
        getline(cin, tipo);
        obj->setCenouras(stoi(tipo));

        getline(cin, tipo);
        obj->setNasc(tipo);

        getline(cin, tipo);
        obj->setPreco(stof(tipo));

        getline(cin, tipo);
        obj->setRaca(tipo);

        return obj;
    }else{
        Gato* obj = new Gato();

        getline(cin, tipo);
        obj->setCor(tipo);

        getline(cin, tipo);
        obj->setAlturaPulo(stof(tipo));

        
        getline(cin, tipo);
        obj->setPeloLongo(stoi(tipo));

        getline(cin, tipo);
        obj->setNasc(tipo);

        getline(cin, tipo);
        obj->setPreco(stof(tipo));

        getline(cin, tipo);
        obj->setRaca(tipo);

        return obj;
    }

    return NULL;

}

void Logica::adciona(void* obj) {

    if(obj == NULL){
        return;
    }else if(typeid(obj) == typeid(Coelho*)){

        this->listaCoelho.push_back((Coelho*)obj);
    
    }else if(typeid(obj) == typeid(Cachorro*)){
    
        this->listaCachorro.push_back((Cachorro*) obj);
    
    }else{

        this->listaGato.push_back((Gato*) obj);

    }

}

void Logica::exibeTodos() {
    for(vector<Cachorro*>::iterator Cachorro = listaCachorro.begin();
        Cachorro != listaCachorro.end(); Cachorro++){
            exibeUnico(*Cachorro);
    }
    
    for(vector<Gato*>::iterator Gato = listaGato.begin();
        Gato != listaGato.end(); Gato++){
            exibeUnico(*Gato);
    }

    for(vector<Coelho*>::iterator Coelho = listaCoelho.begin();
        Coelho != listaCoelho.end(); Coelho++){
            exibeUnico(*Coelho);
    }

}

void* Logica::exibeUnico(void* obj){

    if(typeid(obj) == typeid(Cachorro*)){

        Cachorro* temp = (Cachorro*) obj;

        cout << temp->getCor() << endl;
        cout << temp->getFaro() << endl;
        cout << temp->getLatido() << endl;
        cout << temp->getNasc() << endl;
        cout << temp->getPreco() << endl;
        cout << temp->getRaca() << endl;

    }else if (typeid(obj) == typeid(Gato*)){

        Gato* temp = (Gato*) obj;

        cout << temp->getAlturaPulo() << endl;
        cout << temp->getCor() << endl;
        cout << temp->getNasc() << endl;
        cout << temp->getPreco() << endl;
        cout << temp->getRaca() << endl;
        cout << temp->hasPeloLongo() << endl;

    } else{

        Coelho* temp = (Coelho*) obj;

        cout << temp->getCenouras() << endl;
        cout << temp->getCor() << endl;
        cout << temp->getNasc() << endl;
        cout << temp->getPreco() << endl;
        cout << temp->getRaca() << endl;
        cout << temp->hasPeloLongo() << endl;

    }

    return NULL;

}