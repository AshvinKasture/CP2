// #define ONLINE_JUDGE

#include <bits/stdc++.h>

#define ll long long int
#define ld long double

using namespace std;

void file_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

pair<ll, ll> getCordinates(ll no)
{
    if (sqrt(no) == (float)((int)sqrt(no)))
    {
        if ((int)sqrt(no) % 2 == 0)
        {
            return pair<ll, ll>(sqrt(no), 1);
        }
        else
        {
            return pair<ll, ll>(1, sqrt(no));
        }
    }
    ll base, diff, mod, mod2, x, y;
    base = ((int)(sqrt(no))) + 1;
    diff = (base * base) - no;
    mod = (2 * base) - 1;
    mod2 = mod / 2;
    if (base % 2 == 1)
    {
        if (diff > mod2)
        {
            x = base;
            y = mod - diff;
        }
        else
        {
            y = base;
            x = diff + 1;
        }
    }
    else
    {
        if (diff > mod2)
        {
            y = base;
            x = mod - diff;
        }
        else
        {
            x = base;
            y = diff + 1;
        }
    }
    return pair<ll, ll>(x, y);
}

int main()
{
    file_io();
    ll no;
    while (true)
    {
        cin >> no;
        if (no == 0)
        {
            break;
        }
        pair<ll, ll> ans = getCordinates(no);
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}