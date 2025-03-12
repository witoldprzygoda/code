# ZADANIE 1

Napisz program w języku C++, który tworzy obiekt typu `std::string` o nazwie `s1`. Następnie, za pomocą pętli dodaj do tego obiektu 258 razy znak `'a'`. W każdej iteracji wypisz aktualny rozmiar napisu (`size()`) oraz jego pojemność (`capacity()`). Po zakończeniu pętli wykonaj operacje: wyczyść zawartość napisu (`clear()`), wypisz czy napis jest pusty (`empty()`), wykonaj `shrink_to_fit()` i na koniec wykonaj operację `reserve(57)`. Po każdej z tych operacji również wypisz stan obiektu (pojemność lub stan pusty/niepusty).

Przykładowy początek wyjścia:
```
size: 1, capacity: 15
size: 2, capacity: 15
...
empty: true
capacity after shrink_to_fit: 15
capacity after reserve(57): 57
```

