#include <bits/stdc++.h>
using namespace std;

long long ctr = 0;

void findcombination(vector<int> &v, int a, int idx, int n){
    if(a == 0){
        ctr++;
        return;
    }

    for(int i = idx ; i < n ; i++){
        if(v[i] > a)
            break;
        findcombination(v, a - v[i], i, n);
    }
}

int main(){
    int n, a;
    cin >> n >> a;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort (v.begin(), v.end());
    findcombination(v, a, 0, n);
    cout << ctr % 1000000007 << endl;
    return 0;
}