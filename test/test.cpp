#include<cstring>
#include<iostream>
//using namespace std;

int main()
{

	std::string str("waha");
	std::cout<<str.length()<<std::endl;
	return 0;
}

int sum(int& x, int& y)
{
	x = 1;
	return x+y;
}

