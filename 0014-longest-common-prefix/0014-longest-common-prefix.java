class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder ans = new StringBuilder();
        int n = strs.length; // Use length instead of size for arrays

        if (n == 0) {
            return ans.toString(); // Handle the case when the array is empty
        }

        for (int j = 0; j < strs[0].length(); j++) {

            char c = strs[0].charAt(j); // Get the character from the first string
            for (int i = 1; i < n; i++) {
                if (j >= strs[i].length() || strs[i].charAt(j) != c) {
                    return ans.toString();
                }
            }

            ans.append(c);
        }

        return ans.toString();
    }
}
