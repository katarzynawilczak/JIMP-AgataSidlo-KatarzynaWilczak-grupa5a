#include "TextPool.h"

namespace pool{

    TextPool & TextPool::operator=(TextPool &&textpool) {
        if (this == &textpool) {
            return textpool;
        }
        txt_pool.clear();
        std::swap(txt_pool, textpool.txt_pool);
    }

    TextPool::~TextPool() {
        txt_pool.clear();
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        for (auto it : txt_pool) {
            if (it==str) {
                return it;
            }
        }
        std::experimental::string_view ptr=str;
        txt_pool.insert(ptr);
        return ptr;
    }

    size_t TextPool::StoredStringCount() const {
        return txt_pool.size();
    }
}
