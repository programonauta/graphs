// Graph class represents a undirected graph
// using adjacency list representation

// Method to label connected components in an
// undirected graph
#include "graphs.h"

// Insert a new node in the Graph
//
void Graph::addNode()
{
    nodeGraph n;
    vector<int> adjM;
    n.clusterIndex = -1; // set Cluster Index -1 as default
    nodes.push_back(n);
    adj.resize(nodes.size());
    edgeWeight.resize(nodes.size());
}

Graph::Graph()
{
//  adj = new list<int>;
}

Graph::Graph(int qtyNodes)
{
    for (int i = 0; i < qtyNodes; i++)
        addNode();

    adj.resize(qtyNodes);
    edgeWeight.resize(qtyNodes);
}

//
// Insert a new edge in the graph
// return false if any of nodes doesn't exist
//
bool Graph::addEdge(unsigned n, unsigned m, double weight)
{
    if (n >= nodes.size() || m >= nodes.size())
        return false;
    adj[n].push_back(m);
    edgeWeight[n].push_back(weight);
    adj[m].push_back(n);
    edgeWeight[m].push_back(weight);
    return true;
}

int Graph::getNumberNodes()
{
    return nodes.size();
}

vector<unsigned> Graph::getAdjacents(unsigned n)
{
    return adj[n];
}

vector<int> Graph::getClusters()
{
    return clusters;
}

int Graph::getClusterIndex(unsigned n)
{
    if (n >= nodes.size())
        return -2;

    return nodes[n].clusterIndex;
}

void Graph::DFSUtil(unsigned n, unsigned cIndex, bool visited[])
{
    // Mark the current node as visited and print it
    visited[n] = true;
    nodes[n].clusterIndex = cIndex;
    clusters[cIndex]++;

    // Recur for all the vertices
    // adjacent to this vertex
    for(unsigned i = 0; i < adj[n].size(); ++i)
    {
        unsigned m = adj[n][i];
        if(!visited[m])
            DFSUtil(m, cIndex, visited);
    }
}


//
// Mark with different labels connected components
//
// if maxWeight == true, only connected through max weights

void Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[nodes.size()];
    for(unsigned n = 0; n < nodes.size(); n++)
        visited[n] = false;

    int clusterIndex = -1;
    for (unsigned n=0; n<nodes.size(); n++)
    {
        if (!visited[n])
        {
            // print all reachable vertices
            // from v
            clusterIndex++;
            clusters.push_back(0);
            DFSUtil(n, clusterIndex, visited);
        }
    }
}


