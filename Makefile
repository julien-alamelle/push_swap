# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalamell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:18:09 by jalamell          #+#    #+#              #
#    Updated: 2022/02/01 17:24:13 by jalamell         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
MKDIR_P=mkdir -p
RM_RF=rm -rf
NAME=push_swap

INCLDIR=incl/
SRCDIR=src/
OBJDIR=.obj/

FILES=main\
	  pile/pile pile/pile_push pile/pile_rot pile/pile_rrot pile/pile_swap pile/pile_util\
	  quick_sort/quick_sort quick_sort/quick_sort_2\
	  pile_limit/pile_limit_push
INCLFILES=pile.h quick_sort.h pile_limit.h
SUBDIR=pile/ quick_sort/ pile_limit/

SRC=$(addprefix $(SRCDIR),$(addsuffix .c,$(FILES)))
OBJ=$(addprefix $(OBJDIR),$(addsuffix .o,$(FILES)))
INCL=$(addprefix $(INCLDIR),$(INCLFILES))
DIRS=$(addprefix $(OBJDIR),$(SUBDIR))


all: $(NAME)

clean:
	$(RM_RF) $(OBJDIR)

fclean: clean
	$(RM_RF) $(NAME) $(AFILE)

re: fclean
	@make -C .

$(OBJDIR)%.o: $(SRCDIR)%.c Makefile $(INCL) | $(OBJDIR) $(DIRS)
	$(CC) $(CFLAGS) -I $(INCLDIR) -o $@ -c $<

$(DIRS): $(OBJDIR)
	$(MKDIR_P) $(DIRS)

$(OBJDIR):
	$(MKDIR_P) $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re
