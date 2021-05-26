CC = gcc
CFLAGS = -W -Wall
SRC = DigitechDays.c \
	algo.c
OBJ = $(SRC:.c=.o)
NAME = DigitechDay.exe

$(NAME) : $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean