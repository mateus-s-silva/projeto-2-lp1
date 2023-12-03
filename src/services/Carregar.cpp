#include <iostream>
#include <fstream>
#include "../../headers/Professor.hpp"
#include "../../headers/TecnicoADM.hpp"


inline void carregarProfessor(Professor professor){
    std::fstream arquivo;

    arquivo.open("../funcionarios/professores.txt", std::ios::app);

    if(!arquivo.is_open()){
        std::cout << "Nao ta abrindo papai" << std::endl;
    }

    //bool vazio = arquivo.peek() == std::ifstream::traits_type::eof();

    // if(!vazio){
    //     arquivo << '\n';
    // }
    

    arquivo << professor.getNome() << '\n';
    arquivo << professor.getCpf() << '\n';
    arquivo << professor.getDataNascimento() << '\n';

    arquivo << professor.getGenero() << '\n';

    arquivo << professor.getEndereco().rua << '\n';
    arquivo << professor.getEndereco().numero << '\n';
    arquivo << professor.getEndereco().bairro << '\n';
    arquivo << professor.getEndereco().cidade << '\n'; 
    arquivo << professor.getMatricula() << '\n';
    arquivo << professor.getSalario() << '\n';
    arquivo << professor.getDepartamento() << '\n';
    arquivo << professor.getCargaHoraria() << '\n';
    arquivo << professor.getDataIngresso() << '\n';

    // Convertendo o enum para int antes de salvar
    arquivo << static_cast<int>(professor.getNivel()) << '\n';
    arquivo << static_cast<int>(professor.getFormacao()) << '\n';  
    arquivo << professor.getDisciplina() << '\n';

    arquivo.close();
}

inline void carregarTecnico(TecnicoADM tecnico){
    std::fstream arquivo;

    arquivo.open("../funcionarios/tecnicos.txt", std::ios::app);

    if(!arquivo.is_open()){
        std::cout << "Nao ta abrindo papai" << std::endl;
    }

    //bool vazio = arquivo.peek() == std::ifstream::traits_type::eof();
    
    // if(!vazio){
        // arquivo << '\n';
    // }

    if (arquivo << tecnico.getNome() << '\n') {
    std::cout << "Nome gravado com sucesso." << std::endl;
} else {
    std::cout << "Erro ao gravar o nome." << std::endl;
}
    arquivo << tecnico.getCpf() << '\n';
    arquivo << tecnico.getDataNascimento() << '\n';

    arquivo << tecnico.getGenero() << '\n';

    arquivo << tecnico.getEndereco().rua << '\n';
    arquivo << tecnico.getEndereco().numero << '\n';
    arquivo << tecnico.getEndereco().bairro << '\n';
    arquivo << tecnico.getEndereco().cidade << '\n'; 
    arquivo << tecnico.getMatricula() << '\n';
    arquivo << tecnico.getSalario() << '\n';
    arquivo << tecnico.getDepartamento() << '\n';
    arquivo << tecnico.getCargaHoraria() << '\n';
    arquivo << tecnico.getDataIngresso() << '\n';
    
    arquivo << tecnico.getAdicional() << '\n';
    arquivo << tecnico.getFuncaoDesempenhada();

    arquivo.flush();
    arquivo.close();
}
