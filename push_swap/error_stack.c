
#include "push_swap.h"

void    ft_free_stack(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

void    ft_exit_error(t_stack **a, t_stack **b)
{
    if (!a || !(*a))
        ft_free_stack(a);
    if (!b || !(*b))
        ft_free_stack(b);
    write(1, "Error\n", 6);
    exit(1);
}