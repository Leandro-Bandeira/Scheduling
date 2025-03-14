#include "sjf.hpp"
#include <iostream>
#include <iomanip>  
#include <vector>  
#include <sstream>

using namespace std;

void Sjf::execute(){

    sortForArrivalTime();    //ordena o vetor "process" pra saber quais chegam primeiro

    std::vector <Process*> ready_proc;
    double current_time = process[0].arrivalTime; //começa o tempo qd o primeiro processo chega
    int i = 0;
    while(i < (process.size())){

        if(current_time >= process[i].arrivalTime){   //se o processo já chegou, vamos tratá-lo 

            ready_proc.push_back(&process[i]); 
            int last_index = i;
            for(int j = i+1; j < process.size(); j++){

                if(current_time >= process[j].arrivalTime){
                    ready_proc.push_back(&process[j]);
                    last_index = j;
                }else{
                    break;
                }
            }

            sortForShortestTime(ready_proc);   //ordenando os processos da lista de prontos por tempo de execução
            
            int proc_done = 0;
            for(Process* p : ready_proc){
                (*p).completionTime = (current_time + (*p).duration) - (*p).arrivalTime;
                (*p).turnAroundTime = current_time - (*p).arrivalTime;
                (*p).waitTime = (*p).turnAroundTime;
                current_time += (*p).duration;
                proc_done++;

                if(last_index != (process.size()-1)){
                    if(current_time >= process[last_index+1].arrivalTime){
                        break;
                    }
                }
                
            }
            
            for (auto it = ready_proc.begin(); it != ready_proc.end();) {
                ready_proc.erase(it);  
                proc_done--;
                if(proc_done == 0){
                    break;
                }
            }

            i = last_index+1;

        }else{       //se o processo ainda nao chegou, devemos aumentar o tempo
            current_time++;
        }
    }
    printResults();
}

void Sjf::sortForShortestTime(std::vector<Process*> &vec){
    std::sort(vec.begin(), vec.end(), [](const Process* a, const Process* b){
        return a->getDuration() < b->getDuration();
    });

}

void Sjf::sortForArrivalTime(){
    std::sort(process.begin(), process.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });

}

void Sjf::printResults(){

    //parametros de avaliacao
    double resume_completion = 0;
    double resume_turnAround = 0;
    double resume_wait = 0;
    for(Process p : process){    //fazendo a soma dos parametros de avaliacao
        
        resume_completion += p.completionTime;
        resume_turnAround += p.turnAroundTime;
        resume_wait += p.waitTime;
    }
    
    resume_completion = resume_completion / process.size(); //calculando a media do tempo de retorno
    resume_turnAround = resume_turnAround / process.size(); //media do tempo de resposta
    resume_wait = resume_wait / process.size(); //media do tempo de espera

    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << resume_completion;
    std::string str_completion = ss.str();
    std::stringstream ss2;
    ss2 << std::fixed << std::setprecision(1) << resume_turnAround;
    std::string str_turnaround = ss2.str();
    std::stringstream ss3;
    ss3 << std::fixed << std::setprecision(1) << resume_wait;
    std::string str_wait = ss3.str();
    std::replace(str_completion.begin(), str_completion.end(), '.', ',');
    std::replace(str_turnaround.begin(), str_turnaround.end(), '.', ',');
    std::replace(str_wait.begin(), str_wait.end(), '.', ',');

    std::cout << "SJF: " << std::fixed << std::setprecision(1) << str_completion << " " << str_turnaround << " " << str_wait << endl;   
    //printar valores médios de tempo de retorno, tempo de resposta e tempo de espera (1 casa decimal)
}