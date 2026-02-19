NAME		= templates
SRCS		= main.cpp
BUILD		= build
OBJS		= $(addprefix $(BUILD)/, $(SRCS:.cpp=.o))
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -MMD -MP
LDFLAGS		=
SANITIZE	= -fsanitize=address,undefined -fno-omit-frame-pointer

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

debug :
	@$(MAKE) all \
		CXX="clang++" \
		LDFLAGS="$(SANITIZE)" \
		CXXFLAGS="$(CXXFLAGS) -pedantic -Wconversion -Wshadow -g2 -O0 $(SANITIZE)"

run : all
	./$(NAME)

-include $(OBJS:.o=.d)

.PHONY : all clean fclean re debug run

MAKEFLAGS += --no-print-directory
