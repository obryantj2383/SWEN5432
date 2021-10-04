using System;
using System.Runtime.InteropServices;

namespace ConsoleApp
{
    class Program
    {
        static void Main()
        {
            Span<byte> data = stackalloc byte[20];
            GetBytes(0, data, 0);
            GetBytes(123.45F, data, 4);
            GetBytes(123.45D, data, 8);
        }

        static unsafe void GetBytes(float value, Span<byte> buffer, int offset)
            => MemoryMarshal.Cast<byte, float>(buffer.Slice(offset))[0] = value;
        static unsafe void GetBytes(double value, Span<byte> buffer, int offset)
            => MemoryMarshal.Cast<byte, double>(buffer.Slice(offset))[0] = value;
    }
}
