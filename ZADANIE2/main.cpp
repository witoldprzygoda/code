// nagłówki

// struktura z przeciążonym operatorem() przyjmującym char i zwracającym int

int main() {
    std::vector<char> input{'A', 'b', '1', '\n'};
    std::vector<int>  output(input.size());

    // użyj std::transform (od, do, dokąd, obiekt funkcyjny)


    for (int v : output) std::cout << v << ' '; // 65 98 49 10
    std::cout << '\n';
}
