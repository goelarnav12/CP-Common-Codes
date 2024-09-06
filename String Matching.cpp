vector<int> z_fun(string s){
    int n = s.size();
    vector<int> z(n);
    z[0]=0;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        z[i]=0;
        if(i<r) z[i]=min(z[i-l],r-i);
        while(i+z[i]<n && s[z[i]]==s[z[i]+i]) z[i]++;
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

vector<int> pref_fun(string s){
    int n=s.size();
    vector<int> pi(n);
    pi[0]=0;
    for(int i=1;i<n;i++){
        int l=pi[i-1];
        while(l>0 && s[i]!=s[l]) l=pi[l-1];
        if(s[i]==s[l]) l++;
        pi[i]=l;
    }
    return pi;
}
