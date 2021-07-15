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
public:
    ll id;
    ld x, y;

    Vertex(ll id, ld x, ld y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    // bool operator==(Vertex *v)
    // {
    //     if (this->name == v->name && this->x == v->x && this->y == v->y)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
};

class Edge
{
public:
    Vertex *v1, *v2;
    ld distance;

    Edge(Vertex *v1, Vertex *v2, ld distance)
    {
        this->v1 == v1;
        this->v2 == v2;
        this->distance = distance;
    }
};

class Graph
{
public:
    vector<Vertex *> vertices;
    vector<Edge *> edges;

    Graph()
    {
    }

    void addVertex(Vertex *vertex)
    {
        vertices.push_back(vertex);
    }

    Vertex *getVertex(ll id)
    {
        for (ll i = 0; i < vertices.size(); i++)
        {
            if ((vertices[i])->id == id)
            {
                return vertices[i];
            }
        }
    }

    void addEdge(Edge *edge)
    {
        edges.push_back(edge);
    }

    Edge *getEdge(Vertex *v1, Vertex *v2)
    {
        for (ll i = 0; i < edges.size(); i++)
        {
            Edge *edge = edges[i];
            if ((edge->v1 == v1 && edge->v2 == v2) || (edge->v1 == v2 && edge->v2 == v1))
            {
                return edge;
            }
        }
    }

    vector<Edge *> *getConnectedEdgesToVertex(Vertex *v)
    {
        vector<Edge *> *edgeList = new vector<Edge *>();
        for (ll i = 0; i < edges.size(); i++)
        {
            Edge *edge = edges[i];
            if (edge->v1 == v || edge->v2 == v)
            {
                edgeList->push_back(edge);
            }
        }
        return edgeList;
    }

    ld getDistance(Vertex *v1, Vertex *v2)
    {
        return sqrt(pow(v1->x - v2->x, 2) + pow(v1->y - v2->y, 2));
    }

    Edge *getMinEdge()
    {
        Edge *minEdge = edges[0];
        for (ll i = 1; i < edges.size(); i++)
        {
            Edge *edge = edges[i];
            if (edge->distance < minEdge->distance)
            {
                minEdge = edge;
            }
        }
        return minEdge;
    }

    bool notIn(Edge *edge, vector<Edge *> *allEdges)
    {
        for (ll i = 0; i < allEdges->size(); i++)
        {
            if (allEdges->at(i) == edge)
            {
                return false;
            }
        }
        return true;
    }

    vector<Edge *> *getConnectedEdges(vector<Edge *> *currentGraph)
    {
        vector<Edge *> *edgeList = new vector<Edge *>();
        for (ll i = 0; i < currentGraph->size(); i++)
        {
            edgeList->push_back(currentGraph->at(i));
        }
        ll i = 0;
        while (i < edgeList->size())
        {
            Edge *edge = edgeList->at(i);
            vector<Edge *> *nextEdgeList = getConnectedEdgesToVertex(edge->v1);
            for (ll j = 0; j < nextEdgeList->size(); j++)
            {
                Edge *nextEdge = nextEdgeList->at(j);
                if (notIn(nextEdge, edgeList))
                {
                    edgeList->push_back(nextEdge);
                }
            }

            nextEdgeList = getConnectedEdgesToVertex(edge->v2);
            for (ll j = 0; j < nextEdgeList->size(); j++)
            {
                Edge *nextEdge = nextEdgeList->at(j);
                if (notIn(nextEdge, edgeList))
                {
                    edgeList->push_back(nextEdge);
                }
            }

            i++;
        }

        return edgeList;
    }

    Edge *getMinEdgeExcept(vector<Edge *> *collection, vector<Edge *> *done)
    {
        vector<Edge *> edgeList;
        for (ll i = 0; i < collection->size(); i++)
        {
            Edge *edge = collection->at(i);
            if (notIn(edge, done))
            {
                edgeList.push_back(edge);
            }
        }
        Edge *minEdge = edgeList[0];
        for (ll i = 0; i < edgeList.size(); i++)
        {
            Edge *edge = edgeList[i];
            if (edge->distance < minEdge->distance)
            {
                minEdge = edge;
            }
        }
        return minEdge;
    }
};

ld roundTill2(ld no)
{
    no = int(no * 100 + 0.5);
    return float(no / 100);
}

int main()
{
    file_io();
    ll noOfFreckles;
    ld c1, c2;
    cin >> noOfFreckles;
    vector<pair<ld, ld>> rawFreckles;
    for (ll i = 0; i < noOfFreckles; i++)
    {
        cin >> c1 >> c2;
        pair<ld, ld> p(c1, c2);
        rawFreckles.push_back(p);
    }

    Graph graph;

    for (ll i = 0; i < rawFreckles.size(); i++)
    {
        Vertex *v = new Vertex(i + 1, rawFreckles[i].first, rawFreckles[i].second);
        graph.addVertex(v);
    }

    for (ll i = 0; i < graph.vertices.size() - 1; i++)
    {
        for (ll j = i + 1; j < graph.vertices.size(); j++)
        {
            Vertex *v1 = graph.vertices[i];
            Vertex *v2 = graph.vertices[j];
            ld distance = graph.getDistance(v1, v2);
            Edge *edge = new Edge(v1, v2, distance);
            graph.addEdge(edge);
        }
    }

    vector<Edge *> *spanningTree = new vector<Edge *>();
    spanningTree->push_back(graph.getMinEdge());

    while (spanningTree->size() < graph.vertices.size())
    {
        vector<Edge *> *connectedEdges = graph.getConnectedEdges(spanningTree);
        spanningTree->push_back(graph.getMinEdgeExcept(connectedEdges, spanningTree));
    }

    ld sum = 0;
    for (ll i = 0; i < spanningTree->size() - 1; i++)
    {
        sum += spanningTree->at(i)->distance;
    }

    cout << roundTill2(sum) << endl;

    return 0;
}