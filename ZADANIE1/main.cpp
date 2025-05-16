#include <iostream>
using namespace std;

#define P(x) std::cout << x << std::endl

//–––– 1.  Wspólna baza ––––––––––––––––––––––––––––––––––
class A1 {
    int i{5};
public:
    explicit A1(bool)               { P("A1  c-tor"); }
    virtual ~A1()                   { P("A1  d-tor"); }
    int get() const                 { return i; }
};

//–––– 2.  Gałąź V1 ––––––––––––––––––––––––––––––––––––––
class V1 : virtual public A1 {
public:
    explicit V1(bool)               { P("V1  c-tor"); }   
    ~V1() override                  { P("V1  d-tor"); }
};

//–––– 3.  Pozostałe elementy drzewa –––––––––––––––––––––
class B2 {
    // kod
};

class B3 {
    // kod
};

class V2 : virtual public A1, public B2 {
    // kod
};

class C1 : virtual public V1 {
    // kod
};

class C2 : virtual public V2, public B3 {
    // kod
};

//–––– 4.  Składowe ––––––––––––––––––––––––––––––––––––––
class M1 {
    // kod
};

class M2 {
    // kod
};

//–––– 5.  Klasa główna –––––––––––––––––––––––––––––––
class X : public C1, public C2 {
    M1 m1;
    M2 m2;
public:
    // kod 
};

//–––– 6.  Test ––––––––––––––––––––––––––––––––––––––––––
int main()
{
    std::cout << "--- START ---\n\n";

    A1* pa = new X;                       
    std::cout << "\nwartosc i = " << pa->get() << "\n\n";
    delete pa;                            

    std::cout << "\n---  END  ---\n";
}
