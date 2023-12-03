#include "../headers/BancoDAO.hpp"
#include "./services/Validador.cpp"
#include <fstream>
#include <algorithm>
#include "./services/Carregar.cpp"

void BancoDAO::cadastrarProfessor(){
    std::string nome, cpf, dataNascimento, genero, matricula, departamento, dataIngresso, disciplina;
    Endereco endereco;
    Nivel nivel;
    Formacao formacao;
    float salario;
    int cargaHoraria;
    int escolha;

    std::cout << "*---------------------------------------*" << std::endl;
    std::cout << "Nome: " << std::endl;
    std::cin >> nome;

    std::cout << "CPF: " << std::endl;
    std::cin >> cpf;

    std::cout << "Data de Nascimento: " << std::endl;
    std::cin >> dataNascimento;

    std::cout << "Genero: " << std::endl;
    std::cin >> genero;

    do{
        std::cout << "Matricula: " << std::endl;
        std::cin.ignore();
        std::cin >> matricula;
    }while(validaMatricula(matricula, this->professores));

    std::cout << "Nivel(I(1), II(2), III(3), IV(4), V(5), VI(6), VII(7), VIII(8)): " << std::endl;
    std::cin >> escolha;
    nivel = static_cast<Nivel>(escolha);


    std::cout << "Formacao(ESPECIALIZACAO(1), MESTRADO(2), DOUTORADO(3)): " << std::endl;
    std::cin >> escolha;
    formacao = static_cast<Formacao>(escolha);

    std::cout << "Departamento: " << std::endl; 
    std::cin >> departamento;

    std::cout << "dataIngresso: " << std::endl;
    std::cin >> dataIngresso;

    std:: cout << "Disciplina: " << std::endl;
    std::cin >> disciplina;

    std:: cout << "Rua: " << std::endl;
    std::cin >> endereco.rua;
    
    std:: cout << "Numero da casa: " << std::endl;
    std::cin >> endereco.numero;

    std::cout << "Bairro: " << std::endl;
    std::cin >> endereco.bairro;

    std::cout << "Cidade: " << std::endl;
    std::cin >> endereco.cidade;

    std::cout << "Salario: " << std::endl;
    std::cin >> salario;

    std::cout << "Carga Horaria: " << std::endl;
    std::cin >> cargaHoraria;

    Professor novoProfessor(nome, cpf, dataNascimento, genero, endereco, matricula, salario,
                             departamento, cargaHoraria, dataIngresso, nivel, formacao, disciplina);
    
    this->professores.push_back(novoProfessor);

    carregarProfessor(novoProfessor);
}

void BancoDAO::cadastrarTecnico(){
    std::string nome, cpf, dataNascimento, genero, matricula, departamento, dataIngresso, funcaoDesempenhada;
    Endereco endereco;
    float salario, adicional;
    int cargaHoraria;

    std::cout << "*---------------------------------------*" << std::endl;
    std::cout << "Nome: " << std::endl;
    std::cin >> nome;

    std::cout << "CPF: " << std::endl;
    std::cin >> cpf;

    std::cout << "Data de Nascimento: " << std::endl;
    std::cin >> dataNascimento;

    std::cout << "Genero: " << std::endl;
    std::cin >> genero;

    do{
        std::cout << "Matricula: " << std::endl;
        std::cin >> matricula;
    }while(validaMatricula(matricula, this->tecnicos));

    std::cout << "Departamento: " << std::endl; 
    std::cin >> departamento;

    std::cout << "dataIngresso: " << std::endl;
    std::cin >> dataIngresso;

    std:: cout << "Rua: " << std::endl;
    std::cin >> endereco.rua;
    
    std:: cout << "Numero da casa: " << std::endl;
    std::cin >> endereco.numero;

    std::cout << "Bairro: " << std::endl;
    std::cin >> endereco.bairro;

    std::cout << "Cidade: " << std::endl;
    std::cin >> endereco.cidade;

    std::cout << "Salario: " << std::endl;
    std::cin >> salario;

    std::cout << "Carga Horaria: " << std::endl;
    std::cin >> cargaHoraria;

    std::cout << "Adicional: " << std::endl;
    std::cin >> adicional;

    std::cout << "Funcao desempenhada: " << std::endl;
    std::cin >> funcaoDesempenhada;

    TecnicoADM novoTecnicoADM(nome, cpf, dataNascimento, genero, endereco, matricula, salario, departamento, cargaHoraria, dataIngresso, adicional, funcaoDesempenhada);

    this->tecnicos.push_back(novoTecnicoADM);

    carregarTecnico(novoTecnicoADM);
}

void BancoDAO::listarProfessores(){

    std::cout << "*---------------------------------------*" << std::endl;

    std::cout << "Lista de professores:" << std::endl;

    for(Professor professor: this->professores){
        std::cout << "Nome: " << professor.getNome()
        << " /--/ " << "Disciplina: " << professor.getDisciplina() 
        << " /--/ Matricula: " << professor.getMatricula()
        << std::endl;
    }

    std::cout << "*---------------------------------------*" << std::endl;
}

void BancoDAO::listarTecnicosADM(){

    std::cout << "*---------------------------------------*" << std::endl;

    std::cout << "Lista de tecnicos:" << std::endl;

    for(TecnicoADM tecnico: this->tecnicos){
        std::cout << "Nome: " << tecnico.getNome()
        << " /--/ " << "Funcao: " << tecnico.getFuncaoDesempenhada() 
        << " /--/ " << "Matricula: " << tecnico.getMatricula()
        << std::endl;
    }

    std::cout << "*---------------------------------------*" << std::endl;
}

void BancoDAO::deletarProfessor(int matricula){
    auto it = std::find_if(this->professores.begin(), this->professores.end(),
                           [matricula](const Professor& professor) {
                               return professor.getMatricula() == std::to_string(matricula);
                           });

    if (it != this->professores.end()) {
        this->professores.erase(it);  // Chama erase diretamente no vector
    }

    std::fstream arquivo("../funcionarios/professores.txt", std::ios::out | std::ios::trunc);

    if(!arquivo.is_open()){
        std::cout << "Nao ta abrindo papai" << std::endl;
    }

    auto professor = this->professores.begin();

    while(professor != this->professores.end()){
        arquivo << professor->getNome() << '\n';
        arquivo << professor->getCpf() << '\n';
        arquivo << professor->getDataNascimento() << '\n';

        arquivo << professor->getGenero() << '\n';

        arquivo << professor->getEndereco().rua << '\n';
        arquivo << professor->getEndereco().numero << '\n';
        arquivo << professor->getEndereco().bairro << '\n';
        arquivo << professor->getEndereco().cidade << '\n'; 
        arquivo << professor->getMatricula() << '\n';
        arquivo << professor->getSalario() << '\n';
        arquivo << professor->getDepartamento() << '\n';
        arquivo << professor->getCargaHoraria() << '\n';
        arquivo << professor->getDataIngresso() << '\n';

        // Convertendo o enum para int antes de salvar
        arquivo << static_cast<int>(professor->getNivel()) << '\n';
        arquivo << static_cast<int>(professor->getFormacao()) << '\n';  
        arquivo << professor->getDisciplina() << '\n';

        professor++;
    }

    arquivo.close();
    std::cout << "\nItem excluido com sucesso." << std::endl;
}

void BancoDAO::deletarTecnicoADM(int matricula){
    auto it = std::find_if(this->tecnicos.begin(), this->tecnicos.end(),
                           [matricula](const TecnicoADM& tecnico) {
                               return tecnico.getMatricula() == std::to_string(matricula);
                           });

    if (it != this->tecnicos.end()) {
        this->tecnicos.erase(it);  // Chama erase diretamente no vector
    }


    std::fstream arquivo("../funcionarios/tecnicos.txt", std::ios::out | std::ios::trunc);

    if(!arquivo.is_open()){
        std::cout << "Nao ta abrindo papai" << std::endl;
    }

    auto tecnico = this->tecnicos.begin();

    while(tecnico != this->tecnicos.end()){
        arquivo << tecnico->getNome() << '\n';
        arquivo << tecnico->getCpf() << '\n';
        arquivo << tecnico->getDataNascimento() << '\n';

        arquivo << tecnico->getGenero() << '\n';

        arquivo << tecnico->getEndereco().rua << '\n';
        arquivo << tecnico->getEndereco().numero << '\n';
        arquivo << tecnico->getEndereco().bairro << '\n';
        arquivo << tecnico->getEndereco().cidade << '\n'; 
        arquivo << tecnico->getMatricula() << '\n';
        arquivo << tecnico->getSalario() << '\n';
        arquivo << tecnico->getDepartamento() << '\n';
        arquivo << tecnico->getCargaHoraria() << '\n';
        arquivo << tecnico->getDataIngresso() << '\n';

        arquivo << tecnico->getAdicional() << '\n';
        arquivo << tecnico->getFuncaoDesempenhada() << '\n';

        tecnico++;
    }

    arquivo.close();
    std::cout << "\nItem excluido com sucesso." << std::endl;
}

void BancoDAO::setListaProfessores(std::vector<Professor> professores){
    this->professores = professores;
}

void BancoDAO::setListaTecnicos(std::vector<TecnicoADM> tecnicos){
    this->tecnicos = tecnicos;
}

Professor BancoDAO::buscarProfessor(int matricula){
    for(Professor professor: this->professores){
        if(std::stoi(professor.getMatricula()) == matricula){
            std::cout << '\n' 
            << "Professor(a): "
            << professor.getNome() 
            << " - Disciplina: "
            << professor.getDisciplina()
            << std::endl;
            return professor;
        }
    }
    throw std::runtime_error("Professor nao encontrado.");
}

TecnicoADM BancoDAO::buscarTecnicoADM(int matricula){
    for(TecnicoADM tecnico: this->tecnicos){
        if(std::stoi(tecnico.getMatricula()) == matricula){
            std::cout << '\n'
            << "Tecnico(a): "
            << tecnico.getNome() 
            << " - Funcao: "
            << tecnico.getFuncaoDesempenhada()
            << std::endl;
            return tecnico;
        }
    }
    throw std::runtime_error("Tecnico nao encontrado");
}
