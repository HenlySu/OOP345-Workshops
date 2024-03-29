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

#include "Dictionary.h"

namespace sdds {
   //Constructor
   Dictionary::Dictionary() { }

   std::ostream& operator << (std::ostream& os, const Dictionary obj) {
      os << std::setw(20) << obj.getTerm() << ": " << obj.getDefinition();
      return os;
   }

   bool operator == (const Dictionary& LO, const Dictionary& RO) {
      return LO.getTerm() == RO.getTerm();
   }
}