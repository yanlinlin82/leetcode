// https://leetcode-cn.com/problems/design-twitter/
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		tweets.push_front(make_pair(userId, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		vector<int> a;
		for (auto it = tweets.begin(); it != tweets.end(); ++it) {
			if (it->first != userId) {
				auto it2 = followship.find(it->first);
				if (it2 == followship.end()) continue;
				auto it3 = it2->second.find(userId);
				if (it3 == it2->second.end()) continue;
			}
			a.push_back(it->second);
			if (a.size() >= 10) break;
		}
		return a;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
		followship[followeeId].insert(followerId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
		auto it = followship.find(followeeId);
		if (it != followship.end()) {
			auto it2 = it->second.find(followerId);
			if (it2 != it->second.end()) {
				it->second.erase(it2);
			}
		}
    }

private:
	list<pair<int, int>> tweets; // [ user -> tweet ]
	unordered_map<int, unordered_set<int>> followship;
};

void print(const vector<int>& a)
{
	for (auto e : a) cout << e << " ";
	cout << endl;
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
int main()
{
	Twitter* obj = new Twitter();
	obj->postTweet(1, 5);
	print(obj->getNewsFeed(1)); // answer: [5]
	obj->follow(1, 2);
	obj->postTweet(2, 6);
	print(obj->getNewsFeed(1)); // answer: [6, 5]
	obj->unfollow(1, 2);
	print(obj->getNewsFeed(1)); // answer: [5]
	delete obj;
	return 0;
}
