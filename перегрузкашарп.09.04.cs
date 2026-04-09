namespace ConsoleApp8
{

    class Vector2
    {
        public float X { get; set; }
        public float Y { get; set; }

        public Vector2(float x, float y) 
        {
            X = x;
            Y = y;

        }

        public static Vector2 operator +(Vector2 a, Vector2 b)
        {
            return new Vector2(a.X + b.X, a.X + b.Y);

        }
        public override string ToString() => $"Vector2 ({X}, {Y})";
        }

    internal class Program
        {

        static void Main(string[] args)
        {
            Vector2 a = new Vector2(11, 7);
            Vector2 b = new Vector2(10, 1);
            Vector2 result = a + b;
            Console.WriteLine(result.ToString());
        }
        
    }
}
