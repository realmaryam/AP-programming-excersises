#include "dht11.h"
#include <iostream>
#include <random>
#include <utility>

DHT11::DHT11(double _temp_stdev, double _hum_stdev)
    : temp_stdev { _temp_stdev }
    , hum_stdev { _hum_stdev }
{}

DHT11::DHT11(double _temp_stdev, double _hum_stdev, Room* _proom)
    : temp_stdev { _temp_stdev }
    , hum_stdev { _hum_stdev }
    , proom { _proom }
{}


DHT11::DHT11()
    : DHT11 { 1, 1 } 
{}

double DHT11::getTemperature() const
{
    std::random_device device;
    std::mt19937 generator (device());
    std::normal_distribution<double> distribution (proom->getTemperature(), temp_stdev);
    return distribution (generator);
}

double DHT11::getHumidity() const
{
    std::random_device device;
    std::mt19937 generator (device());
    std::normal_distribution<double> distribution (proom->getHumidity(), hum_stdev);
    return distribution (generator);
}

void DHT11::changeTemperatureStdev(double stdev)
{
    temp_stdev = stdev;
}

void DHT11::changeHumidityStdev(double stdev)
{
    hum_stdev = stdev;
}

std::pair<double, double> DHT11::getStdevs() const
{
    return std::make_pair (temp_stdev, hum_stdev);
}
