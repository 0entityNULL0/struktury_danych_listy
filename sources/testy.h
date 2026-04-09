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

#include <iostream>
#include <fstream>
#include <string>

template <template <typename> typename T> 
void typowy_test(unsigned int ile, unsigned int rozmiar, std::string nazwa_struktury = "Struktura")
{
    T<int> tablica;
    int dodaj = 5;
    for(unsigned int i = 0; i < rozmiar; i++) tablica.add_last(dodaj);

    long long af = testuj_add_first(tablica, dodaj, ile);
    long long al = testuj_add_last(tablica, dodaj, ile);
    long long ap = testuj_add_on_position(tablica, dodaj, ile);
    long long rf = testuj_remove_first(tablica, ile);
    long long rl = testuj_remove_last(tablica, ile);
    long long rp = testuj_remove_on_position(tablica, ile);

    double avg_af = (double)af / ile;
    double avg_al = (double)al / ile;
    double avg_ap = (double)ap / ile;
    double avg_rf = (double)rf / ile;
    double avg_rl = (double)rl / ile;
    double avg_rp = (double)rp / ile;

    std::ofstream plik("wyniki.csv", std::ios::app);
    if (plik.is_open()) {
        plik.seekp(0, std::ios::end);
        if (plik.tellp() == 0) {
            plik << "Type;Size;Reps;AddFirst;AddLast;AddPos;RemFirst;RemLast;RemPos\n";
        }
        
        plik << nazwa_struktury << ";" 
             << rozmiar << ";" 
             << ile << ";" 
             << avg_af << ";" 
             << avg_al << ";" 
             << avg_ap << ";" 
             << avg_rf << ";" 
             << avg_rl << ";" 
             << avg_rp << "\n";
        
        plik.close();
    }
    std::cout << "[INFO] Zapisano: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
}
#endif
