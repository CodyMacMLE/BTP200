#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "guitar.h"

using namespace std;

namespace seneca {

	Guitar::Guitar(const char* model)
	{
		if (model == nullptr)
			m_model[0] = '\0';
		else
		strcpy(m_model, model);
		m_strings = nullptr;
		m_cntStrings = 0;
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

	Guitar::~Guitar()
	{
		if (m_strings != nullptr)
			delete[] this->m_strings;
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
		bool exitFlag = false;
		if (this->m_cntStrings > 0)
			exitFlag = true;
		return exitFlag;
	}

	Guitar& Guitar::reString(const GuitarString* strings, int cntStrings)
	{
		delete[] this->m_strings;
		m_cntStrings = 0;
		for (auto i = 0; i < cntStrings; i++)
		{
			if (strings[i].getGauge() != 0.0)
			{
				m_cntStrings++;
			}
		}

		this->m_strings = new GuitarString[m_cntStrings];
		for (auto i = 0; i < m_cntStrings; i++)
			m_strings[i] = strings[i];
		return *this;
	}

	Guitar& Guitar::reString(const GuitarString& aString, int idx)
	{
		if (idx >= 0 && idx < m_cntStrings)
		{
			m_strings[idx] = aString;
		}
		return *this;
	}

	Guitar& Guitar::deString()
	{
		if (m_strings != nullptr)
			delete[] m_strings;
		m_cntStrings = 0;

		return *this;
	}

	ostream& Guitar::display(std::ostream& out) const
	{
		if ((m_model == nullptr || m_model[0] == '\0') || m_strings == nullptr)
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
					out << " #" << i + 1 << ". " << tmpMaterial << " (" << tmpGauge << "mm)" << endl;
				}
			}
		}
		return out;
	}
}