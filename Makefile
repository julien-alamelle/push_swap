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
NAME_BONUS=checker

INCLDIR=incl
SRCDIR=src
OBJDIR=.obj

FILES=pile/pile pile/pile_push pile/pile_rot pile/pile_rrot pile/pile_swap pile/pile_util pile/pile_util2\
	quick_sort/quick_sort quick_sort/quick_sort_2\
	pile_limit/pile_limit pile_limit/pile_limit_push pile_limit/pile_limit_rot pile_limit/pile_limit_rrot pile_limit/pile_limit_swap pile_limit/pile_limit_util\
	fifo/fifo fifo/fifo_util\
	btree/btree\
	perfect_sort/perfect_sort\
	exec/exec exec/exec_push exec/exec_rot exec/exec_rrot exec/exec_swap
SUBPART=pile quick_sort pile_limit fifo btree perfect_sort exec

SRC=$(addprefix $(SRCDIR)/,$(addsuffix .c,$(FILES)))
OBJ=$(addprefix $(OBJDIR)/,$(addsuffix .o,$(FILES)))
INCL=$(addprefix $(INCLDIR)/,$(addsuffix .h,$(SUBPART)))
SUBDIR=$(addprefix $(OBJDIR)/,$(SUBPART))


all: mandatory bonus

mandatory: $(NAME)

bonus: $(NAME_BONUS)

clean:
	$(RM_RF) $(OBJDIR)

fclean: clean
	$(RM_RF) $(NAME) $(NAME_BONUS)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile $(INCL) | $(SUBDIR)
	$(CC) $(CFLAGS) -I $(INCLDIR) -o $@ -c $<

$(SUBDIR):
	$(MKDIR_P) $@

$(NAME): $(OBJDIR)/main.o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $< -o $(NAME)

$(NAME_BONUS): $(OBJDIR)/main_bonus.o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $< -o $(NAME_BONUS)

.PHONY: all mandatory bonus clean fclean re
