#include <iostream>
#include <string>

using namespace std; // убирает std::

struct Pipe // структура трубы
{
    string name; // имя
    double length; // длинна дробная или целая
    int diameter;
    bool repair; //0/1
};

struct CompressorStation
{
    string name;
    int workshopCount;
    int workshopsInOperation;
    int stationClass;

};

int main()
{
    Pipe pipe; // P - тип данных, p - переменная
    CompressorStation station; 
    //pipe
    cout << "Enter pipe name: ";
    cin >> pipe.name;

    cout << "Enter pipe length (km): ";
    cin >> pipe.length;

    cout << "Enter pipe diameter (mm): ";
    cin >> pipe.diameter;

    cout << "Is pipe under repair? (1 - y/0 - n): ";
    cin >> pipe.repair;

    cout << endl;

    //station
    cout << "Enter station name: ";
    cin >> station.name;

    cout << "Enter number of workshops: ";
    cin >> station.workshopCount;

    cout << "Enter number of workshops in operation: ";
    cin >> station.workshopsInOperation;

    cout << "Enter station class: ";
    cin >> station.stationClass;

    //out
    cout << "Pipe name: " << pipe.name << endl;
    cout << "Length: " << pipe.length << " km" << endl;
    cout << "Diameter: " << pipe.diameter << " mm" << endl;
    cout << "Repair: " << pipe.repair << endl;
    
    //y/n
    if (pipe.repair == true)
    {
        cout << "Repair: Yes" << endl;
    }
    else
    {
        cout << "Repair: No" << endl;
    }

    cout << endl;

    //out
    cout << "--- Compressor Station ---" << endl;
    cout << "Name: " << station.name << endl;
    cout << "Workshops: " << station.workshopCount << endl;
    cout << "Workshops in operation: " << station.workshopsInOperation << endl;
    cout << "Station class: " << station.stationClass << endl;
    

    return 0;
    
}