//// vscnm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
#include "pch.h"
//using namespace std;
//
//int **f;
//int **c;
//int **cf;
//int *visited;
//int v;
//int e;
//vector<int> path;
//ifstream infile;
//
//bool bfs();
//void renewCF();
//
//bool bfs() {
//	int i;
//	int *parent = new int[v];
//	for (i = 0; i < v; i++) {
//		visited[i] = false;
//		parent[i] = i;
//	}
//	queue<int> q;
//	q.push(0);
//	visited[0] = true;
//	int t;
//	while (!q.empty()) {
//		t = q.front();
//		q.pop();
//		for (i = 1; i < v; i++) {
//			if(cf[t][i] > 0)
//				if (!visited[i]) {
//					parent[i] = t;
//					if (i == v - 1) {
//						while (parent[i] != i) {
//							path.push_back(i);
//							i = parent[i];
//						}
//						path.push_back(i);
//						/*cout << "找到增广路经：";
//						int l = path.size();
//						for (i = l - 1; i > 0; i--)
//							cout << path.at(i) << " -> ";
//						cout << path.at(0) << endl;*/
//						return true;
//					}
//					visited[i] = true;
//					q.push(i);
//				}
//		}
//	}
//	return false;
//}
//void renewCF()
//{
//	for (int i = 0; i < v; i++) {
//		for (int j = 0; j < v; j++) {
//			if (c[i][j] > 0)
//				cf[i][j] = c[i][j] - f[i][j];
//			else if (c[j][i] > 0)
//				cf[i][j] = f[j][i];
//			else
//				cf[i][j] = 0;
//		}
//	}
//}
//int main() {
//	infile.open("C:\\Users\\叶学谦\\Desktop\\算法\\roadNet-CA.txt");
//	infile >> v;
//	cout << "点数量为：" << v << endl;
//	infile >> e;
//	cout << "边数量为：" << e << endl;
//	visited = new int[v];
//	c = new int*[v];
//	f = new int*[v];
//	cf = new int*[v];
//	int i;
//	for (i = 0; i < v; i++) {
//		c[i] = new int[v];
//		f[i] = new int[v];
//		cf[i] = new int[v];
//		for (int j = 0; j < v; j++) {
//			c[i][j] = 0;
//			f[i][j] = 0;
//			cf[i][j] = 0;
//		}
//	}
//	int u1, v1, val;
//	srand((int)time(0));
//	cout << "读取边中..." << endl;
//	for (i = 0; i < e; i++) {
//		cout << i << endl;
//		infile >> u1 >> v1;
//		val = rand();
//		cout << val << endl;
//		c[u1][v1] += val;
//		cf[u1][v1] += val;
//		cin >> u1;
//	}
//	infile.close();
//	cout << "读取完毕" << endl;
//	int result = 0;
//	while (bfs()) {
//		int min = INT32_MAX;
//		int l = path.size(), ut, vt;
//		for (i = l - 1; i > 0; i--) {
//			ut = path.at(i);
//			vt = path.at(i - 1);
//			if (min > cf[ut][vt]) {
//				min = cf[ut][vt];
//			}
//		}
//		for (i = l - 1; i > 0; i--) {
//			ut = path.at(i);
//			vt = path.at(i - 1);
//			if (c[ut][vt] > 0)
//				f[ut][vt] += min;
//			else
//				f[vt][ut] -= min;
//		}
//		path.clear();
//		//cout << "当前流为:" << min << endl << endl;
//		renewCF();
//		result += min;
//	}
//	//cout << "最大流为：" << result << endl;
//	return 0;
//}
//
////acm测试
////int main() {
////	//infile.open("C:\\Users\\叶学谦\\Desktop\\算法\\roadNet-CA.txt");
////	//infile >> v;
////	//cout << "点数量为：" << v << endl;
////	//infile >> e;
////	//cout << "边数量为：" << e << endl;
////	int num;
////	cin >> num;
////	for (int lp = 1; lp <= num; lp++) {
////		cin >> v >> e;
////		visited = new int[v];
////		c = new int*[v];
////		f = new int*[v];
////		cf = new int*[v];
////		int i;
////		for (i = 0; i < v; i++) {
////			c[i] = new int[v];
////			f[i] = new int[v];
////			cf[i] = new int[v];
////			for (int j = 0; j < v; j++) {
////				c[i][j] = 0;
////				f[i][j] = 0;
////				cf[i][j] = 0;
////			}
////		}
////		int u1, v1, val;
////		//srand((int)time(0));
////		//cout << "读取边中..." << endl;
////		for (i = 0; i < e; i++) {
////			cin >> u1 >> v1 >> val;
////			u1--;
////			v1--;
////			c[u1][v1] += val;
////			cf[u1][v1] += val;
////		}
////		//infile.close();
////		//cout << "读取完毕" << endl;
////		int result = 0;
////		while (bfs()) {
////			int min = INT32_MAX;
////			int l = path.size(), u, v, ut, vt;
////			for (i = l - 1; i > 0; i--) {
////				ut = path.at(i);
////				vt = path.at(i - 1);
////				if (min > cf[ut][vt]) {
////					u = ut;
////					v = vt;
////					min = cf[ut][vt];
////				}
////			}
////			for (i = l - 1; i > 0; i--) {
////				ut = path.at(i);
////				vt = path.at(i - 1);
////				if (c[ut][vt] > 0)
////					f[ut][vt] += min;
////				else
////					f[vt][ut] -= min;
////			}
////			path.clear();
////			//cout << "当前流为:" << min << endl << endl;
////			renewCF();
////			result += min;
////		}
////		//cout << "最大流为：" << result << endl;
////		cout << "Case " << lp << ": " << result << endl;
////	}
////	return 0;
////}
//
//
//// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
//// 调试程序: F5 或调试 >“开始调试”菜单
//
//// 入门提示: 
////   1. 使用解决方案资源管理器窗口添加/管理文件
////   2. 使用团队资源管理器窗口连接到源代码管理
////   3. 使用输出窗口查看生成输出和其他消息
////   4. 使用错误列表窗口查看错误
////   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
////   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
