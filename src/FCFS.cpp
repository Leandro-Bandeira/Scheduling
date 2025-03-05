#include "FCFS.hpp"
#include <iostream>

void FCFS::execute(){
    // Process now is sorted by arrival time
    sortForArrivalTime();
    
    for (int i = 0; i < process.size(); i++){
        
        if(i == 0){
            process[i].completionTime = process[i].duration + process[i].arrivalTime;
    
        }
        else{
            // Se o instante que o processo i chega for maior do que o tempo de término do anterior
            // Então o instante de término de i será dado por
            if (process[i].arrivalTime > process[i-1].completionTime){
                process[i].completionTime = process[i].arrivalTime + process[i].duration; 
            }else{
                process[i].completionTime = process[i-1].completionTime + process[i].duration;
            }
            
        }
        std::cout << i << "Completion time: " << process[i].completionTime << "\n";
        process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
        process[i].waitTime = process[i].turnAroundTime - process[i].duration;
    }
}

void FCFS::sortForArrivalTime(){
    std::sort(process.begin(), process.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });

}