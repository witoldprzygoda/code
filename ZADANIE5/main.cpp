#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

// wstaw w jedej lub drugiej funkcji opoznienie
// std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

void addstring( unsigned n, string& s ) {
   while (n--) { 
	   // dodawaj
   }
}
void removestring( string& s ) {
   while ( !s.empty() ) { 
	   // usuwaj
   }	
}
int main() {
   string m;
   // w jednym watku uruchom 100 razy addstring i dodawaj "*" wypisujac "A"
   // w drugim watku uruchom removestrin i usuwaj "*" wypisujac "B"

   cout << endl << m << endl;
}

