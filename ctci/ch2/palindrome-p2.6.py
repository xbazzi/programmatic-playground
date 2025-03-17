# Implement a function to checkj if a linked list is a palindrome

from python_std import LinkedList
import array

def is_palindrome(head: LinkedList.Node) -> bool:
    curr = head
    arr = array.array('i', [])
    while (curr):
        arr.append(curr.val)
        curr = curr.next
    for i in arr:
        if arr[i] != arr[len(arr) - i - 1]:
            return False
    return True

def is_palindrome_twopointer(head: LinkedList.Node) -> bool:
    if not head:
        return False
    if not head.next:
        return True
    slow = head
    fast = head
    stack = array.array('i', [slow.val])
     
    # while (slow):
    #     if fast and fast.next:
    #         stack.append(slow.val)
    #         fast = fast.next.next
    #     else:
    #         if stack.pop() != slow.val:
    #             return False
    #         if fast:
    #             slow = slow.next
    #     slow = slow.next
    # return True
    while slow:
        # First half: push values onto the stack
        if fast and fast.next:
            stack.append(slow.val)
            fast = fast.next.next  # Move fast pointer two steps
        else:
             # If fast is not None, we are at the middle of an odd-length list, so skip the middle node
            if fast:
                slow = slow.next

            # Second half: start comparing with the stack
            if stack and stack.pop() != slow.val:
                return False
        slow = slow.next  # Move slow pointer forward
    return True


def main():
    ll = LinkedList.LinkedList()
    ll.append(2)
    ll.append(3)
    ll.append(5)
    # ll.append(5)
    ll.append(5)
    ll.append(3)
    ll.append(2)
    ll.print()
    print(is_palindrome_twopointer(ll.head))

if __name__ == "__main__":
    main()
