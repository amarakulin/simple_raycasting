
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_copy;
	t_list	*lst_new;
	t_list	*lst_temp;

	if (!(lst))
		return (NULL);
	lst_copy = lst;
	lst_new = NULL;
	while (lst_copy)
	{
		if (!(lst_temp = ft_lstnew(f(lst_copy->content))))
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, lst_temp);
		lst_copy = lst_copy->next;
	}
	return (lst_new);
}
