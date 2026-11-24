#include <iostream>
#include <string>

using namespace std;

class Graph
{
private:
    static const int max_nodes = 10;
    int num_vertices;
    int adj_matrix[max_nodes][max_nodes];

    // Recursive helper function for DFS
    void dfsHelper(int current_node, bool visited[])
    {
        // Mark the current node as visited and print it
        visited[current_node] = true;
        cout << current_node << " ";

        // Explore all unvisited neighbors by going as deep as possible
        for (int neighbor = 0; neighbor < num_vertices; neighbor++)
        {
            if (adj_matrix[current_node][neighbor] == 1 && !visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
    }

public:
    // Constructor using an initializer list
    Graph(int vertices) : num_vertices(vertices)
    {
        // Initialize the adjacency matrix with 0 (no edges yet)
        for (int i = 0; i < max_nodes; i++)
        {
            for (int j = 0; j < max_nodes; j++)
            {
                adj_matrix[i][j] = 0;
            }
        }
    }

    // Adds an undirected edge between two vertices
    void addEdge(int node_u, int node_v)
    {
        adj_matrix[node_u][node_v] = 1;
        adj_matrix[node_v][node_u] = 1;
    }

    // Breadth-First Search (explores level by level using a queue)
    void runBfs(int start_node)
    {
        bool visited[max_nodes];
        for (int i = 0; i < num_vertices; i++)
        {
            visited[i] = false;
        }

        // Simple array-based queue
        int queue_arr[max_nodes];
        int front_index = 0;
        int rear_index = 0;

        // Mark start node as visited and add it to the queue
        visited[start_node] = true;
        queue_arr[rear_index++] = start_node;

        cout << "BFS Traversal: ";

        while (front_index < rear_index)
        {
            // Remove the front node from the queue and print it
            int current_node = queue_arr[front_index++];
            cout << current_node << " ";

            // Add all unvisited neighbors of current_node to the queue
            for (int neighbor = 0; neighbor < num_vertices; neighbor++)
            {
                if (adj_matrix[current_node][neighbor] == 1 && !visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue_arr[rear_index++] = neighbor;
                }
            }
        }

        cout << endl;
    }

    // Depth-First Search (explores branch by branch using recursion)
    void runDfs(int start_node)
    {
        bool visited[max_nodes];
        for (int i = 0; i < num_vertices; i++)
        {
            visited[i] = false;
        }

        cout << "DFS Traversal: ";
        dfsHelper(start_node, visited);
        cout << endl;
    }
};

int main()
{
    // Create a graph with 5 vertices (0, 1, 2, 3, 4)
    Graph my_graph(5);

    // Connect vertices with edges
    my_graph.addEdge(0, 1);
    my_graph.addEdge(0, 2);
    my_graph.addEdge(1, 3);
    my_graph.addEdge(1, 4);
    my_graph.addEdge(2, 4);

    // Run both traversals starting from vertex 0
    my_graph.runBfs(0);
    my_graph.runDfs(0);

    return 0;
}