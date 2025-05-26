#include <iostream>

// Klasa bazowa z szablonowa metoda "prepareDrink"
class Drink {
public:
    // Metoda szablonowa
    void prepareDrink() {
        boilWater();
        brew();
        pourInCup();
        addIngredients();
    }

    // Krok wspolny dla wszystkich napojow
    void boilWater() {
        std::cout << "Boiling water\n";
    }

    // Krok wspolny
    void pourInCup() {
        std::cout << "Pouring into cup\n";
    }

    // Kroki abstrakcyjne (wirtualne)
    virtual void brew() = 0;
    virtual void addIngredients() = 0;

    virtual ~Drink() = default;
};

// Konkretna klasa - Herbata
class Tea : public Drink {
public:
// kod

};

// Konkretna klasa - Kawa
class Coffee : public Drink {
public:
// kod
    
};

int main() {
    Drink* drink;

    std::cout << "Making tea:\n";
    drink = new Tea();
    drink->prepareDrink();
    delete drink;

    std::cout << "\nMaking coffee:\n";
    drink = new Coffee();
    drink->prepareDrink();
    delete drink;

    return 0;
}
