#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# ifndef uintptr_t
#  define uintptr_t unsigned long
# endif

class	Data;

class	Serializer {
	public:
		static uintptr_t	serialize(Data *ptr);
    	static Data 		*deserialize(uintptr_t raw);
	private:
		Serializer(void);
		Serializer(const Serializer &obj);
		Serializer	&operator=(const Serializer &obj);
		~Serializer(void);
};

#endif