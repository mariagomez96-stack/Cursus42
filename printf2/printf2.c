#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *s)
{
    int i;
    
    i = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return (i);
}

int ft_find_d(int c, int counter)
{
    if (c < 0)
    {
        counter += ft_putchar ('-');
        counter = ft_find_d(-c, counter);
    }
    else if (c >= 0 && c <= 9)
    {
        counter += ft_putchar((c + '0'));
    }
    else
    {
        counter += ft_find_d(c / 10, counter);
        counter += ft_putchar((c % 10));
    }
    return (counter);

}



int ft_next(va_list args, char *str, int counter)
{
    int i;

    i = 0;
    if (str[i] == 'c')
    {
        counter += ft_putchar(va_arg(args, int));
    }
    else if (str[i] == 's')
    {
        counter += ft_putstr(va_arg(args, char *));
    }
    else if (str[i] == 'd')
    {
        counter += ft_find_d(va_arg(args, int), counter);
    }
    return (counter);
}

int ft_print2(const char *str, ...)
{
    int i;
    int counter;
    va_list args;

    i = 0;
    counter = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            counter += ft_next(args, (char *)&str[i], counter);
        }
        else
        {
            counter += ft_putstr((char *)&str[i]);
        }
        i++;
    }
    va_end(args);
    return (counter);
}

int main(void)
{
    int i;
    int i2;

    i = ft_print2("Hi print by me: ""%d", 42);
    i2 = printf("Hi, realprint es: ""%d\n", 42);
    return (0);
}