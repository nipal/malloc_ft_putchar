gcc ft_putchar.c -c;
objdump -d ft_putchar.o
echo "===================="
echo -n "" > data_ret;
gcc -w main_test.c && ./pars_instruct.sh ft_putchar.o | ./a.out 2>data_ret;
echo "===================="
hexdump -C data_ret
