/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func solve(root *TreeNode, count []int) int {
    if root == nil {
        return 0
    }

    count[root.Val]++

    result := 0

    if root.Left == nil && root.Right == nil {
        oddFreq := 0
        for i := 1; i <= 9; i++ {
            if count[i]%2 != 0 {
                oddFreq++
            }
        }

        if oddFreq <= 1 {
            result = 1
        }
    }

    result += solve(root.Left, count)
    result += solve(root.Right, count)

    count[root.Val]--

    return result
}

func pseudoPalindromicPaths(root *TreeNode) int {
    count := make([]int, 10)
    return solve(root, count)
}
