a,b,c = map(int,input().split())
#squence is x_0 =1,  x_(i+1) = (a*x_i + x_i//b) % c
#Floyd's Cycle-Finding Algorithm Steps:
#1. Initialize two pointers, slow and fast to the first node of the Linked List.
#2. Move the slow pointer by one and the fast pointers by two.
#3. If the slow pointer and the fast pointer meet at some point, then there is a loop in the Linked List.
#4. If the slow pointer and fast pointer do not meet then no loop exists in the Linked List.
def floyd(a,b,c):
    slow = 1
    fast = 1
    while True:
        slow = (a*slow + slow//b) % c
        fast = (a*fast + fast//b) % c
        fast = (a*fast + fast//b) % c
        if slow == fast:
            break
    mu = 0
    slow = 1
    while slow != fast:
        slow = (a*slow + slow//b) % c
        fast = (a*fast + fast//b) % c
        mu += 1
    lam = 1
    fast = (a*slow + slow//b) % c
    while slow != fast:
        fast = (a*fast + fast//b) % c
        lam += 1
    return mu,lam

mu,lam = floyd(a,b,c)
print(mu+lam)
