import java.util.*;

class SortCharacterByFrequency {
    public String frequencySort(String s) {
        // Step 1: Count the frequency of each character
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        // Step 2: Sort characters by frequency in descending order
        // Create a list from the map entries and sort by frequency (descending)
        List<Map.Entry<Character, Integer>> entryList = new ArrayList<>(freqMap.entrySet());
        entryList.sort((a, b) -> b.getValue() - a.getValue());  // Sort by value in descending order

        // Step 3: Build the result string based on the sorted order
        StringBuilder result = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : entryList) {
            char c = entry.getKey();
            int freq = entry.getValue();
            for (int i = 0; i < freq; i++) {
                result.append(c);  // Append the character based on its frequency
            }
        }

        // Step 4: Return the result string
        return result.toString();
    }
}