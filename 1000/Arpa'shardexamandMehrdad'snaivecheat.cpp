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

vi divisors(int n) {
    vi divs;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);

    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);

    return divs;
}

int32_t main() {
    fast;

    int n; cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }

    n %= 4;
    if (n == 1)
        cout << 8;
    else if (n == 2)
        cout << 4;
    else if (n == 3)
        cout << 2;
    else
        cout << 6;

    return 0;
}