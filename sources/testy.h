


template <typename T> T* zrob_kopie(T co, unsigned int ile)
{
	T* wyjscie = new T[ile];
	for(int i = 0; i<ile; i++)
		wyjscie[i]=co;
	return wyjscie;
}

