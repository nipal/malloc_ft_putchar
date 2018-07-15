gcc ft_putchar.c -c;																# on compile la fonction que l'on veut charger dynamiquement
echo "===================="															# truc de mise en page
echo -n "" > data_ret;																# on vide le fichier de retour
gcc -w main_test.c && ./pars_instruct.sh ft_putchar.o | ./a.out 2>data_ret;			# on compile le programe qui va "malloc/mmap ft_putchar"
echo "===================="															# truc de mise en page
hexdump -C data_ret																	# debug de la section de memoire que l'on a ecrit

# Un makefile ca serait bien nan?
