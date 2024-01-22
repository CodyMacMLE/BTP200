#ifndef LECTURES_PERSON_H // Checking if header exists (if not defined)
#define LECTURES_PERSON_H // If not defined, defines the header

// Prefer passing custom objects by-reference or by-address
// All references or pointers should be constant (unless you have a good reason not to)
// All headers should have header guards
// 
// Never put "using namespace ... ;" in headers

namespace lectures
{
	class Person
	{
		char m_name[100 + 1];
		int m_height; // in cm

		
		/// <summary>
		/// returns true when the object is in an empty state
		/// </summary>
		/// <returns></returns>
		bool isEmpty() const;

		/// <summary>
		/// changes state to empty
		/// </summary>
		void setEmpty();
	public:

		/// <summary>
		/// Display a Person
		/// </summary>
		/// <param name="thePerson">The object reference of that student</param>
		void display(const Person& thePerson) const; // viewing therefor const

		/// <summary>
		/// Adding a Person by GUI
		/// </summary>
		void set(); // changing therefor not const

		/// <summary>
		/// Add person by mem function
		/// </summary>
		void set(const char* name, int height);
	};
}

#endif // Ends the definition of the header