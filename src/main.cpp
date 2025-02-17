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
    
    // Init FCFS
    for(auto value: process){
        std::cout << value.getArrivalTime() << "\n";
    }
    FCFS fcfs(process);
    fcfs.execute();

    return 0;
}