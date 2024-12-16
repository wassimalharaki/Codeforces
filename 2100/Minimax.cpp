#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 26;

void solve() {
    string s; cin >> s;
    int n = s.size();

    if (set<char>(s.begin(), s.end()).size() == 1)
        return void(cout << s << nl);
    
    array<int, N> cnt; cnt.fill(0);
    for (char& c : s)
        cnt[c - 'a']++;
    for (int i = 0; i < N; i++)
        if (cnt[i] == 1) {
            s.erase(s.begin() + s.find(char('a' + i)));
            sort(s.begin(), s.end());
            cout << char('a' + i) << s << nl;
            return;
        }

    char first = '.';
    for (int i = 0; i < N; i++)
        if (cnt[i]) {
            first = char('a' + i);
            s.erase(s.begin() + s.find(char('a' + i)));
            cnt[i]--;
            break;
        }
    n = s.size();
    
    for (int i = 0; i < N; i++)
        if (cnt[i]) {
            if (first - 'a' == i) {
                if (2 * cnt[i] > n + 1) continue;

                v<char> other;
                for (char& c : s)
                    if (c != first)
                        other.push_back(c);
                sort(other.rbegin(), other.rend());

                cout << first << first; cnt[i]--;

                while (cnt[i]--) {
                    cout << other.back() << first;
                    other.pop_back();
                }
                while (other.size()) {
                    cout << other.back();
                    other.pop_back();
                }

                cout << nl;
                break;
            }
            else {
                char second = char('a' + i);
                cout << first << second; cnt[i]--;

                v<array<int, 2>> b;
                for (int j = 0; j < N; j++)
                    if (cnt[j])
                        b.push_back({'a' + j, cnt[j]});
                int m = b.size();

                for (int j = 0; j < m - 1; j++)
                    if (b[j][0] == first and b[j + 1][0] == second) {
                        if (j + 2 >= m)
                            swap(b[j], b[j + 1]);
                        else {
                            b[j + 2][1]--;
                            b.insert(b.begin() + j + 1, {b[j + 2][0], 1});
                        }
                    }
                for (auto& [c, x] : b)
                    cout << string(x, char(c));
                cout << nl;
                break;
            }
        }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}