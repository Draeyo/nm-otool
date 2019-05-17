#include "otool.h"

static size_t	is_power_of_two(size_t n)
{
	return (n && (!(n & (n - 1))));
}

static ssize_t	find_position(size_t n)
{
	size_t		i;
	ssize_t		pos;

	if (!is_power_of_two(n))
		return (-1);
	i = 1;
	pos = 1;
	while (!(i & n))
	{
		i = i << 1;
		++pos;
	}
	return (pos);
}

size_t			align_number(size_t input, size_t align)
{
	size_t		ret;
	ssize_t		pos;

	pos = find_position(align) - 1;
	if (pos < 0)
		return (-1);
	if ((input % align))
		ret = 1;
	else
		ret = 0;
	ret = (((input >> pos) + ret) * align);
	return (ret);
}