#include <string>
#include "Word.h"

namespace datastructures {

    Word::Word() : _word("") {

    }

    Word::Word(std::string str) : _word(str) {

    }

    std::string Word::GetWord() const {
        return _word;
    }

    void Word::SetWord(std::string word) {
        _word = word;
    }


}
