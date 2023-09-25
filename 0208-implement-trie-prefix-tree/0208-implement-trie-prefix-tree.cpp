struct Node{
	Node* links[26];
	bool flag=false;

	bool contains(char letter){
		return !(links[letter-'a']==NULL);
	}
	void point(char letter,Node *node){
		links[letter-'a']=node;
	}
	Node* next(char letter){
		return links[letter-'a'];
	}
	void setTrue(){
		flag=true;
	}
	bool isEnd(){
		return flag;
	}
};

class Trie {
	private:
		Node* root;
	public:
		Trie() {
			root=new Node();
		}
		
		void insert(string word) {
			Node* node=root;
			for(int i=0;i<word.size();i++){
				if(!node->contains(word[i])){
					node->point(word[i],new Node());
				}
				node=node->next(word[i]);
			}
			node->setTrue();
		}
		
		bool search(string word) {
			Node* node=root;
			for(int i=0;i<word.size();i++){
				if(!node->contains(word[i])){
					return false;
				}
				node=node->next(word[i]);
			}return node->isEnd();
		}
		
		bool startsWith(string word) {
			Node* node=root;
			for(int i=0;i<word.size();i++){
				if(!node->contains(word[i])){
					return false;
				}
				node=node->next(word[i]);
			}return true;
		}
};



