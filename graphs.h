#ifndef GRAPH_H
#define GRAPH_H

//#include <list>
#include <vector>

using namespace std;

typedef struct nGraph
{
    int clusterIndex;
} nodeGraph;

class Graph
{
private:

    vector<nodeGraph> nodes;
    vector<int> clusters;   // Clusters Vector. Each position indicates quantity of nodes each cluster has

    // Pointer to an array containing adjacency lists
    vector<vector <unsigned> > adj;
    // pointer to an array containing the weight of edges
    vector<vector <double> > edgeWeight;

    // A function used by DFS
    void DFSUtil(unsigned n, unsigned cLabel, bool visited[]);

public:
    Graph();
    Graph(int qtyNodes);   // Constructor
    void addNode();
    bool addEdge(unsigned n, unsigned m, double weight);
    void connectedComponents();
    vector<unsigned> getAdjacents(unsigned n);
    vector<int> getClusters();

    int getClusterIndex(unsigned n);
    int getNumberNodes();
};



#endif
