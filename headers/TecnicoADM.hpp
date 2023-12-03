#ifndef TECNICOADM_HPP
#define TECNICOADM_HPP

#include <iostream>
#include "Funcionario.hpp"

class TecnicoADM : public Funcionario
{
private:
    float adicional = 0.25;
    std::string funcaoDesempenhada;

public:
    TecnicoADM(std::string, std::string, std::string, std::string, Endereco, std::string, float, std::string, int, std::string, float, std::string);
    ~TecnicoADM();

    void setAdicional(float);
    void setFuncaoDesempenhada(std::string);

    float getAdicional() const;
    std::string getFuncaoDesempenhada() const;
};
#endif