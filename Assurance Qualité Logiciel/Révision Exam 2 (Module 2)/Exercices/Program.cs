using System;
class ArrayExample
{
    static void Main()
    {
        char[] letters = { 'A', 'l', 'e', 'x', ' ', 'S', 'm', 'i', 't', 'h' };
        string name = "";
        int[] a = new int[10];
        for (int i = 0; i < letters.Length; i++)
        {
            name += letters[i];
            a[i] = i + 1;
            SendMessage(name, a[i]);
        }
        Console.ReadKey();
    }
    static void SendMessage(string name, int msg)
    {
        Console.WriteLine("Bonjour, " + name + "! compte jusqu'à " + msg);
    }
}