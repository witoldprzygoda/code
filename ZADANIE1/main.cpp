// nagłówki

class WordList {
    std::list<std::string> words;          // przechowuje wszystkie słowa

public:
    // konstruktor przyjmujący listę inicjalizacyjną łańcuchów
    

    // operator[] - przyjmuje std::string
    

    // przeciążenie operator[] dla const char*
    
    
};


int main() {
    WordList wl{"apple", "banana", "cherry"};

    std::cout << std::boolalpha;
    std::cout << "banana? "   << wl["banana"]   << "\n"; // true
    std::cout << "orange? "   << wl["orange"]   << "\n"; // false
    std::cout << "cherry? "   << wl["cherry"]   << "\n"; // true
}
