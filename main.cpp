#include <iostream>
#include <vector>

int main()
{
	std::vector <int> a;
	for(int i = 0 ;  i<5; i++) 
	{
		a.push_back(i);
	}
	int running=1;
	while(running)
	{
		int wybor;
			
		for(int i = 0 ;  i<a.size(); i++) 
		{
			std::cout<<i<<": "<<a[i]<<"\n";
		}
		std::cout<<"opcje:\n1.dodaj w x\n2. usun w x\nwybierz: ";
		std::cin>>wybor;
		if(wybor>0&&wybor<3)
		{
			int co;int gdzie;
			std::cout<<"gdzie dodac: ";
			std::cin>>gdzie;
			if(wybor==1)
			{
				std::cout<<"co dodac: ";
				std::cin>>co;
				a.insert(a.begin()+gdzie,co);
			}else
				a.erase(a.begin()+gdzie);
		}else running=0;
	}
	return 0;
}
