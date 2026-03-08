NAME		:= PmergeMe
SRCS		:= main.cpp PmergeMe.cpp sort-vector.cpp sort-list.cpp jacobsthal.cpp utils.cpp
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
	./$(NAME) 2 0 6 8 3 1 9 5 4 7
#	./$(NAME) 11 89 2 17 0 16 8 52 6 15 33 10 24 3 21 98 1 18 9 14 19 12 5 4 71 20 13 7 51 22 23

test : all
	./$(NAME) || true
	@echo
	./$(NAME) 1 -5 42 0 53 88 || true
	@echo
	./$(NAME) 1 5 42 0 4294967296 53 88 || true
	@echo
	./$(NAME) "7 -25 82" "0 53 88" || true

-include $(OBJS:.o=.d)

.PHONY : all clean fclean re debug run test

MAKEFLAGS += --no-print-directory
