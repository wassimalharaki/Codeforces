#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> shoes;
    
    for (int i = 0; i < 4; i++) {
        int a; cin >> a;
        shoes.insert(a);
    }
    
    cout << 4 - shoes.size();

    return 0;
}