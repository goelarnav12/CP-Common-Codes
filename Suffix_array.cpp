void radix_sort(vector<pair<pair<int,int>,int> > &a){
    int n=a.size();
    {
        vector<int> cnt(n);
        for(int i=0;i<n;i++){
            pair<pair<int,int>,int> x=a[i];
            cnt[x.ff.ss]++;
        }
        vector<pair<pair<int,int>,int> > a_new(n);
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++){
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(int i=0;i<n;i++){
            pair<pair<int,int>,int> x=a[i];
            int j=x.ff.ss;
            a_new[pos[j]]=x;
            pos[j]++;
        }
        a=a_new;
    }
    {
        vector<int> cnt(n);
        for(int i=0;i<n;i++){
            pair<pair<int,int>,int> x=a[i];
            cnt[x.ff.ff]++;
        }
        vector<pair<pair<int,int>,int> > a_new(n);
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++){
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(int i=0;i<n;i++){
            pair<pair<int,int>,int> x=a[i];
            int j=x.ff.ff;
            a_new[pos[j]]=x;
            pos[j]++;
        }
        a=a_new;
    }
}

void solve(int tc){
    string s;
    cin>>s;
    s+='$';
    int n=s.size();
    int p[n],c[n];
    {
        // k=0
        vector<pair<char,int> > a(n);
        for(int i=0;i<n;i++) a[i]=mp(s[i],i);
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++) p[i]=a[i].ss;
        c[p[0]]=0;
        for(int i=1;i<n;i++){
            if(a[i].ff==a[i-1].ff) c[p[i]]=c[p[i-1]];
            else c[p[i]]=c[p[i-1]]+1;
        }
    }
    int k=0;
    while((1<<k)<n){
        // k->k+1
        vector<pair<pair<int,int>,int> > a(n);
        for(int i=0;i<n;i++) a[i]=mp(mp(c[i],c[(i+(1<<k))%n]),i);
        radix_sort(a);
        for(int i=0;i<n;i++) p[i]=a[i].ss;
        c[p[0]]=0;
        for(int i=1;i<n;i++){
            if(a[i].ff==a[i-1].ff) c[p[i]]=c[p[i-1]];
            else c[p[i]]=c[p[i-1]]+1;
        }
        k++;
    }
    for(int i=0;i<n;i++) cout<<p[i]<<" ";
    cout<<endl;
    // for(int i=0;i<n;i++) cout<<s.substr(p[i],n-p[i])<<endl;
    // cout<<endl;
    int lcp[n];
    // lcp[0]=0;
    k=0;
    for(int i=0;i<n-1;i++){
        int pi=c[i];
        int j=p[pi-1];
        while(s[i+k]==s[j+k]) k++;
        lcp[pi]=k;
        k=max(k-1,0ll);
    }
    for(int i=1;i<n;i++) cout<<lcp[i]<<" ";
}
