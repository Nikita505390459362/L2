#include <iostream>
#include <limits>
#include <windows.h>
#include "AEROFLOT.h"
#include "AEROFLOTWithCheck.h"

using namespace std;

void menu() {
    cout << "\nМеню:\n";
    cout << "1. Добавить новый рейс\n";
    cout << "2. Вывести данные всех рейсов\n";
    cout << "3. Вывести данные рейсов по типу самолета\n";
    cout << "4. Изменить данные рейса\n";
    cout << "5. Удалить рейс\n";
    cout << "6. Заменить рейс номер рейсом номер\n";
    cout << "7. Выход\n";
    cout << "Выберите опцию: ";
}

void displayAllFlights(AEROFLOT** flights, int numFlights) {
    if (numFlights == 0) {
        cout << "Нет доступных рейсов.\n";
        return;
    }

    cout << "\nВсе рейсы:\n";
    for (int i = 0; i < numFlights; ++i) {
        flights[i]->display();
    }
}

void displayFlightsByAircraftType(AEROFLOT** flights, int numFlights, const string& aircraftType) {
    bool found = false;
    for (int i = 0; i < numFlights; ++i) {
        if (flights[i]->getAircraftType() == aircraftType) {
            cout << "Рейс: " << flights[i]->getFlightNumber() << ", Пункт назначения: " << flights[i]->getDestination()
                 << ", Тип самолета: " << flights[i]->getAircraftType() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Нет рейсов с таким типом самолета.\n";
    }
}


void removeFlightByNumber(AEROFLOT**& flights, int& numFlights, const string& flightNum) {
    bool found = false;
    for (int i = 0; i < numFlights; ++i) {
        if (flights[i]->getFlightNumber() == flightNum) {
            delete flights[i];
            for (int j = i; j < numFlights - 1; ++j) {
                flights[j] = flights[j + 1];
            }
            numFlights--;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Рейс с номером " << flightNum << " не найден.\n";
    }
}

void replaceFlightByNumber(AEROFLOT** flights, int numFlights, const string& oldFlightNum, const string& newFlightNum) {
    AEROFLOT* oldFlight = nullptr;
    AEROFLOT* newFlight = nullptr;

    for (int i = 0; i < numFlights; ++i) {
        if (flights[i]->getFlightNumber() == oldFlightNum) {
            oldFlight = flights[i];
        }
        if (flights[i]->getFlightNumber() == newFlightNum) {
            newFlight = flights[i];
        }
    }

    if (!oldFlight) {
        cout << "Рейс с номером " << oldFlightNum << " не найден.\n";
        return;
    }

    if (!newFlight) {
        cout << "Рейс с номером " << newFlightNum << " не найден.\n";
        return;
    }

    oldFlight->setDestination(newFlight->getDestination());
    oldFlight->setAircraftType(newFlight->getAircraftType());

    cout << "Рейс с номером " << oldFlightNum << " был заменен рейсом с номером " << newFlightNum << ".\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    AEROFLOT** flights = new AEROFLOT*[10];
    int numFlights = 0;
    int capacity = 10;

    while (true) {
        menu();
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                if (numFlights == capacity) {
                    capacity *= 2;
                    AEROFLOT** newFlights = new AEROFLOT*[capacity];
                    for (int i = 0; i < numFlights; ++i) {
                        newFlights[i] = flights[i];
                    }
                    delete[] flights;
                    flights = newFlights;
                }

                string dest, flightNum, aircraft;
                cout << "Введите пункт назначения: ";
                getline(cin, dest);
                cout << "Введите номер рейса: ";
                getline(cin, flightNum);
                cout << "Введите тип самолета: ";
                getline(cin, aircraft);

                flights[numFlights] = new AEROFLOTWithCheck(dest, flightNum, aircraft);
                numFlights++;

                cout << "Рейс успешно добавлен!\n";
                break;
            }
            case 2: {
                displayAllFlights(flights, numFlights);
                break;
            }
            case 3: {
                string aircraftType;
                cout << "Введите тип самолета для вывода рейсов: ";
                getline(cin, aircraftType);

                displayFlightsByAircraftType(flights, numFlights, aircraftType);
                break;
            }
            case 4: {
                string flightNum;
                cout << "Введите номер рейса для изменения: ";
                getline(cin, flightNum);

                bool found = false;
                for (int i = 0; i < numFlights; ++i) {
                    if (flights[i]->getFlightNumber() == flightNum) {
                        string newDest, newAircraft;
                        cout << "Введите новый пункт назначения: ";
                        getline(cin, newDest);
                        cout << "Введите новый тип самолета: ";
                        getline(cin, newAircraft);

                        flights[i]->setDestination(newDest);
                        flights[i]->setAircraftType(newAircraft);

                        cout << "Данные рейса изменены!\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Рейс с таким номером не найден.\n";
                }
                break;
            }
            case 5: {
                string flightNum;
                cout << "Введите номер рейса для удаления: ";
                getline(cin, flightNum);

                removeFlightByNumber(flights, numFlights, flightNum);
                break;
            }
            case 6: {
                string oldFlightNum, newFlightNum;
                cout << "Введите номер рейса для замены: ";
                getline(cin, oldFlightNum);
                cout << "Введите номер рейса, который заменит старый: ";
                getline(cin, newFlightNum);

                replaceFlightByNumber(flights, numFlights, oldFlightNum, newFlightNum);
                removeFlightByNumber(flights, numFlights, newFlightNum);
                break;
            }
            case 7: {
                for (int i = 0; i < numFlights; ++i) {
                    delete flights[i];
                }
                delete[] flights;
                cout << "Выход из программы.\n";
                return 0;
            }
            default: {
                cout << "Неверный выбор. Попробуйте еще раз.\n";
                break;
            }
        }
    }
}
