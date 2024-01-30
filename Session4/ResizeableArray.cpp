#include <iostream>
#include "ResizeableArray.h"

using namespace std;

namespace lectures
{

	ResizeableArray::ResizeableArray()
	{
		m_arr = nullptr;
		m_cnt = 0;
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
}