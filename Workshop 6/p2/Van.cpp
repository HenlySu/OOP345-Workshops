#include <iomanip>
#include "Van.h"
#include "Car.h"

namespace sdds {

	Van::Van(std::istream& is) {

		std::string line{};
		std::string speed{};

		std::getline(is, line);

		delData(line, ',');						//Tag
		getData(line, m_maker, ',');			//Maker
		getData(line, m_type, ',');			//Type
		getData(line, m_purpose, ',');		//Purpose
		getData(line, m_condition, ',');		//Condition
		getData(line, speed, ',');				//Safe speed

		isNum(speed, m_topSpeed);				//Speed

		//Checking for type
		if (m_type != "p" && m_type != "m" && m_type != "c") {
			throw std::invalid_argument("Invalid record!");
		}

		//Checking for purpose
		if (m_purpose != "d" && m_purpose != "p" && m_purpose != "c") {
			throw std::invalid_argument("Invalid record!");
		}

		//Setting and checking for condition
		if (m_condition == "")
			m_condition = "n";

		if (m_condition != "n" && m_condition != "u" && m_condition != "b") {
			throw std::invalid_argument("Invalid record!");
		}
	}

	std::string Van::condition()const {
		std::string condition{};

		if (m_condition == "n")
			condition = "new";
		else if (m_condition == "u")
			condition = "used";
		else if (m_condition == "b")
			condition = "broken";

		return condition;
	}

	std::string Van::type() const {
		std::string type{};

		if (m_type == "p")
			type = "pickup";
		else if (m_type == "m")
			type = "mini-bus";
		else if (m_type == "c")
			type = "camper";
		
		return type;
	}

	std::string Van::usage()const	{
		std::string purpose{};

		if (m_purpose == "d")
			purpose = "delivery";
		else if (m_purpose == "p")
			purpose = "passenger";
		else if (m_purpose == "c")
			purpose = "camping";
		
		return purpose;
	}

	double Van::topSpeed()const { 
		return m_topSpeed; 
	}

	void Van::display(std::ostream& os)const {
		os << "| " << std::setw(8) << m_maker;
		os << " | " << std::setw(12) << std::left << type();
		os << " | " << std::setw(12) << std::left << usage();
		os << " | " << std::setw(6) << std::left << condition();
		os << " | " << std::setw(6) << std::right << std::setprecision(2) << topSpeed();
		os << " |";
	}

}