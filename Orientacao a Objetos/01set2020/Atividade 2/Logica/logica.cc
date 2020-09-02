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

    cout << "[carro | lancha | aviao]";
    string tipo;
    getline(cin, tipo);

    if(tipo == "carro" || tipo == "Carro"){

        Carro* obj = new Carro();

        cout << "Modelo: ";
        getline(cin, tipo);
        obj->setModelo(tipo);

        cout << "Placa: ";
        getline(cin, tipo);
        obj->setPlaca(tipo);

        cout << "Ano: ";
        getline(cin, tipo);
        obj->setAno(stoi(tipo));

        cout << "Comprimento: ";
        getline(cin, tipo);
        obj->setComprimento(stoi(tipo));

        cout << "Numero de portas: ";
        getline(cin, tipo);
        obj->setNumPortas(stoi(tipo));

        cout << "Numero de Lugares: ";
        getline(cin, tipo);
        obj->setNumLugares(stof(tipo));

        return obj;
    }else if(tipo == "aviao" || tipo == "Aviao"){

        Aviao* obj = new Aviao();

        cout << "Modelo: ";
        getline(cin, tipo);
        obj->setModelo(tipo);

        cout << "Numero de Turbinas: ";
        getline(cin, tipo);
        obj->setNumTurbinas(stoi(tipo));

        cout << "Ano: ";
        getline(cin, tipo);
        obj->setAno(stoi(tipo));

        cout << "Comprimento: ";
        getline(cin, tipo);
        obj->setComprimento(stoi(tipo));

        cout << "Numero de portas: ";
        getline(cin, tipo);
        obj->setNumLugares(stoi(tipo));

        cout << "Numero de Lugares: ";
        getline(cin, tipo);
        obj->setNumLugares(stof(tipo));

        return obj;
    }else{
        Lancha* obj = new Lancha();

        cout << "Modelo: ";
        getline(cin, tipo);
        obj->setModelo(tipo);

        cout << "Numero de Turbinas: ";
        getline(cin, tipo);
        obj->setNumMotores(stoi(tipo));

        cout << "Ano: ";
        getline(cin, tipo);
        obj->setAno(stoi(tipo));

        cout << "Comprimento: ";
        getline(cin, tipo);
        obj->setComprimento(stoi(tipo));

        cout << "Numero de portas: ";
        getline(cin, tipo);
        obj->setNumLugares(stoi(tipo));

        cout << "Numero de Lugares: ";
        getline(cin, tipo);
        obj->setNumLugares(stof(tipo));

        return obj;
    }

    return NULL;

}

void Logica::adciona(void* obj) {

    if(obj == NULL){
        return;
    }else if(typeid(obj) == typeid(Aviao*)){

        this->listaAviao.push_back((Aviao*)obj);
    
    }else if(typeid(obj) == typeid(Carro*)){
    
        this->listaCarro.push_back((Carro*) obj);
    
    }else{

        this->listaLancha.push_back((Lancha*) obj);

    }

}

void Logica::exibeTodos() {
    for(vector<Carro*>::iterator Carro = listaCarro.begin();
        Carro != listaCarro.end(); Carro++){
            exibeUnico(*Carro);
    }
    
    for(vector<Lancha*>::iterator Lancha = listaLancha.begin();
        Lancha != listaLancha.end(); Lancha++){
            exibeUnico(*Lancha);
    }

    for(vector<Aviao*>::iterator Aviao = listaAviao.begin();
        Aviao != listaAviao.end(); Aviao++){
            exibeUnico(*Aviao);
    }

}

void* Logica::exibeUnico(void* obj){

    if(typeid(obj) == typeid(Carro*)){

        Carro* temp = (Carro*) obj;

        cout << temp->getModelo() << endl;
        cout << temp->getAno() << endl;
        cout << temp->getComprimento() << endl;
        cout << temp->getModelo() << endl;
        cout << temp->getNumLugares() << endl;
        cout << temp->getNumPortas() << endl;
        cout << temp->getPlaca() << endl;

    }else if (typeid(obj) == typeid(Lancha*)){

        Lancha* temp = (Lancha*) obj;

        cout << temp->getModelo() << endl;
        cout << temp->getAno() << endl;
        cout << temp->getComprimento() << endl;
        cout << temp->getModelo() << endl;
        cout << temp->getNumLugares() << endl;
        cout << temp->getNumMotores() << endl;

    } else{

        Aviao* temp = (Aviao*) obj;

        cout << temp->getModelo() << endl;
        cout << temp->getAno() << endl;
        cout << temp->getComprimento() << endl;
        cout << temp->getModelo() << endl;
        cout << temp->getNumLugares() << endl;
        cout << temp->getNumTurbinas() << endl;
        cout << temp->getPrefixo() << endl;

    }

    return NULL;

}