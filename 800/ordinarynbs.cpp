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

int32_t main() {
    fast

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;
        int answ = 0;
        if (n < 10) {
            cout << n nl;
            continue;
        }

        string s = to_string(n);
        answ += (s.size() - 1) * 9;
        string ones;
        for (int i = 0; i < s.size(); i++) {
            ones += "1";
        }
        answ += n / stoi(ones);

        cout << answ nl;
    }

    return 0;
}