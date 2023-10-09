using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Academy
{
	internal class Student: Human
	{
		public string Speciality { get; set; }
		public string Group { get; set; }
		public double Rating { get; set; }
		public double Attendance { get; set; }

		public Student
			(
				string lastName, string firstName, int age,
				string speciality, string group, double rating, double attendance


			) : base(lastName, firstName, age)
				{
					Speciality = speciality;
					Group = group;
			Rating = rating;
			Attendance = attendance;
            Console.WriteLine($"SConstructor:\t{this.GetHashCode()}");
        }

		public Student(Student other) : base(other)
		{
			//this.Subject = other.Subject;
			Console.WriteLine($"SConstructor:\t{this.GetHashCode()}");
		}


		~Student()
		{
            Console.WriteLine($"SDestructor:\t{this.GetHashCode()}");
        }

		public override string ToString()
		{
			return $"{LastName} {FirstName} {Age} {Speciality} {Group} {Rating} {Attendance}";
		}

		public override void Print()
		{
			base.Print() ;
            Console.WriteLine("Speciality:\t" + Speciality);
            Console.WriteLine("Group:\t" + Group);
            Console.WriteLine("Rating:\t" + Rating);
            Console.WriteLine("Attendance:\t" + Attendance);
        }

	}
}
