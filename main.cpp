#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
void Sort(map<int,int> &Map) {
    vector<pair<int,int>> v;
    for(auto &it:Map){
        v.push_back(it);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it :v){
        //cout<<it.first<<" ";
    }
}
int flag = 0;
int findMinOps(int arr[], int n){
    int ans = 0;
    for (int i=0,j=n-1; i<=j;){
        if (arr[i] == arr[j]){
            flag++;
            m.insert(pair<int,int>(i,arr[i]));
            m.insert(pair<int,int>(j,arr[j]));
            i++;
            j--;
        }
        else if (arr[i] > arr[j]){
            j--;
            arr[j] += arr[j+1] ;
            ans++;
        }
        else{
            i++;
            arr[i] += arr[i-1];
            ans++;
        }
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    if(n == 1){
        cout<<a[0]<<endl;
        return 0;
    }
    findMinOps(a,n);
    Sort(m);
    if(flag == 0 || m.size() == 1){
        cout<<"*"<<endl;
        return 0;
    }
    map<int,int>::iterator it;
    for(it = m.begin();it != m.end();it++){
        cout<<it->second<<endl;
    }

}