/*

Program to implement graph ADT using adjacency matrix with following methods:
1. Insert
2. Delete
3. Search
4. Display

*/


#include <iostream>
#include <vector>
using namespace std;

class Graph_AM
{
    private:
        vector<vector<int>> matrix;
        vector <int> nodes;
        int len;
        int find_index(int);
        
    public:
        Graph_AM()
        {
            len=0;
        }
        bool Is_empty();
        bool Insert_v(int);
        bool Insert_e(int,int,int);
        bool Delete_v(int);
        bool Delete_e(int,int);
        void Display();
        int Search(int,int);
};

// function to obtain user input and implement insertion
void menu_insert_input(Graph_AM* graph)
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
void menu_delete(Graph_AM* graph)
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

int main()
{
    Graph_AM graph;
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

bool Graph_AM::Is_empty()
{
    return matrix.empty();
}

// finds index of vertex in matrix
// Input:   elt - element to find
// returns index, -1 if not found
int Graph_AM::find_index(int elt) {
    for (int i = 0; i < nodes.size(); i++)
        if (nodes[i] == elt) return i;
    return -1;
}

// inserts vertex into matrix
// Input:   elt - vertex to insert
// returns boolean for success
bool Graph_AM::Insert_v(int elt)
{
    if (find_index(elt)!=-1) return false;
    vector<int> newelt;
    int res;
    
    for (int i=0;i<len;i++)
    {
        res = 0;
        matrix[i].push_back(res);
        newelt.push_back(res);
    }
    newelt.push_back(0);
    nodes.push_back(elt);
    matrix.push_back(newelt);
    len++;
    return true;
}

// inserts edge into matrix
// Input:   val - edge weight to insert
//          v1,v2 - vertices
// returns boolean for success
bool Graph_AM::Insert_e(int val,int v1, int v2)
{
    int idx1=find_index(v1),idx2=find_index(v2);
    if (idx1==-1||idx2==-1) return false;
    matrix[idx1][idx2]=val;
    matrix[idx2][idx1]=val;
    return true;
}

// deleted vertex from matrix
// Input:   elt - vertex to delete
// returns boolean for success, false if not found
bool Graph_AM::Delete_v(int elt)
{
    int idx=find_index(elt);
    if (idx==-1) return false;
    nodes.erase(nodes.begin()+idx);
    for (int k=0;k<len;k++)
    {
        matrix[k].erase(matrix[k].begin()+idx);
    }
    matrix.erase(matrix.begin()+idx);
    len--;
    return true;
}

// deleted edge from matrix
// Input:  v1,v2 - vertices
// returns boolean for success, false if not found
bool Graph_AM::Delete_e(int v1, int v2)
{
    int idx1=find_index(v1),idx2=find_index(v2);
    if (idx1==-1||idx2==-1) return false;
    matrix[idx1][idx2]=0;
    matrix[idx2][idx1]=0;
    return true;
}

// Displays matrix
void Graph_AM::Display()
{
    if (matrix.empty())
    {
        cout << "Graph is empty.\n";
        return;
    }
    cout <<"  ";
    for (int i=0;i<len;i++)
    {
        cout << nodes[i] << ' ';
    }
    cout << '\n';
    for (int i=0;i<len;i++)
    {
        cout << nodes[i] << ' ';
        for (int j=0;j<len;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout <<"\n";
    }
}

// searches for edge in matrix
// Input:   v1,v2 - vertices
// returns weight of edge, -1 if not found
int Graph_AM::Search(int v1,int v2)
{
    int idx1=find_index(v1),idx2=find_index(v2);
    if (idx1==-1||idx2==-1) return -1;
    return matrix[idx1][idx2];
}

