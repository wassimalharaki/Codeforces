#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    vi cals(5);

    for (int i = 1; i < 5; i++) 
        cin >> cals[i];

    int sum= 0;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        sum += cals[s[i] - '0'];
    }

    cout << sum nl;

    return 0;
}