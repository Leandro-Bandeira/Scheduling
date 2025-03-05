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
        void Sjf::sortForShortestTime();
        void Sjf::printResults();
        std::vector<Process> process;
        

};



#endif 