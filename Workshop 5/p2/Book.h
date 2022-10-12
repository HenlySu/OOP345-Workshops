/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include <regex>

namespace sdds {
   class Book {
      std::string bookAuthor{};
      std::string bookTitle{};
      std::string bookCountry{};
      size_t bookYear{};
      double bookPrice{};
      std::string bookDescription{};
   public:
      Book() = default;
      Book(const std::string& strBook);

      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      auto price() -> double&;

      friend auto operator << (std::ostream& os, Book& obj)->std::ostream&;
      auto trim(std::string& str) -> void;
   
      template <typename T>
         void fixSpelling(T& SpellChecker) {

         }
   };
}
#endif // !_BOOK_H_