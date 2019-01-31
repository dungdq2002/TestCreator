#include <bits/stdc++.h>
using namespace std;

int Rand(int l, int r) {
	int range = r - l + 1;
	return l + (rand()%(range) + rand()%(range)) % range;
}

int main() {
	srand(time (0));
	freopen ("input.txt", "w", stdout);
	int n = Rand (90000, 100000);
	cout << n << '\n';
	for (int i = 0; i < n; i++)
		cout << Rand (1, 1000000000) << ' ';
	return 0;
}