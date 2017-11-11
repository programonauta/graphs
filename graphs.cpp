/*
 *  Graph class represents a undirected graph
 *  using adjacency list representation
 *
 *  Method to label connected components in an
 *  undirected graph
 */
#include "graphs.h"

/*
 *  Insert a new node in the Graph
 *
 */
void Graph::addNode()
{
    nodeGraph n;
    n.idxNode = -1; // set node Index -1 as default
    n.clusterLabel = -1;
    nodes.push_back(n);
    adj.resize(nodes.size());
    edgeWeight.resize(nodes.size());
}

// Constructor
Graph::Graph()
{
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

// Return the quantity of adjacents nodes
unsigned Graph::getQtyAdjacents(unsigned n)
{
    return adj[n].size();
}

vector<vector <int> > Graph::getClusters()
{
    return clusters;
}

int Graph::getClusterIndex(unsigned n)
{
    if (n >= nodes.size())
        return -2;

    return nodes[n].idxNode;
}

void Graph::DFSUtil(unsigned n, unsigned cIndex, bool visited[])
{
    // Mark the current node as visited and print it
    visited[n] = true;
    nodes[n].idxNode = cIndex;
    nodes[n].clusterLabel = cIndex;
    clusters[cIndex][1]++;      // Increment the number of nodes on cluster cIndex
    clusters[cIndex][0]=cIndex; // Update the cluster label

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

// connected Components give labels for clusters and
// for each node store its cluster on g.[<idxNode>].idxNode
// Also, update an internal vector of graph that store the numbers of nodes each cluster has
// This vector could be gathered by getCluster method

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
            vector<int> a(2);
            a[0] = -1;
            a[1] = 0;
            clusters.push_back(a);
            DFSUtil(n, clusterIndex, visited);
        }
    }
}


