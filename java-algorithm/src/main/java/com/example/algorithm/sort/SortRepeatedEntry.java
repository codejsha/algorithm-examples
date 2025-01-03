package com.example.algorithm.sort;

import java.util.HashMap;

public class SortRepeatedEntry {
    public static String[] groupByAge(String[][] people) {
        if (people.length == 0) {
            return new String[0];
        }

        var ageMap = new HashMap<String, Integer>();

        // count age
        for (String[] person : people) {
            String age = person[1];
            ageMap.put(age, ageMap.getOrDefault(age, 0) + 1);
        }

        // calculate start index
        var keyIndexPair = new HashMap<String, Integer>();
        int sum = 0;
        for (String age : ageMap.keySet()) {
            keyIndexPair.put(age, sum);
            sum += ageMap.get(age);
        }

        // sort by age
        String[] result = new String[people.length];
        for (String[] person : people) {
            String age = person[1];
            Integer key = keyIndexPair.get(age);
            result[key] = person[0] + " " + person[1];
            keyIndexPair.put(age, key + 1);
        }
        return result;
    }
}
