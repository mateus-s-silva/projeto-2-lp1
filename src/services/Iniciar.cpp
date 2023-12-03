#include <iostream> 
#include <fstream>
#include <vector> 
#include "../../headers/BancoDAO.hpp"


inline std::vector<TecnicoADM> iniciarTecnicos(){
    std::vector<std::string> linhas;
    std::string linha;
    std::vector<TecnicoADM> listaTecnicos;

    std::fstream arquivo;

    arquivo.open("../funcionarios/tecnicos.txt");

    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    while(std::getline(arquivo, linha)){
        linhas.push_back(linha);
    }

    for(size_t i = 0; i < linhas.size(); i += 15){
        Endereco novoEndereco;

        novoEndereco.rua = linhas[i+4];
        novoEndereco.numero = std::stoi(linhas[i+5]);
        novoEndereco.bairro = linhas[i+6];
        novoEndereco.cidade = linhas[i+7];

        
        TecnicoADM novoTecnico(linhas[i], linhas[i+1], linhas[i+2], linhas[i+3], novoEndereco, linhas[i+8], std::stof(linhas[i+9]), linhas[i+10], std::stoi(linhas[i+11]), linhas[i+12], std::stof(linhas[i+13]), linhas[i+14]);

        listaTecnicos.push_back(novoTecnico);
    }

    return listaTecnicos;
}

inline std::vector<Professor> iniciarProfessores(){

    std::vector<std::string> linhas;
    std::string linha;
    std::vector<Professor> listaProfessores;

    std::fstream arquivo; 

    arquivo.open("../funcionarios/professores.txt");

    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    while(std::getline(arquivo, linha)){
        linhas.push_back(linha);
    }

    for(size_t i = 0; i < linhas.size(); i += 16){
        Endereco novoEndereco;

        novoEndereco.rua = linhas[i+4];
        novoEndereco.numero = std::stoi(linhas[i+5]);
        novoEndereco.bairro = linhas[i+6];
        novoEndereco.cidade = linhas[i+7];

        Professor novoProfessor(linhas[i], linhas[i+1], linhas[i+2], linhas[i+3], novoEndereco, linhas[i+8], std::stof(linhas[i+9]), linhas[i+10], std::stoi(linhas[i+11]), linhas[i+12], static_cast<Nivel>(std::stoi(linhas[i+13])), static_cast<Formacao>(std::stoi(linhas[i+14])), linhas[i+15]);

        listaProfessores.push_back(novoProfessor);
    }

    return listaProfessores;
}
