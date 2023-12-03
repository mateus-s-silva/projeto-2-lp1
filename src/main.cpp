#include <iostream>
#include "../headers/BancoDAO.hpp"
#include "./services/Iniciar.cpp"
#include "./services/Carregar.cpp"
#include "./services/Validador.cpp"

int main() {

    BancoDAO banco;

    banco.setListaProfessores(iniciarProfessores());
    banco.setListaTecnicos(iniciarTecnicos());

    int opcao;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Cadastrar Professor\n";
        std::cout << "2. Cadastrar Técnico ADM\n";
        std::cout << "3. Listar Professores\n";
        std::cout << "4. Listar Técnicos ADM\n";
        std::cout << "5. Deletar Professor\n";
        std::cout << "6. Deletar Técnico ADM\n";
        std::cout << "7. Buscar Professor\n";
        std::cout << "8. Buscar Técnico ADM\n";
        std::cout << "0. Sair\n";

        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {

            case 1:
                banco.cadastrarProfessor();
                break;

            case 2:
                banco.cadastrarTecnico();
                break;

            case 3:
                banco.listarProfessores();
                break;

            case 4:
                banco.listarTecnicosADM();
                break;

            case 5:
                int matriculaDeletarProfessor;
                std::cout << "Digite a matrícula do Professor a ser deletado: ";
                std::cin >> matriculaDeletarProfessor;
                banco.deletarProfessor(matriculaDeletarProfessor);
                break;

            case 6:
                int matriculaDeletarTecnico;
                std::cout << "Digite a matrícula do Técnico ADM a ser deletado: ";
                std::cin >> matriculaDeletarTecnico;
                banco.deletarTecnicoADM(matriculaDeletarTecnico);
                break;

            case 7:
                int matriculaBuscarProfessor;
                std::cout << "Digite a matrícula do Professor a ser buscado: ";
                std::cin.ignore();
                std::cin >> matriculaBuscarProfessor;
                banco.buscarProfessor(matriculaBuscarProfessor);
                break;

            case 8:
                int matriculaBuscarTecnico;
                std::cout << "Digite a matrícula do Técnico ADM a ser buscado: ";
                std::cin.ignore();
                std::cin >> matriculaBuscarTecnico;
                banco.buscarTecnicoADM(matriculaBuscarTecnico);
                break;

            case 0:
                std::cout << "Saindo do programa.\n";
                break;

            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
