#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define s1(i) s1[i-1]
#define s2(i) s2[i-1]
using namespace std;
void match(){
	int j=0;
	for (int i=2;i<=m;i++){
		while (j && s2(j+1)!=s2(i)) j=p[j];
		if (s2(j+1)==s2(i)) j++;
		p[i]=j;
	}
}
void kmp(){
	int j=0;
	for (int i=1;i<=n;i++){
		while (j && s2(j+1)!=s1(i)) j=p[j];
		if (s2(j+1)==s1(i)) j++;
		if (j==m) {printf("%d\n",i-m+1);j=p[j];}
	}
}

