#include <iostream>
#include <string>
#include <vector>
#include "../utils/InstanceReader.hpp"
#include "Process.hpp"
#include "FCFS.hpp"
#include "sjf.hpp"
#include "rr.hpp"


int main(int argc, char** argv){  
    InstanceReader reader; // Cria um objeto da classe InstanceReader para ler a instância  
    reader.readInstance(argv[1]); // Lê os dados da instância a partir do arquivo passado como argumento  


    std::vector<Process> process = reader.getProcess(); // Obtém a lista de processos lidos  

    //-----------------------------------FCFS---------------------------------------- 
    FCFS fcfs(process);  
    fcfs.execute(); // Executa o algoritmo FCFS  

    //-----------------------------------sjf----------------------------------------
    Sjf obj_sjf(process);
    obj_sjf.execute();

    RR obj_rr(process);
    obj_rr.execute();

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso  
}