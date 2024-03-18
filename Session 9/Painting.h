#pragma once
#include "Image.h"

class Painting : public Image {
	double m_price;
	char* m_title;
public:
	Painting();
	Painting(const char* author, double price);

	//Rule of 3
	~Painting();
	Painting(const Painting& that);
	Painting& operator=(const Painting& that);
};