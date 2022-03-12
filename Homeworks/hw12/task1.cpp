/*#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int maxN = 1000000;
int N, M, Q;
pair<int, int> edgeList[maxN];
int parent[maxN];

void init() {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
}

int Find(int v) {
    if (v == parent[v])
        return v;
    return  parent[v]= Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) 
        parent[b] = a;
}

int kruskal_find_path(int from, int to) {
    if (Find(from) != Find(to)) 
        return 0;
    else 
        return 1;
}

int main() {
	cin >> N >> M;
    init();
    for(int i =0;i < M;i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        Union(temp1, temp2);
        edgeList[i] = { temp1,temp2 };
    }
    

    cin >> Q;
    vector<int> ans;
    for (int i = 0; i < Q; i++) {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        if (temp1 == 1) {
            ans.push_back(kruskal_find_path(temp2, temp3));
        }
        else if(temp1 == 2) {
            Union(temp2, temp3);
        }
    }

    for (auto x : ans) {
        cout << x;
    }

	return 0;
}*/