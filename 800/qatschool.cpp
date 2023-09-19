#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    string q;
    cin >> n >> t >> q;

    loop(i, 0, t) {
        for (int i = 0; i < n - 1; ++i) {
            if (q[i] == 'B' && q[i + 1] == 'G') {
                q[i] = 'G';
                q[i + 1] = 'B';
                ++i;
            }
        }
    }

    cout << q;

    return 0;
}