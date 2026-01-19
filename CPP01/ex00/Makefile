NAME		= ex00
SRCS		= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
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

-include $(OBJS:.o=.d)

.PHONY : all clean fclean re
