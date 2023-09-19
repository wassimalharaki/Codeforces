#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n, sum = 0;
    cin >> n;

    sum = 0;

    if (n % 2 == 1)
        sum = - ( n + 1 ) / 2;
    else
        sum = n / 2;
    
    cout << sum;

    return 0;
}