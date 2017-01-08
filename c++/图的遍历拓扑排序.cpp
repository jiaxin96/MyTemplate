void BFS(int num) {
	queue<int> q;
	q.push(num);
	while (!allVisited()) {
		while(q.size()) {
			int f = q.front();
			cout << point[f].getData();
			visited[f] = 1;
			q.pop();
			for (int i = 0; i < order; ++i) {
				if (!visited[i] && matrix[f][i]) {
					visited[i] = 1;
					q.push(i);
				}
			}
		}
		for (int i = 0; i < order; ++i) {
			if (visited[i] == false) q.push(i);
		}
	}
}
void DFS(vector< set<int, greater<int> > > &mm, vector<int> & visit, int num, list<int> & ans) {
	for (set<int, greater<int> >::iterator it = mm[num].begin(); it != mm[num].end(); it++)
	{
		if (!visit[*it]) {
			visit[*it]++;
			DFS(mm, visit, *it, ans);
		}
	}
	ans.push_front(num);
}