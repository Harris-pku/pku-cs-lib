#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Cow{
    long long time, num;
    bool operator < (const Cow & x) const{
        return time*x.num < x.time*num;
    }
}cow[100005];
long long ans, T; int n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &cow[i].time, &cow[i].num);
    sort(cow+1, cow+n+1);
    for (int i = 1; i <= n; ++i){
		ans += T*cow[i].num; T += cow[i].time*2;
	}
	printf("%lld", ans);
    return 0;
}
