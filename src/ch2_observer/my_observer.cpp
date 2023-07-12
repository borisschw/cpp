#include<iostream>
#include <vector>
#include <algorithm>

class ObserverInterface{
    public:
    virtual void update() = 0;
};

class Subject{
    public:
        virtual void registerObserver(ObserverInterface* o) = 0;
        virtual void removeObserver(ObserverInterface* o) = 0;
        virtual void notifyObservers() = 0;
};


class DisplayInterface{
    public:
    virtual void display() = 0;
};

class WeatherData: public Subject{
public:

     WeatherData(){

    }
    void registerObserver(ObserverInterface* o) override{

        observers.push_back(o);
    }
    void removeObserver(ObserverInterface* o) override
    {

        auto it = std::find(observers.begin(), observers.end(), o);
        if(it != observers.end()){
            observers.erase(it);
        }
    }

    void notifyObservers() override
    {
        for (ObserverInterface* ob : observers){
            ob->update();
        }
    }

    void measurementsChanged(){
        notifyObservers();
    }

    void setMeasurements(float temperature, float humidity, float pressure) {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }

    float getTemp(){
        return temperature;
    }
    float getHumidity(){
        return humidity;
    }

    float getPressure()
    {
        return pressure;
    }

private:
    std::vector<ObserverInterface*> observers;
    float temperature;
    float humidity;
    float pressure;
};

class CurrentConditionsDisplay : ObserverInterface, DisplayInterface{

    public:
    CurrentConditionsDisplay(WeatherData* weather_data)
    {
        this->weather_data = weather_data;
        weather_data->registerObserver(this);
    }

    void update()
    {

        this->temperature = weather_data->getTemp();
        this->humidity = weather_data->getHumidity();
        display();
    }

    void display()
    {
        std::cout<< "current condition: "<< temperature << " degrees, " << humidity << " pct humidity" << std::endl;
    }

    private:
        float temperature;
        float humidity;
        WeatherData* weather_data;
};

class AvgDisplay : ObserverInterface, DisplayInterface{

    public:
    AvgDisplay(WeatherData* weather_data)
    {
        this->weather_data = weather_data;
        weather_data->registerObserver(this);
    }

    void update()
    {
        this->temperature = weather_data->getTemp();
        this->humidity = weather_data->getHumidity();
        display();
    }

    void display()
    {
        std::cout<< "AvgDisplay: "<< temperature << " degrees, " << humidity << " pct humidity" << std::endl;
    }

    private:
        float temperature;
        float humidity;
        WeatherData* weather_data;
};


class HeatIndex : ObserverInterface, DisplayInterface{

    public:
    HeatIndex(WeatherData* weather_data)
    {
        this->weather_data = weather_data;
        weather_data->registerObserver(this);
    }

    void update()
    {

        this->heatindex = weather_data->getTemp()+2 + weather_data->getHumidity() + 2;
        display();
    }

    void display()
    {
        std::cout<< "Heat index = " << heatindex << std::endl;
    }

    private:
        double heatindex = 0;
        WeatherData* weather_data;
};
int main()
{
    WeatherData* weatherData = new WeatherData();
    CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(weatherData);

    AvgDisplay* average = new AvgDisplay(weatherData);
    HeatIndex* hindex = new HeatIndex(weatherData);

    weatherData->setMeasurements(32.2,50,1.23);
    weatherData->setMeasurements(30.2,60,2.23);
    weatherData->setMeasurements(39.2,70,3.23);


    return 0;
}
