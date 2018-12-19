#include "pch.h"
using namespace std;

typedef struct {
	int v;//终点
	int c;//容量
	int f;//流
}edge;
int *visited;
int v;
int e;
vector<edge> *graph;
vector<int> path;
ifstream infile;

bool bfs();

//void debug() {
//	for (int i = 0; i < v; i++) {
//		int l = graph[i].size();
//		for (int j = 0; j < l; j++)
//			cout << graph[i].at(j).u << " + " << graph[i].at(j).v << " + " << graph[i].at(j).f << " + " << graph[i].at(j).c << endl;
//	}
//
//}

bool bfs() {
	int i;
	int *parent = new int[v];
	for (i = 0; i < v; i++) {
		visited[i] = false;
		parent[i] = i;
	}
	queue<int> q;
	q.push(0);
	visited[0] = true;
	int t;
	edge temp;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		int l = graph[t].size();
		for (i = 0; i < l; i++) {
			temp = graph[t].at(i);
			if (!visited[temp.v]) {
				parent[temp.v] = t;
				if (temp.v == v - 1) {
					i = v - 1;
					while (parent[i] != i) {
						path.push_back(i);
						i = parent[i];
					}
					path.push_back(i);
					cout << "找到增广路经：";
					l = path.size();
					for (i = l - 1; i > 0; i--)
						cout << path.at(i) << " -> ";
					cout << path.at(0) << endl;
					return true;
				}
				visited[temp.v] = true;
				q.push(temp.v);
			}
		}		
	}
	return false;
}

edge* finde(int ut, int vt) {
	int l = graph[ut].size();
	for (int i = 0; i < l; i++)
		if (graph[ut].at(i).v == vt)
			return &graph[ut].at(i);
	return nullptr;
}
vector<edge>::iterator findx(vector<edge> &ut, int vt) {
	vector<edge>::iterator it;
	for (it = ut.begin(); it != ut.end(); it++)
		if (it->v == vt) {
			return it;
		}
	return ut.end();
}

int main() {
	infile.open("C:\\Users\\叶学谦\\Desktop\\算法\\roadNet-CA.txt");
	//infile.open("C:\\Users\\叶学谦\\Desktop\\算法\\123.txt");
	infile >> v >> e;
	cout << "point:" << v << endl;
	cout << "edge:" << e << endl;
	//int num;
	//cin >> num;
	//int shit = 0;
	//while (shit++ < num) {
		//cin >> v >> e;
	visited = new int[v];
	graph = new vector<edge>[v];
	edge *edges = new edge[e];
	int i;
	//srand((int)time(0));
	for (i = 0; i < e; i++) {
		edges[i].f = 0;
		edges[i].c = 0;
	}
	for (i = 0; i < e; i++) {
		/*int u1, v1, c1;
		cin >> u1 >> v1 >> c1;
		edges[i].u = u1-1;
		edges[i].v = v1-1;
		edges[i].c += c1;*/
		int ut;
		infile >> ut >> edges[i].v >> edges[i].c;
		//edges[i].c = rand();
		vector<edge>::iterator it = findx(graph[ut], edges[i].v);
		if (it != graph[ut].end())
			it->c += edges[i].c;
		else
			graph[ut].push_back(edges[i]);
	}
	LARGE_INTEGER s, e, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&s);
	int result = 0;
	while (bfs()) {
		int min = INT32_MAX;
		int l = path.size(), ut, vt;
		vector<edge>::iterator it1;
		vector<edge>::iterator it2;
		for (i = l - 1; i > 0; i--) {
			ut = path.at(i);
			vt = path.at(i - 1);
			it1 = findx(graph[ut], vt);
			int cf = it1->c - it1->f;
			min = min < cf ? min : cf;
		}
		for (i = l - 1; i > 0; i--) {
			ut = path.at(i);
			vt = path.at(i - 1);
			it1 = findx(graph[ut], vt);
			it2 = findx(graph[vt], ut);
			if (it2 == graph[vt].end()) {
				edge nedge;
				nedge.v = ut;
				nedge.c = it1->c;
				nedge.f = it1->c;
				graph[vt].push_back(nedge);
				it2 = graph[vt].end() - 1;
			}
			if ((it1->c - it1->f) >= min) {
				it1->f += min;
				if (it1->f == it1->c) {
					graph[ut].erase(it1, it1 + 1);
				}
				it2->f -= min;
			}
			else {
				it1->f -= min;
				if (it1->f == 0) {
					graph[vt].erase(it2, it2 + 1);
				}
				it2->f += min;
			}
		}
		path.clear();
		result += min;
		cout << min << endl;
	}
	cout << "最大流：" << result << endl;
	QueryPerformanceCounter(&e);
	cout << "time:" << (double)(e.QuadPart - s.QuadPart) * 1000 / fre.QuadPart << "ms" << endl;
	/*	cout << "Case "<<shit<<": " << result << endl;
	}*/
	return 0;
}