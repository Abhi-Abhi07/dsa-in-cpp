#include<iostream>
#include<vector>

using namespace std;
void segmentTree(int ind,int s,int e,int *arr,vector<int>&seg_tree){
    if(s==e){
        seg_tree[ind]=arr[s];
        return;
    }

    int mid=(s+e)/2;
    segmentTree(ind*2+1,s,mid,arr,seg_tree);
    segmentTree(ind*2+2,mid+1,e,arr,seg_tree);
    
    seg_tree[ind] = max(seg_tree[ind*2+1],seg_tree[ind*2+2]);

}

int segmentQuery(int ind,int s,int e,int *arr,vector<int>&seg_tree,int l,int r){
    if(s>r || e<l)  return 0;
    if(s>=l && e<=r)    return seg_tree[ind];

    int mid = (s+e)/2;
    int a = segmentQuery(ind*2+1,s,mid,arr,seg_tree,l,r);
    int b = segmentQuery(ind*2+2,mid+1,e,arr,seg_tree,l,r);
    return max(a,b);
}
int main(){
    int arr[]={8,2,5,1,4,5,3,9,6,10};
    int n=sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    vector<int>seg_tree(4*n,0);
    segmentTree(0,0,n-1,arr,seg_tree);

    // for(int s: seg_tree) cout<<s<<" ";

    cout<<segmentQuery(0,0,n-1,arr,seg_tree,2,6)<<endl;
    cout<<endl;
    return 0;
}