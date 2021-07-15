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

class Vertex
{
private:
    ll no;
    bool colorSet, black;

public:
    Vertex(ll n)
    {
        no = n;
        colorSet = false;
    }

    bool isSet()
    {
        return colorSet;
    }

    void setBlack()
    {
        colorSet = true;
        black = true;
    }

    void setWhite()
    {
        colorSet = true;
        black = false;
    }

    bool isBlack()
    {
        return black;
    }
};

class Graph
{
public:
    vector<Vertex *> graph;
    bool impossible;

    Graph(ll size)
    {
        Vertex *v;
        for (ll i = 0; i < size; i++)
        {

            v = new Vertex(i);
            graph.push_back(v);
        }
        impossible = false;
    }

    Vertex *getVertex(ll position)
    {
        return graph[position];
    }

    void setInitialColor(pair<ll, ll> edge)
    {
        // cout << edge.first << " " << edge.second << endl;
        getVertex(edge.first)->setBlack();
        getVertex(edge.second)->setWhite();
    }

    bool isSame(Vertex *v1, Vertex *v2)
    {
        if (v1->isBlack() == v2->isBlack())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool checkIncorrectElseSet(pair<ll, ll> edge)
    {
        Vertex *v1 = getVertex(edge.first);
        Vertex *v2 = getVertex(edge.second);
        bool returnValue = false;
        ;
        if (v1->isSet() && v2->isSet())
        {
            // cout << "both are already set" << endl;
            // Check if color combination is valid
            if (isSame(v1, v2))
            {
                impossible = true;
                returnValue = true;
            }
        }
        else if (v1->isSet())
        {
            // cout << "v1 is set" << endl;
            // Set opposite color to v2
            if (v1->isBlack())
            {
                v2->setWhite();
            }
            else
            {
                v2->setBlack();
            }
        }
        else if (v2->isSet())
        {
            // cout << "v2 is set" << endl;
            // Set opposite color to v1
            if (v2->isBlack())
            {
                v1->setWhite();
            }
            else
            {
                v1->setBlack();
            }
        }
        else
        {
            // cout << "both are unset" << endl;
            // Set random colors to both
            v1->setBlack();
            v2->setWhite();
        }
        return returnValue;
    }

    bool isImpossible()
    {
        return impossible;
    }
};

int main()
{
    file_io();
    ll N, E, v1, v2;
    vector<pair<ll, ll>> *edges;
    Graph *graph;
    while (true)
    {
        edges = new vector<pair<ll, ll>>();
        cin >> N;
        if (N == 0)
        {
            break;
        }
        graph = new Graph(N);
        // cout << "Graph initialised" << endl;
        cin >> E;

        for (ll i = 0; i < E; i++)
        {
            // cout << "i is " << i << endl;
            cin >> v1 >> v2;
            // cout << v1 << " " << v2 << endl;
            pair<ll, ll> p(v1, v2);
            // cout << "created pair" << endl;
            edges->push_back(p);
            // cout << "pushed" << endl;
        }
        // cout << "Edges set" << endl;
        graph->setInitialColor(edges->at(0));
        // cout << "Initial color set" << endl;
        for (ll i = 1; i < E; i++)
        {
            // cout << "Doing edge " << i << endl;
            bool incorrect = graph->checkIncorrectElseSet(edges->at(i));
            if (incorrect)
            {
                // cout << "Incorrect for edge " << i << endl;
                break;
            }
            // cout << "Edge " << i << " done" << endl;
        }
        if (graph->isImpossible())
        {
            cout << "NOT BICOLORABLE" << endl;
        }
        else
        {
            cout << "BICOLORABLE" << endl;
        }
    }

    return 0;
}
