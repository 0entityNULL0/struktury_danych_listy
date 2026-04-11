#include "tablica_d.h"
#include "testy.h"
#include "linked_list.h"

int main() {
    
    unsigned int rozmiary[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    unsigned int powtorzenia = 1000; 

    for(unsigned int n : rozmiary) {
        std::cout << "Testuje rozmiar: " << n << std::endl;
        typowy_test<tablica_dynamiczna>(powtorzenia, n, "Tablica");
        typowy_test<LinkedList>(powtorzenia, n, "Lista");
    }

    return 0;
}
