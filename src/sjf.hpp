#ifndef SJF_H
#define SJF_H

#include <vector>
#include "Process.hpp"
#include <algorithm>

class Sjf{
    public:
        Sjf(std::vector<Process> &process):process(process) {}
        std::vector<Process>& getProcess(){return this->process;}
        void execute();
        

    private:
        void sortForShortestTime(std::vector<Process*> &v);
        void sortForArrivalTime();
        void printResults();
        std::vector<Process> process;
        

};



#endif 