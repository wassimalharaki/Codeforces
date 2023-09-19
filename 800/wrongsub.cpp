#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    loop(i, 0, k)
        if (n % 10 == 0)
            n /= 10;
        else
            --n;
    
    cout << n;

    return 0;
}