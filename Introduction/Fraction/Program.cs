//#define TEST_1
//#define TEST_2

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using System.Value

namespace Fraction
{


	class Fraction
	{
		private int integer;
		private int numerator;
		private int denominator;

		public int get_integer() { return integer; }
		public int get_numerator() { return numerator; }
		public int get_denominator() { return denominator; }

		public void set_integer(int integer) { this.integer = integer; }
		public void set_numerator(int numerator) { this.numerator = numerator; }
		public void set_denominator(int denominator) { this.denominator = denominator; }

		public Fraction(int integer, int numerator, int denominator)
		{
			set_integer(integer);
			set_numerator(numerator);
			set_denominator(denominator);
		}

		public Fraction(int numerator, int denominator)
		{
			this.integer = 0;
			this.numerator = numerator;
			set_denominator(denominator);
		}

		~Fraction() { }

		public void print()
		{
			if (get_integer() != 0) Console.Write(get_integer());
			if (get_numerator() != 0)
			{
				if (get_integer() != 0) Console.Write("(");
				Console.Write(get_numerator() + "/" + get_denominator());
				if (get_integer() != 0) Console.Write(")");
			}
			else Console.Write(0);
			Console.WriteLine();
		}

		public Fraction to_improper()
		{
			numerator += integer * denominator;
			integer = 0;
			return this;
		}

		public Fraction to_proper()
		{
			integer += numerator / denominator;
			numerator %= denominator;
			return this;
		}

		public Fraction reduction()
		{
			int a = numerator;
			int b = denominator;
			while (a != 0 && b != 0)
			{
				if (a > b)
					a = a % b;

				else
					b = b % a;

			}
			numerator = numerator / (a + b);
			denominator = denominator / (a + b);
			return this;
		}






		public static Fraction operator *(Fraction left, Fraction right)
		{
			left.to_improper();
			right.to_improper();
			return new Fraction
			(
				left.get_numerator() * right.get_numerator(),
				left.get_denominator() * right.get_denominator()
			).to_proper();

		}


		public static bool operator >(Fraction left, Fraction right)
		{
			left.to_improper();
			right.to_improper();
			return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
		}

		public static bool operator <(Fraction left, Fraction right)
		{
			left.to_improper();
			right.to_improper();
			return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
		}


		public static bool operator >=(Fraction left, Fraction right)
		{
			return !(left < right);
		}

		public static bool operator <=(Fraction left, Fraction right)
		{
			return !(left > right);
		}







	}


	internal class Program
	{
		static void Main(string[] args)
		{
#if TEST_1
			Fraction one = new Fraction(1, 4, 5);
			one.print();
			one.to_improper();
			one.print();
			one.to_proper();
			one.print();
			Fraction two = new Fraction(2, 3, 4);
			// Console.WriteLine(one*two);
			one = one * two;
			one.print();
			if (one > two)
				two = one;
			two.to_proper();
			two.print();

			Fraction tree = new Fraction( 100, 5);
			tree.reduction();
			tree.print();
		
#endif

#if TEST_2

			Fraction_OA A = new Fraction_OA();
			//A.setInteger(22);
			//A.setNumerator(33);
			//A.setDenominator(44);
			//A.Print();
			A.Integer = 123;
			A.Numerator = 456;
			A.Denominator = 789;
            Console.WriteLine(A);

            Fraction_OA B = new Fraction_OA(5);
			B.Print();
            Console.WriteLine(B);

            Fraction_OA C = new Fraction_OA(2, 3);
			C.Print();
            Console.WriteLine(C);

            Fraction_OA D = new Fraction_OA(2, 3, 4);
			D.Print();
            Console.WriteLine(D);

			Fraction_OA E = new Fraction_OA (D);
            Console.WriteLine(E);
#endif
			Fraction_OA F = new Fraction_OA(1.95);
			F.Print();
            Console.WriteLine(F);

			Fraction_OA A = new Fraction_OA(2, 3, 4);
			Fraction_OA B = new Fraction_OA(3, 4, 5);
			Fraction_OA C = A * B;
            Console.WriteLine($" {A} * {B} = {C}");
            Console.WriteLine($" {A} / {B} = {A/B}");
        }

	}
}