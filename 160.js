/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var solution1 = function(headA, headB) {
    if (headA == null || headB == null)
        return null;
    
    // Get lengths of lists
    var lengthA = 0;
    var a = headA;
    while (a != null) {
        a = a.next;
        lengthA++;
    }

    var lengthB = 0;
    var b = headB;
    while (b != null) {
        b = b.next;
        lengthB++;
    }
    
    // After doing that, you can just start the longer one first 
    // and the shorter one later for them to reach at the same time
    var longer, shorter;
    if (lengthA > lengthB) {
        longer = headA;
        shorter = headB;
    } else {
        longer = headB;
        shorter = headA;
    }
    
    for (var i = 0; i < Math.max(lengthA, lengthB); i++) {
        
        if (longer === shorter) {
            return longer;
        }
        
        longer = longer.next;
        if (i >= Math.abs(lengthA - lengthB)) {
            shorter = shorter.next;
        }
    }
    
    return null;
};

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var solution2 = function(headA, headB) {
    if (headA == null || headB == null)
        return null;
    
    var a = headA;
    var b = headB;
    
    while (a !== b) {
        // Loop until it reaches the end (aka the value is null)
        // since they reach the end at different times, the pointers
        // are naturally offset, so restarting them on the opposite
        // ones they started on will allow them to finish at the same
        // time
        a = a == null ? headB : a.next;
        b = b == null ? headA : b.next;
    }
    
    return a;
};
