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

ll getLCM(ll no1, ll no2)
{
    if (no1 % no2 == 0)
        return no2;
    else if (no2 % no1 == 0)
        return no1;
    else
        return no1 * no2;
}

int main()
{
    file_io();
    ll n, c1, n1, c2, n2, f1, f2;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        cin >> c1 >> n1 >> c2 >> n2;
        ll lcm = getLCM(n1, n2);
        // cout << lcm << endl;
        f1 = lcm / n1;
        f2 = lcm / n2;
        if (c1 * f1 < c2 * f2)
        {
            // Use 1 max
            ll max = n / n1;
            // cout << "Initial max is " << max << endl;
            while ((n - (max * n1)) % n2 != 0)
            {
                // cout << "Max becomes " << max << endl;
                if (max < 0)

                    break;

                max -= 1;
            }
            if (max >= 0)
            {
                cout << max << " " << (n - (max * n1)) / n2 << endl;
            }
            else
            {
                cout << "failed" << endl;
            }
        }
        else
        {
            // Use 2 max
            ll max = n / n2;
            while ((n - (max * n2)) % n1 != 0)
            {
                if (max < 0)

                    break;

                max -= 1;
            }
            if (max >= 0)
            {
                cout << (n - (max * n1)) / n2 << " " << max << endl;
            }
            else
            {
                cout << "failed" << endl;
            }
        }
    }

    return 0;
}