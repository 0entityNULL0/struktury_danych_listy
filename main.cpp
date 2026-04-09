
#include "tablica_d.h"
#include "testy.h"
#include "linked_list.h"

int main()
{
	
typowy_test<tablica_dynamiczna>(1000, 16, "TablicaDynamiczna");
typowy_test<LinkedList>(1000, 16, "ListaWiazana");
	
	return 0;
}
