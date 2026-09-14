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

Pipe inputPipe()
{
    Pipe pipe;
    cout << "Enter pipe name: ";
    cin >> pipe.name;

    cout << "Enter pipe length (km): ";
    cin >> pipe.length;

    cout << "Enter pipe diameter (mm): ";
    cin >> pipe.diameter;

    cout << "Is pipe under repair? (1-y/0-n): ";
    cin >> pipe.repair;

    return pipe;
}

CompressorStation inputSation()
{
    CompressorStation station;

    cout << "Enter station name: ";
    cin >> station.name;

    cout << "Enter number of workshops: ";
    cin >> station.workshopCount;

    cout << "Enter number of workshops in operation: ";
    cin >> station.workshopsInOperation;

    cout << "Enter station class: ";
    cin >> station.stationClass;
    return station;

}

void printPipe(Pipe pipe)
{
    cout << "--- Pipe ---" << endl;
    cout << "Name: " << pipe.name << endl;
    cout << "Length: " << pipe.length << " km" << endl;
    cout << "Diameter: " << pipe.diameter << " mm" << endl;
    if (pipe.repair == true)
    {
        cout << "Repair: Yes" << endl;
    }
    else
    {
        cout << "Repair: No" << endl;
    }
}

void printCompressorStation(CompressorStation station)
{
    cout << "--- Compressor Station ---" << endl;
    cout << "Name: " << station.name << endl;
    cout << "Workshops: " << station.workshopCount << endl;
    cout << "Workshops in operation: " << station.workshopsInOperation << endl;
    cout << "Station class: " << station.stationClass << endl;
}

int main()
{
    Pipe pipe; // P - тип данных, p - переменная
    CompressorStation station; 

    int command = -1;

    while (command != 0)
    {
        cout << endl; 
        cout << "1. Add pipe" << endl;
        cout << "2. Add compressor station" << endl;
        cout << "3. View all objects" << endl;
        cout << "4. Edit pipe" << endl;
        cout << "5. Edit Compressor station" << endl;
        cout << "6. Save" << endl;
        cout << "7. Load" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter command: ";
        cin >> command;
        
        switch (command)
        {
            case 1:
                cout << "Add pipe" << endl;
                break;

            case 2:
                cout << "Add compressor station" << endl;
                break;
            
            case 3:
                cout << "View all objects" << endl;
                break;
            
            case 4:
                cout << "Edit pipe" << endl;
                break;
            
            case 5:
                cout << "Edit compressor station" << endl;
                break;
            
            case 6:
                cout << "Save" << endl;
                break;

            case 7:
                cout << "Load" << endl;
                break;

            case 0:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Wrong command" << endl;
                break;
        }
    }

    return 0;
}