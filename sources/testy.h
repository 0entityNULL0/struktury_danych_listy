#ifndef TESTY_H
#define TESTY_H
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <ctime>


template <typename T> class tablica_dynamiczna;
template <typename T> class LinkedList;

template <typename T> T* zrob_kopie(T &co, long long int ile)
{
    T* wyjscie = new T[ile];
    for(int i = 0; i < ile; i++) {
        wyjscie[i] = co;
    }
    return wyjscie;
}

template <typename T, typename B> long long int testuj_add_first(T &struktura, B &dodawany_przedmiot, long long int ile)
{
    T* kopie = zrob_kopie(struktura, ile);
    B* kopie_dodawania = zrob_kopie(dodawany_przedmiot, ile);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(int i = 0; i < ile; i++)
        kopie[i].add_first(kopie_dodawania[i]);
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    delete[] kopie;
    delete[] kopie_dodawania;
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

template <typename T, typename B> long long int testuj_add_last(T &struktura, B &dodawany_przedmiot, long long int ile)
{
    T* kopie = zrob_kopie(struktura, ile);
    B* kopie_dodawania = zrob_kopie(dodawany_przedmiot, ile);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(int i = 0; i < ile; i++)
        kopie[i].add_last(kopie_dodawania[i]);
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    delete[] kopie;
    delete[] kopie_dodawania;
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

template <typename T, typename B> long long int testuj_add_on_position(T &struktura, B &dodawany_przedmiot, long long int ile)
{
    T* kopie = zrob_kopie(struktura, ile);
    B* kopie_dodawania = zrob_kopie(dodawany_przedmiot, ile);
    
    std::srand(std::time({}));
   long long int * losowe_pozycje = new long long int[ile];
     
    for(int i = 0; i < ile; i++) {
        losowe_pozycje[i] = std::rand() % (struktura.size() + 1);
    }
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(int i = 0; i < ile; i++) {
        kopie[i].add_on_position(kopie_dodawania[i], losowe_pozycje[i]);
    }
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    delete[] kopie;
    delete[] kopie_dodawania;
    delete[] losowe_pozycje;
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

template <typename T> long long int testuj_remove_first(T &struktura, long long int  ile)
{
    T* kopie = zrob_kopie(struktura, ile);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(long long int  i = 0; i < ile; i++)
        delete kopie[i].remove_first();
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    delete[] kopie;
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

template <typename T> long long int testuj_remove_last(T &struktura, long long int  ile)
{
    T* kopie = zrob_kopie(struktura, ile);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(long long int  i = 0; i < ile; i++)
        delete kopie[i].remove_last();
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    delete[] kopie;
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

template <typename T> long long int testuj_remove_on_position(T &struktura, long long int ile)
{
    T* kopie = zrob_kopie(struktura, ile);
    std::srand(std::time({}));
    long long int* losowe_pozycje = new long long int[ile];
     
    for(long long int i = 0; i < ile; i++) {
        losowe_pozycje[i] = std::rand() % (struktura.size());
    }
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(long long int i = 0; i < ile; i++) 
        delete kopie[i].remove_on_position(losowe_pozycje[i]);
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    delete[] kopie;
    delete[] losowe_pozycje;
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}


template <typename T> long long int testuj_find(T &struktura, long long int ile)
{
	
    std::srand(std::time({}));
    int* losowe_pozycje = new int[ile];
     
    for(long long int i = 0; i < ile; i++) {
        losowe_pozycje[i] = std::rand();
    }
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(long long int i = 0; i < ile; i++) {
        struktura.find(losowe_pozycje[i]);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

template <template <typename> typename T> 
void typowy_test(long long int ile, long long int rozmiar, std::string nazwa_struktury = "Struktura")
{
    T<long long int> tablica;
    long long int dodaj;
    std::cout << "[INFO] Tworze: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    for(int i = 0; i < rozmiar; i++) 
    {
		dodaj=i;
		tablica.add_last(dodaj);
	}
	 std::cout << "[INFO-B] Testowanie add_first: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long af = testuj_add_first(tablica, dodaj, ile);
	 std::cout << "[INFO-B] Testowanie add_last: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long al = testuj_add_last(tablica, dodaj, ile);
	 std::cout << "[INFO-B] Testowanie add_on_position: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long ap = testuj_add_on_position(tablica, dodaj, ile);
	 std::cout << "[INFO-B] Testowanie remove_first: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long rf = testuj_remove_first(tablica, ile);
	 std::cout << "[INFO-B] Testowanie remove_last: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long rl = testuj_remove_last(tablica, ile);
	 std::cout << "[INFO-B] Testowanie remove_on_position: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long rp = testuj_remove_on_position(tablica, ile);
	 std::cout << "[INFO-B] Testowanie find: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long find_time = testuj_find(tablica, ile);

    std::ofstream plik("wyniki.csv", std::ios::app);
    if (plik.is_open()) {
        plik.seekp(0, std::ios::end);
        if (plik.tellp() == 0) {
            plik << "Type;Size;Reps;AddFirst;AddLast;AddPos;RemFirst;RemLast;RemPos;Find\n";
        }
        
        plik << nazwa_struktury << ";" 
             << rozmiar << ";" 
             << ile << ";" 
             << af/ile << ";" 
             << al/ile << ";" 
             << ap/ile << ";" 
             << rf/ile << ";" 
             << rl/ile << ";" 
             << rp/ile << ";"
             << find_time/ile << "\n";
        
        plik.close();
    }
    std::cout << "[INFO] Zapisano: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
}
template <template <typename> typename T> 
void typowy_test_add_first(long long int ile, long long int rozmiar, std::string nazwa_struktury = "Struktura")
{
    T<long long int> tablica;
    int dodaj;
    std::cout << "[INFO] Tworze: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    for(int i = 0; i < rozmiar; i++) 
    {
		dodaj=i;
		tablica.add_first(dodaj);
	}
	 std::cout << "[INFO-B] Testowanie add_first: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long af = testuj_add_first(tablica, dodaj, ile);
	 std::cout << "[INFO-B] Testowanie add_last: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long al = testuj_add_last(tablica, dodaj, ile);
	 std::cout << "[INFO-B] Testowanie add_on_position: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long ap = testuj_add_on_position(tablica, dodaj, ile);
	 std::cout << "[INFO-B] Testowanie remove_first: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long rf = testuj_remove_first(tablica, ile);
	 std::cout << "[INFO-B] Testowanie remove_last: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long rl = testuj_remove_last(tablica, ile);
	 std::cout << "[INFO-B] Testowanie remove_on_position: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long rp = testuj_remove_on_position(tablica, ile);
	 std::cout << "[INFO-B] Testowanie find: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
    long long find_time = testuj_find(tablica, ile);

    std::ofstream plik("wyniki.csv", std::ios::app);
    if (plik.is_open()) {
        plik.seekp(0, std::ios::end);
        if (plik.tellp() == 0) {
            plik << "Type;Size;Reps;AddFirst;AddLast;AddPos;RemFirst;RemLast;RemPos;Find\n";
        }
        
        plik << nazwa_struktury << ";" 
             << rozmiar << ";" 
             << ile << ";" 
             << af/ile << ";" 
             << al/ile << ";" 
             << ap/ile << ";" 
             << rf/ile << ";" 
             << rl/ile << ";" 
             << rp/ile << ";"
             << find_time/ile << "\n";
        
        plik.close();
    }
    std::cout << "[INFO] Zapisano: " << nazwa_struktury << " (n=" << rozmiar << ")" << std::endl;
}
#endif
