#include <iostream>
#include <string>
#include <fstream> //чтение/запись в вайл

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
    
    while (!(cin >> pipe.length) || pipe.length <= 0)
    {
        cout << "Wrong value. Enter length again: ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter pipe diameter (mm): ";
    
    while (!(cin >> pipe.diameter) || pipe.diameter <= 0)
    {
        cout << "Wrong value. Enter diameter again: ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Is pipe under repair? (1-y/0-n): ";
    cin >> pipe.repair;

    return pipe;
}

CompressorStation inputStation()
{
    CompressorStation station;

    cout << "Enter station name: ";
    cin >> station.name;

    cout << "Enter number of workshops: ";
    
    while (!(cin >> station.workshopCount) || station.workshopCount < 0)
    {
        cout << "Wrong value. Enter number of workshops again: ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter number of workshops in operation: ";
    
    while (!(cin >> station.workshopsInOperation) || 
            station.workshopsInOperation < 0 ||
            station.workshopsInOperation > station.workshopCount)
    {
        cout << "Wrong value. Enter number of workshops in operation again: ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

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

void editPipe(Pipe &pipe) // & - изменяет оригинал, а не создает копию
{
    if (pipe.repair == true)
    {
        pipe.repair = false;
    }
    else 
    {
        pipe.repair = true;
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

void editStation(CompressorStation &station)
{
    cout << "Enter number of workshops in operation: ";

    while (!(cin >> station.workshopsInOperation) ||
        station.workshopsInOperation < 0 ||
        station.workshopsInOperation > station.workshopCount)
    {
        cout << "Wrong value. Enter number again: ";

        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void saveData(Pipe pipe, CompressorStation station)
{
    ofstream file("data.txt");//открыть файл для записи

    file << pipe.name << endl;
    file << pipe.length << endl;
    file << pipe.diameter << endl;
    file << pipe.repair << endl;

    file << station.name << endl;
    file << station.workshopCount << endl;
    file << station.workshopsInOperation << endl;
    file << station.stationClass << endl;

    file.close();

    cout << "Data saved" << endl;
}

bool loadData(Pipe &pipe, CompressorStation &station)
{
    ifstream file("data.txt"); //чтение из файла

    if (!file)//наличие файла
    {
        cout << "File not found" << endl;
        return false;
    }

    file >> pipe.name;
    file >> pipe.length;
    file >> pipe.diameter;
    file >> pipe.repair;

    file >> station.name;
    file >> station.workshopCount;
    file >> station.workshopsInOperation;
    file >> station.stationClass;

    file.close();

    cout << "Data loaded" << endl;
    return true;
}

int main()
{
    Pipe pipe; // P - тип данных, p - переменная
    CompressorStation station; 
    bool pipeExists = false;
    bool stationExists = false;

    int command = -1;

    while (command != 0)
    {
        cout << endl; 
        cout << "1. Add pipe" << endl;
        cout << "2. Add compressor station" << endl;
        cout << "3. View all objects" << endl;
        cout << "4. Edit pipe status" << endl;
        cout << "5. Edit Compressor station" << endl;
        cout << "6. Save" << endl;
        cout << "7. Load" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter command: ";
        cin >> command;
        
        switch (command)
        {
            case 1:
                pipe = inputPipe();
                pipeExists = true;
                break;

            case 2:
                station = inputStation();
                stationExists = true;
                break;
            
            case 3:
                if (pipeExists == true)
                {
                    printPipe(pipe);
                }
                else
                {
                    cout << "Pipe not added" << endl;
                }

                cout << endl;

                if (stationExists == true)
                {
                    printCompressorStation(station);
                }
                else
                {
                    cout << "Station not added" << endl;
                }
                break;
            
            case 4:
                if (pipeExists == true)
                {
                    editPipe(pipe);
                    cout << "Pipe repair status changed" << endl;
                }
                else
                {
                    cout << "Pipe not added" << endl;
                }
                break;
            
            case 5:
                if (stationExists == true)
                {
                    editStation(station);
                }
                else
                {
                    cout << "Station not added" << endl;
                }
                break;
            
            case 6:
                if (pipeExists == true && stationExists == true)
                {
                    saveData(pipe, station);
                }
                else
                {
                    cout << "Add pipe & station first" << endl;
                }
                break;

            case 7:
                if (loadData(pipe, station) == true)
                {
                    pipeExists = true;
                    stationExists = true;
                }
                
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