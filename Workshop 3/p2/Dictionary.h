/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include <iostream>

namespace sdds {
   class Dictionary {
      std::string m_term{};
      std::string m_definition{};
   public:
      const std::string& getTerm() const { return m_term; }
      const std::string& getDefinition() const { return m_definition; }
      Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{}

      //Constructor
      Dictionary();

      //Rule of three
      Dictionary(const Dictionary& obj);
      Dictionary& operator = (const Dictionary& obj);
      ~Dictionary();

      friend std::ostream& operator << (std::ostream& os, const Dictionary obj);
   };
}
#endif // !SDDS_DICTIONARY_H