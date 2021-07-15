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

class DefaultDict
{
public:
    vector<pair<ll, ll>> dictionary;

    void addNew(ll pos)
    {
        dictionary.push_back(pair<ll, ll>(pos, 1));
    }

    void increase(ll pos)
    {
        for (ll i = 0; i < dictionary.size(); i++)
        {
            if (dictionary[i].first == pos)
            {
                dictionary[i].second++;
                return;
            }
        }
        addNew(pos);
    }

    void decrease(ll pos)
    {
        for (ll i = 0; i < dictionary.size(); i++)
        {
            if (dictionary[i].first == pos)
            {
                dictionary[i].second--;
                return;
            }
        }
    }
};

pair<bool, pair<ll, ll>> *get_next_bead(vector<DefaultDict> &amatrix, ll color)
{
    pair<bool, pair<ll, ll>> *answer = new pair<bool, pair<ll, ll>>();
    ll s_color = 0, s_degree = 0, col, deg;
    for (ll i = 0; i < amatrix[color].dictionary.size(); i++)
    {
        col = amatrix[color].dictionary[i].first;
        deg = amatrix[color].dictionary[i].second;
        if (deg > s_degree)
        {
            s_color = col;
            s_degree = deg;
        }
    }

    if (s_degree > 0)
    {
        amatrix[color].decrease(s_color);
        amatrix[s_color].decrease(color);
        answer->first = true;
        answer->second = pair<ll, ll>(color, s_color);
        return answer;
    }
    else
    {
        answer->first = false;
        return answer;
    }
}

pair<bool, deque<pair<ll, ll>>> *build_necklace(vector<pair<ll, ll>> &beads)
{
    pair<bool, deque<pair<ll, ll>>> *answer = new pair<bool, deque<pair<ll, ll>>>();
    vector<DefaultDict> amatrix;
    for (ll i = 0; i < 51; i++)
    {
        DefaultDict d;
        amatrix.push_back(d);
    }
    DefaultDict degree;
    // cout << "beads are" << endl;
    for (ll i = 0; i < beads.size(); i++)
    {
        // cout << beads[i].first << " " << beads[i].second << endl;
        amatrix[beads[i].first].increase(beads[i].second);
        amatrix[beads[i].second].increase(beads[i].first);
        degree.increase(beads[i].first);
        degree.increase(beads[i].second);
    }
    for (ll i = 0; i < degree.dictionary.size(); i++)
    {
        if (degree.dictionary[i].second % 2 != 0)
        {
            answer->first = false;
            // cout << "not possible" << endl;
            return answer;
        }
    }
    // cout << "possible" << endl;
    // cout << "printing amatrix" << endl;

    // for (ll i = 0; i < amatrix.size(); i++)
    // {
    //     if (amatrix[i].dictionary.size() == 0)
    //     {
    //         cout << "empty";
    //     }
    //     for (ll j = 0; j < amatrix[i].dictionary.size(); j++)
    //     {
    //         cout << amatrix[i].dictionary[j].first << ":" << amatrix[i].dictionary[j].second << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "amatrix printing complete" << endl;

    pair<bool, pair<ll, ll>> *nxt = get_next_bead(amatrix, beads[0].second);
    deque<pair<ll, ll>> necklace;
    necklace.push_back(nxt->second);
    // necklace.push_back(nxt->second.first);
    // necklace.push_back(nxt->second.second);
    // cout << "first bead added it is " << necklace.back().first << " " << necklace.back().second << endl;
    while (true)
    {
        nxt = get_next_bead(amatrix, necklace.back().second);
        if (nxt->first)
        {
            // cout << "next bead is " << nxt->second.first << " " << nxt->second.second << endl;
        }
        else
        {
            // cout << "next bead returned as none" << endl;
        }
        if (nxt->first)
        {
            // cout << "adding this bead to last" << endl;
            necklace.push_back(nxt->second);
        }
        else if (beads.size() != necklace.size())
        {
            // cout << "next bead was none, so replacing last bead to first" << endl;
            pair<ll, ll> prev = necklace.back();
            necklace.pop_back();
            necklace.push_front(prev);
        }
        else
        {
            // cout << "nothing is left, breaking" << endl;
            break;
        }
    }

    answer->first = true;
    answer->second = necklace;
    // cout << "printing necklace here" << endl;
    for (ll i = 0; i < necklace.size(); i++)
    {
        // cout << necklace[i].first << " " << necklace[i].second << endl;
    }
    // cout << "printing completed" << endl;

    return answer;
}

int main()
{
    file_io();
    ll testCases, nbeads, no1, no2;
    cin >> testCases;
    for (ll testCase = 1; testCase <= testCases; testCase++)
    {

        cin >> nbeads;
        // cout << "nbeads are " << nbeads << endl;
        vector<pair<ll, ll>> beads;
        for (ll b = 0; b < nbeads; b++)
        {
            cin >> no1 >> no2;
            beads.push_back(pair<ll, ll>(no1, no2));
        }
        pair<bool, deque<pair<ll, ll>>> *necklace = build_necklace(beads);
        string necklace_str = "";
        // cout << "necklace_str initially is " << necklace_str << endl;
        cout << "Case #" << testCase << endl;
        if (necklace->first)
        {
            necklace_str = "";
            // cout << "necklace string is" << necklace_str << "ended" << endl;
            for (ll i = 0; i < necklace->second.size(); i++)
            {
                cout << necklace->second[i].first << " " << necklace->second[i].second << endl;
                // necklace_str += necklace->second[i].first + " " + necklace->second[i].second;
            }
            // cout << "necklace string is" << necklace_str << "ended" << endl;
            ;
        }
        else
        {
            cout << "some beads may be lost" << endl;
        }
        // cout << "Case #" << testCase << endl;
        // cout << necklace_str << endl;
    }
    return 0;
}