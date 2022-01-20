#ifndef FIFO_H
# define FIFO_H

typedef struct s_fifo_cell
{
	void		*data;
	t_fifo_cell	*next;
}	t_fifo_cell;

typedef struct s_fifo
{
	t_fifo_cell	*first;
	t_fifo_cell	*last;
	void		*del(void *);
}

t_fifo	*fifo_init(void *del(void *));
t_fifo	*fifo_dell(t_fifo *f);
void	*fifo_get(t_fifo *f);
void	fifo_add(t_fifo *f, void *data);

#endif
