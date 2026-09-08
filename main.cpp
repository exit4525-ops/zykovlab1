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

    cout << "Enter pipe name: ";
    cin >> pipe.name;

    cout << "Enter pipe length (km): ";
    cin >> pipe.length;

    cout << "Enter pipe diameter (mm): ";
    cin >> pipe.diameter;

    cout << "Is pipe under repair? (1 - y/0 - n): ";
    cin >> pipe.repair;

    cout << endl;

    cout << "Pipe name: " << pipe.name << endl;
    cout << "Length: " << pipe.length << " km" << endl;
    cout << "Diameter: " << pipe.diameter << " mm" << endl;
    cout << "Repair: " << pipe.repair << endl;
 
    return 0;
    
}