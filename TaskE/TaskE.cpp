#ifdef TASKE

#include <deque>
#include "Library.h"

struct Edge{
	int u, v, w, c;
};

void task()
{
	int n, m;
	read(n, m);

	vector<Edge> edges(m+1);
	REP(i, m) {
		edges[i].c = 0;
		read(edges[i].u, edges[i].v, edges[i].w);		
	}
	sort(edges.begin(), edges.end(), [](const Edge& x, const Edge& y) {return x.u < y.u || x.u==y.u && x.w > y.w; });

	vector<pair<int, int>> weights(m);
	REP(i, m) {
		weights[i - 1].first = edges[i].w;
		weights[i - 1].second = i;
	}
	sort(weights.begin(), weights.end(), [](const auto& x, const auto& y) { return x.first > y.first; });
		
	vector<int> ref(n + 1); 
	REP(i, m) {
		int u = edges[i].u; // u->v
		if (ref[u] != 0) continue;
		ref[u] = i;
	}
		
	deque<int> queue;
	int cost = 0;

	vector<int> costs(n + 1);
	vector<int> vertex(n + 1);

	int x = 0;
	for (const auto& pair : weights) {
		const int i = pair.second;
		if (edges[i].c > 0) continue;

		int maxC = costs[edges[i].v];
		int startEdge = max(ref[edges[i].v], vertex[edges[i].v]);
		if (startEdge) {
			for (int j = startEdge; j <= m && edges[j].u == edges[i].v && edges[j].w > edges[i].w; j++)
			{
				maxC = max(maxC, edges[j].c);
				vertex[edges[i].v] = j + 1;
				costs[edges[i].v] = maxC;
			}
		}

		edges[i].c = maxC + 1;
		cost = max(edges[i].c, cost);
	}

	write(cost);
}

#endif