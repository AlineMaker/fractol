# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueno-te <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 02:24:24 by sueno-te          #+#    #+#              #
#    Updated: 2024/05/13 00:54:29 by sueno-te         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a

SRC_DIR		:=	src
BUILD_DIR	:=	build

SRCS		:=	\
	ft_isupper.c \
	ft_islower.c \
	ft_isspace.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_todigit.c \
	ft_tochr.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memclear.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_atof.c \
	ft_atoll.c \
	ft_atoi_base.c \
	ft_atoull_base.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_ulltoa_base.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_strcspn.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr_base_fd.c \
	ft_putptr_fd.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putptr.c \
	ft_putnbr_base.c \
	ft_putstr_len.c \
	ft_putnbr_len.c \
	ft_putptr_len.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstaddcontent_front.c \
	ft_lstaddcontent_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstcspn.c
SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(OBJS:.o=.d)

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	-I include -MMD -MP
AR			:=	ar
ARFLAGS		:=	-r -c -s

RM			:=	rm -f
MAKEFLAGS	+=	--no-print-directory

RED			:=	$(shell tput setaf 1)
GREEN		:=	$(shell tput setaf 2)
YELLOW		:=	$(shell tput setaf 3)
BLUE		:=	$(shell tput setaf 4)
RESET		:=	$(shell tput sgr0)
TITLE		:=	$(YELLOW)$(basename $(NAME))$(RESET)
message		=	$(info [$(TITLE)] $(3)$(1)$(RESET) $(2))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(call message,CREATED,$(NAME),$(BLUE))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(call message,CREATED,$(basename $(notdir $@)),$(GREEN))

clean:
	$(RM) -r $(BUILD_DIR)
	$(call message,DELETED,$(BUILD_DIR),$(RED))

fclean: clean
	$(RM) $(NAME)
	$(call message,DELETED,$(NAME),$(RED))

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
.SILENT:

-include $(DEPS)
