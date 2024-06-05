##
## EPITECH PROJECT, 2023
## robotfactory
## File description:
## The main Makefile of our project
##

NAME		=	asm

BUILDDIR 	=	./build
SRCDIR		=	./src

SRCS        +=  main.c
SRCS        +=  op.c
SRCS        +=  body.c
SRCS        +=  header.c
SRCS        +=  create_robot.c
SRCS        +=  check_instructions.c
SRCS        +=  function_checker.c
SRCS        +=  label.c
SRCS        +=  file.c
SRCS        +=  bytes.c
SRCS        +=  set_instructions.c
SRCS        +=  instructions/add.c
SRCS        +=  instructions/aff.c
SRCS        +=  instructions/and.c
SRCS        +=  instructions/fork.c
SRCS        +=  instructions/ld.c
SRCS        +=  instructions/ldi.c
SRCS        +=  instructions/lfork.c
SRCS        +=  instructions/live.c
SRCS        +=  instructions/lld.c
SRCS        +=  instructions/lldi.c
SRCS        +=  instructions/or.c
SRCS        +=  instructions/st.c
SRCS        +=  instructions/sti.c
SRCS        +=  instructions/sub.c
SRCS        +=  instructions/xor.c
SRCS        +=  instructions/zjmp.c

OBJS     	=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS		=	-Werror -Wextra -g3 -I./include/

LDFLAGS 	=	-L./lib/ -lmymemory  -lmylist -lmy

all: create-build libs $(BUILDDIR) $(NAME)
	@echo -e "\033[1;33mrobotfactory compiled.\033[0m"

libs:
	@make --no-print-directory -C ./lib/my/
	@make --no-print-directory -C ./lib/mylist/
	@make --no-print-directory -C ./lib/mymemory/
	@echo -e "\033[1;33mLibs made.\033[0m"

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/instructions/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	@rm -rf ./lib/my/*.a
	@rm -rf ./lib/mylist/*.a
	@rm -rf ./lib/mymemory/*.a

clean:
	@rm -rf $(BUILDDIR)
	@echo -e "\033[1;31mAll .o deleted.\033[0m"

fclean: clean
	@rm -rf ./lib/*.a
	@rm -rf unit_tests*
	@rm -rf tests/unit_tests*
	@rm -rf vgcore*
	@rm -rf *.log
	@rm -rf $(NAME)
	@echo -e "\033[1;31mProject cleaned.\033[0m"

re:	fclean all

codingstyle: fclean
	@coding-style . .
	-@grep -vE "(:C-O1|: illegal token)" coding-style-reports.log
	@yes | rm -rf coding-style-reports.log

test: re
	@echo -e "\033[1;32mExecuting tester.sh...\033[0m"
	@./tester.sh

# Unit tests Makefile
unit_tests:
	@make unit_tests --no-print-directory -C./tests/

tests_run:
	@make tests_run --no-print-directory -C./tests/
	@gcovr
