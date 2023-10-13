################# Name ######################

NAME	= libft.a

################# Compilateur ######################

CC		= gcc

################# Flag ######################

CFLAGS	= -Wall -Wextra -Werror -g

################# Path ######################

SRC_PATH			= ./src/
SORT_PATH			=./src/tri/
LIST_PATH			= ./src/list/simpl_list/
DLIST_PATH			= ./src/list/doubl_list/
GNL_SRC_PATH		= ./src/gnl/
PRINTF_SRC_PATH		= ./src/ft_printf/
GARBAGE_PATH		= ./src/garbage_collector/
GARBAGE_LIST_PATH	= ./src/garbage_collector/list/

################# Sources ######################

SRC	= ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_itoa.c \
			ft_strdup.c \
			ft_strchr.c \
			ft_nbrlen_d.c \
			ft_nbrlen_exa.c \
			ft_strrchr.c \
			ft_strlen.c \
			ft_islower.c \
			ft_isupper.c \
			ft_free_2da.c \
			ft_free_arrays.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_split.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_substr.c \
			ft_strnstr.c \
			ft_bzero.c \
			ft_nbrlen_b.c \
			ft_itob.c \
			ft_btoi.c \
			ft_atob.c \
			ft_power.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_calloc.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_striteri.c \
			ft_free.c \
			ft_swap.c \
			ft_exit.c \
			ft_strcmp.c

SORT_SRC		= bubblesort.c \
				quicksort.c

SRC_SLIST	= ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c

SRC_DLIST	= ft_dlst_addback.c \
				ft_dlst_addfront.c \
				ft_dlst_clear.c \
				ft_dlst_new.c \
				ft_dlst_newcontent.c \
				ft_pop_front.c \
				ft_pop_back.c \
				ft_dlst_add.c \
				ft_dlst_delone.c

SRCS_GNL	= get_next_line.c \
				get_next_line_utils.c

SRCS_PRINTF	= ft_printf.c \
				ft_print_c.c \
				ft_print_d.c \
				ft_print_hex.c \
				ft_print_p.c \
				ft_print_s.c \
				ft_print_u.c

SRCS_GRBG	= list/gc_dlst_new.c \
				list/gc_dlst_newcontent.c \
				list/gc_lstnew.c \
				gc_calloc.c \
				gc_split.c \
				gc_strdup.c \
				gc_strjoin.c \
				gc_substr.c \
				my_malloc.c

SRCS	= $(addprefix $(SRC_PATH)/,$(SRC)) $(addprefix $(LIST_PATH)/,$(SRC_SLIST)) $(addprefix $(DLIST_PATH)/,$(SRC_DLIST)) $(addprefix $(GNL_SRC_PATH)/,$(SRCS_GNL)) $(addprefix $(PRINTF_SRC_PATH)/,$(SRCS_PRINTF)) $(addprefix $(SORT_PATH)/,$(SORT_SRC)) $(addprefix $(GARBAGE_PATH)/,$(SRCS_GRBG))
OBJS	= $(SRCS:.c=.o)


################# Colors ######################

BOLD		=			\e[1m
UNDERLINE	=			\e[4m
BLACK		=			\e[30m
VIOLET		=			\e[35m
CYAN		=			\e[36m
GREEN		=			\033[1;32m
BG_GREEN	=			\033[42m
BLUE		=			\033[0;94m
RED			=			\033[1;31m
GREY		=			\033[0;37m
ENDCOLOR	=			\033[0m

#***** Messages *****#

START		= @echo "											$(GREEN)Compilation of $(NAME) started\n$(ENDCOLOR)"
END_COMP	= @echo "											       $(GREEN)Compilation is done !$(ENDCOLOR)"
CLEAN_TXT	= @echo "												   Deleting $(RED)objects$(ENDCOLOR)"
FCLEAN_TXT	= @echo "												   Deleting $(RED)program$(ENDCOLOR)"
BS_N		= @echo "\n"

#***** Message compilation *****#

TOTAL_FILES		= $(words $(SRCS))
COMPILED_FILE	= 0
MESSAGE			= "			Compilation en cours : $(COMPILED_FILES)/$(TOTAL_FILES) ($(shell expr $(COMPILED_FILES) \* 100 / $(TOTAL_FILES))%)"


all :	start $(NAME)

start :
			@clear
			@tput setaf 2; cat ascii_art/my_libft1; tput setaf default
			@$(BS_N)
			@$(START)
			@sleep 2
			@clear

%.o: %.c
			@${CC} ${CFLAGS} -c $< -o $@
			$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
			@printf "								$(GREEN)%s$(ENDCOLOR)" $(MESSAGE)
			@sleep 0.001
			@printf "\r"

re : fclean all

clean :
		@clear
		@$(CLEAN_TXT)
		@$(RM) $(SRC_PATH)*.o $(GNL_SRC_PATH)*.o $(PRINTF_SRC_PATH)*.o $(DLIST_PATH)*.o $(LIST_PATH)*.o $(GARBAGE_PATH)*.o $(SORT_PATH)*.o $(GARBAGE_LIST_PATH)*.o
		@$(BS_N)
		@tput setaf 1; cat ascii_art/trash; tput setaf default

fclean : clean
		@$(FCLEAN_TXT)	
		@$(RM) $(NAME)
		@echo "												    $(GREEN)Cleaning succes$(ENDCOLOR)"
		@$(BS_N)
		@$(BS_N)

$(NAME) : $(OBJS)
		@$(BS_N)
		@$(BS_N)
		@printf "\n												$(BLUE)GNL objects$(ENDCOLOR)	[$(GREEN)✓$(ENDCOLOR)]\n"
		@printf "												$(BLUE)PRINTF objects$(ENDCOLOR)	[$(GREEN)✓$(ENDCOLOR)]\n"
		@printf "												$(BLUE)LIBFT objects$(ENDCOLOR)	[$(GREEN)✓$(ENDCOLOR)]\n"
		@ar -rs $(NAME) $(OBJS)
		@$(END_COMP)
		@$(BS_N)
		@tput setaf 1; cat ascii_art/dragon; tput setaf default


RM		= rm -f

.PHONY: all re clean fclean