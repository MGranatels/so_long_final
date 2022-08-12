NAME		= libftprintf.a

SRCS		=		ft_printf.c ft_printf_resourc.c ft_printf_extra.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra -I.

.c.o:		@$(OBJS)
				@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) 

all:		$(NAME)

$(NAME):	$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS)

fclean: 	clean
				@$(RM) $(NAME)

re: 		fclean all

bonus:		$(OBJS)
			@ar rcs $(NAME) $(OBJS)

.PHONY: 	all clean fclean re bonus .c.o
