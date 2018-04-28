#include <unistd.h>
#include <stdio.h>

void	ft_1(char c)
{
	printf("hahahahahah je suis le plus fort\n");
	write(1, &c, 1);
}

void	ft_2(char c)
{
	printf("hahahahahah je suis le plus fort\n");
	write(1, &c, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	truc()
{
	ft_putchar('S');
	ft_putchar('a');
	ft_putchar('l');
	ft_putchar('u');
	ft_putchar('t');
	ft_putchar('\n');


	ft_1('S');
	ft_1('a');
	ft_1('l');
	ft_1('u');
	ft_1('t');
	ft_1('\n');


	ft_2('S');
	ft_2('a');
	ft_2('l');
	ft_2('u');
	ft_2('t');
	ft_2('\n');
}
