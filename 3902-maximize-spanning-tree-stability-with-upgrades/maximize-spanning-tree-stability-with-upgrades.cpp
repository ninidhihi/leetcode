class Solution {
public:

    struct DSU{
        vector<int> parent, rankv;

        DSU(int n){
            parent.resize(n);
            rankv.resize(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int x){
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        }

        bool unite(int a,int b){
            a=find(a);
            b=find(b);

            if(a==b) return false;

            if(rankv[a] < rankv[b])
                swap(a,b);

            parent[b]=a;

            if(rankv[a]==rankv[b])
                rankv[a]++;

            return true;
        }
    };

    bool can(int n, vector<vector<int>>& edges, int k, long long x){

        DSU dsu(n);
        int used=0;
        int upgrades=0;

        vector<pair<int,int>> normal;
        vector<pair<int,int>> upgrade;

        for(auto &e:edges){

            int u=e[0], v=e[1];
            long long s=e[2];
            int must=e[3];

            if(must==1){

                if(s < x) return false;

                if(!dsu.unite(u,v))
                    return false;

                used++;
            }
            else{

                if(s >= x)
                    normal.push_back({u,v});

                else if(2*s >= x)
                    upgrade.push_back({u,v});
            }
        }

        for(auto &p:normal){
            if(dsu.unite(p.first,p.second))
                used++;
        }

        for(auto &p:upgrade){

            if(used == n-1) break;

            if(dsu.unite(p.first,p.second)){
                upgrades++;
                used++;
            }
        }

        if(used != n-1) return false;

        return upgrades <= k;
    }


    int maxStability(int n, vector<vector<int>>& edges, int k) {

        long long lo=1, hi=0;

        for(auto &e:edges)
            hi=max(hi,(long long)e[2]*2);

        long long ans=-1;

        while(lo<=hi){

            long long mid=(lo+hi)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }

        return ans;
    }
};