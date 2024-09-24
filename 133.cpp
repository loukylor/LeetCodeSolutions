/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        map<int, Node*> createdNodes {};
        return cloneGraphInternal(node, createdNodes);
    }

private:
    Node* cloneGraphInternal(Node* node, map<int, Node*>& createdNodes) {
        Node* newNode = new Node(node->val, vector<Node*>(node->neighbors.size()));
        createdNodes[node->val] = newNode;

        for (int i = 0; i < node->neighbors.size(); i++) {
            if (createdNodes.contains(node->neighbors[i]->val)) {
                newNode->neighbors[i] = createdNodes[node->neighbors[i]->val];
                continue;
            }

            newNode->neighbors[i] = cloneGraphInternal(node->neighbors[i], createdNodes);
        }
        return newNode;
    }
};