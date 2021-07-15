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
    vector<ll> *vc = new vector<ll>(10, 0);
    for (ll i = 0; i < vc->size(); i++)
    {
        cout << vc->at(i) << " ";
    }
    cout << endl;
    ll no = 5;
    vc[2] = no;
    for (ll i = 0; i < vc->size(); i++)
    {
        cout << vc->at(i) << " ";
    }

    return 0;
}