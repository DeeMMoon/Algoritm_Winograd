NAME			= winograd

SRCS			= Winograd.cc input.cc utils.cc winograd_algo.cc
OBJS			= $(patsubst %.cc, %.o, $(SRCS))
HEADER			= headers
CC				= clang++
CFLAGS			= -Werror -Wall -Wextra -std=c++17 -I $(HEADER)

all:	$(NAME)

$(NAME): $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re:		fclean all

style: 	
		clang-format -i *.cc 
		clang-format -n *.cc 

.PHONY: all clean fclean re

