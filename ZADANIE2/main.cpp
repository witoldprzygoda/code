#include <map>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>   

struct DowolneLitery {
	// operator funkcyjny: argumenty dwa stringi
	// zwraca bool niezależnie od wielkości liter
	
};




int main() {
    // zdefiniuj mape o nazwie scores: string, int
    // oraz używającą do sortowania predykat DowolneLitery 
    // niech mapa ma klucze: "Adam", "bogdan", "aron", "Zbigniew", "zdzislawa"
    // i różne wartości w zakresie 0-20, mniejsze lub większe od 10

    // trafia w istniejący klucz "Adam"
    scores["ADAM"] += 3;   

    // usuwamy graczy z wynikiem < 10
    std::erase_if(scores,
        [](const auto& entry) { return entry.second < 10; });

    for (const auto& [name, score] : scores)
        std::cout << name << " => " << score << '\n';
}

