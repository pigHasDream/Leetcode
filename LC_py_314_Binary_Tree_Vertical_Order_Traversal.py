# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        vals = collections.defaultdict(list)
        que = collections.deque()
        que.append((root, 0))

        min_col, max_col = 0, 0

        while que:
            node, col = que.popleft()
            if node:
                vals[col].append(node.val)
                que.append((node.left, col-1))
                que.append((node.right, col+1))
                min_col = min(min_col, col)
                max_col = max(max_col, col)

        ret = []
        # This is based on the observation that the column will be consecutive!
        for k in range(min_col, max_col+1):
            ret.append(vals[k])

        return ret
