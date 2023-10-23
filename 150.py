class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        op = tokens.pop()
        if not self.is_operator(op):
            return int(op)
        return self.eval_expression(op, tokens)

    def eval_expression(self, operator: str, tokens: List[str]) -> int:
        right_hand = tokens.pop()
        if self.is_operator(right_hand):
            right_hand = self.eval_expression(right_hand, tokens)
        else:
            right_hand = int(right_hand)

        left_hand = tokens.pop()
        if self.is_operator(left_hand):
            left_hand = self.eval_expression(left_hand, tokens)
        else:
            left_hand = int(left_hand)
        
        if operator == "+":
            return left_hand + right_hand
        elif operator == "-":
            return left_hand - right_hand
        elif operator == "*":
            return left_hand * right_hand
        else:
            return int(left_hand / right_hand)
    
    def is_operator(self, operator) -> bool:
        return operator == "+" or operator == "-" or operator == "*" or operator == "/"
