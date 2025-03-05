#include "sjf.hpp"
#include <iostream>
#include <iomanip> 

void Sjf::execute(){

    sortForShortestTime();    //ordena o vetor "process" do job mais curto ao mais longo 

    double current_time = process[0].arrivalTime; 
    for(Process p : process){

        p.completionTime = (current_time + p.duration) - p.arrivalTime;
        p.turnAroundTime = current_time - p.arrivalTime;
        p.waitTime = p.turnAroundTime;
    }

    printResults();
}

void Sjf::sortForShortestTime(){
    std::sort(process.begin(), process.end(), [](const Process& a, const Process& b){
        return a.getDuration() < b.getDuration();
    });

}

void Sjf::printResults(){

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

    std::cout << "SJF: " << std::fixed << std::setprecision(1) << resume_completion << " " << resume_turnAround << " " << resume_wait << endl;   
    //printar valores médios de tempo de retorno, tempo de resposta e tempo de espera (1 casa decimal)
}