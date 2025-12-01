using System;

class Program
{
    static void Main()
    {
        int[] arr = new int[10];
        Random rnd = new Random();
        
        for (int i = 0; i < 10; i++)
        {
            arr[i] = rnd.Next(-50, 51);
        }

        Console.WriteLine("Massive: " + string.Join(" ", arr));

        Console.Write("chetnie polozhitelnie: ");
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] > 0 && arr[i] % 2 == 0)
            {
                Console.Write(arr[i] + " ");
            }
        }

        int sumNeg = 0;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] < 0) sumNeg += arr[i];
        }
        Console.WriteLine($"\nSum of negative: {sumNeg}");

        int min = arr[0], max = arr[0];
        for (int i = 1; i < 10; i++)
        {
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];
        }
        Console.WriteLine($"Min: {min}, Max: {max}");
    }
}
