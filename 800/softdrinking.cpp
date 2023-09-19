#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l, c, d, p, nl, np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int slices = c * d;
    int grams = p / np;
    int drink = k * l / nl;

    cout << min(slices, min(grams, drink)) / n;

    return 0;
}