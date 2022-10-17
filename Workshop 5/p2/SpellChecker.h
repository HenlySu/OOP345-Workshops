#pragma once
#ifndef _SPELL_CHECKER_H_
#define _SPELL_CHECKER_H_

namespace sdds {
   class SpellChecker {
      std::string m_badWords[6]{};
      std::string m_goodWords[6]{};
      size_t cnt = 0;
   public:
      SpellChecker(const char* filename);
      void operator () (std::string& text);
      void showStatistics(std::ostream& os) const;
   };
}
#endif // !_SPELL_CHECKER_H_
