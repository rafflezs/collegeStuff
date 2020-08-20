#include "logica.h"

void Logica::start(){

    int op;

    do{
        op = this->menu();

        switch (op){
        case 1:{

            string temp;

            cin >> temp;

            Aluno* aluno = criaAluno(temp);

            alunos.push_back(aluno);
        }break;
        case 2:{

            string temp;

            cin >> temp;

            Professor* prof = criaProf(temp);

            professores.push_back(prof);
        }break;
        case 3:{

            string temp;
            cin >> temp;

            Aluno* al = buscaAluno(temp);
            altera(al);

        }break;
        case 4:{
            string temp;
            cin >> temp;

            Professor* prof = buscaProf(temp);
            altera(prof);
        }break;
        case 5:{
            string temp;
            cin >> temp;

            Aluno* al = buscaAluno(temp);
        }break;
        case 6:{
            string temp;
            cin >> temp;

            Professor* prof = buscaProf(temp);
        }break;
        default:
            break;
        }

    } while (op != 0);
    

}

int Logica::menu(){

    int op;

    cout << "[1] Cadastro ALUNO" << endl;
    cout << "[2] Cadastro PROFESSOR" << endl;
    cout << "[3] Altera ALUNO" << endl;
    cout << "[4] Altera PROFESSOR" << endl;
    cout << "[5] Exclui ALUNO" << endl;
    cout << "[6] Exclui PROFESSOR" << endl;
    cout << "[7] Exibe ALUNOS por ordem alfabetica" << endl;
    cout << "[8] Exibe PROFESSORES por ordem de remuneração" << endl;

    cout << "Escolha uma opção: ";
    cin >> op;

    return op;
}

Aluno* Logica::criaAluno(string temp){

    Endereco* end = new Endereco();
    end = criaEnd();
    Disciplina* newDisc = new Disciplina();
    newDisc = criaDisc();
    vector<Disciplina*> listDisc;
    listDisc.push_back(newDisc);
    Aluno* aluno = new Aluno(end,listDisc,temp);

    return aluno;
}

Professor* Logica::criaProf(string temp){

    Endereco* end = new Endereco();
    end = criaEnd();
    Professor* newProf = new Professor(end, temp);

    string a;
    cin >> a;
    newProf->setTitulacao(a);

    cin >> a;
    newProf->setSalario(stoi(a));

    return newProf;
}

Endereco* Logica::criaEnd(){

    string temp;

    Endereco* end = new Endereco();

    cin >> temp;
    end->setRua(temp);

    cin >> temp;
    end->setBairro(temp);

    cin >> temp;
    end->setCep(temp);

    cin >> temp;
    end->setNumero(stoi(temp));

    cin >> temp;
    end->setCidade(temp);

    return end;
}

Disciplina* Logica::criaDisc(){

    Disciplina* newDisc = new Disciplina();
    string temp;

    cin >> temp;
    newDisc->setCargaHoraria(stoi(temp));
    cin >> temp;
    newDisc->setNome(temp);
    cin >> temp;
    newDisc->setNota(stoi(temp));

    return newDisc;
}

Aluno* Logica::buscaAluno(string temp){

    for(auto al = alunos.begin(); al != alunos.end(); al++){
        if((*al)->getNome() == temp){
            return (*al);
        }
    }

    return NULL;
}

Professor* Logica::buscaProf(string temp){
    for(auto al = professores.begin(); al != professores.end(); al++){
        if((*al)->getNome() == temp){
            return (*al);
        }
    }

    return NULL;
}

void Logica::altera(Aluno* al){

    string temp;
    cin >> temp;
    al->setNome(temp);
    cin >> temp;
    Endereco* end = criaEnd();
    al->setEndereco(end);

}

void Logica::altera(Professor* prof){
    string temp;
    cin >> temp;
    prof->setNome(temp);
    cin >> temp;
    Endereco* end = criaEnd();
    prof->setEndereco(end);
    cin >> temp;
    prof->setSalario(stoi(temp));
}

void Logica::deleta(Aluno* al){

    delete al;

}

void Logica::deleta(Professor* al){

    delete al;

}

void Logica::printa(int a = 0){

    for(auto it = alunos.begin(); it != alunos.end(); it++){
        (*it)->print();
    }

}

void Logica::printa(int b = 1){

    for(auto it = professores.begin(); it != professores.end(); it++){
        (*it)->print();
    }

}