// Problem Link:
//https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1/?track=amazon-arrays&batchId=192

vector<int> duplicates(int a[], int n) {

    int i = 0;
    int j = 1;

    vector<int> vs;
    vs.clear();
    sort(a,a+n);
    while(j<n){
        if(a[i] == a[j]){
            vs.push_back(a[i]);
            while(a[i] == a[j]) {
                i++;
                j++;
            }
        }  else if(a[i] != a[j]){
            i++;
            j++;
        }
    }

    if(vs.empty()) vs.push_back(-1);

    return vs;
}
