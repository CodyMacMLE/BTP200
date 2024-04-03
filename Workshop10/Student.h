// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// April 03, 2024
#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H
#include<iostream>

namespace seneca
{
	class Book; // forward declaration

	class Student {
		int m_id;
		char m_name[256];
		float m_marks[32];
		int m_numCourses;
		char m_program[4]; // program student enrolled in
	public:
		Student();
		Student(int id, const char* name, const char* program, const float* marks, int num);
		const char* Program() const;
		bool operator==(int) const;
		bool operator==(double) const;
		bool operator==(const Book& bk) const;
		std::ostream& display(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream&, const Student&);
}

#endif
