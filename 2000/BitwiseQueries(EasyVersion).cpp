#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector


int ask_and(int i, int j) {
	cout << "AND " << i + 1 << " " << j + 1 << endl;
    int x; cin >> x;
	return x;
}

int ask_xor(int i, int j) {
	cout << "XOR " << i + 1 << " " << j + 1 << endl;
    int x; cin >> x;
	return x;
}

void ans(vector<int>& a) {
	cout << "! ";
	for (int& x : a)
        cout << x << " ";
	cout << endl;
}

void solve() {
    int n; cin >> n;

    vector<int> ok(n);
    int x = 0, y = 1, z = 2;
    int xXORy = ask_xor(x, y);
    int xANDy = ask_and(x, y);
    int yANDz = ask_and(y, z);
    int xXORz = ask_xor(x, z);
    int xANDz = ask_and(x, z);
    int yXORz = xXORy ^ xXORz;

    int a = xXORy + 2 * (xANDy);
    int b = yXORz + 2 * (yANDz);
    int c = xXORz + 2 * (xANDz);
    ok[z] = (c + b - a) / 2;
    ok[x] = c - ok[z];
    ok[y] = b - ok[z];

    for (int i = 3; i < n; i++)
        ok[i] = ask_xor(x, i) ^ ok[x];
    ans(ok);
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
}