#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << 1;
    else
        cout << round(log((float) b / a) / log(1.5) + 0.51);

    return 0;
}