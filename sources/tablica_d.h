
#ifndef TABLICA_D_H
#define TABLICA_D_H

#include <utility>

template <typename T> class tablica_dynamiczna
{
private:
	T *dane;
	unsigned int len;
	unsigned int rezerwowany_len;

private:
	
	
public:

	tablica_dynamiczna()
	{
		len=0;
		rezerwowany_len=1;
		dane=new T[1];
	}
	tablica_dynamiczna(unsigned int size)
	{
		len=size;
		rezerwowany_len=1;
		while(rezerwowany_len<size) rezerwowany_len*=2;
		dane=new T[rezerwowany_len];
	}
	~tablica_dynamiczna()
	{
		if(dane!=nullptr) delete dane;
	}
	tablica_dynamiczna(tablica_dynamiczna<T> &&kopia)
	{
		unsigned int tmp = this->len;
		this->len=kopia.size();
		kopia.len=tmp;
		tmp = this->rezerwowany_len;
		this->rezerwowany_len=kopia.size();
		kopia.rezerwowany_len=tmp;
		T* tmp2= this->dane;
		this->dane = kopia->dane;
		kopia->dane=tmp2;
	}
	tablica_dynamiczna& operator=(tablica_dynamiczna<T>&& kopia)
	{
		unsigned int tmp = this->len;
		this->len=kopia.size();
		kopia.len=tmp;
		tmp = this->rezerwowany_len;
		this->rezerwowany_len=kopia.size();
		kopia.rezerwowany_len=tmp;
		T* tmp2= this->dane;
		this->dane = kopia->dane;
		kopia->dane=tmp2;
	}
	
	tablica_dynamiczna(const tablica_dynamiczna<T> &kopia)
	{
		this->len=kopia.size();
		this->rezerwowany_len=kopia.mem_size();
		this->dane = new T[rezerwowany_len];
		for(int i = 0 ; i < rezerwowany_len; i++ )
		{
			this->dane[i]=kopia[i];
		}
	}
    tablica_dynamiczna& operator=(const tablica_dynamiczna<T>& kopia)
    {
		if(dane!=nullptr) delete dane;
		this->len=kopia.size();
		this->rezerwowany_len=kopia.mem_size();
		this->dane = new T[rezerwowany_len];
		for(int i = 0 ; i < rezerwowany_len; i++ )
		{
			this->dane[i]=kopia[i];
		}
		return *this;
	}
	unsigned int mem_size() const
	{
		return rezerwowany_len;
	}
	unsigned int size() const
	{
		return len;
	}
	unsigned int is_empty() const
	{
		if(len==0)
			return 1;
		return 0;
	}
	int add_first(T &element)
	{
		unsigned int nowy_len=len+1;
		T *nowa_tablica;
		int zmiana_tablicy=0;
		if(rezerwowany_len<len)
		{
			zmiana_tablicy=1;
			unsigned int nowy_rezerwowany_len=rezerwowany_len*2;
			nowa_tablica=new T[nowy_rezerwowany_len];
			rezerwowany_len=nowy_rezerwowany_len;
		}else
		{
			nowa_tablica=dane;
		}
		for(int i=len; i>0;i--)
			nowa_tablica[i]=std::move(dane[i-1]); 
		nowa_tablica[0]=std::move(element);
		len=nowy_len;
		if(zmiana_tablicy==1)
			delete dane;
		dane=nowa_tablica;
		return 0;
		
	}
	int add_last(T &element)
	{
		T *nowa_tablica;
		unsigned int nowy_len=len+1;
		if(rezerwowany_len<len)
		{
			unsigned int nowy_rezerwowany_len=rezerwowany_len*2;
			nowa_tablica=new T[nowy_rezerwowany_len];
			for(int i=0; i<len;i++)
				nowa_tablica[i]=std::move(dane[i]); 
			rezerwowany_len=nowy_rezerwowany_len;
			delete dane;
		}else nowa_tablica=dane;
		nowa_tablica[len]=std::move(element);
		len=nowy_len;
		dane=nowa_tablica;
		return 0;
		
	}
	int add_on_position(T &element,unsigned int where)
	{
		if(where>len) return -1;
		T *nowa_tablica;
		unsigned int nowy_len=len+1;
		int zmiana_tablicy=0;
		if(rezerwowany_len<len)
		{
			zmiana_tablicy=1;
			unsigned int nowy_rezerwowany_len=rezerwowany_len*2;
			nowa_tablica=new T[nowy_rezerwowany_len];
			rezerwowany_len=nowy_rezerwowany_len;
		}else nowa_tablica=dane;
		
		for(int i=len; i>where;i--)
			nowa_tablica[i]=std::move(dane[i-1]); 
		
		nowa_tablica[where]=std::move(element);
		
		for(int i=0; i<where;i++)
			nowa_tablica[i]=std::move(dane[i]); 
		len=nowy_len;
		if(zmiana_tablicy==1) delete dane;
		dane=nowa_tablica;
		return 0;
	}
	T* remove_first()
	{
		if(len<1) return nullptr;
		T *nowa_tablica;
		T* usuwany_element = new T;
		int zmiana_tablicy=0;
		*usuwany_element=std::move(dane[0]);
		unsigned int nowy_len=len-1;
		if(nowy_len!=0&&nowy_len*2<=rezerwowany_len)
		{
			nowa_tablica=new T[rezerwowany_len/2];
			rezerwowany_len=rezerwowany_len/2;
		}else nowa_tablica=dane;
		for(int i=0; i<nowy_len; i++)
			nowa_tablica[i]=std::move(dane[i+1]);
		if(zmiana_tablicy==1) delete dane;
		dane=nowa_tablica;
		len=nowy_len;
		return usuwany_element;
		
	}
	T* remove_last()
	{
		if(len<1) return nullptr;
		T *nowa_tablica;
		T* usuwany_element = new T;
		*usuwany_element=std::move(dane[len-1]);
		unsigned int nowy_len=len-1;
		if(nowy_len!=0&&nowy_len*2<=rezerwowany_len)
		{
			nowa_tablica=new T[rezerwowany_len/2];
			rezerwowany_len=rezerwowany_len/2;
			for(int i=0; i<nowy_len; i++)
				nowa_tablica[i]=std::move(dane[i]);
			delete dane;
			dane=nowa_tablica;
		}
		
		len=nowy_len;
		return usuwany_element;}
	T* remove_on_position(unsigned int where)
	{
		unsigned int nowy_len=len-1;
		
		if(where>=len) return nullptr;
		
		T *nowa_tablica;
		T* usuwany_element = new T;
		*usuwany_element=std::move(dane[where]);
		int zmiana_tablicy=0;
		if(nowy_len!=0&&nowy_len*2<=rezerwowany_len)
		{
			zmiana_tablicy=1;
			nowa_tablica=new T[rezerwowany_len/2];
			rezerwowany_len=rezerwowany_len/2;
		}else nowa_tablica=dane;
		
		for(int i=where; i<len-1;i++)
			nowa_tablica[i]=std::move(dane[i+1]); 
		
		for(int i=0; i<where;i++)
			nowa_tablica[i]=std::move(dane[i]); 
			
		len=nowy_len;
		
		if(zmiana_tablicy==1) delete dane;
		
		dane=nowa_tablica;
		return usuwany_element;
		
	}
	T operator [](int i) const    {return dane[i];}
    T & operator [](int i) {return dane[i];}
};


#endif
