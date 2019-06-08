n = int(input())

tree = dict()

for _ in range(n):
    root, right, left = input().split()
    tree[root] = [right, left]


def preorder(root):
    traversal = []
    traversal.append(root)
    if tree[root][0] != '.':
        traversal += preorder(tree[root][0])
    if tree[root][1] != '.':
        traversal += preorder(tree[root][1])
    return traversal


def inorder(root):
    traversal = []
    if tree[root][0] != '.':
        traversal += inorder(tree[root][0])
    traversal.append(root)
    if tree[root][1] != '.':
        traversal += inorder(tree[root][1])
    return traversal


def postorder(root):
    traversal = []
    if tree[root][0] != '.':
        traversal += postorder(tree[root][0])
    if tree[root][1] != '.':
        traversal += postorder(tree[root][1])
    traversal.append(root)

    return traversal


preorder_tra = preorder('A')
inorder_tra = inorder('A')
postorder_tra = postorder('A')

print("".join(preorder_tra))
print("".join(inorder_tra))
print("".join(postorder_tra))