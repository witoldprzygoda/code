class Kolo;
class Kwadrat;
class OdwiedzajacyKsztalty;
 
// Klasa bazowa dla kształtów
class Ksztalt {
public:
    virtual ~Ksztalt() = default;
    virtual void przyjmij(OdwiedzajacyKsztalty& odwiedzajacy) = 0;
};
 
// Interfejs dla odwiedzającego (visitor)
class OdwiedzajacyKsztalty {
public:
    virtual void odwiedz(Kolo& kolo) = 0;
    virtual void odwiedz(Kwadrat& kwadrat) = 0;
};
 
// Konkretne klasy kształtów
class Kolo : public Ksztalt {
public:
    void przyjmij(OdwiedzajacyKsztalty& odwiedzajacy) override {
        odwiedzajacy.odwiedz(*this);
    }
};
 
class Kwadrat : public Ksztalt {
// twoja definicja
};
 
// Konkretna klasa odwiedzającego, implementująca wielokrotną dyspozycję
class OdwiedzajacyKolizje : public OdwiedzajacyKsztalty {
public:
 
    void obsluzKolizje(Ksztalt& ksztalt1, Ksztalt& ksztalt2) {
// twoja definicja

