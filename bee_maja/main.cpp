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

array<ll, 120100> global_x;
array<ll, 120100> global_y;
ll counter = 2;

void updateCounter(ll &x, ll &y)
{
    global_x[counter] = x;
    global_y[counter++] = y;
}

void up(ll &x, ll &y)
{
    y--;
    updateCounter(x, y);
}
void upRight(ll &x, ll &y)
{
    x++;
    y--;
    updateCounter(x, y);
}
void downRight(ll &x, ll &y)
{
    x++;
    updateCounter(x, y);
}
void down(ll &x, ll &y)
{
    y++;
    updateCounter(x, y);
}
void downLeft(ll &x, ll &y)
{
    x--;
    y++;
    updateCounter(x, y);
}
void upLeft(ll &x, ll &y)
{
    x--;
    updateCounter(x, y);
}

int main()
{
    file_io();

    ll x = 0;
    ll y = 0;
    global_x[1] = 0;
    global_y[1] = 0;
    for (ll i = 1; i < 184; i++)
    {
        down(x, y);
        for (ll j = 1; j < i; j++)
            downLeft(x, y);
        for (ll j = 0; j < i; j++)
            upLeft(x, y);
        for (ll j = 0; j < i; j++)
            up(x, y);
        for (ll j = 0; j < i; j++)
            upRight(x, y);
        for (ll j = 0; j < i; j++)
            downRight(x, y);
        for (ll j = 0; j < i; j++)
            down(x, y);
    }
    ll query;
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        cin >> query;
        cout << global_x[query] << " " << global_y[query] << endl;
    }

    return 0;
}