#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

set<int> s; int a[15];
int main(){
    for (int i = 10; i >= 1; --i)
        s.insert(i);
    for (int i = 10; i >= 1; --i)
        a[i] = 11 - i;
    printf("size = %d\n", s.size());
    /*if (s.count(4)){
        s.erase(4);
    }*/
    
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        printf("%d ", *it);
	printf("\n");
	
    for (int i = 1; i <= 10; ++i)
        printf("%d ", *(a+i));
    printf("\n");
    
    printf("size = %d\n", s.size());
    if (s.empty()){
        printf("s is empty\n");
    }
    else printf("s is not empty\n");
    s.clear();
    if (s.empty()){
        printf("s is empty\n");
    }
    else printf("s is not empty\n");

}
