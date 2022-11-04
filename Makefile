NAME = bsq
SOURCE_DIR = src/
HEADER_DIR = lib/
FUNCTIONS = ft_lib ft_file ft_file2 bsq bsq2
FLAGS =
MAIN = main.c

.PHONY: all clean fclean re

all:
	@gcc -I $(HEADER_DIR) $(FLAGS) -c $(patsubst %,$(SOURCE_DIR)%.c,$(FUNCTIONS)) 
	@gcc -I $(HEADER_DIR) $(FLAGS) $(patsubst %,%.o,$(FUNCTIONS)) $(MAIN) -o $(NAME)
			
clean:
	@rm -f $(patsubst %,%.o,$(FUNCTIONS))
				
fclean: clean
	@rm -f $(NAME)
					
re: fclean all
