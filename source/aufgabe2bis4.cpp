# include <cstdlib>
# include <vector> 
# include <list>   
# include <iostream> 
# include <iterator> 
# include <algorithm> 
# include <set>
# include <map>
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
//Tasks 2 to 4
//3.2
int main(int argc, char *argv[])
{
	std::list<unsigned int> l0(100); //list l0 with 100

	for(std::list<unsigned int>::iterator it = l0.begin(); //iterate the vector
		it != l0.end(); ++it)
	{
		*it = rand() % 101;   //fill with 0-100, 101 because of the 0
	}

	std::vector<unsigned int>v0(l0.size()); //vector, size of l0
	std::copy(std::begin(l0), std::end(l0), std::begin(v0)); //copy list into vector 

//3.3
	std::cout <<"\n";	
	std::set<unsigned int>set_list(std::begin(l0), std::end(l0)); //set all values must be unique
	std::cout<<"There are " <<set_list.size() << " diffrent numbers\n" <<std::endl; //.size unsigned comparison of int values

	//cout whats not in the list
	std::cout <<"Following values are not in the list\n";
	for(int i = 0; i<= 100; ++i)
	{
		if(set_list.count(i) == false)
		{
			std::cout << i << std::endl;
		}
	}
	std::cout <<"\n";
//3.4
	//create map
	std::cout <<"Numbers and their frequency\n";
	std::map<unsigned int, unsigned int>mapls;//Map with 2 values
	//commonnes	
	for(auto &i: l0)
	{
		++mapls[i];
	}

	for(int i = 0; i<= 100; ++i)
	{
		std::cout << i << " : " << mapls[i] << std::endl;
	}

	return Catch::Session().run(argc, argv);
}
/* Ein Map bietet sich an, da man so als Schluessel die Zahl nutzen kann
 und ihr die Haeufigkeit zuornden kann
*/
