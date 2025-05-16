// kod


int main() {
    DP1 library1; // pierwsza biblioteka
    DP2 library2; // druga biblioteka

    Drawing *d1 = new V1Drawing( library1 );
    Drawing *d2 = new V2Drawing( library2 );

    Shape *p1 = new Rectangle( d1 );
    Shape *p2 = new Circle( d2 );

    p1->draw(); // rectangle linia V1
    p2->draw(); // circle okrag V2
    p1->setLib( d2 );
    p2->setLib( d1 );
    p1->draw(); // rectangle linia V2
    p2->draw(); // circle okrag V1

    delete p1;
    delete p2;
    delete d1; 
    delete d2;   
}

