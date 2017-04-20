#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

namespace datastructures {
    class Word {
    public:
        Word();

        Word(std::string str);

        std::string GetWord() const;

        void SetWord(std::string word);

        bool operator==(const Word &w) const {
            if (_word == w._word)
                return true;
            else
                return false;
        }

        bool operator<(const Word &other) const ;

    private:
        std::string _word;

    };

}



#endif //JIMP_EXERCISES_WORD_H
