#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
const int maxn = 1000000;
using namespace std;
struct Node{int val, pos;};
Node q1[maxn], q2[maxn];
int n, k, num, cur;int head1, tail1, head2, tail2;
int cur1[maxn], cur2[maxn];

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++){
		scanf("%d",&num);
		
		while (head1 < tail1 && q1[tail1 - 1].val >= num) --tail1;
		q1[tail1].val = num;q1[tail1++].pos = i;
		
		while (head2 < tail2 && q2[tail2 - 1].val <= num) --tail2;
		q2[tail2].val = num;q2[tail2++].pos = i;
	}
	for (int i=k+1;i<=n;i++){
		cur1[++cur] = q1[head1].val;
		cur2[cur] = q2[head2].val;
		
		scanf("%d",&num);
		
		while (head1 < tail1 && i - q1[head1].pos >= k) ++head1;
		while (head1 < tail1 && q1[tail1 - 1].val >= num) --tail1;
		q1[tail1].val = num;q1[tail1++].pos = i;
		
		while (head2 < tail2 && i - q2[head2].pos >= k) ++head2;
		while (head2 < tail2 && q2[tail2 - 1].val <= num) --tail2;
		q2[tail2].val = num;q2[tail2++].pos = i;
	}
	cur1[++cur] = q1[head1].val;
	cur2[cur] = q2[head2].val;
	
	for (int i=1;i<=n-k+1;i++) printf("%d ",cur1[i]);
	printf("\n");
	for (int i=1;i<=n-k+1;i++) printf("%d ",cur2[i]);
	
	return 0;
}
