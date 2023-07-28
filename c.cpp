#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<pair<int,int>> intervals;
    vector<int> starts;
    vector<int> stops;
    for (int i = 0 ; i < N ; i++){
        int l,r;
        cin >> l >> r;
        intervals.push_back({l,r});
        starts.push_back(l);
        stops.push_back(r);
    }

    sort(starts.begin(), starts.end());
    sort(stops.begin(), stops.end());

    vector<int> ans;
    for (int i = 0 ; i < N ; i++){
        int left = upper_bound(starts.begin(), starts.end(), intervals[i].second) - starts.begin();
        int right = lower_bound(stops.begin(), stops.end(), intervals[i].first) - stops.begin();
        ans.push_back(max(0, left - right) - 1);
    }

    for (int i = 0 ; i < N ; i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}