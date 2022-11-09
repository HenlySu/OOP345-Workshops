#include "Luxuryvan.h"
#include "Utilities.h"

namespace sdds {
	sdds::Luxuryvan::Luxuryvan(std::istream& in) : Van(in) {
		std::string line{};

		in.seekg(std::ios_base::beg);

		std::getline(in, line);
		trim(line);

		size_t found = 0;

		for (int i = 0; i < 6; i++) {
			delData(line, ',');
		}

		trim(line);
		m_consumption = line;

		if (m_consumption != "e") {
			throw std::invalid_argument("Invalid record!");
		}
	}

	void sdds::Luxuryvan::display(std::ostream& out) const {
		Van::display(out);
		out << " electric van  *";
	}

	std::string Luxuryvan::consumption() const {
		std::string type{};

		if (m_consumption[0] == 'e') {
			type = "electronic";
		}
		else if (m_consumption[0] == 'g') {
			type = "gas";
		}

		return type;
	}
}