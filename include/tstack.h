#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <string>

class TStack {
 private:
    S data[Size];
    int s;

 public:
    TStack() : s(0) {}

    S pop() {
        if (s > 0)
            return data[--t];
        else
            throw std::string("empty");
    }

    void push(const S& item) {
        if (s <= Size - 1)
            data[s++] = item;
        else
            throw std::string("full");
    }

    bool isEmpty() {
        return s == 0;
    }

    S get() {
        if (!isEmpty())
            return data[s - 1];
        else
            throw std::string("empty");
    }
};
