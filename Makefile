# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalamell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:18:09 by jalamell          #+#    #+#              #
#    Updated: 2022/02/03 17:10:27 by jalamell         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
MKDIR_P=mkdir -p
RM_RF=rm -rf
NAME=push_swap

INCLDIR=incl
SRCDIR=src
OBJDIR=.obj

FILES=main\
	pile/pile pile/pile_push pile/pile_rot pile/pile_rrot pile/pile_swap pile/pile_util pile/pile_util2\
	quick_sort/quick_sort quick_sort/quick_sort_2\
	pile_limit/pile_limit pile_limit/pile_limit_push pile_limit/pile_limit_rot pile_limit/pile_limit_rrot pile_limit/pile_limit_swap\
	fifo/fifo\
	btree/btree\
	perfect_sort/perfect_sort
SUBPART=pile quick_sort pile_limit fifo btree perfect_sort

SRC=$(addprefix $(SRCDIR)/,$(addsuffix .c,$(FILES)))
OBJ=$(addprefix $(OBJDIR)/,$(addsuffix .o,$(FILES)))
INCL=$(addprefix $(INCLDIR)/,$(addsuffix .h,$(SUBPART)))
SUBDIR=$(addprefix $(OBJDIR)/,$(SUBPART))


all:
	@make -C . -k $(NAME)

clean:
	$(RM_RF) $(OBJDIR)

fclean: clean
	$(RM_RF) $(NAME)

re: fclean
	@make -C .

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile $(INCL) | $(SUBDIR)
	$(CC) $(CFLAGS) -I $(INCLDIR) -o $@ -c $<

$(SUBDIR):
	$(MKDIR_P) $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re
