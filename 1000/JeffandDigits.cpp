#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int n; cin >> n;
    int fives = 0, zeroes = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a == 5 ? fives++ : zeroes++;
    }

    if (not zeroes) {
        cout << -1 nl;
        return 0;
    }

    if (fives / 9 == 0) {
        cout << 0 nl;
        return 0;
    }

    for (int i = 0; i < fives / 9; i++)
        cout << "555555555";
    for (int i = 0; i < zeroes; i++)
        cout << 0;

    return 0;
}