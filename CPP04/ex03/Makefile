NAME		= materia
SRCS		= main.cpp Character.cpp Cure.cpp Ice.cpp Materia.cpp MateriaSource.cpp
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

re : fclean all

debug :
	$(MAKE) re CXXFLAGS="$(CXXFLAGS) -g3 -O0"

-include $(OBJS:.o=.d)

.PHONY : all clean fclean re debug
