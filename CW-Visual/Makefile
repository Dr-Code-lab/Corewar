NAME_COREWAR = corewar

SRC_DIR_COR = src/corewar/

SRCS_COREWAR := args.c \
                checks.c \
                cycle.c \
                errors.c \
                functions.c \
                init.c \
                koretko_utils.c \
                main.c \
                operations.c \
                operations2.c \
                operations3.c \
                parse.c \
                utils.c \
                vis.c \
                vis_color.c \
                vis_deinit.c \
                vis_hex.c \
                vis_cycle.c \
                vis_param.c \
                vis_clr_param.c \
                vis_p1.c \
                vis_p2.c

OBJSFD	= tmp

OBJ_COREWAR = $(addprefix $(OBJSFD)/,$(SRCS_COREWAR:.c=.o))

LIB_DIR = ./printf/
LIBFT = $(LIB_DIR)libftprintf.a

FLAGS = -Wall -Werror -Wextra -g

INCLUDE = inc/op.h \
          inc/vm.h \
          inc/vm_op.h \
          inc/SDL2/SDL.h \
          inc/SDL2/SDL_ttf.h

all: $(LIBFT) $(NAME_COREWAR)

$(LIBFT):
	make -C $(LIB_DIR)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: $(SRC_DIR_COR)%.c | $(OBJSFD)
	gcc $(FLAGS) -c $< -o $@

$(NAME_COREWAR): $(OBJ_COREWAR) $(LIBFT)
	gcc -o $(NAME_COREWAR) $(FLAGS) $(OBJ_COREWAR) $(LIBFT) $(SDL2) $(SDL2_TTF) -L lib -lSDL2 -lSDL2_ttf

clean:
	rm -rf $(OBJSFD)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME_COREWAR)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

