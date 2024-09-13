struct node{
    int child[26];
    int ind;
    int suf_link;
    int output_link;
    node(){
        rep(i,0,26) child[i]=-1;
        num=-1;
        ind=-1;
        suf_link=-1;
        output_link=-1;
    }
};
 
void add_to_trie(vector<node> &trie,string s,int index){
    int curr=0;
    for(auto ch:s){
        int c=ch-'a';
        if(trie[curr].child[c]==-1){
            node nn;
            trie[curr].child[c]=trie.size();
            trie.pb(nn);
        }
        curr=trie[curr].child[c];
    }
    trie[curr].ind=index;
}
 
void build_links(vector<node> &trie){
    int curr=0;
    trie[curr].suf_link=0;
    trie[curr].output_link=0;
    queue<int> q;
    for(int i=0;i<26;i++){
        if(trie[curr].child[i]!=-1){
            trie[trie[curr].child[i]].suf_link=0;
            trie[trie[curr].child[i]].output_link=0;
            q.push(trie[curr].child[i]);
        }
    }
 
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(trie[num].child[i]!=-1){
                int cc = trie[num].child[i];
                int tmp = trie[num].suf_link;
                while(trie[tmp].child[i]==-1 && tmp!=0) tmp=trie[tmp].suf_link;
 
                if(trie[tmp].child[i]!=-1) trie[cc].suf_link=trie[tmp].child[i];
                else trie[cc].suf_link=0;
                q.push(cc);
            }
        }
 
        if(trie[trie[num].suf_link].ind>=0) trie[num].output_link=trie[num].suf_link;
        else trie[num].output_link = trie[trie[num].suf_link].output_link;
    }
}
 
void search(vector<node> &trie,string &s,vector<int> pos[]){
    int par=0;
    for(int i=0;i<s.size();i++){
        int c = s[i]-'a';
        if(trie[par].child[c]!=-1){
            par = trie[par].child[c];
            if(trie[par].ind>=0){
                pos[trie[par].ind].pb(i);
            }
            int mol = trie[par].output_link;
            while(mol!=0){
                pos[trie[mol].ind].pb(i);
                mol = trie[mol].output_link;
            }
        }else{
            while(par!=0 && trie[par].child[c]==-1){
                par=trie[par].suf_link;
            }
            if(trie[par].child[c]!=-1) i--;
        }
    }
}


vector<node> trie;
node nn;
trie.pb(nn);
