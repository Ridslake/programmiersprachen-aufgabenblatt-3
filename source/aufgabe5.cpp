# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>

bool is_odd(int i)
{
	return (i % 2) != 0;  //odd if mod2 != 0
}

bool is_even(int i)
{
	return(i % 2) == 0;
}


TEST_CASE ("describe_factorial","[aufgabe3]")
{
	std::vector<unsigned int> v0(100); //vector, size 100

	for(std::vector<unsigned int>::iterator it = v0.begin(); //iterate
		it != v0.end(); ++it)
		{
			*it = std::rand() % 101;   //random values
		}


	v0.erase(std::remove_if(v0.begin(), v0.end(), is_odd), v0.end() );//remove all odd

	REQUIRE(std::all_of(v0.begin(),v0.end(),is_even ));//test
}

int main(int argc,char*argv[])
{
	return Catch::Session().run(argc,argv );
}
