
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*end_lst;

	end_lst = lst;
	if (!(lst))
		return (NULL);
	while (end_lst->next)
	{
		end_lst = end_lst->next;
	}
	return (end_lst);
}
