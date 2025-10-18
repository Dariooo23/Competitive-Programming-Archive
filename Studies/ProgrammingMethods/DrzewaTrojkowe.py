class Node:
    def __init__(self, node_id=None):
        self.node_id = node_id
        self.children = [None, None, None]

class TernaryTree:
    def __init__(self):
        self.root = None
        self.nodes = {}

    def add_node(self, parent_id, child_id, child_index):
        if self.root == None:
            self.root = Node(1)
            self.nodes[1] = self.root

        parent_node = self.nodes[parent_id]

        new_node = Node(child_id)
        parent_node.children[child_index] = new_node
        self.nodes[child_id] = new_node

    def load_from_console(self):
        while True:
            parent_id = input("Podaj ID rodzica: ")
            if parent_id == "stop":
                break

            child_id = input("Podaj ID dziecka: ")
            child_index = input("Podaj kolejnosc dziecka [0-2]: ")

            self.add_node(int(parent_id), int(child_id), int(child_index))

    def preorder_traversal(self, node=None):
        if node is None:
            node = self.root

        if node is None:
            return

        print(node.node_id, " ")

        if node.children[0] != None:
            self.preorder_traversal(node.children[0])
        if node.children[1] != None:
            self.preorder_traversal(node.children[1])
        if node.children[2] != None:
            self.preorder_traversal(node.children[2])
    
    def postorder_traversal(self, node=None):
        if node is None:
            node = self.root

        if node is None:
            return


        if node.children[0] != None:
            self.postorder_traversal(node.children[0])
        if node.children[1] != None:
            self.postorder_traversal(node.children[1])
        if node.children[2] != None:
            self.postorder_traversal(node.children[2])

        print(node.node_id, " ")
    
    def inorder_traversal(self, node=None):
        if node is None:
            node = self.root

        if node is None:
            return

        if node.children[0] != None:
            self.inorder_traversal(node.children[0])
        print(node.node_id, " ")
        if node.children[1] != None:
            self.inorder_traversal(node.children[1])
        if node.children[2] != None:
            self.inorder_traversal(node.children[2])


tree = TernaryTree()
tree.load_from_console()

#tree.preorder_traversal()
#print()
#tree.postorder_traversal()
#print()
tree.inorder_traversal()
print()