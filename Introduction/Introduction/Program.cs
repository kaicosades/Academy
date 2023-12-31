﻿//#define CONSOLE_SETTING

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using System.Threading.Tasks;

namespace Introduction
{
    internal class Program
    {
        const string delimiter = "\n----------------------------------------------\n";
        static void Main(string[] args)
        {

#if CONSOLE_SETTING
            Console.Title = "Indroduction to .NET";

            Console.Beep(37, 500);

            int width = 120;
            int height = 32;

            Console SetBufferSize(width, height);
            Console SetWindowSize(width, height);

            Console.WriteLine("Buffer width\t" + Console.BufferWidth);
            Console.WriteLine("Buffer height\t" + Console.BufferHeight);
            Console.WriteLine(delimiter);
            Console.WriteLine("Window width\t" + Console.WindowWidth);
            Console.WriteLine("Window height\t" + Console.WindowHeight);

            Console.Write("Hello .NET");
            Console.WriteLine();

            Console.CursorLeft = 50;

            Console.WriteLine("Cursor position check");

            Console.SetCursorPosition(25, 7);
            Console.BackgroundColor = ConsoleColor.DarkGreen;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Cirsor position check2");
            Console.BackgroundColor = ConsoleColor.Black;

            Console.Write("Finita la comedia");
            //Console.ResetColor();
#endif

            Console.Write("Введите Ваше имя: ");
            string first_name = Console.ReadLine();

            Console.Write("Введите Вашу фамилию: ");
            string last_name = Console.ReadLine();

            Console.Write("Введите Ваш возраст: ");
            //int age = Console.Read();
            int age = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Имя: " + first_name + ", фамилия: " + last_name + ", возраст: " + age + " лет.");

            Console.WriteLine(string.Format("Имя: {0}, фамилия: {1}, возраст: {2} лет.", first_name, last_name, age));

            Console.WriteLine($"Имя: {first_name}, фамилия: {last_name}, возраст: {age} лет.");
        }
    }
}

