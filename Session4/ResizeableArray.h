#ifndef LECTURES_RESIZEABLE_ARRAY_H
#define LECTURES_RESIZEABLE_ARRAY_H
#include <iostream>

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
		double* m_arr; // = nullptr; // adding the declaration here tells the compiler the insert it into the default constructor
		/// <summary>
		/// Stores the size of the array
		/// </summary>
		int m_cnt; // = 0;

	public:
		/// <summary>
		/// Default constructor:
		/// Initializes to an empty state (to a default state)
		/// </summary>
		ResizeableArray(); // = default; // making the constructor default

		/// <summary>
		/// Initializes to a state with size of n
		/// </summary>
		/// <param name="cnt">The size to inititalize the array</param>
		explicit ResizeableArray(int cnt);

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
		/// Appends one to the end of the array
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		ResizeableArray& operator+=(double value);

		/// <summary>
		/// Appends the array to another array
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		ResizeableArray& operator+=(const ResizeableArray& other);

		/// <summary>
		/// prefeix ++ , adds one to each index
		/// </summary>
		/// <returns></returns>
		ResizeableArray& operator++();

		/// <summary>
		/// Checking if array has a value
		/// </summary>
		explicit operator bool() const; //explicit in front means this operator can not be used in automatic conversion (only when a boolean is called)

		operator double() const;

		/// <summary>
		/// Deconstructor:
		/// Cleans up any dynamic memory in use by this object
		/// </summary>
		~ResizeableArray();

		friend std::ostream& operator <<(std::ostream& out, const ResizeableArray& arr);
	};
	// a free helper function due to not needed the member this (this, is always put as the first param inside the class), and cout is the first param
	//std::ostream& operator <<(std::ostream& out, const ResizeableArray& arr);
}
#endif

