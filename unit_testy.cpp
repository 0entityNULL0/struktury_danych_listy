#include <iostream>
#include <vector>
#include <ctime>
#include "tablica_d.h"
#include "linked_list.h"
template <typename T> void wypisz_liste(T &lista)
{
	std::cout<<"dlugosc listy: "<<lista.size()<<"\n";
	for(int i = 0; i<lista.size(); i++)
	{
		std::cout<<"element "<<i<<": "<<lista[i]<<"\n";
	}
}


template <template  <typename> typename T> int testuj_poprawnosc_listy()
{
	const unsigned int rozmiar_testu=1030;
	T <int> lista;
	//std::cout<<"len: "<<lista.size()<<", max_len: "<<lista.mem_size()<<"\n";
	std::cout<<"#[INFO] testuje dodanie 1030 elementow metoda add_last po kolei od 0 do "<<rozmiar_testu-1<<"\n";
	for(int i = 0; i<rozmiar_testu; i++)
	{
		lista.add_last(i);
		for(int j = 0; j<=i; j++)
		{
			if(lista[j]!=j){
				std::cout<<"#[ERROR] dodawanie nie powiodlo sie: po dodaniu "<<j<<" elementu lista nie zgadza się\n";
				wypisz_liste(lista);
				return 1;
			}
		}
	}
	std::cout<<"#[INFO] test przebiegl pomyslnie\n";
	std::cout<<"#[INFO] tworze kopie listy\n";
	T <int> lista2 = lista;
	std::cout<<"#[INFO] testuje usuniecie "<<rozmiar_testu<<" elementow metoda remove_first na kopii\n";
	for(int i = 0; i<rozmiar_testu; i++)
	{
		int * usuwany_element=lista2.remove_first();
		if(usuwany_element!=nullptr) delete usuwany_element;
		if(lista.size()!=rozmiar_testu){
			std::cout<<"#[ERROR] usuwanie na kopii zmienilo liste oryginalna (zmiana rozmiaru)\n";
			wypisz_liste(lista);
				return 1;
		}
		for(int j = 0; j<rozmiar_testu; j++)
		{
			if(lista[j]!=j){
				std::cout<<"#[ERROR] usuwanie na kopii zmienilo liste oryginalna (zmiana elementu)\n";
				wypisz_liste(lista2);
				return 1;
			}
		}
		if(lista2.size()!=rozmiar_testu-(i+1)){
			std::cout<<"#[ERROR] usuwanie nie powiodlo sie: po usnieciu po raz "<<i+1<<" rozmiar nie zgadza sie\n";
			wypisz_liste(lista2);
				return 1;
		}
		for(int j = 0; j<lista2.size(); j++)
		{
			if(lista2[j]!=j+i+1){
				std::cout<<"#[ERROR] usuwanie nie powiodlo sie: po usnieciu po raz "<<i+1<<" zawartosc listy nie zgadza sie\n";
				wypisz_liste(lista2);
				return 1;
			}
		}
	}
	std::cout<<"#[INFO] test przebiegl pomyslnie\n";
	std::cout<<"#[INFO] testuje dodanie 1030 elementow metoda add_first po kolei od 0 do "<<rozmiar_testu-1<<"\n";
	for(int i = 0; i<rozmiar_testu; i++)
	{
		lista2.add_first(i);
		for(int j = 0; j<i; j++)
		{
			if(lista2[j]!=(i)-j){
				std::cout<<"#[ERROR] dodawanie nie powiodlo sie: po dodaniu "<<j<<" elementu lita nie zgadza się\n";
				wypisz_liste(lista2);
				return 1;
			}
		}
	}
	std::cout<<"#[INFO] test przebiegl pomyslnie\n";
	std::cout<<"#[INFO] testuje usuniecie "<<rozmiar_testu<<" elementow metoda remove_last\n";
	for(int i = 0; i<rozmiar_testu; i++)
	{
		int * usuwany_element=lista2.remove_last();
		if(usuwany_element!=nullptr) delete usuwany_element;
		if(lista2.size()!=rozmiar_testu-(i+1)){
			std::cout<<"#[ERROR] usuwanie nie powiodlo sie: po usnieciu po raz "<<i+1<<" rozmiar nie zgadza sie\n";
			wypisz_liste(lista2);
				return 1;
		}
		for(int j = 0; j<lista2.size(); j++)
		{
			if(lista2[j]!=rozmiar_testu-(1+j)){
				std::cout<<"#[ERROR] usuwanie nie powiodlo sie: po usnieciu po raz "<<i+1<<" zawartosc listy nie zgadza sie\n";
				wypisz_liste(lista2);
				return 1;
			}
		}
	}
	std::cout<<"#[INFO] test przebiegl pomyslnie\n";
	std::vector<int> wektor;
	std::cout<<"#[INFO] testuje dodanie 1030 elementow metoda add_on_position po kolei od 0 do "<<rozmiar_testu-1<<" w losowych miejscach (porownuje do std::vector)\n";
	std::srand(std::time({}));
	for(int i = 0; i<rozmiar_testu; i++)
	{
		unsigned int pozycja = std::rand()%(lista2.size()+1);
		if(lista2.add_on_position(i,pozycja)==-1)
		{
			std::cout<<"#[ERROR] dodawanie nie powiodlo sie: pozycja dodawania "<<lista2.size()<<" jest nie odpowiednia dla listy o rozmiarze "<<lista2.size()<<"\n";
		}
		wektor.insert(wektor.begin()+pozycja,i);
		for(int j = 0; j<=i; j++)
		{
			if(lista2[j]!=wektor[j]){
				std::cout<<"#[ERROR] dodawanie nie powiodlo sie: po dodaniu "<<j<<" elementu lita nie zgadza się\n";
				wypisz_liste(lista2);
				std::cout<<"#[INFO] wektor:\n";
				wypisz_liste(wektor);
				return 1;
			}
		}
	}
	std::cout<<"#[INFO] test przebiegl pomyslnie\n";
	std::cout<<"#[INFO] testuje usuwanie 1030 elementow metoda remove_on_position w losowych miejscach (porownuje do std::vector)\n";
	std::srand(std::time({}));
	for(int i = 0; i<rozmiar_testu; i++)
	{
		unsigned int pozycja = std::rand()%(lista2.size());
		int * usuwany_element=lista2.remove_on_position(pozycja);
		if(usuwany_element!=nullptr) delete usuwany_element;
		wektor.erase(wektor.begin()+pozycja);
		if(lista2.size()!=wektor.size())
		{
			std::cout<<"#[ERROR] usuwanie nie powiodlo sie: po usunieciu "<<i<<" elementu na pozycji "<<pozycja<<" lista nie zgadzaja sie dlugosci\n";
			wypisz_liste(lista2);
			std::cout<<"#[INFO] wektor:\n";
			wypisz_liste(wektor);
			return 1;
		}
		
		for(int j = 0; j<lista2.size(); j++)
		{
			if(lista2[j]!=wektor[j]){
				std::cout<<"#[ERROR] usuwanie nie powiodlo sie: po usunieciu "<<i<<" elementu lita nie zgadza się na elemencie "<<j<<"\n";
				wypisz_liste(lista2);
				std::cout<<"#[INFO] wektor:\n";
				wypisz_liste(wektor);
				return 1;
			}
		}
	}
	std::cout<<"#[INFO] test przebiegl pomyslnie\n";
	return 0;
}
int main()
{
	std::cout<<"#[INFO] testy tablicy dynamicznej\n";
	if(testuj_poprawnosc_listy<tablica_dynamiczna>()==0)
		std::cout<<"#[INFO] testy tablicy dynamicznej zakonczone sukcesem\n";
	else return 0;
		
	std::cout<<"#[INFO] testy listy wiazanej\n";
	if(testuj_poprawnosc_listy<LinkedList>()==0)
		std::cout<<"#[INFO] testy listy wiazanej zakonczone sukcesem\n";
	else return 0;
}

