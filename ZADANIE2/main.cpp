#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <numeric>
#include <random>
#include <format>

class Obserwator {
public:
    explicit Obserwator(const char* s = "nienazwany")
        : nazwa{s ? s : "nienazwany"} {}

    virtual ~Obserwator() = default;
    virtual void update() = 0;
    const char* id() const { return nazwa.c_str(); }

private:
    std::string nazwa;
};

class Manager {
public:
    void dodaj(Obserwator* p);
    void usun(Obserwator* p);
    void powiadom();
    void obserwatorzy() const;

private:
    std::vector<Obserwator*> klient;
};

void Manager::dodaj(Obserwator* p) {
    if (!std::ranges::contains(klient, p)) {
        klient.push_back(p);
    } else {
        std::cout << std::format("Obserwator {} jest juz na liscie\n", p->id());
    }
}

void Manager::usun(Obserwator* p) {
    std::erase(klient, p);
}

void Manager::powiadom() {
    std::ranges::for_each(klient, &Obserwator::update);
}

void Manager::obserwatorzy() const {
    if (klient.empty()) {
        std::cout << "Brak obserwatorow\n";
    } else {
        for (auto* p : klient) {
            std::cout << std::format("Obserwator {}\n", p->id());
        }
    }
}

class Meteo : public Manager {
public:
    double getT() const { return t; }
    void operator()(std::size_t n);

private:
    double losuj(double a, double b);

    double t{0.0};
    std::mt19937 gen{std::random_device{}()};
};

double Meteo::losuj(double a, double b) {
    std::uniform_real_distribution<double> dis{a, b};
    return dis(gen);
}

void Meteo::operator()(std::size_t n) {
    while (n--) {
        t = losuj(5.0, 25.0);
        powiadom();
    }
}

class Monitor : public Obserwator {
public:
    Monitor(const char* s, const Meteo& ref) : Obserwator(s), ref(ref) {}
    void update() override {
        t = ref.getT();
        std::cout << std::format("Obserwator {} - t = {:.1f}\n", id(), t);
    }

private:
    double t{0.0};
    const Meteo& ref;
};

class MonitorSredni : public Obserwator {
public:
    MonitorSredni(const char* s, const Meteo& ref) : Obserwator(s), ref(ref) {}
    void update() override {
        vec.push_back(ref.getT());
        double suma = std::accumulate(vec.begin(), vec.end(), 0.0);
        tsr = suma / static_cast<double>(vec.size());
        std::cout << std::format("Obserwator {} - t srednia = {:.2f}\n", id(), tsr);
    }

private:
    double tsr{0.0};
    std::vector<double> vec;
    const Meteo& ref;
};

int main() {
    Meteo stacja;

    Obserwator* p1 = new Monitor("Monitor 1", stacja);
    Obserwator* p2 = new Monitor("Monitor 2", stacja);
    Obserwator* p3 = new MonitorSredni("Monitor Sredni 1", stacja);
    Obserwator* p4 = new MonitorSredni("Monitor Sredni 2", stacja);

    stacja.obserwatorzy();
    stacja.dodaj(p1);
    stacja.dodaj(p2);
    stacja.dodaj(p3);
    stacja.dodaj(p4);
    stacja.obserwatorzy();

    stacja(2);

    stacja.dodaj(p1);
    stacja.usun(p3);

    stacja(3);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

