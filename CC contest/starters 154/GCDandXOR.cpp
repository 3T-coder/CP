#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define po pop_back
#define mp make_pair
#define int long long
#define f first
#define se second
#define be begin
#define en end
#define all(X) (X).begin(), (X).end()
// #define pbds tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
int mod = pow(10, 9) + 7;
int INF = pow(10, 18);
int one = 1;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// using namespace __gnu_pbds;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// cout<<"Case #"<<c<<": ";

void input(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
        cin >> v[i];
    return;
}

void tellme(bool ok)
{
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * number of ways asking ? go with DP
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * If code of any problem getting very complex, then your approach is wrong.
 */

/*
     IMPORTANT OF ALL

   * HAVE CONFIDENCE THAT YOU CAN DO IT, YOU WILL.

*/

// for finding (a^b)%c.
int modPow(int a, int b, int c)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return modPow((a * a) % c, b / 2, c);
    else
        return ((a % c) * modPow((a * a) % c, b / 2, c)) % c;
}

// for computing (p/q)%mod
int modfrac(int p, int q, int m)
{
    int x = p % m;
    int y = modPow(q, m - 2, m);
    int ans = (x * y) % m;
    return ans;
}

bool same(vector<int> v, int k)
{
    for (auto e : v)
    {
        if (e != k)
            return false;
    }
    return true;
}

bool gcd(vector<int> v, int k)
{
    for (auto e : v)
    {
        if (__gcd(e, k) != k)
            return false;
    }
    return true;
}

bool Xor(vector<int> v, int k)
{
    int z, id;
    for (int i = 0; i < v.size(); i++)
    {
        int e = v[i];
        if (e != k)
        {
            z = (e ^ k);
            id = i;
            break;
        }
    }

    // Right
    for (int i = id; i < v.size(); i++)
    {
        if (v[i] == k)
            break;
        v[i] = (z ^ v[i]);
    }
    // Left
    for (int i = id - 1; i >= 0; i--)
    {
        if (v[i] == k)
            break;
        v[i] = (z ^ v[i]);
    }
    return (same(v, k));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        input(v, n);
        if (same(v, k))
        {
            cout << 0 << "\n";
            continue;
        }

        if (gcd(v, k) || Xor(v, k))
        {
            cout << 1 << "\n";
            continue;
        }

        cout << 2 << "\n";
    }
    return 0;
}
