#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
    sort (A.begin(), A.end());

    vector<int> ans;

    for (int i = 0 ; i < N ; i++){
        int l = 0;
        for (int j = i + 1 ; j < N ; j++){
            if (abs(A[i] - A[j]) <= M){
                l++;
            } else{
                break;
            }
        }
        if (l + 1 >= ans.size()) {
            ans.clear();
            for (int j = i ; j <= i + l ; j++){
                ans.push_back(A[j]);
            }
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}