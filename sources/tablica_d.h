#include <utility>
namespace my {
template <type T> class tablica_dynamiczna
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
		dane=nullptr;
	}
	tablica_dynamiczna(unsigned int size)
	{
			len=size;
		if(len!=0){
			dane=malloc(sizeof(t)*size);
		}else{
			dane=nullptr;
		}
	}
	~tablica_dynamiczna()
	{
		free(dane);
	}
	int size()
	{
		return len;
	}
	int len()
	{
		return len;
	}
	int is_empty()
	{
		if(len==0)
			return 1;
		return 0;
	}
	int add_first(T element)
	{
		nowy_len=len+1;
		T *nowa_tablica;
		if(rezerwowany_len<len)
		{
			unsigned int nowy_rezerwowany_len=rezerwowany_len*2;
			nowa_tablica=malloc(nowy_rezerwowany_len)
			rezerwowany_len=nowy_rezerwowany_len;
		}else
		{
			nowa_tablica=dane;
		}
		for(int i=len; i>0;i--)
			nowa_tablica[i]=std::move(dane[i-1]); 
		nowa_tablica[0]=std::move(element);
		len++;
		free(dane);
		dane=nowa_tablica;
		return 0;
		
	}
	int add_last(T element)
	{
		nowy_len=len+1;
		if(rezerwowany_len<len)
		{
			unsigned int nowy_rezerwowany_len=rezerwowany_len*2;
			T *nowa_tablica=malloc(nowy_rezerwowany_len)
			for(int i=0; i<len;i++)
				nowa_tablica[i]=std::move(dane[i]); 
			rezerwowany_len=nowy_rezerwowany_len;
		}else {nowa_tablica=dane;dane=null;}
		nowa_tablica[len]=std::move(element);
		len++;
		free(dane);
		dane=nowa_tablica;
		return 0;
		
	}
	int add_in_place(T element,unsigned int where)
	
	{
		nowy_len=len+1;
		T *nowa_tablica;
		if(rezerwowany_len<len)
		{
			unsigned int nowy_rezerwowany_len=rezerwowany_len*2;
			nowa_tablica=malloc(nowy_rezerwowany_len)
			rezerwowany_len=nowy_rezerwowany_len;
		}else
		{
			nowa_tablica=dane;
		}
		for(int i=len; i>where;i--)
			nowa_tablica[i]=std::move(dane[i-1]); 
			
		for(int i=where-1; i>=0;i--)
			nowa_tablica[i]=std::move(dane[i]); 
		nowa_tablica[0]=std::move(element);
		len++;
		free(dane);
		dane=nowa_tablica;
		return 0;
		
	}
	T remove_first()
	{
		if(len==0) return nullptr;
		nowy_len=len-1;
		T *nowa_tablica;
		if(rezerwowany_len/2>=nowy_len)
		{
			unsigned int nowy_rezerwowany_len=rezerwowany_len/2;
			nowa_tablica=malloc(nowy_rezerwowany_len)
			rezerwowany_len=nowy_rezerwowany_len;
		}else
		{
			nowa_tablica=dane;
		}
		T usuwany_element=std::move(dane[0])
		for(int i=0; i<len-1;i++)
			nowa_tablica[i]=std::move(dane[i+1]); 
		nowa_tablica[0]=std::move(element);
		len--;
		free(dane);
		dane=nowa_tablica;
	
		return usuwany_element;
	}
	T* remove_last(T element)
	{
		if(len==0) return nullptr;
		T usuwany_element=std::move(dane[len-1])
		nowy_len=len-1;
		T *nowa_tablica;
		if(rezerwowany_len/2>=nowy_len)
		{
			unsigned int nowy_rezerwowany_len=rezerwowany_len/2;
			nowa_tablica=malloc(nowy_rezerwowany_len)
			rezerwowany_len=nowy_rezerwowany_len;
			for(int i=0; i<len-1;i++)
				nowa_tablica[i]=std::move(dane[i]); 
			free(dane);
			dane=nowa_tablica;
		}
		len=nowy_len;
		for(int i=len; i>where;i--)
			nowa_tablica[i]=std::move(dane[i-1]); 
	
		return usuwany_element;
		
	}
	T* remove_in_place(T element)
	int connect(tablica_dynamiczna <T> dodawana)
};
}
