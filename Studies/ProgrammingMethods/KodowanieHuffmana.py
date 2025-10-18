class Node:
    def __init__(self, x, y):
        self.data = x
        self.char = y
        self.left = None
        self.right = None



def pre_order(root, ans, curr):
	if root is None:
		return

	if root.left is None and root.right is None:
		ans.append((root.char,curr))
		return

	pre_order(root.left, ans, curr + '0')
	pre_order(root.right, ans, curr + '1')



class heapq:
    def __init__(self):
        self.heap = []

    def push(self, node):
        self.heap.append(node)
        self._siftup(len(self.heap) - 1)

    def pop(self):
        if len(self.heap) == 0:
            return None
        
        last_item = self.heap.pop()

        if len(self.heap) == 0:
            return last_item
        
        return_item = self.heap[0]

        self.heap[0] = last_item
        self._siftdown(0)

        return return_item

    def _siftup(self, pos):
        item = self.heap[pos]

        while pos > 0:
            parent_pos = (pos - 1) // 2
            parent_item = self.heap[parent_pos]

            if item.data < parent_item.data:
                self.heap[pos] = parent_item
                pos = parent_pos
            else:
                break

        self.heap[pos] = item

    def _siftdown(self, pos):
        item = self.heap[pos]
        end_pos = len(self.heap)
        child_pos = 2 * pos + 1

        while child_pos < end_pos:
            right_child_pos = child_pos + 1

            if right_child_pos < end_pos and not (self.heap[child_pos].data < self.heap[right_child_pos].data):
                child_pos = right_child_pos
            if item.data < self.heap[child_pos].data:
                break

            self.heap[pos] = self.heap[child_pos]
            pos = child_pos
            child_pos = 2 * pos + 1
            
        self.heap[pos] = item

def HuffmanCoding(czestotliwosc_liter):
    heap = heapq()
    
    for i in range(len(czestotliwosc_liter)):
        if czestotliwosc_liter[i] != 0:
            tmp = Node(czestotliwosc_liter[i], chr(i + ord('a')))
            heap.push(tmp)
    
    while len(heap.heap) > 1:
        left = heap.pop()
        right = heap.pop()

        new_node = Node(left.data + right.data, ' ')
        new_node.left = left
        new_node.right = right

        heap.push(new_node)

    root = heap.pop()
    ans = []

    pre_order(root, ans, '')
    return ans


wejscie = input().split()

czestotliwosc_liter = [0] * 26

for slowo in wejscie:
    for litera in slowo:
        if 'a' <= litera <= 'z':
            czestotliwosc_liter[ord(litera) - ord('a')] += 1

ans = HuffmanCoding(czestotliwosc_liter)

for i in range(len(ans)):
    print(ans[i][0] + ': ' + ans[i][1])
