#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> tab(n + 1);
    for (int i = 0; i <= n; i++)
        tab[i] = 0;

    for (int i = 0 ; i < n ; i++) {
        if (a[i] > sqrt(n))
            break;
        
        for (int j = i + 1 ; j < n ; j++) {
            if (a[i] * a[j] > n) 
                break;
            
            tab[a[i] * a[j]]++;
        }
    }

    int l, r, ctr;
    for (int i = 0 ; i < m ; i++) {
        cin >> l >> r;
        ctr = 0;
        for (int i = l ; i <= r ; i++)
            ctr += tab[i];
        cout << ctr << endl;
    }
    return 0;
}
