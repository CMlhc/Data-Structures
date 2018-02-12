void DFS(MGraph Graph, Vertex V, void(*Visit)(Vertex))
{
	
	Visit(V);
	Visited[V] = true;
	
	for (int j = 0; j < Graph->Nv; ++j)
	{
		if (Graph->G[V][j] == 1 && !Visited[j])
		{
			DFS(Graph, j, Visit);
		}
	}

}
