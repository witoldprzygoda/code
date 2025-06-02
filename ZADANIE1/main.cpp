#include <ranges>
#include <vector>
#include <iostream>

struct CzyPodzielny {
	// skladowa + konstruktor + operator funkcyjny
};

int main() {
    std::vector<int> data{1,2,3,4,5,6,7,8,9,10};

    // filtrujemy liczby podzielne przez 3
    auto mult3 = data | std::views::filter(CzyPodzielny{3});

    for (int v : mult3) std::cout << v << ' ';   
}

