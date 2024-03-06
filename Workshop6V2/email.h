#ifndef SENECA_EMAIL_H
#define SENECA_EMAIL_H
#include <fstream>

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 6th, 2024

namespace seneca
{
	class Email
	{
		/// <summary>
		/// a statically allocated array of 100 characters representing the name of the person who sent the email.
		/// </summary>
		char m_fromName[100 + 1];

		/// <summary>
		/// a statically allocated array of 100 characters representing the email address of the person who sent the email.
		/// </summary>
		char m_fromAddress[100 + 1];

		/// <summary>
		/// a statically allocated array of 20 characters representing the date and time when the email has been received. 
		/// The date and time field will have the format YYYY-MM-DD HH:MM:SS.
		/// </summary>
		char m_dateReceived[20];

		/// <summary>
		/// a pointer to a dynamically allocated array of characters that represents the subject of the email.
		/// </summary>
		char* m_subject;

		/// <summary>
		/// size of subject array
		/// </summary>
		int m_cntSubject;

	public:
		/// <summary>
		/// Empty state { nullptr for all }
		/// </summary>
		Email();

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="that">Email to be copied</param>
		Email(const Email& that);

		/// <summary>
		/// Assignment operator
		/// </summary>
		/// <param name="that">email to be copied</param>
		/// <returns>new email</returns>
		Email& operator=(const Email& that);

		/// <summary>
		/// Deallocates m_subject
		/// </summary>
		~Email();

		/// <summary>
		/// a modifier that loads data from an input stream and stores it into the current instance. 
		/// The data existing in the stream will contain the information about an email with the fields 
		/// separated by comma, using the format: FROM_ADDRESS,FROM_NAME,SUBJECT,DATE (in this order).
		/// </summary>
		/// <param name="in">a reference to an object of type std::istream</param>
		/// <returns>true if data was successfully loaded; false otherwise</returns>
		bool load(std::istream& in);

		/// <summary>
		/// overload the insertion to insert an Email object into the first parameter.
		/// </summary>
		/// <param name="out">a reference to an output stream</param>
		/// <param name="email">an un-modifiable reference to an object of type Email.</param>
		/// <returns>returns output stream</returns>
		friend std::ostream& operator<<(std::ostream& out, const Email& email);
	};
}
#endif // !SENECA_EMAIL_H