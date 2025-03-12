// naglowki
  // std::pair
  // std::tuple
  // std::array

int main() {
    // Tablica std::string o nazwie tab
    
    auto [s1, s2, s3] = tab;
    std::cout << "Tablica: " << s1 << " | " << s2 << " | " << s3 << std::endl;

    // Para (std::pair) i rozpakowanie na obiekty p1 i p2

    std::cout << "Para: " << p1 << " | " << p2 << std::endl;

    // Krotka (std::tuple) i rozpakowanie na p1, p2, p3

    std::cout << "Krotka: " << t1 << " | " << t2 << " | " << t3 << std::endl;

    // Tablica (std::array) z trzema elementami std::string i rozpakowanie na a1, a2, a3

    std::cout << "std::array: " << a1 << " | " << a2 << " | " << a3 << std::endl;

    return 0;
}

