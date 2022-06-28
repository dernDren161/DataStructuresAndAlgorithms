// Problem Link: https://www.geeksforgeeks.org/program-count-numbers-fingers/

int count_num_finger(int n)
{
    int r = n % 8;
    if (r == 0)
        return 2;
    if (r < 5)
        return r;
    else
        return 10 - r;
}


int main()
{
    int n;
    n = 30;
    cout << count_num_finger(n);

    return 0;
}
