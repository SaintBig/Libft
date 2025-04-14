# Variables
NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

# Source files
SRCS        = ft_itoa.c ft_libc01.c ft_libc02.c ft_libc03.c ft_libc04.c \
              ft_libc05.c ft_put.c ft_split.c ft_striteri.c ft_strjoin.c \
              ft_strmapi.c ft_strtrim.c ft_substr.c
BONUS_SRCS  = ft_bonus01.c ft_bonus02.c
MAIN_SRC    = main.c

# Object files
OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)
MAIN_OBJ    = $(MAIN_SRC:.c=.o)

# Header file
HEADER      = libft.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS) $(OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re