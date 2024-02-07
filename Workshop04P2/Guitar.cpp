#include <cstring>
#include "guitar.h"

using namespace std;

namespace seneca {
	Guitar::Guitar() : m_model{ '\0' }, m_strings{nullptr}, m_cntStrings{0}
	{
	}

	Guitar::Guitar(const char* model)
	{
		*this = Guitar();
		if (model != nullptr || model[0] != '\0')
		{
			strcpy(this->m_model, model);
		}
	}

	Guitar::Guitar(const GuitarString* strings, int cntStrings, const char* model)
	{
		*this = Guitar(model);
		if (strings != nullptr && cntStrings > 0)
		{
			this->m_strings = new GuitarString[cntStrings];
			for (auto i = 0; i < cntStrings; i++)
			{
				appendString(strings[i]);
			}
		}
	}

	Guitar& Guitar::appendString(const GuitarString& aString)
	{
		GuitarString* tmp = new GuitarString[m_cntStrings + 1];
		for (auto i = 0; i < m_cntStrings; i++)
			tmp[i] = m_strings[i];
		tmp[m_cntStrings] = aString;

		delete[] m_strings;

		m_strings = tmp;
		m_cntStrings++;

		return *this;
	}

	bool Guitar::isStrung() const
	{
		// Next function to work on, is next in main.cpp and is used in display();
	}

	std::ostream& Guitar::display(std::ostream& out = std::cout) const
	{
		if (m_model != nullptr)
		{
			out << "Empty guitar object!" << endl;
		}
		else
		{
			if (!(isStrung()))
			{
				out << "Guitar Model: " << m_model << endl;
				out << "Guitar cannot be used yet because it has no strings." << endl;
			}
			else
			{
				out << "Guitar Model: " << m_model << endl;
				out << "Strings:" << endl;
				for (auto i = 0; i < m_cntStrings; i++)
				{
					char tmpMaterial[30 + 1];
					strcpy(tmpMaterial, m_strings[i].getMaterial());
					double tmpGauge = m_strings[i].getGauge();
					out << "#" << i + 1 << ". " << tmpMaterial << " (" << tmpGauge << ")" << endl;
				}
			}
		}
		return out;
	}

}