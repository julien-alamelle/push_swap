#ifndef PILE_H
# define PILE_H

 /********************************************************\
 * last_op :                                              *
 *   0 : nothing                                          *
 *   0 : pb   conflict pa                                 *
 *   1 : pa   conflict pb, nothing                        *
 *   2 : sa   conflict sa, sb, ss                         *
 *   2 : sb   conflict sa, sb, ss                         *
 *   2 : ss   conflict sa, sb, ss                         *
 *   4 : ra   conflict rb, rra, rrr   not after rr, rrb   *
 *   8 : rb   conflict ra, rrb, rrr   not after rr, rra   *
 *  16 : rr   conflict rra, rrb, rrr                      *
 *  32 : rra  conflict ra, rr, rrb                        *
 *  64 : rrb  conflict ra, rr, rra                        *
 * 128 : rrr  conflict ra, rb, rr     not after rra, rrb  *
 \********************************************************/

typedef struct s_pile
{
	int		n;
	int		*u;
	int		*o;
	int		a;
	int		b;
	unsigned char	last_op;
}	t_pile;

t_pile	*pile_init(int ac, char **av);
t_pile	*pile_copy(t_pile *p);
t_pile	*pile_del(t_pile *p);
int	*get_pos(t_pile *p);
t_pile	*sa(t_pile *p);
t_pile	*sb(t_pile *p);
t_pile	*ss(t_pile *p);
t_pile	*pa(t_pile *p);
t_pile	*pb(t_pile *p);
t_pile	*ra(t_pile *p);
t_pile	*rb(t_pile *p);
t_pile	*rr(t_pile *p);
t_pile	*rra(t_pile *p);
t_pile	*rrb(t_pile *p);
t_pile	*rrr(t_pile *p);

#endif
