//1 задание
using System;
using System.Collections.Generic;

class Program
{
    static Dictionary<string, List<string>> graph = new Dictionary<string, List<string>>()
    {
        {"A", new List<string> {"B", "C"}},
        {"B", new List<string> {"D"}},
        {"C", new List<string>()},
        {"D", new List<string>()},
        {"E", new List<string>()},
        {"F", new List<string>()} 
    };

    static bool DFS(string current, string target, HashSet<string> visited, List<string> path)
    {
        visited.Add(current);
        path.Add(current);

       
        if (current == target)
            return true;

        
        if (graph.ContainsKey(current))
        {
            foreach (var neighbor in graph[current])
            {
                if (!visited.Contains(neighbor))
                {
                    if (DFS(neighbor, target, visited, path))
                        return true;
                }
            }
        }

      
        path.RemoveAt(path.Count - 1);
        return false;
    }

    static void Main()
    {
        string startVertex = "A";
        string endVertex = "F";

        var visited = new HashSet<string>();
        var path = new List<string>();

        bool pathExists = DFS(startVertex, endVertex, visited, path);

        if (pathExists)
        {
            Console.WriteLine("Путь найден: " + string.Join(" -> ", path));
        }
        else
        {
            Console.WriteLine("Путь не найден");
        }
    }
}

//задание 2
using System;
using System.Collections.Generic;

class Program
{
    
    static Dictionary<string, List<(string neighbor, int weight)>> graph = new Dictionary<string, List<(string, int)>>()
    {
        {"A", new List<(string, int)> {("B", 2), ("C", 5)}},
        {"B", new List<(string, int)> {("C", 1)}},
        {"C", new List<(string, int)> {("D", 3)}},
        {"D", new List<(string, int)>()}
    };

    static void Dijkstra(string start)
    {
        var dist = new Dictionary<string, int>();
        var visited = new HashSet<string>();
        var pq = new PriorityQueue<string, int>();

      
        foreach (var vertex in graph.Keys)
        {
            dist[vertex] = int.MaxValue;
        }
        dist[start] = 0;

        pq.Enqueue(start, 0);

        while (pq.Count > 0)
        {
            var current = pq.Dequeue();

            if (visited.Contains(current))
                continue;

            visited.Add(current);

            if (graph.ContainsKey(current))
            {
                foreach (var (neighbor, weight) in graph[current])
                {
                    int newDist = dist[current] + weight;
                    if (newDist < dist[neighbor])
                    {
                        dist[neighbor] = newDist;
                        pq.Enqueue(neighbor, newDist);
                    }
                }
            }
        }

     
        foreach (var vertex in graph.Keys)
        {
            string distanceStr = dist[vertex] == int.MaxValue ? "бесконечно" : dist[vertex].ToString();
            Console.WriteLine($"{vertex} = {distanceStr}");
        }
    }

    static void Main()
    {
        Console.WriteLine("Кратчайшие расстояния от вершины A:");
        Dijkstra("A");
    }
}
