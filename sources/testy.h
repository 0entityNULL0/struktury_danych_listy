#ifndef TESTY_H
#define TESTY_H
#include <iostream>
#include <chrono>

#include <ctime>



template <typename T> T* zrob_kopie(T &co, unsigned int ile)
{
	T* wyjscie = new T[ile];
	for(int i = 0; i<ile; i++){
		wyjscie[i]=co;
	}
	return wyjscie;
}

template <typename T,typename B> int testuj_add_first(T &struktura, B &dodawany_przedmiot, unsigned int ile)
{
	T* kopie = zrob_kopie(struktura,ile);
	B* kopie_dodawania = zrob_kopie(dodawany_przedmiot,ile);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for(int i = 0; i<ile; i++)
		kopie[i].add_first(kopie_dodawania[i]);
	
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	delete[] kopie;
	delete kopie_dodawania;
	return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}
template <typename T,typename B> int testuj_add_last(T &struktura, B &dodawany_przedmiot, unsigned int ile)
{
	T* kopie = zrob_kopie(struktura,ile);
	B* kopie_dodawania = zrob_kopie(dodawany_przedmiot,ile);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for(int i = 0; i<ile; i++)
		kopie[i].add_last(kopie_dodawania[i]);
	
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	delete[] kopie;
	delete kopie_dodawania;
	return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}
template <typename T,typename B> int testuj_add_on_position(T &struktura,  B &dodawany_przedmiot, unsigned int ile)
{
	T* kopie = zrob_kopie(struktura,ile);
	B* kopie_dodawania = zrob_kopie(dodawany_przedmiot,ile);
	
	std::srand(std::time({}));
	unsigned int losowe_pozycje[ile];
	 
	for(int i = 0; i<ile; i++){
		losowe_pozycje[ile]= std::rand()%(struktura.size()+1);
	}
	
	
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for(int i = 0; i<ile; i++){
		kopie[i].add_on_position(kopie_dodawania[i],losowe_pozycje[i]);
	}
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	delete[] kopie;
	delete kopie_dodawania;
	return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}
template <typename T> int testuj_remove_first(T &struktura, unsigned int ile)
{
	T* kopie = zrob_kopie(struktura,ile);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for(int i = 0; i<ile; i++)
		delete kopie[i].remove_first();
	
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	delete[] kopie;
	return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}
template <typename T> int testuj_remove_last(T &struktura, unsigned int ile)
{
	T* kopie = zrob_kopie(struktura,ile);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for(int i = 0; i<ile; i++)
		delete kopie[i].remove_last();
	
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	delete[] kopie;
	return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}
template <typename T> int testuj_remove_on_position(T &struktura, unsigned int ile)
{
	T* kopie = zrob_kopie(struktura,ile);
	std::srand(std::time({}));
	unsigned int losowe_pozycje[ile];
	 
	for(int i = 0; i<ile; i++){
		losowe_pozycje[ile]= std::rand()%(struktura.size());
	}
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for(int i = 0; i<ile; i++)
		delete kopie[i].remove_on_position(losowe_pozycje[i]);
	
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	delete[] kopie;
	return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

template <template  <typename> typename T> void typowy_test(unsigned int ile,unsigned int rozmiar)
{
	T <int> tablica;
	int dodaj=5;
	
	for(int i = 0; i<rozmiar;i++){
		tablica.add_last(dodaj);
	}
	int czas;
	std::cout<<"[INFO]test listy o rozmiarze "<<rozmiar<<" wyknoywany "<<ile<<" razy dla każdej operacji\n";
	std::cout<<"[INFO]test add_first\n";
	czas = testuj_add_first(tablica,dodaj,rozmiar);
	std::cout<<"[INFO-WYNIK]czas wykonania operacji wyniusl "<<czas<<"ns\n";
	std::cout<<"[INFO]test add_last\n";
	czas = testuj_add_last(tablica,dodaj,rozmiar);
	std::cout<<"[INFO-WYNIK]czas wykonania operacji wyniusl "<<czas<<"ns\n";
	std::cout<<"[INFO]test add_on_position\n";
	czas = testuj_add_on_position(tablica,dodaj,rozmiar);
	std::cout<<"[INFO-WYNIK]czas wykonania operacji wyniusl "<<czas<<"ns\n";
	std::cout<<"[INFO]test remove_first\n";
	czas = testuj_remove_first(tablica,rozmiar);
	std::cout<<"[INFO-WYNIK]czas wykonania operacji wyniusl "<<czas<<"ns\n";
	std::cout<<"[INFO]test remove_last\n";
	czas = testuj_remove_last(tablica,rozmiar);
	std::cout<<"[INFO-WYNIK]czas wykonania operacji wyniusl "<<czas<<"ns\n";
	std::cout<<"[INFO]test remove_on_position\n";
	czas = testuj_remove_on_position(tablica,rozmiar);
	std::cout<<"[INFO-WYNIK]czas wykonania operacji wyniusl "<<czas<<"ns\n";
	std::cout<<"[INFO]koniec testu\n";
	
	
}

#endif
