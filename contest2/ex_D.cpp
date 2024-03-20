#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> arr(10,vector<int>(10,0));
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
    }

    int ans = 0;
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};

    for (int i = 1; i < 9; ++i)
        for (int j = 1; j < 9; ++j)
            if (arr[i][j] == 1)
                for (int k = 0; k < 4; ++k)
                    if (arr[i+dx[k]][j+dy[k]] == 0)
                        ++ans;
    cout << ans;
    
    return 0;
}