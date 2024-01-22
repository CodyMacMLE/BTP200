# Workshop #1: Modules

In this workshop, you will use *references* to modify content of variables in other scopes, overload functions and allocate memory at run-time and deallocate that memory when it is no longer required.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate and deallocate dynamic memory for an array;
- overload functions;
- create and use references;



## General Instructions

### Submission Policy

This workshop is divided into two coding parts and one non-coding part.

- **Part 1** (*LAB*): A *step-by-step* guided workshop, worth 50% of the workshop's total mark.
  Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- **Part 2** (*DIY*): A *do-it-yourself* type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- **reflection**: non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of "Part 2" mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
  - Submissions of **Part 2** that do not contain the *reflection* (that is the **non-coding part**) are considered incomplete and are ignored.



### Due Dates

The due dates depend on your section. The due date for *Part #1* is at the end of they when your lab is scheduled; the due date for *Part #2* is at the end of the day that is 5 days after the day with the lab.

Please choose the `-due` option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_SSS -due
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]



### Late penalties

You are allowed to submit your work up to 2 days after the due date with 30% penalty for each day. After that, the submission will be closed, and the mark will be zero. If the reflection is missing when the submission closes, the mark for **Part 2** will be set to 0.



### Citation

Every file that you submit must contain (as a comment) at the top:

- **your name**,
- **your Seneca email**,
- **Seneca Student ID**,
- the **date** when you completed the work.


#### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#### For work that is done partially by you

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from**.  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

- Add the citation to the file in which you have the borrowed code (make sure to clearly mark the code that is not created by you and where did you get it from).
- In the `reflect.txt` file, add a summary of the files/portions of code that is not yours (the source files should un-ambiguously identify the portions of code that are not yours).

> ⚠️ This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.


#### If you have helped someone with your code

If you have helped someone with your code, let them know of these regulations and, in your `reflect.txt` file, write exactly which part of your code was copied and who was the recipient of this code. By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.



### Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace, unless instructed otherwise.





## Part 1 (50%)

***Movies Report*** is a program that reads an unknown number of `Movie` records from a file and stores them in a dynamically-allocated array. Each record holds the title, budget, gross income, and rating of a movie in a comma-separated-values format (`csv` file).

The program is partially developed; you can find all the files in the repository. Your responsibility is to complete the code as stated in the comments in the source code.

Create a project and add to it the provided files. From the main menu in Visual Studio, select **`View` » `Task List`**; this will open a window with a list with all your tasks (the tasks are marked with `TODO` in the source code). You can click on each one of them and Visual Studio will take you to the place where you must insert code or make changes.


### Data File

The data in the file with movie records has the following format:

```txt
BUDGET,GROSS_INCOME,RATING,TITLE<NEWLINE>
```

Two input files with movie records have been provided.  Test your code with those files.

A text input file with tokens has also been provided to test that the `read()` functions work as described.  See the main module about how those files are used.


### The `Movie` module (Partially Provided)

The structure holding a record is designed as follows:

```cpp
/// <summary>
/// A structure that encapsulates some information about a
///   single movie.
/// 
/// The title of the movie is a dynamically-allocated array
///   of characters. It requires that the programmer manages
///   the memory (allocation and deallocation).
/// </summary>
struct Movie
{
  char* m_title;
  int m_budget;
  long m_grossIncome;
  double m_rating;
};
```

The title of the movie is held in a dynamically-allocated C-style string; an object of type `Movie` will store the address of this dynamically-allocated string.

Look in the provided files and read the comments; make sure to understand the responsibilities of each function.  Read the provided code and understand how it accomplishes the goal.  If you need clarifications, contact your professor.



### `DataHandle` Module (Partially Provided)

This module contains functions that facilitate working with files to read data. Look in the provided files and read the comments; make sure to understand the responsibilities of each function.  Read the provided code and understand how it accomplishes the goal.  If you need clarifications, contact your professor.


### `w2p1` Module (Provided)

This is the tester module and is fully provided. Look at it, make sure you understand it, but do not change it.




### Submission

Upload the header files (`*.h`), source code files (`*.cpp`), and the data files (`*.csv`, `*.txt`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.  Using the provided tester module (`w2p1.cpp`), a correct implementation will produce the output as shown in `sample_output.txt`.

Then, run the following command from your `matrix` account:

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace **SSS** with the section: [`naa`, `nbb`, `nra`, `zaa`, etc.]
and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty!





## Part 2 (50%)


In *Part #2* of the workshop you are to create an application that manages the activity at a hotel. The hotel will have an undetermined number of rooms of different types (*standard rooms*, *family rooms*, and *suites*). The data regarding the rooms available at the hotel will be loaded from a file (`hotel.csv` -- a comma-separated-values type of file; the file is provided.)

Your task is to implement the module `hotel`, that reads the data from the file, stores it in an object of type `Hotel`. A sample output of the application has been provided in the file `sample_output.txt` (generated using the client provided in module `w2_p2`).

This program consists of the following modules:
- `w2_p2` (already provided, do not change it)
- `file` (add here any function that works with files). There is no mandatory function from this module that the client requires; add any extra function as you see fit.
- `hotel` (partially provided, add what's missing -- see below).



### The `hotel` Module

Add the following custom types to the header of this module:

```cpp
/// <summary>
/// A structure that contains information about a single person that stays
///   at a hotel
/// </summary>
struct Guest
{
	/// <summary>
	/// The first name of the person.
	///   The name must not exceed 100 characters.
	/// </summary>
	char m_firstName[101]{};
	/// <summary>
	/// The last name of the person.
	///   The name must not exceed 100 characters.
	/// </summary>
	char m_lastName[101]{};
};

/// <summary>
/// A structure that contains information about a single room that
///   guests can rent.
/// </summary>
struct Room
{
	/// <summary>
	/// The room number. The first letter of the room number specifies
	///   in which building the room is located:
	///   - Building 'A': Standard Rooms (for solo travelers or couples)
	///   - Building 'B': Family Rooms (rooms for families with kids)
	///   - Building 'C': Suites (apartment-style with at least 2 bedrooms)
	/// 
	/// This attribute stores the address of a dynamically-allocated array
	///   of characters.
	/// </summary>
	char* m_roomNumber = nullptr;
	/// <summary>
	/// The MAXIMUM number of guests that can stay in the room at a given
	///   moment.  This is the capacity of the room.  Large families/parties
	///   should book large rooms.
	/// </summary>
	int m_maxCntGuests = 0;
	/// <summary>
	/// The number of guests that currently stay in the room.
	/// 
	/// This number cannot exceed `m_maxCntGuests`.
	/// </summary>
	int m_cntGuests = 0;
	/// <summary>
	/// A collection of `Guest` objects of size `m_cntGuests`.
	/// 
	/// This attributes stores the address of a dynamically-allocated
	///   array of objects of type `Guest`.
	/// </summary>
	Guest* m_guests = nullptr;
};

/// <summary>
/// A structure that contains information about a single hotel.
/// </summary>
struct Hotel
{
	/// <summary>
	/// A collection of rooms of some undetermined size.
	/// 
	/// This attribute stores the address of a dynamically-allocated
	///   array of objects of type `Room`.
	/// </summary>
	Room* m_rooms = nullptr;
	/// <summary>
	/// The number of rooms in the collection.
	/// </summary>
	int m_cntRooms = 0;
};
```

Also add the following functions to this module (the protoype in the header, the implementation in the cpp file):

```cpp
/// <summary>
/// Sets the first name and last name of a guest.
/// </summary>
/// <param name="theGuest">the guest whose name must be set.</param>
/// <param name="fName">the first name of the guest</param>
/// <param name="lName">the last name of the guest</param>
void setGuest(Guest& theGuest, const char* fName, const char* lName)
{
	strcpy(theGuest.m_firstName, fName);
	strcpy(theGuest.m_lastName, lName);
}

/// <summary>
/// Load all information about the rooms found in a file and store it in
///   the `Hotel` object.
/// </summary>
/// <param name="fileName">the name of the file containing data.</param>
/// <param name="theHotel">the object that must be populated with data
///   extracted from the file.</param>
/* TODO: add the prototype of the `loadData` function that receives as parameters
*         the address of a C-string with the file name containing the data, and
*         a reference to an object of type `Hotel`.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* loadData()
* - the file contains information about an undetermined number of rooms that a hotel
*     has. Each line from the file contains information about a single room in the
*     format:
* 
*     `ROOM_NUMBER,ROOM_CAPACITY\n`
* 
* - the number of rooms and the number of characters for a single ROOM_NUMBER is not
*     known, and must be determined at runtime; use dynamic memory to store this info
*     in your program. Allocate *exactly* the amount of memory necessary and not more.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
???

/// <summary>
/// Load from a file the information about a single room.
/// </summary>
/// <param name="theRoom">the object where to put data loaded from the file</param>
/* TODO: add the prototype of the `loadData` function that receives as a parameter
*         a reference to an object of type `Room`.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* loadData()
* - load the room number (in a dynamically-allocated string) and the capacity
*     of the room (as an integer) and store them in the attributes of the parameter.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
???

/// <summary>
/// Print to screen the details of the hotel.
/// </summary>
/// <param name="theHotel">the hotel whose details are to be printed.</param>
/* TODO: add the prototype of the `display` function that receives as a parameter
*         an unmodifiable reference to an object of type `Hotel`.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* display()
* - print the data stored in the object in the following format:
*     `Standard Rooms:\n`
*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_A`
*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_A`
*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_A`
*     `...`
*     `Family Rooms:\n`
*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_B`
*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_B`
*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_B`
*     `...`
*     `Suites:\n`
*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_C`
*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_C`
*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_C`
*     `...`
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
void display(const Hotel& theHotel);

/// <summary>
/// Print to screen the details of a single room.
/// </summary>
/// <param name="theRoom">the room whose details are to be printed.</param>
/* TODO: add the prototype of the `display` function that receives as a parameter
*         an unmodifiable reference to an object of type `Room`.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* display()
* - if the room has guests, print the data stored formatted as:
*     `ROOM_NUMBER (NUMBER_OF_GUESTS/MAX_NUMBER_OF_GUESTS): GUEST_1, GUEST_2, ...`
* - if the room has no guests, print the data stored formatted as:
*     `ROOM_NUMBER (NUMBER_OF_GUESTS/MAX_NUMBER_OF_GUESTS)`
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
???

/// <summary>
/// Add a guest to the room ONLY if the room capacity has not been reached.
///   If the room is already at capacity, this function does nothing.
/// </summary>
/// <param name="theRoom">the room where guests will be staying</param>
/// <param name="theGuest">the gust that wants to stay in the room</param>
/* TODO: add the prototype of the `addGuest` function that receives as a parameters
*         a reference to an object of type `Room` and an unmodifiable reference
*         to an object of type `Guest`.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* addGuest()
* - resize the array of guests currently staying in the room, but only if there
*     enough capacity to accommodate the new guest.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
???

/// <summary>
/// Searches in the hotel for a room with the number specified in the
///   second parameter.
/// </summary>
/// <param name="theHotel">the hotel where to search for a room.</param>
/// <param name="roomNumber">the room number being searched.</param>
/// <returns>the address of the `Room` object with the number specified
///   in the second parameter, or null if no such room exists.</returns>
/* TODO: add the prototype of the `findRoom` function that receives as a parameters
*         an unmodifiable reference to an object of type `Hotel` and the
*         address of a C-string.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* findRoom()
* - search in the hotel a room with the specified "Room Number"
*     (iterate over the collection of rooms).
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
???

/// <summary>
/// Deallocates all dynamic memory used by a `Hotel` object.
/// </summary>
/// <param name="theHotel">the object whose memory must be deallocated.</param>
/* TODO: add the prototype of the `deallocate` function that receives as a parameter
*         an unmodifiable reference to an object of type `Room`.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* deallocate()
* - deallocate all the dynamic memory used by the hotel:
*   - the room number and the array of guests (for each room)
*   - the array of rooms
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
???
```

See the provided comments about the responsibility of each function and some hints about how to implement them.  Use the provided sample output to find more about how these functions are supposed to work.

***You may freely use/copy any logic or code needed from the PART 1!***  You can add as many functions, custom types, and variables as your design requires. You must use *function overloading*, *references* and *dynamic memory allocation*.  All the global variables/functions and custom types must be added to `seneca` namespace.




### Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:

- In the code from *Part #1*, you were instructed to overload the function `read` multiple times. The reference parameter received by these overloads is called an **out parameter**. Do some research and explain what is an **out parameter** for a function and compare it with an **in parameter**.  In your code, can you identify any function that receives an **in parameter**? Justify your answer.

To avoid deductions, refer to code in your solution as examples to support your explanations.

You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the source code files to your `matrix` account:

- `w2_p2.cpp`
- `hotel.h`
- `hotel.cpp`
- `file.h`
- `file.cpp`
- `hotel.csv`
- `reflect.txt`

Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly. The professor's tester module has been provided in the repository. A sample run can be found in the file `output_sample.txt`.

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
