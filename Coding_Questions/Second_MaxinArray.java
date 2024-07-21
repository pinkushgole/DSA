public class Second_MaxinArray {

    public static void main(String ar[]) {

        int[] a = { 2, 4, 81, 5, 90, 76, 23, 12, 44, 670 };

        int first_Max = Integer.MIN_VALUE;
        int second_Max = Integer.MIN_VALUE;

        for (int i = 0; i < a.length; i++) {
            if (first_Max < a[i]) {
                first_Max = a[i];
            } else if (a[i] > second_Max && first_Max != second_Max) {
                second_Max = a[i];
            }
        }
        System.out.println("First largest number in array:" + first_Max);
        System.out.println("Second largest Element in array :" + second_Max);

    }

}