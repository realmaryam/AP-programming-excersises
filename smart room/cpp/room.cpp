#include "room.h"
#include <iostream>

Room::Room(size_t _id, double _temperature, double _humidity)
{
    id = _id;
    temperature = _temperature;
    humidity = _humidity;
    dht = std::make_unique<DHT11> (1,1,this);

}

void Room::changeTemperatureStdev(double stdev) const
{
    dht->changeTemperatureStdev(stdev);
}

void Room::changeHumidityStdev(double stdev) const
{
    dht->changeHumidityStdev(stdev);
}

