#include <iostream>
#include <limits>
#include <windows.h>
#include "AEROFLOT.h"
#include "AEROFLOTWithCheck.h"

using namespace std;

class InvalidInputException : public exception {
public:
    InvalidInputException(const string& message) : msg(message) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    string msg;
};

class MemoryAllocationException : public exception {
public:
    MemoryAllocationException(const string& message) : msg(message) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    string msg;
};

void menu() {
    cout << "\nМеню:\n";
    cout << "1. Добавить новый рейс\n";
    cout << "2. Вывести данные всех рейсов\n";
    cout << "3. Вывести данные рейсов по типу самолета\n";
    cout << "4. Изменить данные рейса\n";
    cout << "5. Удалить рейс\n";
    cout << "6. Заменить рейс номер рейсом номер\n";  // Новый пункт
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
        flights[i]->display();  // Используем метод display() для вывода информации о рейсе
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

// Функция для удаления рейса по номеру
void removeFlightByNumber(AEROFLOT**& flights, int& numFlights, const string& flightNum) {
    bool found = false;
    for (int i = 0; i < numFlights; ++i) {
        if (flights[i]->getFlightNumber() == flightNum) {
            // Удаляем рейс, сдвигая все остальные рейсы влево
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

// Новый пункт: заменяем рейс с одним номером на рейс с другим номером
void replaceFlightByNumber(AEROFLOT** flights, int numFlights, const string& oldFlightNum, const string& newFlightNum) {
    AEROFLOT* oldFlight = nullptr;
    AEROFLOT* newFlight = nullptr;

    // Поиск старого и нового рейса
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

    // Заменяем старый рейс на новый
    oldFlight->setDestination(newFlight->getDestination());
    oldFlight->setAircraftType(newFlight->getAircraftType());

    cout << "Рейс с номером " << oldFlightNum << " был заменен рейсом с номером " << newFlightNum << ".\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для правильной работы с кириллицей
    SetConsoleCP(CP_UTF8);

    AEROFLOT** flights = new AEROFLOT*[10];  // Массив для хранения рейсов
    int numFlights = 0;
    int capacity = 10;

    while (true) {
        try {
            menu();
            int choice;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice < 1 || choice > 7) {
                throw InvalidInputException("Неверный выбор в меню.");
            }

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
                    try {
                        cout << "Введите пункт назначения: ";
                        getline(cin, dest);
                        if (dest.empty()) {
                            throw InvalidInputException("Пункт назначения не может быть пустым.");
                        }

                        cout << "Введите номер рейса: ";
                        getline(cin, flightNum);
                        if (flightNum.empty()) {
                            throw InvalidInputException("Номер рейса не может быть пустым.");
                        }

                        cout << "Введите тип самолета: ";
                        getline(cin, aircraft);
                        if (aircraft.empty()) {
                            throw InvalidInputException("Тип самолета не может быть пустым.");
                        }

                        flights[numFlights] = new AEROFLOTWithCheck(dest, flightNum, aircraft);
                        numFlights++;

                        cout << "Рейс успешно добавлен!\n";
                    }
                    catch (const InvalidInputException& e) {
                        cout << e.what() << endl;
                    }
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
                case 6: {  // Новый пункт
                    string oldFlightNum, newFlightNum;
                    cout << "Введите номер рейса для замены: ";
                    getline(cin, oldFlightNum);
                    cout << "Введите номер рейса, который заменит старый: ";
                    getline(cin, newFlightNum);

                    replaceFlightByNumber(flights, numFlights, oldFlightNum, newFlightNum);
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
            }
        }
        catch (const InvalidInputException& e) {
            cout << e.what() << endl;
        }
        catch (const MemoryAllocationException& e) {
            cout << "Ошибка выделения памяти: " << e.what() << endl;
        }
    }
}
