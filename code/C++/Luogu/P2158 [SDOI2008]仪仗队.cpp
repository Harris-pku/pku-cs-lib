#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int phi[40005];
int n, ans = 1;
int main(){
  cin >> n; n--;
  phi[1] = 1;
  for (int i = 2; i <= n; i++){
      if (!phi[i])
          for (int j = i; j <= n; j += i){
              if (!phi[j])
              phi[j] = j;
          phi[j] = phi[j] / i * (i - 1);
        }
    ans += phi[i];
  }
  cout << ans * 2 + 1;
  return 0;
}
