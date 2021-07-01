#include <bits/stdc++.h>
using namespace std;

bool is_ok(int N, int K, vector<int> &a, int len)
{
    int num = 0;
    map<int, int> cnt_map;
    for (int i = 0; i < len; ++i) {
        auto ai = a.at(i);
        ++cnt_map[ai];
        if (cnt_map.at(ai) == 1)
            ++num;
    }
    if (num <= K)
        return true;
    for (int i = 0, j = len; j < N; ++i, ++j) {
        auto ai = a.at(i);
        auto aj = a.at(j);
        --cnt_map[ai];
        if (cnt_map.at(ai) == 0)
            --num;
        ++cnt_map[aj];
        if (cnt_map.at(aj) == 1)
            ++num;
        if (num <= K)
            return true;
    }
    return false;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (auto &ai : a)
        cin >> ai;
    int ok = 0;
    int ng = N + 1;
    while (abs(ok - ng) > 1) {
        auto mid = (ok + ng) / 2;
        if (is_ok(N, K, a, mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
}
