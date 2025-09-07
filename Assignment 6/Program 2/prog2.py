# infix to postfix operation
class stack:
    def __init__(self,capacity):
        self.stack = []
        self.capacity = capacity
    
    def push(self, val):
        if len(self.stack) == self.capacity:
            print("Stack Overflow")
        else:
            self.stack.append(val)
    
    def pop(self):
        if len(self.stack) == 0:
            print("Stack Underflow")
            return None
        else:
            return self.stack.pop()
        
    def peep(self):
        if len(self.stack) == 0:
            return None
        return self.stack[-1]

    def is_empty(self):
        return len(self.stack) == 0

def isOperator(a):
    if a == '+' or a == '-' or a == '*' or a == '/' :
        return 1
    else:
        return 0

def precedence(op):
    if op == '*' or op == '/':
        return 3
    if op == '+' or op == '-':
        return 2
    return 0
    

def infix_to_postfix(infix):
    sp = stack(len(infix))
    postfix = []

    i=0

    while i< len(infix):
        ch = infix[i]

        if ch == '(':
            sp.push(ch)

        elif ch.isalnum():
            postfix.append(ch)

        elif ch == ')':
            while not sp.is_empty() and sp.peep() != '(':
                postfix.append(sp.pop())
            sp.pop()

        elif isOperator(ch):
            while not sp.is_empty() and (precedence(sp.peep()) > precedence(ch)):
                postfix.append(sp.pop())
            sp.push(ch)
        i+=1

    while not sp.is_empty():
        postfix.append(sp.pop())
    return "".join(postfix)

infix = "(a+b)"
print(infix_to_postfix(infix))

