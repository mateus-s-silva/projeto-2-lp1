#ifndef BANCODAO_HPP
#define BANCODAO_HPP

#include <iostream>
#include <vector>
#include "./enums/enums.hpp"
#include "Professor.hpp"
#include "TecnicoADM.hpp"

class BancoDAO
{
private:

    std::vector<Professor> professores;
    std::vector<TecnicoADM> tecnicos;

public:

    void cadastrarProfessor();
    void cadastrarTecnico();
    void listarProfessores();
    void listarTecnicosADM();
    void deletarProfessor(int matricula);
    void deletarTecnicoADM(int matricula);

    void setListaProfessores(std::vector<Professor>);
    void setListaTecnicos(std::vector<TecnicoADM>);

    Professor buscarProfessor(int matricula);
    TecnicoADM buscarTecnicoADM(int matricula);

};




#endif