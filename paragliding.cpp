#include <stdio.h>
#include <limits.h>
#include <algorithm>

const int MAXN = 100005;
const int MAXK = 100005;

void read_arr(int *a, int n) {
	int A, B, C, M;
	scanf("%d%d%d%d%d%d", a + 1, a + 2, &A, &B, &C, &M);
	for (int i = 3; i <= n; i++) {
		a[i] = (1LL * A * a[i - 1] + 1LL * B * a[i - 2] + C) % M + 1;
	}
}

int p[MAXN], h[MAXN];
int x[MAXK], y[MAXK];

int t_x[MAXN], t_y[MAXN];
int b_x[MAXK], b_y[MAXK];

int ids_t[MAXN], ids_b[MAXK];

bool cmp_t(int i, int j) {
	return t_x[i] < t_x[j];
}

bool cmp_b(int i, int j) {
	return b_x[i] < b_x[j];
}

int solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	read_arr(p, n);
	read_arr(h, n);
	read_arr(x, k);
	read_arr(y, k);
	
	for (int i = 1; i <= n; i++) {
		ids_t[i] = i;
		t_x[i] = p[i] - h[i];
		t_y[i] = p[i] + h[i];
	}
	for (int i = 1; i <= k; i++) {
		ids_b[i] = i;
		b_x[i] = x[i] - y[i];
		b_y[i] = x[i] + y[i];
	}
	std::sort(ids_t + 1, ids_t + n + 1, cmp_t);
	std::sort(ids_b + 1, ids_b + k + 1, cmp_b);
	
	int idx = 1;
	int max_y = INT_MIN;
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		while (idx <= n && t_x[ids_t[idx]] <= b_x[ids_b[i]]) {
			max_y = std::max(max_y, t_y[ids_t[idx]]);
			++idx;
		}
		ans += max_y >= b_y[ids_b[i]];
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
}
