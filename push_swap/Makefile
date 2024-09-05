# Definiere den Compiler
CC = cc

# Definiere die Compiler-Flags
CFLAGS = -Wall -Wextra -Werror

# Definiere den Namen der ausführbaren Datei
TARGET = push_swap

BONUS = checker

# Liste der Quelldateien
SOURCES = push_swap.o fillarray.o

# Liste der Objektdateien
OBJECTS = push_swap.o fillarray.o operation_functions.o commands.o commands2.o \
        rotate_operations.o rotate_operations2.o utils.o utils2.o

OBJECTSBONUS =  checker.o fillarray.o operation_functions.o checker_utils.o \
        commands.o commands2.o

# Liste der Bibliotheksdateien von libft
LIBFT = libft/ft_tolower.o libft/ft_toupper.o libft/ft_atoi.o \
        libft/ft_bzero.o libft/ft_calloc.o libft/ft_isalnum.o \
        libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o \
        libft/ft_isprint.o libft/ft_itoa.o libft/ft_memchr.o \
        libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memmove.o \
        libft/ft_memset.o libft/ft_putchar_fd.o libft/ft_putendl_fd.o \
        libft/ft_putnbr_fd.o libft/ft_putstr_fd.o libft/ft_strchr.o \
        libft/ft_strdup.o libft/ft_striteri.o libft/ft_strjoin.o \
        libft/ft_strlcat.o libft/ft_strlcpy.o libft/ft_strlen.o \
        libft/ft_strmapi.o libft/ft_strncmp.o libft/ft_strnstr.o \
        libft/ft_strrchr.o libft/ft_split.o libft/ft_strtrim.o \
        libft/ft_substr.o libft/ft_lstadd_back_bonus.o libft/ft_lstadd_front_bonus.o \
        libft/ft_lstclear_bonus.o libft/ft_lstdelone_bonus.o libft/ft_lstiter_bonus.o \
        libft/ft_lstlast_bonus.o libft/ft_lstmap_bonus.o libft/ft_lstnew_bonus.o \
        libft/ft_lstsize_bonus.o

# Regel für die Erzeugung der ausführbaren Datei
$(TARGET): $(OBJECTS) $(LIBFT)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBFT)

$(BONUS): $(OBJECTSBONUS) $(LIBFT)
	$(CC) -o $(BONUS) $(OBJECTSBONUS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C libft
	$(MAKE) -C libft bonus

# Regel für die Erzeugung der Objektdateien
%.o: %.c
	$(CC) -Ilibft -c $< -o $@ $(CFLAGS)

# Regel für das Löschen von erzeugten Dateien
clean:
	rm -f $(TARGET) $(OBJECTS) $(OBJECTSBONUS)
	$(MAKE) -C libft clean
	

# Regel für das Löschen aller erzeugten Dateien
fclean: clean

# Regel für das Löschen aller erzeugten Dateien und der ausführbaren Datei
fclean: clean
	rm -f $(TARGET) $(BONUS)

# Regel für das Löschen aller erzeugten Dateien und Neukompilieren des Projekts
re: fclean all

# Definiere die Standardziele
all: $(TARGET)

bonus: $(BONUS)