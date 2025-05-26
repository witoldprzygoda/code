#include <iostream>
#include <string>

class Model {
    std::string data;
public:
    void setData(const std::string& d) { data = d; }
    std::string getData() const { return data; }
};

class View {
public:
    // tu metoda niewirtualna show zgodnie z ideą NVI (Non-Virtual Interface)
protected:
    virtual void rysuj(const std::string& d) // zaimplementuj razem z jakąś ramką ozdobną
};

class Controller {
    Model& model;
    View& view;
public:
    Controller(Model& m, View& v) : model(m), view(v) {}
    void set(const std::string& d) { model.setData(d); }
    void updateView() { view.show(model.getData()); }
};

int main() {
    Model m;
    View v;
    Controller c(m, v);

    // kod: wczytaj wielokrotnie z klawiatury tekst (+ mechanizm że jakiś znak kończy) i za każdym razem zaktualizuj widok

    return 0;
}
