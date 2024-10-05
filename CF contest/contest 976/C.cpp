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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int b, c, d;
        cin >> b >> c >> d;
        int a = 0;
        bool flag = true;
        for (int i = 0; i < 64; i++)
        {
            int bit_a = 0;

            int bit_d = (d & 1);
            d >>= 1;

            int bit_c = (c & 1);
            c >>= 1;

            int bit_b = (b & 1);
            b >>= 1;

            if (bit_d)
            {
                if (bit_b == 0 && bit_c == 1)
                {
                    flag = false;
                    break;
                }
                bit_a = (bit_b ^ 1);
            }
            else
            {
                if (bit_b == 1 && bit_c == 0)
                {
                    flag = false;
                    break;
                }
                bit_a = (bit_b);
            }
            // (one<<i)  = 2^i
            a += (one << i) * (bit_a);
        }
        if (flag == false)
            cout << -1 << "\n";
        else
            cout << a << "\n";
    }
    return 0;
}
