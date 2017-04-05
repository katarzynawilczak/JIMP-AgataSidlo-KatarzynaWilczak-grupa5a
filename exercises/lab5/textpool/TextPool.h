#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H


namespace pool {

    class TextPool {
    public:

        TextPool()=default;
        TextPool(const TextPool &textpool) = delete;
        TextPool(TextPool &&textpool)=default;
        TextPool &operator=(const TextPool &textpool)= delete;
        TextPool &operator=(TextPool &&textpool);
        ~TextPool();
        TextPool(const std::initializer_list<std::experimental::string_view> &elements) : txt_pool(elements){}
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:

        std::set<std::experimental::string_view> txt_pool;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
