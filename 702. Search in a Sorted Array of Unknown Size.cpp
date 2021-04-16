/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 10000;
        while(reader.get(r) < target) {
            r *= 2;
        }

        while(l+1 < r) {
            int mid = l + (r-l)/2;
            if (reader.get(mid) == target) {
                return mid;
            }
            if (reader.get(mid) > target) {
                r = mid;
            }
            if (reader.get(mid) < target) {
                l = mid;
            }

        }
        if (reader.get(l) == target) return l;
        if (reader.get(r) == target) return r;
        return -1;
    }
};