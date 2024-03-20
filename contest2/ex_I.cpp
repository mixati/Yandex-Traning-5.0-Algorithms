#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits.h>

using namespace std;

bool compare1(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}
bool compare2(vector<int>&a, vector<int>& b) {
    return a[1] < b[1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(2));

    for (int i = 0; i < n; ++i)
        cin >> arr[i][0] >> arr[i][1];

    sort(arr.begin(),arr.end(),compare1);
    sort(arr.begin(),arr.end(),compare2);

    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int s = 0;
        vector<vector<int>> b;
        for (int j = 0; j < n; ++j)
            if (arr[j][1] != i)
                b.push_back(arr[j]);

        set<int> c_;
        for (int j = 0; j < n; ++j)
            if (arr[j][1] == i)
                c_.insert(arr[j][0]);
        vector<int> x_;
        for (int j = 1; j <= n; ++j)
            if (c_.find(j) == c_.end())
                x_.push_back(j);
        sort(x_.begin(),x_.end());
        for (int j = 0; j < x_.size(); ++j) {
            s += abs(x_[j] - b[j][0]) + abs(i - b[j][1]);
        }
        // cout << b.size() << ' ' << x_.size() << endl;
        ans = min(ans, s);
    }
    cout << ans;

    return 0;
}