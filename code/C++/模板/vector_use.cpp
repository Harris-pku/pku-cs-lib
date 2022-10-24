#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;
int main(){
    for (int i = 1; i <= 10; ++i)
        v.push_back(i);
    printf("size = %d\n", v.size());
    printf("%d\n", v[4]);

    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);

    if (v.empty()){
        printf("v is empty\n");
    }
    else printf("v is not empty\n");
    v.clear();
    if (v.empty()){
        printf("v is empty\n");
    }
    else printf("v is not empty\n");
}
