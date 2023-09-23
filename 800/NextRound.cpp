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

    int n, k; cin >> n >> k;

    vi grades(n);

    for (int i = 0; i < n; i++)
        cin >> grades[i];

    int nb = 0;

    for (int i = 0; i < n; i++)
        if (grades[i] >= grades[k - 1] && grades[i] > 0)
            nb++;
        else
            break;

    cout << nb;
    return 0;
}