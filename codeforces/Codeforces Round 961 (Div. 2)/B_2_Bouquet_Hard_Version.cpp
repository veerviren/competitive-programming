/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <random>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <complex>
#include <math.h>
#include <cstring>
#include <chrono>
#include <string>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define allr(X) (X).rbegin(), (X).rend()
#define sz(X) (int)X.size()
#define setbits(X) __builtin_popcountll(X)
#define fix(X) fixed << setprecision(X)
#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))
// Operator overloads <<, >>
template <typename T1, typename T2>
// cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T>
// cin >> vector
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
    {
        cin >> it;
    }
    return istream;
}

template <typename T1, typename T2>
// cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << ' ' << p.second);
}

template <typename T>
// cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
    {
        cout << it << ' ';
    };
    return ostream;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void find(int cur, int coin, pair<int, int> a, pair<int, int> b, int &ans)
{
    cur = min((coin / a.first), a.second) * a.first;
    int used1 = min((coin / a.first), a.second);
    coin -= used1 * a.first;
    cur += min((coin / b.first), b.second) * b.first;
    int used2 = min((coin / b.first), b.second);
    coin -= used2 * b.first;

    b.second -= used2;
    cur += min({used1, b.second, coin});
    ans = max(ans, cur);
}

void Jay_Shree_Krishna()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    cin >> a >> b;

    // map<int, int> mp;

    // for (auto &x : a)
    // {
    //     mp[x]++;
    // }

    vector<pair<int, int>> v;

    // for (auto &x : mp)
    // {
    //     v.push_back({x.first, x.second});
    // }

    for(int i = 0; i < n; i++)
    {
        v.push_back({a[i], b[i]});
    }

    sort(all(v));
    int ans = 0;
    if (sz(v) >= 2)
    {
        for (int i = 0; i < sz(v) - 1; i++)
        {

            int coin = m;
            int cur = 0;
            if (v[i + 1].first - v[i].first <= 1)
            {
                find(0, m, v[i], v[i + 1], ans);
            }
            ans = max(ans, min((m / v[i].first), v[i].second) * v[i].first);
        }

        ans = max(ans, min((m / v[sz(v) - 1].first), v[sz(v) - 1].second) * v[sz(v) - 1].first);
    }
    else
    {
        ans = min((m / v[0].first), v[0].second) * v[0].first;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        Jay_Shree_Krishna();
    return 0;
}