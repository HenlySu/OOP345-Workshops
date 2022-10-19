#pragma once
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include "Book.h"
#include "SpellChecker.h"

namespace sdds {
   class Movie {
      std::string movieTitle{};
      std::string movieDescription{};
      int movieYear{};
   public:
      Movie() = default;
      Movie(const std::string& strMovie);

      const std::string& title() const;
   
      template <typename T>
      void fixSpelling(T& spellChecker) {
         spellChecker(movieTitle);
         spellChecker(movieDescription);
      }

      friend std::ostream& operator << (std::ostream& os, const Movie& movie);
   };
}
#endif // !_MOVIE_H_
