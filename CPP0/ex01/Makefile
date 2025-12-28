NAME		= phonebook
SRCS		= main.cpp Contact.cpp Phonebook.cpp
OBJS		= $(SRCS:.cpp=.o)
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS:.o=.d)

fclean : clean
	rm -f $(NAME)

re : fclean all

run : all
	./$(NAME)

-include $(OBJS:.o=.d)

.PHONY : all clean fclean re run