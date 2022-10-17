/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "SpellChecker.h"

namespace sdds {
   SpellChecker::SpellChecker(const char* filename) {

      std::ifstream file(filename);
      size_t found{};

      if (file) {
         for (size_t i = 0; i < 6; i++) {

            //Bad words
            std::getline(file, m_badWords[i], ' ');
            found = m_badWords[i].find_first_not_of(' ');
            m_badWords[i].erase(0, found);
            m_badWords[i].erase(found + 1);

            //Good words
            std::getline(file, m_goodWords[i], '\n');
            found = m_goodWords[i].find_first_not_of(' ');
            m_goodWords[i].erase(0, found);
            m_goodWords[i].erase(found);
         }
      }
      else {
         throw "Bad file name!";
      }
      
      file.close();
   }

   void SpellChecker::operator () (std::string& text) {
      for (size_t i = 0; i < 6; i++) {
         while (text.find(m_badWords[i]) != std::string::npos) {
            text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
            cnt++;
         }
      }
   }

   void SpellChecker::showStatistics(std::ostream& os) const {
      os << "BAD_WORD: " << cnt << " replacements\n";
   }
}