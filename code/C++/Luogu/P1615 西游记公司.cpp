#include <cstdio>

using namespace std;

long long g, s1, f1, m1, s2, f2, m2;
int main(){
    scanf("%lld:%lld:%lld%lld:%lld:%lld%lld", &s1, &f1, &m1, &s2, &f2, &m2, &g);
    printf("%lld", ((s2-s1) * 3600 + (f2-f1) * 60 + m2 - m1) * g);
}
