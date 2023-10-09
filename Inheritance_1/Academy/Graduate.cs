using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Academy
{
	internal class Graduate : Student
	{
		public string Subject{ get; set; }
		//public 

		public Graduate
			(
			string lastName, string firstName, int age, string speciality, string group, double rating, double attendance,
			string subject

			):base(lastName,  firstName,  age,  speciality,  group,  rating,  attendance)
		{
			Subject = subject;
			Console.WriteLine($"GConstructor:\t{this.GetHashCode()}");

		}

		public Graduate(Graduate other):base(other)
		{
			this.Subject = other.Subject;
            Console.WriteLine($"GConstructor:\t{this.GetHashCode()}");
        }

		~Graduate()
		{
			Console.WriteLine($"GDestructor:\t{this.GetHashCode()}");
		}

		public override string ToString()
		{
			return $"{LastName} {FirstName} {Age} {Speciality} {Group} {Rating} {Attendance} {Subject} ";
		}

		public override void Print()
		{
			base.Print();
            Console.WriteLine("Sybject: " + Subject);
        }
	}
}
