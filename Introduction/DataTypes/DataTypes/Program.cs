#define LOGICAL_TYPES
#define CHARACTER_TYPES
#define ITEGRAL_TYPES
#define FLOATING_TYPES

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataTypes
{
	internal class Program
	{
		static readonly string delimeter = "\n-----------------------------------------------------\n";
		static void Main(string[] args)
		{
#if LOGICAL_TYPES
			Console.WriteLine("BOOL: ");
			Console.WriteLine(sizeof(bool));    //Boolean
			Console.WriteLine(true);
			Console.WriteLine(true.GetType());
            Console.WriteLine(delimeter);

#endif
#if CHARACTER_TYPES
			Console.WriteLine("CHAR: ");		//хранит 1 символ в кодировке Unicode
			Console.WriteLine(sizeof(char));
			Console.WriteLine((int)char.MinValue);
			Console.WriteLine((int)char.MaxValue);
			Console.WriteLine(delimeter);
#endif
#if ITEGRAL_TYPES
			Console.WriteLine("SHORT: ");
            Console.WriteLine(sizeof(ushort));
            Console.WriteLine("USHORT:\t" + ushort.MinValue + " ... " + ushort.MaxValue);
            Console.WriteLine(" SHORT:\t" + short.MinValue + " ... " + short.MaxValue);
			Console.WriteLine(delimeter);

			Console.WriteLine("INT: ");
			Console.WriteLine(sizeof(int));
			Console.WriteLine("UINT:\t" + uint.MinValue + " ... " + uint.MaxValue);
			Console.WriteLine(" INT:\t" + int.MinValue + " ... " +int.MaxValue);
			Console.WriteLine(delimeter);

			Console.WriteLine("LONG: ");
			Console.WriteLine(sizeof(int));
			Console.WriteLine("ULONG:\t" + ulong.MinValue + " ... " + ulong.MaxValue);
			Console.WriteLine(" LONG:\t" + long.MinValue + " ... " + long.MaxValue);
			Console.WriteLine(delimeter);
#endif
#if FLOATING_TYPES
            Console.WriteLine("FLOAT:\t" + sizeof(float) + " Bytes");
            Console.WriteLine(float.MinValue + " ... " + float.MaxValue);
			Console.WriteLine(delimeter);

			Console.WriteLine("DOUBLE:\t" + sizeof(double) + " Bytes");
			Console.WriteLine(double.MinValue + " ... " + double.MaxValue);
			Console.WriteLine(delimeter);

		}
	}
}
