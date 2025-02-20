#ifndef PROCESS_H
#define PROCESS_H


class Process{
    public:
        Process(int arrivalTime, int duration)
            :arrivalTime(arrivalTime), duration(duration) {}
        
        int getArrivalTime() const {return arrivalTime;}
        
 
        int arrivalTime; 
        int duration;   
        int completionTime;
        int turnAroundTime; // Tempo de resposta
        int waitTime; // Tempo de espera
    private:
};





#endif 