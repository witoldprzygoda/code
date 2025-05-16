#include <iostream>
#include <string>

class TOsoba {
protected:
    std::string imie;
public:
    TOsoba() = default;
    explicit TOsoba(const std::string& n) : imie(n) {}
    virtual void przedstawSie() const {
        std::cout << "Czesc, nazywam sie " << imie << ".\n";
    }
    virtual ~TOsoba() = default;
};

class MozeWykBadania {
public:
    void prowadzBadania() const {
        std::cout << "- Prowadze badania.\n";
    }
};

class MozeNauczac {
public:
    void prowadzWyklad() const {
        std::cout << "- Prowadze wyklad.\n";
    }
};

class MozeBycStudentem {
public:
    void uczSie() const {
        std::cout << "- Ucze sie.\n";
    }
};

// w każdej klasie jak niżej w ramach jej definicji napisz konstruktor!
// oraz umieść metodę opis(), np. dla studenta z napisem:
// void opis() const { std::cout << "[Student]\n"; }  itd.


class TStudent 

class TAsystentBadan 

class TDoktorant 

class TDoktorantNaucz 

class TDoktorantBadacz 



int main() {
    TAsystentBadan as("Adam");
    TStudent st("Piotr");
    TDoktorant dr("Ewa");
    TDoktorantNaucz dn("Dorota");
    TDoktorantBadacz db("Wojciech");

    std::cout << "\n--- TAsystentBadan ---\n";
    as.opis(); as.przedstawSie(); as.prowadzBadania(); as.prowadzWyklad();

    std::cout << "\n--- TStudent ---\n";
    st.opis(); st.przedstawSie(); st.uczSie();

    std::cout << "\n--- TDoktorant ---\n";
    dr.opis(); dr.przedstawSie(); dr.uczSie();

    std::cout << "\n--- TDoktorantNaucz ---\n";
    dn.opis(); dn.przedstawSie(); dn.uczSie(); dn.prowadzWyklad();

    std::cout << "\n--- TDoktorantBadacz ---\n";
    db.opis(); db.przedstawSie(); db.uczSie(); db.prowadzBadania(); db.prowadzWyklad();
}

