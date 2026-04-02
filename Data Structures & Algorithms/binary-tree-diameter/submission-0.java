/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    int maxHeight = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null){
            return 0;
        }
        int rightMax = nodeDepth(root.right);
        int leftMax = nodeDepth(root.left);
        int nodeDiameter = rightMax+leftMax;
        if(maxHeight < nodeDiameter){
            maxHeight = nodeDiameter;
        }
        diameterOfBinaryTree(root.left);
        diameterOfBinaryTree(root.right);
        return maxHeight;
    }
    public int nodeDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        return Math.max(nodeDepth(root.left)+1,nodeDepth(root.right)+1);
    }
}
