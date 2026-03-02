NAME		:= PmergeMe
SRCS		:= main.cpp PmergeMe.cpp
BUILD		:= build
OBJS		:= $(addprefix $(BUILD)/, $(SRCS:.cpp=.o))
CXX			:= c++
CXXFLAGS	:= -std=c++98 -Wall -Wextra -Werror -MMD -MP
LDFLAGS		:=
SANITIZE	:= -fsanitize=address,undefined -fno-omit-frame-pointer

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD)/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(BUILD)

fclean : clean
	rm -f $(NAME)

re : fclean all

debug: CXX		:=	clang++
debug: CXXFLAGS	+=	-pedantic -Wshadow -g2 -O0 $(SANITIZE)
debug: LDFLAGS	+= $(SANITIZE)
debug: all

run : all
	./$(NAME) 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

-include $(OBJS:.o=.d)

.PHONY : all clean fclean re debug run

MAKEFLAGS += --no-print-directory
