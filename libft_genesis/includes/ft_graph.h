/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:58:14 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 16:08:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H
# include "ft_linked_list.h"

# define FALSE		0
# define TRUE		0

/*
** matrices d adjacence
*/

typedef struct		s_node
{
	t_linked_list	*begin;
}					t_node;

typedef struct		s_graph
{
	e_bool			is_oriented;
	int				nb_vertices;
	t_node			*nodes;
}					t_graph;

t_graph				*ft_make_graph(int nb_vertices, e_bool is_oriented);

void				ft_destroy_graph(t_graph *graph,\
		void (*del_content)(void *));

void				ft_display_graph(t_graph *graph,\
		void (*display_lst)(void *));

e_bool				ft_graph_exist(t_graph *graph);

#endif
