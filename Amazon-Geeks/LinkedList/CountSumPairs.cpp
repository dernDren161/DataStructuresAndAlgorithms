// Problem Link: https://practice.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1

int countPairs(struct Node* head1, struct Node* head2, int x) {

    map<int,int> m;

    while(head1 != NULL){
        m[head1 -> data] = 1;
        head1 = head1 -> next;
    }

    int answer = 0;

    while(head2 != NULL){

        if(m.find(x - head2 -> data) != m.end()) answer++;
        head2 = head2 -> next;
    }

    return answer;
}
