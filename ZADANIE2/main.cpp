#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Dokument {
    public:
        virtual void czytaj() { } // zwykla metoda wirtualna
        virtual void drukuj() = 0; // metoda czysto wirtualna
        virtual ~Dokument() = default;
};

class Dok : public Dokument {
    public:
        virtual void drukuj() override final {
            cout << buf << endl;
        }
    protected:
        string buf;
};

class DokStd : public Dok {
    public:
        virtual void czytaj() override final {
            getline(cin, buf);
        }
};

class DokPlik : public Dok {
    public:
        // napisz finalną wersję czytaj() która
        // otworzy plik test.txt i wczyta do buf całą jego zawartość


};

class Dekorator : public Dokument {
    public:
        Dekorator(Dokument *p) : ptr{p} { }
        ~Dekorator() { delete ptr; }
        virtual void drukuj() override {
            ptr->drukuj();
        }
    private:
        Dokument *ptr {nullptr};
};

class Naglowek : public Dekorator {
    public:
        Naglowek(Dokument* p) : Dekorator(p), nr{++licznik} { }
        void drukuj() override final;
    private:
        void drukujNaglowek();
        static unsigned licznik; // deklaracja skladowej statycznej
        const unsigned nr; // musi byc inicjalizowany w konstruktorze
};

unsigned Naglowek::licznik { 0 }; // definicja skladowej statycznej klasy

void Naglowek::drukujNaglowek() {
    cout << string(12,'.') << " N A G L O W E K " << nr << " " << string(12,'.') << endl;
}

void Naglowek::drukuj() {
    drukujNaglowek();
    Dekorator::drukuj();
}

// napisz klasę Stopka - analogiczną wersję jak Naglowek 
// pamiętając o właściwej kolejności wywołania w metodzie drukuj()



int main() {
    //Dokument *p = new DokStd;
    Dokument *p = new DokPlik;
    p->czytaj();
    p->drukuj();
    cout << string(80,'-') << endl;
    p = new Stopka(new Naglowek(new Stopka(p)));
    p = new Stopka(new Stopka(new Stopka(new Naglowek(p))));
    p = new Stopka(new Stopka(new Stopka(new Naglowek(p))));
    p = new Stopka(new Stopka(new Stopka(new Naglowek(p))));
    p = new Naglowek(p);
    p->drukuj();
    delete p;
}