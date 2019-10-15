
//Code By: pratibha_899 (Pratibha Shrivastav)

/********   All Required Header Files ********/
#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

//All the Loops and defines required
typedef long long int ll;
#define FOR(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (ll i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

//All the declarations using typedef

typedef pair<ll, ll> PII;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<ll, ll> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int l;
typedef unsigned long int ul;
typedef unsigned long long int  ull;

ll dist[3005];
bool flag[3005];
VII adj[3005];

void init(ll n){
    FOR(i, 1, n+1, 1){
        dist[i]=MOD;
        adj[i].clear();
        flag[i]=false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        init(n);
        ll x,y,l;
        FOR(i, 0, m, 1){
            cin>>x>>y>>l;
            adj[x].PB({l,y});
            adj[y].PB({l,x});
        }
        ll source;
        cin>>source;
        dist[source]=0;
        priority_queue<PII> pq;
        pq.push({0,source});
        pair <ll, ll> u,v;
        ll ele;
        while(!pq.empty()){
            u = pq.top();
            pq.pop();
            ele = u.second;
            FOR(i, 0, adj[ele].size(), 1){
                v = adj[ele].at(i);
                if(dist[v.second]>dist[ele]+v.first){
                    dist[v.second]=dist[ele]+v.first;
                    pq.push({dist[v.second],v.second});
                }
            }
        }
        FOR(i, 1, n+1, 1){
            if(dist[i]==0)
                continue;
            else if(dist[i]==MOD)
                cout<<"-1 ";
            else
            {
                cout<<dist[i]<<" ";
            }
            
        }
        cout<<"\n";
    }
    return 0;
}