#ifndef SENECA_CAR_H
#define SENECA_CAR_H

// TODO: put all entities you create in `seneca` namespace.  Create and add the member functions
//           as described in the comments below.

namespace seneca 
{
	const char* const INVALID_REASON__PLATE = "Received bad value for license plate.";
	const char* const INVALID_REASON__MODEL = "Received bad value for car model.";
	const char* const INVALID_REASON__DESC = "Received bad value for problem description.";
	const char* const INVALID_REASON__EMPTY = "Object not initialized.";
	const char* const VALID_OBJECT = "The object contains valid data and can be used.";

	/// <summary>
	/// A class that represents a `Car` object that requires service from
	///     an AutoService.
	/// </summary>
	class Car
	{
		/// <summary>
		/// A statically-allocated C-style array of characters containing
		///     the license plate number of the car.
		/// </summary>
		char m_licencePlate[9];
		/// <summary>
		/// A dynamically-allocated C-style array of characters containing
		///     the make/model of the car.
		/// </summary>
		char* m_makeModel;
		/// <summary>
		/// A dynamically-allocated C-style array of characters containing
		///     a description of the problem as reported by the customer.
		/// </summary>
		char* m_problemDesc;
		/// <summary>
		/// An estimation of the cost to repair the problem reported by a customer.
		/// </summary>
		double m_cost;

		/// <summary>
		/// A C-style string with a descriptive text if the object contains
		///     good data and can be used, or the reason why data was not accepted.
		/// 
		/// This attribute will contain the value of one of the global variables:
		/// INVALID_REASON__PLATE
		/// INVALID_REASON__MODEL
		/// INVALID_REASON__DESC 
		/// INVALID_REASON__EMPTY
		/// VALID_OBJECT
		/// 
		/// This is not a dynamically-allocated string and doesn't require deallocation.
		/// </summary>
		const char* m_objectStatus;
	public:
		/// <summary>
		/// Check if the `Car` object contains valid data and can be used.
		/// </summary>
		/// <returns>`true` if the object contains valid data; `false` otherwise.</returns>
		bool isEmpty() const;

		/// <summary>
		/// Sets the object into an empty state.  The object is not valid anymore and should
		///     not be used until it receives valid data.
		/// </summary>
		void setEmpty();

		/// <summary>
		/// Copies the values of the parameters into the attributes.  If at least one of the
		///     parameters is not valid, this function sets the object into an empty state
		///     and records the reason why the object could not accept the values received.
		/// 
		/// This function will validate the parameters before accepting them: the strings
		///     are considered valid if they have at least one character (they are not null
		///     and not empty).
		/// </summary>
		/// <param name="plateNo">an array of characters with the plate number of the car</param>
		/// <param name="model">an array of characters with the make/model of the car</param>
		/// <param name="desc">an array of characters with the description of the problem
		///     the car has</param>
		/// <param name="serviceCost">an estimation of the repair cost of the problem reported
		///     by a customer.</param>
		void set(const char* plateNo, const char* model, const char* desc, double serviceCost);

		/// <summary>
		/// Prints to screen the content of the object.
		/// 
		/// If the object is valid, prints the data in the format:
		/// `| PLATE(8) | MODEL(20) | PROBLEM_DESCRIPTION(40) | COST(8) |`
		/// 
		/// If the object is not valid, prints to screen:
		/// `| REASON_WHY_INVALID(85) |`
		/// 
		/// The numbers in brackets represent the size of the field for printed value.
		/// 
		/// This function has no side-effects: the function will restore any changes to
		///     formatting options to their original values (as they were before the
		///     function is called).
		/// </summary>
		void display() const;

		/// <summary>
		/// Deallocates all the dynamic memory used by the object, and set the object
		///   to an empty state.
		/// </summary>
		void deallocateMemory();		
	};
}
#endif // SENECA_CAR_H
