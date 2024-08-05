
#include "push_swap.h"

void    rotate(t_stack **a)
{
    t_stack	*tmp;
    t_stack	*tail;

	if (!*a || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	tail = stack_tail(*a);
	tail->next = tmp;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_putnbr("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_putnbr("rb\n");
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putnbr("rr\n");
}