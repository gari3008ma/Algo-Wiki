

void solution(int n, int m)
{
	int i, j, u, v, b, a,w;
	for(int i = 0; i <= n; i++){
		G[i].clear();
		d[i] = INF;
		e[i] = 0;
	}
	while(m--){
		scanf("%d %d", &u, &v,&w);
		G[u].push_back(pii(w, v));
		G[v].push_back(pii(w, u));
	}
	d[1] = 0;
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	Q.push(pii(0, 1));

	while(!Q.empty()) {
		u = Q.top().second;
		b = Q.top().first;
		Q.pop();
		int size = G[u].size();
		for(i = 0; i < size; i++){
			v = G[u][i].second;
			a = G[u][i].first;
			if(e[v] == 0 && b + a <= d[v]) {
				d[v] = b+a;
				Q.push(pii(d[v], v));
			}
		}
		e[u] = 1;
		if(u == n) break;
	}
	printf("%d\n", d[n]);
}
