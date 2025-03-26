# ZADANIE 3

Napisz program, w którym przetestujesz, **jak szybko losowane są liczby** za pomocą:
- `std::random_device`
- `std::mt19937_64`

W tym celu należy zmierzyć czas (początek i koniec) interesującego fragmentu programu (podobnie jak w zadaniu nr 1. z zestawu Lab #3, w którym był przykładowy kod pomiaru czasu).

Załóżmy, że wykonamy pętlę z określoną liczbą powtórzeń operacji losowania, np.:

    const size_t num_iterations = 10'000'000;

W **pierwszej** pętli wywołuj:

    [[maybe_unused]] volatile int n = rd();

gdzie wcześniej zdefiniowano:

    std::random_device rd;

Atrybut `[[maybe_unused]]` i słowo kluczowe `volatile` zapobiegają ostrzeżeniom kompilatora i optymalizacjom, które mogłyby usunąć nieużywane zmienne.

W **drugiej** pętli wywołuj:

    [[maybe_unused]] volatile int n = dist(gen);

gdzie wcześniej zdefiniowano:

    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dist(rd.min(), rd.max());

Bardzo ciekawe będzie **porównanie**, gdy kompilujemy **bez** opcji `-O3` oraz **z** opcją `-O3`.
Obserwuj różnicę w czasach wykonania dla `std::random_device` i `std::mt19937_64` przy różnych ustawieniach kompilacji.
