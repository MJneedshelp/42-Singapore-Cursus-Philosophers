# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 22:10:59 by mintan            #+#    #+#              #
#    Updated: 2024/12/07 12:24:55 by mintan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler + compile flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread


# Definitions
NAME = philo
SRCDIR = srcs
SRCS = $(SRCDIR)/main.c $(SRCDIR)/init_philo.c $(SRCDIR)/utils/ft_atoi.c
OBJ = $(SRCS:.c=.o)


# Target to make using Make all
all: $(NAME) print_art

# Target to make using Make bonus
bonus: $(NAME_BONUS) print_art

# Generate the mandatory programme by compiling the objects with libft.a
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
	@echo "                                                                                                         ''''''  "
	@echo "	SSSSSSSSSSSSSSS                                          kkkkkkkk             iiii                    '::::'    "
	@echo "	SS:::::::::::::::S                                         k::::::k            i::::i                   '::::'  "
	@echo "	S:::::SSSSSS::::::S                                         k::::::k             iiii                    ':::'' "
	@echo "	S:::::S     SSSSSSS                                         k::::::k                                    ':::'   "
	@echo "	S:::::S               mmmmmmm    mmmmmmm      ooooooooooo    k:::::k    kkkkkkkiiiiiiinnnn  nnnnnnnn    ''''    "
	@echo "	S:::::S             mm:::::::m  m:::::::mm  oo:::::::::::oo  k:::::k   k:::::k i:::::in:::nn::::::::nn          "
	@echo "	S::::SSSS         m::::::::::mm::::::::::mo:::::::::::::::o k:::::k  k:::::k   i::::in::::::::::::::nn          "
	@echo "	SS::::::SSSSS    m::::::::::::::::::::::mo:::::ooooo:::::o k:::::k k:::::k    i::::inn:::::::::::::::n          "
	@echo "		SSS::::::::SS  m:::::mmm::::::mmm:::::mo::::o     o::::o k::::::k:::::k     i::::i  n:::::nnnn:::::n        "
	@echo "		SSSSSS::::S m::::m   m::::m   m::::mo::::o     o::::o k:::::::::::k      i::::i  n::::n    n::::n           "
	@echo "				S:::::Sm::::m   m::::m   m::::mo::::o     o::::o k:::::::::::k      i::::i  n::::n    n::::n        "
	@echo "				S:::::Sm::::m   m::::m   m::::mo::::o     o::::o k::::::k:::::k     i::::i  n::::n    n::::n        "
	@echo "	SSSSSSS     S:::::Sm::::m   m::::m   m::::mo:::::ooooo:::::ok::::::k k:::::k   i::::::i n::::n    n::::n        "
	@echo "	S::::::SSSSSS:::::Sm::::m   m::::m   m::::mo:::::::::::::::ok::::::k  k:::::k  i::::::i n::::n    n::::n        "
	@echo "	S:::::::::::::::SS m::::m   m::::m   m::::m oo:::::::::::oo k::::::k   k:::::k i::::::i n::::n    n::::n        "
	@echo "	SSSSSSSSSSSSSSS   mmmmmm   mmmmmm   mmmmmm   ooooooooooo   kkkkkkkk    kkkkkkkiiiiiiii nnnnnn    nnnnnn         "

# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⡤⠤⠤⠤⢤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⡟⠏⠛⠁⠉⠁⠀⠀⠀⠀⠀⠀⠉⠉⠓⠢⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⠯⠤⠚⠛⠓⠒⠒⠒⠲⠤⠤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⢦⣀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⣠⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠦⣀⠀⠀⢀⣤⣄⣤⣴⣴⢹⣷⡀⠀⠀⠀
# ⠀⠀⠀⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢿⣟⡾⡿⢡⢋⣿⣿⡏⣽⡄⠀⠀
# ⠀⠀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢐⡿⡞⢻⣷⣡⢯⢎⡾⡿⣽⣸⣿⠀⠀
# ⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⡿⠀⠙⢿⡎⡼⡰⢹⣿⣿⢻⡇⠀
# ⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣥⣾⣥⠀⠘⣿⡴⢡⣿⣿⢣⣿⡇⠀
# ⣾⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣦⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠿⣿⣿⠀⠀⢸⣡⣿⣿⢃⣾⣿⠃⠀
# ⡏⢸⣻⣷⣤⣤⣀⡀⠀⠀⣰⣿⣿⣿⠞⠋⠈⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠀⠀⢸⣿⣿⣿⢏⣾⠏⠀⠀
# ⠙⠛⠿⠿⠿⠿⠿⠧⠤⠤⠿⠟⠋⠀⠀⠀⠀⢸⡆⣾⣶⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⣱⣿⢃⡾⠃⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠁⢹⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⡷⠋⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠚⠁⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣿⢏⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⣸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣯⢣⣿⢃⢞⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣧⣿⣿⢃⣿⢏⢎⣼⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⢨⣇⡀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⢃⣾⣿⣞⡾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣶⣄⠀⠀⠀⠀⢀⣼⠿⣿⣿⣿⣿⣾⣿⣷⣶⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⣷⣶⣶⣶⣦⣬⣯⣭⣿⣿⣿⣿⣿⠿⣿⡿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⢰⠿⠿⠯⠽⠿⢭⣿⣺⣿⣿⣟⣿⠟⣿⣾⡼⡝⣰⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⣾⠀⠀⠀⠀⠀⠀⠀⠙⢻⣿⣿⡞⣰⣿⣹⢱⢁⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣷⢣⢣⢋⠇⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢹⣿⠏⡎⡞⣼⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⣿⢰⣧⣀⠀⠀⠀⠀⠀⠀⠀⢸⡟⡸⣽⣿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⠻⣾⡟⣿⣿⣶⣦⣠⠀⠀⠀⠘⣷⣷⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠛⠛⠒⠒⠒⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠀⢀⡀⢀⠀⣀⠄⢀⡄⢀⡠⢀⡠⠀⡠⠀⣀⠄⢀⡠⢀⠄⢀⡤⢀⡀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀
# ⠀⠀⠀⠀⠐⠿⢟⡵⠊⡡⠚⡡⠔⡩⠔⣉⠔⢋⡤⠊⡡⠖⡩⠞⣡⠖⣡⠖⡩⣺⠟⣩⣾⠗⣫⢶⣿⣾⢶⠆
# ⠀⠀⠀⠀⠀⠀⠀⠀⠉⠐⠊⠀⠊⠠⠊⣡⠖⠁⡴⠋⡴⠊⠠⠊⠠⠎⠑⠋⠘⠁⠊⠉⠉⠀⠀⠈⠀⠀⠀⠀
