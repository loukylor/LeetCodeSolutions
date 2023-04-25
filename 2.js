/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var currentNode1 = l1;
    var currentNode2 = l2;

    var result = new ListNode(0, null);
    const root = result;
    // Loop from ones to higher digits
    while (currentNode1 != null || currentNode2 != null) {
        const val1 = currentNode1 != null ? currentNode1.val : 0;
        const val2 = currentNode2 != null ? currentNode2.val : 0;
        
        const next = new ListNode(0, null);
        result.next = next;
        result.val += val1 + val2;
        // If larger than 9, carry one to next digit
        if (result.val >= 10) {
            next.val = 1;
            result.val %= 10;
        } else if (currentNode1?.next == null && currentNode2?.next == null) {
            // If on last loop then don't have next set to 
            // next since it will just be a trailing 0
            result.next = null;
        }
        result = next;
        currentNode1 = currentNode1?.next;
        currentNode2 = currentNode2?.next;
    }
    
    return root;
};
