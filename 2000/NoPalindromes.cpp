#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

vector<int> manacher(string& t) {
    string s{'$'};
    for(char& c: t) s += string{'#', c};
    s += string{'#', '^'};

    int n = s.size() - 2, l = 1, r = 1;
    vector<int> p(n + 2);
    for(int i = 1; i <= n; i++) {
        p[i] = max(0ll, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if(i + p[i] > r)
            l = i - p[i], r = i + p[i];
        p[i]--;
    }
    return vector<int>(begin(p) + 2, end(p) - 2);
}

bool is_palindrome(vector<int>& man, int l, int r) {
    return man[l + r] >= r - l + 1;
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    v<int> man = manacher(s);
    if (not is_palindrome(man, 0, n - 1)) {
        cout << "YES\n1\n" << s << nl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (is_palindrome(man, 0, i)) continue;
        if (is_palindrome(man, i + 1, n - 1)) continue;

        cout << "YES\n2\n";
        cout << s.substr(0, i + 1) << " " << s.substr(i + 1, n - (i + 1)) << nl;
        return;
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}