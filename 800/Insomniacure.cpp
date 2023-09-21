#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast

    int k, l, m, n, d; cin >> k >> l >> m >> n >> d;
    vi dragons(d, 1);

    for (int i = k; i <= d; i += k)
        dragons[i - 1] = 0;
        
    for (int i = l; i <= d; i += l)
        dragons[i - 1] = 0;
        
    for (int i = m; i <= d; i += m)
        dragons[i - 1] = 0;
        
    for (int i = n; i <= d; i += n)
        dragons[i - 1] = 0;

    int dead = 0;
    for (int i = 0; i < d; i++)
        if (dragons[i] == 0)
            dead++;
    
    cout << dead;

    return 0;
}