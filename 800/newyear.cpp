#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    int time = 240 - k;

    for (int i = 1; i <= n; i++)
        if (time - i * 5 >= 0)
            time -= i * 5;
        else {
            cout << i - 1;
            return 0;
        }

    cout << n;

    return 0;
}