#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int misha = max(3 * a / 10, a - a / 250 * c);
    int vasya = max(3 * b / 10, b - b / 250 * d);

    misha > vasya ?
        cout << "Misha":
        misha == vasya ?
            cout << "Tie":
            cout << "Vasya";

    return 0;
}