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

    int n; cin >> n;
    string s; cin >> s;

    map<string, int> pairs;
    for (int i = 0; i < n - 1; i++)
        pairs[string{s[i], s[i + 1]}]++;
    
    int max = -1;
    string answ;
    for (auto it = pairs.begin(); it != pairs.end(); it++)
        if (it -> second > max) {
            max = it -> second;
            answ = it -> first;
        }
    cout << answ;

    return 0;
}