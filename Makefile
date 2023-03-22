NAME_ASM = asm
NAME_COREWAR = corewar

SRC_DIR_ASM = src/asm/
SRC_DIR_COR = src/corewar/

SRCS_ASM := asm.c \
            dop_function.c \
            dop_function2.c \
            free_del.c \
            op.c \
            oper_name.c \
            pars_name.c \
            pars.c \
            pars_one.c \
            pars_operation.c \
            pars_operation2.c \
            pars_operation3.c \
            read.c \
            proverca_registra.c \
            proverca_registra2.c \
            str_label.c \
            trace.c \
            write_code.c \
            zap_label.c \
            zap_operation.c \

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
                utils.c

OBJSFD	= tmp

OBJ_ASM = $(addprefix $(OBJSFD)/,$(SRCS_ASM:.c=.o))
OBJ_COREWAR = $(addprefix $(OBJSFD)/,$(SRCS_COREWAR:.c=.o))

LIB_DIR = ./printf/
LIBFTPRINTF = $(LIB_DIR)libftprintf.a

FLAGS = -Wall -Werror -Wextra -g

INCLUDE = inc/asm.h \
          inc/op.h \
          inc/vm.h \
          inc/vm_op.h

all: $(LIBFTPRINTF) $(NAME_ASM) $(NAME_COREWAR)

$(LIBFTPRINTF): libftprintf_a

libftprintf_a:
	make -C $(LIB_DIR)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: $(SRC_DIR_ASM)%.c | $(OBJSFD)
	gcc $(FLAGS) -c $< -o $@

$(OBJSFD)/%.o: $(SRC_DIR_COR)%.c | $(OBJSFD)
	gcc $(FLAGS) -c $< -o $@

$(NAME_ASM): $(OBJ_ASM) $(LIBFTPRINTF)
	gcc -o $(NAME_ASM) $(FLAGS) $(OBJ_ASM) $(LIBFTPRINTF)

$(NAME_COREWAR): $(OBJ_COREWAR) $(LIBFTPRINTF)
	gcc -o $(NAME_COREWAR) $(FLAGS) $(OBJ_COREWAR) $(LIBFTPRINTF)

clean:
	rm -rf $(OBJSFD)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME_ASM) $(NAME_COREWAR)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
