#include "logica.h"

int Logica::menu(){
    int op;

    cout << "[1] Cadastro ALUNO" << endl;
    cout << "[2] Exclui ALUNO" << endl;
    cout << "[3] Altera PROFESSOR" << endl;
    cout << "[4] Exibe ALUNOS por ordem alfabetica" << endl;

    cout << "Escolha uma opção: ";
    cin >> op;

    return op;
}

Aluno* Logica::criaAluno(){
    Endereco* end = new Endereco();
    Aluno* aluno = new Aluno(end);
}

void Logica::start(){
    int op;

    do{
        op = this->menu();

        switch (op){
        case 1:{
            Aluno* aluno = criaAluno();

            alunos.push_back(aluno);
        }break;
        case 2:{

            string temp;

            cin >> temp;

            exlcuiAluno(buscaAluno(temp));
        }break;
        case 3:{
            string temp;

            cin >> temp;
            alteraAluno(buscaAluno(temp));

        }break;
        case 4:{
            string temp;
            cin >> temp;
        }break;
        default:
            break;
        }

    } while (op != 0);
}

Aluno* Logica::buscaAluno(string temp){
    for(auto it = alunos.begin(); it != alunos.end(); it++){
        if((*it)->getMatricula() == temp){
            return (*it);
        }
    }
}

void Logica::alteraAluno(Aluno* aluno){
    string temp;
    cin >> temp;
    aluno->setCpf(temp);
}

void Logica::exlcuiAluno(Aluno* aluno){
    delete aluno;
}