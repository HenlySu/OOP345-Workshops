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
#include "Book.h"

namespace sdds {
   SpellChecker::SpellChecker(const char* filename) {

      std::ifstream file(filename);

      if (file) {
         for (size_t i = 0; i < 6; i++) {
            getline(file, m_badWords[i], ' ');
            Book::trim(m_badWords[i]);

            getline(file, m_goodWords[i], '\n');
            Book::trim(m_goodWords[i]);
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
      os << "Spellchecker Statistics\n";
      os << "BAD_WORD: " << cnt << " replacements\n";
   }
}