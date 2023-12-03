#include <iostream>
#include <vector>
#include "../../headers/BancoDAO.hpp"

template<typename T>
bool validaMatricula(std::string matricula, T lista){
    for(auto funcionario: lista){
        if(funcionario.getMatricula() == matricula){
            std::cout << "\nMatricula ja existe, digite uma matricula valida." << std::endl;
            return true;
        }
    }
    return false;
}