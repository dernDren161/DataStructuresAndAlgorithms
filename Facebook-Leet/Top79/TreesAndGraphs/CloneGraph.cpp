// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/277

class Solution {

    // Steps
    // Clone just the values
    // Push all the connected nodes for the given node into the vector(recursively)
    // assign the neighbours for a given node with their exact neighbours

    Node* callDFS(Node* n,map<Node*,Node*> &m){

        if(n==NULL) return NULL;

        if(m[n] == NULL){ // extremely important condition
            Node* temp = new Node(n->val);
            m[n] = temp;

            vector<Node*> vs;
            for(auto x: n->neighbors){
                vs.push_back(callDFS(x,m));
            }
            temp ->neighbors = vs;
        }
        return m[n];

    }

public:
    Node* cloneGraph(Node* node) {

        if(node == NULL) return NULL;

        map<Node*,Node*>m;

        return callDFS(node,m);

    }
};
