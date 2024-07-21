package Coding_Questions;

public class First_Max {

    public void first_Max(int a[]) {

        int first_max = Integer.MIN_VALUE;

        for (int i = 0; i < a.length; i++) {
            if (a[i] > first_max) {
                first_max = a[i];
            }
            System.out.println("Lragest Values in array : " + first_max);
        }

    }

    public static void main(String a[]) {

        int a1[] = { 3, 6, 9, 12, 45, 23, 45 };

        First_Max f = new First_Max();
        f.first_Max(a1);

    }

}
