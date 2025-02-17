#include "InstanceReader.hpp"

InstanceReader::InstanceReader(){}


void InstanceReader::readInstance(char *file_path){
    std::ifstream file(file_path);
    std::string line;
    if(!file){
        std::cout << "Erro ao abrir o arquivo\n";
        std::exit(-1);
    }

    while(std::getline(file, line)){
        std::istringstream ss(line);
        int arrivalTime, duration;

        ss >> arrivalTime >> duration;
        Process p1(arrivalTime, duration);
        process.push_back(p1);
    }
    
}

