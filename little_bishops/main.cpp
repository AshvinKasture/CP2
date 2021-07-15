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
    if (no1 > no2)
        return no1;
    else
        return no2;
}

class None
{
public:
    bool none;
    ll value;

    None(ll val)
    {
        none = false;
        value = val;
    }

    None(bool non)
    {
        none = true;
        value = -1;
    }
};

class Board
{
public:
    ll n, b, solutions_found;
    vector<ll> *board;
    vector<ll> *moves;

    Board(ll n, ll b)
    {
        this->n = n;
        this->b = b;
        this->solutions_found = 0;
        board = new vector<ll>(n * n);
        moves = new vector<ll>();
    }

    void mod_diagonals(ll k, ll v)
    {
        // cout << "inside mod diagonals" << endl;
        ll x = k % this->n;
        ll y = k / this->n;

        for (ll i = 0; i < this->n - max(x, y); i++)
        {
            (*(this->board))[k + (this->n + 1) * i] += v;
        }
        for (ll i = 0; i < this->n - max(this->n - 1 - x, y); i++)
        {
            (*(this->board))[k + (this->n - 1) * i] += v;
        }
        // cout << "getting out of mod diagonals" << endl;
    }

    void make_move(ll k)
    {
        // cout << "inside make move" << endl;
        (*(this->board))[k] += 9999;
        moves->push_back(k);
        mod_diagonals(k, 1);
        // cout << "getting out of make move" << endl;
    }

    void undo_move()
    {
        // cout << "inside undo move" << endl;
        ll k = moves->back();
        moves->pop_back();
        mod_diagonals(k, -1);
        (*(this->board))[k] = 0;
        // cout << "completed undo move" << endl;
    }

    None *next_candidate(ll k)
    {
        // cout << "inside next_candidate" << endl;
        None *n;
        for (ll i = k; i < (this->n * this->n); i++)
        {
            if ((*(this->board))[i] == 0)
            {
                n = new None(i);
                // cout << "getting out of next_candidate" << endl;
                return n;
            }
        }
        n = new None(true);
        // cout << "getting out of next_candidate" << endl;
        return n;
    }

    bool is_solved()
    {
        // cout << "Inside is solved. moves size is " << moves->size() << " and b is " << b << endl;
        return (moves->size() >= b);
    }

    void count_solutions()
    {
        count_solutions(0);
    }

    void count_solutions(ll k)
    {
        // cout << "count_solutions called with k value " << k << endl;
        // is_solved_2();
        // cout << "here" << endl;
        if (is_solved())
        {
            // cout << "This solution is solved. SO increaminging value. Earlier was " << solutions_found << " now is ";
            solutions_found++;
            // cout << solutions_found << endl;
            return;
        }

        None *nxt = next_candidate(k);
        if (nxt->none)
        {
            // cout << "Nxt got is none" << endl;
        }
        else
        {
            // cout << "nxt got is " << nxt->value << endl;
        }
        while (!(nxt->none))
        {
            // cout << "Inside while loop in count_solutions" << endl;
            make_move(nxt->value);
            count_solutions(nxt->value + 1);
            undo_move();
            nxt = next_candidate(nxt->value + 1);
        }
    }

    ll solutions()
    {
        // cout << "Inside solutions" << endl;
        count_solutions();
        // cout << "Returning solutions" << endl;
        return solutions_found;
    }
};

int main()
{
    file_io();
    ll n, k;
    while (true)
    {

        cin >> n >> k;
        if (n == 0)
            break;
        // cout << n << " " << k << endl;
        Board *b = new Board(n, k);
        cout << b->solutions() << endl;
    }
    return 0;
}