#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void * ft_malloc ( size_t size )
{
    int *plen;
    int len = size + sizeof( size ); // Add sizeof( size ) for holding length.

    plen = mmap( 0, len, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );

    *plen = len;                     // First 4 bytes contain length.
    return (void*)(&plen[1]);        // Memory that is after length variable.
}

void ft_free ( void * ptr )
{
    int *plen = (int*)ptr;
    int len;

    plen--;                          // Reach top of memory
    len = *plen;                     // Read length

    munmap( (void*)plen, len );
}

static	inline	int	is_alphanum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static	inline	unsigned	char	alpha_val(char c)
{
//	static	const	char	ref[17] = ""
//	int			id;
	return (((c >= '0' && c <= '9') ? (c - '0') : ((c >= 'a' && c <= 'f') ? (c - 'a' + 10) : ((c >= 'A' && c <= 'F') ? (c - 'A' + 10): 0))));
	
}

void	atohs(unsigned char *hexa, char *data)
{
	int	i, j;

	i = 0;
	j = 0;
	while (data[i])
	{
		while (isspace(data[i]))
			i++;
		if (data[i])
			hexa[j] = alpha_val(data[i++]);
		hexa[j] <<= 4;
		if (data[i])
			hexa[j++] |= alpha_val(data[i++]);
	}
	
}

//void	print_err_byte(unsigned char *data, size_t len)
//{
//	size_t	i;
//
//	i = 0;
//	while
//}

int	main()
{
	void			(*func)(char *s);
	char			*data;
	unsigned	char	*hexa;
	size_t	size, ret;
	data = NULL;

	size = 4096;
	if ((data = ft_malloc(size)) && (hexa = ft_malloc(size)))
	{
		memset(data, 0, size);
		memset(hexa, 0, size);
		ret = read(0, data, size);
		atohs(hexa, data);
	//	strcpy(data, "coucou, ca va?");
		printf("input{%1$p}	:%1$s\n", data);
		write(2, hexa, size);
//		dprintf(2, "instruct{%1$p}	:%1$s\n", hexa);
		func = hexa;
		char buff[50];
		func(buff);
		printf(">>> %s <<<\n", buff);
	}
	else
	{
		printf("ooooooh! ...\n");
	}
	return (0);
}
