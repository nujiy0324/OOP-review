#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	//int sum(int x,int y);
	//int (*p) (int, int);
	//p = sum;
	int a = 2, &b = a;
	cout<<a<<" "<<b<<endl;
	b = 3;
	cout<<a;
	return 0;
}
/*
int sum(int x, int y)
{
	return x+y;
}
*/
