#include "rr.hpp"
#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <queue>

#define QUANTUM 2

using namespace std;

void RR::execute(){

    queue<Process*> ready_proc;
    int current_time = 0;
    int index = 0;

    while (index < process.size() or !ready_proc.empty()) {
        // Adiciona processos que chegaram ao tempo atual na fila
        while (index < process.size() && process[index].arrivalTime <= current_time) {
            ready_proc.push(&process[index]);
            index++;
        }

        if (!ready_proc.empty()) {
            Process* current_p = ready_proc.front();
            ready_proc.pop();

            if((*current_p).duration_extra == (*current_p).duration){   //tempo de resposta só é calculado com a 1 execucao
                (*current_p).turnAroundTime = current_time - (*current_p).arrivalTime;
            }

            // Executa o processo por um tempo limitado pelo quantum
            int time_exec = min(QUANTUM, (*current_p).duration_extra);
            current_time += time_exec;
            (*current_p).duration_extra -= time_exec;

            if ((*current_p).duration_extra > 0) {
                ready_proc.push(current_p);
            }else{
                 //isso significa que a tarefa foi terminada
                (*current_p).completionTime = (current_time + (*current_p).duration) - (*current_p).arrivalTime;
                (*current_p).waitTime = (*current_p).completionTime - (*current_p).duration;
            
            }
        } else {
            current_time++;
        }
    }

    printResults();
}


void RR::printResults(){

    double resume_completion = 0;
    double resume_turnAround = 0;
    double resume_wait = 0;
    for(Process p : process){
        
        resume_completion += p.completionTime;
        resume_turnAround += p.turnAroundTime;
        resume_wait += p.waitTime;
    }

    resume_completion = resume_completion / process.size(); 
    resume_turnAround = resume_turnAround / process.size();
    resume_wait = resume_wait / process.size();

    std::cout << "RR: " << std::fixed << std::setprecision(1) << resume_completion << " " << resume_turnAround << " " << resume_wait << std::endl;   
    //printar valores médios de tempo de retorno, tempo de resposta e tempo de espera (1 casa decimal)
}