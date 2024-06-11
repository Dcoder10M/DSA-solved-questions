public class Solution {
    public int[] RelativeSortArray(int[] arr1, int[] arr2) {
        Dictionary<int, int> countMap = new Dictionary<int, int>();
        List<int> remainingElements = new List<int>();

        // Count occurrences of each element in arr1
        foreach (var num in arr1) {
            if (countMap.ContainsKey(num)) {
                countMap[num]++;
            } else {
                countMap[num] = 1;
            }
        }

        int index = 0;

        // Place elements of arr1 that are in arr2 according to the order in arr2
        foreach (var num in arr2) {
            if (countMap.ContainsKey(num)) {
                int count = countMap[num];
                for (int i = 0; i < count; i++) {
                    arr1[index++] = num;
                }
                countMap.Remove(num);
            }
        }

        // Collect remaining elements
        foreach (var kvp in countMap) {
            int num = kvp.Key;
            int count = kvp.Value;
            for (int i = 0; i < count; i++) {
                remainingElements.Add(num);
            }
        }

        // Sort remaining elements
        remainingElements.Sort();

        // Place sorted remaining elements into arr1
        foreach (var num in remainingElements) {
            arr1[index++] = num;
        }

        return arr1;
    }
}
