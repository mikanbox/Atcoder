import java.util.*;

class Main {
    public static void main(String arg[]) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.next());
        char[] s = scan.next().toCharArray();
        char[] t = scan.next().toCharArray();

        boolean ans = true;

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (!(s[i] == '0' && t[i] == 'o'))
                    ans = false;

                if (!(s[i] == 'o' && t[i] == '0'))
                    ans = false;

                if (!(s[i] == 'l' && t[i] == '1'))
                    ans = false;

                if (!(s[i] == '1' && t[i] == 'l'))
                    ans = false;
            }
        }

        System.out.print((ans)?"Yes":"No");
    }
}
