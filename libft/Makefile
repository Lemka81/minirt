NAME	= libft.a
SRC		= ft_bzero.c\
		  ft_memset.c\
		  ft_memcpy.c\
		  ft_memmove.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_strlen.c\
		  ft_isalpha.c\
		  ft_isdigit.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_toupper.c\
		  ft_tolower.c\
		  ft_strrchr.c\
		  ft_strchr.c\
		  ft_strncmp.c\
		  ft_strlcpy.c\
		  ft_strlcat.c\
		  ft_strnstr.c\
		  ft_atoi.c\
		  ft_calloc.c\
		  ft_strdup.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_substr.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_itoa.c\
		  ft_strmapi.c\
		  ft_striteri.c\
		  ft_split.c\
		  ft_printf.c\
		  print.c\
		  get_next_line.c\
		  get_next_line_utils.c

OBJ		= $(SRC:.c=.o)
DEP		= $(SRC:.c=.d)
CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)

-include $(DEP)

%.o:	%.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

clean:
	rm -rf $(OBJ) $(DEP)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all