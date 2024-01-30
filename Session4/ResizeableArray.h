#ifndef LECTURES_RESIZEABLE_ARRAY_H
#define LECTURES_RESIZEABLE_ARRAY_H

// Constructors
// - Don't return
// - haver the name of the class
// - Thet are called automatically when a new object is created
// - only compiler can call them, client can not
// - can be overloaded
// - constructor initialize ALL attributes

// Destructors:
// - Don't return
// - Have the name of the class preceeded by '~'
// - They are called automatically when an instance goes out of scope
// - programmers SHOULD NOT call them automatically
// - only handle resources (ie dynamically allocated memory)
// - Can not be overloaded

namespace lectures
{
	class ResizeableArray
	{
		/// <summary>
		///  Stores the address of a dynamically allocated array
		/// </summary>
		double* m_arr;
		/// <summary>
		/// Stores the size of the array
		/// </summary>
		int m_cnt;

	public:
		/// <summary>
		/// Default constructor:
		/// Initializes to an empty state (to a default state)
		/// </summary>
		ResizeableArray();

		/// <summary>
		/// Adds an item of type double to the end of an array
		/// </summary>
		/// <param name=item>The item to add</param>
		void addItem(double item);

		/// <summary>
		/// Displays the current array
		/// </summary>
		void display() const;
		
		/// <summary>
		/// Deconstructor:
		/// Cleans up any dynamic memory in use by this object
		/// </summary>
		~ResizeableArray();
	};
}
#endif

