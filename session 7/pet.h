#ifndef LECTURES_PET_H
#define LECTURES_PET_H

namespace lectures {
	class Pet
	{
	private: // only the class Pet has access {variables should always be private}
		char m_name[50 + 1];
		int m_location{}; // only one means linear - {} after sets every byte in location to 0
		short m_speed = 0; // measured in cm/s

	protected: // only class Pet and any derived class from Pet have access
		void setName(const char* name); // allows the use of function in Cat, but not globally

	public: // everybody has access
		Pet();
		Pet(const char* name);
		Pet(const char* name, int location, int speed);
		~Pet();
		void setSpeed(int speed);
		void display() const;
		void move(int distance);

		// friend std::ostream& operator<<(std::ostream&, const Pet&); // helpers do no get inheritated
	};
}

#endif // !LECTURES_PET_H