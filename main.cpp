#include <iostream>
#include <limits>
#include "AEROFLOT.h"
#include "AEROFLOTWithCheck.h"

using namespace std;

void menu() {
    cout << "\nМеню:\n";
    cout << "1. Ввод данных о рейсе\n";
    cout << "2. Вывод данных о рейсе\n";
    cout << "3. Изменить данные рейса\n";
    cout << "4. Выход\n";
    cout << "Выберите опцию: ";
}

int main() {

    AEROFLOT* flight = nullptr;
    int choice;

    while (true) {
        menu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {

                string dest, flightNum, aircraft;
                cout << "Введите пункт назначения: ";
                getline(cin, dest);
                cout << "Введите номер рейса: ";
                getline(cin, flightNum);
                cout << "Введите тип самолета: ";
                getline(cin, aircraft);

                if (flight != nullptr) {
                    delete flight;
                }
                flight = new AEROFLOTWithCheck(dest, flightNum, aircraft);
                break;
            }
            case 2: {

                if (flight != nullptr) {
                    try {
                        flight->display();
                    } catch (const exception& e) {
                        cout << "Ошибка: " << e.what() << endl;
                    }
                } else {
                    cout << "Нет информации о рейсе!\n";
                }
                break;
            }
            case 3: {

                if (flight != nullptr) {
                    string dest, flightNum, aircraft;
                    cout << "Введите новый пункт назначения: ";
                    getline(cin, dest);
                    cout << "Введите новый номер рейса: ";
                    getline(cin, flightNum);
                    cout << "Введите новый тип самолета: ";
                    getline(cin, aircraft);

                    flight->setDestination(dest);
                    flight->setFlightNumber(flightNum);
                    flight->setAircraftType(aircraft);
                } else {
                    cout << "Нет информации о рейсе!\n";
                }
                break;
            }
            case 4: {

                if (flight != nullptr) {
                    delete flight;
                }
                cout << "Выход из программы.\n";
                return 0;
            }
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}
