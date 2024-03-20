#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,pair<long long,long long>>> berries(n);
    
    for (int i = 0; i < n; ++i) {
        long long a,b;
        cin >> a >> b;
        berries[i].first = i+1;
        berries[i].second.first = a - b;
        berries[i].second.second = a;
    }
    vector<pair<int,pair<long long,long long>>> sorted;
    int max_berry_index = -1;
    long long positiv = 0;
    long long max_height;
    for (int i = 0; i < n; ++i)
        if (berries[i].second.first > 0) {
            sorted.push_back(berries[i]);
            positiv += berries[i].second.first;            
        }
    for (int i = 0; i < sorted.size(); ++i) {
        long long max_if_last = positiv - sorted[i].second.first + sorted[i].second.second;
        if (max_if_last > max_height) {
            max_height = max_if_last;
            max_berry_index = i;
        }
    }
    if (max_berry_index != -1)
        swap(sorted[sorted.size()-1],sorted[max_berry_index]);
    
    vector<pair<int,pair<long long,long long>>> neg_sorted;
    max_berry_index = 0;
    for (int i = 0; i < n; ++i)
        if (berries[i].second.first <= 0) {
            neg_sorted.push_back(berries[i]);
            if (neg_sorted[neg_sorted.size()-1].second.second > neg_sorted[max_berry_index].second.second)
                max_berry_index = neg_sorted.size()-1;
        }
    if (neg_sorted.size())
        swap(neg_sorted[0],neg_sorted[max_berry_index]);

    for (int i = 0; i < neg_sorted.size(); ++i)
        sorted.push_back(neg_sorted[i]);

    long long sums = sorted[0].second.second;
    max_height = sorted[0].second.second;
    for (int i = 1; i < sorted.size(); ++i) {
        sums = sums - sorted[i-1].second.second + sorted[i-1].second.first + sorted[i].second.second;
        max_height = max(max_height, sums);
    }
    cout << max_height << endl;
    for (int i = 0; i < sorted.size(); ++i) {
        cout << sorted[i].first << ' ';
    }
    return 0;
}