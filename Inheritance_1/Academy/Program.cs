using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Academy
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Human human = new Human("Montana", "Antonio", 30);
          //  Console.WriteLine(human);

			Student student = new Student("Pincman", "Jessie", 25, "Chemistry", "WW_220", 90, 99);
          //  Console.WriteLine(student);

			Teacher teacher = new Teacher("White", "Walter", 50, "Chemistry", 25);
           // Console.WriteLine(teacher);

			Graduate graduate = new Graduate("Vasiliy", "Tupenko", 26, "Chemistry", "WWW_22200", 50, 50, "Subject");
			//Console.WriteLine(graduate);

			Student tommy = new Student(human, "Theft", "Vise", 98, 99);
			
			Human[] group = new Human[] { student, teacher, graduate, tommy, 
				new Teacher("Diaz", "Ricardo", 50, "Weapons distribution" , 25) };
			for(int i =0; i<group.Length; i++)
			{
				//Console.WriteLine(group[i]);
				group[i].Print();
            }

        }
	}
}
