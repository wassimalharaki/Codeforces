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

    int T; cin >> T;
    
    while (T--) {
        string s; cin >> s;
        int n = s.size();

        auto balanced = [&]() -> bool {
            int ab = 0, ba = 0;
            for (int i = 0; i < n - 1; i++)
                if (s[i] == 'a' and s[i + 1] == 'b')
                    ab++;
                else if (s[i] == 'b' and s[i + 1] == 'a')
                    ba++;
            return ab == ba;
        };

        if (not balanced())
            for (int i = 0; i < n; i++) {
                char curr = s[i], next;
                curr == 'a' ? next = 'b' : next = 'a';
                s[i] = next;
                if (balanced())
                    break;
                s[i] = curr;
            }
        cout << s nl;
    }

    return 0;
}