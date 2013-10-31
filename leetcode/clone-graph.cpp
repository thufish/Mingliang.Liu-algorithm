/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return nullptr;
            
        unordered_map<UndirectedGraphNode*, int> p2id;
        unordered_map<int, UndirectedGraphNode*> id2p;        
        p2id[nullptr] = 0;
        id2p[0] = nullptr;
        
        p2id[node] = 1;
        UndirectedGraphNode *nnode = new UndirectedGraphNode(node->label);
        id2p[1] = nnode;
        
        queue<UndirectedGraphNode*> Q;
        Q.push(node);
        int count = 2;
        while (!Q.empty()) {
            UndirectedGraphNode *n = Q.front();
            Q.pop();
            for (UndirectedGraphNode *nb : n->neighbors)
                if (nb && p2id.find(nb) == p2id.end()) {
                    Q.push(nb);
                    p2id[nb] = count;
                    UndirectedGraphNode *nnb = new UndirectedGraphNode(nb->label);
                    id2p[count] = nnb;
                    count++;
                }
        }
        
        Q.push(node);
        unordered_set<UndirectedGraphNode*> visited;
        visited.insert(node);
        while (!Q.empty()) {
            UndirectedGraphNode *n = Q.front();
            Q.pop();
            for (UndirectedGraphNode *nb : n->neighbors) {
                if (nb && !visited.count(nb)) {
                    Q.push(nb);
                    visited.insert(nb);
                }
                id2p[p2id[n]]->neighbors.push_back(id2p[p2id[nb]]);
            }
        }
        
        return nnode;
    }
};
