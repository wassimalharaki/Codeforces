#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    string s; cin >> s;
    bool z = s.find('0') != -1;

    while (1) {
        int n = s.size(), x = 0;
        array<int, 3> cnt; cnt.fill(0);
        for (char& c : s) {
            x += c - '0';
            cnt[(c - '0') % 3]++;
        }
        cnt[(s.front() - '0') % 3]--;
        x %= 3;

        if (x == 0)
            break;
        else if (x == 1) {
            if (cnt[1]) {
                string t{s[0]};
                int ok = 0;
                for (int i = 1; i < n; i++)
                    if ((s[i] - '0') % 3 == 1 and ok < 1)
                        ok++;
                    else
                        t += s[i];
                t.swap(s);
                break;
            }
            else if ((s.front() - '0') % 3 == 1 and s.size() > 1 and s[1] != '0') {
                s = s.substr(1, n - 1);
                break;
            }
            else if (cnt[2] > 1) {
                string t{s[0]};
                int ok = 0;
                for (int i = 1; i < n; i++)
                    if ((s[i] - '0') % 3 == 2 and ok < 2)
                        ok++;
                    else
                        t += s[i];
                t.swap(s);
                break;
            }
            else {
                if (s.size() == 1) {
                    cout << (z ? 0 : -1) << nl;
                    return;
                }
                reverse(s.begin(), s.end());
                s.pop_back();
                while (s.size() > 1 and s.back() == '0')
                    s.pop_back();
                reverse(s.begin(), s.end());
            }
        }
        else {
            if (cnt[2]) {
                string t{s[0]};
                int ok = 0;
                for (int i = 1; i < n; i++)
                    if ((s[i] - '0') % 3 == 2 and ok < 1)
                        ok++;
                    else
                        t += s[i];
                t.swap(s);
                break;
            }
            else if ((s.front() - '0') % 3 == 2 and s.size() > 1 and s[1] != '0') {
                s = s.substr(1, n - 1);
                break;
            }
            else if (cnt[1] > 1) {
                string t{s[0]};
                int ok = 0;
                for (int i = 1; i < n; i++)
                    if ((s[i] - '0') % 3 == 1 and ok < 2)
                        ok++;
                    else
                        t += s[i];
                t.swap(s);
                break;
            }
            else {
                if (s.size() == 1) {
                    cout << (z ? 0 : -1) << nl;
                    return;
                }
                reverse(s.begin(), s.end());
                s.pop_back();
                while (s.size() > 1 and s.back() == '0')
                    s.pop_back();
                reverse(s.begin(), s.end());
            }
        }
    }
    cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}