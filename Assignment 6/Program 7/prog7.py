#  7. Write a C program to validate the parenthesis of an expression.

class stack:
    def __init__(self,capacity):
        self.stack = []
        self.capacity = capacity
    
    def isFull(self):
        if len(self.stack) == self.capacity:
            return 1
        return 0
    
    def isEmpty(self):
        if len(self.stack) == 0:
            return 1
        return 0

    def push(self, val):
        if self.isFull():
            print("Stack Overflow")
        else:
            self.stack.append(val)

    def pop(self):
        if self.isEmpty():
            print("Stack Undeflow")
        else:
            return self.stack.pop()

def match(char1, char2):
    if char1 == '(' and char2 == ')':
        return 1
    if char1 == '[' and char2 == ']':
        return 1
    if char1 == '{' and char2 == '}':
        return 1
    return 0

def validate_parenthisis(exp):
    sp = stack(len(exp))

    for i in range(0,len(exp)):
        if exp[i] == '(' or exp[i] == '[' or exp[i] == '{' :
            sp.push(exp[i])
        elif exp[i] == ')' or exp[i] == ']' or exp[i] == '}' :
            if sp.isEmpty():
                return 0
            poped_ele = sp.pop()
            if not match(poped_ele, exp[i]):
                return 0
    if sp.isEmpty():
        return 1
    else:
        return 0
    
if __name__== "__main__":
    exp = "(a+b)"
    if validate_parenthisis(exp):
        print("The Praenthesis is matched")
    else:
        print("The Praenthesis is not matched")