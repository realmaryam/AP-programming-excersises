
<img src="stuff/m1.jpg" width="300" />

# Introduction
In this homework, you'll be implementing a **super!** smart room in C++. This room has a **DHT11** sensor to measure both temperature and humidity. Let's see.


# Room Class
This class represents our room. It has the following member functions and member variables.

```c++
class Room{
private:
    size_t id;
    double temperature{28};
    double humidity{95};  //  Make this as last 2 digits of your student no
    std::unique_ptr<DHT11> dht;

public:
    Room(size_t id, double temperature, double humidity);
    double getTemperature() const;
    double getHumidity() const;
    void changeTemperatureStdev(double stdev);
    void changeHumidityStdev(double stdev);
};
```

Names of variables and functions are clear about their application. You only need to know about the **DHT11** class now.

#  DHT11 Class
This class represents the sensor. It has a pointer to the room to get the temperature and humidity. But, as every sensor has, this sensor has some measurement noise. So it gets measurements as a **Normal** random variable with the specified mean (from the room class) and specified standard deviation. Let's see contents of this class.

# main File
You must not alter the **main.cpp** file at all. Just write all your codes in the **room** and **dht11** header and cpp files. Good luck!
