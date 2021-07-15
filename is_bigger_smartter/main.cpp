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

class Elephant
{
public:
    ll weight, iq, num;

    Elephant(ll weight, ll iq, ll num)
    {
        this->weight = weight;
        this->iq = iq;
        this->num = num;
    }

    bool operator<(Elephant e)
    {
        return (weight * 10000 - iq) < (e.weight * 10000 - e.iq);
    }
};

vector<ll> *find_sequence(vector<Elephant> &elephants)
{
    vector<Elephant> seq;
    for (ll i = 0; i < elephants.size(); i++)
    {
        Elephant newE(elephants[i].weight, elephants[i].iq, elephants[i].num);
        seq.push_back(newE);
    }

    for (ll i = 0; i < seq.size() - 1; i++)
    {
        for (ll j = i + 1; j < seq.size(); j++)
        {
            if (seq[i] < seq[j])
            {
                Elephant newE = seq[i];
                seq[i] = seq[j];
                seq[j] = newE;
            }
        }
    }
    vector<ll> seq_len;
    for (ll i = 0; i < seq.size(); i++)
    {
        seq_len.push_back(1);
    }

    vector<ll> seq_nxt;
    for (ll i = 0; i < seq.size(); i++)
    {
        seq_nxt.push_back(i);
    }

    ll current_weight, current_iq, weight, iq;

    for (ll c = 1; c < seq.size(); c++)
    {
        current_weight = seq[c].weight;
        current_iq = seq[c].iq;

        for (ll j = c - 1; j > -1; j--)
        {
            weight = seq[j].weight;
            iq = seq[j].iq;

            if (iq >= current_iq)
            {
                continue;
            }

            if (current_weight == weight)
            {
                if (seq_len[j] > seq_len[c])
                {
                    seq_len[c] = seq_len[j];
                    seq_nxt[c] = seq_nxt[j];
                }
            }
            else
            {
                if (seq_len[j] >= seq_len[c])
                {
                    seq_len[c] = seq_len[j] + 1;
                    seq_nxt[c] = j;
                }
            }
        }
    }

    ll n, s;
    n = 0;
    s = seq_len[n];
    for (ll i = 0; i < seq_len.size(); i++)
    {
        if (seq_len[i] > s)
        {
            n = i;
            s = seq_len[i];
        }
    }

    vector<ll> longest = {n};

    while (seq_nxt[longest.back()] != longest.back())
    {
        longest.push_back(seq_nxt[longest.back()]);
    }

    vector<ll> *answer = new vector<ll>();

    for (ll i = 0; i < longest.size(); i++)
    {
        ll e = longest[i];
        answer->push_back(seq[e].num);
    }

    return answer;
}

int main()
{
    file_io();
    ll size, wt, iq;
    cin >> size;
    vector<Elephant> elephants;
    for (ll i = 1; i <= size; i++)
    {
        cin >> wt >> iq;
        Elephant e(wt, iq, i);
        elephants.push_back(e);
    }
    vector<ll> *seq = find_sequence(elephants);

    for (ll i = 0; i < seq->size(); i++)
    {
        cout << seq->at(i) << endl;
    }

    return 0;
}