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

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "Tetrahedron")
            counter += 4;
        else if (s == "Cube")
            counter += 6;
        else if (s == "Octahedron")
            counter += 8;
        else if (s == "Dodecahedron")
            counter += 12;
        else if (s == "Icosahedron")
            counter += 20;
    }

    cout << counter;

    return 0;
}