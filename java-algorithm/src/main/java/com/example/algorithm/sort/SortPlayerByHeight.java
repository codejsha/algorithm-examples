package com.example.algorithm.sort;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Given two arrays of numbers, for team photos, players are arranged in front and back rows and then photographed.
 * The players in the back row must necessarily be taller than those in the front row.
 * Additionally, all players in a row should belong to the same team.
 */
public class SortPlayerByHeight {
    /**
     * Sort players by height.
     *
     * @param frontTeam height of players in front row
     * @param backTeam  height of players in back row
     * @return sorted players by height (front row first, then back row)
     */
    public static Integer[] sortByHeight(Integer[] frontTeam, Integer[] backTeam) {
        var frontRow = Arrays.stream(frontTeam).sorted().toList();
        var backRow = Arrays.stream(backTeam).sorted().toList();

        var result = new Integer[frontRow.size() + backRow.size()];
        var f = 0;
        var b = 0;
        for (var k = 0; k < frontRow.size(); k++) {
            if (frontRow.get(f) < backRow.get(b)) {
                result[f] = frontRow.get(f);
                result[b + frontRow.size()] = backRow.get(b);
                f++;
                b++;
            } else {
                return null;
            }
        }
        return result;
    }

    /**
     * Sort players by height using merge sort.
     *
     * @param frontTeam height of players in front row
     * @param backTeam  height of players in back row
     * @return sorted players by height (front row first, then back row)
     */
    public static Integer[] sortByHeightMerge(Integer[] frontTeam, Integer[] backTeam) {
        var frontRow = new ArrayList<>(Arrays.stream(frontTeam).sorted().toList());
        var backRow = Arrays.stream(backTeam).sorted().toList();

        frontRow.addAll(backRow);
        return frontRow.toArray(Integer[]::new);
    }
}
