SRC =	ft_printf.c \
	utils.c \
	print_num.c \
	libft/ft_strchr.c \
	libft/ft_strlen.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c

OBJS = $(SRC:.c=.o)
NAME =    libftprintf.a
GCC =     gcc
CFLAGS = -Wall -Wextra -Werror
RM = 	  rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
