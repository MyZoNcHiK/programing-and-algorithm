package lab15;

import java.util.Scanner;

public class Solution{
    public static String joinPath(String part1, String part2) {
        return part1.replaceAll("/+$", "") + "/" + part2.replaceAll("^/+", "");
    }
    public static void main(String[] args){
        Scanner scaner = new Scanner(System.in);
        System.out.println("Введіть 3-ьо значне число");
        int n = scaner.nextInt();
        System.out.println(((n % 100) / 10)*100 + (n / 100)*10 + n % 10);
        System.out.println(joinPath("portion1", "portion2"));
        System.out.println(joinPath("portion1", "/portion2"));
        System.out.println(joinPath("portion1/", "/portion2"));
    }
}