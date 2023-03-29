NAME	:=	fdf

OBJ_DIR	:=	./obj
SRC_DIR :=	./src
INC_DIR :=	./include \
			./libft/include

CFLAGS	= -Wextra -Wall -Werror

ifdef DEBUG
CFLAGS += -pg
endif

LIBMLX	:= ./MLX42 
INCLUDE	:= $(addprefix -I, $(INC_DIR))
LIBS	:= ./MLX42/libmlx42.a ./libft/libft.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit 

SRCS	:= 		$(shell ls src/)
OBJS	:= 		$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: libmlx $(NAME)

$(OBJ_DIR):
	mkdir -p $@

mem : $(OBJ)
	./memdetect/memdetect.sh $(OBJ) ./libft/libft.a

libmlx:
	@$(MAKE) -C $(LIBMLX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ && printf "Compiling: $(notdir $<) "

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C ./libft fclean

re: clean all

debug:
	$(MAKE) DEBUG=1

rebug: fclean
	$(MAKE) debug

.PHONY: all, clean, fclean, re, libmlx