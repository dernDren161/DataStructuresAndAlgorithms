// Problem Link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung

class Solution
{
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n)
    {
       int i,j,x,y;
    i = 0;
    j = 0;
    x = 0;
    y = 0;

    while(i<n && j<n){
        x = i+1;
        y = j+1;

            while(x<n && y<n){
                swap(matrix[x][i],matrix[j][y]);
                x++; y++;
            }
        i++;
        j++;
    }

    int a,b;
    a = 0;
    b = n-1;

    while(a<=b){
        for(int i=0;i<n;i++){
            swap(matrix[a][i],matrix[b][i]);
        }
        a++;b--;
    }
    }
};
