m = 0
def reverse( n ):
    global m
    if n:
        m = m * 10 + n % 10
        reverse( n / 10 )

reverse( 91391847 )
print m
