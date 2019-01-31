#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen ("input.txt", "r", stdin);
	freopen ("answer.txt", "w", stdout);

	int n; cin >> n;
	vector <int> a(n);
	for (int &x : a) cin >> x;

	vector <int> b (n+1, INT_MAX);
	b[0] = -INT_MAX;

	int res = 1;
	for (int x : a) {
		int k = lower_bound(b.begin(), b.end(), x) - b.begin();
		b[k] = x;
		res = max (res, k);
	}

	cout << res;

	return 0;
}