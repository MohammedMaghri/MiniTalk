NAME = minitalk.a
SERVER = server.c reciverV2.c
CLIENT = client.c convertV.c 
OBJS1 = $(SERVER:.c=.o)
OBJS2 = $(CLIENT:.c=.o)
cl = Client
Sr = Server
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

RED=\033[0;31m
BGRN=\033[1;32m
WHITE=\033[1;97m
NC=\033[0m

all : $(cl) $(Sr)
$(cl) : $(OBJS1)
	@echo "$(BGRN) [ON]" "$(WHITE) ****{ SERVER }****"
	@$(CC) $(CFLAGS) -o $(cl) $(OBJS1)
$(Sr) : $(OBJS2)
	@echo "$(BGRN) [ON]" "$(WHITE) ****{ CLIENT }****"
	@$(CC) $(CFLAGS) -o $(Sr) $(OBJS2)
clean : $(RM)
fclean : clean 

	