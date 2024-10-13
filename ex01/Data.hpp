#ifndef DATA_HPP
# define DATA_HPP

class Data {
	public:
		Data(void);
		Data(const Data &obj);
		Data(int value);
		Data	&operator=(const Data &obj);
		~Data(void);

		int getValue();

	private:
		int value;
};

#endif