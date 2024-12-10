#include "FileHandler.h"

FileHandler::FileHandler() {
    cout << "Конструктор FileHandler (без параметров)" << endl;
}

FileHandler::~FileHandler() {
    cout << "Деструктор FileHandler" << endl;
}

void FileHandler::setFileName(const string& filename) {
    this->filename = filename;
}

string FileHandler::getFileName() const {
    return filename;
}

const char* InvalidInputException::what() const noexcept {
    return "Ошибка ввода: введено неверное значение!";
}
