#include "FCFS.hpp"
#include <iostream>
#include <iomanip> 

void FCFS::execute(){
    // Process now is sorted by arrival time
    sortForArrivalTime();
    for (int i = 0; i < process.size(); i++){
        
        if(i == 0){
            process[i].completionTime = process[i].duration + process[i].arrivalTime;
            process[i].startTime = process[i].arrivalTime;
            
        }
        else{
            // Se o instante que o processo i chega for maior do que o tempo de término do anterior
            // Então o instante de término de i será dado por
            if (process[i].arrivalTime > process[i-1].completionTime){
                process[i].completionTime = process[i].arrivalTime + process[i].duration; 
            }else{
                process[i].completionTime = process[i-1].completionTime + process[i].duration;
            }
            process[i].startTime = std::max(process[i].arrivalTime, process[i-1].completionTime);
            
        }
        
        process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
        process[i].waitTime = process[i].turnAroundTime - process[i].duration;
        process[i].responseTime = process[i].startTime - process[i].arrivalTime;
        
    }
    printResults();
}

void FCFS::sortForArrivalTime(){
    std::sort(process.begin(), process.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });

}

void FCFS::printResults(){

    double resume_response = 0;
    double resume_turnAround = 0;
    double resume_wait = 0;
    for(Process p : process){
        
        resume_response += p.responseTime;
        resume_turnAround += p.turnAroundTime;
        resume_wait += p.waitTime;
    }

    resume_response = resume_response / process.size(); 
    resume_turnAround = resume_turnAround / process.size();
    resume_wait = resume_wait / process.size();

    std::cout << "FCFS: " << std::fixed << std::setprecision(1) << resume_turnAround << " " << resume_response << " " << resume_wait << std::endl;   
    //printar valores médios de tempo de retorno, tempo de resposta e tempo de espera (1 casa decimal)
}