#include "SentenceReverser.h"
#include <fstream>

SentenceReverser::SentenceReverser() {
    cout << "Конструктор SentenceReverser (без параметров)" << endl;
}

SentenceReverser::SentenceReverser(const string& filename) {
    cout << "Конструктор SentenceReverser (с параметром)" << endl;
    setFileName(filename);
}

SentenceReverser::SentenceReverser(const SentenceReverser& other) : FileHandler(other) {
    cout << "Конструктор копирования SentenceReverser" << endl;
    this->numSentences = other.numSentences;
    this->sentences = make_unique<string[]>(other.numSentences);
    for (int i = 0; i < numSentences; ++i) {
        this->sentences[i] = other.sentences[i];
    }
}

SentenceReverser::~SentenceReverser() {
    cout << "Деструктор SentenceReverser" << endl;
}

void SentenceReverser::readFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Ошибка при открытии файла: " + filename);
    }

    cout << "Чтение файла: " << filename << endl;
    string line;
    numSentences = 3;
    sentences = make_unique<string[]>(numSentences);

    for (int i = 0; i < numSentences; ++i) {
        if (getline(file, line)) {
            sentences[i] = line;
        } else {
            throw runtime_error("Ошибка: не удалось считать все 3 предложения.");
        }
    }
}

void SentenceReverser::printReversed() const {
    cout << "Предложения в обратном порядке:" << endl;
    for (int i = numSentences - 1; i >= 0; --i) {
        cout << sentences[i] << endl;
    }
}

void SentenceReverser::setSentencesCount(int count) {
    numSentences = count;
}

int SentenceReverser::getSentencesCount() const {
    return numSentences;
}
