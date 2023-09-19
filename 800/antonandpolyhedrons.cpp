#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int counter = 0;
    string s;
    string tetra = "Tetrahedron";
    string cube = "Cube";
    string octa = "Octahedron";
    string dode = "Dodecahedron";
    string ico = "Icosahedron";

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == tetra)
            counter += 4;
        else if (s == cube)
            counter += 6;
        else if (s == octa)
            counter += 8;
        else if (s == dode)
            counter += 12;
        else if (s == ico)
            counter += 20;
    }

    cout << counter;

    return 0;
}