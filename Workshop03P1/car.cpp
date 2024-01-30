#include <iostream>
#include <string>
#include "car.h"

namespace seneca {
	/*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* isEmpty()
	* - return `true` if the attribute `m_makeModel` is null; `false` otherwise.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool Car::isEmpty() const
	{
		bool exitFlag = false;
		if (m_makeModel == nullptr)
		{
			exitFlag = true;
		}
		return exitFlag;
	}

	/*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* setEmpty()
	* - set the plate number (`m_licencePlate`) to empty string
	* - set the model/make of the car (`m_makeModel`) and the description of the
	*       problem (`m_problemDesc`) to null
	* - set the repair cost (`m_cost`) to zero
	* - set object status (`m_objectStatus`) to `INVALID_REASON__EMPTY`
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void Car::setEmpty()
	{
		m_licencePlate[0] = '\0';
		m_makeModel = nullptr;
		m_problemDesc = nullptr;
		m_cost = 0;
		m_objectStatus = INVALID_REASON__EMPTY;
	}

	/* 
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* set()
	* - call `Car::deallocateMemory()` to release any dynamic memory in use by this object.
	* - validate the parameters (the order is important to set appropriate status message):
	*       - if the plate number parameter is null or contains the address of an empty
	*             string, set `m_objectStatus` to `INVALID_REASON__PLATE`
	*       - else if the model/make parameter is null or contains the address of an empty
	*             string, set `m_objectStatus` to `INVALID_REASON__MODEL`
	*       - else if the problem description parameter is null or contains the address
	*             of an empty string, set `m_objectStatus` to `INVALID_REASON__DESC`
	*       - if all parameters are good, then:
	*             - copy with `std::strncpy()` the plate number into `m_licencePlate`.
	*                   See that `m_licencePlate` can accept at most 8+1 characters
	*                   so we must ensure that we do not copy more than that and the null
	*                   is set appropriately at the end.
	*             - allocate dynamic memory for C-string able to store the make/model
	*                   received as parameter; copy with `std::strcpy()` the parameter into
	*                   this dynamic array; store the address of this array in `m_makeModel`
	*             - allocate dynamic memory for C-string able to store the problem description
	*                   received as parameter; copy with `std::strcpy()` the parameter into
	*                   this dynamic array; store the address of this array in `m_problemDesc`
	*             - copy the cost parameter into `m_cost`
	*             - set `m_objectStatus` to `VALID_OBJECT`
	*
	* Documentation to read:
	* - `std::strcpy`    - https://en.cppreference.com/w/c/string/byte/strcpy
	* - `std::strncpy`   - https://en.cppreference.com/w/c/string/byte/strncpy
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void Car::set(const char* plateNo, const char* model, const char* desc, int serviceCost)
	{
		deallocateMemory();
		if (plateNo == nullptr || plateNo[0] == '\0')
			m_objectStatus = INVALID_REASON__PLATE;
		else if (model == nullptr || model[0] == '\0')
			m_objectStatus = INVALID_REASON__MODEL;
		else if (desc == nullptr || desc[0] == '\0')
			m_objectStatus = INVALID_REASON__DESC;
		else
		{
			strncpy(m_licencePlate, plateNo, sizeof(char) * 9);

			m_makeModel = new char[strlen(model) + 1];
			strcpy(m_makeModel, model);

			m_problemDesc = new char[strlen(desc) + 1];
			strcpy(m_problemDesc, desc);

			m_cost = serviceCost;

			m_objectStatus = VALID_OBJECT;
		}
	}

	/* 
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* display()
	* - store in a local variable the current filling character and the precision
	* - if the object is valid, then
	*       - print the `m_licencePlate`, `m_makeModel`, `m_problemDesc`, and `m_cost`.
	*
	*         See the sample output for hints on alignment, filling character,
	*             and precision. The field width for each attribute is specified in
	*             the description above.
	*
	*         When you change a formatting option with `ostream::setf(...)`, you must
	*             remove it with `ostream::unsetf(...)` when you are done.
	* - if the object is not valid, then
	*       - print the `m_objectStatus`.
	* - restore the filling character and precision to the original values.
	*
	* Documentation to read (also in the course notes):
	* - `std::ostream::fill()`       - https://en.cppreference.com/w/cpp/io/basic_ios/fill
	* - `std::ostream::width()`      - https://en.cppreference.com/w/cpp/io/ios_base/width
	* - `std::ostream::precision()`  - https://en.cppreference.com/w/cpp/io/ios_base/precision
	* - `std::ostream::setf()`       - https://en.cppreference.com/w/cpp/io/ios_base/setf
	* - `std::ostream::unsetf()`     - https://en.cppreference.com/w/cpp/io/ios_base/unsetf
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void Car::display() const
	{

	}

	/* 
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* deallocateMemory()
	* - deallocate the memory used by make/model array (`m_makeModel`) and the problem
	*       description array (`m_problemDesc`)
	* - call the `Car::setEmpty()` function to set the object in an empty state.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void Car::deallocateMemory()
	{
		delete[] m_makeModel;
		delete[] m_problemDesc;
		setEmpty();
	}

}
