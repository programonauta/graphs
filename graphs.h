#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

using namespace std;

typedef struct nGraph
{
    int idxNode;
    int clusterLabel;
} nodeGraph;

class Graph
{
private:

    vector<nodeGraph> nodes;
    vector<vector <int> > clusters;   // Clusters Vector.
                                      // Each position has a 2 position array:
                                      // [0] quantity of nodes each cluster has
                                      // [1] label of cluster

    // 2 dimensional rray containing adjacency lists [idxNodeFrom][idxNodeTo]
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
    unsigned getQtyAdjacents(unsigned n);
    vector<vector <int> > getClusters();

    int getClusterIndex(unsigned n);
    int getNumberNodes();
};



#endif
