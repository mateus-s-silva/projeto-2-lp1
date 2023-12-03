#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <iostream>
#include "./enums/enums.hpp"
#include "Funcionario.hpp"

class Professor: public Funcionario
{
private:
    Nivel nivelProfessor;
    Formacao formacaoProfessor;
    std::string disciplina;
public:
     Professor(std::string nome, std::string cpf, std::string dataNascimento, std::string genero,
              Endereco endereco, std::string matricula, float salario, std::string departamento,
              int cargaHoraria, std::string dataIngresso, Nivel nivel, Formacao formacao,
              std::string disciplina);
    ~Professor();

    void setNivel(Nivel);
    void setFormacao(Formacao);
    void setDisciplina(std::string);

    Nivel getNivel();
    Formacao getFormacao();
    std::string getDisciplina();
};

#endif