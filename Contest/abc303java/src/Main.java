import java.util.*;

class MultiKeyMap {
    HashMap<Integer, HashMap<Integer,Boolean>> mp = new HashMap<>();
    public void put(Integer l, Integer r) {
        if (mp.containsKey(l)) {
            mp.get(l).put(r,true);
        } else {
            mp.put(l,new HashMap<Integer,Boolean>());
            mp.get(l).put(r,true);
        }
    }
    public Boolean find(Integer l, Integer r) {
        if (!mp.containsKey(l)) {
            return false;
        }
        if (!mp.get(l).containsKey(r)) {
            return false;
        }
        if (mp.get(l).get(r) == false) {
            return false;
        }

        return true;
    }

    public void retrieve(Integer l, Integer r) {
        mp.get(l).put(r,false);
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.next());
        int m = Integer.parseInt(scan.next());
        int h = Integer.parseInt(scan.next());
        int k = Integer.parseInt(scan.next());
        String s = scan.next();


        MultiKeyMap itemMap = new MultiKeyMap();
        for (int i = 0; i < m; i++) {
            itemMap.put(Integer.parseInt(scan.next()),Integer.parseInt(scan.next()));
        }

        boolean ans = true;
        int x = 0;
        int y = 0;


        for (char c:s.toCharArray()) {
            if ( h <= 0) {
                ans = false;
            }
            if (c == 'R') {
                x = x + 1;
            }
            if (c == 'L') {
                x = x - 1;
            }
            if (c == 'U') {
                y = y + 1;
            }
            if (c == 'D') {
                y = y - 1;
            }
            h--;


            System.err.println("  x" + x + " y " + y + " h:" + h);

            if (itemMap.find(x,y)) {
                System.err.println("find");
                if (h < k) {
                    h = k;
                    itemMap.retrieve(x,y);
                }
            }
        }


        System.out.print((ans)?"Yes":"No");
    }
}
