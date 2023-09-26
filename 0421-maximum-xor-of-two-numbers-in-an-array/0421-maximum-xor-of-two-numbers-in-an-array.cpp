class Solution {
public:
    struct Node{
        Node *links[2];
        bool contain(int bit){
            return links[bit]!=NULL;
        }
        void point(int bit,Node* node){
            links[bit]=node;
        }
        Node* next(int bit){
            return links[bit];
        }
        bool hasOpp(int bit){
            return links[1-bit]!=NULL;
        }
    };

    class Trie{
        private:
            Node* root;
        public:
            Trie(){
                root=new Node();
            }
            void insert(int num){
                Node* node=root;
                for(int i=30;i>=0;i--){
                    int mask=num>>i;
                    int bit=mask&1;
                    if(!node->contain(bit)){
                        node->point(bit,new Node());
                    }
                    node=node->next(bit);
                }
            }
            int calculate(int num){
                Node* node=root;
                int ans=0;
                for(int i=30;i>=0;i--){
                    int mask=num>>i;
                    int bit=mask&1;
                    if(node->hasOpp(bit)){
                        ans+=1<<i;
                        node=node->next(1-bit);
                    }else
                    node=node->next(bit);
                }return ans;
            }
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto i:nums){
            trie.insert(i);
        }
        int ans=0;
        for(auto i:nums){
            ans=max(ans,trie.calculate(i));
        }return ans;
    }
};