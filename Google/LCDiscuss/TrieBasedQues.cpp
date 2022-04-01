// Problem Link: https://leetcode.com/discuss/interview-question/1521932/Google-Onsite

public class Main {
public static void main(String[] args) {
     int[][] bottom = {{1,2,3,4}, {3,4,2,5}, {1,2,4,1}};
     int[][] top = {{3,4,2,5}, {1,2,4,1}, {1,5,7,8}, {7,5,7,3}};
    // int[][] bottom = {{1,4,2,5}, {3,4,2,5}, {1,4,2,5},  {3,4,2,5}};
    // int[][] top = {{1,4,2,5}, {3,4,2,5}, {1,4,2,5},{3,4,2,5}, {7,5,7,3}};
    // int[][] top = {{1,4,2,5}, {3,4,2,5}};
    System.out.println(findNoOfOverlappingParts(bottom, top));
}

private static int findNoOfOverlappingParts(int[][] bottom, int[][] top){
    if(bottom.length==0||bottom[0].length==0||top.length==0||top[0].length==0){
        return 0;
    }
    Trie trie = new Trie();
    for(int i=0;i<bottom.length;i++){ //O(m*m*n) time, Suffix trie based approach
        trie.add(bottom, i);
    }
    int rowIndex = trie.search(top); //O(k*n) time
    return rowIndex==-1?0:bottom.length-rowIndex;
}

private static class Trie{
    TrieNode root = new TrieNode();
    public void add(int[][] matrix, int index){
        TrieNode temp = root;
        for(int i=index;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(!temp.children.containsKey(matrix[i][j])){
                    temp.children.put(matrix[i][j], new TrieNode());
                }
                temp = temp.children.get(matrix[i][j]);
            }
        }
        temp.rowIndex = index;
    }

    public int search(int[][] matrix){
        TrieNode temp = root;
        int result = -1;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(!temp.children.containsKey(matrix[i][j])){
                    return result;
                }
                temp = temp.children.get(matrix[i][j]);
                if(temp.rowIndex!=null){
                    result = temp.rowIndex;
                }
            }
        }
        return result;
    }
}

private static class TrieNode{
    HashMap<Integer, TrieNode> children = new HashMap();
    Integer rowIndex=null;
}
 }
