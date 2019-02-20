// 006 ZigZag Conversion
class Solution {
    public String convert(String s, int numRows) {
        int length = numRows>1? numRows + numRows-2:1;
        // System.out.printf("%d %d%n", numRows, length);
        String[] tmp = new String[numRows];
        // initialize
        for (int i=0;i<numRows;i++) {
            tmp[i] = "";
        }
        StringBuilder res = new StringBuilder();
        // 4->2 5->1
        for (int i=0;i<s.length();i++) {
            int pos = i%length < numRows? i%length : length-(i%length);
            tmp[pos] += s.charAt(i);
        }
        for (int i=0;i<numRows;i++) {
            if (tmp[i] != null)
                res.append(tmp[i]);
        }
        return res.toString();
    }
}
