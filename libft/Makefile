NAME		:=	libft.a
SRC_DIR		:=	./src
OBJ_DIR		:=	./obj
INC_DIR		:=	./include

INCLUDE		:= -I $(INC_DIR)

COMPILE		=	$(CC) $(FLAGS)

#===============================================#
#=================== SOURCES ===================#
#===============================================#

SRC_DIR_ASCII	:=	/ascii
SRC_ASCII		:=	ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \

SRC_DIR_CONVERT	:=	/convert
SRC_CONVERT		:=	ft_atoi.c \
					ft_itoa.c \
					ft_tolower.c \
					ft_toupper.c

SRC_DIR_LST		:=	/list
SRC_LST			:=	ft_lstadd_back.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c  \
					ft_lstsize.c \
					ft_lstadd_front.c \
					ft_lstdelone.c \
					ft_lstlast.c \
					ft_lstnew.c

SRC_DIR_MEM		:=	/mem
SRC_MEM			:=	ft_bzero.c \
					ft_calloc.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c

SRC_DIR_PRINTF	:=	/printf
SRC_PRINTF		:=	ft_printf.c \
					helpers.c \
					hex_helpers.c \
					num_helpers.c

SRC_DIR_GNL		:=	/gnl
SRC_GNL			:=	get_next_line.c \
					get_next_line_utils.c

SRC_DIR_PUT		:=	/put
SRC_PUT			:=	ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c

SRC_DIR_STR		:=	/string
SRC_STR			:=	ft_free_split.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c

SRC				:=	$(addprefix $(SRC_DIR_ASCII)/,$(SRC_ASCII)) \
					$(addprefix $(SRC_DIR_CONVERT)/,$(SRC_CONVERT)) \
					$(addprefix $(SRC_DIR_LST)/,$(SRC_LST)) \
					$(addprefix $(SRC_DIR_GNL)/,$(SRC_GNL)) \
					$(addprefix $(SRC_DIR_MEM)/,$(SRC_MEM)) \
					$(addprefix $(SRC_DIR_PRINTF)/,$(SRC_PRINTF)) \
					$(addprefix $(SRC_DIR_PUT)/,$(SRC_PUT)) \
					$(addprefix $(SRC_DIR_STR)/,$(SRC_STR))

SRC				:=	$(SRC:%=$(SRC_DIR)%)

OBJ				:=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_SUB_DIRS	:=	$(sort $(dir $(OBJ)))

DEP				:=	$(OBJ:%.o=%.d)
#===============================================#
#=================== UTENSILS ==================#
#===============================================#

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

#===============================================#
#=================== RECIPES ===================#
#===============================================#

-include $(DEP)

echo:
	@echo $(OBJ)
	echo
	@echo $(SRC)
	echo
	@echo $(DEP)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -crs $(NAME) $^
	@echo "ar rcs $(NAME) $(OBJ_DIR)/*/*.o"

$(OBJ_SUB_DIRS):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_SUB_DIRS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o : %.c
	@$(COMPILE) -MMD $(HEADER) -c $< -o $@

re: fclean all

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -f $(NAME)

.DEFAULT_GOAL := all