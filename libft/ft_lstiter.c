
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_copy;

	lst_copy = lst;
	if (!(lst))
		return ;
	while (lst_copy->next)
	{
		f(lst_copy->content);
		lst_copy = lst_copy->next;
	}
	f(lst_copy->content);
}
