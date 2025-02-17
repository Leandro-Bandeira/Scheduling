#include "FCFS.hpp"
#include <iostream>

void FCFS::execute(){
    sortForArrivalTime();
    for(auto value: this->process){
        std::cout << value.getArrivalTime() << "\n";
    }
}
void FCFS::sortForArrivalTime(){
    std::sort(process.begin(), process.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });

}