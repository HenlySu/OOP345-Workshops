/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#ifndef TENNISLOG_H
#define TENNISLOG_H

namespace sdds {
   class TennisMatch {
      std::string tournamentID;
      std::string tournamentName;
      unsigned int matchID;
      std::string matchWinner;
      std::string matchLoser;
   public:
      friend std::ostream& operator << (std::ostream& os, const TennisMatch tennisMatch);
   };

   class TennisLog {
      TennisMatch* tennisMatches;
   public:
      TennisLog();
      TennisLog(const char* filename);
      void addMatch(TennisMatch& tennisMatch);
      TennisLog& findMatches(const char* playername);
      

   };
}
#endif // !TENNISLOG_H
