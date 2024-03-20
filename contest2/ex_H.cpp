#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int get_max_exept(vector<vector<int>>& races_classes, int& x, int& y) {
    int max_ = -1;
    for (int i = 0; i < races_classes.size(); ++i)
        for (int j = 0; j < races_classes[i].size(); ++j)
            if (i != x && j != y && max_ < races_classes[i][j])
                max_ = races_classes[i][j];
    return max_;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> races_classes(n, vector<int>(m, 0));
    vector<vector<int>> maxis(n, vector<int>(m,0));
    int x = -1,
        y = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> races_classes[i][j];
        }
    }

    int max_other = INT_MAX;
    pair<int,int> ans = {-1,-1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp = get_max_exept(races_classes, i, j);
            if (tmp < max_other) {
                max_other = tmp;
                ans = {i,j};
            }
        }
    }

    cout << ans.first + 1 << ' ' << ans.second + 1;

    return 0;
}