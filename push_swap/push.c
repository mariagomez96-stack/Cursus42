
#include "push_swap.h"

void    push(t_stack **src, t_stack **dest)
{

    t_stack *tmp;
    
    if (!*src)
        return ;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
}

void    push_a(t_stack **a, t_stack **b)
{
    push(b, a);
    ft_putstr("pa\n");
}

void    push_b(t_stack **a, t_stack **b)
{
    push(a, b);
    ft_putstr("pb\n");
}