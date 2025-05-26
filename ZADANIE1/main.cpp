#include <iostream>

class TClock {
private:
    TClock() {
        std::cout << "TClock() - konstruktor\n";
    }
    static TClock* cp;

public:
    TClock(const TClock&) = delete;
    TClock& operator=(const TClock&) = delete;

    static TClock* makeObject() {
        if (cp == nullptr) {
            cp = new TClock();
        }
        return cp;
    }

    static void destroy() {
        delete cp;
        cp = nullptr;
    }

    void printAddress() const {
        std::cout << "Adres obiektu TClock: " << this << std::endl;
    }

    ~TClock() {
        std::cout << "~TClock() - destruktor\n";
    }
};

TClock* TClock::cp = nullptr;

int main() {
    TClock* cp1 = TClock::makeObject();
    TClock* cp2 = TClock::makeObject();

    cp1->printAddress();
    cp2->printAddress();

    if (cp1 == cp2)
        std::cout << "To ten sam obiekt (singleton dziala poprawnie).\n";
    else
        std::cout << "Blad: to rozne obiekty!\n";

    // Kasujemy singleton na koncu programu:
    TClock::destroy();

    return 0;
}
