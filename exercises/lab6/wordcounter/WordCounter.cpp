#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <ostream>
#include <algorithm>
#include <functional>
#include "Word.h"
#include "Counts.h"
#include "WordCounter.h"


using namespace std;

namespace datastructures {

    WordCounter::WordCounter() {
    }

    WordCounter::WordCounter(const initializer_list<Word> &elements) {
        Word w;
        for (w : elements) {
            bool flag = false;
            for (std::vector<std::pair<Word, Counts>>::iterator it = _words.begin(); it != _words.end(); ++it) {
                if (w == it->first) {
                    it->second++;
                    flag = true;
                }
            }
            if (!flag) {
                _words.push_back(pair<Word, Counts>(w, 1));
            }

        }
    }
    WordCounter &WordCounter::FromInputStream(std::ifstream &is) {
        static WordCounter myObj;
        if (is) {
            std::string word;
            while (is >> word) {
                    Word w;
                    w.SetWord(word);
                    Counts c;
                    c.SetCounter(1);
                    std::pair<Word, Counts> p = make_pair(w, c);
                    myObj.AddPair(p);
            }

            is.close();
        }
        return myObj;
    }

    int WordCounter::DistinctWords() {
        return _words.size();
    }

    int WordCounter::TotalWords() {
        int totalWords = 0;
        for (vector<std::pair<Word, Counts> >::iterator it = _words.begin(); it != _words.end(); ++it) {
            totalWords += it->second.GetCounter();
        }
        return totalWords;
    }

    set<Word> WordCounter::Words() {
        std::set<Word> wordList;
        for (vector<std::pair<Word, Counts> >::iterator it = _words.begin(); it != _words.end(); ++it) {
            wordList.insert(it->first.GetWord());
        }
        return wordList;
    }
    bool Word::operator<(const Word &other) const {
        return(GetWord()<other.GetWord());
    }

    vector<std::pair<Word, Counts> > WordCounter::GetWords() const {
        return _words;
    }


    void WordCounter::AddPair(std::pair<Word, Counts> w) {

        bool exists = false;
        for (std::vector<std::pair<Word, Counts> >::iterator it = _words.begin(); it != _words.end(); ++it) {
            if (it->first.GetWord().compare(w.first.GetWord())) {
                exists = true;
                it->second++;
            }
        }

        if (!exists)
            _words.push_back(w);
    }


    struct {
        bool operator()(const std::pair<Word, Counts> &left, const std::pair<Word, Counts> &right) {
            return left.second > right.second;
        }
    }sort_pred;

    std::ostream &operator<<(std::ostream &out, WordCounter const &wc) {

        out << "Raport: " << endl;
        vector<std::pair<Word, Counts> > mylist = wc.GetWords();
        std::sort(mylist.begin(), mylist.end(), sort_pred);
        for (vector<std::pair<Word, Counts> >::iterator it = mylist.begin(); it != mylist.end(); ++it) {
            out << it->first.GetWord() << " : " << it->second.GetCounter() << endl;
        }

        return out;
    }
}