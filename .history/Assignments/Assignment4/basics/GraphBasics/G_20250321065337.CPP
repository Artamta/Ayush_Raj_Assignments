#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdexcept> // for exceptions
using namespace std;

/*
 * Graph ADT using adjacency list representation.
 * We support both directed and undirected graphs.
 *
 * Operations included:
 * 1) Constructor: Graph(int vertices, bool isDirected = false)
 * 2) addEdge(u, v)
 * 3) removeEdge(u, v)
 * 4) printGraph()
 * 5) BFS(start)
 * 6) DFS(start) - recursive or iterative
 */

class Graph
{
private:
    int V;                   // Number of vertices
    bool directed;           // True if the graph is directed
    vector<vector<int>> adj; // Adjacency list: for each vertex, store a list of neighbors

    // Helper function for recursive DFS
    void dfsUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        // Visit all neighbors of v
        for (int neighbor : adj[v])
        {
            if (!visited[neighbor])
            {
                dfsUtil(neighbor, visited);
            }
        }
    }

public:
    // Constructor
    // -------------------------------------------------------------
    // vertices: number of vertices in the graph (0..vertices-1)
    // isDirected: false => undirected, true => directed
    Graph(int vertices, bool isDirected = false)
    {
        if (vertices < 1)
        {
            throw invalid_argument("Number of vertices must be >= 1");
        }
        V = vertices;
        directed = isDirected;
        adj.resize(vertices); // Create V empty lists
    }

    // addEdge(u, v)
    // -------------------------------------------------------------
    // Adds an edge from u to v.
    // If undirected, also adds an edge from v to u.
    void addEdge(int u, int v)
    {
        if (u < 0 || u >= V || v < 0 || v >= V)
        {
            throw out_of_range("Vertex index out of range");
        }
        // Add an edge from u to v
        adj[u].push_back(v);
        // If undirected, add edge from v to u
        if (!directed)
        {
            adj[v].push_back(u);
        }
    }

    // removeEdge(u, v)
    // -------------------------------------------------------------
    // Removes an edge from u to v if it exists.
    // If undirected, also removes the edge from v to u.
    void removeEdge(int u, int v)
    {
        if (u < 0 || u >= V || v < 0 || v >= V)
        {
            throw out_of_range("Vertex index out of range");
        }
        // Remove v from u's adjacency list
        // We'll find v in adj[u] and erase it
        auto &neighborsU = adj[u];
        for (auto it = neighborsU.begin(); it != neighborsU.end(); ++it)
        {
            if (*it == v)
            {
                neighborsU.erase(it);
                break;
            }
        }

        // If undirected, remove u from v's adjacency list
        if (!directed)
        {
            auto &neighborsV = adj[v];
            for (auto it = neighborsV.begin(); it != neighborsV.end(); ++it)
            {
                if (*it == u)
                {
                    neighborsV.erase(it);
                    break;
                }
            }
        }
    }

    // printGraph()
    // -------------------------------------------------------------
    // Prints the adjacency list for each vertex
    void printGraph() const
    {
        cout << "Graph adjacency list:\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << ": ";
            for (int neighbor : adj[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // BFS(start)
    // -------------------------------------------------------------
    // Performs a breadth-first search starting from vertex 'start'
    // and prints the order in which vertices are visited.
    void BFS(int start) const
    {
        if (start < 0 || start >= V)
        {
            throw out_of_range("Start vertex out of range");
        }
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting at vertex " << start << ": ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Enqueue all unvisited neighbors
            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // DFS(start)
    // -------------------------------------------------------------
    // Performs a depth-first search starting from 'start'
    // using recursion, and prints the visited order.
    void DFS(int start)
    {
        if (start < 0 || start >= V)
        {
            throw out_of_range("Start vertex out of range");
        }
        vector<bool> visited(V, false);
        cout << "DFS (recursive) starting at vertex " << start << ": ";
        dfsUtil(start, visited);
        cout << endl;
    }

    // Alternatively, we could provide an iterative DFS version:
    void DFSIterative(int start)
    {
        if (start < 0 || start >= V)
        {
            throw out_of_range("Start vertex out of range");
        }
        vector<bool> visited(V, false);
        stack<int> st;

        st.push(start);
        cout << "DFS (iterative) starting at vertex " << start << ": ";

        while (!st.empty())
        {
            int current = st.top();
            st.pop();

            if (!visited[current])
            {
                visited[current] = true;
                cout << current << " ";

                // Push neighbors onto stack
                // (Typically in reverse order if we want the same order as recursive DFS)
                for (auto it = adj[current].rbegin(); it != adj[current].rend(); ++it)
                {
                    if (!visited[*it])
                    {
                        st.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    /*
       Let's demonstrate how to use our Graph class.

       We'll create a small undirected graph with 5 vertices (0..4),
       add some edges, and then do BFS and DFS traversals.
    */
    try
    {
        // Create an undirected graph with 5 vertices
        Graph g(5, false); // 5 vertices, undirected
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 3);
        g.addEdge(3, 4);

        cout << "=== Undirected Graph Demo ===\n";
        g.printGraph();

        g.BFS(0);
        g.DFS(0);
        g.DFSIterative(0);

        cout << "\nRemove edge (0,2)...\n";
        g.removeEdge(0, 2);
        g.printGraph();

        cout << "\n=== Directed Graph Demo ===\n";
        // Create a directed graph with 5 vertices
        Graph dg(5, true); // 5 vertices, directed
        dg.addEdge(0, 1);
        dg.addEdge(0, 2);
        dg.addEdge(1, 3);
        dg.addEdge(2, 3);
        dg.addEdge(3, 4);

        dg.printGraph();
        dg.BFS(0);
        dg.DFS(0);
    }
    catch (exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
