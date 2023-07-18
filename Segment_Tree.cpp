// Use Like This

// int a[]={1,2,3,4,5,6,7,8,9,10};
// int n=10;
// int tree[4*n+1];
// build(tree,a,1,0,n-1);
// cout<<query(tree,1,0,n-1,1,6)<<endl;

int combine(int a, int b)
{
    return a+b; // change this acc to question
}
void build(int tree[], int a[], int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(tree, a, 2 * node, st, mid);
    build(tree, a, 2 * node + 1, mid + 1, en);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}
int query(int tree[], int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        return 0;
    }
    if (st >= l && en <= r)
    {
        return tree[node];
    }
    int mid = (st + en) / 2;
    int q1 = query(tree, 2 * node, st, mid, l, r);
    int q2 = query(tree, 2 * node + 1, mid + 1, en, l, r);
    return combine(q1, q2);
}
// changes only in segment tree not in actual array
void update(int tree[], int a[], int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        tree[node] = val;
        return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid)
    {
        update(tree, a, 2 * node, st, mid, idx, val);
    }
    else
    {
        update(tree, a, 2 * node + 1, mid + 1, en, idx, val);
    }
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

