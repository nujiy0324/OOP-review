#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int sum(int x,int y);
	int (*p) (int, int);
	p = sum;
	int a = 2, b = 3;
	cout<<p(a,b);
	return 0;
}
int sum(int x, int y)
{
	return x+y;
}
