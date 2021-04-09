#include <iostream>
#include <string>
using namespace std;

// Trie supports lowercase English characters `a – z`.
// So, the character size is 26.
#define CHAR_SIZE 26

// Data structure to store a Trie node
struct Trie
{
    string key;        // set when the node is a leaf node
    Trie* character[CHAR_SIZE];

    // Constructor
    Trie()
    {
        for (int i = 0; i < CHAR_SIZE; i++) {
            character[i] = nullptr;
        }
    }
};

// Iterative function to insert a string into a Trie
void insert(Trie* &head, string const &str)
{
    // start from the root node
    Trie* curr = head;

    for (char ch: str)
    {
        // create a new node if the path doesn't exist
        if (curr->character[ch - 'a'] == nullptr) {
            curr->character[ch - 'a'] = new Trie();
        }

        // go to the next node
        curr = curr->character[ch - 'a'];
    }

    // store key in the leaf node
    curr->key = str;
}

// Function to perform preorder traversal on a given Trie
bool preorder(Trie* const curr, Trie const *root)
{
    // return if Trie is empty
    if (curr == nullptr) {
        return false;
    }

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (curr->character[i] != nullptr)
        {
            // if the current node is a leaf, print the key
            if (curr->character[i]->key.length() > 0) {
                cout << curr->character[i]->key << endl;
            }

            preorder(curr->character[i], root);
        }
    }
}

int main()
{
    Trie* head = new Trie();

    // given set of keys
    string dict[] =
    {
        "lexicographic", "sorting", "of", "a", "set", "of", "keys", "can",
        "be", "accomplished", "with", "a", "simple", "trie", "based",
        "algorithm", "we", "insert", "all", "keys", "in", "a", "trie",
        "output", "all", "keys", "in", "the", "trie", "by", "means", "of",
        "preorder", "traversal", "which", "results", "in", "output", "that",
        "is", "in", "lexicographically", "increasing", "order", "preorder",
        "traversal", "is", "a", "kind", "of", "depth", "first", "traversal"
    };

    // insert all keys of a dictionary into a Trie
    for (string word: dict) {
        insert(head, word);
    }

    // print keys in lexicographic order
    preorder(head, head);

    return 0;
}
