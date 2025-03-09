#ifndef RR_H
#define RR_H

#include <vector>
#include "Process.hpp"
#include <algorithm>

class RR{
    public:
        RR(std::vector<Process> &process):process(process) {}
        std::vector<Process>& getProcess(){return this->process;}
        void execute();
        

    private:
        void sortForArrivalTime();
        void printResults();
        std::vector<Process> process;
        

};



#endif 