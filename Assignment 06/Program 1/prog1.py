# Write a python program to evaluate a postfix expression.

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
        else:
            item = self.stack[-1]
            self.stack.pop()
            return item

def isOperator(a):
    if a == '+' or a == '-' or a == '*' or a == '/':
        return 1
    else:
        return 0


def evaluate_postfix(exp):
    sp = stack(len(exp))
    for i in range(0,len(exp)):
        if not isOperator(exp[i]):
            sp.push(int(exp[i]))
        else:
            if exp[i] == '+':
                x = sp.pop()
                y = sp.pop()
                res = y+x
                sp.push(res)
            elif exp[i] == '-':
                x = sp.pop()
                y = sp.pop()
                res = y-x
                sp.push(res)
            elif exp[i] == '*':
                x = sp.pop()
                y = sp.pop()
                res = y*x
                sp.push(res)
            elif exp[i] == '/':
                x = sp.pop()
                y = sp.pop()
                res = y/x
                sp.push(res)

    val = sp.pop()
    return val


val = "234*6/+"
print(evaluate_postfix(val))
