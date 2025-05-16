//
// Created by claire on 5/7/2025.
//
#include "graph.h"

#include <iostream>
#include <climits>

#include "heap.h"

Graph::Graph(int vertices) {
    // account for vertices 0, 1, 2, 3, 4
    numVertices = vertices;
    adjMatrix = new int*[numVertices]; // ptrs (rows)

    for (int i = 0; i < numVertices; i++) {
        // traverse through rows and add numVertices amount of cols to each
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = INT_MAX;
        }
    }


}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {

    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // its an undirectional graph

}

void Graph::primMST() {

    bool* visited = new bool[numVertices];
    int* minWeight = new int[numVertices]; // could be called key, minimum weight edge to vertex (vertex num is index)
    int* mst = new int[numVertices]; // stores the mst
    for (int i = 0; i < numVertices; i++) {
        minWeight[i] = INT_MAX;
        mst[i] = -1;
        visited[i] = false;

    }


    minWeight[0] = 0; // Start vertex (0) has key 0.
    MinHeap heap(numVertices);

    // cur = (0,0)

    for (int i = 0; i < numVertices; i++) {
        heap.insert(i, minWeight[i]);
    }


    while (!heap.isEmpty()) {
        // add the min to the mst
        int min = heap.extractMin();

        visited[min] = true;

        // find neighbors in adjMatrix
        // neighbors are found in matrix by seeing which are in the same row
        for (int i = 0; i < numVertices; i++) {

            bool exists = adjMatrix[min][i] != INT_MAX;
            bool unvisited = !visited[i];
            bool better = adjMatrix[min][i] < minWeight[i];
            if (exists && unvisited && better) {
                minWeight[i] = adjMatrix[min][i];
                mst[i] = min;
                heap.decreaseKey(i, minWeight[i]);
            }
        }
    }

    // Print MST edges using mst[] and total weight using minWeight

    int totalWeight = 0;
    for (int i = 1; i < numVertices; i++) {
        if (mst[i] != -1) {
            std::cout << mst[i] + 1 << "--" << i + 1 << " (" << minWeight[i] << ")" << std::endl;
            totalWeight += minWeight[i];
        }
    }
    std::cout << "Total Cost: " << totalWeight << std::endl;

    delete[] minWeight;
    delete[] mst;
    delete[] visited;
};





