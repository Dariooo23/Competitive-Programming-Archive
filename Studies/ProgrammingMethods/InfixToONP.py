operations = {'+', '-', '*', '/', '(', ')'}
priority = {'+': 1, '-': 1, '*': 2, '/': 2}

infix_operations = input().split()

onp_operations = []
stack = []

for operation in infix_operations:
    
    if operation not in operations:
        onp_operations.append(operation)
    elif operation == '(':
        stack.append(operation)
    elif operation == ')':
        while stack and stack[-1] != '(':
            onp_operations.append(stack.pop())
        stack.pop()
    else:
        while (stack and stack[-1] != '(' and priority[stack[-1]] >= priority[operation]):
            onp_operations.append(stack.pop())
        stack.append(operation)

while stack:
    onp_operations.append(stack.pop())

print(*onp_operations)
