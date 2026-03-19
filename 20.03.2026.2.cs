//задание 1
using System;
using System.Collections.Generic;

class Graph
{
    private int nodesCount;
    private List<int>[] adjacencyList;
    private Random rand = new Random();

    public Graph(int n)
    {
        nodesCount = n;
        adjacencyList = new List<int>[n];
        for (int i = 0; i < n; i++)
        {
            adjacencyList[i] = new List<int>();
        }
    }

    public void FillRandom()
    {
        for (int i = 0; i < nodesCount; i++)
        {
            int edgesCount = rand.Next(1, 6); // 1-5 ребер на узел
            for (int j = 0; j < edgesCount; j++)
            {
                int neighbor = rand.Next(nodesCount);
                if (neighbor != i && !adjacencyList[i].Contains(neighbor))
                {
                    adjacencyList[i].Add(neighbor);
                }
            }
        }
    }

    public void DFS(int start)
    {
        bool[] visited = new bool[nodesCount];
        DFSUtil(start, visited);
    }

    private void DFSUtil(int node, bool[] visited)
    {
        visited[node] = true;
        Console.WriteLine($"Visited node: {node}");

        foreach (var neighbor in adjacencyList[node])
        {
            if (!visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }
}

class Program
{
    static void Main()
    {
        Graph graph = new Graph(1000);
        graph.FillRandom();

        Console.WriteLine("Starting DFS from node 0:");
        graph.DFS(0);

        Console.WriteLine("DFS completed.");
    }
}

//задание 2
using System;
using System.Collections.Generic;

class Graph
{
    private int nodesCount;
    private List<int>[] adjacencyList;
    private Random rand = new Random();

    public Graph(int n)
    {
        nodesCount = n;
        adjacencyList = new List<int>[n];
        for (int i = 0; i < n; i++)
        {
            adjacencyList[i] = new List<int>();
        }
    }

    public void FillRandom()
    {
        for (int i = 0; i < nodesCount; i++)
        {
            int edgesCount = rand.Next(1, 6);
            for (int j = 0; j < edgesCount; j++)
            {
                int neighbor = rand.Next(nodesCount);
                if (neighbor != i && !adjacencyList[i].Contains(neighbor))
                {
                    adjacencyList[i].Add(neighbor);
                }
            }
        }
    }

    // Обход в ширину
    public void BFS(int start)
    {
        bool[] visited = new bool[nodesCount];
        Queue<int> queue = new Queue<int>();

        visited[start] = true;
        queue.Enqueue(start);

        while (queue.Count > 0)
        {
            int node = queue.Dequeue();
            Console.WriteLine($"Visited node: {node}");

            foreach (var neighbor in adjacencyList[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.Enqueue(neighbor);
                }
            }
        }
    }
}

class Program
{
    static void Main()
    {
        Graph graph = new Graph(1000);
        graph.FillRandom();

        Console.WriteLine("Starting BFS from node 0:");
        graph.BFS(0);

        Console.WriteLine("BFS completed.");
    }
}
