#include <iostream>
#include "Book.h"
#include "LibraryItem.h"

// Checking if header guards exist and follows convention.
#ifndef SENECA_LIBRARYITEM_H
	#error "The header guard for 'LibraryItem.h' doesn't follow the convention!"
#endif
#ifndef SENECA_BOOK_H
	#error "The header guard for 'Book.h' doesn't follow the convention!"
#endif

int cout = 0; // prevents compilation if headers don't follow convention

void swap(seneca::Book& A, seneca::Book& B);
void sort(seneca::Book* arr[], int n);
void deallocate(seneca::LibraryItem* item);
void display(seneca::LibraryItem* item, int row);

int main()
{
    const int SIZE = 5;
    seneca::LibraryItem* libraryItems[SIZE] = {
        new seneca::LibraryItem("The Great Gatsby", 1925),
        new seneca::LibraryItem("To Kill a Mockingbird", 1960),
        new seneca::LibraryItem("1984", 1949),
        new seneca::LibraryItem("Brave New World", 1932),
        new seneca::LibraryItem("The Catcher in the Rye", 1951)
    };
    seneca::Book* books[SIZE] = {
        new seneca::Book("The Catcher in the Rye", 1951, "J.D. Salinger"),
        new seneca::Book("The Hobbit", 1937, "J.R.R. Tolkien"),
        new seneca::Book("Pride and Prejudice", 1813, "Jane Austen"),
        new seneca::Book("1984", 1949, "George Orwell"),
        new seneca::Book("The Great Gatsby", 1925, "F. Scott Fitzgerald")
    };

    std::cout << "Library Items:" << std::endl;
    std::cout << "***********************************************" << std::endl;
    for (auto i = 0; i < SIZE; ++i)
        ::display(libraryItems[i], i + 1);

    std::cout << "\nBooks:" << std::endl;
    std::cout << "***********************************************" << std::endl;

    for (auto i = 0; i < SIZE; ++i)
        ::display(books[i], i + 1);

    std::cout << std::endl
              << "Testing Copy Assignment and Copy Constructor" << std::endl;
    std::cout << "***********************************************" << std::endl;
    std::cout << "Books sorted by author:" << std::endl;

    ::sort(books, SIZE);

    for (auto i = 0; i < SIZE; ++i)
        ::display(books[i], i + 1);

    for (auto i = 0; i < SIZE; ++i)
    {
        ::deallocate(libraryItems[i]);
        ::deallocate(books[i]);
    }

    return cout;
}

void deallocate(seneca::LibraryItem* item)
{
    delete item;
}

void display(seneca::LibraryItem* item, int row)
{
    std::cout << row << ">" << std::endl;
    item->display() << std::endl;
    std::cout << "===============================================" << std::endl;
}

void swap(seneca::Book& A, seneca::Book& B)
{
    seneca::Book temp(A);
    A = B;
    B = temp;
}

void sort(seneca::Book* arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*arr[j] > *arr[j + 1])
                swap(*arr[j], *arr[j + 1]);
}
