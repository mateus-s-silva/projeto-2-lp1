#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

struct Endereco
{
    std::string rua;
    int numero;
    std::string bairro;
    std::string cidade;
};

class Pessoa
{

private:
    std::string nome;
    std::string cpf;
    std::string dataNascimento;
    std::string genero;
    Endereco endereco;

public:
    Pessoa(std::string, std::string, std::string, std::string, Endereco);
    ~Pessoa();

    void setNome(std::string);
    void setCpf(std::string);
    void setDataNascimento(std::string);
    void setGenero(std::string);
    void setEndereco(Endereco);

    std::string getNome();
    std::string getCpf();
    std::string getDataNascimento();
    std::string getGenero();
    Endereco getEndereco(); 
};




#endif