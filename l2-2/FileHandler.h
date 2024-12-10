#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;


class FileHandler {
public:
    FileHandler();
    virtual ~FileHandler();

    virtual void readFile(const string& filename) = 0;
    virtual void printReversed() const = 0;

    void setFileName(const string& filename);
    string getFileName() const;

protected:
    string filename;
    unique_ptr<string[]> sentences;
    int numSentences = 0;
};


class InvalidInputException : public exception {
public:
    const char* what() const noexcept override;
};

#endif // FILE_HANDLER_H
