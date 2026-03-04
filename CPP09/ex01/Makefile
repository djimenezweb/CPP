NAME		:= RPN
SRCS		:= main.cpp RPN.cpp
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
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "42 (expected)\n"
	./$(NAME) "7 7 * 7 -"
	@echo "42 (expected)\n"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@echo "0 (expected)\n"
	./$(NAME) "3 4 - 5 +"
	@echo "4 (expected)\n"
	./$(NAME) "3 4 + 2 *"
	@echo "14 (expected)\n"
	./$(NAME) "3 4 - 2 7 + * 4 /"
	@echo "-2.25 (expected)\n"
	./$(NAME) "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
	@echo "42 (expected)\n"
	./$(NAME) "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
	@echo "15 (expected)\n"
	./$(NAME) "3 2 /"
	@echo "1.5 (expected)\n"
	./$(NAME) "3 0 /"
	@echo "Error (expected)\n"
	./$(NAME) "(1 + 1)"
	@echo "Error (expected)\n"
	./$(NAME) "1 + 2"
	@echo "Error (expected)\n"
	./$(NAME) "1 2 + 2"
	@echo "Error (expected)\n"
	./$(NAME) "7 7* 7 -"
	@echo "Error (expected)\n"
	./$(NAME) "2 -1"
	@echo "Error (expected)\n"

-include $(OBJS:.o=.d)

.PHONY : all clean fclean re debug run

MAKEFLAGS += --no-print-directory
