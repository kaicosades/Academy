using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

//int Sum( int[] arr, const int n);
//void Sum();

namespace Array
{
	
	
	internal class Program
	{

		static double arr_Sum(int[] arr, int n)
		{
			return Function(arr, n, 0);
		}
		static double arr_Min(int[] arr, int n)
		{
			return Function(arr, n, 1);
		}
		static double arr_Max(int[] arr, int n)
		{
			return Function(arr, n, 2);
		}
		static double arr_Avg(int[] arr, int n)
		{
			return Function(arr, n, 3);
		}
		static double Function(int[] arr, int n, int index)
		{
			int a_max = arr[0];
			int a_min = arr[0];
			double a_sum = arr[0];
			for (int i = 1; i < arr.Length; i++)
			{
				a_sum += arr[i];
				if (arr[i] > a_max) a_max = arr[i];
				if (arr[i] < a_min) a_min = arr[i];
			}
			if(index==0) return a_sum;
			if(index==1) return a_min;
			if(index==2) return a_max;
			if(index==3) return a_sum/n;
			return 0;
		}


		static double i_arr_2_Sum(int[,] i_arr_2, int rows, int cols)
		{
			return Function_2(i_arr_2, rows, cols, 0);
		}

		static double i_arr_2_Min(int[,] i_arr_2, int rows, int cols)
		{
			return Function_2(i_arr_2, rows, cols, 1);
		}

		static double i_arr_2_Max(int[,] i_arr_2, int rows, int cols)
		{
			return Function_2(i_arr_2, rows, cols, 2);
		}

		static double i_arr_2_Avg(int[,] i_arr_2, int rows, int cols)
		{
			return Function_2(i_arr_2, rows, cols, 3);
		}

		static double Function_2(int[,] i_arr_2, int rows, int cols, int index)
		{
			int b_max = i_arr_2[0, 0];
			int b_min = i_arr_2[0, 0];
			double b_sum = 0;
			for (int i = 0; i < i_arr_2.GetLength(0); i++)
			{
				for (int j = 0; j < i_arr_2.GetLength(1); j++)
				{
					b_sum += (i_arr_2[i, j]);
					if (i_arr_2[i, j] > b_max) b_max = i_arr_2[i, j];
					if (i_arr_2[i, j] < b_min) b_min = i_arr_2[i, j];
				}
			}
			if (index == 0) return b_sum;
			if (index == 1) return b_min;
			if (index == 2) return b_max;
			if (index == 3) return b_sum/(rows*cols);
			return 0;
		}





		static readonly string delimiter = "\n--------------------------------------\n";
		static void Main(string[] args)
		{
			
			Console.Write("Введите размер массива: ");
			int n = Convert.ToInt32(Console.ReadLine());
			int[] arr = new int[n];
			Random rand = new Random(0);	//создаем объект класса Random 
			for(int i=0; i<arr.Length; i++)
			{
				arr[i] = rand.Next(100, 200);
			}

			for(int i=0; i< arr.Length; i++)
			{
				Console.Write(arr[i] + "\t");
			}
            Console.WriteLine();


			foreach (int i in arr)
			{
				Console.Write(i + "\t");
			}
			Console.WriteLine();
            Console.WriteLine(delimiter);



            Console.Write("Введите количество строк: ");
			int rows = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите количество элементов строки: ");
			int cols = Convert.ToInt32(Console.ReadLine());
			int[,] i_arr_2 = new int[rows,cols];

			for(int i=0; i<rows; i++)
			{
				for(int j=0; j< cols; j++)
				{
					i_arr_2[i, j] = rand.Next(100);
				}
			}
			for (int i = 0; i < i_arr_2.GetLength(0); i++)
			{
				for (int j = 0; j < i_arr_2.GetLength(1); j++)
				{
					Console.Write(i_arr_2 [i,j] + "\t");
                }
                Console.WriteLine();
            }



			foreach (int i in i_arr_2)
			{
                Console.Write(i+ "\t");
            }
            Console.WriteLine();
			Console.WriteLine(delimiter);



			int[][] jagged_arr = new int[][] //зубчатый массив одномерных массивов
			{
				new int[] {3,5,8,13,21},
				new int[] {34, 55,89},
				new int[] {144,233,377,610}
			};

			for (int i = 0; i < jagged_arr.Length; i++)
			{
				for (int j = 0; j < jagged_arr[i].Length; j++)
				{
					Console.Write(jagged_arr[i][j] + "\t");
				}
				Console.WriteLine();
			}
			Console.WriteLine();
			Console.WriteLine(delimiter);


			int c_max = jagged_arr[0][0];
			int c_min = jagged_arr[0][0];
			double c_sum = 0;
			int m = 0;
			for (int i = 0; i < jagged_arr.Length; i++)
			{
				for (int j = 0; j < jagged_arr[i].Length; j++)
				{
					c_sum += jagged_arr[i][j];
					if(jagged_arr[i][j]>c_max) c_max = jagged_arr[i][j]; 
					if(jagged_arr[i][j]<c_min) c_min = jagged_arr[i][j];
					m++;
				}
			}
			



			int[][,] jagged_arr_2 = new int[][,]
				{
					i_arr_2,
					new int[,]
					{
						{ 256, 384,512,768},
						{1024, 2048,3072,4096 }
					}
				};

			
			for (int i = 0; i < jagged_arr_2.Length; i++)
			{
				for (int j = 0; j < jagged_arr_2[i].GetLength(0); j++)
				{
					for (int ij = 0; ij < jagged_arr_2[i].GetLength(1); ij++) Console.Write(jagged_arr_2[i][j,ij] + "\t");
					Console.WriteLine();
				}
				Console.WriteLine();
			}

			int d_max = jagged_arr_2[0][0, 0];
			int d_min = jagged_arr_2[0][0, 0];
			double d_sum = 0;
			int mm = 0;
			for (int i = 0; i < jagged_arr_2.Length; i++)
			{
				for (int j = 0; j < jagged_arr_2[i].GetLength(0); j++)
				{
					for (int ij = 0; ij < jagged_arr_2[i].GetLength(1); ij++)
					{
						d_sum += jagged_arr_2[i][j, ij];
						if (jagged_arr_2[i][j, ij] > d_max) d_max = jagged_arr_2[i][j, ij];
						if (jagged_arr_2[i][j, ij] < d_min) d_min = jagged_arr_2[i][j, ij];
						mm++;
					}
				}
				Console.WriteLine();
			}
			Console.WriteLine(delimiter);


           // Console.WriteLine(a_max);
           // Console.WriteLine(a_min);
           // Console.WriteLine(b_max);
           // Console.WriteLine(b_min);
            Console.WriteLine(c_max);
            Console.WriteLine(c_min);
            Console.WriteLine(d_max);
            Console.WriteLine(d_min);
           // Console.WriteLine(a_sum);
            //Console.WriteLine(b_sum);
            Console.WriteLine(c_sum);
			Console.WriteLine(d_sum) ;
           // Console.WriteLine(a_sum/ arr.Length);
			//Console.WriteLine(b_sum/ (rows * cols));
			Console.WriteLine(c_sum / m);
            Console.WriteLine(d_sum / mm);
            //сумму элементов, среднее-арифметическое, минимальное и максимальное значение для всех массивов;

           // Console.WriteLine(arr_Sum(arr, n));
          //  Console.WriteLine(arr_Min(arr, n));
           // Console.WriteLine(arr_Max(arr, n));
          //  Console.WriteLine(arr_Avg(arr, n));

           // Console.WriteLine(i_arr_2_Sum(i_arr_2, rows, cols));
            //Console.WriteLine(i_arr_2_Min(i_arr_2, rows, cols));
           // Console.WriteLine(i_arr_2_Max(i_arr_2, rows, cols));
           // Console.WriteLine(i_arr_2_Avg(i_arr_2, rows, cols));


        }
	}
	

}
