#include "push_swap.h"

int	ft_check_num(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '-' || src[i] == '+')
			i++;
	while (src[i])
	{
		if (src[i] < '0' && src[i] > '9')
			return (0);
	}
	return (1);
}

int	ft_check_duplicates(char **args, int i, long n)
{
	i++;
	int long cmp;

	cmp = 0;
	while (args[i])
	{
		cmp = ft_atol(args[i]);
		if (cmp == n)
			return (1);
		i++;
	}
	return (0);
}

void    ft_checker_args(int argc, char **argv)
{
    char    **args;
    long    n;
    int     i;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1]);
    else
    {
        i = 1;
        args = argv;
    }
    while (args[i])
    {
        n = ft_atol(args[i]);
        if (!ft_check_num(argv[i]))
			ft_putnbr("Error");
		if (ft_check_duplicates(args, i, n) == 1)
			ft_putnbr("Error");
		if (n < -2147483648 || n > 2147483647)
			ft_putnbr("Error");
		i++;
    }
	if (argc == 2)
		free(args);
}