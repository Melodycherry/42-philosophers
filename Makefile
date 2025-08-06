# nom de l'executable
NAME = philo

# Source and object diretories
SRCDIR = src
OBJDIR = obj
INCLUDE = -I include

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g3 -fno-omit-frame-pointer -fstack-protector-all


RM = rm -f

vpath %.c \
	$(SRCDIR) \
	

# Sources and object files
SRC = main.c \
	fork.c \
	monitoring.c \
	parsing.c \
	init.c \
	routine.c \
	thread.c \
	utils.c \
	time.c \
	testing.c
	
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

debug: CFLAGS = $(DEBUG_FLAGS)
debug: re

# Sanitize
sanitize: DEBUG_FLAGS += -fsanitize=address 
sanitize: debug 

# Rule to compile with Leaks check
leaks:
ifeq ($(OS), Darwin)
    MallocStackLogging=YES leaks --outputGraph=minishell.memgraph --fullContent --fullStackHistory --atExit -- ./$(NAME)
else ifeq ($(OS), Linux)
	valgrind --leak-check=full --log-file=valgrind.log --show-leak-kinds=all --track-fds=all --default-suppressions=yes --suppressions=ignore_readline.supp ./$(NAME)
endif
	
# Compile each .c file to .o		
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to clean up object files	
clean:
		$(RM) $(OBJS)
		@rm -rf $(OBJDIR)

#Rule to clean up object files and the library
fclean: clean
		$(RM) $(NAME)

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re debug sanitize