#include <map>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>

// lambda nieczuła na wielkość liter
auto dowolneLitery = [](const std::string& a, const std::string& b) {
	// kod 
};

int main() {
    // zdefiniuj mapę scores jak w zadaniu 2, z kluczami "Adam", "bogdan", "aron", "Zbigniew", "zdzislawa"
    // i dowolnymi wartościami z zakresu -20, oraz użyj komparator dowolneLitery
    // uwaga: ZAINICJALIZUJ scores odpowiednio!

    // aktualizacja istniejącego klucza przez inny wariant liter
    scores["ADAM"] += 3;       

    // usunięcie wszystkich z wynikiem < 10
    std::erase_if(scores, [](const auto& e){ return e.second < 10; });

    // wypisanie mapy
    for (const auto& [name, score] : scores)
        std::cout << name << " => " << score << '\n';
}

