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

    int r, c; cin >> r >> c;
    v<vi> cake(r, vi(c, 1));

    vi rows(r); vi cols(c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            char c; cin >> c;
            if (c == 'S')
                rows[i] = 1, cols[j] = 1;
        }
    
    int count = 0;
    for (int i = 0; i < r; i++) {
        if (rows[i])
            continue;
        count += c;
        fill(all(cake[i]), 0);
    }
    for (int j = 0; j < c; j++) {
        if (cols[j])
            continue;
        for (int i = 0; i < r; i++)
            if (cake[i][j])
                count++;
    }
    cout << count;

    return 0;
}