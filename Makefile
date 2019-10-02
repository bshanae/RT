all : RT

RT :
	@make RT -C ./build

clean :
	@make clean -C ./build

fclean :
	@make fclean -C ./build

re :
	@make re -C ./build
