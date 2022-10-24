#include <cstdio>
#include <algorithm>

using namespace std;

int d[10005], price[55], sell[55];
int x, y, n, m, c, p, k, u1, u2, maxp;
int main(){
	scanf("%d%d%d", &n, &x, &y);
	while (x != -1 && y != -1){
		price[++c] = x;
		sell[c] = y;
		scanf("%d%d", &x, &y);
	}
	scanf("%d", &m);
	p = price[1];
	maxp = price[c] + sell[c] / m;
	if (n < p || n > maxp){
		printf("NO SOLUTION");
		return 0;
	}
	for (int i = 1; i < c; i++){
		k = (sell[i] - sell[i + 1]) / (price[i + 1] - price[i]);
		for (int j = price[i]; j < price[i + 1]; j++)
			d[j] = sell[i] - k * (j - price[i]);
	}
	for (int i = price[c]; i <= maxp; i++)
		d[i] = sell[c] - m * (i - price[c]);
	/*
	k1:=-1e20; k2:=1e20;
	for i:=p to most do    //�ӳɱ������
     begin
    r:=d[n]-d[i];
    t:=i*d[i]-n*d[n]-p*(d[i]-d[n]);
    if (r>0) and (t/r>k1) then
      k1:=t/r;
    if (r<0) and (t/r<k2) then
      k2:=t/r;
     end;
    if k1<-1e19 then u1:=-maxlongint         //�޽紦��
    else if (k1>0)and(k1-int(k1)>0) then u1:=trunc(k1)+1 else u1:=trunc(k1);
    if k2>1e19 then u2:=maxlongint
    else if (k2<0)and(int(k2)-k2>0) then u2:=trunc(k2)-1 else u2:=trunc(k2);
    */
	if (u1 < 0 && u2 > 0)
		u1 = u2 = 0;
	if (u1 > u2)
		printf("NO SOLUTION");
	else
		printf("%d", abs(u1) < abs(u2) ? u1 : u2);
	return 0;
}
