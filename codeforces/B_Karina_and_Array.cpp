/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include <bits/stdc++.h>
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
    int n;
    cin >> n;

    vector<int> v(n), neg, pos;
    bool zero = false;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x < 0)
        {
            neg.push_back(x);
        }
        else if(x > 0){
            pos.push_back(x);
        }
        else{
            zero = true;
        }
    }

    sort(all(neg));
    sort(all(pos));

    int ans1 = 0, ans2 = 0;
    bool ok1 = false, ok2 = false;
    if(neg.size() >= 2)
    {
        ok1 = true;
        ans1 = neg[0]*neg[1];
    }

    if(pos.size() >= 2)
    {
        ok2 = true;
        ans2 = pos[pos.size() - 1]*pos[pos.size() - 2];
    }



    if(!ok1 && !ok2 && zero)
    {
        cout << 0 << endl;
        return;
    }
    // cout << ok1 << " " << ok2 << endl;
    if(!ok1 && !ok2){
        cout << neg[0] * pos[0] << endl;
        return;
    }

    cout << max(ans1, ans2) << endl;
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