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

ll nmatches_table(string text, string pattern)
{
    ll t = text.length();
    ll p = pattern.length();
    vector<vector<ll>> dp;
    for (ll i = 0; i < p + 1; i++)
    {
        vector<ll> shortArray;
        for (ll j = 0; j < t + 1; j++)
        {
            shortArray.push_back(0);
        }
        dp.push_back(shortArray);
    }

    for (ll i = 0; i < dp[0].size(); i++)
    {
        dp[0][i] = 1;
    }

    for (ll ip = 0; ip < p; ip++)
    {
        ll matches = 0;
        for (ll it = ip; it < t; it++)
        {
            if (text.substr(it, 1) == pattern.substr(ip, 1))
            {
                matches += dp[ip][it];
            }
            dp[ip + 1][it + 1] = matches;
        }
    }

    // cout << "DP last line is " << endl;
    // for (ll i = 0; i < dp.back().size(); i++)
    // {
    //     cout << dp.back()[i] << " ";
    // }
    // cout << endl;
    // cout << "Maximum would be ";
    return *max_element(dp.back().begin(), dp.back().end());
}

int main()
{
    file_io();
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        string text, pattern;
        cin >> text >> pattern;
        cout << nmatches_table(text, pattern) << endl;
    }
    return 0;
}