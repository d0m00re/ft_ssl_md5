/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_graph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:04:08 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:04:48 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

/*
** del_content : fonction de destruction de liste chainee
*/

void		ft_destroy_graph(t_graph *graph, void (*del_content)(void *))
{
	int		i;

	i = 0;
	while (i < graph->nb_vertices)
	{
		ft_lstdestroy(&graph->nodes[i].begin, del_content);
		i++;
	}
	free(graph->nodes);
	free(graph);
}
