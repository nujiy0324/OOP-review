#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int sum(int& x,int& y);
	//int (*p) (int, int);
	//p = sum;
	int a = 2, &b = a;
	cout<<a<<" "<<b<<endl;
	b = 3;
	cout<<a<<endl;
	cout<<sum(a,b)<<endl;
	cout << b ;
	return 0;
}

int sum(int& x, int& y)
{
	x = 1;
	return x+y;
}

