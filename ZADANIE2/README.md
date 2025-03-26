# Zadanie 2

**Napisz program, który wczyta wskazany plik tekstowy (`input.txt`), umieszczając go w obiekcie `std::string` i wypisze na ekran.**

1. Zrób to najpierw za pomocą `getline()`, przy czym:
   - Po każdym odczycie wstawiaj znak końca linii (np. `'\n'`).
   - Pamiętaj, aby sprawdzić, czy nie doszliśmy do końca pliku zaraz po wywołaniu `getline()` (aby nie doklejać dodatkowych znaków, jeśli nie ma już kolejnej linii).

2. Następnie **zakomentuj** fragment z `getline()` i spróbuj wczytać cały plik do łańcucha znaków, tworząc obiekt `std::string` za pomocą konstruktora, który przyjmuje **dwie** wartości:
   - Pierwszy argument – **iterator** strumienia wejściowego do czytania *nieformatowanego*, czyli `std::istreambuf_iterator<char>(plik)`.
   - Drugi argument – iterator końca tego strumienia, czyli `std::istreambuf_iterator<char>()`.

3. Na koniec **znowu zakomentuj** powyższy sposób i użyj:
   - **formatowanego** czytania, czyli `std::istream_iterator<char>(plik)` oraz `std::istream_iterator<char>()` jako pary początk–koniec do konstruktora `std::string`.  
   - Podobnie jak wyżej, ale tym razem strumień będzie traktował dane jako ciąg „tokenów” – w tym przypadku pojedynczych znaków, bo typem parametru jest `char`.

## Ważna uwaga

Gdy nazwa pliku do czytania to np. `plik`, to wywołanie dwóch iteratorów może wyglądać tak:

```cpp
std::istream_iterator<char>(plik), std::istream_iterator<char>()
