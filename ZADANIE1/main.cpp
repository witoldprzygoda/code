#include <iostream>
#include <string>
#include <chrono>
int main() {
    const size_t largeSize = 1'000'000;
    const int iterations = 50'000;

    std::string largeString(largeSize, 'A');

    // Start czas
    auto start = std::chrono::high_resolution_clock::now();

    std::string testString;

    // napisz pętlę wykonującą liczbę iteracji iterations razy, w pętli dodawaj
    // do obiektu testString obiekt largeString ale kilka razy (to będzie wymuszać
    // powiększenie bufora. Następnie rób clear() i w pierwszym wariancie to wszystko,
    // a w drugim rób shirink_to_fit()  Jakie otrzymujesz wyniki?

    // Stop czas
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Calkowity czas: " << duration.count() << " sekund" << std::endl;
}

