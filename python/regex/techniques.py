
def two_sum(nums, target):
    """function that use hash map to find the answer"""
    seen = {}
    for i, num in enumerate(nums):
        diff = target - num
        if diff in seen:
            return [seen[diff], i]
        seen[num] = i
    return []

def max_sum_window(arr, k):
    """the sliding window technique instead of calculating one by one
    we have the current sum and just adding and subtracting one at a time"""
    if len(arr) < k: return None
    current_sum = sum(arr[:k])
    max_sum = current_sum
    for i in range(len(arr) - k):
        current_sum = current_sum - arr[i] + arr[i + k]
        max_sum = max(max_sum, current_sum)

    return max_sum


def merge_intervals(intervals):
    """merging the intervals that we receive if a list is [[1,4][2,5]] merging to [1,5] to make it easier  """
    intervals.sort(key=lambda x: x[0])
    merged = []
    for interval in intervals:
        if not merged or merged[-1][1] < interval[0]:
            merged.append(interval)
        else:
            merged[-1][1] = max(merged[-1][1], interval[1])
    return merged