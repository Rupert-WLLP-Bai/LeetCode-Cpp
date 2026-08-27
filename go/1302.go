package main

func deepestLeavesSum(root *TreeNode) int {
	ans := 0
	maxDepth := -1

	var dfs func(node *TreeNode, depth int)

	dfs = func(node *TreeNode, depth int) {
		if node == nil {
			return
		}

		if depth > maxDepth {
			// 第一次到达更深的一层
			maxDepth = depth
			ans = node.Val
		} else if depth == maxDepth {
			// 当前节点也是目前最深层
			ans += node.Val
		}

		dfs(node.Left, depth+1)
		dfs(node.Right, depth+1)
	}

	dfs(root, 0)
	return ans
}
