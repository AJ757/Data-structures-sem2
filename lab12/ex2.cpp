/*

Program to implement graph ADT using adjacent list with following methods:
1. Insert
2. Delete
3. Search
4. Display

*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph_AL {
    private:
        struct node {
            int vertex;
            int edge;
        };
        unordered_map<int, vector<node>> adjList;

    public:
        bool Is_empty();
        bool Insert_v(int);
        bool Insert_e(int, int, int);
        bool Delete_v(int);
        bool Delete_e(int, int);
        int Search(int, int);
        void Display();
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
        cout<< "\n\t\t\t\tMENU\n1. Insert\t2. Delete\t3. Search\t4. Display\t5. Exit\n";
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
                cout << "Exiting...\n";
                break;
            }
            default:
            {
                cout<<"Invalid choice.\n";
            }
        }
    }while(ch!=5);
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
        if (adjList[v1][i].vertex == v2) {
            adjList[v1][i].edge = wt;
            found = true;
            break;
        }
    }
    if (!found) adjList[v1].push_back({v2, wt});

    found = false;
    for (int i = 0; i < adjList[v2].size(); i++) {
        if (adjList[v2][i].vertex == v1) {
            adjList[v2][i].edge = wt;
            found = true;
            break;
        }
    }
    if (!found) adjList[v2].push_back({v1, wt});

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
            if (neighbors[i].vertex == v) {
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
        if (list1[i].vertex == v2) {
            list1.erase(list1.begin() + i);
            break;
        }
    }

    vector<node>& list2 = adjList[v2];
    for (int i = 0; i < list2.size(); i++) {
        if (list2[i].vertex == v1) {
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
        if (adjList[v1][i].vertex == v2) return adjList[v1][i].edge;
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
            cout << "(" << it->second[i].vertex << " - " << it->first << " , " << it->second[i].edge << ") ";
        }
        cout << '\n';
    }
}
