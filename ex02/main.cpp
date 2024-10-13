#include <Base.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

namespace Identifier {
	
	typedef Base *(*generate_t)(void);

	Base	*generateA(void) {
		return (new A());
	}

	Base	*generateB(void) {
		return (new B());
	}

	Base	*generateC(void) {
		return (new C());
	}

	generate_t	deriveds[4] = {
		generateA,
		generateB,
		generateC,
		NULL,
	};

	Base	*generate(void) {
		srand(time(NULL));

		generate_t gen = Identifier::deriveds[rand() % 4];

		return (gen ? gen(): NULL);
	}

	void identify(Base *p) {
		if (dynamic_cast<A*>(p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "C" << std::endl;
	}

	void identify(Base &p) {
		try {
			(void)dynamic_cast<A&>(p);
			std::cout << "A" << std::endl;
		} catch (...) {
			try {
				(void)dynamic_cast<B&>(p);
				std::cout << "B" << std::endl;
			} catch (...) {
				try {
					(void)dynamic_cast<C&>(p);
					std::cout << "C" << std::endl;
				} catch (...) {
					std::cerr << "Error: unknown type." << std::endl;
				}
			}
		}
	}
}

int main() {

    Base* p = Identifier::generate();
    Identifier::identify(p);
    Identifier::identify(*p);
    Identifier::identify(NULL);

    delete p;
    return (0);
}