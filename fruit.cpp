#include <bits/stdc++.h>
using namespace std;

// 由于数据有超出int数据范围的可能，开long long
using ll = long long;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> arr;
    for (int i = 1; i <= n; ++i)
    {
        ll value; cin >> value;
        arr.push(value);
    }

    ll ans = 0;
    while (arr.size() >= 2)
    {
        ll a = arr.top(); arr.pop();
        ll b = arr.top(); arr.pop();
        ans += a + b;
        arr.push(ans);
    }
    cout << ans << '\n';
    return 0;
}