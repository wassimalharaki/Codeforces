#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(Nlog(log(N)))
const int N = 4e4 + 1;
bitset<N> is_prime;
vector<int> primes;
void build() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    primes.push_back(2);
    for (int i = 4; i < N; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i < N; i += 2)
        if (is_prime[i])
            for (int j = i * i; j < N; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i < N; i += 2)
        if (is_prime[i])
            primes.push_back(i);
}

// O(d(n^p))
vector<int> gen_divisors(const vector<array<int, 2>>& pfs) {
    vector<int> divs;

    auto f = [&](int x, int i, auto&& self) -> void {
        if (i >= (int) pfs.size()) return;
        self(x, i + 1, self);
        for (int j = 0; j < pfs[i][1]; j++) {
            x *= pfs[i][0];
            divs.push_back(x);
            self(x, i + 1, self);
        }
    };
    f(1, 0, f);

    // sort(divs.begin(), divs.end());
    return divs;
}

// O(sqrt(n) / log(sqrt(n)) + d(n^p))
vector<array<int, 2>> pfs;
vector<int> divisors(int n, int p = 1) {
    if (primes.empty()) build();

    pfs.clear();
    for (const int& x : primes) {
        if (x * x > n) break;
        if (n % x) continue;
        pfs.push_back({x, 0});
        while (n % x == 0) {
            n /= x;
            pfs.back()[1] += p;
        } 
    }
    if (n != 1) pfs.push_back({n, p});
    
    return gen_divisors(pfs);
}

void solve() {
    int n; cin >> n;

    auto divs = divisors(n);
    if (pfs.size() == 1) {
        for (int& d : divs)
            cout << d << " ";
        return void(cout << nl << 0 << nl);
    }
    if (divs.size() == 3) {
        for (int& d : divs)
            cout << d << " ";
        return void(cout << nl << 1 << nl);
    }
    divs.pop_back();

    v<v<int>> ans;
    v<int> vis(divs.size());
    for (auto& [p, _] : pfs) {
        ans.push_back(v<int>());
        for (int i = 0; i < (int) divs.size(); i++)
            if (not vis[i] and divs[i] % p == 0)
                ans.back().push_back(divs[i]), vis[i] = 1;
    }
    ans.back().push_back(n);

    for (int i = 0; i < (int) ans.size(); i++) {
        int p = pfs[(i + 1) % pfs.size()][0];
        for (int& d : ans[i])
            if (d % p == 0)
                swap(d, ans[i].back());
    }

    for (auto& x : ans)
        for (int& y : x)
            cout << y << " ";
    cout << nl << 0 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}