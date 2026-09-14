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
    cin >> pipe.length;
    while (pipe.length <= 0)
    {
        cout << "length must be greater than 0. Enter ahain: ";
        cin >> pipe.length;
    }

    cout << "Enter pipe diameter (mm): ";
    cin >> pipe.diameter;
    while (pipe.diameter <= 0)
    {
        cout << "Diameter must be greater than 0. Enter again: ";
        cin >> pipe.diameter;
    }

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
    while (station.workshopsInOperation < 0)
    {
        cout << "Number cannot be negative. Enter again: ";
        cin >> station.workshopCount;
    }

    cout << "Enter number of workshops in operation: ";
    cin >> station.workshopsInOperation;
    while (station.workshopsInOperation > station.workshopCount || station.workshopsInOperation < 0)// || - or
    {
        cout << "Too many workshops. Enter again: ";
        cin >> station.workshopsInOperation;
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
    cin >> station.workshopsInOperation;
    while (station.workshopsInOperation > station.workshopCount)
    {
        cout << "Too many workshops. Enter again: ";
        cin >> station.workshopsInOperation;
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
                station = inputSation();
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
                if (loadData(pipe, station) == true);
                {
                    pipeExists = true;
                    stationExists = true;
                }
                2
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