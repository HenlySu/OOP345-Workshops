
/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

#include "Book.h"

namespace sdds {
   Book::Book() {
      bookAuthor = {};
      bookTitle = {};
      bookCountry = {};
      bookYear = 0;
      bookPrice = 0.0;
      bookDescription = {};
   }

   Book::Book(const std::string& strBook) {
      //Implement tomorrow
      //Same as previous ws
   }

   const std::string& Book::title() const {
      return bookTitle;
   }

   const std::string& Book::country() const {
      return bookCountry;
   }

   const size_t& Book::year() const {
      return bookYear;
   }

   double& Book::price() {
      return bookPrice;
   }

   std::ostream& operator << (std::ostream& os, Book& obj) {
      os << std::setw(20) << obj.bookAuthor;
      os << std::setw(22) << obj.bookTitle;
      os << std::setw(5) << obj.bookCountry;
      os << std::setw(4) << obj.bookYear;

      //the price printed on a field of size 6, with 2 decimal digits;
      os << std::setw(6) << obj.bookPrice;
   }
}

//Also have to implement the main