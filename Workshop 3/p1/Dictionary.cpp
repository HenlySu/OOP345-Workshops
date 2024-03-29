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

   //Rule of three
   Dictionary::Dictionary(const Dictionary& obj) {
      *this = obj;
   }
   Dictionary& Dictionary::operator = (const Dictionary& obj) {
      if (this != &obj) {
         m_term = obj.m_term;
         m_definition = obj.m_definition;
      }
      return *this;
   }
   Dictionary::~Dictionary() { }

   std::ostream& operator << (std::ostream& os, const Dictionary obj) {
      os << std::setw(20) << obj.getTerm() << ": " << obj.getDefinition();
      return os;
   }
}
