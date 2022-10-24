#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int l, r, mid;
int a[10] = {1, 1, 2, 2, 2, 2, 3, 3, 4};
int main(){
    cout << lower_bound(a, a+9, 2) - a << endl;
    cout << upper_bound(a, a+9, 2) - a << endl;

    int l = 0, r = 8, mid;
    while (l < r){
        mid = (l+r+1) >> 1;
        if (can(mid)) l = mid;
        else r = mid - 1;
    }

    l = 0; r = 8;
    while (l < r){
		mid = (l+r) >> 1;
	 	if (can(mid)) r = mid;
	 	else l = mid+1;
	}
}
