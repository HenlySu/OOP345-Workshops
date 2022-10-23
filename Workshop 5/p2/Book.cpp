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
      char comma = ',';
      char period = '.';

      trim(tempString);
      parseString(tempString, bookAuthor ,comma);
      parseString(tempString, bookTitle, comma);
      parseString(tempString, bookCountry, comma);
      parseDouble(tempString, bookPrice, comma);
      parseInt(tempString, bookYear, comma);
      parseString(tempString, bookDescription, period);
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
      os << std::setw(20) << std::right << obj.bookAuthor << " | ";
      os << std::setw(22) << std::right << obj.bookTitle << " | ";
      os << std::setw(5) << std::right << obj.bookCountry << " | ";
      os << std::setw(4) << obj.bookYear << " | ";

      //the price printed on a field of size 6, with 2 decimal digits;
      os << std::setw(6) << std::right << std::setprecision(2) << std::fixed << obj.bookPrice << " | ";
      os << obj.bookDescription << '\n';

      return os;
   }

   auto Book::trim(std::string& str) -> void {
      std::regex regularExpression("^\\s+|\\s+$"); // remove leading and trailing spaces
      str = std::regex_replace(str, regularExpression, "");
   }

   void Book::parseString(std::string& line, std::string& objLine, char& delimeter) {
      size_t found = line.find(delimeter);
      (delimeter != '.') ? objLine = line.substr(0, found) : objLine = line.substr(0, found + 1); //Keeping period for description
      line.erase(0, found + 1);
      trim(objLine);
   }

   void Book::parseDouble(std::string& line, double& into, char& delimeter) {
      size_t found = line.find(delimeter);
      into = stod(line.substr(0, found));
      line.erase(0, found + 1);
   }

   void Book::parseInt(std::string& line, size_t& into, char& delimeter) {
      size_t found = line.find(delimeter);
      into = stoi(line.substr(0, found));
      line.erase(0, found + 1);
   }
}