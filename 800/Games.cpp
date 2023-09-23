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

    int n, counter = 0; cin >> n;

    vi home(n);
    vi guest(n);

    for (int i = 0; i < n; i++)
        cin >> home[i] >> guest[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (home[i] == guest[j])
                counter++;

    cout << counter;

    return 0;
}