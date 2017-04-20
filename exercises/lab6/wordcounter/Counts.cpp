#include "Counts.h"


namespace datastructures {
    Counts::Counts() : _counter(0) {

    }
    Counts::Counts(int k) :_counter(k) {

    }

    int Counts::GetCounter() const {
        return _counter;
    }

    void Counts::SetCounter(int l) {
        _counter = l;
    }
}