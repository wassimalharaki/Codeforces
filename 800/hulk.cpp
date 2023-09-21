#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << "I hate ";

    for (int i = 1; i < n; i++)
        (i & 1)? cout << "that I love ": cout << "that I hate ";

    cout << "it";

    return 0;
}