package main

func pairSum(head *ListNode) int {
	// 1. 快慢指针找中点
	// 2. 反转链表
	// 3. 加

	slow, fast := head, head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	var reverseList func(head *ListNode) *ListNode
	reverseList = func(head *ListNode) *ListNode {
		if head == nil || head.Next == nil {
			return head
		}
		newHead := reverseList(head.Next)
		head.Next.Next = head
		head.Next = nil

		return newHead
	}

	second := reverseList(slow)
	first := head
	ans := 0

	for second != nil {
		sum := first.Val + second.Val
		if sum > ans {
			ans = sum
		}
		first = first.Next
		second = second.Next
	}

	return ans
}
