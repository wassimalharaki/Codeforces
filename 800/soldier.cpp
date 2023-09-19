#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int price, money, amount;
    cin >> price >> money >> amount;

    int total = (1 + amount) * amount * price / 2;

    if (total <= money)
        cout << 0;
    else
        cout << total - money;

    return 0;
}