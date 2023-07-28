#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    vector<bool> visited(N, false);
    for (int i = 0 ; i < N ; i++){ 
        cin >> A[i];
        A[i]--;
    }

    int acyclic = 0;
    int cyclic = 0;

    for (int i = 0 ; i < N ; i++){
        if (!visited[i]){
            int idx = i;
            int p1 = i;
            int p2 = -1;
            while (!visited[idx]){
                visited[idx] = true;
                p2 = p1;
                p1 = idx;
                idx = A[idx];
            }
            if (idx == p2){
                acyclic++;
            }
            else if (idx == i){
                cyclic++;
            }
        }
    }
    if (acyclic > 0){
        cout << cyclic + 1 << " " << acyclic + cyclic << endl;
    } else {
        cout << cyclic << " " << acyclic + cyclic << endl;
    }
    return 0;
}