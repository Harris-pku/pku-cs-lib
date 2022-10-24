#include<cstdio>
using namespace std;
int buf[15];
void writeln(int i){
	int p=0;
	if (i<0) {putchar('-');i=-i;}
	while (i) {buf[p++]=i%10;i/=10;}
	while (p) putchar('0'+buf[--p]);
	putchar('\n');
}
int read(){
	char c;int f=1,x=0;
	while (c=getchar(),(c < '0' || c > '9') && c != '-');
	if (c=='-') f=-1;else x=c-'0';
	while (c=getchar(),c >= '0' && c <= '9') x=x*10+c-'0';
    return f*x;
}
int main(){
	int i;
	while (i=read()) writeln(i);
}
