CC = gcc

FLAGS = -Wall -Wextra -Werror

#======= BONUS ========

#======= CLIENT ========
SND_BONUS = client_bonus
B_SRC_SND = client_bonus.c mini_utils_bonus.c
B_OBJ_SND = $(B_SRC_SND:.c=.o)

#======= SERVER ========
RCV_BONUS = server_bonus
B_SRC_RCV = server_bonus.c mini_utils_bonus.c
B_OBJ_RCV = $(B_SRC_RCV:.c=.o)

#======= CLIENT ========

SENDER = client
SRC_SND = client.c mini_utils.c
OBJ_SND = $(SRC_SND:.c=.o)

#======= SERVER ========

RECEIVER = server
SRC_RCV = server.c mini_utils.c
OBJ_RCV = $(SRC_RCV:.c=.o)

#======= PRINTF ========

PRINTF = my_printf/libftprintf.a

#================o================o================o================o

all: $(SENDER) $(RECEIVER)

%.o: %.c
	$(CC) $(FLAGS) $< -c

$(PRINTF):
	make -C my_printf/

$(SENDER): $(OBJ_SND) $(PRINTF)
	$(CC) $(FLAGS) $(PRINTF) $^ -o $(SENDER)

$(RECEIVER): $(OBJ_RCV) $(PRINTF)
	$(CC) $(FLAGS) $(PRINTF) $^ -o $(RECEIVER)

bonus: $(SND_BONUS) $(RCV_BONUS)

$(SND_BONUS): $(B_OBJ_SND) $(PRINTF)
	$(CC) $(FLAGS) $(PRINTF) $^ -o $(SND_BONUS)

$(RCV_BONUS): $(B_OBJ_RCV) $(PRINTF)
	$(CC) $(FLAGS) $(PRINTF) $^ -o $(RCV_BONUS)

clean:
	make clean -C my_printf/
	rm -f $(OBJ_SND) $(OBJ_RCV) $(B_OBJ_RCV) $(B_OBJ_SND)

fclean: clean
	make fclean -C my_printf/
	rm -f $(SENDER) $(RECEIVER) $(SND_BONUS) $(RCV_BONUS)

re: fclean all

.PHONY: all clean fclean re