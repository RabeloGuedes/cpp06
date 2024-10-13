#include <ScalarConverter.hpp>
#include <iostream>
#include <climits>
#include <iomanip>

namespace	Utils {
	std::string floatTokens[] = {
		"-inff",
		"+inff",
		"inff",
		"nanf",
	};

	std::string doubleTokens[] = {
		"-inf",
		"+inf",
		"inf",
		"nan",
	};

	bool	isTokenAlnum(std::string token) {
		if (token[0] == '+' || token[0] == '-')
			token = token.substr(1);
		for (size_t i = 0; i < token.length(); i++) {
			if (!std::isdigit(token[i]) && token[i] != '.')
				return (false);
		}
		return (true);
	}

	std::string	getFloatTokens(std::string token) {
		for (size_t i = 0; i < 3; i++) {
			if (token == floatTokens[i])
				return (floatTokens[i]);
		}
		return ("notFound");
	}

	std::string	getDoubleTokens(std::string token) {
		for (size_t i = 0; i < 3; i++) {
			if (token == doubleTokens[i])
				return (doubleTokens[i]);
		}
		return ("notFound");
	}

	bool	isChar(std::string input) {
		return (input.length() == 1 && !std::isdigit(input[0]));
	}

	bool	isInt(std::string input) {
		if (input.length() == 1 && (input[0] == '+' || input[0] == '-'))
			return (false);
		if (input[0] == '+' || input[0] == '-')
			input = input.substr(1);
		for (size_t i = 0; i < input.length(); i++) {
			if (!std::isdigit(input[i]))
				return (false);
		}
		return (true);
	}

	bool	isDouble(std::string input) {
		bool	hasDot = false;

		if (getDoubleTokens(input) != "notFound")
			return (true);
		if (input.length() == 1 && (input[0] == '+' || input[0] == '-'))
			return (false);
		if (input[0] == '+' || input[0] == '-')
			input = input.substr(1);
		if (input[0] == '.')
			return (false);
		for (size_t i = 0; i < input.length(); i++) {
			if (!std::isdigit(input[i]) && input[i] != '.')
				return (false);
			if (hasDot && input[i] == '.')
				return (false);
			if (input[i] == '.')
				hasDot = true;
		}
		return (hasDot && input[input.length() - 1] != '.');
	}

	bool	isFloat(std::string input) {
		if (getFloatTokens(input) != "notFound")
			return (true);
		std::string	doubleToken = input.substr(0, input.length() - 1);
		return (getDoubleTokens(input) == "notFound"
			&& isDouble(doubleToken) && input[input.length() - 1] == 'f');
	}

	bool	isNum(std::string input) {
		return (Utils::isDouble(input) || Utils::isFloat(input) || Utils::isInt(input));
	}

	void	typeNotFound(void) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}

	void	putChar(double d) {
		char c = static_cast<char>(d);
		if (std::numeric_limits<char>::max() < d || std::numeric_limits<char>::min() > d)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else if (std::isprint(c))
			std::cout << "char: " << "'" << c << "'" << std::endl;
	}

	void	putInt(double d) {
		if (std::numeric_limits<int>::max() < d || std::numeric_limits<int>::min() > d)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

	void	putFloat(double d) {
		std::cout << "float: ";
		if (std::numeric_limits<float>::max() < d)
			std::cout << "+";
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	}

	void	putDouble(double d) {
		std::cout << "double: ";
		if (std::numeric_limits<double>::max() < d)
			std::cout << "+";
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}

	void	charConversion(std::string input) {
		char	c = static_cast<char>(input[0]);

		Utils::putChar(c);
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) <<  static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	}

	void	numConversion(std::string input) {
		if (Utils::isFloat(input))
			input = input.substr(0, input.length() - 1);
		double		d = std::strtod(input.c_str(), NULL);

		if (Utils::isTokenAlnum(input)) {
			Utils::putChar(d);
			Utils::putInt(d);
		}
		else {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		Utils::putFloat(d);
		Utils::putDouble(d);
	}
}

void ScalarConverter::convert(const std::string& input) {
	if (Utils::isChar(input))
		Utils::charConversion(input);
	else if (Utils::isNum(input))
		Utils::numConversion(input);
	else
		Utils::typeNotFound();
}