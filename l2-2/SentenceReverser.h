#ifndef SENTENCE_REVERSER_H
#define SENTENCE_REVERSER_H

#include "FileHandler.h"

class SentenceReverser : public FileHandler {
public:
    SentenceReverser();
    SentenceReverser(const string& filename);
    SentenceReverser(const SentenceReverser& other);
    ~SentenceReverser();

    void readFile(const string& filename) override;
    void printReversed() const override;

    void setSentencesCount(int count);
    int getSentencesCount() const;
};

#endif // SENTENCE_REVERSER_H
