NAME		= form
SRCS		= main.cpp AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
BUILD		= build
OBJS		= $(addprefix $(BUILD)/, $(SRCS:.cpp=.o))
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $@

$(BUILD)/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(BUILD)

fclean : clean
	rm -f $(NAME)
	rm -f *_shrubbery

re : fclean all

debug :
	$(MAKE) re CXXFLAGS="$(CXXFLAGS) -g3 -O0"

run : all
	./$(NAME)

-include $(OBJS:.o=.d)

.PHONY : all clean fclean re debug run
