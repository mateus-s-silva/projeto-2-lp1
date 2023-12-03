# Projeto 2 - Linguagem de programação 1
## Estrutura
### Headers
Na pasta ./headers estão todas as assinaturas de todas as funções e classes utilizadas. 

&nbsp;
Estão separadas por classes:
* BancoDAO.hpp: possui a assinatura da classe BancoDAO junto com todas as assinaturas de seus métodos
* Funcionario.hpp: possui a assinatura da classe Funcionario junto com todas as assinaturas de seus métodos
* Pessoa.hpp: possui a assinatura da classe Pessoa junto com todas as assinaturas de seus métodos
* Professor.hpp: possui a assinatura da classe Professor junto com todas as assinaturas de seus métodos
* TecnicoADM.hpp: possui a assinatura da classe TecnicoADM junto com todas as assinaturas de seus métodos

Na pasta ./header/enum, está o arquivo enums.hpp, com as definições dos enums Nivel e Formacao.

## Funcionarios
Na pasta ./funcionarios possui os arquivos de texto a serem persistidos.

### Source 
Na pasta ./src encontramos todas as implementações de nossas funções declaradas no ./headers.

&nbsp;

Também possui a pasta ./src/services que possui:

* Carregar.cpp: responsável por persistir os novos objetos Professor e TecnicoADM cadastrados nos arquivos funcionarios.txt e tecnicos.txt
* Iniciar.cpp: responsável por, ao executar o programa, salvar todos os os professores e tecnicos que estão salvos nos arquivos funcionarios.txt e tecnicos.txt nos membros da classe BancoDAO(vector<Professor> professores e vector<TecnicoADM> tecnicos)
* Validador.cpp: um simples algoritmo responsável por verificar se ao cadastrar um novo objeto (professor ou tecnico) se a matrícula informada já existe. Ele não permitirá que o objeto seja salvo enquanto não for digitado uma matrícula válida


## Como executar
Para compilar, navegue até a pasta ./src e execute o seguinte comando no terminal: 
~~~shell
g++ main.cpp Pessoa.cpp Professor.cpp TecnicoADM.cpp Funcionario.cpp BancoDAO.cpp ./services/Carregar.cpp ./services/Iniciar.cpp ./services/Validador.cpp -o exec -Wall -Wextra -pedantic
~~~

Em seguide, execute o seguinte comando:
~~~shell
./exec
~~~ 

Se você tiver windows, provavelmente  terá que executar: 
~~~shell
exec.exe
~~~
ou 
~~~shell
./exec.exe
~~~