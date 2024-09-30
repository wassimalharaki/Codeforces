#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

struct fraction {
    __int128 n, d;
    fraction() {}
    fraction(__int128 _n, __int128 _d) {
        int g = __gcd(_n, _d);
        n = _n / g, d = _d / g;
        if (d < 0) n *= -1, d *= -1;
    }
    fraction operator*(int x) {
        return fraction(n * x, d);
    }
    fraction operator+(int x) {
        return fraction(n + d * x, d);
    }
    fraction operator+(fraction& f) {
        return fraction(n * f.d + f.n * d, d * f.d);
    }
    friend bool operator==(const fraction& f1, const fraction& f2) {
        return f1.n == f2.n and f1.d == f2.d;
    }
    friend bool operator<(const fraction& f1, const fraction& f2) {
        if (f1.n == f2.n) return f1.d < f2.d;
        return f1.n < f2.n;
    }
};

struct point {
    int x, y;
    point() {}
    point(int _x, int _y) { x = _x, y = _y; }
    friend istream& operator>>(istream& in, point& p) {
        in >> p.x >> p.y;
        return in;
    }
};

struct line {
    fraction a, b;
    int x;
    bool vert = 0;
    line(point& p, point& q) {
        if (p.x - q.x == 0)
            vert = 1, x = p.x;
        else {
            a = fraction(p.y - q.y, p.x - q.x);
            b = a * - p.x + p.y;
        }
    }
    friend bool operator<(const line& l1, const line& l2) {
        if (l1.vert and l2.vert)
            return l1.x < l2.x;
        if (l1.vert) return 1;
        if (l2.vert) return 0;
        if (l1.a == l2.a)
            return l1.b < l2.b;
        return l1.a < l2.a;
    }
    fraction f(int _x) {
        return a * _x + b; 
    }
    bool belongs(point p) {
        if (vert) return x == p.x;
        fraction y = f(p.x);
        return y.d == 1 and y.n == p.y;
    }
};

void solve() {
    int n; cin >> n;

    v<point> a(n);
    for (point& p : a) cin >> p;

    if (n <= 3) {
        cout << "YES" << nl;
        return;
    }
    
    set<line> lines;
    for (int i = 1; i < n - 1; i++)
        lines.insert(line(a[i], a[i + 1]));
    
    if (lines.size() == 1) {
        cout << "YES" << nl;
        return;
    }

    auto check = [&](line l) -> bool {
        v<int> kill(n);
        for (int i = 0; i < n; i++)
            if (l.belongs(a[i]))
                kill[i] = 1;
        
        if (count(kill.begin(), kill.end(), 0) <= 1)
            return 1;
        v<int> alive;
        for (int i = 0; i < n; i++)
            if (not kill[i])
                alive.push_back(i);
        l = line(a[alive[0]], a[alive[1]]);

        for (int i = 0; i < n; i++)
            if (l.belongs(a[i]))
                kill[i] = 1;
        return count(kill.begin(), kill.end(), 0) == 0;
    };

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (check(line(a[i], a[j]))) {
                cout << "YES" << nl;
                return;
            }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}