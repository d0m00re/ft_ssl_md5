#include "ft_graph.h"
#include <stdio.h>

/*
** interface pour les linked list
*/

typedef struct s_perso_node
{
	int target;
	double dist;
} t_perso;

void *get_node(int target, double dist)
{
	t_perso *node;

	if (!(node = malloc(sizeof(t_perso))))
		return (0);
	node->dist = dist;
	node->target = target;
	return (node);
}

void read_node_perso(void *data)
{
	t_perso *perso;

	perso = (t_perso *)data;
	printf("\t%d | dist : %f\n", perso->target, perso->dist);
}

void destroy_node_perso(void *data)
{
	data = (void *)data;
	return ;
}

/*
** interface pour les graphes
** src : node de base
** dest : node cible
** dist : distance les separants
*/
void add_edge(t_graph *graph, int src, int dest, double dist)
{
	t_perso *perso;

	perso = get_node(dest, dist); // lien vers le node d id target, ajout de la distance
	ft_lstpush_front(&(graph->nodes[src].begin), perso);
	if (graph->is_oriented)
	{
        	perso = get_node(src, dist); // lien vers le node d id target, ajout de la distance
        	ft_lstpush_front(&(graph->nodes[dest].begin), perso);
	}
}

// contiendra l element actuel pour l algo de dijkstra :)
// id du noeud : indice de l element dans le futur tableu
typedef struct s_dijkstra
{
	double min_dist; // POIDS
	int runing; // 0 non | 1 : oui
	int id_antecedent; // id du noeud antecedant
} t_dij;

// initialisation de tout les points du graphe a inf oun0 pour le debut
t_dij *init_dij(t_graph *graph, int sdeb)
{
	int c;
	t_dij *dij;

	dij = (t_dij *)(malloc(sizeof(t_dij) * graph->nb_vertices));
	c = 0;
	while (c < graph->nb_vertices)
	{
		dij[c].min_dist = 100000.0;  //valeur mise a jour au cours du programme
		dij[c].runing = 0;
		dij[c].id_antecedent = -1;
		c++;
	}
	dij[sdeb].min_dist = 0.0;
	dij[sdeb].runing = 1;
	return (dij);
}

/*
	Structure contenu dans la liste chainee
	typedef struct s_perso_node
	{
        	int target;
        	double dist; // valeur du lien
	} t_perso;
*/
/*
void	update_son(t_graph *graph, t_dij *dij, int id_parent)
{
        t_linked_list *l;
        t_perso *perso;
	double dist_father;

	l = graph->nodes[id_parent].begin; // recuperation de la liste d adjacence du node
	perso = l->content;
	dist_father = dij[id_parent].min_dist;
	while (l)
	{
		perso = l->content; // recuperation du node contenant les data
		if (l->runing == 0 || dist_father + graph-> < )
		{
			//distance father and distance de la liaison
			// min_dist + dist_father
			l->runing = 1;
			l->id_antecedent = id_parent;
			l->min_dist = graph->nodes[id_parent]	
		}
		l = l->next;
	}
}
*/
void	init_runing(t_graph *graph, t_dij *dij)
{
	t_linked_list *l;
	t_perso *perso;
	int c;
	int c2;

	c = 0;
	c2 = 0;
	while (c < graph->nb_vertices)
	{
		dij[c].runing = 1;		
		l = graph->nodes[c].begin;
		while (l)
		{
			perso = l->content;
			
			l = l->next;
		}
		c++;
	}
}

int main(void)
{
	t_graph *graph;

	if (!(graph = ft_make_graph(10, true)))
	{
		printf("Echec ...\n");
		return (0);
	}
	// arras   0
	// Nantes 1
	// strasbourg 2
	// brest 3
	// paris 4
	// lyon 5
	// poitiers 6
	// marseille 7
	// bordeaux 8
	// montpellier 9

	// arras - nantes
	add_edge(graph, 0, 1, 561.0); // arras
	// arras - strasbourg
	add_edge(graph, 0, 2, 522.0);
	// arras - paris
	add_edge(graph, 0, 4, 185.0);
	// nantes -brest
	add_edge(graph, 1, 3, 298.0);
	// nantes - paris
        add_edge(graph, 1, 4, 386.0);
	// nantes - bordeaux
	add_edge(graph, 1, 8, 334.0);
	// strasbourg - lyon
	add_edge(graph, 2, 5, 494.0);
	// strasbourg - marseille
	add_edge(graph, 2, 7, 809.0);
	// strasbourg - Montpelier
	add_edge(graph, 2, 9, 797.0);
	// brest - paris
	add_edge(graph, 3, 4, 593.0);
	// paris - poitiers
	add_edge(graph, 4, 6, 338.0);
	// paris - lyon
	add_edge(graph, 4, 5, 465.0);
	// lyon - marseille
        add_edge(graph, 5, 7, 315.0);
	// lyon - montpellier
        add_edge(graph, 5, 9, 303.0);
	// poitiers - bordeaux
	add_edge(graph, 6, 8, 237.0);
	// poitiers - montpelier
        add_edge(graph, 6, 9, 557.0);
	// marseille - montpellier
	add_edge(graph, 7, 9, 171.0);

	ft_display_graph(graph, &read_node_perso);

	ft_destroy_graph(graph, &destroy_node_perso);
}

int main3(void)
{
	t_linked_list *test = 0;

	test = ft_lstcreate_elem(get_node(20, 100));
	ft_lstpush_back(&test, get_node(10, 50));
	ft_lstdisplay(test, &read_node_perso);
	ft_lstdestroy(&test, &destroy_node_perso);
	printf("---> %p\n", test);
	return (0);
}
/*
int main2(void)
{
	int a = 10;
	int b = 5;
	int c = 2;
	t_linked_list *bibitch = 0;
	t_linked_list *tmp = 0;
	
	bibitch = ft_lstcreate_elem(&a);
	ft_lstpush_back(&bibitch, &b);
	ft_lstpush_front(&bibitch, &c);
	
	tmp  = bibitch;
	while (tmp)
	{
		printf("----> %d\n", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
	ft_lstdisplay(bibitch, &read_node);
	return (0);
}
*/
