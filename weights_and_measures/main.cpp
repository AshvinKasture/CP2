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

class Turtle
{
public:
    ll weight, strength;

    Turtle(ll weight, ll strength)
    {
        this->weight = weight;
        this->strength = strength;
    }
};

int main()
{
    file_io();
    ll size, w, s;
    cin >> size;
    vector<Turtle> allTurtles;
    for (ll i = 0; i < size; i++)
    {
        cin >> w >> s;
        Turtle t(w, s);
        allTurtles.push_back(t);
    }

    for (ll i = 0; i < allTurtles.size() - 1; i++)
    {
        for (ll j = i + 1; j < allTurtles.size(); j++)
        {
            if (allTurtles[j].weight < allTurtles[i].weight)
            {
                Turtle t = allTurtles[i];
                allTurtles[i] = allTurtles[j];
                allTurtles[j] = t;
            }
        }
    }

    ll totalWeight = 0;

    for (ll i = 0; i < allTurtles.size(); i++)
    {
        totalWeight += allTurtles[i].weight;
        if (allTurtles[i].strength < totalWeight)
        {
            allTurtles.erase(allTurtles.begin() + i);
            totalWeight -= allTurtles[i].weight;
        }
    }

    // for (ll i = 0; i < allTurtles.size(); i++)
    // {
    //     cout << allTurtles[i].weight << " " << allTurtles[i].strength << endl;
    // }

    cout << allTurtles.size() << endl;

    return 0;
}