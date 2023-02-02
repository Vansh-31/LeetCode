// Problem : Number of Good Paths
// Problem Statement : There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

// You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// A good path is a simple path that satisfies the following conditions:

// The starting node and the ending node have the same value.
// All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
// Return the number of distinct good paths.

// Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MOD 1000000007
#define PI 3.14
using namespace std;
class Solution {
public:
    int find(vector<int>& y,int i) {
		if(i==y[i]) return i;
		y[i]=find(y,y[i]);
		return y[i];
	}
	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(),m=edges.size(),ans=0;
		vector<vector<int>> x(n);
		vector<int> y(n);
		for(int i=0;i<n;i++){
			y[i]=i;
			x[i]={vals[i],1};
		}
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
	    	return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
		});
		for(int i=0;i<m;i++){
			int a=find(y,edges[i][0]);
			int b=find(y,edges[i][1]);
			if(x[a][0]!=x[b][0]){
				if(x[a][0]>x[b][0]) y[b]=a;
				else y[a]=b;
			}
			else{
				y[a]=b;
				ans+=x[a][1]*x[b][1];
				x[b][1]+=x[a][1];
			}
		}
		return ans+n;
	}
};
int main()
{
    
    return 0;
}