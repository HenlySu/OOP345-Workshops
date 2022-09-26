/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef SDDS_DICTIONARY_H
#include <iostream>

namespace sdds {
   class Dictionary {
      std::string m_term{};
      std::string m_definition{};
   public:
      const std::string& getTerm() const { return m_term; }
      const std::string& getDefinition() const { return m_definition; }
      Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{}

      // TODO: Code the missing prototype functions and operators
      //       that the class needs in order to work with the Queue class.
      //       Implement them in the Dictionary.cpp file.
   };
}
#endif // !SDDS_DICTIONARY_H