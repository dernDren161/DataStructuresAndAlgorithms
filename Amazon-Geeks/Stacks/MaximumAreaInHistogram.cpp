// Problem Link: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0#

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll call(ll arr[], ll n){

    // We need to find Nearest Smaller Right and Nearest Smaller Left from 'arr'
    // width = (NSR-NSL-1);
    // area = width * (arr[i])

    vector<ll> vs1; //stores indices
    vector<ll> vs2;

    stack<pair<ll,ll>>st;  // ----------->>>  number, index
    stack<pair<ll,ll>>st2; // same format as above

    // find NSL
    for(ll i=0;i<n;i++){
        if(st.empty()) vs1.push_back(-1);
        else if(st.size()>0 && st.top().first < arr[i]){
            vs1.push_back(st.top().second);
        }else{ // st.top() > arr[i]
            while(st.size()>0 && st.top().first>=arr[i]) st.pop();
            if(st.empty()) vs1.push_back(-1);
            else vs1.push_back(st.top().second);
        }
    st.push({arr[i],i});
    }

     // find NSR
     for(ll i=n-1;i>=0;i--){
        if(st2.empty()) vs2.push_back(n);
        else if(st2.size()>0 && st2.top().first < arr[i]){
            vs2.push_back(st2.top().second);
        }else{ // st.top() > arr[i]
            while(st2.size()>0 && st2.top().first>=arr[i]) st2.pop();
            if(st2.empty()) vs2.push_back(n);
            else vs2.push_back(st2.top().second);
        }
    st2.push({arr[i],i});
    }

    reverse(vs2.begin(),vs2.end());

    // now the highest width can be achieved by: (NSR-NSL-1), and the largest area could be calculated by: (NSR-NSL-1) * arr[i]
    ll m = INT_MIN;

    for(ll i=0;i<n;i++){
        ll temp = vs2[i] - vs1[i] - 1; // we get the width
        ll obsArea = temp * arr[i];
        if(obsArea > m) m = obsArea;
    }

    return m;

}

int main(){
    ll test;
    cin >> test;
    while(test--){
        ll num;
        cin >> num;
        ll arr[num];
        for(ll i=0;i<num;i++){
            cin >> arr[i];
        }

        cout << call(arr,num) << endl;
    }

    return 0;
}
