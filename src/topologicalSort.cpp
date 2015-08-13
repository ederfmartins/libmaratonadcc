bool topologicalSort(vector< vector< int > > &g, vector< int > &r)
{
	vector< int > deg(g.size());
	FOREACH(node, g){
		FOREACH(ngb, *node){
			deg[*ngb]++;
		}
	}

	priority_queue< int, vector< int >, greater< int > > q;
	FORN(i, 0, g.size())
		if(0 == deg[i]) q.push(i);

	while(not q.empty()){
		int node = q.top();
		q.pop();
		r.push_back(node);
		FOREACH(ngb, g[node]){
			if(--deg[*ngb] == 0) q.push(*ngb);
		}
	}

	return r.size() == g.size();
}
