n = raw_input()
n = int( n )

m = 0
while n != 0:
    m = m * 10 + n % 10
    n /= 10

print m
