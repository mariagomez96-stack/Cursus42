
#include "push_swap.h"

void    swap(t_stack **a)
{
    t_stack *tmp;
    t_stack *tmp2;

    if (!(*a) || ((*a)->next) == NULL)
        return ;
    tmp = (*a)->next;
    tmp2 = *a;
    *a = tmp;
    (*a)->next = tmp2;
}

void    sa(t_stack **a)
{
    swap(a);
    ft_putstr("sa\n");
}

void    sb(t_stack **b)
{
    swap(b);
    ft_putstr("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_putstr("ss\n");
}