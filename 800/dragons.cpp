#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    int dragons[d];
    loop(i, 0, d)
        dragons[i] = 1;

    for (int i = k; i <= d; i += k)
        dragons[i - 1] = 0;
        
    for (int i = l; i <= d; i += l)
        dragons[i - 1] = 0;
        
    for (int i = m; i <= d; i += m)
        dragons[i - 1] = 0;
        
    for (int i = n; i <= d; i += n)
        dragons[i - 1] = 0;

    int dead = 0;
    loop(i, 0, d)
        if (dragons[i] == 0)
            dead++;
    
    cout << dead;

    return 0;
}