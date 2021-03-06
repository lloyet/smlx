# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/09/20 01:31:31 by lloyet       #+#   ##    ##    #+#        #
#    Updated: 2019/02/17 23:29:04 by lloyet      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libsmlx.a

# COMPILER#

CC	= clang
CFLAGS = -Wall -Wextra -Werror

# DIR

SRCDIR = ./src/
INCDIR = ./inc/
OBJDIR = ./obj/
LIBDIR = ../

SRC =	framework.c \
		framework_utils.c \
		window.c \
		window_utils.c \
		image.c \
		draw.c \
		
OBJ	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

# FT_LIBRARY#

FT = $(addprefix $(LIBDIR), libft)
LIBFT = $(addprefix $(FT), /libft.a)
LIBINC = -I $(FT)
LIBLINK	= -L $(FT) -lft

.PHONY: all clean fclean re
.SILENT: $(OBJDIR) fclean clean re
all: $(OBJDIR) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[$(NAME)]: all done."

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
