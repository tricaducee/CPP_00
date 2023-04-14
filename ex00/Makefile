NAME = megaphone
SRC = megaphone.cpp

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

ifeq ($(DEBUG), 1)
	CXXFLAGS += -fsanitize=address -g3
endif

CC = g++
RM = rm -rf

all: $(NAME)

$(NAME):
	@$(CC) $(CXXFLAGS) $(SRC) -o $@
	@echo compilation done

clean:
	@$(RM) $(NAME)
	@echo "It's clean"

fclean: clean

re: fclean all

.PHONY: all clean fclean re