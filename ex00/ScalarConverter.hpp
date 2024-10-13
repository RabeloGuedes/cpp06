#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <limits>

class ScalarConverter {
	public:
		static void convert(const std::string& input);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter	&operator=(const ScalarConverter &obj);
		~ScalarConverter(void);
};

#endif