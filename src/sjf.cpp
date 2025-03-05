#include "sjf.hpp"
#include <iostream>

void Sjf::execute(){

    
}

void Sjf::sortForShortestTime(){
    std::sort(process.begin(), process.end(), [](const Process& a, const Process& b){
        return a.getDuration() < b.getDuration();
    });

}