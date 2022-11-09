#pragma once
#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include"Van.h"

namespace sdds {
	class Luxuryvan :public Van {
		std::string m_consumption{};
	public:
		Luxuryvan() = default;
		Luxuryvan(std::istream& in);

		void display(std::ostream& out)const;
		std::string consumption()const;
	};
}

#endif // !SDDS_LUXURYVAN_H