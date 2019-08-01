#ifndef FT_GRAPHE_H
# define FT_GRAPHE_H

	typedef enum
	{
		false,
		true
	}e_bool;

	typedef struct s_node_list_element
	{
		int value;
		struct s_node_list_element *next;
	} t_node_list;

	/* list d adjacence */
	typedef struct s_adjency_list_element
	{
		t_node_list *begin;
		
	} t_adjency_list;

	/* definition d un graphe */
	typedef struct s_graph_element
	{
		e_bool is_oriented; // graphe oriente
		int nb_vertices; // nombre de sommet
		t_adjency_list *tab_neightbours; 
	} t_graph;

	t_graph *new_graph(int vertices, e_bool is_oriented);
	void	erase_graph(t_graph *graph);

	e_bool is_empty_graph(t_graph *g);

	t_node_list *get_node(int x);
	void		add_edge(t_graph *graph, int src, int dest);

	/* print node */
	void    print_node(t_adjency_list);
	void    print_graph(t_graph *graph);
#endif
