#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 11:47:33 by echavez-          #+#    #+#              #
#    Updated: 2023/07/10 22:24:02 by echavez-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME        =   so_long

#****************** INC *******************#
# General
INC         =   ./include/                  # Project header files drectory

# Libft
LIB         =   ./lib/libft/                # Library to include
LIB_H       =   ./lib/libft/                # Library header files directory

# Minilibx
LIBMLX         =   ./lib/minilibx-linux/    # Library to include
LIBMLX_H       =   ./lib/minilibx-linux/    # Library header files directory


INCLUDE     =   -O3 -I $(LIB_H) -I $(LIBMLX_H) -I $(INC)

LIB_INC     =   -L$(LIB) -lft -L$(LIBMLX) -lmlx -lXext -lX11 -lm -lbsd

#****************** SRC *******************#

DIRSRC      =   ./src/
DIRFOO      :=  $(DIRSRC)analyzer/
DIRLOAD		:=	$(DIRSRC)load/
DIRGRAPHICS	:=	$(DIRSRC)graphics/
DIRGAME		:=	$(DIRSRC)game/

DIRS        :=  $(DIRSRC) $(DIRFOO) $(DIRLOAD) $(DIRGRAPHICS) $(DIRGAME)

SRC         =   main.c
FOO         =	analyzer.c map.c
LOAD		=	load.c
GRAPHICS	=	graphics.c image.c
GAME		=	game.c

SRCS        :=  $(SRC) $(FOO) $(LOAD) $(GRAPHICS) $(GAME)

#***************** DEPS ******************#

DIROBJ      =   ./depo/

#********************************* END OF CONFIG *********************************#

OAUX        =   $(SRCS:%=$(DIROBJ)%)
DEPS        =   $(OAUX:.c=.d)
OBJS        =   $(OAUX:.c=.o)

.ONESHELL:

$(info Creating directory...)
$(shell mkdir -p $(DIROBJ))

ifdef FLAGS
    ifeq ($(FLAGS), no)
CFLAGS      =
    endif
    ifeq ($(FLAGS), debug)
CFLAGS      =   -Wall -Wextra -Werror -ansi -pedantic -g
    endif
else
CFLAGS      =   -Wall -Wextra -Werror
endif

ifdef VERB
    ifeq ($(VERB), on)
CFLAGS      +=  -DM_VERB
    endif
endif

ifndef VERBOSE
.SILENT:
endif

ENV         =   /usr/bin/env
CC          =   $(ENV) clang
RM          =   $(ENV) rm -rf
ECHO        =   $(ENV) echo -e
MKDIR       =   $(ENV) mkdir -p
GIT         =   $(ENV) git
BOLD        =   "\e[1m"
BLINK       =   "\e[5m"
RED         =   "\e[38;2;255;0;0m"
GREEN       =   "\e[92m"
BLUE        =   "\e[34m"
YELLOW      =   "\e[33m"
E0M         =   "\e[0m"

#******************************* DEPS COMPILATION ********************************#

define generate_objects
$(DIROBJ)%.o    :   $(1)%.c
	                @printf $(GREEN)"Generating $(NAME) objects... %-33.33s\r"$(E0M) $$@
	                @$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $$@ -c $$<
endef

# Generate objects
$(foreach dir,$(DIRS),$(eval $(call generate_objects,$(dir))))

#******************************* MAIN COMPILATION ********************************#

$(NAME)         :       ftlib $(OBJS)
	                @$(CC) $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_INC)
	                @$(ECHO) $(BOLD)$(GREEN)'> '$(NAME)' Compiled'$(E0M)

$(OBJS): | mkdepo

clean           :
	                @($(RM) $(OBJS))
	                @($(RM) $(DEPS))
	                @($(RM) $(DIROBJ))
	                @(cd $(LIB) && $(MAKE) clean)
					@(cd $(LIBMLX) && $(MAKE) clean)
	                @$(ECHO) $(BOLD)$(RED)'> '$(NAME)' directory        cleaned'$(E0M)

all             :       $(NAME)

fclean          :       clean
	                @$(RM) $(NAME)
	                @(cd $(LIB) && $(MAKE) fclean)
					@(cd $(LIBMLX) && $(MAKE) fclean)
	                @$(ECHO) $(BOLD)$(RED)'> Executable             removed'$(E0M)


re              :  fclean mkdepo all

mkdepo			:
					@$(MKDIR) $(DIROBJ)


ftlib           :
	                @(cd $(LIB) && $(MAKE))
					@(cd $(LIBMLX) && $(MAKE))

init            :
	                @$(GIT) submodule init
	                @$(GIT) submodule update

.PHONY          :       all clean re fclean ftlib

-include $(DEPS)
