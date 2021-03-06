#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int one, two;
int arr[1001][1001];
bool isVisited[1001];

void input() {
	cin >> N >> M >> V;
	for (int i = 0;i < M;i++) {
		cin >> one >> two;
		arr[one][two] = 1;
		arr[two][one] = 1;
	}
}

void reset_visit() {
	for (int i = 1;i <= N;i++) {
		isVisited[i] = false;
	}
}

void dfs(int start) {
	cout << start << " ";
	isVisited[start] = true;

	for (int i = 1;i <= N;i++) {
		if (i == start) continue;
		else {
			if (!isVisited[i] && arr[start][i] == 1 && arr[i][start] == 1)
				dfs(i);
		}
	}
}

void bfs(int start) {
	queue<int> q;

	q.push(start);
	isVisited[start] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";

		for (int i = 1;i <= N;i++) {
			if (i == cur) continue;
			else {
				if (!isVisited[i] && arr[cur][i] == 1 && arr[i][cur] == 1) {
					q.push(i);
					isVisited[i] = true;
				}
			}
		}
	}
}

int main() {
	input();
	dfs(V);
	reset_visit();
	cout << "\n";
	bfs(V);
}