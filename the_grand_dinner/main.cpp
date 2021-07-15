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

class Heap
{
public:
    vector<pair<ll, ll>> data;

    void push_back(pair<ll, ll> pp)
    {
        data.push_back(pp);
    }

    ll size()
    {
        return data.size();
    }

    pair<ll, ll> pop()
    {
        // cout << "in pop size is " << data.size() << endl;
        ll minDataFirst = data[0].first;
        ll minDataSecond = data[0].second;
        ll minIndex = 0;
        for (ll i = 1; i < data.size(); i++)
        {
            if (data[i].first < minDataFirst)
            {
                minDataFirst = data[i].first;
                minDataSecond = data[i].second;
                minIndex = i;
            }
        }
        data.erase(data.begin() + minIndex);
        return pair<ll, ll>(minDataFirst, minDataSecond);
    }

    void print()
    {
        cout << "printing heap" << endl;
        for (ll i = 0; i < data.size(); i++)
        {
            cout << data[i].first << " " << data[i].second << endl;
        }
        cout << "ended printing heap" << endl;
    }
};

void find_seating(vector<ll> &teams, vector<ll> &tables)
{
    vector<vector<ll>> team_tables;
    for (ll i = 0; i < teams.size(); i++)
    {
        team_tables.push_back(vector<ll>());
    }
    // cout << "team_tables created" << endl;
    vector<pair<ll, ll>> new_tables;
    for (ll i = 0; i < tables.size(); i++)
    {
        new_tables.push_back(pair<ll, ll>(tables[i], i));
    }
    // cout << "new_tables created\nit is " << endl;

    for (ll i = 0; i < new_tables.size(); i++)
    {
        // cout << new_tables[i].first << " " << new_tables[i].second << endl;
    }

    // Sorting new tables

    for (ll i = 0; i < new_tables.size() - 1; i++)
    {
        for (ll j = i + 1; j < new_tables.size(); j++)
        {
            if (new_tables[i].first < new_tables[j].first)
            {
                auto temp = new_tables[j];
                new_tables[j] = new_tables[i];
                new_tables[i] = temp;
            }
        }
    }
    // cout << "new_tables sorted\nit is " << endl;
    for (ll i = 0; i < new_tables.size(); i++)
    {
        // cout << new_tables[i].first << " " << new_tables[i].second << endl;
    }

    // vector<pair<ll, ll>> team_heap;
    Heap team_heap;
    for (ll i = 0; i < teams.size(); i++)
    {
        team_heap.push_back(pair<ll, ll>(-teams[i], i));
    }
    // cout << "team_heap created and pushed" << endl;
    // team_heap.print();

    for (ll i = 0; i < new_tables.size(); i++)
    {
        ll seats = new_tables[i].first;
        ll table = new_tables[i].second;
        // cout << "for table no " << table << " whose capacity is " << seats << endl;

        if (team_heap.size() == 0)
        {
            // cout << "team_heap was empty, so broke out" << endl;
            break;
        }

        vector<pair<ll, ll>> teams_seated;

        while (team_heap.size() != 0 && teams_seated.size() < seats)
        {
            pair<ll, ll> t = team_heap.pop();
            // cout << "while iteration " << teams_seated.size() << " t is " << t.first << " " << t.second << endl;
            teams_seated.push_back(t);
        }

        // cout << "teams seated for this iteration" << endl;

        for (ll j = 0; j < teams_seated.size(); j++)
        {
            // cout << "seating arrangement for team " << j << " added with table no " << table + 1 << endl;
            team_tables[teams_seated[j].second].push_back(table + 1);
        }

        // cout << "arrangement created" << endl;

        for (ll j = 0; j < teams_seated.size(); j++)
        {
            ll members = teams_seated[j].first;
            ll team = teams_seated[j].second;
            if (members + 1 < 0)
            {
                team_heap.push_back(pair<ll, ll>(members + 1, team));
            }
        }
        // cout << "rearranged back" << endl;

        // cout << "put the values back in original team_heap" << endl;
    }

    // cout << "after doing everything, output is" << endl;
    // for (ll i = 0; i < team_tables.size(); i++)
    // {
    //     sort(team_tables[i].begin(), team_tables[i].end());
    //     for (ll j = 0; j < team_tables[i].size(); j++)
    //     {
    //         cout << team_tables[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (team_heap.size() > 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
        for (ll i = 0; i < team_tables.size(); i++)
        {
            sort(team_tables[i].begin(), team_tables[i].end());
            for (ll j = 0; j < team_tables[i].size(); j++)
            {
                cout << team_tables[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    file_io();
    ll M, N;
    while (true)
    {
        cin >> M >> N;
        if ((M == 0) || (N == 0))
        {
            break;
        }
        vector<ll> teams(M);
        vector<ll> tables(N);
        for (ll i = 0; i < M; i++)
        {
            cin >> teams[i];
        }
        for (ll i = 0; i < N; i++)
        {
            cin >> tables[i];
        }
        // cout << "input taken" << endl;
        find_seating(teams, tables);
    }
    return 0;
}