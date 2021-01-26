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
               std::cout << "Opção inválida!";
            break;
        }
    } while (op != 0);
    
}

int Logica::menu() {
    std::cout << "[1] Criar objeto\n" << "[2] Exibir lista de objetos\nSua opção: "; 
    int op;
    std::cin >> op;

    return op;
}

void* Logica::cria() {

    std::cin.ignore();

    std::cout << "[matricial | laser]";
    std::string tipo;
    getline(std::cin, tipo);

    if(tipo == "Matricial" || tipo == "matricial"){

        Matricial* obj = new Matricial();

        std::cout << "Marca: ";
        getline(std::cin, tipo);
        obj->setMarca(tipo);

        std::cout << "Modelo: ";
        getline(std::cin, tipo);
        obj->setModelo(tipo);

        std::cout << "Num Agulhas: ";
        getline(std::cin, tipo);
        obj->setNumAgulhas(std::stoi(tipo));

        std::cout << "É colorida? : [1 | 0]";
        getline(std::cin, tipo);
        obj->setColorida(std::stoi(tipo));

        std::cout << "Imprime vias??????: [1 | 0]";
        getline(std::cin, tipo);
        obj->setImprimeVias(std::stoi(tipo));

        std::cout << "Peso: ";
        getline(std::cin, tipo);
        obj->setPeso(std::stof(tipo));

        return obj;
    }else{

        Laser* obj = new Laser();

        std::cout << "Marca: ";
        getline(std::cin, tipo);
        obj->setMarca(tipo);

        std::cout << "Modelo: ";
        getline(std::cin, tipo);
        obj->setModelo(tipo);

        std::cout << "Capacidade do Toner: ";
        getline(std::cin, tipo);
        obj->setCapacidadeToner(std::stof(tipo));

        std::cout << "É colorida? : [1 | 0]";
        getline(std::cin, tipo);
        obj->setColorida(std::stoi(tipo));

        std::cout << "Imprime frente e verso? : [1 | 0]";
        getline(std::cin, tipo);
        obj->setFrenteVerso(std::stoi(tipo));

        std::cout << "Peso: ";
        getline(std::cin, tipo);
        obj->setPeso(std::stof(tipo));

        return obj;
    }

    return NULL;

}

void Logica::adciona(void* obj) {

    if(obj == NULL){
        return;
    }else if(typeid(obj) == typeid(Matricial*)){
        this->listaMat.push_back((Matricial*)obj);
    }else{
        this->listaLaser.push_back((Laser*) obj);
    }

}

void Logica::exibeTodos() {
    for(std::vector<Matricial*>::iterator mat = listaMat.begin();
        mat != listaMat.end(); mat++){
            exibeUnico(*mat);
    }
    
    for(std::vector<Laser*>::iterator laser = listaLaser.begin();
        laser != listaLaser.end(); laser++){
            exibeUnico(*laser);
    }

}

void* Logica::exibeUnico(void* obj){

    if(typeid(obj) == typeid(Matricial*)){

        Matricial* temp = (Matricial*) obj;

        std::cout << "\nMarca: ";
        std::cout << temp->getMarca();

        std::cout << "\nModelo: ";
        std::cout << temp->getModelo();

        std::cout << "\nPeso: ";
        std::cout << temp->getPeso();

        std::cout << "\nÉ colorida? : ";
        std::cout << temp->isColorida();

        std::cout << "\nImprime vias???????? : ";
        std::cout << temp->doesImprimeVias();

        std::cout << "\nQuantidade de Agulhas: ";
        std::cout << temp->getNumAgulhas();

    }else{

        Laser* temp = (Laser*) obj;
        std::cout << "\nMarca: ";
        std::cout << temp->getMarca();

        std::cout << "\nModelo: ";
        std::cout << temp->getModelo();

        std::cout << "\nPeso: ";
        std::cout << temp->getPeso();

        std::cout << "\nÉ colorida? : ";
        std::cout << temp->isColorida();

        std::cout << "\nImprime frente e verso? : ";
        std::cout << temp->isFrenteVerso();

        std::cout << "\nCapacidade do toner: ";
        std::cout << temp->getCapacidadeToner();
    }    

    return NULL;

}