CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

NAME = indentify

SRCS = Base.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o $(NAME)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all