#include <iostream>
#include <string>
#include <vector>
#include "../utils/InstanceReader.hpp"
#include "Process.hpp"
#include "FCFS.hpp"



int main(int argc, char** argv){
    InstanceReader reader;
    reader.readInstance(argv[1]);
    std::vector<Process> process = reader.getProcess();
    
    for(Process p: process){
        std::cout << p.arrivalTime << "||" << p.duration << "\n";
    }
    // Init FCFS
    FCFS fcfs(process);
    fcfs.execute();
    std::vector<Process>processResult = fcfs.getProcess();

    double total_aroundTime, total_waitTime = 0;
    int numberProcess = (int)processResult.size();
    for(Process p : processResult){
        total_aroundTime += p.turnAroundTime;
        total_waitTime  += p.waitTime;
    }

    std::cout << "completion_time_avg: " << (double)total_aroundTime/numberProcess << "\n";
    std::cout << "wait time avg: " << (double)total_waitTime/numberProcess << "\n";

    return 0;
}