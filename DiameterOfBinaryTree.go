/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func height(node *TreeNode) int {
        if node == nil {
            return 0
        }
        left := height(node.Left)
        right := height(node.Right)
        
        ans := max(left, right) + 1
        
        return ans
    }
 
func diameterOfBinaryTree(root *TreeNode) int {
    if root == nil {
            return 0
        }
        
        op1 := diameterOfBinaryTree(root.Left)
        op2 := diameterOfBinaryTree(root.Right)
        op3 := height(root.Left) + height(root.Right)
        
        ans := max(op1, max(op2, op3))
        
        return ans
}