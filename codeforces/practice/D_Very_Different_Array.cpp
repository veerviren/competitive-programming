/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include <bits/stdc++.h>
#include <iostream>
#include <map>
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
#define input(a, n) for(int i=0;i<n;i++){cin>>a[i];}
// Operator overloads <<, >>
template<typename T1, typename T2>
// cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T>
// cin >> vector
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) { cin >> it; }
    return istream;
}

template<typename T1, typename T2>
// cout << pair 
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << ' ' << p.second); }

template<typename T>
// cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c) { cout << it << ' '; };
    return ostream;
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    input(a, n);
    input(b, m);

    sort(all(b));
    sort(all(a));

    int st1 = 0;
    int ed1 = n - 1;
    int st2 = 0;
    int ed2 = m - 1;

    int ans1 = 0;
    for(int i = 0; i < n; i++) {
        
        int temp1 = abs(a[st1] - b[ed2]);
        int temp2 = abs(a[ed1] - b[st2]);

        if(temp1 > temp2) {
            ans1 += temp1;
            st1++;
            ed2--;
        } else {
            ans1 += temp2;
            ed1--;
            st2++;
        }
    }

    cout << ans1 << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
	cin >> t;
    while (t--) solve();
    return 0;
}