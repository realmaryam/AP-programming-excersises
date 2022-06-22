<center>
<h1>
In The Name Of ALLAH
</h1>
<h2>
Advanced Programming - Homework 2
</h2>
<h2>
Dr.Amir Jahanshahi
</h2>
<h3>
Deadline: Friday, 13 Farvardin - 23:00
</center>

<img src="stuff/m1.jpg" width="300" />

# Introduction
In this homework, you'll be implementing a **super!** smart room in C++. This room has a **DHT11** sensor to measure both temperature and humidity. Let's see.

**Note**: You must not remove any keyword in variables and functions definitions, but you can add some keywords wherever necessary.

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

```c++
class DHT11{
    private:
        double temp_stdev{1};
        double hum_stdev{1};
        Room* proom;

    public:
        DHT11(double temp_stdev, double hum_stdev);
        DHT11(double temp_stdev, double hum_stdev, Room* proom);
        
        double getTemperature() const;
        double getHumidity() const;
};
```

**Question 1**: What would you do for your code to be able to run the next block successfully? Explain and do it!

```c++
const Room r2(2, 35, 50);
r2.changeHumidityStdev(83);
std::pair<double, double> p{r2.dht->getStdevs()};
std::cout<<p.second<<std::endl;  //  Prints 83
```

**Question 2**: Can you call a ```std::unique_ptr``` variable in a function, by value? If yes, explain how, and if no, explain why!

# main File
You must not alter the **main.cpp** file at all. Just write all your codes in the **room** and **dht11** header and cpp files. Good luck!

<img src="stuff/m2.jpg">