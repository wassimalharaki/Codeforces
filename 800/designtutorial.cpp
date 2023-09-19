#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if (n % 2 == 0)
        cout << 4 << " " << n - 4;
    else
        cout << 9 << " " << n - 9;

    return 0;
}