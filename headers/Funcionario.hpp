#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "Pessoa.hpp"

class Funcionario: public Pessoa{
private:
    std::string matricula;
    float salario;
    std::string departamento;
    int cargaHoraria;
    std::string dataIngresso;

public:
    Funcionario(std::string, std::string, std::string, std::string, Endereco, std::string, float, std::string, int, std::string);
    ~Funcionario();

    void setMatricula(std::string novaMatricula);
    void setSalario(float novoSalario);
    void setDepartamento(std::string novoDepartamento);
    void setCargaHoraria(int novaCargaHoraria);
    void setDataIngresso(std::string novaDataIngresso);
    
    std::string getMatricula() const;
    float getSalario() const;
    std::string getDepartamento() const;
    int getCargaHoraria() const;
    std::string getDataIngresso() const;
};

#endif // FUNCIONARIO_H
