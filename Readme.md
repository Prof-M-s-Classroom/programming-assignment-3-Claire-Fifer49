[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Claire Fifer

## Description
This program uses Prim's algorithm to find the Minimum Spanning Tree
of a graph. This is implemented with a custom minimum heap. Graph.cpp contains
the Prim's algorithm method.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logV)         |
| Extract Min          | O(logV)         |
| Decrease Key         | O(logV)         |
| Prim’s MST Overall   | O(ElogV)        |

Bubbling up and heapifying down take O(logV) time for a binary heap. 
Insert, extract, and decrease key all have to either bubble up or heapify down.
There are V insertions initially, V extract-min operations and for each edge you might have to do a decrease key which would be O(ElogV).
The dominant term is O(E log V) so that is the overall time complexity of Prim’s algorithm using a binary heap.

## Assumptions
It is assumed that there will be no disconnected graphs.

## Test Case Description

Input:  
Graph g2(6);
g2.addEdge(0, 1, 4);
g2.addEdge(0, 2, 3);
g2.addEdge(1, 2, 1);
g2.addEdge(1, 3, 2);
g2.addEdge(2, 3, 4);
g2.addEdge(3, 4, 2);
g2.addEdge(4, 5, 6);
g2.primMST();

Output:
3--2 (1)
1--3 (3)
2--4 (2)
4--5 (2)
5--6 (6)
Total Cost: 14