package main

func createBinaryTree(descriptions [][]int) *TreeNode {
	nodeMap := make(map[int]*TreeNode) // 存储所有节点
	childSet := make(map[int]struct{}) // 记录所有子节点

	for _, cur := range descriptions {
		parentVal, childVal, isLeft := cur[0], cur[1], cur[2]
		if _, exists := nodeMap[parentVal]; !exists {
			nodeMap[parentVal] = &TreeNode{Val: parentVal}
		}
		if _, exists := nodeMap[childVal]; !exists {
			nodeMap[childVal] = &TreeNode{Val: childVal}
		}

		// 连接
		if isLeft == 1 {
			nodeMap[parentVal].Left = nodeMap[childVal]
		} else {
			nodeMap[parentVal].Right = nodeMap[childVal]
		}

		childSet[childVal] = struct{}{} // 标记存在
	}

	// 根节点：没有出现在childSet中
	for _, cur := range descriptions {
		parentVal := cur[0]
		if _, isChild := childSet[parentVal]; !isChild {
			return nodeMap[parentVal]
		}
	}
	return nil
}
