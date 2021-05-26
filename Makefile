CC = gcc
CFLAGS = -W -Wall -fPIC
SRC = DigitechDays.c
SRC_LIB =	algo.c
OBJ = $(SRC:.c=.o)
OBJ_LIB = $(SRC_LIB:.c=.o)
NAME = DigitechDay.exe
SHARED_LIB = libalgo.so

$(NAME) : $(SHARED_LIB) $(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lalgo -L./

$(SHARED_LIB) : $(OBJ_LIB)
		$(CC) -o $(SHARED_LIB) $(OBJ_LIB) -shared
		export LD_LIBRARY_PATH=./

all : $(NAME)

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_LIB)
	
fclean : clean
	rm -rf $(NAME)
	rm -rf $(SHARED_LIB)

re : fclean all

run : all
	LD_LIBRARY_PATH=./ ./$(NAME)

.PHONY : all clean fclean