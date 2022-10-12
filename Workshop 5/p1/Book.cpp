
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
#include <string>

#include "Book.h"

namespace sdds {

   Book::Book(const std::string& strBook) {
      std::string tempString = strBook;


      size_t startingPosition = 0;
      char comma = ',';
      char period = '.'; //For end of the sentence

      //AUTHOR,   TITLE,   COUNTRY, PRICE,   YEAR, DESCRIPTION

      trim(tempString);
      

      //For book author
      size_t found = tempString.find(comma);
      bookAuthor = tempString.substr(startingPosition, found);
      tempString.erase(startingPosition, found + 1);

      trim(bookAuthor);
      

      //For book title
      found = tempString.find(comma);
      bookTitle = tempString.substr(startingPosition, found);
      tempString.erase(startingPosition, found + 1);

      trim(bookTitle);
      

      //For book countr
      found = tempString.find(comma);
      bookCountry = tempString.substr(startingPosition, found);
      tempString.erase(startingPosition, found + 1);

      trim(bookCountry);
      

      //For book price
      found = tempString.find(comma);
      bookPrice = stod(tempString.substr(startingPosition, found));
      tempString.erase(startingPosition, found + 1);
      

      //For book year
      found = tempString.find(comma);
      bookYear = std::stoi(tempString.substr(startingPosition, found));
      tempString.erase(startingPosition, found + 1);

      //For book description
      found = tempString.find(period);
      bookDescription = tempString.substr(startingPosition, found + 1);
      tempString.erase(startingPosition, found + 1);

      trim(bookDescription);
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
      os << std::setw(20) << std::right <<obj.bookAuthor << " | ";
      os << std::setw(22) << std::right << obj.bookTitle << " | ";
      os << std::setw(5) << std::right << obj.bookCountry << " | ";
      os << std::setw(4) << obj.bookYear << " | ";

      //the price printed on a field of size 6, with 2 decimal digits;
      os << std::setw(6) << std::right << std::setprecision(2) << std::fixed << obj.bookPrice << " | ";
      os << obj.bookDescription << '\n';

      return os;
   }

   auto Book::trim(std::string& str) -> void{
      std::regex regularExpression("^\\s+|\\s+$"); // remove leading and trailing spaces
      str = std::regex_replace(str, regularExpression, "");
   }
}