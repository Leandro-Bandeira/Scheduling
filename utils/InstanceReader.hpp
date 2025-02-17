#ifndef INSTANCE_READER
#define INSTANCE_READER

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../src/Process.hpp"


class InstanceReader{
    public:
        InstanceReader();
        void readInstance(char* filePath);
        std::vector<Process>& getProcess() {return process;};
        
    private:
        std::vector<Process> process;
};




#endif