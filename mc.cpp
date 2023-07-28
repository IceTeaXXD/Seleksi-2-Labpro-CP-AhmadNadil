#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& v, int x) {
    int m = v.size();
    vector<int> table(x + 1, INT_MAX);
    table[0] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = x ; j >= v[i]; j--) {
            if (table[j - v[i]] != INT_MAX) {
                table[j] = min(table[j], table[j - v[i]] + 1);
            }
        }
    }

    if (table[x] == INT_MAX) {
        return -1;
    }
    return table[x];
}

int main() {
    int x,n;
    cin >> x >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << find(v, x) << endl;
    return 0;
}