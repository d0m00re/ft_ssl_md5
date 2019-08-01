/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_graph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:05:24 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:05:31 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"
#include <stdio.h>

void	ft_display_graph(t_graph *graph, void (*display_lst)(void *))
{
	int i;

	i = 0;
	while (i < graph->nb_vertices)
	{
		printf("Node %d:\n", i);
		ft_lstdisplay(graph->nodes[i].begin, display_lst);
		i++;
	}
}
