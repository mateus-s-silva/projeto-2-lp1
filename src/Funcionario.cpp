#include "../headers/Funcionario.hpp"

// Construtor
Funcionario::Funcionario(std::string nome, std::string cpf, std::string dataNascimento, std::string genero, Endereco endereco, std::string matricula, float salario, std::string departamento,
int cargaHoraria, std::string dataIngresso)
    : Pessoa(nome, cpf, dataNascimento, genero, endereco), matricula(matricula), salario(salario),
      departamento(departamento), cargaHoraria(cargaHoraria), dataIngresso(dataIngresso) {
    // Implementação do construtor
}

// Destrutor
Funcionario::~Funcionario() {
    // Implementação do destrutor
}

// Métodos de definição (setters)
void Funcionario::setMatricula(std::string novaMatricula) {
    matricula = novaMatricula;
}

void Funcionario::setSalario(float novoSalario) {
    salario = novoSalario;
}

void Funcionario::setDepartamento(std::string novoDepartamento) {
    departamento = novoDepartamento;
}

void Funcionario::setCargaHoraria(int novaCargaHoraria) {
    cargaHoraria = novaCargaHoraria;
}

void Funcionario::setDataIngresso(std::string novaDataIngresso) {
    dataIngresso = novaDataIngresso;
}

// Métodos de obtenção (getters)
std::string Funcionario::getMatricula() const {
    return matricula;
}

float Funcionario::getSalario() const {
    return salario;
}

std::string Funcionario::getDepartamento() const {
    return departamento;
}

int Funcionario::getCargaHoraria() const {
    return cargaHoraria;
}

std::string Funcionario::getDataIngresso() const {
    return dataIngresso;
}
