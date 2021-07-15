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

ll max(ll no1, ll no2)
{
    return no1 > no1 ? no1 : no2;
}

class Board
{
public:
    ll n, b, solutionsFound;
    vector<ll> *board, *moves;

    Board(ll n, ll b)
    {
        this->n = n;
        this->b = b;
        this->solutionsFound = 0;
        this->board = new vector<ll>(n * n, 0);
        this->moves = new vector<ll>();
    }

    void modDiagonals(ll k, ll v)
    {
        ll x = k % n;
        ll y = k / n;

        for (ll i = 1; i < n - max(x, y); i++)
        {
            (*board)[k + (n + 1) * i] += v;
        }
        for (ll i = 1; i < n - max(n - 1 - x, y); i++)
        {
            (*board)[k + (n - 1) * i] += v;
        }
    }

    void makeMove(ll k)
    {
        (*board)[k] += 9999;
        moves->push_back(k);
        modDiagonals(k, 1);
    }

    void undoMove()
    {
        ll k = moves->back();
        moves->pop_back();
        modDiagonals(k, -1);
        (*board)[k] = 0;
    }

    pair<ll, bool> *nextCandidate(ll k)
    {
        pair<ll, bool> *solution;
        for (ll i = k; i < n * n; i++)
        {
            if (!((*board)[i]))
            {

                solution = new pair<ll, bool>(i, false);
                return solution;
            }
        }
        solution = new pair<ll, bool>(-1, true);
        return solution;
    }

    bool isSolved()
    {
        return moves->size() >= b;
    }

    void countSolutions(ll k)
    {
        if (isSolved())
        {
            solutionsFound++;
            return;
        }

        pair<ll, bool> *nxt = nextCandidate(k);
        if (!nxt->second)
        {
            makeMove(nxt->first);
            countSolutions(nxt->first + 1);
            undoMove();
            nxt = nextCandidate(nxt->first + 1);
        }
    }

    ll solutions()
    {
        countSolutions(0);
        return solutionsFound;
    }
};

int main()
{
    file_io();
    ll n, k;

    cin >> n >> k;
    cout << n << " " << k << endl;
    while (n)
    {
        Board *b = new Board(n, k);
        cout << b->solutions();
        cin >> n >> k;
        if (!k)
            break;
    }

    return 0;
}