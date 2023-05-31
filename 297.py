# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        # Recursively serialize by doing BFS
        def _serialize(root) -> str:
            if root == None:
                return "null"
            
            return ",".join([
                str(root.val),
                
                # Add entire left serialization
                _serialize(root.left),
                
                # Then right serialization
                _serialize(root.right),
            ])
        return _serialize(root)
    
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        # Recursively deserialize by deserializing the left
        # node first
        def _deserialize(data, index) -> Tuple[TreeNode, int]:
            if data[index] != "null":
                root = TreeNode(data[index])
            else:
                return (None, index)
            
            # Maintain an index value that just counts up
            root.left, index = _deserialize(data, index + 1)
            root.right, index = _deserialize(data, index + 1)
            
            return (root, index)

        return _deserialize(data.split(","), 0)[0]


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
