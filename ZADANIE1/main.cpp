#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
using namespace std;

class Obserwator {
    public:
        Obserwator(const char* s) : nazwa{s ? s : "nienazwany"} { /* */ }
        virtual ~Obserwator() = default;
        virtual void update() = 0; // metoda czysto wirtualna
        const char* id() const {  return nazwa.c_str(); }
    private:
        string nazwa;
};

class Manager {
    public:
        void dodaj(Obserwator* p);
        void usun(Obserwator* p);
        void powiadom();
        void obserwatorzy() const;
    private:
        list<Obserwator*> klient;
};

void Manager::obserwatorzy() const {
    // zaimplementuj wpisanie wszystkich obserwatorow z listy
    // "Obserwator nazwa1"
    // "Obserwator nazwa2" ... itd.
    // lub "Brak obserwatorów"


}

void Manager::powiadom() {
    // wywołaj update() na każdym elemencie listy

}

void Manager::dodaj(Obserwator* p) {
    // dodaj wskaźnik p na listę jeśli go tam nie ma lub wypisz
    // "Obserwator nazwaN jest juz na liscie";

}

void Manager::usun(Obserwator* p) {
    // usuń obiekt p z listy
    
}

class Meteo : public Manager {
    public:
        double getT() const { return t; }
        void operator()(size_t n);
    private:
        double t {0.};
        double a{5.}, b{25.};
        double losuj(double a = 5., double b = 25.);
        random_device rd;
        mt19937 gen { rd() };
        uniform_real_distribution<> dis { a,b };
};

double Meteo::losuj(double a, double b) {
    return dis(gen);
}

void Meteo::operator()(size_t n) {
    while (n--) {
        t = losuj();
        powiadom();
    }
}

class Monitor : public Obserwator {
    public:
        Monitor(const char* s, const Meteo& r) : Obserwator(s), ref{r} { }
        virtual void update() override final {
            t = ref.getT();
            cout << "Obserwator " << id() << " t = " << t << endl;
        }
    private:
        double t {0.};
        const Meteo& ref;
};

class MonitorSredni : public Obserwator {
    public:
        MonitorSredni(const char* s, const Meteo& r) : Obserwator(s), ref{r} { }
        virtual void update() override final {
            vec.push_back(ref.getT());
            tsr = 0.;
            for (auto d : vec) tsr += d;
            tsr /= vec.size();
            cout << "Obserwator " << id() << " t srednia = " << tsr << endl;
        }
    private:
        double tsr {0.};
        vector<double> vec;
        const Meteo& ref;
};

int main() {
    Meteo stacja;
    Obserwator* p1 = new Monitor("Monitor 1",stacja);
    Obserwator* p2 = new Monitor("Monitor 2",stacja);
    Obserwator* p3 = new MonitorSredni("Monitor 3",stacja);
    Obserwator* p4 = new MonitorSredni("Monitor 4",stacja);
    stacja.obserwatorzy(); // pusta lista
    stacja.dodaj(p1);
    stacja.dodaj(p2);
    stacja.dodaj(p3);
    stacja.dodaj(p4);
    stacja.obserwatorzy(); // lista nazw wszystkich aktywnych obserwatorow
    stacja(2); // dwa losowania, stacja.operator()(2);
    stacja.dodaj(p1); // sprawdzenie, czy p1 jest już na liście
    stacja.usun(p3); // od teraz p3 nie jest już obserwatorem
    stacja(3); 
    delete p1;
    delete p2;
    delete p3;
    delete p4;
}