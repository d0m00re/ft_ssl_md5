/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:05:39 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:05:50 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

t_graph		*ft_make_graph(int nb_vertices, e_bool is_oriented)
{
	int		c;
	t_graph *graph;

	if (!(graph = malloc(sizeof(t_graph))))
		return (0);
	graph->is_oriented = is_oriented;
	graph->nb_vertices = nb_vertices;
	if (!(graph->nodes = malloc(nb_vertices * sizeof(t_node))))
		return (0);
	c = 0;
	while (c < nb_vertices)
	{
		graph->nodes[c].begin = 0;
		c++;
	}
	return (graph);
}
