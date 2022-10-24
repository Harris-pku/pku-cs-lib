#include <cstdio>
#include <algorithm>

using namespace std;

char c; int ans;
int main(){
	do{
		scanf("%c", &c);
		if (c == '(')
			ans++;
		if (c == ')')
			ans--;
	} while (c != '@');
	if (ans)
		printf("NO");
	else
		printf("YES");
	return 0;
}
