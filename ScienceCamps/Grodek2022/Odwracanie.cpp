// Treap
#include<bits/stdc++.h>
using namespace std;
 
struct Node {
    Node *l = 0, *r = 0;
    int val, prior, subtree_size = 1;
    bool lazy=0;
    Node(int _val) : val(_val), prior(rand()) {}
    void recalc();
};
 
int subtreeSize(Node* n) { return n ? n->subtree_size : 0;} // useful for calling subtreeSize(null)
void Node::recalc() { subtree_size = subtreeSize(l) + subtreeSize(r) + 1; }

void PushLazy(Node* n)
{
    if(!n)return;
    if(n->lazy)n->lazy=0;
    else n->lazy=1;
}
void PointTurnAround(Node* n)
{
    if(!n)return;
    if(!n->lazy)return;
    swap(n->l,n->r);
    n->lazy=0;
    PushLazy(n->l);
    PushLazy(n->r);
}
 
pair<Node*, Node*> split(Node* n, int k) {
    if (!n) return {}; // nulls are base case for recursion for both split & merge
    PointTurnAround(n);
    if (subtreeSize(n->l) >= k) { // "n->val >= k" for standard set's lower_bound(k) by key
        auto pa = split(n->l, k);
        // Attach subtree
        n->l = pa.second;
        n->recalc();
        return {pa.first, n};
    } else {
        auto pa = split(n->r, k - subtreeSize(n->l) - 1); // and just "k" for set's lower_bound
        // Attach subtree
        n->r = pa.first;
        n->recalc();
        return {n, pa.second};
    }
}
 
Node* merge(Node* l, Node* r){
    if(!l)return r;
    if(!r)return l;
    PointTurnAround(l);
    PointTurnAround(r);
    if(l->prior > r->prior){
        l->r = merge(l->r, r);
        l->recalc();
        return l;
    }else{
        r->l=merge(l,r->l);
        r->recalc();
        return r;
    }
}
 
Node* root=nullptr;
 
Node* newNode(int val){
    return new Node(val);
}
 
void insert(int val, int pos) {
    auto pa = split(root, pos);
    root = merge(merge(pa.first, newNode(val)), pa.second);
}
 
int findKth(Node* n, int k) {
    PointTurnAround(n);
    if (subtreeSize(n->l)+1 == k)
        return n->val;
    if (subtreeSize(n->l) >= k)
        return findKth(n->l, k);
    else
        return findKth(n->r, k - subtreeSize(n->l) - 1);
}

void LazyTurnAround(int p,int k){
    auto segment1=split(root,p-1);
    auto segment2=split(segment1.second,k-p+1);
    PushLazy(segment2.first);
    root=merge(merge(segment1.first,segment2.first),segment2.second);
}
 
void cleanup(Node *n){
    if(n==nullptr) return;
    cleanup(n->l);
    cleanup(n->r);
    delete n;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int wartosc;
        cin>>wartosc;
        insert(wartosc,i);
    }
    while(q--)
    {
        int a,b,c;
        cin>>a;
        if(a){
            cin>>b;
            cout<<findKth(root,b)<<endl;
        }
        else{
            cin>>b>>c;
            LazyTurnAround(b,c);
        }
    }


    cleanup(root); 
}