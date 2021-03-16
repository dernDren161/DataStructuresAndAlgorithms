// Problem Link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/?company[]=Amazon&problemStatus=unsolved&page=1&query=company[]AmazonproblemStatusunsolvedpage1

void rotate(vector<vector<int> >& matrix)
{
    // first finding the transpose of the matrix
    int x = 0;
    int y = 0;
    int n = matrix.size();

    while(x < n && y < n){
        int i = x + 1;
        int j = y + 1;
        while(i<n && j<n){
            swap(matrix[x][i],matrix[j][y]);
            i++;
            j++;
        }
        x++;
        y++;
    }

    int l=0;
    int r=n-1;
    while(l<r){
        int i = 0;
        while(i<n){
            swap(matrix[l][i],matrix[r][i]);
            i++;      
        }
        l++;
        r--;
    }
}
