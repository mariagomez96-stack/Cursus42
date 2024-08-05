#include "push_swap.h"

void    reverse_rotate(t_stack **a)
{
    t_stack *tail;
    t_stack *before_tail;
    
    if (!*a || (*a)->next == NULL)
        return ;
    tail = stack_tail(*a);
    before_tail = stack_before_tail(*a);
    before_tail->next = NULL;
    tail->next = *a;
    *a = tail;
}

void    rra(t_stack **a)
{
    reverse_rotate(a);
    ft_putnbr("rra\n");
}

void    rrb(t_stack **b)
{
    reverse_rotate(b);
    ft_putnbr("rrb\n");
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putnbr("rrr\n");
}

    