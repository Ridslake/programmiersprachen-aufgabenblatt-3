#include <csdtlib>	//std::rand()
#include <vector>	//std::vectir<>
#include <list>		//std::list<>
#include <iostream>
#include <iterator>	//std::ostream_iterator<>
#include <algorithm>	//std::reverse, std::generate

int main()
{
//Vector v0 with 10 int-values
	std::vector<int> v0(10);			//vector <int>
//Iterator for all values of v0
	for(std::vector<int>::iterator it = v0.begin(); it != v0.end(); ++it)
		+it = std::rand();
//alternative
//for (auto& v : v0)
//{
//	v= std:: rand();
//}
/*
Ein Iterator ist ein Zeiger mit dem die Elemente einer Menge durchlaufen werden koennen
*/

//cout a copy of the vector using the iterator
std::copy(std::begin(v0), std::end(v0)
	std::ostream_iterator<int>(std::cout, "\n"));

//create a list with the size of the vector with the values of the vector
std::list<int> l0(v0.size());				//list <int>
std::copy(std::begin(v0), std::end(v0), std::begin(l0));

//reverse the list
std::list<int> l1(std::begin(l0), std::end(l0));	//list <int>
std::reverse(std::begin(l1), std::end(l1));		//list <int>
std::copy(std::begin(l1), std::end(l1),
		std::ostream_iterator<int>(std::cout, "\n"));

//sort the list
l1.sort();
std::copy(l1.begin(), l1.end(),
		std::ostream_iterator<int>(std::cout, "\n"));

//generate and cout reverse v0 with random values
std::generate(std::begin(v0), std::end(v0), std::rand);
std::copy(v0.rbegin(), v0.rend(),
		std::ostream:iterator<int>(std::cout, "\n"));

return 0;
}
