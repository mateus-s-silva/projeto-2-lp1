#include "../headers/Professor.hpp"

// Construtor
Professor::Professor(std::string nome, std::string cpf, std::string dataNascimento, std::string genero,
                     Endereco endereco, std::string matricula, float salario, std::string departamento,
                     int cargaHoraria, std::string dataIngresso, Nivel nivel, Formacao formacao,
                     std::string disciplina)
    : Funcionario(nome, cpf, dataNascimento, genero, endereco, matricula, salario, departamento,
                  cargaHoraria, dataIngresso),
      nivelProfessor(nivel), formacaoProfessor(formacao), disciplina(disciplina) {
    // Implementação do construtor da classe Professor
}

// Destrutor
Professor::~Professor() {
    // Implementação do destrutor
}

// Métodos de definição (setters)
void Professor::setNivel(Nivel novoNivel) {
    nivelProfessor = novoNivel;
}

void Professor::setFormacao(Formacao novaFormacao) {
    formacaoProfessor = novaFormacao;
}

void Professor::setDisciplina(std::string novaDisciplina) {
    disciplina = novaDisciplina;
}

// Métodos de obtenção (getters)
Nivel Professor::getNivel() {
    return nivelProfessor;
}

Formacao Professor::getFormacao() {
    return formacaoProfessor;
}

std::string Professor::getDisciplina() {
    return disciplina;
}
