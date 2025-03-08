#ifndef PROCESS_H
#define PROCESS_H


class Process{
    public:
        Process(int arrivalTime, int duration)
            :arrivalTime(arrivalTime), duration(duration) {}
        
        int getArrivalTime() const {return arrivalTime;}
        int getDuration() const {return duration;}
 
        int arrivalTime;
        int startTime; // Tempo que inicia 
        int duration;        //duração do processo na cpu
        int responseTime;    // Tempo de resposta
        int completionTime;
        int turnAroundTime;  // Tempo de retorno
        int waitTime;        // Tempo de espera
    private:
};





#endif 