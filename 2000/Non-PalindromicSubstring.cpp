#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

vector<int> manacher_odd(string& s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if(i + p[i] > r)
            l = i - p[i], r = i + p[i];
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string& s) {
    string t;
    for(char& c: s) t += string{'#', c};
    t += '#';
    vector<int> res = manacher_odd(t);
    return vector<int>(begin(res) + 1, end(res) - 1);
}

int op(int a, int b) {
    return max(a, b);
}

template <class S, S (*op)(S, S)>
struct sparse_table {
    const int n = 25;
    vector<vector<S>> d;

    sparse_table(vector<S>& nums) {
        d = vector<vector<S>>(n + 1, vector<S>(nums.size()));
        copy(nums.begin(), nums.end(), d[0].begin());

        for (int i = 1; i <= n; i++)
            for (int j = 0; j + (1 << i) <= nums.size(); j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    
    vector<vector<int>> prefix(n + 1, vector<int>(26));
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i];
        prefix[i + 1][s[i] - 'a']++;
    }

    vector<int> use(n - 1);
    for (int i = 0; i < n - 1; i++)
        use[i] = (s[i] == s[i + 1]);
    sparse_table<int, op> tble(use);

    v<int> man = manacher(s);
    auto is_pal = [&](int l, int r) {
        return man[l + r] - 1 >= r - l + 1;
    };

    while (q--) {
        int l, r; cin >> l >> r;
        int size = r - l + 1;
        l--, r--;

        int cnt = 0;
        for (int i = 0; i < 26; i++)
            if (prefix[r + 1][i] - prefix[l][i] > 0)
                cnt++;
        
        if (cnt == 1)
            cout << 0 << nl;
        else if (cnt == 2 and tble.prod(l, r) == 0) {
            size -= size & 1;
            cout << (2ll + size) * (size / 2) / 2 << nl;
        }
        else {
            int x = is_pal(l, r) * size;
            cout << (2ll + size) * (size - 1) / 2 - x << nl;
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