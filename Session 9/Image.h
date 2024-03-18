#pragma once

class Image {
	int m_year; // when the img was created
	char* m_author;
public:
	// Constructors
	Image();
	Image(const char* author, int year);

	// Rule-of-3
	Image(const Image& that);
	Image& operator= (const Image& that);
	~Image();
};