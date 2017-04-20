#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <vector>
#include <utility>
#include <ostream>
#include <set>
#include <initializer_list>
#include "Word.h"
#include "Counts.h"


using ::std::initializer_list;


namespace datastructures {

    class WordCounter {
    public:
        WordCounter();

        WordCounter(const initializer_list<Word> &elements);

        static WordCounter &FromInputStream(std::ifstream &is);

        int DistinctWords();

        int TotalWords();

        std::set<Word> Words();


        void AddPair(std::pair<Word, Counts> w);

        std::vector<std::pair<Word, Counts> > GetWords() const;

        int operator[](const std::string &key) {

            int value = 0;

            for (std::vector<std::pair<Word, Counts> >::iterator it = _words.begin(); it != _words.end(); ++it) {
                if (!key.compare(it->first.GetWord())) {
                    value = it->second.GetCounter();
                    break;
                }
            }
            return value;
        }

        friend std::ostream &operator<<(std::ostream &out, WordCounter const &wc);

    private:
        std::vector<std::pair<Word, Counts> > _words;
    };

}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
