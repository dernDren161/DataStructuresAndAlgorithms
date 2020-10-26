// Problem Link: https://practice.geeksforgeeks.org/problems/next-larger-element/0
// This problem, also known as: Nearest Greater to right

// This same variation is used for:
// Nearest greater to left.
// Nearest smaller to right.
// Nearest smaller to left.

// NSR = (change of 'for' loop from) NSL

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> call(ll arr[], ll num){

        vector<ll>vs;
        stack<ll>st;

        for(ll i=num-1;i>=0;i--){
            if(st.empty()) vs.push_back(-1);

            else if(st.size()>0 && st.top()>arr[i]){
                vs.push_back(st.top());
            }else if(st.size()>0 && st.top()<=arr[i]){
                while(st.size()>0 && st.top()<=arr[i]){
                    st.pop();
                }
                if(st.empty()) vs.push_back(-1);
                else vs.push_back(st.top());
            }

            st.push(arr[i]);
        }

        return vs;
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
        vector<ll> vs;
        vs = call(arr,num);
        ll s = vs.size();
        reverse(vs.begin(),vs.end());
        for(ll i=0;i<s;i++){
            cout << vs[i] << " ";
        }
        cout << endl;
    }
}
