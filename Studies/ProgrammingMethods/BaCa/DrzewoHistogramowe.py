#Karol Dziekan

def input():
    return raw_input()

inorder_list = []

class HistogramNode:
    def __init__(self, key):
        self.key = key
        self.count = 1
        self.left = None
        self.right = None

class HistogramTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = HistogramNode(key)
            print("Added: " + str(key))
            return
        
        current = self.root
        parent = None
        path = []

        while current is not None:
            path.append(current)
            if key < current.key:
                parent = current
                current = current.left
            elif key > current.key:
                parent = current
                current = current.right
            else:
                print("Element already exists")
                return
        
        for node in path:
            node.count += 1

        new_node = HistogramNode(key)
        if key < parent.key:
            parent.left = new_node
        else:
            parent.right = new_node

        print("Added: " + str(key))

    def delete(self, key):
        current = self.root
        parent = None
        path = []

        while current is not None and current.key != key:
            path.append(current)
            parent = current
            if key < current.key:
                current = current.left
            else:
                current = current.right

        if current is None:
            print("Element does not exist")
            return

        for node in path:
            node.count -= 1

        if current.left is None or current.right is None:
            child = current.left if current.left else current.right
            if parent is None:
                self.root = child
            else:
                if parent.left == current:
                    parent.left = child
                else:
                    parent.right = child
        else:
            predecessor_parent = current
            predecessor = current.left
            pred_path = []

            while predecessor.right is not None:
                pred_path.append(predecessor_parent)
                predecessor_parent = predecessor
                predecessor = predecessor.right

            pred_path.append(predecessor_parent)

            current.key = predecessor.key

            if predecessor_parent.right == predecessor:
                predecessor_parent.right = predecessor.left
            else:
                predecessor_parent.left = predecessor.left

            for node in pred_path:
                node.count -= 1

        print("Deleted: " + str(key))
    
    def search(self, key):
        current = self.root

        while current is not None:
            if current.key == key:
                return "YES"
            elif key < current.key:
                current = current.left
            else:
                current = current.right

        return "NO"

    def count_in_range(self, start, end):
        if self.search(end) == "YES":
            temp_node = 1
        else:
            temp_node = 0

        return self.count_less_than(end) - self.count_less_than(start) + temp_node

    def count_less_than(self, key):
        count = 0
        current = self.root
        while current is not None:
            if current.key < key:
                count += 1
                if current.left:
                    count += current.left.count
                current = current.right
            else:
                current = current.left
        return count

    def count_greater_than(self, key):
        count = 0
        current = self.root
        while current is not None:
            if current.key > key:
                count += 1
                if current.right:
                    count += current.right.count
                current = current.left
            else:
                current = current.right
        return count

    def find_kth_smallest(self, k):
        current = self.root
        remaining_k = k
        while current is not None:
            left_count = current.left.count if current.left else 0
            if remaining_k <= left_count:
                current = current.left
            elif remaining_k == left_count + 1:
                return current.key
            else:
                remaining_k -= left_count + 1
                current = current.right

    def inorder_traversal(self):
        del inorder_list[:]
        stack = []
        current = self.root
        while True:
            while current is not None:
                stack.append(current)
                current = current.left
            
            if not stack:
                break
            
            current = stack.pop()
            inorder_list.append(current.key)
            current = current.right
        return


bst_tree = HistogramTree()

while True:
    line = input().strip()
        
    parts = line.split()
    command = parts[0]
    args = parts[1:]
    
    if command == "EXIT":
        break
        
    elif command == "INSERT":
        key = int(args[0])
        bst_tree.insert(key)
            
    elif command == "DELETE":
        key = int(args[0])
        bst_tree.delete(key)
    
    elif command == "SEARCH":
        key = int(args[0])
        print(bst_tree.search(key))
    
    elif command == "COUNT_RANGE":
        start = int(args[0])
        end = int(args[1])
        print("Elements in range [" + str(start) + ", " + str(end) + "]: " + str(bst_tree.count_in_range(start, end)))
    
    elif command == "COUNT_LESS":
        key = int(args[0])
        print("Elements less than " + str(key) + ": " + str(bst_tree.count_less_than(key)))
    
    elif command == "COUNT_GREATER":
        key = int(args[0])
        print("Elements greater than " + str(key) + ": " + str(bst_tree.count_greater_than(key)))
    
    elif command == "FIND_KTH":
        k = int(args[0])
        node_count = bst_tree.root.count if bst_tree.root else 0
        if k < 1 or k > node_count:
            print("Invalid index")
        else:
            print(bst_tree.find_kth_smallest(k))
    
    elif command == "INORDER":
        bst_tree.inorder_traversal()
        if len(inorder_list) == 0:
            print("[ ]")
        else:   
            print("[ " + ", ".join(map(str, inorder_list)) + " ]")