# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 18:19:16 by mcutura           #+#    #+#              #
#    Updated: 2023/03/13 19:17:20 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET := ft_ls
SRCS := srcs
FILES := main.c ft_strlen.c ft_puterr.c ft_flags_to_bits.c ft_flagchecks.c
FILEPATHS := $(FILES:%=$(SRCS)/%)
OBJECTS := $(FILEPATHS:%.c=%.o)
HEADERS := includes
CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(HEADERS)

all: color.purple $(TARGET)

$(TARGET): $(OBJECTS) color.green
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

clean: color.red
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

color.red:
	@echo -en "\e[31m"

color.green:
	@echo -en "\e[32m"

color.purple:
	@echo -en "\e[35m"

.PHONY: all clean fclean re
