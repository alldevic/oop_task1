#include <iostream>
#include <cassert>

namespace Trit {
    enum Trit {
        False, Unknown, True
    };

    class TritSet {
    private:
        unsigned int *set_{};
        size_t size_ = 0;
    public:
        TritSet() = default;

        explicit TritSet(size_t size) : size_(size) {
            set_ = new unsigned int[size];
        };

        void shrink() {
        }


        size_t capacity() {
            return this->size_ * 2 / 8 / sizeof(unsigned int);
        }

        Trit operator[](int a) { return Trit::Unknown; };

        TritSet operator!() {

        }

        TritSet operator&(const TritSet rhs) {

        }

        TritSet operator|(const TritSet rhs) {

        }
    };
}

using namespace Trit;

int main() {
    //резерв памяти для хранения 1000 тритов
    TritSet set(1000);
// length of internal array
    size_t allocLength = set.capacity();
    assert(allocLength >= 1000 * 2 / 8 / sizeof(unsigned int));
// 1000*2 - min bits count
// 1000*2 / 8 - min bytes count
// 1000*2 / 8 / sizeof(uint) - min uint[] size

//не выделяет никакой памяти
    set[1000000000] = Unknown;

// false, but no exception or memory allocation
    if (set[2000000000] == True) {}
    assert(allocLength == set.capacity());

//выделение памяти
    set[1000000000] = True;
    assert(allocLength < set.capacity());

//no memory operations
    allocLength = set.capacity();
    set[1000000000] = Unknown;
    set[1000000] = False;
    assert(allocLength == set.capacity());

//освобождение памяти до начального значения или
//до значения необходимого для хранения последнего установленного трита
//в данном случае для трита 1000’000
    set.shrink();
    assert(allocLength > set.capacity());

    TritSet setA(1000);
    TritSet setB(2000);
    TritSet setC = setA & setB;
    assert(setC.capacity() == setB.capacity());

    std::cout << "Hello, World!" << std::endl;
    return 0;
}