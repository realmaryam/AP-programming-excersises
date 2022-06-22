#include <limits.h>
#include "room.h"
#include "dht11.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "gtest/gtest.h"
namespace
{

TEST(APHW2Test, Test1)
{
    Room r1(1, 38, 95);
    DHT11 d1(0.1, 0.1, &r1);
    double temp{d1.getTemperature()};
    EXPECT_EQ(true, (temp > 37) && (temp < 39) && (temp!=38));
}

TEST(APHW2Test, Test2)
{
    const Room r2(2, 35, 50);
    r2.changeHumidityStdev(83);
    std::pair<double, double> p{r2.dht->getStdevs()};
    EXPECT_EQ(83, p.second);
}

}
