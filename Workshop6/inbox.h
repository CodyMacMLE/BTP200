#ifndef SENECA_INBOX_H
#define SENECA_INBOX_H
#include "email.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 14th, 2024

namespace seneca {
	/// An onject that stores a collection of emails
	class Inbox {
		/// <summary>
		/// A pointer to a dynamic array of emails of type Email
		/// </summary>
		Email* m_emails;

		/// <summary>
		/// The number of emails stored
		/// </summary>
		int m_cntEmails;

	public:
		/// <summary>
		/// Default constructor - Empty state { nullptr, 0 }
		/// </summary>
		Inbox();

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="source">Object to be copied</param>
		Inbox(Inbox& source);

		/// <summary>
		/// Copies one inbox object to another
		/// </summary>
		/// <param name="source"></param>
		/// <returns></returns>
		Inbox& operator= (Inbox& source);

		/// <summary>
		/// Destructor
		/// </summary>
		~Inbox();

		/// <summary>
		/// Adds one email to the inbox
		/// </summary>
		/// <param name="email">An unmodifiable reference of type Email</param>
		/// <returns></returns>
		Inbox& operator+= (const Email& email);

		/// <summary>
		/// A query that 
		/// </summary>
		/// <param name="email"></param>
		/// <returns></returns>
		Inbox& operator+ (const Email& email) const;

		/// <summary>
		/// a modifier that loads a collection of emails from a file and adds them to the current object.
		/// </summary>
		/// <param name="filename">the file to load</param>
		void load(const char* filename);

		/// <summary>
		/// a query that saves into the file all the emails stored in the inbox
		/// </summary>
		/// <param name="filename">The filename where the inbox will be stored</param>
		void save(const char* filename) const;

		/// <summary>
		/// Iterates of over the inbox an displays emails
		/// </summary>
		/// <param name="out">output stream</param>
		/// <param name="inbox">the inbox to be iterated</param>
		/// <returns>output stream</returns>
		friend std::ostream& operator<< (std::ostream& out, const Inbox inbox);
	};
}

#endif // !SENECA_INBOX_H

