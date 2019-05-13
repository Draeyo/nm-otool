#include "libft.h"

static void		print_hex(unsigned long nb)
{
	const char	*tmp = "0123456789abcdef";

	if (nb >= 16)
	{
		print_hex(nb / 16);
		print_hex(nb % 16);
	}
	else
		ft_putchar(tmp[nb]);
}

void			ft_print_mem(void *ptr)
{
	ft_putstr("0x");
	print_hex((unsigned long)ptr);
}
