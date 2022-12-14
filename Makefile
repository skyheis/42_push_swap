# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:49:20 by ggiannit          #+#    #+#              #
#    Updated: 2022/12/14 12:19:34 by ggiannit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = push_swap
PRNAME = push_swap

BNUS = checker

INCLUDE = include

###### VARIABLE ######

DIRSRCS =
DIROBJS = obj/

FLSRCS = ft_istack.c ft_istack_utils.c ft_stackmove.c \
		ft_algo_utils.c ft_small_sort.c ft_sort_three.c \
		ft_biggest_sort.c ft_biggest_sort_utils.c \
		ft_bubbleing.c ft_check_n_make.c ft_debugging.c

FLOBJS = ${FLSRCS:.c=.o}

FLBNSRCS = checker_bonus.c ft_exec_your_rules_bonus.c \
		   ft_istack_bonus.c ft_stackmove_bonus.c

FLBNOBJS = ${FLBNSRCS:.c=.o}

OBJS = $(addprefix $(DIROBJS),$(FLOBJS))
BNOBJS = $(addprefix $(DIROBJS),$(FLBNOBJS))

ARUSD = libft.a
ARUSDDIR = archive/

ARINC = $(addprefix $(ARUSDDIR),$(ARUSD))

CC = cc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

#.c.o:
$(DIROBJS)%.o: $(DIRSRCS)%.c
	@echo "$(YELLOW)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

#$(DIRBNOBJS)%.o: $(DIRBNSRCS)%.c
#	@echo "$(YELLOW)Compiling:$(BLUE) $< $(DEF_COLOR)"
#	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

####### RULES ########

all: libft ${NAME}

${NAME}: starting ${OBJS}
	@echo ""
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo ""
	@${CC} ${CFLAGS} -I ${INCLUDE} -o $(PRNAME) main.c $(OBJS) $(ARINC)
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${PRNAME}$(DEF_COLOR)"
	@echo ""

bonus: starting_bonus ${OBJS} ${BNOBJS}
	@echo ""
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo ""
	@${CC} ${CFLAGS} -I ${INCLUDE} -o $(BNUS) $(OBJS) $(BNOBJS) $(ARINC)
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${BNUS}$(DEF_COLOR)"
	@echo ""

clean: libftclean
	@echo "$(WHITE)\"wait.. is $(CYAN)${PRNAME}$(WHITE) all trash? 🧹\" $(DEF_COLOR)"
	@${RM} ${OBJS} 
	@echo "$(RED)All objects removed with $(WHITE)${RM}$(DEF_COLOR)"
	@echo ""

fclean: clean
	@echo "$(WHITE)\"...it's always as been 🚮\" $(DEF_COLOR)"
	@${RM} ${PRNAME} ${BNUS}
	@echo "$(RED)..and $(CYAN)${ARNAME}, ${BNUS} $(RED)as been removed$(DEF_COLOR)"
	@echo ""

libft:
	cd libft && ${MAKE}

libftclean:
	cd libft && ${MAKE} clean

libftre:
	cd libft && ${MAKE} re

re: fclean all

starting:
	@echo "$(WHITE)🧙as a wizard, I made appear your $(CYAN) $(BNUS) $(WHITE)binary!🪄 💫$(DEF_COLOR)"

starting_bonus:
	@echo "$(WHITE)🧙as a wizard, I made appear your $(CYAN) $(PRNAME) $(WHITE)binary!🪄 💫$(DEF_COLOR)"

.PHONY: all clean fclean re bonus starting starting_bonus .c.o libft libftclean libftre exec
.SUFFIXES: .c .o 
