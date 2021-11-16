// A C++ program for Bellman-Ford's single source 
// shortest path algorithm.
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

const string location[] = { "Math-Comp Science", "Lewis Science Center", "Speech Language Hearing",
"College Square", "Prince Center", "Burdick", "Torreyson Library", "Maintenance", "Old Main", "Police Dept.",
"Fine Art", "McAlister Hall", "Student Center", "Wingo",
"Student Health Center", "New Business Building",
"Oak Tree Apt.", "Brewer-Hegeman", "Bear Village Apt." };

// a structure to represent a weighted edge in graph
struct Edge
{
	int src, dest, weight;
};

// a structure to represent a connected, directed and 
// weighted graph
struct Graph
{
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

// Prints distance from the source
void printArr(int dist[], int n)
{
	printf("Building                              Distance from Source\n\n");
	for (int i = 0; i < n; ++i)
		printf("%s \t\t\t\t %d\n", location[i].c_str(), dist[i]);
}

// Finds shortest distance of each node from src using Bellman Ford Alg.
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int *dist;
	dist = new int[V];

	// Sets all distances to infinity
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Checks every single edge
	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[v] != INT_MAX && dist[v] + weight < dist[u])
				dist[u] = dist[v] + weight;

			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	printArr(dist, V);

	return;
}

// Finds shortest distance of each node from src using Dijkstras Alg.
void Dijkstras(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int *dist;
	dist = new int[V];
	queue <int> q;

	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		q.push(i);
	}
	dist[src] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int j = 0; j < E; j++)
		{
			int w = graph->edge[j].src;
			int v = graph->edge[j].dest;

			if (u == w || v == u)
			{
				int weight = graph->edge[j].weight;
				if (dist[v] != INT_MAX && dist[w] > dist[v] + weight)
				{
					dist[w] = dist[v] + weight;
				}


				if (dist[w] != INT_MAX && dist[v] > dist[w] + weight)
				{
					dist[v] = dist[w] + weight;
				}

			}

		}
		int *temp = new int[q.size()];
		queue <int> temp1 = q;
		queue <int> temp2;

		int b = dist[0];
		for (int i = 0; i < q.size(); i++)
		{
			if (dist[i] < b)
				b = i;
		}
		while (!temp1.empty())
		{
			if (temp1.front() != b)
				temp2.push(temp1.front());
			temp1.pop();
		}
		q = temp2;
	}
	printArr(dist, V);

}

// Main
int main()
{
	// creates graph given # of vertices and edges
	int V = 19;  // Number of vertices in graph
	int E = 36;  // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	// adding each edge individually
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 150;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 4;
	graph->edge[1].weight = 80;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 5;
	graph->edge[2].weight = 30;

	graph->edge[3].src = 0;
	graph->edge[3].dest = 6;
	graph->edge[3].weight = 40;

	graph->edge[4].src = 1;
	graph->edge[4].dest = 2;
	graph->edge[4].weight = 250;

	graph->edge[5].src = 1;
	graph->edge[5].dest = 3;
	graph->edge[5].weight = 200;

	graph->edge[6].src = 2;
	graph->edge[6].dest = 5;
	graph->edge[6].weight = 100;

	graph->edge[7].src = 3;
	graph->edge[7].dest = 4;
	graph->edge[7].weight = 300;

	graph->edge[8].src = 4;
	graph->edge[8].dest = 6;
	graph->edge[8].weight = 30;

	graph->edge[9].src = 4;
	graph->edge[9].dest = 9;
	graph->edge[9].weight = 100;

	graph->edge[10].src = 5;
	graph->edge[10].dest = 6;
	graph->edge[10].weight = 80;

	graph->edge[11].src = 5;
	graph->edge[11].dest = 7;
	graph->edge[11].weight = 300;

	graph->edge[12].src = 5;
	graph->edge[12].dest = 11;
	graph->edge[12].weight = 200;

	graph->edge[13].src = 6;
	graph->edge[13].dest = 8;
	graph->edge[13].weight = 30;

	graph->edge[14].src = 7;
	graph->edge[14].dest = 11;
	graph->edge[14].weight = 150;

	graph->edge[15].src = 7;
	graph->edge[15].dest = 13;
	graph->edge[15].weight = 100;

	graph->edge[16].src = 7;
	graph->edge[16].dest = 15;
	graph->edge[16].weight = 150;

	graph->edge[17].src = 7;
	graph->edge[17].dest = 16;
	graph->edge[17].weight = 160;

	graph->edge[18].src = 8;
	graph->edge[18].dest = 9;
	graph->edge[18].weight = 200;

	graph->edge[19].src = 8;
	graph->edge[19].dest = 10;
	graph->edge[19].weight = 90;

	graph->edge[20].src = 8;
	graph->edge[20].dest = 11;
	graph->edge[20].weight = 100;

	graph->edge[21].src = 9;
	graph->edge[21].dest = 10;
	graph->edge[21].weight = 50;

	graph->edge[22].src = 9;
	graph->edge[22].dest = 14;
	graph->edge[22].weight = 100;

	graph->edge[23].src = 10;
	graph->edge[23].dest = 11;
	graph->edge[23].weight = 180;

	graph->edge[24].src = 10;
	graph->edge[24].dest = 12;
	graph->edge[24].weight = 80;

	graph->edge[25].src = 11;
	graph->edge[25].dest = 12;
	graph->edge[25].weight = 100;

	graph->edge[26].src = 11;
	graph->edge[26].dest = 13;
	graph->edge[26].weight = 200;

	graph->edge[27].src = 12;
	graph->edge[27].dest = 13;
	graph->edge[27].weight = 100;

	graph->edge[28].src = 12;
	graph->edge[28].dest = 14;
	graph->edge[28].weight = 50;

	graph->edge[29].src = 12;
	graph->edge[29].dest = 15;
	graph->edge[29].weight = 110;

	graph->edge[30].src = 13;
	graph->edge[30].dest = 15;
	graph->edge[30].weight = 50;

	graph->edge[31].src = 14;
	graph->edge[31].dest = 17;
	graph->edge[31].weight = 200;

	
	graph->edge[32].src = 15;
	graph->edge[32].dest = 17;
	graph->edge[32].weight = 20;

	graph->edge[33].src = 16;
	graph->edge[33].dest = 17;
	graph->edge[33].weight = 40;

	graph->edge[34].src = 17;
	graph->edge[34].dest = 18;
	graph->edge[34].weight = 350;

	graph->edge[35].src = 15;
	graph->edge[35].dest = 16;
	graph->edge[35].weight = 30;
	
	//graph->edge[36].src = 1;
	//graph->edge[36].dest = 0;
	//graph->edge[36].weight = 150;

	cout << "Bellman-Ford:" << endl;
	//Runs each algorithm and displays distance from Math/CS building
	BellmanFord(graph, 0);
	cout << endl << endl << "Dijkstras:" << endl;
	Dijkstras(graph, 0);
	return 0;
}
