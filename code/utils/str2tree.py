class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right

def get_tree(data: str) -> TreeNode:
    data = data.strip('[').strip(']')
    data = data.split(',')
    if data[0] == '' or data[0] == 'null':
        return None
    tree = TreeNode(int(data[0]))
    data.pop(0)
    Queue = [tree]

    while len(Queue) > 0 and len(data) > 0:
        root = Queue.pop(0)
        l = data.pop(0)
        if len(data) > 0:
            r = data.pop(0)
        else:
            r = 'null'
        if l != 'null':
            root.left = TreeNode(int(l))
            Queue.append(root.left)
        else:
            root.left = None
        
        if r != 'null':
            root.right = TreeNode(int(r))
            Queue.append(root.right)
        else:
            root.right = None
    
    return tree

def pre(root):
    if root is None:
        return
    print(root.val, end=' ')
    pre(root.left)
    pre(root.right)


def mid(root):
    if root is None:
        return
    pre(root.left)
    print(root.val, end=' ')
    pre(root.right)

def post(root):
    if root is None:
        return
    pre(root.left)
    pre(root.right)
    print(root.val, end=' ')


if __name__ == '__main__':
    data = input()
    tr = get_tree(data)
    pre(tr)
    print()
    mid(tr)
    print()
    post(tr)
    print()
