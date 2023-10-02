//#define KALKULATOR
//#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4
//#define KALKULATOR_OA

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kalkulator
{
	internal class Program
	{
		static void Main(string[] args)
		{
#if KALKULATOR
			string expression = (Console.ReadLine());
			double a =0;
			double b = 0;
			int j = 0;
			for (int i = 0; expression[i]!=' '; i++)
			{
				a = a * 10 + Convert.ToInt32(expression[i]) - 48;
				j++;
			}
			for(int i = j+3; (expression[i]) != ' '; i++)
			{
				b = b * 10 +  Convert.ToInt32(expression[i]) - 48;
			}
			switch (expression[j + 1])
			{
				case '+': Console.Write("= " + (a + b)); break;
                case '-': Console.Write("= "+ (a - b)); break;
				case '/': Console.Write("= "+ (a / b)); break;
				case '*': Console.Write("= "+ (a * b)); break;

			}
#endif

#if TASK_1
			//Console.Read
			string s_money = Console.ReadLine();
			s_money = s_money.Replace('.', ',');
            Console.WriteLine(s_money);
            double i = Convert.ToDouble(s_money);
			int j;
			j = (int)i;						//рубли
			i = Convert.ToInt32((i - j) * 100);			//копейки
            Console.WriteLine(j + " рублей " + i + " копеек");


#endif

#if TASK_2
			Console.WriteLine("Введите исходные данные:");
			Console.Write("Цена тетради (руб.): "); float i = (float)Convert.ToDouble(Console.ReadLine());
			Console.Write("Количество тетрадей: "); int n = Convert.ToInt32(Console.ReadLine());
			Console.Write("Цена карандаша (руб.): "); float j = (float)Convert.ToDouble(Console.ReadLine());
			Console.Write("Количество карандашей: "); int m = Convert.ToInt32(Console.ReadLine());
			Console.Write("Стоимость всей покупки: " + (i*n + j*m) + " рублей.");
#endif

#if TASK_3
			Console.WriteLine("Введите исходные данные:");
			Console.Write("Цена тетради (руб.): "); float i = (float)Convert.ToDouble(Console.ReadLine());
			Console.Write("Цена обложки (руб.): "); float j = (float)Convert.ToDouble(Console.ReadLine());
			Console.Write("Количество комплектов: "); int n = Convert.ToInt32(Console.ReadLine());
			Console.Write("Стоимость всей покупки: " + ((i + j) *n) + " рублей.");
#endif

#if TASK_4
Console.WriteLine("Вычисление стоимости поездки на дачу и обратно.");
			Console.Write("Расстояние до дачи (км): "); float i = (float)Convert.ToDouble(Console.ReadLine());
			Console.Write("Расход бензина (литров на 100 км пробега): "); float j = (float)Convert.ToDouble(Console.ReadLine());
			Console.Write("Цена литра бензина (руб.) "); float n = (float)Convert.ToDouble(Console.ReadLine());
			Console.Write("Поездка на дачу и обратно обойдется в " + (i * 2 * n * j/100) + " рублей.");
#endif

#if KALKULATOR_OA
			Console.WriteLine("Введите арифметическое выражение: ");
			string expression = Console.ReadLine();
            Console.WriteLine(expression);
			string[] operands = expression.Split('+', '-', '*', '/');
			double a = Convert.ToDouble(operands[0]);
			double b = Convert.ToDouble(operands[1]);
			if (expression.Contains("+")) Console.WriteLine($" {a} + {b} = {a+b}");		// без $ выводится просто выражение в скобках
			else if (expression.Contains("-")) Console.WriteLine($" {a} - {b} = {a-b}");
			else if (expression.Contains("*")) Console.WriteLine($" {a} * {b} = {a*b}");
			else if (expression.Contains("/")) Console.WriteLine($" {a} / {b} = {a/b}");
			else Console.WriteLine("Error: No operation");
#endif

		}

	}
}
