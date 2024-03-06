#ifndef SENECA_INBOX_H
#define SENECA_INBOX_H
#include "email.h"

namespace seneca {
	/// An onject that stores a collection of emails
	class Inbox {
		/// <summary>
		/// A pointer to a dynamica array of emails of type Email
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
	};
}

#endif // !SENECA_INBOX_H

