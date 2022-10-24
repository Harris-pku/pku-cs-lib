#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
	int x, y, xy;
}mini[1005];
int sum[2005] = {0,1}, add[2005], ans[2005];
int n, tot = 1, lenadd = 1, lenans = 1;
int cmp(Node a,Node b){
	return a.xy < b.xy;
}
void cheng(int cur){
	memset(add, 0, sizeof add);
	for (int i = 1; i <= tot; ++i){
		sum[i] *= cur;
		add[i+1] += sum[i] / 1000;
		sum[i] %= 1000;
	}
	for(int i = 1; i <= tot+4; ++i) {
        sum[i] += add[i];
        sum[i+1] += sum[i] / 1000;
        sum[i] %= 1000;
        if(sum[i]){
            tot = max(tot, i);
        } 
    }
}
void division(int cur){
	memset(add, 0, sizeof add);
	lenadd = 1; int x = 0;
	for (int i = tot; i >= 1; --i){
		x = 1000*x + sum[i];
		add[i] = x/cur;
		x %= cur;
		if (lenadd==1 && add[i]){
			lenadd = i;
		} 
	}
}
int check(){
	if (lenadd > lenans) return 1;
	if (lenadd < lenans) return 0;
	for (int i = lenadd; i >= 1; --i){
		if (add[i] > ans[i]) return 1;
		if (ans[i] > add[i]) return 0;
	}
	return 0;
}
void change(){
	memset(ans, 0, sizeof ans); 
	for (int i = lenadd; i >= 1; --i){
		ans[i] = add[i];
	}
	lenans = lenadd;
	return;
}
void printt(){
	printf("%d", ans[lenans]);
	for (int i = lenans-1; i >= 1; --i){
		printf("%03d", ans[i]);
	}
	printf("\n");
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i){
		scanf("%d%d", &mini[i].x, &mini[i].y);
		mini[i].xy = mini[i].x * mini[i].y;
	}
	sort(mini+1, mini+n+1, cmp);
	for (int i = 1; i <= n; ++i){
		cheng(mini[i-1].x);
		division(mini[i].y);
		if (check()) change();
	}
	printt();
	return 0;
}
