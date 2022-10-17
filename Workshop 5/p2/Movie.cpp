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

#include "Movie.h"

namespace sdds {
   Movie::Movie(const std::string& strMovie) {
      std::string tempString = strMovie;
      size_t startingPosition = 0;

      char comma = ',';
      char period = '.';
      size_t found = 0;

      //Movie Title
      found = tempString.find(comma);
      movieTitle = tempString.substr(startingPosition, found);
      tempString.erase(startingPosition, found + 1);
      Book::trim(movieTitle);

      //Movie Year
      found = tempString.find(comma);
      movieYear = std::stoi(tempString.substr(startingPosition, found));
      tempString.erase(startingPosition, found + 1);

      //Movie Description
      found = tempString.find(period);
      movieDescription = tempString.substr(startingPosition, found + 1);
      tempString.erase(startingPosition, found + 1);
      Book::trim(movieDescription);
   }

   const std::string& Movie::title() const {
      return movieTitle;
   }

   std::ostream& operator << (std::ostream& os, Movie& movie) {
      os << std::setw(40) << movie.movieTitle << " | "; 
      os << std::setw(4) << movie.movieYear << " | ";
      os << movie.movieDescription;
   }
}