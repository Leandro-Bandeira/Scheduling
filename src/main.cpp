#include <iostream>
#include <string>
#include <vector>
#include "../utils/InstanceReader.hpp"
#include "Process.hpp"
#include "FCFS.hpp"
#include "sjf.hpp"


int main(int argc, char** argv){  
    InstanceReader reader; // Cria um objeto da classe InstanceReader para ler a instância  
    reader.readInstance(argv[1]); // Lê os dados da instância a partir do arquivo passado como argumento  

    std::vector<Process> process = reader.getProcess(); // Obtém a lista de processos lidos  

    // Itera sobre a lista de processos e imprime o tempo de chegada e duração de cada um  
    for(Process p: process){  
        std::cout << p.arrivalTime << "||" << p.duration << "\n";  
    }  

    // Inicializa o escalonador FCFS (First-Come, First-Served)  
    FCFS fcfs(process);  
    fcfs.execute(); // Executa o algoritmo FCFS  

    std::vector<Process> processResult = fcfs.getProcess(); // Obtém os processos após execução  

    double total_aroundTime, total_waitTime = 0; // Variáveis para armazenar o tempo médio de retorno e espera  
    int numberProcess = (int)processResult.size(); // Obtém o número total de processos  

    // Calcula o tempo total de retorno e tempo total de espera  
    for(Process p : processResult){  
        total_aroundTime += p.turnAroundTime; // Soma o tempo de retorno  
        total_waitTime  += p.waitTime; // Soma o tempo de espera  
    }  

    // Imprime os tempos médios de conclusão e espera  
    std::cout << "completion_time_avg: " << (double)total_aroundTime/numberProcess << "\n";  
    std::cout << "wait time avg: " << (double)total_waitTime/numberProcess << "\n"; 
    
    //-----------------------------------sjf----------------------------------------
    Sjf obj_sjf(process);
    obj_sjf.execute();

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso  
}