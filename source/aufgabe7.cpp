# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
# include "circle.hpp"
//tasks 7 to 9
bool is_odd(int i)
{
	return (i % 2) != 0;  
}

bool is_even(int i)
{
	return(i % 2) == 0;
}

//7
template <typename container, typename funktion>
	container filter(container const& C, funktion const& D)
	{
		container nC;	//new C
		for(auto i : C)
		{
			if(D(i))nC.push_back(i); //sort
		}
	return nC;
	}

//8  swap
template <typename container, typename datype>
	void swap(datype one, datype two, container& C)
	{
		auto D = C[one];	//save temporary
		C[one]=C[two];		//exchange
		C[two]=D;		//two = temporary
	}

TEST_CASE ("describe_factorial","[aufgabe7]")
{
	std::vector<Circle> circle(50); //50 circle

		for(int i = 0; i < 50; ++i){
			circle[i].setradius(rand());	//random radius
		}

	std::sort(circle.begin(),circle.end());		//sort

	REQUIRE(std::is_sorted(circle.begin(),circle.end()));
}

TEST_CASE("describe_swap","[aufgabe8]")
{
	std::vector<char> vec{'a','b','c','d','e'};
	swap(0,4,vec);
	swap(1,2,vec);
	REQUIRE(vec[0]=='e');
	REQUIRE(vec[4]=='a');
	REQUIRE(vec[1]=='c');
	REQUIRE(vec[2]=='b');
	swap(1,3,vec);
	REQUIRE(vec[1]=='d');
	REQUIRE(vec[3]=='c');
}
//9
TEST_CASE("lambda","[lambda]")
{
	std::vector<Circle> circle(33);

	for(int i = 0; i < 33; ++i)
	{
		circle[i].setradius(rand());
	}
	std::sort(circle.begin(),circle.end(), [] (Circle d, Circle e) {return d.getradius() < e.getradius();});

	REQUIRE(std::is_sorted(circle.begin(), circle.end()));
}
//10
TEST_CASE("vecadd","[vecadd]")
{
	std::vector<int>v1 {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	std::vector<int>v2 {9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
	std::vector<int>v3 (9);				//9 because 9

	std::transform(v1.begin(),v1.end(),v2.begin(),v3.begin(), [] (int d, int e) {return d + e;});

	REQUIRE(std::all_of (v3.begin(), v3.end(), [] (int a) {return a == 10;}));
}
//11
TEST_CASE("filter","[filter]")
{
	std::vector<int>v{1,2,3,4,5,6};
	std::vector<int>alleven = filter(v, is_even );

	REQUIRE(std::all_of(alleven.begin(),alleven.end(), is_even));
}

int main(int argc,char*argv[])
{
	return Catch::Session().run(argc,argv );
}
