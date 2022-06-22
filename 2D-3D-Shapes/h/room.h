#ifndef ROOM_H
#define ROOM_H
#include<iostream>
#include<memory>
#include "dht11.h"
class DHT11;

class Room{
private:
    size_t id;
    double temperature{28};
    double humidity{16};  
   
public:
 std::unique_ptr<DHT11> dht;

    Room(size_t id, double temperature, double humidity);
    double getTemperature() const   { return temperature; };
    double getHumidity() const      { return humidity; };
    void changeTemperatureStdev(double stdev) const;
    void changeHumidityStdev(double stdev) const;
};

#endif