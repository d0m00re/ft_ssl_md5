/*
** https://www.youtube.com/watch?v=T5MU8NDMMj4 54min
*/

#include <stdio.h>
#include <stdlib.h>
#include "ft_graph.h"

t_graph *new_graph(int vertices, e_bool is_oriented)
{
	t_graph *graph;
	int i;

	if (!(graph = (t_graph *)(malloc(sizeof(t_graph)))))
		return (0);
	graph->is_oriented = is_oriented;
	graph->nb_vertices = vertices;
	graph->tab_neightbours = malloc(vertices * sizeof(t_adjency_list));
	i = 0;
	while (i < vertices)
	{
		graph->tab_neightbours[i].begin = 0;
		i++;
	}
	return (graph);
}

e_bool is_empty_graph(t_graph *g)
{
	if (g)
		return (true);
	return (false);
}

t_node_list *get_node(int x)
{
	t_node_list *node;

	node = malloc(sizeof(t_node_list));
	if (node == 0)
		return (0);
	node->value = x;
	node->next = 0;
	return  (node);
}

void	erase_graph(t_graph *g)
{
	int i;
	t_node_list *node;
	t_node_list *tmp;

	if (is_empty_graph(g))
		return ;
	// si sommet d adjacence
	if (g->tab_neightbours)
	{
		i = 0;
		while (i < g->nb_vertices)
		{
			node = g->tab_neightbours[i].begin;
			while (node != 0)
			{
				tmp = node;
				node = node->next;
				free(tmp);	
			}
			i++;
		}
		// free adjacence tab
		free(g->tab_neightbours);
	}
	// free graphe
	free(g);
}

void	add_edge(t_graph *graph, int src, int dest)
{
	t_node_list *node;

	node = get_node(dest);
	node->next = graph->tab_neightbours[src].begin;
	graph->tab_neightbours[src].begin = node;

	//graph non oriente
	if (!(graph->is_oriented))
	{
        	node = get_node(src);
        	node->next = graph->tab_neightbours[dest].begin;
        	graph->tab_neightbours[dest].begin = node;
	}	
}

void	print_graphe(t_graph *graph)
{
	int c;
	t_node_list *node;

	if (!graph)
		return ;
	c = 0;
	while (c < graph->nb_vertices)
	{
		node = graph->tab_neightbours[c].begin;
		printf("%d)", c);
		while(node)
		{
			printf("%d, ", node->value);
			node = node->next;
		}
		printf("\n");
		c++;
	}
}

int main(void)
{
	t_graph *graph = new_graph(5, false);

	add_edge(graph, 0, 2);
	add_edge(graph, 0, 4);
	add_edge(graph, 1, 3);
        add_edge(graph, 1, 2);
        add_edge(graph, 2, 3);
        add_edge(graph, 3, 4);

	print_graphe(graph);
	erase_graph(graph);
	return (1);
}
