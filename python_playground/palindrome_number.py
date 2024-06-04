
def reverse(num, number_reverse):
  if num==0:
      n=num%10
      n=n*(10**(len(str(num))-1))
      number_reverse+=n
      return number_reverse
  n=num%10
  n=n*(10**(len(str(num))-1))
  number_reverse+=n
  return reverse(num//10, number_reverse)

def is_palindrome(number):
  if number<0:
     return False
  reverse_number=reverse(number, 0)
  if number!=reverse_number:
     return False
  return True


print(is_palindrome(242))
  

