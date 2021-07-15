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

bool isPrime(ll no)
{
    for (ll i = 2; i < no / 2 + 1; i++)
    {
        if (no % i == 0)
            return false;
    }
    return true;
}

bool isShortPrime(ll no)
{
    // if()
    return false;
}

int main()
{
    file_io();
    ll no;
    while (true)
    {
        cin >> no;
        if (no == 0)
            break;
        if (isPrime(no))
        {
            cout << no << " is normal." << endl;
        }
        else
        {
            cout << "The number " << no << " is a Carmiachel number." << endl;
        }
    }

    return 0;
}