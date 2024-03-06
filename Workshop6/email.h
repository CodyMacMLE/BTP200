#ifndef SENECA_EMAIL_H
#define SENECA_EMAIL_H

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 14th, 2024

namespace seneca {
	// Object to store a single email
	class Email {
		/// <summary>
		/// a statically allocated array of 100 characters representing the name of the person who sent the email.
		/// </summary>
		char m_fromName[100 + 1];

		/// <summary>
		/// a statically allocated array of 100 characters representing the email address of the person who sent the email.
		/// </summary>
		char m_fromAddress[100 + 1];

		/// <summary>
		/// a statically allocated array of 20 characters representing the date and time when the email has been received. The date and time field will have the format YYYY-MM-DD HH:MM:SS
		/// </summary>
		char m_dateReceived[20 + 1];

		/// <summary>
		/// a pointer to a dynamically allocated array of characters that represents the subject of the email.
		/// </summary>
		char* m_subject;

		/// <summary>
		/// Size of dynamic array m_subject
		/// </summary>
		int m_subjectSize;

	public:
		/// <summary>
		/// Default contrustor (Sets object to an empty state - { \0, \0, \0, null } )
		/// </summary>
		Email();

		/// <summary>
		/// Copy Constructor
		/// </summary>
		/// <param name="source">Object of type Email to be copied</param>
		Email(Email& source);

		/// <summary>
		/// Copies one object into the other
		/// </summary>
		/// <param name="source">Object of type Email to be copied</param>
		/// <returns>An object of Email</returns>
		Email& operator =(const Email& source);
		
		/// <summary>
		/// Destructor
		/// </summary>
		~Email();

		/// <summary>
		/// a modifier that loads data from an input stream and stores it into the current instance.
		/// </summary>
		/// <param name="in"></param>
		/// <returns>Sucessfully loaded data state</returns>
		bool load(std::istream& in);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="out"></param>
		/// <param name="email"></param>
		/// <returns></returns>
		friend std::ostream& operator <<(std::ostream& out, const Email email);
	};

}

#endif // !SENECA_EMAIL_H

