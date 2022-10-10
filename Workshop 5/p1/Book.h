#pragma once
#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>

namespace sdds {
   class Book {
      std::string bookAuthor{};
      std::string bookTitle{};
      std::string bookCountry{};
      size_t bookYear{};
      double bookPrice{};
      std::string bookDescription{};
   public:
      Book();
      Book(const std::string& strBook);

      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      
      friend std::ostream& operator << (std::ostream& os, Book& obj);
   };
}
#endif // !_BOOK_H_
