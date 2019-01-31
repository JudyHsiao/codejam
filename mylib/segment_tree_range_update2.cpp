#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <assert.h>

using namespace std;
typedef long long ll;
struct Node
{
	ll val, lazy;
	int left, right;
};
Node rangetree[20000000];
int upto;
int newnode()
{
	upto++;
	assert(upto < 20000000);
	rangetree[upto].val = rangetree[upto].lazy = rangetree[upto].left = rangetree[upto].right = 0;
	return upto;
}
void push(int curr, ll sz1, ll sz2)
{
	if (!rangetree[curr].left) rangetree[curr].left = newnode();
	if (!rangetree[curr].right) rangetree[curr].right = newnode();
	if (!rangetree[curr].lazy) return;
	rangetree[rangetree[curr].left].val += rangetree[curr].lazy*sz1;
	rangetree[rangetree[curr].right].val += rangetree[curr].lazy*sz2;
	rangetree[rangetree[curr].left].lazy += rangetree[curr].lazy;
	rangetree[rangetree[curr].right].lazy += rangetree[curr].lazy;
	rangetree[curr].lazy = 0;
}

// s ~ e 都加1
void update(ll s, ll e, int curr = 1, ll cstart = 0, ll cend = 1e9+10)
{
	assert(curr);
	if (s <= cstart && cend <= e)
	{
		rangetree[curr].val += cend-cstart+1;
		rangetree[curr].lazy++;
		return;
	}
	ll mid = (cstart+cend)/2;
	push(curr, mid-cstart+1, cend-mid);
	if (e <= mid) update(s, e, rangetree[curr].left, cstart, mid);
	else if (s > mid) update(s, e, rangetree[curr].right, mid+1, cend);
	else
	{
		update(s, e, rangetree[curr].left, cstart, mid);
		update(s, e, rangetree[curr].right, mid+1, cend);
	}
	rangetree[curr].val = rangetree[rangetree[curr].left].val + rangetree[rangetree[curr].right].val;
}
ll kthlargest(ll k, int curr = 1, ll cstart = 0, ll cend = 1e9+10)
{
	if (cstart == cend) return cstart;
	ll mid = (cstart+cend)/2;
	push(curr, mid-cstart+1, cend-mid);
	if (rangetree[rangetree[curr].right].val >= k) return kthlargest(k, rangetree[curr].right, mid+1, cend);
	else return kthlargest(k - rangetree[rangetree[curr].right].val, rangetree[curr].left, cstart, mid);
}

int main() {

	//interval: [3,4] [2,8] [4,8] [1,3] [7,9] 左右閉區間
	//  [9, 8, 8, 8, 7, 7, 7, 6, 6, 5, 5, 4, 4, 4, 3, 3, 3, 2, 2, 1]
	upto = 0;
	newnode();
	update(3,4);
	update(2,8);
	update(4,8);
	update(1,3);
	update(7,9);

	int i5 = kthlargest(5);

	int i1 = kthlargest(1);

	int i30 = kthlargest(30);

	cout << "5th: " << i5 << " 1st:" << i1 << " 30th:" << i30 << endl;

	upto = 0;
	newnode();
	update(3,4);
	update(2,8);
	update(4,8);
	update(1,3);
	update(7,9);

	i5 = kthlargest(5);

	i1 = kthlargest(1);

	i30 = kthlargest(30);

	cout << "5th: " << i5 << " 1st:" << i1 << " 30th:" << i30 << endl;





}