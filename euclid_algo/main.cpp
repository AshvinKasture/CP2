#define ONLINE_JUDGE

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

int main()
{
    file_io();
    ll a, b, c;
    cin >> a >> b;
    while (true)
    {
        c = a % b;
        if (c == 0)
        {
            cout << b << endl;
            break;
        }
        a = b;
        b = c;
    }

    return 0;
}