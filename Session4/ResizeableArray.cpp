#include <iostream>
#include "ResizeableArray.h"

using namespace std;

namespace lectures
{

	ResizeableArray::ResizeableArray() : m_arr{ nullptr }, m_cnt{ 0 } // n members Accomplishes the same, try to keep in order due to cpu time
	{ // Keep brackets
		cout << "[" << this << "] Default constructor was called\n";
	//	m_arr = nullptr;
	//	m_cnt = 0;
	}

	ResizeableArray::ResizeableArray(int cnt)
	{
		cout << "[" << this << "] Custom constructor was called\n";
		if (cnt > 0)
		{
			m_arr = new double[cnt];
			for (int i = 0; i < cnt; i++)
				m_arr[i] = 0;
			m_cnt = cnt;
		}
		else // need the else if its less than 0, in a constructor no matter what all variables must be initialized to some value
		{
			*this = ResizeableArray();
		}
	}

	void ResizeableArray::display() const
	{
		for (auto i = 0; i < m_cnt; i++)
		{
			cout << "[" << m_arr[i] << "]";
		}
		cout << endl;
	}

	void ResizeableArray::addItem(double item)
	{
		double* tmp = new double[m_cnt + 1];
		cout << "Allocated address at: [" << tmp << "]" << endl;

		for (auto i = 0; i < m_cnt; i++) // Apparently no scope brackets are needed
			tmp[i] = m_arr[i]; // for/if/while can read one and only one line after, if more lines are used it needs scope

		tmp[m_cnt] = item;
		
		cout << "Delete address at:    [" << m_arr << "]" << endl;
		delete[] m_arr;
		m_arr = tmp; // since this is a reference we do not need to deallocate tmp

		m_cnt++;
	}

	ResizeableArray::~ResizeableArray()
	{
		cout << "Delete address at:    [" << m_arr << "]" << endl;
		delete[] m_arr;
	}

	ResizeableArray& ResizeableArray::operator+=(double value)
	{
		addItem(value);
		return *this;
	}

	ResizeableArray& ResizeableArray::operator+=(const ResizeableArray& other)
	{
		for (int i = 0; i < other.m_cnt; i++)
			this->addItem(other.m_arr[i]);
		return *this;
	}

	ResizeableArray& ResizeableArray::operator++()
	{
		for (int i = 0; i < m_cnt; ++i)
			m_arr[i] += 1;
		return *this;
	}

	ResizeableArray::operator bool() const
	{
		return m_cnt > 0;
	}

	std::ostream& operator <<(std::ostream& out, const ResizeableArray& arr)
	{
		arr.display();
		return cout;
	}
}