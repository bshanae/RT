all : RT

RT :
	@make test -C ./build

RT_float :
	@make re_no_extern -C ./build VAR_PROJECT_FLAGS_ANY="-D RT_FLOAT"

RT_double :
	@make re_no_extern -C ./build VAR_PROJECT_FLAGS_ANY="-D RT_DOUBLE"

clean :
	@make clean -C ./build

fclean :
	@make fclean -C ./build

re :
	@make re -C ./build


.PHONY : RT clean fclean re	
