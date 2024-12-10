#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "SentenceReverser.h"

using namespace std;

void menu() {
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Ввести имя файла и прочитать его\n";
        cout << "2. Показать предложения в обратном порядке\n";
        cout << "3. Выход\n";
        cout << "Выберите опцию (1-3): ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Введите имя файла: ";
            string filename;
            getline(cin, filename);

            try {
                SentenceReverser reverser(filename);
                reverser.readFile(filename);
                cout << "Файл успешно считан!" << endl;
            } catch (const runtime_error& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
        } else if (choice == 2) {
            try {
                string filename;
                cout << "Введите имя файла: ";
                getline(cin, filename);

                SentenceReverser reverser(filename);
                reverser.readFile(filename);
                reverser.printReversed();
            } catch (const runtime_error& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
        } else if (choice == 3) {
            cout << "Выход из программы." << endl;
            break;
        } else {
            try {
                throw InvalidInputException();
            } catch (const InvalidInputException& e) {
                cout << e.what() << endl;
            }
        }
    }
}

int main() {
    try {
        menu();
    } catch (const exception& e) {
        cout << "Необработанное исключение: " << e.what() << endl;
    }

    return 0;
}
