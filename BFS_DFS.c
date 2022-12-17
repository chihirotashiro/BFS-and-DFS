#include <stdio.h>
#include <malloc.h>
int totaldist;
struct node
{
	int distance;
	int vertex;
	struct node* next;
};

struct node* gnode;
void displayGraph(struct node* adj[], int no_of_nodes);
void deleteGraph(struct node* adj[], int no_of_nodes);
void createGraph(struct node* adj[], int no_of_nodes);


//This algorithm only showing if you start at one node, what other nodes can you visit
int dfs(struct node* adj[], int start, int visited_org[], int end)
{ totaldist=0;
	int found = 0;
	visited_org[start] = 1;

	struct node* ptr;//Each recursive call has a new copy
	ptr = adj[start];
	while (ptr != NULL)
	{
		if (visited_org[ptr->vertex] == -5)
		{
			if (ptr->vertex == end) {
				
				totaldist = totaldist + ptr->distance;
				printf("<= %d", start);
        
				return 1;
			}
			found = dfs(adj, ptr->vertex, visited_org, end);

		}
		
		if (found == 1)//If the value was found previously, accumulate rest of the values
		{
			totaldist = totaldist + ptr->distance;
			printf(" <= %d", start);
			return 1;
		}
		ptr = ptr->next;

	}

	return found;
}

int main()
{
	struct node* Adj[10];//similar to head pointer

	int i, no_of_nodes, found;
	//clrscr();
	printf("\nEnter the number of nodes in G: ");
	scanf("%d", &no_of_nodes);
	for (i = 0; i < no_of_nodes; i++)
		Adj[i] = NULL;
	createGraph(Adj, no_of_nodes);
	printf("\nThe graph is: ");
	displayGraph(Adj, no_of_nodes);

	int visited_org[10];//In this array, -1 indicate the starting node. -5 indicate that this node hasn't been visited. All other numbers indicate the origin node.

	while (1 == 1)
	{
		for (int k = 0; k < 10; k++)
		{
			visited_org[k] = -5;//To denote we hadn't visited this location yet
		}

		int start, end;
		printf("\n\nStarting node: ");
		scanf("%d", &start);
		printf("Ending node: ");//
		scanf("%d", &end);
	
		printf("%d", end);
		found=dfs(Adj, start, visited_org, end);
    if (found == 0)
			printf("No Path found"); 
    
    if(found==1)
		printf("\nTotal distance: %d", totaldist);
	}


	return 0;
}


void createGraph(struct node* Adj[], int no_of_nodes)
{
	struct node* new_node, * last;
	int i, j, n, val, distance;
	for (i = 0; i < no_of_nodes; i++)
	{
		last = NULL;
		printf("\nEnter the number of neighbours of vertex %d: ", i);
		scanf("%d", &n);
		for (j = 1; j <= n; j++)
		{
			printf(" Enter the neighbour %d of vertex %d: ", j, i);
			scanf("%d", &val);
			printf("Enter their distance: ");
			scanf("%d", &distance);
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node->vertex = val;
			new_node->distance = distance;
			new_node->next = NULL;
			if (Adj[i] == NULL)
				Adj[i] = new_node;
			else
				last->next = new_node;
			last = new_node;
		}

	}
}
void displayGraph(struct node* Adj[], int no_of_nodes)
{
	struct node* ptr;
	int i;
	for (i = 0; i < no_of_nodes; i++)
	{
		ptr = Adj[i];
		printf("\n The neighbours of vertex %d are:", i);
		while (ptr != NULL)
		{
			printf("   %d,%d\t", ptr->vertex, ptr->distance);
			ptr = ptr->next;
		}
	}
}

