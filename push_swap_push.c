#include "push_swap.h"

void ft_push_a(t_stack **a, t_stack **b)
{
    if(!*b)
        return ;
    ft_stackadd_front(&a,*b);
    *b = (*b)->next_value;
    free(*b);
}