# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 22:10:59 by mintan            #+#    #+#              #
#    Updated: 2024/12/22 18:04:02 by mintan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler + compile flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g #-fsanitize=address


# Definitions
NAME = philo
SRCDIR = srcs
RELATIVE_SRCS = main.c initialisation_1.c initialisation_2.c meal.c waiter.c \
cleanup.c check_reservation.c /utils/ft_atoi.c /utils/ft_putchar_fd.c \
/utils/ft_strlen.c /utils/ft_putendl_fd.c /utils/ft_putstr_fd.c \
/utils/mt_utils_1.c /utils/mt_utils_2.c /utils/gettime_utils.c \
/utils/ft_isdigit.c /utils/ft_putnbr_fd.c

SRCS = $(addprefix $(SRCDIR)/, $(RELATIVE_SRCS))
OBJ = $(SRCS:.c=.o)


# Target to make using Make all
all: $(NAME) print_art

# Target to make using Make bonus
bonus: $(NAME_BONUS) print_art

# Generate the mandatory programme by compiling the objects
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Generate all the .o files from the .c files for the programme
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clear the build files
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Rule to rebuild the target
re:	fclean all

# Phony targets
.PHONY: all clean re fclean

print_art:
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⡤⠤⠤⠤⢤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⡟⠏⠛⠁⠉⠁⠀⠀⠀⠀⠀⠀⠉⠉⠓⠢⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⠯⠤⠚⠛⠓⠒⠒⠒⠲⠤⠤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⢦⣀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⣠⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠦⣀⠀⠀⢀⣤⣄⣤⣴⣴⢹⣷⡀⠀⠀⠀"
	@echo " ⠀⠀⠀⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢿⣟⡾⡿⢡⢋⣿⣿⡏⣽⡄⠀⠀"
	@echo " ⠀⠀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢐⡿⡞⢻⣷⣡⢯⢎⡾⡿⣽⣸⣿⠀⠀"
	@echo " ⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⡿⠀⠙⢿⡎⡼⡰⢹⣿⣿⢻⡇⠀"
	@echo " ⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣥⣾⣥⠀⠘⣿⡴⢡⣿⣿⢣⣿⡇⠀"
	@echo " ⣾⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣦⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠿⣿⣿⠀⠀⢸⣡⣿⣿⢃⣾⣿⠃⠀"
	@echo " ⡏⢸⣻⣷⣤⣤⣀⡀⠀⠀⣰⣿⣿⣿⠞⠋⠈⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠀⠀⢸⣿⣿⣿⢏⣾⠏⠀⠀"
	@echo " ⠙⠛⠿⠿⠿⠿⠿⠧⠤⠤⠿⠟⠋⠀⠀⠀⠀⢸⡆⣾⣶⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⣱⣿⢃⡾⠃⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠁⢹⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⡷⠋⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠚⠁⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣿⢏⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⣸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣯⢣⣿⢃⢞⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣧⣿⣿⢃⣿⢏⢎⣼⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⢨⣇⡀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⢃⣾⣿⣞⡾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣶⣄⠀⠀⠀⠀⢀⣼⠿⣿⣿⣿⣿⣾⣿⣷⣶⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⣷⣶⣶⣶⣦⣬⣯⣭⣿⣿⣿⣿⣿⠿⣿⡿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⢰⠿⠿⠯⠽⠿⢭⣿⣺⣿⣿⣟⣿⠟⣿⣾⡼⡝⣰⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⣾⠀⠀⠀⠀⠀⠀⠀⠙⢻⣿⣿⡞⣰⣿⣹⢱⢁⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣷⢣⢣⢋⠇⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢹⣿⠏⡎⡞⣼⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⣿⢰⣧⣀⠀⠀⠀⠀⠀⠀⠀⢸⡟⡸⣽⣿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠻⣾⡟⣿⣿⣶⣦⣠⠀⠀⠀⠘⣷⣷⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠛⠛⠒⠒⠒⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠀⢀⡀⢀⠀⣀⠄⢀⡄⢀⡠⢀⡠⠀⡠⠀⣀⠄⢀⡠⢀⠄⢀⡤⢀⡀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀"
	@echo " ⠀⠀⠀⠀⠐⠿⢟⡵⠊⡡⠚⡡⠔⡩⠔⣉⠔⢋⡤⠊⡡⠖⡩⠞⣡⠖⣡⠖⡩⣺⠟⣩⣾⠗⣫⢶⣿⣾⢶⠆"
	@echo " ⠀⠀⠀⠀⠀⠀⠀⠀⠉⠐⠊⠀⠊⠠⠊⣡⠖⠁⡴⠋⡴⠊⠠⠊⠠⠎⠑⠋⠘⠁⠊⠉⠉⠀⠀⠈⠀⠀⠀⠀"
