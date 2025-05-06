/*

Program to implement graph ADT using adjacent list with following methods:
1. Insert
2. Delete
3. Search
4. Display
5. Prim's MST
6. Kruskal's MST
7. Dijkstra's shortest path

*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <climits>
using namespace std;

struct node {
    int edge;
    int v1;
    int v2;

    node(int w, int a, int b) : edge(w), v1(a), v2(b) {}

    bool operator>(const node& other) const {
        return edge > other.edge;
    }
};

// Disjoint set class to implement kruskals algorithm
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Graph_AL {
    private:
        unordered_map<int, vector<node>> adjList;
    public:
        bool Is_empty();
        bool Insert_v(int);
        bool Insert_e(int, int, int);
        bool Delete_v(int);
        bool Delete_e(int, int);
        int Search(int, int);
        void Display();
        void primMST();
        void kruskalMST();
        void dijkstraPath(int,int);
};

// function to obtain user input and implement insertion
void menu_insert_input(Graph_AL* graph)
{
    cout << "1. Insert vertex\t2. Insert edge\n";
    cout << "Enter choice: ";
    int ch,v1;
    cin >> ch;
    switch(ch)
    {
        case 1:
        {
            cout << "Enter vertex: ";
            cin >> v1;
            if (!graph->Insert_v(v1)) cout << "Vertex already exists.\n";
            return;
        }
        case 2:
        {
            int v2, e;
            cout << "Enter vertex 1: ";
            cin >> v1;
            cout << "Enter vertex 2: ";
            cin >> v2;
            cout << "Enter edge weight: ";
            cin >> e;
            if (!graph->Insert_e(e,v1,v2)) cout << "Invalid vertex.\n";
            return;
        }
        default:
            cout << "Invalid choice.\n";
    }
}

// function to obtain user input and implement deletion
void menu_delete(Graph_AL* graph)
{
    cout << "1. Delete vertex\t2. Delete edge\n";
    cout << "Enter choice: ";
    int ch,v1;
    cin >> ch;
    switch(ch)
    {
        case 1:
        {
            cout << "Enter vertex: ";
            cin >> v1;
            cout << (graph->Delete_v(v1)?"Vertex deleted.\n":"Vertex not found.\n");
            return;
        }
        case 2:
        {
            int v2, e;
            cout << "Enter vertex 1: ";
            cin >> v1;
            cout << "Enter vertex 2: ";
            cin >> v2;
            if (!graph->Delete_e(v1,v2)) cout << "Invalid vertex.\n";
            else cout << "Edge deleted.\n";
            return;
        }
        default:
            cout << "Invalid choice.\n";
    }
}

int main() {
    Graph_AL graph;
    int ch,v1,v2,res;
    do
    {
        cout<< "\n\t\t\tMENU\n1. Insert\t2. Delete\t3. Search\t4. Display\n5. Prim's MST\t6. Kruskal's MST\t7. Dijkstra's shotest path\n8. Exit\n";
        cout << "Enter choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1:
            {
                menu_insert_input(&graph);
                break;
            }
            case 2:
            {
                if (graph.Is_empty())
                {
                    cout << "Graph is empty.\n";
                    break;
                }
                menu_delete(&graph);
                break;
            }
            case 3:
            {
                if (graph.Is_empty())
                {
                    cout << "Graph is empty.\n";
                    break;
                }
                cout << "Enter vertex 1 of edge to search: ";
                cin >> v1;
                cout << "Enter vertex 2 of edge to search: ";
                cin >> v2;
                res=graph.Search(v1,v2);
                if (res==-1) cout << "Edge not found.\n";
                else cout << "Edge weight "<<res<<'\n';
                break;
            }
            case 4:
            {
                graph.Display();
                break;
            }
            case 5:
            {
                if (graph.Is_empty())
                {
                    cout << "Graph is empty.\n";
                    break;
                }
                graph.primMST();
                break;
            }
            case 6:
            {
                if (graph.Is_empty())
                {
                    cout << "Graph is empty.\n";
                    break;
                }
                graph.kruskalMST();
                break;
            }
            case 7:
            {
                if (graph.Is_empty())
                {
                    cout << "Graph is empty.\n";
                    break;
                }
                cout << "Enter start: ";
                cin >> v1;
                cout << "Enter end: ";
                cin >> v2;
                graph.dijkstraPath(v1,v2);
                break;
            }
            case 8:
            {
                cout << "Exiting...\n";
                break;
            }
            default:
            {
                cout<<"Invalid choice.\n";
            }
        }
    }while(ch!=8);
    return 0;
}

// empty check
bool Graph_AL::Is_empty()
{
    return adjList.empty();
}

// inserts vertex into list
// Input:   v - vertex to insert
// returns boolean for success
bool Graph_AL::Insert_v(int v) {
    if (adjList.count(v)) return false;
    adjList[v] = vector<node>();
    return true;
}

// inserts edge into list
// Input:   wt - edge weight to insert
//          v1,v2 - vertices
// returns boolean for success
bool Graph_AL::Insert_e(int wt, int v1, int v2) {
    if (!adjList.count(v1) || !adjList.count(v2)) return false;

    bool found = false;
    for (int i = 0; i < adjList[v1].size(); i++) {
        if (adjList[v1][i].v1 == v2) {
            adjList[v1][i].edge = wt;
            found = true;
            break;
        }
    }
    if (!found) adjList[v1].push_back({wt,v2,v1});

    found = false;
    for (int i = 0; i < adjList[v2].size(); i++) {
        if (adjList[v2][i].v1 == v1) {
            adjList[v2][i].edge = wt;
            found = true;
            break;
        }
    }
    if (!found) adjList[v2].push_back({wt,v1,v2});

    return true;
}

// deleted vertex from list
// Input:   v - vertex to delete
// returns boolean for success, false if not found
bool Graph_AL::Delete_v(int v) {
    if (!adjList.count(v)) return false;

    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        vector<node>& neighbors = it->second;
        for (int i = 0; i < neighbors.size(); i++) {
            if (neighbors[i].v1 == v) {
                neighbors.erase(neighbors.begin() + i);
                break;
            }
        }
    }

    adjList.erase(v);
    return true;
}

// deleted edge from list
// Input:  v1,v2 - vertices
// returns boolean for success, false if not found
bool Graph_AL::Delete_e(int v1, int v2) {
    if (!adjList.count(v1) || !adjList.count(v2)) return false;

    vector<node>& list1 = adjList[v1];
    for (int i = 0; i < list1.size(); i++) {
        if (list1[i].v1 == v2) {
            list1.erase(list1.begin() + i);
            break;
        }
    }

    vector<node>& list2 = adjList[v2];
    for (int i = 0; i < list2.size(); i++) {
        if (list2[i].v1 == v1) {
            list2.erase(list2.begin() + i);
            break;
        }
    }

    return true;
}

// searches for edge in list
// Input:   v1,v2 - vertices
// returns weight of edge, -1 if not found
int Graph_AL::Search(int v1, int v2) {
    if (!adjList.count(v1)||!adjList.count(v2)) return -1;
    for (int i = 0; i < adjList[v1].size(); i++) {
        if (adjList[v1][i].v1 == v2) return adjList[v1][i].edge;
    }
    return -1;
}

// Displays list
void Graph_AL::Display() {
    if (adjList.empty()) {
        cout << "\nGraph is empty.\n";
        return;
    }

    cout << "\nAdjacency List:\n";
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        cout << it->first << " -> ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << "(" << it->second[i].v1 << " - " << it->second[i].v2 << ", "  << it->second[i].edge << ") ";
        }
        cout << '\n';
    }
}

// Displays MST of graph using Prim's algorithm
// Displays appropriate message if graph is disconnected
void Graph_AL::primMST() {
    if (adjList.empty()) {
        cout << "Graph is empty.\n";
        return;
    }

    unordered_set<int> visited;
    vector<node> mst;
    priority_queue<node, vector<node>, greater<node>> pq;

    int start = adjList.begin()->first;
    visited.insert(start);

    for (const node& n : adjList[start]) {
        pq.push(n);
    }

    while (!pq.empty()) {
        node current = pq.top();
        pq.pop();

        int nextVertex = current.v1;
        if (visited.count(nextVertex)) continue;

        visited.insert(nextVertex);
        mst.push_back(current);

        for (const node& neighbor : adjList[nextVertex]) {
            if (!visited.count(neighbor.v1)) {
                pq.push(neighbor);
            }
        }
    }

    if (mst.size() != adjList.size() - 1) {
        cout << "Graph is disconnected.\n";
        return;
    }

    cout << "\nMinimum Spanning Tree (Prim's):\n";
    for (const node& e : mst) {
        cout << e.v2 << " - " << e.v1 << " : " << e.edge << '\n';
    }
}

// Displays MST of graph using Kruskal's algorithm using DSU
// Displays appropriate message if graph is disconnected
void Graph_AL::kruskalMST() {
    set<pair<int, int>> addedEdges;
    priority_queue<node, vector<node>, greater<node>> pq;

    unordered_map<int, int> vertexToIndex;
    unordered_map<int, int> indexToVertex;
    int idx = 0;
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        vertexToIndex[it->first] = idx;
        indexToVertex[idx] = it->first;
        idx++;
    }

    int n = vertexToIndex.size();
    DSU dsu(n); 

    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        int u = it->first;
        for (auto& e : it->second) {
            int a = min(e.v1, e.v2);
            int b = max(e.v1, e.v2);
            if (addedEdges.count({a, b}) == 0) {
                pq.push(e);
                addedEdges.insert({a, b});
            }
        }
    }

    vector<node> mst;
    int mstWeight = 0;

    while (!pq.empty() && mst.size() < n - 1) {
        node e = pq.top(); pq.pop();
        int uIdx = vertexToIndex[e.v1];
        int vIdx = vertexToIndex[e.v2];

        int uRoot = dsu.find(uIdx);
        int vRoot = dsu.find(vIdx);

        if (uRoot != vRoot) {
            mst.push_back(e);
            mstWeight += e.edge;
            dsu.unionSets(uIdx, vIdx);
        }
    }

    if (mst.size() != n - 1) {
        cout << "Graph is disconnected. MST not possible.\n";
        return;
    }

    cout << "Minimum Spanning Tree:\n";
    for (auto& e : mst) {
        cout << e.v1 << " - " << e.v2 << " (wt = " << e.edge << ")\n";
    }
    cout << "Total weight = " << mstWeight << '\n';
}

// Calculates shortest distance from start to end and displays path
// Input:   start,end - vertices
// Displays appropriate message for invalid vertices or no paths.
void Graph_AL::dijkstraPath(int start, int end) {
    if (!adjList.count(start)||!adjList.count(end))
    {
        cout << "Invalid start and end.\n";
        return;
    }
    unordered_map<int, int> dist;
    unordered_map<int, int> parent;

    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        dist[it->first] = INT_MAX;
    }
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currDist > dist[u]) continue;

        for (auto edgeIt = adjList[u].begin(); edgeIt != adjList[u].end(); ++edgeIt) {
            int v = edgeIt->v1;  
            int weight = edgeIt->edge; 

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "No path exists from " << start << " to " << end << ".\n";
        return;
    }

    cout << "Shortest distance from " << start << " to " << end << " = " << dist[end] << '\n';

    vector<int> path;
    for (int at = end; at != start; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(start);

    cout << "Path: ";
    for (int i = path.size()-1; i >=0; i--) {
        cout << path[i];
        if (i - 1 >= 0) cout << " -> ";
    }
    cout << '\n';
}
