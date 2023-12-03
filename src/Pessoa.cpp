#include "../headers/Pessoa.hpp"

// Construtor
Pessoa::Pessoa(std::string nome, std::string cpf, std::string dataNascimento, std::string genero, Endereco endereco)
    : nome(nome), cpf(cpf), dataNascimento(dataNascimento), genero(genero), endereco(endereco) {
    // Implementação do construtor
}

// Destrutor
Pessoa::~Pessoa() {
    // Implementação do destrutor
}

// Métodos de definição (setters)
void Pessoa::setNome(std::string novoNome) {
    nome = novoNome;
}

void Pessoa::setCpf(std::string novoCpf) {
    cpf = novoCpf;
}

void Pessoa::setDataNascimento(std::string novaDataNascimento) {
    dataNascimento = novaDataNascimento;
}

void Pessoa::setGenero(std::string novoGenero) {
    genero = novoGenero;
}

void Pessoa::setEndereco(Endereco novoEndereco) {
    endereco = novoEndereco;
}

// Métodos de obtenção (getters)
std::string Pessoa::getNome() {
    return nome;
}

std::string Pessoa::getCpf() {
    return cpf;
}

std::string Pessoa::getDataNascimento() {
    return dataNascimento;
}

std::string Pessoa::getGenero() {
    return genero;
}

Endereco Pessoa::getEndereco() {
    return endereco;
}
