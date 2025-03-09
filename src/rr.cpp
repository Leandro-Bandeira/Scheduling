#include "rr.hpp"
#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <queue>

#define QUANTUM 2

using namespace std;

void RR::execute(){

    sortForArrivalTime();
    queue<int> ready_proc;
    int index = 0;
    double current_time = 0;
    int n = process.size();

    while (index < n or (ready_proc.empty() != 1) ) {
        // Adiciona processos que chegaram ao tempo atual na fila
        while (index < n && process[index].arrivalTime <= current_time) {
            if(process[index].duration_extra > 0)
                ready_proc.push(index);

            index++;
        }
    
        if (ready_proc.empty()) {
            // Se não há processos prontos, avança no tempo
            current_time++;
            continue;
        }
    
        int current_p = ready_proc.front();
        ready_proc.pop();
    
        // Marca o start no momento em que o processo é executado pela primeira vez
        if (process[current_p].start == -1) {   
            // Tempo de resposta só é calculado com a 1ª execução
            process[current_p].start = current_time;  // Marca o tempo de início
        }
    
        // Executa o processo por um tempo limitado pelo quantum
        double time_exec = min(double(QUANTUM), process[current_p].duration_extra);
        current_time = current_time + time_exec;
        process[current_p].duration_extra =  process[current_p].duration_extra - time_exec;
    
        if (process[current_p].duration_extra > 0) {
            ready_proc.push(current_p);
        } else {
            // Isso significa que a tarefa foi terminada
            process[current_p].finish = current_time;
        }      
    }
        
    for(int i = 0; i < process.size(); i++){
        
        process[i].responseTime = process[i].start - process[i].arrivalTime;
        process[i].turnAroundTime = process[i].finish - process[i].arrivalTime;
        process[i].waitTime = process[i].turnAroundTime - process[i].duration;
    }

    printResults();
}
  
void RR::sortForArrivalTime(){
    std::sort(process.begin(), process.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });

}


void RR::printResults(){

    double resume_completion = 0;
    double resume_turnAround = 0;
    double resume_wait = 0;
    for(int i = 0; i <  process.size(); i++){
        
        resume_completion += process[i].responseTime;
        resume_turnAround += process[i].turnAroundTime;
        resume_wait += process[i].waitTime;
    }

    resume_completion = double(resume_completion / process.size()); 
    resume_turnAround = double(resume_turnAround / process.size());
    resume_wait = double(resume_wait / process.size());

    std::cout << "RR: " << resume_turnAround << " " << resume_completion << " " << resume_wait << std::endl;   
    //printar valores médios de tempo de retorno, tempo de resposta e tempo de espera (1 casa decimal)
}