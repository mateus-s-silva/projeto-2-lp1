#include "../headers/TecnicoADM.hpp"

// Construtor
TecnicoADM::TecnicoADM(std::string nome, std::string cpf, std::string dataNascimento, std::string genero,
                       Endereco endereco, std::string matricula, float salario, std::string departamento,
                       int cargaHoraria, std::string dataIngresso, float adicional, std::string funcaoDesempenhada)
    : Funcionario(nome, cpf, dataNascimento, genero, endereco, matricula, salario, departamento, cargaHoraria, dataIngresso),
      adicional(adicional), funcaoDesempenhada(funcaoDesempenhada) {
    // Implementação do construtor
}

// Destrutor
TecnicoADM::~TecnicoADM() {
    // Implementação do destrutor
}

// Métodos de definição (setters)
void TecnicoADM::setAdicional(float novoAdicional) {
    adicional = novoAdicional;
}

void TecnicoADM::setFuncaoDesempenhada(std::string novaFuncaoDesempenhada) {
    funcaoDesempenhada = novaFuncaoDesempenhada;
}

// Métodos de obtenção (getters)
float TecnicoADM::getAdicional() const {
    return adicional;
}

std::string TecnicoADM::getFuncaoDesempenhada() const {
    return funcaoDesempenhada;
}
