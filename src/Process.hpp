#ifndef PROCESS_H
#define PROCESS_H


class Process{
    public:
        Process(int arrivalTime, int duration)
            :arrivalTime(arrivalTime), duration(duration) {}

        int getArrivalTime() const {return arrivalTime;}
    private:

        int arrivalTime; // Tempo de chegada
        int duration;   // Duração
};





#endif 