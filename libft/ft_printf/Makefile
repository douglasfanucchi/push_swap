NAME			:= libftprintf.a

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror

MANDATORY_DIR	:= mandatory
SOURCE_FILES	:= ft_printf.c ft_printf_utils.c ft_printf_convert.c
SOURCES			:= $(addprefix $(MANDATORY_DIR)/,$(SOURCE_FILES))
OBJECTS			:= $(patsubst %.c, %.o, $(SOURCES))

BONUS_DIR		:= bonus
BONUS_FILES		:= ft_printf_bonus.c\
				   ft_printf_utils_bonus.c\
				   specs_setup_bonus.c\
				   ft_convert_integer_bonus.c\
				   ft_convert_char_and_str_bonus.c\
				   ft_convert_pointer_bonus.c\
				   ft_convert_base_bonus.c\
				   precision_bonus.c\
				   width_bonus.c
SOURCES_BONUS	:= $(addprefix $(BONUS_DIR)/,$(BONUS_FILES))
OBJECTS_BONUS	:= $(SOURCES_BONUS:.c=.o)

LIBFT_DIR		:= libft
LIB_INCLUDES	:= $(LIBFT_DIR)/includes 

PRINT_INCLUDES  := includes

LIBFT_HEADER	:= $(LIB_INCLUDES)/libft.h
FTPRINTF_HEADER	:= ft_printf.h

LIBFT			:= libft.a

all: .mandatory_mode

.mandatory_mode: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS)
	@rm -f .bonus_mode
	@touch .mandatory_mode

bonus: .bonus_mode

.bonus_mode: $(OBJECTS_BONUS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS_BONUS)
	@rm -f .mandatory_mode
	@touch .bonus_mode

%.o: %.c
	@echo compiling
	$(CC) $(CFLAGS) -c $< -I$(LIB_INCLUDES) -I$(PRINT_INCLUDES) -o $@


clean:
	@echo clean ft_print objects
	@rm -f .mandatory_mode .bonus_mode
	rm -f $(OBJECTS) $(OBJECTS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@echo fclean
	rm -f $(NAME)
	rm -rf $(LIBFT_DIR)/$(LIBFT)

re: fclean all 

.PHONY: all bonus clean fclean 
