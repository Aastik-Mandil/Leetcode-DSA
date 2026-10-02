class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = version1.split('.')
        version2 = version2.split('.')

        version1 = [int(v) for v in version1]
        version2 = [int(v) for v in version2]

        diff = abs(len(version1) - len(version2))
        if len(version1) < len(version2):
            version1.extend([0]*diff)
        elif len(version1) > len(version2):
            version2.extend([0]*diff)

        for i in range(len(version1)):
            if version1[i] < version2[i]:
                return -1
            elif version1[i]> version2[i]:
                return 1
        return 0
# PROBLEM:- https://leetcode.com/problems/compare-version-numbers/description/
