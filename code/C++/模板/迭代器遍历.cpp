#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<map> 
using namespace std;
int main()
{
	map<int,int> ma;
	ma[5]=6;ma[6]=7;
	map<int,int>::iterator it=ma.begin();
	for (;it!=ma.end();it++)
	{
		int t=it->second;
		cout<<t<<endl;
	}
}

