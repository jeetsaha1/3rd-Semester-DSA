#  Write a Python program to find the palindrome using appropriate ADT to implement a more powerful version of the is_palindrome() function. As a reminder, this function implements simple palindome verification. Here is the signature and documentation for the function:
# bool is_palindrome(char *text)

#  Return true if text is a palindrome, false otherwise. A palindrome is a string that is identical to itself when reversed. For example, "madam", "dad", and "abba" are palindromes. Note: the empty string is a palindrome, as is every string of length one.

#  Your solution should ignore whitespace and punctuation, and all comparisons should be case-insensitive. Include some tests in your main function. Examples of valid palindromes:

#  Example- "", "a", "aa", "aaa", "aba", "abba", "Taco cat", "Madam, I'm Adam", "A man, a plan, a canal: Panama", "Doc, note: I dissent. A fast never prevents a fatness. I diet on cod."


class stack :
    def __init__(self,capacity):
        self.stack = []
        self.capacity = capacity
    
    def push (self,item):
        if len(self.stack) == self.capacity:
            print("Stack overflow")
            return None
        else:
            self.stack.append(item)

    def pop (self):
        if len(self.stack) == 0:
            print("Stack underflow")
            return None
        else:
            return self.stack.pop()
        
    def peek (self):
        if len(self.stack) == 0:
            print("Empty Stack")
            return None
        else:
            return (self.stack[-1])
        
    def display(self):
        if len(self.stack) == 0:
            print("Empty Stack")
            return None
        else:
            print(self.stack[::-1])



def is_palindrome(string):
    length = len(string)
    mid = length//2
    s = stack(mid)

    for i in range(mid):
        s.push(string[i])

    start = mid if length % 2 == 0 else mid + 1

    for j in range (start,length):
        if(string[j]!= s.pop()):
            return False
    return True


# Input the string
string = input("Enter the string: ")
if is_palindrome(string):
    print(True)
else:
    print(False)