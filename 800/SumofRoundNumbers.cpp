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

int biggestRound(int n) {
    string s = to_string(n);
    return (n / (int) pow(10, s.size() - 1)) * (int) pow(10, s.size() - 1);
}

int32_t main() {
    fast;

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        string s = to_string(n);
        int k = s.size();
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
                k--;
        cout << k nl;

        while (n != 0) {
            int round = biggestRound(n);
            cout << round << " ";
            n -= round;
        }
        cout nl;
    }

    return 0;
}