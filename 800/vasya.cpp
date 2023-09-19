#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, mini;
    cin >> a >> b;
    mini = min(a, b);

    cout << mini << " ";

    a -= mini;
    b -= mini;

    cout << (a + b) / 2;

    return 0;
}