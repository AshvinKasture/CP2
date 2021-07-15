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

int main()
{
    file_io();
    ll nbulbs;
    ll factors;
    while (true)
    {
        factors = 0;
        cin >> nbulbs;
        if (nbulbs == 0)
            break;
        for (ll i = 1; i <= nbulbs; i++)
        {
            if (nbulbs % i == 0)
                factors++;
        }
        // cout << factors << endl;
        if (factors % 2 == 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}