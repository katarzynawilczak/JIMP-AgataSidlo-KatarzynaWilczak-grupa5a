#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures {

    class Counts {
    public:
        Counts();

        Counts(int k);

        int GetCounter() const;

        void SetCounter(int l);

        Counts &operator++() {
            ++_counter;
            return *this;
        }

        Counts operator++(int) {
            Counts copy = (*this);
            ++_counter;
            return copy;
        }

        bool operator==(const Counts &c) const {
            if (GetCounter() == c.GetCounter())
                return true;
            else
                return false;
        }

        bool operator<(const Counts &c) const {
            return GetCounter() < c.GetCounter();
        }

        bool operator>(const Counts &c) const  {
            return GetCounter() > c.GetCounter();
        }
    private:
        int _counter;
    };
}
#endif //JIMP_EXERCISES_COUNTS_H
