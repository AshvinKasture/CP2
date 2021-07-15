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

vector<vector<ll> *> *initialise_matrix(ll size)
{
    vector<vector<ll> *> *matrix = new vector<vector<ll> *>();
    vector<ll> *row;
    for (ll i = 0; i < size; i++)
    {
        row = new vector<ll>();
        for (ll j = 0; j < size; j++)
        {
            row->push_back(0);
        }
        matrix->push_back(row);
    }
    return matrix;
}

void display_matrix(vector<vector<ll> *> *matrix, ll size)
{
    cout << "\t";
    for (ll i = 0; i < size; i++)
    {
        cout << " " << i << " ";
    }
    cout << endl
         << endl;
    for (ll i = 0; i < size; i++)
    {
        // cout << "for loop" << endl;
        cout << "" << i << "\t";
        // cout << "for loop" << endl;
        for (ll j = 0; j < size; j++)
        {
            // cout << "inside for loop" << endl;
            cout << " " << (*(*matrix)[i])[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    file_io();
    ll N, E, p1, p2;
    vector<pair<ll, ll>> edges;
    vector<vector<ll> *> *matrix;
    while (true)
    {
        edges.clear();
        cin >> N;
        if (N == 0)
        {
            break;
        }
        matrix = initialise_matrix(N);
        cin >> E;
        for (ll i = 0; i < E; i++)
        {
            cin >> p1 >> p2;
            pair<ll, ll> p(p1, p2);
            edges.push_back(p);
        }
        for (pair<ll, ll> p : edges)
        {
            // display_matrix(matrix, N);
            (*(*matrix)[p.first])[p.second] = 1;
            (*(*matrix)[p.second])[p.first] = 1;
        }
        display_matrix(matrix, N);
        vector<vector<ll>> list;
        for (ll i = 0; i < N; i++)
        {
            vector<ll> row;
            for (ll j = 0; j < N; j++)
            {

                if ((*(*matrix)[i])[j] == 1)
                {
                    row.push_back(j);
                }
            }
            list.push_back(row);
        }
        cout << endl
             << endl;
        for (ll i = 0; i < list.size(); i++)
        {
            cout << i << " -> ";
            for (ll j = 0; j < list[i].size(); j++)
            {
                cout << list[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}