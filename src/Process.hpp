#ifndef PROCESS_H
#define PROCESS_H


class Process{
    public:
        Process(int arrivalTime, int duration)
            :arrivalTime(arrivalTime), duration(duration), duration_extra(duration) {}
        
        int getArrivalTime() const {return arrivalTime;}
        int getDuration() const {return duration;}
        
        double start = -1;
        double finish;
        double arrivalTime;
        double startTime; // Tempo que inicia 
        double duration;        //duração do processo na cpu
        double duration_extra;   //utilizado no RR
        double responseTime = 0;    // Tempo de resposta
        double completionTime = 0;
        double turnAroundTime = 0;  // Tempo de retorno
        double waitTime = 0;        // Tempo de espera
    private:
};





#endif 