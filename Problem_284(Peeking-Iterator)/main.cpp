/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    vector<int> v;
    int idx;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        for(int i=0; i<nums.size(); i++){
            v.push_back(nums[i]);
        }
        idx = 0;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return v[idx];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return v[idx++];
	}
	
	bool hasNext() const {
	    return (idx) < v.size();
	}
};
// PROBLEM:- https://leetcode.com/problems/peeking-iterator/description/
