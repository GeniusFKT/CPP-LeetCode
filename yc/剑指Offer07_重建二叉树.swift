/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        if preorder.count == 0 {
            return nil
        }

        var t = TreeNode(preorder[0])

        var idx = 0
        for i in 0 ..< inorder.count {
            if inorder[i] == preorder[0] {
                idx = i
                break
            }
        }

        var leftinorder = [Int](), rightinorder = [Int](), leftpreorder = [Int](), rightpreorder = [Int]()
        
        if idx != 0 {
            leftinorder = Array(inorder[0 ..< idx])
            leftpreorder = Array(preorder[1 ... leftinorder.count])
        }

        if idx != preorder.count - 1 {
            rightinorder = Array(inorder[idx + 1 ..< inorder.count])
            rightpreorder = Array(preorder[leftpreorder.count + 1 ..< preorder.count])
        }

        t.left = self.buildTree(leftpreorder, leftinorder)
        t.right = self.buildTree(rightpreorder, rightinorder)

        return t
    }
}