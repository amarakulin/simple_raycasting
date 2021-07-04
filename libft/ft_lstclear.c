
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_copy;
	t_list	*temp;

	if (!(lst))
		return ;
	lst_copy = *lst;
	while (lst_copy->next)
	{
		del(lst_copy->content);
		temp = lst_copy;
		lst_copy = lst_copy->next;
		free(temp);
	}
	*lst = lst_copy->next;
	del(lst_copy->content);
	free(lst_copy);
}
