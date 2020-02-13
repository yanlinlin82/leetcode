// https://leetcode-cn.com/problems/lru-cache/
#include <cstdio>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity): capacity_(capacity), head(NULL), tail(NULL) {
		//printf("===> init(%d)\n", capacity);
	}
	~LRUCache() {
		for (Node* p = head; p;) {
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	int get(int key) {
		//printf("===> get(%d)\n", key);
		auto it = m.find(key);
		if (it == m.end()) return -1;
		Node* p = it->second;
		if (p != head) {
			if (p == tail) tail = tail->prev;
			if (p->next) p->next->prev = p->prev;
			if (p->prev) p->prev->next = p->next;
			p->next = head;
			head->prev = p;
			head = p;
		}
		//dump();
		return p->val;
	}
	void put(int key, int value) {
		//printf("===> put(%d, %d)\n", key, value);
		auto it = m.find(key);
		Node* p;
		if (it != m.end()) {
			p = it->second;
			p->val = value;
			if (p != head) {
				if (p == tail) tail = tail->prev;
				if (p->next) p->next->prev = p->prev;
				if (p->prev) p->prev->next = p->next;
				p->next = head;
				if (head) head->prev = p;
				head = p;
				if (!tail) tail = p;
			}
		} else {
			while (m.size() >= capacity_) {
				if (tail && tail->prev) {
					Node* p = tail;
					tail = p->prev;
					tail->next = NULL;
					m.erase(m.find(p->key));
					delete p;
				} else {
					delete head;
					m.clear();
					head = tail = NULL;
				}
			}
			//dump();
			//printf("---\n");
			p = new Node(key, value);
			m[key] = p;
			p->next = head;
			if (head) head->prev = p;
			head = p;
			if (!tail) tail = p;
		}
		//dump();
	}
private:
	void dump() {
		printf("head: %p (%d), tail: %p (%d)\n", head, (head ? head->val : -1), tail, (tail ? tail->val : -1));
		printf("map: [ "); for (auto it = m.begin(); it != m.end(); ++it) printf("{%d,%d,%d} ", it->first, it->second->key, it->second->val); printf("]\n");
		printf("list: [ "); for (Node* p = head; p; p = p->next) printf("{%d,%d} ", p->key, p->val); printf("]\n");
	}
	struct Node {
		int key, val;
		Node *prev, *next;
		Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) { }
	};
	int capacity_;
	unordered_map<int, Node*> m;
	Node *head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
	{
		LRUCache cache( 2 /* 缓存容量 */ );
		cache.put(1, 1);
		cache.put(2, 2);
		printf("%d\n", cache.get(1));  // 返回  1
		cache.put(3, 3);                           // 该操作会使得密钥 2 作废
		printf("%d\n", cache.get(2));  // 返回 -1 (未找到)
		cache.put(4, 4);                           // 该操作会使得密钥 1 作废
		printf("%d\n", cache.get(1));  // 返回 -1 (未找到)
		printf("%d\n", cache.get(3));  // 返回  3
		printf("%d\n", cache.get(4));  // 返回  4
	}
	{
		LRUCache cache( 2 /* 缓存容量 */ );
		cache.put(2, 1);
		printf("%d\n", cache.get(2));  // 返回  1
		cache.put(3, 2);
		printf("%d\n", cache.get(2));  // 返回  1
		printf("%d\n", cache.get(3));  // 返回  2
	}
	{
		LRUCache cache( 1 /* 缓存容量 */ );
		cache.put(2, 1);
		printf("%d\n", cache.get(2));  // 返回  1
		cache.put(3, 2);
		printf("%d\n", cache.get(2));  // 返回  1
		printf("%d\n", cache.get(3));  // 返回  2
	}
	{
		LRUCache cache( 2 /* 缓存容量 */ );
		printf("%d\n", cache.get(2));  // 返回  -1
		cache.put(2, 6);
		printf("%d\n", cache.get(1));  // 返回  -1
		cache.put(1, 5);
		cache.put(1, 2);
		printf("%d\n", cache.get(1));  // 返回  2
		printf("%d\n", cache.get(2));  // 返回  6
	}
	{
		LRUCache cache( 2 /* 缓存容量 */ );
		cache.put(2, 1);
		cache.put(3, 2);
		printf("%d\n", cache.get(3));  // 返回  2
		printf("%d\n", cache.get(2));  // 返回  1
		cache.put(4, 3);                           // 该操作会使得密钥 3 作废
		printf("%d\n", cache.get(2));  // 返回  1
		printf("%d\n", cache.get(3));  // 返回  -1
		printf("%d\n", cache.get(4));  // 返回  3
	}
	return 0;
}
