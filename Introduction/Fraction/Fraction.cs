//#define GET_SET

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Fraction
{
	internal class Fraction_OA
	{
		//int integer; // по умолчанию приват
		int numerator;
		int denominator;
		public int Integer // автосвойства. Переменная убирается
		{
			get;
			set;
		}

		public int Numerator
		{
			get { return numerator; }
			set { numerator = value; }
		}

		public int Denominator
		{
			get { return denominator; }
			set { 
				denominator = value;
				if (value == 0) denominator = 1;
			}
		}

#if GET_SET
		public int getItreger()
		{
			return integer;
		}

		public int getNumerator() 
		{
			return numerator;
		}

		public int getDenominator()
		{
			return denominator;
		}

		public void setInteger(int integer)
		{
			this.integer = integer;
		}

		public void setNumerator(int numerator)
		{
			this.numerator = numerator;
		}

		public void setDenominator(int denominator)
		{
			if (denominator == 0) denominator = 1;
			this.denominator = denominator;
		}
#endif

		public Fraction_OA()
		{
			Integer = numerator = 0;
			denominator = 1;
			Console.WriteLine($"DefaultConstructor:{this.GetHashCode()}") ;

        }

		public Fraction_OA(int integer)
		{
			this.Integer = integer;
			this.numerator = 0;
			this.denominator= 1;
            Console.WriteLine($"1AtgConstructor:\t{this.GetHashCode()}");
        }

		public Fraction_OA(int numerator, int denominator)
		{
			this.Integer = 0;
			Numerator = numerator;
			Denominator = denominator;
            Console.WriteLine($"Constructor{this.GetHashCode() }");


        }

		public Fraction_OA (int integer, int numerator, int denominator)
		{
			Integer= integer;
			Numerator = numerator;
			Denominator = denominator;
			Console.WriteLine($"Constructor:\t{ this.GetHashCode()}");
        }

		public Fraction_OA(double fraction)
		{
			Integer = (int)fraction;
			double a = fraction;
			int n = Integer;
			int den = 1;
			for (int i = 0; i < a.ToString().Length - Integer.ToString().Length - 1; i++)
			{
				a = a * 10;
				n = n * 10;
				den = den * 10;
			}
			Numerator = (int)(a - n);
			Denominator = den;
        }

		public Fraction_OA(Fraction_OA other)
		{
			this.Integer = other.Integer;
			this.Numerator = other.Numerator;
			this.Denominator = other.Denominator;
			Console.WriteLine($"CopyConstructor:\t{this.GetHashCode()}");

		}

		public void Print()
		{
			if(Integer!=0) Console.Write(Integer);
			if (numerator != 0)
			{
				if (Integer != 0) Console.Write("(");
				Console.Write($"{numerator}/{denominator}");
				if (Integer != 0) Console.Write(")");
			}
			else if(Integer == 0) Console.Write(0);
            Console.WriteLine();
        }

		public override string ToString()
		{
			string output = "";
			if (Integer != 0) output += Integer.ToString();
			if (numerator != 0)
			{
				if (Integer != 0) output += "(";
				output += $"{numerator}/{denominator}";
				if (Integer != 0) output += ")";
			}
			else if (Integer == 0) output = "0";
			return output;
		}

		public Fraction_OA toProper()
		{
			Integer += Numerator / Denominator;
			Numerator %= Denominator;
			return this;
		}

		public Fraction_OA toImproper()
		{
			Numerator += Integer * Denominator;
			Integer = 0;
			return this;
		}

		public Fraction_OA Inverted()
		{
			Fraction_OA inverted = new Fraction_OA(this);
			inverted.toImproper();
			(inverted.Numerator, inverted.Denominator) = (inverted.Denominator, inverted.Numerator);
			return inverted;
		}


		public static Fraction_OA operator *(Fraction_OA left, Fraction_OA right) //static значит что мы можем вызывать для всего класса
		{
			Fraction_OA left_copy = new Fraction_OA(left);
			Fraction_OA right_copy = new Fraction_OA(right);
			left_copy.toImproper();
			right_copy.toImproper();
			return new Fraction_OA(left_copy.Numerator * right_copy.Numerator, left_copy.Denominator * right_copy.Denominator).toProper();


		}

		public static Fraction_OA operator /(Fraction_OA left, Fraction_OA right)
		{
			return left * right.Inverted();


		}


	}
}
