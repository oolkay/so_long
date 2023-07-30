NAME	= so_long
CC		= gcc
CCFLAG	= -Wall -Werror -Wextra
RM		= rm -f
MLXDIR = mlx
SRCDIR = src
GNLDIR = gnl
GNL = $(wildcard gnl/*.c)
GNLOBJS = $(GNL:.c=.o)
SRC 	= $(wildcard src/*.c)
SRCBONUS	= $(wildcard bonus/*.c)
OBJ		= $(SRC:.c=.o)
OBJBONUS	= $(SRCBONUS:.c=.o)
LFLAGS = -framework OpenGL -framework AppKit

all: $(NAME) show run

${NAME}: libmlx.a ${OBJ} ${GNLOBJS}
	@${CC} ${CCFLAG} ${OBJ} ${GNLOBJS} $(MLXDIR)/libmlx.a ${LFLAGS} -o ${NAME}

libmlx.a:
	@make -C ${MLXDIR}

bonus: libmlx.a ${OBJBONUS} ${GNLOBJS}
	@${CC} ${CCFLAG} ${GNLOBJS} ${OBJBONUS} $(MLXDIR)/libmlx.a ${LFLAGS} -o ${NAME}_bonus

%.o : %.c
	@printf "[1;33m"
	@${CC} ${CCFLAG} -c $< -o $@


show:
	@printf "[1;33m"
	@printf "*********************************************************\n"
	@printf "[1;35m"
	@printf "11111   11111   11       11111      111     11   1111111 \n"
	@printf "[1;35m"
	@printf "11     11   11  11      11    11    11 11   11  11       \n"
	@printf "[1;35m"
	@printf "11111  11   11  11      11    11    11  11  11  11   111 \n"
	@printf "[1;35m"
	@printf "   11  11   11  11      11    11    11   11 11  11     11\n"
	@printf "[1;35m"
	@printf "11111   11111   111111   111111     11    11 1   1111111 \n"
	@printf "[1;33m"
	@printf "*********************************************************\n"
	@printf "[1;30m"
	@printf "<<<<<<<<<< "
	@printf "[1;37m"
	@printf "THE SO_LONG IS READY TO BE EXECUTED"
	@printf "[1;30m"
	@printf " >>>>>>>>>>\n"

norm:
	@printf "[1;32m"
	@norminette src gnl bonus
	
clean:
	@printf "[1;37m"
	@$(RM) $(OBJ)
	@$(RM) $(GNLOBJS)
	@$(RM) $(OBJBONUS)
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re norminette
