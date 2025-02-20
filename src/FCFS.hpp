#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include "Process.hpp"
#include <algorithm>

class FCFS{
    public:
        FCFS(std::vector<Process> &process)
            :process(process) {}
        
        void sortForArrivalTime();
        void execute();
        std::vector<Process>& getProcess(){return this->process;}


    private:
        std::vector<Process> process;
        

};



#endif 